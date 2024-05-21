import javax.swing.*;
import java.awt.*;
import java.util.*;

public class Receiver implements Runnable {
	GUI frame;
	Scanner scan;
	Boolean running = true;

	public Receiver(Scanner scan, GUI frame) {
		this.scan = scan;
		this.frame = frame;
	}

	@Override
	public void run() {
		while(running && scan.hasNextLine()) {
			String s = scan.nextLine();
			System.out.println("Estratto " + s);
		}
		frame.setStatus(true, false);
	}
}
