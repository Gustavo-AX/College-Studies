module somadorumbit(A,B,Te,Ts,S);
input A,B,Te;
output Ts, S;
assign S = ((A^B)^Te);
assign Ts = ((A&B)|(A&Te)|(B&Te));
endmodule
