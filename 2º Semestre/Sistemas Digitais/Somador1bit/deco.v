module deco(Ts,S,a,b,c,d,e,f,g);
input Ts,S;
output a,b,c,d,e,f,g;
assign a = ((~Ts)& S);
assign b = 0;
assign c = ((~S)& Ts);
assign d = ((~Ts)& S);
assign e = S;
assign f = (Ts|S);
assign g = (~Ts);
endmodule 