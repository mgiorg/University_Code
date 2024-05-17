
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
		switch(e.getActionCommand()) {
			case "Connect":
				try {
					s = new Socket(frame.getIP(), frame.getPort());
					scan = new Scanner(s.getInputStream());
					pw = new PrintWriter(s.getOutputStream());

					frame.setStatus(true, false);
					frame.write("=====Connessione Effettuata=====\n");

				} catch (Exception ex) {
					frame.write("Eccezione");
					ex.printStackTrace();
				}
				break;
			case "Disconnect":
				try {
				s.close();
				scan.close();
				pw.close();
				frame.setStatus(false, false);

			} catch (Exception ex) {
				frame.write("Eccezione");
				ex.printStackTrace();
			}
				break;
			case "Start":
				try {
					frame.reset();
					pw.write("start\n");
					pw.flush();
					frame.setStatus(true, true);

					Thread t = new Thread(new Receiver(scan, frame, frame.getCells()));
					t.start();

				} catch (Exception ex) {
					frame.write("Eccezione");
					ex.printStackTrace();
				}
				
				break;
			case "Stop":
				try {
					pw.write("stop\n");
					pw.flush();

					frame.setStatus(true, false);

				} catch (Exception ex) {
					frame.write("Eccezione");
					ex.printStackTrace();
				}
				break;
		}
	}
}
