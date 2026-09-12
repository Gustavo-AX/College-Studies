%a cada chamada aumenta o X
nelementos([], 0).
nelementos([_|R], X) :- nelementos(R,Y), X is Y+1.
