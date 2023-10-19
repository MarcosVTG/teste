#include <iostream>
#include <vector>

using namespace std;
int boroka=12*2;


class Cliente {
    string nome, cpf;

public:
    Cliente(string _nome, string _cpf) {
        nome = _nome;
        cpf = _cpf;
    }

    string getNome() {
        return nome;
    }

    void setNome(string _nome) {
        nome = _nome;
    }
};

class Dependente {
    string nome;
    Cliente* responsavel;

public:
    Dependente(string _nome, Cliente* _responsavel) {
        nome = _nome;
        responsavel = _responsavel;
    }

    Cliente* getResponsavel() {
        return responsavel;
    }
};

class Evento {
public:
    virtual void imprimir() = 0;
    
protected:
    int duracao;

    Evento(int _duracao) : duracao(_duracao) {
    }
};

class Roteiro : public Evento {
    string titulo;
    int ordem;

public:
    Roteiro(int _duracao, string _titulo, int _ordem) : Evento(_duracao) {
        titulo = _titulo;
        ordem = _ordem;
    }

    void imprimir() override {
        cout << "Roteiro: " << titulo << " (Ordem: " << ordem << ", Duracao: " << duracao << " horas)" << endl;
    }
};

class Deslocamento : public Evento {
    string origem;
    string destino;

public:
    Deslocamento(int _duracao, string _origem, string _destino) : Evento(_duracao) {
        origem = _origem;
        destino = _destino;
    }

    void imprimir() override {
        cout << "Deslocamento de " << origem << " para " << destino << " (Duracao: " << duracao << " horas)" << endl;
    }
};

class Pernoite : public Evento {
    string local;

public:
    Pernoite(int _duracao, string _local = "") : Evento(_duracao) {
        local = _local;
    }

    void imprimir() override {
        if (local.empty()) {
            cout << "Pernoite (Duracao: " << duracao << " horas)" << endl;
        } else {
            cout << "Pernoite em " << local << " (Duracao: " << duracao << " horas)" << endl;
        }
    }
};

class Pacote {
private:
    vector<Evento*> listaEventos;

public:
    Pacote(Evento* _evento) {
        listaEventos.push_back(_evento);
    }

    void inserirEvento(Evento* _evento) {
        listaEventos.push_back(_evento);
    }

    vector<Evento*> getEventos() {
        return listaEventos;
    }
};

class Reserva {
public:
    Cliente* cliente;
    Pacote* pacote;

    Reserva(Cliente* _cliente, Pacote* _pacote) {
        cliente = _cliente;
        pacote = _pacote;
    }
};

int main() {
    Cliente* cli01 = new Cliente("Bruno", "111111");
    Dependente* dep01 = new Dependente("Leane", cli01);
    Dependente* dep02 = new Dependente("Vinicius", cli01);

    cout << dep01->getResponsavel()->getNome() << endl;
    cout << dep02->getResponsavel()->getNome() << endl;

    cli01->setNome("Bruno Santana");

    cout << dep01->getResponsavel()->getNome() << endl;
    cout << dep02->getResponsavel()->getNome() << endl;

    Roteiro* r1 = new Roteiro(4, "Noite no Parque do Povo", 1);
    Deslocamento* d1 = new Deslocamento(1, "Hotel", "Noite Parque do Povo");
    Pernoite* p1 = new Pernoite(10, "Hotel");

    Pacote* bronze = new Pacote(r1);
    bronze->inserirEvento(d1);
    bronze->inserirEvento(p1);

    Reserva* reserva01 = new Reserva(cli01, bronze);

    for (auto el : bronze->getEventos()) {
        el->imprimir();
    }

    return 0;
}
