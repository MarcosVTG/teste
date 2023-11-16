package teste;

import java.util.Scanner;

public class Cliente {
    private String nome;
    private int idade;
    private String cpf;


    public Cliente(String nome, String cpf) {
        this.nome = nome;
        this.idade = 0; 
        this.cpf = cpf;
    }
    public String getNome() {
        return nome;
    }
    public void setNome(String nome) {
        this.nome = nome;
    }

    public int getIdade() {
        return idade;
    }
    public void setIdade(int idade) {
        this.idade = idade;
    }
    public String getCpf() {
        return cpf;
    }
    public void setCpf(String cpf) {
        this.cpf = cpf;
    }
    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);

        System.out.print("Digite o nome do cliente: ");
        String nome = scanner.nextLine();

        System.out.print("Digite o CPF do cliente: ");
        String cpf = scanner.nextLine();

      
        Cliente cliente = new Cliente(nome, cpf);

 
        System.out.println("\nDados do Cliente:");
        System.out.println("Nome: " + cliente.getNome());
        System.out.println("Idade: " + cliente.getIdade());
        System.out.println("CPF: " + cliente.getCpf());

     
        System.out.println("\nAlteração de Dados:");

        System.out.print("Digite a nova idade: ");
        int novaIdade = scanner.nextInt();
        cliente.setIdade(novaIdade);

   
        System.out.println("\nDados Atualizados do Cliente:");
        System.out.println("Nome: " + cliente.getNome());
        System.out.println("Idade: " + cliente.getIdade());
        System.out.println("CPF: " + cliente.getCpf());

 
        scanner.close();
    }
}

