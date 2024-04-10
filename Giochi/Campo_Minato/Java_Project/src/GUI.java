import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionListener;

public class GUI extends JFrame{

	private final ActionListener act = new ActionHandler(this);

	final JButton startButton = new JButton("Start");
	final JButton endButton = new JButton("End");
	final JTextField num_bomb = new JTextField("", 3);
	final JTextField dim_campo = new JTextField("", 3);

	final JPanel UpperPanel = new JPanel();
	final JPanel MiddlePanel = new JPanel();
	final JPanel LowerPanel = new JPanel();
	final JPanel FieldPanel = new JPanel();

	TicketCell b[][] = new TicketCell[10][10];
	
	public GUI() {
		//! TITOLO DELLA FINESTRA
		super("Campo Minato");
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.getContentPane().setLayout(new BorderLayout());

		UpperPanel.setLayout(new FlowLayout());
		MiddlePanel.setLayout(new FlowLayout());
		LowerPanel.setLayout(new FlowLayout());
		FieldPanel.setLayout(new GridLayout(10, 10));
		FieldPanel.setPreferredSize(new Dimension(500, 500));

		this.getContentPane().add(UpperPanel, BorderLayout.NORTH);
		this.getContentPane().add(MiddlePanel, BorderLayout.CENTER);
		this.getContentPane().add(LowerPanel, BorderLayout.SOUTH);

		UpperPanel.add(startButton);
		UpperPanel.add(new JLabel("Dimensione Campo"));
		UpperPanel.add(dim_campo);
		UpperPanel.add(new JLabel("Numero Bombe"));
		UpperPanel.add(num_bomb);
		UpperPanel.add(endButton);


		for (int i = 0; i < 10; ++i) {
			for (int j = 0; j < 10; ++j) {
				b[i][j] = new TicketCell();
				b[i][j].setBorder(BorderFactory.createLineBorder(Color.GRAY));
				FieldPanel.add(b[i][j]);
			}
		}
		FieldPanel.setSize(450, 450);
		MiddlePanel.add(FieldPanel);
		
		
		setSize(600, 1000);
		setVisible(true);
	}
	


}
