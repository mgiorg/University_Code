import javax.swing.*;
import java.awt.*;
import java.util.*;

public class GUI extends JFrame {
	Act act = new Act(this);

	JButton start = new JButton("Start");
	JButton stop = new JButton("Interrompi");
	JButton connect = new JButton("Connect");
	JButton disconnect = new JButton("Disconnect");
	JButton clear = new JButton("Clear");

	JTextField portField = new JTextField("4400", 8);
	JTextField ipField = new JTextField("127.0.0.1", 15);

	JPanel centralPanel = new JPanel(new GridLayout(1, 5));
	LinkedList<ColoredButton> buttons = new LinkedList<ColoredButton>();

	Boolean connected;
	Boolean transmitting;

	public GUI() {
		super("Massimo Giordano 2084173");
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.getContentPane().setLayout(new BorderLayout());

		JPanel top = new JPanel();
		start.setActionCommand("start");
		start.addActionListener(act);
		top.add(start);
		top.add(new JLabel("IP Address"));
		top.add(ipField);
		top.add(new JLabel("Port"));
		top.add(portField);
		stop.setActionCommand("stop");
		stop.addActionListener(act);
		top.add(stop);


		for(Integer i = 0; i < 5; ++i) {
			ColoredButton b = new ColoredButton("", Color.RED);
			b.setTextDigit(i.toString());
			b.setPreferredSize(new Dimension(100, 100));
			centralPanel.add(b);
			buttons.add(b);
		}
		centralPanel.setPreferredSize(new Dimension(500, 100));

		JPanel bottom = new JPanel();
		connect.setActionCommand("connect");
		connect.addActionListener(act);
		bottom.add(connect);
		disconnect.setActionCommand("disconnect");
		disconnect.addActionListener(act);
		bottom.add(disconnect);
		clear.setActionCommand("clear");
		clear.addActionListener(act);
		bottom.add(clear);
		
		this.add(top, BorderLayout.NORTH);
		this.add(centralPanel, BorderLayout.CENTER);
		this.add(bottom, BorderLayout.SOUTH);

		setStatus(false, false);

		this.pack();
		this.setVisible(true);
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
		if(!connected) {
			connect.setEnabled(true);
			disconnect.setEnabled(false);
			start.setEnabled(false);
			stop.setEnabled(false);
		} else if(!transmitting) {
			connect.setEnabled(false);
			disconnect.setEnabled(true);
			start.setEnabled(true);
			stop.setEnabled(false);
		} else {
			connect.setEnabled(false);
			disconnect.setEnabled(false);
			start.setEnabled(false);
			stop.setEnabled(true);
		}
	}
}
