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

	private GUI frame;
	Socket s;
	Scanner scan;
	PrintWriter pw;

	public Act(GUI frame) {
		this.frame = frame;
	}

	@Override
	public void actionPerformed(ActionEvent e) {
		switch(e.getActionCommand()) {
			case "connect":
				connect();
				break;
			case "start":
				start();
				break;
			case "stop":
				//stop();
				break;
			case "disconnect":
				//disconnect();
				break;
			case "clear":
				//clear();
				break;
		}
	}
	public void connect() {
		try {
			s = new Socket(frame.getIP(), frame.getPort());
			scan = new Scanner(s.getInputStream());
			pw = new PrintWriter(s.getOutputStream());

			frame.setStatus(true, false);
		} catch(Exception e) {
			e.printStackTrace();
		}
	}
	public void start() {
		try {
			pw.write("start\n");
			pw.flush();

			Thread t = new Thread(new Receiver(scan, frame));
			t.start();

			frame.setStatus(true, true);

		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}
