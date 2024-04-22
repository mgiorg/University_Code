
import java.awt.*;
import java.util.*;

import javax.imageio.*;
import javax.swing.*;

public class GUI extends JFrame{

	private final ActionHandler act = new ActionHandler(this);

	final JButton startButton = new JButton("Start");
	final JButton endButton = new JButton("End");
	
	final JTextArea log = new JTextArea();

	final JPanel UpperPanel = new JPanel();
	private JPanel MiddlePanel = new JPanel();
	final JPanel LowerPanel = new JPanel();
	final JPanel FieldPanel = new JPanel();

	public Boolean GameRun = false;
	private Boolean GameEnd = false;

	public LinkedList<Box> listaBox;

	Integer DIMENSIONE_CAMPO, NUMERO_BOMBE;

	public GUI() {

		//! TITOLO DELLA FINESTRA
		super("Campo Minato");
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.getContentPane().setLayout(new BorderLayout());

		UpperPanel.setLayout(new FlowLayout());
		LowerPanel.setLayout(new FlowLayout());

		this.getContentPane().add(UpperPanel, BorderLayout.NORTH);
		this.getContentPane().add(LowerPanel, BorderLayout.SOUTH);

		UpperPanel.add(startButton);
		UpperPanel.add(endButton);

		startButton.addActionListener(act);
		endButton.addActionListener(act);

		// this.DIMENSIONE_CAMPO = dim;
		// this.NUMERO_BOMBE = bombe;

		// int c = 0;
		// for (int i = 0; i < DIMENSIONE_CAMPO; ++i) {
		// 	JPanel panel = new JPanel(new FlowLayout());
		// 	for (int j = 0; j < DIMENSIONE_CAMPO; ++j) {
		// 		Box box = new Box(i, j);
		// 		box.setOpaque(true);
		// 		box.setVisible(true);
		// 		box.setBorderPainted(false);
		// 		box.setIndex(c);
		// 		box.setPreferredSize(new Dimension(60, 60));
		// 		box.setFont(new Font("Times New Roman", Font.BOLD, 20));
		// 		box.addActionListener(act);
		// 		listaBox.add(box);
		// 		panel.add(box);
		// 		c++;
		// 	}
		// 	MiddlePanel.add(panel);
		// }
		
		log.setPreferredSize(new Dimension(200, 80));
		LowerPanel.add(log);

		this.GameRun  = false;
		this.GameEnd  = false;
		startButton.setEnabled(true);
		endButton.setEnabled(false);
		
		this.pack();
		setVisible(true);
		this.setLocationRelativeTo(null);
	}
	public void insertBox(int dim, int bombe) {
		MiddlePanel.setLayout(new BoxLayout(MiddlePanel, BoxLayout.Y_AXIS));
		this.getContentPane().add(MiddlePanel, BorderLayout.CENTER);
		this.DIMENSIONE_CAMPO = dim;
		this.NUMERO_BOMBE = bombe;

		listaBox = new LinkedList<Box>();

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
	}
	
	public void write(String s) {
		if(s == null) {
			this.log.setText(null);
		}
		else log.append(s + "\n");
	}
	public void setStatus(Boolean Run, Boolean End) {
		this.GameRun=Run;
		this.GameEnd=End;
		update();
	}
	public void update() {
		if(GameRun) {
			startButton.setEnabled(false);
			endButton.setEnabled(true);
		}
		if(GameEnd) {
			startButton.setEnabled(true);
			endButton.setEnabled(false);
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
		this.pack();
	}
	public void showBombs() {
		for(Box b : this.listaBox) {
			if(b.isBomb()) {
				try {
					Image img = ImageIO.read(getClass().getResource("icons8-pene-64.png"));
					b.setBackground(Color.RED);
					b.setIcon(new ImageIcon(img));
				} catch (Exception ex) {
					System.out.println(ex);
				}
			}
		}
	}
	public void boxEnabled(boolean enabled) {
		for(Box b: this.listaBox) {
			b.setEnabled(enabled);
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
	public void deleteBoxPanel() {
		Component[] components = MiddlePanel.getComponents();
		for (Component component : components) {
			MiddlePanel.remove(component);
		}
	}
}
