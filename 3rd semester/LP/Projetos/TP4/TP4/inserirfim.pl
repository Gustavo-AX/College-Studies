%Se a lista estiver vazia, voltamos a lista com o elemento
inserirfim(X,[],[X]).
%Se não estiver vazia, o primeiro elemento (H) permance, e chamamos a função para o resto da lista
inserirfim(X,[H|R1],[H|R2]) :- inserirfim(X,R1,R2).
