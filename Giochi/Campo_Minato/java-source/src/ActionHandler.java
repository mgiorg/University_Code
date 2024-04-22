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
			}
		}
		if(actionEvent.getSource().getClass().equals(Box.class)) {
			Box b = (Box) actionEvent.getSource();
			
			if (b.isBomb()) {
				g.loseGame();
				frame.setStatus(false, true);
			} else {
				g.cercaVuoti(b.getRiga(), b.getColonna());
				if(g.completato()) {
					frame.write(null);
					frame.update();
					JOptionPane.showMessageDialog(null, "Complimenti, hai vinto un cazzo!", "Dai Cazzo Gialluca", JOptionPane.INFORMATION_MESSAGE);
					frame.deleteBoxPanel();
					frame.setStatus(false, true);
				}
			}
			
		}
		frame.update();
	}

	public Game start() {
		
		Game g = new Game(this.frame);

		frame.setStatus(true, false);
		frame.write(null);
		frame.write("Gioco iniziato!");
        
		return g;
	}
	public void end() {

		g.end();
		frame.setStatus(false, true);
		frame.write(null);
		frame.write("Partita conclusa");
	}
}
