import javax.swing.*;
import java.awt.*;
import java.util.*;

public class GUI extends JFrame {
	JButton start = new JButton("Start");
	JButton stop = new JButton("Interrompi");
	JButton connect = new JButton("Connect");
	JButton disconnect = new JButton("Disconnect");
	JButton clear = new JButton("Clear");

	JTextField portField = new JTextField("4400", 8);
	JTextField ipField = new JTextField("127.0.0.1", 15);

	JPanel centralPanel = new JPanel(new GridLayout(1, 5));
	LinkedList<ColoredButton> buttons = new LinkedList<ColoredButton>();

	public GUI() {
		super("Massimo Giordano 2084173");
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.getContentPane().setLayout(new BorderLayout());

		JPanel top = new JPanel();
		top.add(start);
		top.add(new JLabel("IP Address"));
		top.add(ipField);
		top.add(new JLabel("Port"));
		top.add(portField);
		top.add(stop);


		for(int i = 0; i < 5; ++i) {
			ColoredButton b = new ColoredButton("0", Color.LIGHT_GRAY);
			b.setTextDigit("1");
			b.setPreferredSize(new Dimension(100, 100));
			centralPanel.add(b);
			buttons.add(b);
		}
		centralPanel.setPreferredSize(new Dimension(500, 100));


		JPanel bottom = new JPanel();
		bottom.add(connect);
		bottom.add(disconnect);
		bottom.add(clear);
		




		this.add(top, BorderLayout.NORTH);
		this.add(centralPanel, BorderLayout.CENTER);
		this.add(bottom, BorderLayout.SOUTH);

		this.pack();
		this.setVisible(true);
	}
}
