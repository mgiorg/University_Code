import javax.swing.*;
import java.awt.*;
import java.util.*;

public class GUI extends JFrame {

	Act act = new Act(this);

	JPanel cartellaPanel = new JPanel(new BorderLayout());
	LinkedList<TicketCell> ticketCells = new LinkedList<TicketCell>();

	JPanel logPanel = new JPanel(new BorderLayout());
	JTextArea logArea = new JTextArea(120, 30);
	JScrollPane logPane = new JScrollPane(logArea);

	JButton connectButton = new JButton("Connect");
	JButton disconnectButton = new JButton("Disconnect");
	JButton startButton = new JButton("Start");
	JButton stopButton = new JButton("Stop");

	public GUI() {
		super("Massimo Giordano 2084173");
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.getContentPane().setLayout(new BorderLayout());

		JLabel ipLabel = new JLabel("Server Address");
		JTextField ipField = new JTextField("80.211.232.219", 25);

		JLabel portLabel = new JLabel("Port");
		JTextField portField = new JTextField("4400", 10);
		
		connectButton.addActionListener(act);
		disconnectButton.addActionListener(act);
		startButton.addActionListener(act);
		stopButton.addActionListener(act);

		this.add(ipLabel, BorderLayout.NORTH);
		this.add(ipField, BorderLayout.NORTH);
		this.add(portLabel, BorderLayout.NORTH);
		this.add(portField, BorderLayout.NORTH);
		this.add(connectButton, BorderLayout.NORTH);
		this.add(disconnectButton, BorderLayout.NORTH);

		ArrayList<Integer> numeri = generateNumbers();

		JPanel matrice = new JPanel(new GridLayout(1, 5));
		for(int i = 0; i < 5; ++i) {
			JPanel panel = new JPanel(new GridLayout(3, 1));
			for(int j = 0; j < 3; ++j) {
				TicketCell cell = new TicketCell(numeri.get(3*i+j));
				cell.setPreferredSize(new Dimension(100, 100));
				ticketCells.add(cell);
				panel.add(cell);
			}
			matrice.add(panel);
		}
		cartellaPanel.add(matrice);
		cartellaPanel.setBorder(BorderFactory.createTitledBorder("Cartella"));


		this.add(cartellaPanel, BorderLayout.CENTER);
		this.add(logPanel, BorderLayout.EAST);

		this.pack();
		this.setVisible(true);
	}

	public ArrayList<Integer> generateNumbers() {
		Random random = new Random();
		ArrayList<Integer> numbers = new ArrayList<Integer>();
		for(int i = 0; i < 15; ++i) {
			Integer numero = random.nextInt(90);
			if(!numbers.contains(numero)) numbers.add(numero);
			else --i;
		}
		return numbers;
	}

	public void reset() {
		for(TicketCell cell : ticketCells) {
			cell.setSelected(false);
		}
	}
}
