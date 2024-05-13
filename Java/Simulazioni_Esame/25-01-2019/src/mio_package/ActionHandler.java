package mio_package;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.net.Socket;
import java.net.UnknownHostException;
import java.util.Scanner;
import javax.swing.JButton;

//socket, scanner, printwriter

public class ActionHandler implements ActionListener {
	public GUI frame;

	private Socket socket;
	private Scanner scanner;
	private PrintWriter writer;

	public static final String CONNECT = "connect";
	public static final String DISCONNECT = "disconnect";
	public static final String START = "start";
	public static final String STOP = "stop";

	public ActionHandler(GUI frame) {
		this.frame = frame;
	}

	@Override
	public void actionPerformed(ActionEvent event) {
		switch(event.getActionCommand()) {

			case ActionHandler.CONNECT:
				try {
					int port = Integer.parseInt(frame.port_text.getText());
					String ip_address = frame.ip_address_text.getText();

					socket = new Socket(ip_address, port);
					scanner = new Scanner(socket.getInputStream());
					writer = new PrintWriter(new OutputStreamWriter(socket.getOutputStream()));
					frame.setStatus(true, false, false, false);

					writer.println(CONNECT);
					writer.flush();
				}
				catch (UnknownHostException e) {
					System.out.println("Impossibile connettersi");
				}
				catch(IOException e) {
					System.out.println("Impossibile connettersi");
				}
				break;

			case ActionHandler.DISCONNECT:
				try {
					closeConnection();
					writer.println("disconnect");
					writer.flush();
					frame.setStatus(false, true, false, false);
				}
				catch(IOException e) {
					System.out.println("Impossibile disconnettersi");
				}
				break;
			
			// case ActionHandler.START:

		}
	}

	public void closeConnection() throws IOException {
		this.socket.close();
		this.scanner.close();
		this.writer.close();
	}

}
