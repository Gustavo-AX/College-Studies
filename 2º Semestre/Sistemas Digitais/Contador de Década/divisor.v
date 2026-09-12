module divisor(CLOCK_50, clock_novo);
input CLOCK_50; // saida Q[20] 50M/2^21
//variavel intermediaria
output clock_novo; 
reg[25:0] Q; //contador de 21 bits

initial 
	begin
		Q=20'b000;
	end
	
always @ (posedge CLOCK_50)
	begin
		Q<=Q+1;
	end

assign clock_novo=Q[25]; // clock_novo = 50M/2^21 = 23Hz
endmodule
