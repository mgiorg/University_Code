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
	private PrintWriter pw;

	public static final String CONNECT = "connect";
	public static final String DISCONNECT = "disconnect";
	public static final String START = "start";
	public static final String STOP = "stop";

	public ActionHandler(GUI frame) {
		this.frame = frame;
	}

	@Override
	public void actionPerformed(ActionEvent event) {
		if(event.getSource().getClass().equals(JButton.class)) {
			JButton button = (JButton) event.getSource();
			switch(button.getText()) {
				case "Connect":
					System.out.println("Premuto Connect");
					connect();
					break;

				case "Start":
					System.out.println("Premuto Start");
					start();
					break;

				case "Stop":
					System.out.println("Premuto Stop");
					stop();
					break;

				case "Disconnect":
					System.out.println("Premuto Disconnect");
					disconnect();
					break;
			}
		}
	}

	private void connect(){
		try {
			socket = new Socket(frame.getIP(), frame.getPort());
			scanner = new Scanner(socket.getInputStream());
			pw = new PrintWriter(socket.getOutputStream());
			frame.setStatus(true, false);
			frame.update();

		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	
	private void start() {
		try {
			pw.println("start");
			pw.flush();

			frame.setStatus(true, true);
			frame.update();

			Thread t = new Thread(new Receiver(scanner, frame));
			t.start();

		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	private void stop() {
		try {
			pw.println("stop");
			pw.flush();

			frame.setStatus(true, false);
			frame.update();

		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	public void disconnect() {
		try {
			pw.println("disconnect");
			pw.flush();
			pw.close();
			socket.close();
			scanner.close();
			frame.setStatus(false, false);
			frame.update();
			frame.reset();

		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}
