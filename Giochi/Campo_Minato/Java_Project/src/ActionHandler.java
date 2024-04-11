import javax.swing.*;

import java.awt.Component;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.IOException;
import java.io.PrintStream;
import java.net.Socket;
import java.util.Scanner;

public class ActionHandler implements ActionListener {
	public GUI frame;
	public Game g;

	public ActionHandler(GUI frame) {
		this.frame = frame;
		
	}	

	@Override
	public void actionPerformed(ActionEvent actionEvent) {
		if(actionEvent.getSource().getClass().equals(JButton.class)) {
			JButton button = (JButton) actionEvent.getSource();
			switch(button.getText()) {
				case "Start":
					start();
					break;
				case "End":
					end();
					break;
				case "Reset":
					break;
			}
			
		}
		if(actionEvent.getSource().getClass().equals(Box.class)) {
			Box box = (Box) actionEvent.getSource();
			System.out.println(box.getColonna());

		}

    }

	void start() {
		//Game game = new Game();

		frame.setStatus(true, false, false);
		frame.log.setText(null);
		frame.write("----gioco iniziato----\n\n");

		//return game;
	}
	void end() {
		frame.setStatus(false, true);
		frame.write("----gioco stoppato----\n\n");
	}

}
