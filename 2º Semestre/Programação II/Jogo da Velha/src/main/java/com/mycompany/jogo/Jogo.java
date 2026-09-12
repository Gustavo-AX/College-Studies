package com.mycompany.jogo;

import java.util.Scanner;

//Obs: Eu usei a palette do NetBeans para me auxiliar a fazer o desing :)
//também não registrei as callbacks por que falou no arquivo que a gente 
//vai fazer na prox aula

public class Jogo {

    public static void main(String[] args) {
          /* Set the Nimbus look and feel */
        //<editor-fold defaultstate="collapsed" desc=" Look and feel setting code (optional) ">
        /* If Nimbus (introduced in Java SE 6) is not available, stay with the default look and feel.
         * For details see http://download.oracle.com/javase/tutorial/uiswing/lookandfeel/plaf.html 
         */
        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(JanelaPrincipal.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(JanelaPrincipal.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(JanelaPrincipal.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(JanelaPrincipal.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new JanelaPrincipal().setVisible(true);
            }
        });
      
        Scanner entrada=new Scanner(System.in);
        boolean verificador;
        int jogador=2;
        
        JogoDaVelha jogo = new JogoDaVelha();
        while(jogo.verificaFimDeJogo()!=true){
            //defino que cada hora o jogador muda;
            if(jogador==2)
                jogador=1;
            else
                jogador=2;
                       
            jogo.printTabuleiro();
            System.out.println("digite a linha e coluna a ser marcada");
            verificador=jogo.fazJogada(entrada.nextInt()-1, entrada.nextInt()-1, jogador);
            System.out.println();
            
            //se o jogador fizer uma jogada invalida, eu mudo os dois, para que quando reinicie 
            //o ciclo, o mesmo jogador refaça a jogada
            if(verificador==false){
                System.out.println("jogada inválida");
                if(jogador==2)
                jogador=1;
            else
                jogador=2;
            }
        }
        jogo.printTabuleiro();
        
    }
}
