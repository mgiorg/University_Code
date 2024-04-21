
import java.awt.*;
import java.util.*;

import javax.swing.*;

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

	public LinkedList<Box> listaBox = new LinkedList<Box>();

	Integer DIMENSIONE_CAMPO, NUMERO_BOMBE;

	public GUI(String dim, String bombe) {

		//! TITOLO DELLA FINESTRA
		super("Campo Minato");
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.getContentPane().setLayout(new BorderLayout());

		UpperPanel.setLayout(new FlowLayout());
		MiddlePanel.setLayout(new BoxLayout(MiddlePanel, BoxLayout.Y_AXIS));
		LowerPanel.setLayout(new FlowLayout());

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

		this.DIMENSIONE_CAMPO = Integer.valueOf(dim);
		this.NUMERO_BOMBE = Integer.valueOf(bombe);

		int c = 0;
		for (int i = 0; i < DIMENSIONE_CAMPO; ++i) {
			JPanel panel = new JPanel(new FlowLayout());
			for (int j = 0; j < DIMENSIONE_CAMPO; ++j) {
				Box box = new Box(i, j);
				box.setOpaque(true);
				box.setVisible(true);
				box.setBorderPainted(false);
				box.setIndex(c);
				box.setPreferredSize(new Dimension(60, 60));
				box.setFont(new Font("Times New Roman", Font.BOLD, 20));
				box.addActionListener(act);
				listaBox.add(box);
				panel.add(box);
				c++;
			}
			MiddlePanel.add(panel);
		}
		
		log.setPreferredSize(new Dimension(200, 80));
		LowerPanel.add(log);

		this.GameRun  = false;
		this.GameReset = false;
		this.GameEnd  = false;
		startButton.setEnabled(true);
		resetButton.setEnabled(false);
		endButton.setEnabled(false);
		
		setSize(800, 800);
		setVisible(true);
		this.setLocationRelativeTo(null);
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
			startButton.setEnabled(false);
			resetButton.setEnabled(true);
			endButton.setEnabled(true);
		}
		
		for(Box b : this.listaBox) {
			if(!b.isMarked()) {
				b.setBackground(Color.GREEN);
			} else b.setBackground(Color.WHITE);
			// b.write();
			if(b.getNumBombe() >= 1) {
				b.setText(b.getNumBombe().toString());
			} else b.setText("");
		}
	}
	public int getDimension() {
		return DIMENSIONE_CAMPO;
	}
	public int getNumBombe() {
		return NUMERO_BOMBE;
	}
	public Box getListaIndex(int i) {
		return listaBox.get(i);
	}
	public LinkedList<Box> getListaBox() {
		return this.listaBox;
	}
	public void setListaBox(LinkedList<Box> lista) {
		this.listaBox = lista;
	}
}
