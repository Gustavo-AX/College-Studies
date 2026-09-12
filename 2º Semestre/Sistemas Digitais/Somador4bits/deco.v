module deco(S,a,b,c,d,e,f,g);
input [0:3]S;
output a,b,c,d,e,f,g;
assign a = (~S[0]&~S[1]&~S[2]&S[3])|(~S[0]&S[1]&~S[2]&~S[3]);
assign b = (~S[0]&S[1]&~S[2]&S[3])|(~S[0]&S[1]&S[2]&~S[3]);
assign c = (~S[0]&~S[1]&S[2]&~S[3]);
assign d = (~S[0]&~S[1]&~S[2]&S[3])|(~S[0]&S[1]&~S[2]&~S[3])|(~S[0]&S[1]&S[2]&S[3]);
assign e = (~S[0]&S[3])|(~S[1]&~S[2]&S[3])|(~S[0]&S[1]&~S[2]);
assign f = (~S[0]&~S[1]&~S[2]&S[3])|(~S[0]&~S[1]&S[2]&~S[3])|(~S[0]&~S[1]&S[2]&S[3])|(~S[0]&S[1]&S[2]&S[3]);
assign g = (~S[0]&~S[1]&~S[2])|(~S[0]&S[1]&S[2]&S[3]);
endmodule

