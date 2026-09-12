concatenar([], L, L).
concatenar([X|L1], L2, [X|L3]) :- concatenar(L1, L2, L3).

%retiro o primeiro elemento e concateno
rotacionar([], []).
rotacionar([X|R], L) :- concatenar(R,[X],L).
