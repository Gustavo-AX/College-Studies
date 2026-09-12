package com.mycompany.academia;
import java.util.Scanner;


public class Academia {
    public static void main(String[] args) {
      Scanner entrada = new Scanner(System.in);

// declaração das turmas

Turma[] turmas= new Turma[6];
for(int i=0;i<=5;i++) {
	turmas[i]=new Turma();
}

turmas[0].setDescricao("manhã feminino de 9 a 12 anos");
turmas[1].setDescricao("tarde feminino de 13 a 18 anos");
turmas[2].setDescricao("noite feminino de 19 a 30 anos");
turmas[3].setDescricao("manhã masculino de 9 a 12 anos");
turmas[4].setDescricao("tarde masculino de 13 a 18 anos");
turmas[5].setDescricao("noite masculino de 19 a 30 anos");

//declaração do array com os alunos
//fiz com 3 alunos para teste, podemos mudar esse número

Aluno[] alunos = new Aluno[3];
for(int i=0; i<=2; i++){
alunos[i] = new Aluno();
System.out.println("Digite o nome do aluno " + (i+1) + ";");
alunos[i].setNome(entrada.nextLine());
System.out.println("Digite o sexo do aluno:");
alunos[i].setSexo(entrada.nextLine());
System.out.println("Digite a idade do aluno:");
alunos[i].setIdade(entrada.nextInt());
System.out.println("Digite o peso do aluno:");
alunos[i].setPeso(entrada.nextDouble());
System.out.println("Digite a altura do aluno:");
alunos[i].setAltura(entrada.nextDouble());
entrada.nextLine();
System.out.println("Digite o telefone do aluno:");
alunos[i].setTelContato(entrada.nextLine());

//aqui eu destino os alunos à suas respectivas turmas

if(9<=alunos[i].getIdade() && alunos[i].getIdade() <= 12 && "Feminino".equals(alunos[i].getSexo()))
turmas[0].adicionarAluno(alunos[i]);
if(9<=alunos[i].getIdade() && alunos[i].getIdade() <= 12 && "Masculino".equals(alunos[i].getSexo()))
turmas[3].adicionarAluno(alunos[i]); 
if(13<=alunos[i].getIdade() && alunos[i].getIdade() <= 18 && "Feminino".equals(alunos[i].getSexo()))
turmas[1].adicionarAluno(alunos[i]);
if(13<=alunos[i].getIdade() && alunos[i].getIdade() <= 18 && "Masculino".equals(alunos[i].getSexo()))
turmas[4].adicionarAluno(alunos[i]);
if(19<=alunos[i].getIdade() && alunos[i].getIdade() <= 30 && "Feminino".equals(alunos[i].getSexo()))
turmas[2].adicionarAluno(alunos[i]);
if(19<=alunos[i].getIdade() && alunos[i].getIdade() <= 30 && "Masculino".equals(alunos[i].getSexo()))
turmas[6].adicionarAluno(alunos[i]);
}

for(int i=0;i<5;i++){
	turmas[i].exibirTurmaAlunos();
}

    }
}
