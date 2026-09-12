%retorno X se ele for maior, se n, M
maior([X], X).
maior([X|R], X) :- maior(R, M), X >= M.
maior([X|R], M) :- maior(R, M), X < M. 
