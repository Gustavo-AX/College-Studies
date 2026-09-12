nelementos([], 0).
nelementos([_|R], X) :- nelementos(R,Y), X is Y+1.

soma([], 0).
soma([X|R], S) :- soma(R,Y), S is X+Y.

%soma a lista e divide pelo numero de elementos
medio([X], X).
medio(L, M) :- soma(L, S), nelementos(L, N), M is S/N. 
