
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.net.Socket;
import java.net.UnknownHostException;
import java.util.Scanner;
import javax.swing.JButton;

public class Act implements ActionListener {

	GUI frame;
	Socket s;
	Scanner scan;
	PrintWriter pw;

	public Act(GUI frame) {
		this.frame = frame;
	}

	@Override
	public void actionPerformed(ActionEvent e) {
		switch(e.getActionCommand()){
			case "Connect":
				frame.write("Premuto connect\n");
				connect();
				break;
			case "Disconnect":
			frame.write("Premuto disconnect\n");
				disconnect();
				break;
			case "Start":
				frame.write("Premuto start\n");
				start();
				break;
			case "Stop":
				frame.write("Premuto stop\n");
				stop();
				break;
		}
	}

	public void connect() {
		try {
			s = new Socket(frame.getIP(), frame.getPort());
			scan = new Scanner(s.getInputStream());
			pw = new PrintWriter(s.getOutputStream());

			frame.setStatus(true, false);
			frame.write("=====Connessione Effettuata=====\n");

		} catch(Exception e) {
			e.printStackTrace();
		}
	}
	public void start() {
		try {
			pw.write("start");
			pw.flush();
			frame.setStatus(true, true);

			Thread t = new Thread(new Receiver(scan, frame));
			t.start();

		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	public void stop() {
		try {
			pw.write("stop");
			pw.flush();

			frame.setStatus(true, false);

		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	public void disconnect() {
		try {
			s.close();
			scan.close();
			pw.close();

			frame.setStatus(false, false);

		} catch (Exception e) {
			e.printStackTrace();
		}
	}

}
