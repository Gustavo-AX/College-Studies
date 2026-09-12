// Criar estimulos para o MUX de dois canais
module testbench2canais;
	reg Clock_I0,Clock_I1;
	reg Clock_sel;
		wire Clock_s;
parameter stop_time = 1000;

mux2_1 DUT (Clock_I0,Clock_I1,Clock_sel,Clock_s);

initial 
	begin
//		repeat(3)
//			begin
			Clock_I0 = 0; Clock_I1 = 0 ; Clock_sel = 0;
			#10;
/*			Clock_I0 = 0; Clock_I1 = 1 ; Clock_sel = 1;
			#10
			Clock_I0 = 0; Clock_I1 = 0 ; Clock_sel = 1;
			#10
			Clock_I0 = 1; Clock_I1 = 1 ; Clock_sel = 1;
			#10
			Clock_I0 = 1; Clock_I1 = 0 ; Clock_sel = 0;
			#10
			Clock_I0 = 1; Clock_I1 = 1 ; Clock_sel = 0;
			#10
			Clock_I0 = 0; Clock_I1 = 0 ; Clock_sel = 0;
			#10;
			end
*/
end
always #100 Clock_sel = ~Clock_sel;
always #10 Clock_I0 = ~Clock_I0;
always #50 Clock_I1 = ~Clock_I1;
endmodule 