
import java.util.*;
import java.awt.*;
import javax.swing.*;

public class Finestra extends JFrame{

	JButton start = new JButton("Start");
	JButton end = new JButton("End");
	JButton restart = new JButton("Restart");

	JTextArea log = new JTextArea(1, 8);

	TicketCell b[][] = new TicketCell[10][10];

	JPanel top = 	new JPanel();
	JPanel middle = new JPanel();
	JPanel bottom = new JPanel();
	JPanel cella = new JPanel();

	GridLayout gl = new GridLayout(10, 10);

	public Finestra() {
		super("Campo Minato");

		top.add(start);
		top.add(end);
		top.add(restart);
		this.add(top, BorderLayout.NORTH);

		cella.setPreferredSize(new Dimension(500, 500));
		cella.setLayout(gl);

		for(int i = 0; i < 10; i++) {
			for(int j = 0; j < 10; j++) {
				b[i][j] = new TicketCell();
				b[i][j].setBorder(BorderFactory.createLineBorder(Color.GRAY));
				cella.add(b[i][j]);
			}
		}
		middle.add(cella);
		this.add(middle);

		setSize(400, 800);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setVisible(true);
	}
	


}
