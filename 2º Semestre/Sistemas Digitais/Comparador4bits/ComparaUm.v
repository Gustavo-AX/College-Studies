// Comparador bit a bit

module ComparaUm(A,B,Enable,Ig,Me,Ma);
input A,B,Enable;
output Ig,Ma,Me;

assign Me = Enable & (~A & B);
assign Ma = Enable & (A & ~B);
assign Ig = Enable & (A & B)|(~A & ~B);

endmodule

