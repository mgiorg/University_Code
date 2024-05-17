
import javax.swing.*;
import java.awt.*;
import java.util.*;

public class Receiver implements Runnable {

	Scanner scanner;
	GUI frame;
	LinkedList<TicketCell> cells;
	private Boolean running = true;

	public Receiver(Scanner scanner, GUI frame, LinkedList<TicketCell> cells) {
		this.scanner = scanner;
		this.frame = frame;
		this.cells = cells;
	}

	@Override
	public void run() {
		try {
		while(running && scanner.hasNextLine()) {
			String line = scanner.nextLine();
			if(line.equals("+")) {
				frame.write("=====Sessione Conclusa=====\n");
				running = false;
				break;
			} else {
				frame.write("Estratto " + line + "\n");
				int ris = checkCells(Integer.parseInt(line));
			}
		}
		frame.setStatus(true, false);
	} catch(NumberFormatException e) {
		e.printStackTrace();
	}
	}

	private int checkCells(int v) {
        int res = 0;

        for (TicketCell t : cells) {

            if (t.getValue() == v) {
                t.setSelected(true);
            }
            if (t.isSelected()) {
                res += 1;
            }
        }
        return res;
    }
}
