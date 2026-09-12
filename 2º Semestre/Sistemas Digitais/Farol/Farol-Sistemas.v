//cabeçalho
//acende o sinalizador caso a porta desteja aberta ou a  chave ta out da ignição
//Arthur Bracarense e Gustavo Assis
//P = Porta, C = chave;

module farol (F,P,C,S);
input F,P,C;
output S;
assign S = (F & ~P & ~C)|(F & ~P & C)| (F & P & ~C);

endmodule
