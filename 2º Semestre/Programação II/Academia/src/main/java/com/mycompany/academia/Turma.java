package com.mycompany.academia;

public class Turma {
private String descricao;
private Aluno[] alunos;
//Aqui eu determino que cada turma vai ter 10 alunos
    public Turma() {
        this.alunos = new Aluno[10];
    }

public void setAlunos(Aluno[] alunos){
this.alunos=alunos;
}

public Aluno[] getAlunos(){
return this.alunos;
}

public void setDescricao(String descricao){
this.descricao=descricao;
}

public String getDescricao(){
return this.descricao;
}

public boolean adicionarAluno(Aluno aluno){
//nesse caso, cada turma pode ter 10 alunos
for(int i=0; alunos.length>i ; i++){
if(alunos[i]==null){
alunos[i]=aluno;
return true;
}
}
System.out.println("A turma não tem mais espaço");
return false;
}


public void exibirTurmaAlunos(){ 
for(int i=0; alunos.length>=i && alunos[i]!=null;i++){
System.out.println(alunos[i].getNome());
}
}
}
