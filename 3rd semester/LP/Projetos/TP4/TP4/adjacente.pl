%se um estiver do lado do outro, independente da ordem, é true
adjacente(A, B, [A, B|_]).
adjacente(A, B, [B, A|_]).
%comparo de dois em dois, se não for, chamo a função para o resto da lista.
adjacente(A, B, [_,_|R]) :- adjacente(A, B, R).	
