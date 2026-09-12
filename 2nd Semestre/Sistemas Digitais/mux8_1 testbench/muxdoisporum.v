module mux2_1(I0,I1,sel,s);
	output s;
		input I0,I1,sel;
			assign s = ((~sel) & I0|(sel & I1));
endmodule 