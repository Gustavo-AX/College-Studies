concatenar([], L, L).
concatenar([X|L1], L2, [X|L3]) :- concatenar(L1, L2, L3).

%pego de lista e lista e concateno
linearizar([], []).
linearizar([X|R], L) :- linearizar(R, L1), concatenar(X, L1, L).
