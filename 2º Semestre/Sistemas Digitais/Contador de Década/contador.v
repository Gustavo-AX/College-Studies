//Preset = SW[0]
//reset = SW[1]
/*Nomes: Gustavo Assis e Arthur Bracarense
contador de 0 a 9 
*/
module contador(CLOCK_50, reset, preset , HEX0);
input CLOCK_50, preset, reset;
output [0:6] HEX0;

//variavel intermediaria

reg [3:0] Q;

wire clock_novo;

divisor MEC(CLOCK_50, clock_novo);

// posedge ou o negedge

always@(posedge clock_novo or posedge reset or posedge preset)
begin 

	if(reset==1'b1)
		begin
		Q<=4'b000;
		end
		
	else if(preset == 1'b1)
			begin
			Q<=4'b1001;
			end
	
		else
			begin
			
			if(Q == 4'b1001)
				begin
					Q <= 4'b0000;
				end
			else
				begin
					Q<=Q + 1'b1;
				end
				
			end
		
		
		
		
	end //end always
	
decod ELT(Q[3:0], HEX0[0:6]);
	
endmodule
