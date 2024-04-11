import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.*;

public class GUI extends JFrame{

	private final ActionHandler act = new ActionHandler(this);

	final JButton startButton = new JButton("Start");
	final JButton endButton = new JButton("End");
	final JButton resetButton = new JButton("Reset");
	
	final JTextField num_bomb = new JTextField("", 3);
	final JTextField dim_campo = new JTextField("", 3);
	final JTextArea log = new JTextArea();

	final JPanel UpperPanel = new JPanel();
	final JPanel MiddlePanel = new JPanel();
	final JPanel LowerPanel = new JPanel();
	final JPanel FieldPanel = new JPanel();

	public Boolean GameRun = false;
	private Boolean GameEnd = false;
	private Boolean GameReset = false;

	public LinkedList<Box> griglia=new LinkedList<Box>();
	public LinkedList<JPanel> righe = new LinkedList<JPanel>();

	int dimension, bomb;

	
	
	public GUI(int dim, int b) {
		//! TITOLO DELLA FINESTRA
		super("Campo Minato");
		setSize(600, 600);
		setVisible(true);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.getContentPane().setLayout(new BorderLayout());

		UpperPanel.setLayout(new FlowLayout());
		MiddlePanel.setLayout(new BoxLayout(MiddlePanel, BoxLayout.Y_AXIS));
		LowerPanel.setLayout(new FlowLayout());
		// FieldPanel.setLayout(new GridLayout(10, 10));
		// FieldPanel.setPreferredSize(new Dimension(500, 500));

		this.getContentPane().add(UpperPanel, BorderLayout.NORTH);
		this.getContentPane().add(MiddlePanel, BorderLayout.CENTER);
		this.getContentPane().add(LowerPanel, BorderLayout.SOUTH);

		UpperPanel.add(startButton);
		UpperPanel.add(new JLabel("Dimensione Campo"));
		UpperPanel.add(dim_campo);
		UpperPanel.add(new JLabel("Numero Bombe"));
		UpperPanel.add(num_bomb);
		UpperPanel.add(resetButton);
		UpperPanel.add(endButton);

		startButton.addActionListener(act);
		resetButton.addActionListener(act);
		endButton.addActionListener(act);


		for (int i = 0; i < 10; ++i) {
			JPanel panel = new JPanel(new FlowLayout());
			for (int j = 0; j < 10; ++j) {
				Box box = new Box(i, j);
				box.setPreferredSize(new Dimension(30, 30));
				// boxArea[i][j].addActionListener(new ActionListener() {
				// 	@Override
				// 	public void actionPerformed(ActionEvent e) {
				// 		Box clickedButton = (Box) e.getSource();
				// 		log.append("Riga: "+clickedButton.getRiga()+", Colonna: "+clickedButton.getColonna()+"\n");
						
				// 	}
				// });
				box.addActionListener(act);
				panel.add(box);
			}
			MiddlePanel.add(panel);
		}
		
		log.setPreferredSize(new Dimension(100, 80));
		LowerPanel.add(log);

		this.GameRun  = false;
		this.GameReset = false;
		this.GameEnd  = false;
	}
	
	public void write(String s) {
		log.append(s + "\n");
	}
	public void setStatus(Boolean Run, Boolean End, Boolean Reset) {
		this.GameRun=Run;
		this.GameEnd=End;
		this.GameReset = Reset;
		update();
	}
	public void update() {
		if(GameRun) {
			startButton.setEnabled(false);
			resetButton.setEnabled(true);
			endButton.setEnabled(true);
		}
		if(GameEnd) {
			startButton.setEnabled(true);
			resetButton.setEnabled(true);
			endButton.setEnabled(false);
		}
		if(GameReset) {
			startButton.setEnabled(true);
			resetButton.setEnabled(false);
			endButton.setEnabled(true);
		}
	}
}
