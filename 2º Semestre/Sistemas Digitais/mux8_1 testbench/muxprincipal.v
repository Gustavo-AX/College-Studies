/*

Arthur Bracarense e Gustavo de Assis - Projeto MUX com Test Bench

Chaves Seletoras: A e B

Clock do MUX 2:1 feito pelo modulo testebench2canais

*/

module muxprincipal (X0,X1,X2,X3,A,B,SAIDA);
	input X0,X1,X2,X3; // Entrada de dados 
	input A,B; // Entradas de seleção
		output SAIDA; // Saida de dados
			wire SAIDAINTERMED0, SAIDAINTERMED1;
	// Chamando os primeiros blocos do multiplexador
	mux2_1 BLOCO0 (X0,X1,B,SAIDAINTERMED0);
	mux2_1 BLOCO1 (X2,X3,B,SAIDAINTERMED1);
	// Chamando o último bloco do multiplexador
	mux2_1 BLOCOFINAL (SAIDAINTERMED0, SAIDAINTERMED1, A, SAIDA);
endmodule
