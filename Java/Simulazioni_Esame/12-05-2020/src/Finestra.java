import java.awt.*;
import javax.swing.*;

public class Finestra extends JFrame{
	JButton start = new JButton("Start");
	JButton interrompi = new JButton("Interrompi");
	JButton connect = new JButton("Connect");
	JButton disconnect = new JButton("Disconnect");
	JButton clear = new JButton("Clear");

	JTextField add = new JTextField("127.0.0.1");
	JTextField port = new JTextField("4400");

	JLabel Add = new JLabel("IP Address");
	JLabel Port = new JLabel("Port");

	ColoredButton b[] = new ColoredButton [5];

	JPanel top = new JPanel();
	JPanel middle = new JPanel();
	JPanel bottom = new JPanel();

	GridLayout gl = new GridLayout(1, 5);

	/**
	 * 
	 */
	public Finestra() {
		super("Giordano Massimo 2084173");

		port.setEditable(false);
		add.setEditable(false);

		top.add(start);
		top.add(Add);
		top.add(add);
		top.add(Port);
		top.add(port);
		top.add(interrompi);
		this.add(top, BorderLayout.NORTH);

		for (int i = 0; i < 5; i++) {
			b[i] = new ColoredButton(String.valueOf(i), Color.LIGHT_GRAY);
			b[i].setEnabled(false);
		}
		for(int i = 0; i < 5; i++) {
			middle.add(b[i]);
		}
		middle.setLayout(gl);

		bottom.add(connect);
		bottom.add(disconnect);
		bottom.add(clear);

		this.add(bottom, BorderLayout.SOUTH);
		this.add(middle);

		this.setSize(700, 200);
		this.setPreferredSize(new Dimension(700, 150));

		this.setVisible(true);
		this.setDefaultCloseOperation(EXIT_ON_CLOSE);

		connect.setEnabled(true);
		disconnect.setEnabled(false);
		clear.setEnabled(false);
		start.setEnabled(false);
		interrompi.setEnabled(false);
	}
}
