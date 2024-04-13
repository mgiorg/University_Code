import javax.swing.*;

import java.awt.Color;
import java.awt.Component;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.IOException;
import java.io.PrintStream;
import java.net.Socket;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Random;
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
					g = start();
					break;
				case "End":
					end();
					break;
				case "Reset":
					reset();
					break;
			}
			
		}
		if(actionEvent.getSource().getClass().equals(Box.class)) {
			Box b = (Box) actionEvent.getSource();
		}

    }

	public Game start() {
		
		Game g = new Game(this.frame);
		
		frame.setStatus(true, false, false);
		frame.log.setText(null);
		System.out.println("----gioco iniziato----\n\n");
        
		return g;
	}
	public void end() {
		g.init();
		frame.setStatus(false, true, false);
		System.out.println("----gioco stoppato----\n\n");
	}
	public void reset() {
		
		frame.setStatus(false, false, true);
		frame.log.setText(null);
		System.out.println("----gioco resettato----\n\n");
	}

}
