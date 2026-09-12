%passa por cada elemento da lista incrementando 1
incrementar([], []).
incrementar([X|L], [X1|L1]) :- X1 is X + 1, incrementar(L, L1).

