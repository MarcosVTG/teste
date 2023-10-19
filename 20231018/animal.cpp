#include <iostream>
using namespace std;


class Animal {
    public:
    virtual void som() {
        cout << "Som genérico de um animal" << endl;
    }
    };

    class Cachorro : public Animal {
        public:
        void som () override {
            cout << "Latido de cachorro" << endl;
        }
    };
class Gato : public Animal {
    public:
    void som () override {
        cout << "Miado de Gato" << endl;
    }
};

int main () {
Animal*animal;

Cachorro cachorro;
Gato gato;
 animal = &cachorro;
 animal ->som();

 animal =&gato;
 animal ->som();

 return 0;
}





