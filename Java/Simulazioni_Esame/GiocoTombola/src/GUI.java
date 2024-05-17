
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

	JLabel ipLabel = new JLabel("Server Address");
	JTextField ipField = new JTextField("127.0.0.1", 17);

	JLabel portLabel = new JLabel("Port");
	JTextField portField = new JTextField("4400", 10);

	Boolean connected, transmitting;

	public GUI() {
		super("Massimo Giordano 2084173");
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.getContentPane().setLayout(new BorderLayout());
		
		connectButton.setActionCommand("Connect");
		connectButton.addActionListener(act);

		disconnectButton.setActionCommand("Disconnect");
		disconnectButton.addActionListener(act);

		startButton.setActionCommand("Start");
		startButton.addActionListener(act);

		stopButton.setActionCommand("Stop");
		stopButton.addActionListener(act);

		JPanel topPanel = new JPanel();
		topPanel.add(ipLabel);
		topPanel.add(ipField);
		topPanel.add(portLabel);
		topPanel.add(portField);
		topPanel.add(connectButton);
		topPanel.add(disconnectButton);

		this.add(topPanel, BorderLayout.NORTH);
	
		ArrayList<Integer> numeri = generateNumbers();

		JPanel matrice = new JPanel(new GridLayout(1, 5));
		for(int i = 0; i < 5; ++i) {
			JPanel panel = new JPanel(new GridLayout(3, 1));
			for(int j = 0; j < 3; ++j) {
				TicketCell cell = new TicketCell(numeri.get(3*i+j));
				cell.setBorder(BorderFactory.createLineBorder(Color.BLACK));
				ticketCells.add(cell);
				panel.add(cell);
			}
			matrice.add(panel);
		}
		cartellaPanel.add(matrice);
		cartellaPanel.setBorder(BorderFactory.createTitledBorder("Cartella"));

		logPanel.setBorder(BorderFactory.createTitledBorder("Log"));
		logArea.setEditable(false);
		logPanel.add(logPane);
		logPanel.setPreferredSize(new Dimension(300, 300)); 

		this.add(cartellaPanel, BorderLayout.CENTER);
		this.add(logPanel, BorderLayout.EAST);

		JPanel bottomPanel = new JPanel();
		bottomPanel.add(startButton);
		bottomPanel.add(stopButton);
		this.add(bottomPanel, BorderLayout.SOUTH);

		setStatus(false, false);
		this.pack();
		this.setVisible(true);
	}

	public ArrayList<Integer> generateNumbers() {
		Random random = new Random();
		ArrayList<Integer> numbers = new ArrayList<Integer>();
		while(numbers.size() < 15) {
			Integer numero = random.nextInt(90);
			if(!numbers.contains(numero)) numbers.add(numero);
		}
		Collections.sort(numbers);
		return numbers;
	}

	public void reset() {
		for(TicketCell cell : ticketCells) {
			cell.setSelected(false);
		}
	}
	public int getPort() {
		return Integer.parseInt(portField.getText());
	}
	public String getIP() {
		return ipField.getText();
	}
	public void setStatus(Boolean connected, Boolean transmitting) {
		this.connected = connected;
		this.transmitting = transmitting;

		update();
	}
	public void update() {
			if (!connected) {
				connectButton.setEnabled(true);
				disconnectButton.setEnabled(false);
				startButton.setEnabled(false);
				stopButton.setEnabled(false);
			}
			else if (!transmitting) {
				connectButton.setEnabled(false);
				disconnectButton.setEnabled(true);
				startButton.setEnabled(true);
				stopButton.setEnabled(false);
			} else {
				connectButton.setEnabled(false);
				disconnectButton.setEnabled(true);
				startButton.setEnabled(false);
				stopButton.setEnabled(true);
			}
	}
	public void write(String s) {
		logArea.append(s);
	}
	public LinkedList<TicketCell> getCells() {
		return this.ticketCells;
	}
}
