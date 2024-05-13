package mio_package;
import java.util.*;
import java.awt.*;
import javax.swing.*;

public class GUI extends JFrame {

	ActionHandler act = new ActionHandler(this);

	private JPanel top = new JPanel();
	private JPanel mid = new JPanel();
	private JPanel bottom = new JPanel();

	private JLabel ip_address;
	public JTextField ip_address_text;

	private JLabel port;
	public JTextField port_text;

	private JButton connect;
	private JButton disconnect;
	private JButton start;
	private JButton stop;

	private JPanel[] flagPanels = new JPanel[3];

	public GUI() {
		super("Massimo Giordano 2084173");
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.setLayout(new BorderLayout());

		this.getContentPane().add(top, BorderLayout.NORTH);
		this.getContentPane().add(mid, BorderLayout.CENTER);
		this.getContentPane().add(bottom, BorderLayout.SOUTH);

		top.setLayout(new FlowLayout());
		ip_address = new JLabel("IP Address");
		ip_address_text = new JTextField("");

		port = new JLabel("Port");
		port_text = new JTextField("4400");

		connect = new JButton("Connect");
		connect.setActionCommand(ActionHandler.CONNECT);
		connect.addActionListener(act);

		disconnect = new JButton("Disconnect");
		disconnect.setActionCommand(ActionHandler.DISCONNECT);
		disconnect.addActionListener(act);

		top.add(ip_address);
		ip_address_text.setEditable(false);
		top.add(ip_address_text);
		top.add(port);
		port_text.setEditable(false);
		top.add(port_text);
		top.add(connect);
		top.add(disconnect);

		mid.setLayout(new GridLayout(1, 3));
		mid.setPreferredSize(new Dimension(750, 500));
		for(int i = 0; i < 3; ++i) {
			flagPanels[i] = new JPanel();
			flagPanels[i].setPreferredSize(new Dimension(250, 500));
			flagPanels[i].setBackground(Color.LIGHT_GRAY);
			flagPanels[i].setBorder(BorderFactory.createLineBorder(Color.black));
			mid.add(flagPanels[i]);
		}
		
		start = new JButton("Start");
		stop = new JButton("Stop");

		bottom.add(start);
		bottom.add(stop);

		this.setStatus(false, true, false, false);

		this.pack();
		setVisible(true);
	}

	public void setStatus(Boolean connected, Boolean disconnected, Boolean start, Boolean stop) {
		if(connected) {
			this.connect.setEnabled(false);
			this.disconnect.setEnabled(true);
			this.start.setEnabled(true);
			this.stop.setEnabled(false);
		}
		if(disconnected) {
			this.connect.setEnabled(true);
			this.disconnect.setEnabled(false);
			this.start.setEnabled(false);
			this.stop.setEnabled(false);
		}
		if(start) {
			this.connect.setEnabled(false);
			this.disconnect.setEnabled(false);
			this.start.setEnabled(false);
			this.stop.setEnabled(true);
		}
		if(stop) {
			this.connect.setEnabled(false);
			this.disconnect.setEnabled(true);
			this.start.setEnabled(true);
			this.stop.setEnabled(false);
		}
	}
}
