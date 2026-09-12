%utilizando um algoritmo de ordenação por intercalação:
%separa a lista entre A e B fazendo N listas de um elemento.
separa([],[],[]).
separa([X],[X],[]).
separa([X,Y|R],[X|A],[Y|B]) :- separa(R,A,B). 

%intercala A e B de acordo com o maior:
%se for um elemento e uma lista vazia:
intercala([],X,X).
intercala(X,[],X).
%se Y maior ou igual a X
intercala([X|A],[Y|B],[X|R]) :- X =< Y, intercala(A,[Y|B],R).
%else
intercala([X|A],[Y|B],[Y|R]) :-X > Y, intercala([X|A],B,R). 

%pega lista, separa ela e faz a intercalação
ordenar([], []).
ordenar([X], [X]).
ordenar([X,Y|R],L) :- separa([X,Y|R],A,B), ordenar(A,A1), ordenar(B,B1), intercala(A1,B1,L). 
