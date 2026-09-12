%Último de uma lista de um elemento é ele mesmo
ultimo([X], X).
%Se chamar com mais de um elemento, se tira a cabeça da lista e chama para o resto
ultimo([_|R], X) :- ultimo(R, X). 
