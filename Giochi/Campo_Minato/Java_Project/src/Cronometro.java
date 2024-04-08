import java.util.*;
import javax.swing.Timer;

public class Cronometro {
	private static int seconds = 0;
	private static Timer timer;
	private CronometroThread cronometroThread;

	public Cronometro() {
		timer = new Timer();
	}
	/**
	 * 
	 */
	public void start() {
		TimerTask task = new TimerTask() {
			public void run() {
				seconds++;
				System.out.println(formatTime(seconds));
			}
		};

		timer.scheduleAtFixedRate(task, 1000, 1000);
	}

	public void stop() {
		timer.cancel();
	}

	private String formatTime(int seconds) {
		int hours = seconds / 3600;
		int minutes = (seconds % 3600) / 60;
		int secs = seconds % 60;
		return String.format("%02d:%02d:%02d", hours, minutes, secs);
	}


}
