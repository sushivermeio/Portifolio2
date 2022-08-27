
package alberto;

import javax.swing.JOptionPane;


public class Alberto {


    public static void main(String[] args) {
        JOptionPane.showMessageDialog(null, "se clicar 'ok' é gay");
        String s = JOptionPane.showInputDialog("qual é o nome do gayzão?");
        JOptionPane.showMessageDialog(null, "pourra "+s+" quer dar o cu?");
        String resposta1 = JOptionPane.showInputDialog("quem é gay?");
        if(resposta1.equals("pedro dias")){
            JOptionPane.showConfirmDialog(null, "acerto");
        }
        else{
            JOptionPane.showMessageDialog(null,"mlk burro errouKKKKKKKKK");
        }
    }
    
}
