/*
Nomes: Gustavo de Assis Xavier e Arthur 
*/
module projetocincomux (I0, I1, sel, out);
input I0, I1, sel; //I0 - input 0 e I1 - input 1
output out;
assign out = (~sel & I1)|(sel & I0);

endmodule