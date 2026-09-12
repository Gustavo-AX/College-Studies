/* Projeto 4
 Arthur Bracarense - Gustavo Assis    
O que faz: compara dois numeros de 4 bits, indicando se maior, menor ou igual. 
*/

module ComparadorQuatro(A,B,Igual,Menor,Maior);
input [3:0] A,B;
output Igual,Menor,Maior;

wire [3:0] aux_igual, aux_menor, aux_maior;

ComparaUm  BIT3 (A[3],B[3],1,aux_igual[3], aux_menor[3], aux_maior[3]);
ComparaUm  BIT2 (A[2],B[2],aux_igual[3],aux_igual[2], aux_menor[2], aux_maior[2]);
ComparaUm  BIT1 (A[1],B[1],aux_igual[2],aux_igual[1], aux_menor[1], aux_maior[1]);
ComparaUm  BIT0 (A[0],B[0],aux_igual[1],aux_igual[0], aux_menor[0], aux_maior[0]);

assign Igual = aux_igual[3] & aux_igual[2] & aux_igual[1] & aux_igual[0];
assign Menor = aux_menor[3]|aux_menor[2]|aux_menor[1]|aux_menor[0];
assign Maior = aux_maior[3]|aux_maior[2]|aux_maior[1]|aux_maior[0];

endmodule