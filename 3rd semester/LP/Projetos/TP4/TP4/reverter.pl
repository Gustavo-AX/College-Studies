concatenar([], L, L).
concatenar([X|L1], L2, [X|L3]) :- concatenar(L1, L2, L3).

%separa a cabeça e concatena com o resto
reverter([],[]).
reverter([X|R], L) :- reverter(R, T), concatenar(T, [X], L). 
