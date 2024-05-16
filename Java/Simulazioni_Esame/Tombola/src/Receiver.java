
import javax.swing.*;
import java.awt.*;
import java.util.Scanner;

public class Receiver implements Runnable {

	Scanner scanner;
	GUI frame;
	private Boolean running = true;

	public Receiver(Scanner scanner, GUI frame) {
		this.scanner = scanner;
		this.frame = frame;
	}

	@Override
	public void run() {
		frame.write("Inizio scansione\n");
		while(running && scanner.hasNextLine()) {
			frame.write("Interno\n");
			String line = scanner.nextLine();
			frame.write("Ricevuto " + line + "\n");
		}
	}
}
