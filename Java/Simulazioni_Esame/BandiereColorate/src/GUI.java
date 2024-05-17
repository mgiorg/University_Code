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

	Boolean connected, run;

	public GUI() {
		super("Massimo Giordano 2084173");
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.setLayout(new BorderLayout());

		this.getContentPane().add(top, BorderLayout.NORTH);
		this.getContentPane().add(mid, BorderLayout.CENTER);
		this.getContentPane().add(bottom, BorderLayout.SOUTH);

		top.setLayout(new FlowLayout());
		ip_address = new JLabel("IP Address");
		ip_address_text = new JTextField("127.0.0.1");

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
		start.setActionCommand(ActionHandler.START);
		start.addActionListener(act);

		stop = new JButton("Stop");
		stop.setActionCommand(ActionHandler.STOP);
		stop.addActionListener(act);

		bottom.add(start);
		bottom.add(stop);

		setStatus(false, false);
		update();

		this.pack();
		setVisible(true);
	}

	public int getPort() {
		return Integer.parseInt(port_text.getText());
	}

	public String getIP() {
		return ip_address_text.getText();
	}

	public void setStatus(Boolean connected, Boolean run) {
		this.connected = connected;
		this.run = run;
	}

	public void update() {
		if (!connected) {
            this.connect.setEnabled(true);
            this.disconnect.setEnabled(false);
            this.start.setEnabled(false);
            this.stop.setEnabled(false);
        } else if (!run) {
            this.connect.setEnabled(false);
            this.disconnect.setEnabled(true);
            this.start.setEnabled(true);
            this.stop.setEnabled(false);
        } else {
            this.connect.setEnabled(false);
            this.disconnect.setEnabled(false);
            this.start.setEnabled(false);
            this.stop.setEnabled(true);
		}
	}
	public void updateColor(String codice_colore, String pannello) {
		if(codice_colore != "-1" && pannello != "-1") {
			switch(pannello) {
				case "SX":
					setPanelColor(codice_colore, flagPanels[0]);
					break;
				case "CX":
					setPanelColor(codice_colore, flagPanels[1]);
					break;
				case "DX":
					setPanelColor(codice_colore, flagPanels[2]);
					break;
			}
		}
	}
	public void setPanelColor(String codice_colore, JPanel pannello) {
		switch (codice_colore) {
			case "0":
				pannello.setBackground(Color.WHITE);
				break;
			case "1":
				pannello.setBackground(Color.BLACK);
				break;
			case "2":
				pannello.setBackground(Color.GREEN);
				break;
			case "3":
				pannello.setBackground(Color.RED);
				break;
			case "4":
				pannello.setBackground(Color.YELLOW);
				break;
			case "5":
				pannello.setBackground(Color.BLUE);
				break;
			case "6":
				pannello.setBackground(Color.ORANGE);
				break;
		}
	}
	public void reset() {
		for(JPanel panel: flagPanels) {
			panel.setBackground(Color.LIGHT_GRAY);
		}
	}
}
