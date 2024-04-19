import javax.swing.*;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

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
			
			if (b.isBomb()) {
				frame.write("Hai preso una bomba, Game Over!!!\n");
			} else {
				if (g.cercaVuoti(b.getRiga(), b.getColonna())) {
					frame.write("Completato");
				}
			}
			frame.write("Bomba " + b.getIndex() + " ha intorno " + b.getNumBombe() + " bombe");
		}
		frame.update();
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
