gerar(X, X, [X]).
%cria uma lista com o menor e vai adcionando, ps: considero que sempre vira o intervalo de forma crescente
gerar(X, Y, [X|R]) :- X < Y, N is X + 1, gerar(N, Y, R).

