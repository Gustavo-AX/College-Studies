remover(_, [], []).
%caso queiramos remover:
remover(X, [X|R], Y) :- remover(X, R, Y).
%caso a cabeça seja diferente do numero que queremos remover:
remover(X, [Y|R], [Y|R1]) :- X \= Y, remover(X, R, R1).
