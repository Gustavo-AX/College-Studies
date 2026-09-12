module somadorumbit(A,B,Te,HEX0);
input A,B,Te;
output [0:6]HEX0;
wire Ts,S;
assign S = ((A^B)^Te);
assign Ts = ((A&B)|(A&Te)|(B&Te));
deco(Ts,S,HEX0[0],HEX0[1],HEX0[2],HEX0[3],HEX0[4],HEX0[5],HEX0[6]);
endmodule
