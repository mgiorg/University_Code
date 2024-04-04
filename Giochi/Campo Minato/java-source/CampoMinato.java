import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class CampoMinato {
    private JFrame frame;
    private JButton[][] buttons;
    private int rows = 9; // Numero di righe
    private int cols = 9; // Numero di colonne
    private int mines = 10; // Numero di mine

    public CampoMinato() {
        frame = new JFrame("Campo Minato");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLayout(new GridLayout(rows, cols));

        buttons = new JButton[rows][cols];
        initializeButtons();

        frame.pack();
        frame.setVisible(true);
    }

    private void initializeButtons() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                buttons[i][j] = new JButton();
                buttons[i][j].setFont(new Font("Arial", Font.PLAIN, 20));
                buttons[i][j].addActionListener(new ButtonClickListener(i, j));
                frame.add(buttons[i][j]);
            }
        }
    }

    private class ButtonClickListener implements ActionListener {
        private int row;
        private int col;

        public ButtonClickListener(int row, int col) {
            this.row = row;
            this.col = col;
        }

        @Override
        public void actionPerformed(ActionEvent e) {
            // Qui puoi implementare la logica per rivelare la casella e gestire le mine
            // Ad esempio, se il bottone è una mina, mostra un messaggio di perdita
            // Altrimenti, mostra il numero di mine vicine
            buttons[row][col].setText("X"); // Esempio: mostra una "X" per le mine
        }
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> new CampoMinato());
    }
}
