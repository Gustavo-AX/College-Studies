/* NOMES: Arthur e Gustavo 
Somador de 4 bits - 06/10/2022
[3:0]A = [17:14]SW
[3:0]B = [3:0]SW
SAIDAS:
HEX0 -- UNIDADE
HEX1 -- DEZENA
*/

module somaquatro(A,B, HEX0, HEX1);
input [3:0] A,B;
wire Te;
wire [3:0] Ts;
wire [0:3] Dezena,Unidade;
wire [4:0] S;
output [0:6] HEX0,HEX1;
somadorumbit (A[0],B[0],Te,Ts[0],S[0]);
somadorumbit (A[1],B[1],Ts[0],Ts[1],S[1]);
somadorumbit (A[2],B[2],Ts[1],Ts[2],S[2]);
somadorumbit (A[3],B[3],Ts[2],Ts[3],S[3]);
assign S[4]=Ts[3];
assign Dezena = S/10;
assign Unidade = S%10;
deco(Dezena,HEX1[0],HEX1[1],HEX1[2],HEX1[3],HEX1[4],HEX1[5],HEX1[6]);
deco(Unidade,HEX0[0],HEX0[1],HEX0[2],HEX0[3],HEX0[4],HEX0[5],HEX0[6]);
endmodule 
