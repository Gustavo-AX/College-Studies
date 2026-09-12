compactar([], []).
%uma lista de um elemento tem 1 elemento
compactar([X], [[1, X]]).
%se dois elementos consecutivos n forem diferentes, aumenta o contador N
compactar([X, X|R], [[N, X] | T]) :- compactar([X|R], [[M, X] | T]), N is M + 1.
%se dois elemento consecutivos forem diferentes:
compactar([X, Y|R], [[1, X] | T]) :- X \= Y, compactar([Y|R], T).
