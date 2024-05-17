import java.util.Scanner;

public class Receiver implements Runnable {

	private final GUI frame;
	private final Scanner input;
	private Boolean running = true;

	public Receiver(Scanner input, GUI frame) {
		this.input = input;
		this.frame = frame;
	}

	@Override
	public void run() {
		System.out.println("===INIZIO SESSIONE===");
		while(running && input.hasNextLine()) {
			String s = input.nextLine();
			String dati[] = s.split(";");
			frame.updateColor(dati[0], dati[1]);
			System.out.println(dati[0] + " " + dati[1]);
		}
	}
}
