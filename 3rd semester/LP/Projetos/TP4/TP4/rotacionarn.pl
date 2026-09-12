concatenar([], L, L).
concatenar([X|L1], L2, [X|L3]) :- concatenar(L1, L2, L3).

%retiro o primeiro elemento e concateno
rotacionar([], []).
rotacionar([X|R], L) :- concatenar(R,[X],L).

%rotaciono N vezes a lista
rotacionarn(0 ,P ,P).
rotacionarn(N, L, R) :- N > 0, N1 is N - 1, rotacionar(L,P), rotacionarn(N1, P, R).

