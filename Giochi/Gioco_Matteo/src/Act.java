import javax.swing.*;
//import java.awt.*;
import java.awt.event.*;

public class Act implements ActionListener {
	private final GUI frame;
	private Game g;
	
	Act(GUI frame){
		this.frame=frame;
	}
	
	@Override
	public void actionPerformed(ActionEvent actionEvent) {
		if(actionEvent.getSource().getClass().equals(JButton.class)) {
			JButton btn=(JButton) actionEvent.getSource();
			switch(btn.getText()) {
			case "Start":
				this.g=start();
				break;
			case "Stop":
				stop();
				break;
			case "Reset":
				reset(g);
				break;
			case "Pesca":
				pesca();
				break;
			case "Passa":
				if (frame.GameRun && g != null) {
                    passa(g);
                }
				break;
			}
		}
	}
	
	Game start() {
		Game game=new Game();
		frame.setStatus(true, false, false);
		frame.Log.setText(null);
		frame.logmazzo.setText(null);
		frame.logmazzo.append(game.mazzo.toString());
		frame.write("----gioco iniziato----\n\n");
		frame.Hand.setText(game.player.toString());
		frame.logmazzo.setText(game.mazzo.toString());
		return game;
	}
	void stop() {
		frame.setStatus(false,true,false);
		frame.write("----gioco stoppato----\n\n");
		
	}
	void reset(Game game) {
		frame.setStatus(true,false,false);
		frame.Log.setText(null);
		frame.logmazzo.setText(null);
		game.reset();
		start();
	}
	void pesca() {
		Carta c=  Carta.cartaCasuale();
		frame.write(c.toString()+'\n');
	}
	
	void passa(Game game) {
		if(game==null) return;
		game.nextTurn();
		frame.Log.append("TURNO: "+game.turno+'\n');
		frame.Hand.setText(game.player.toString());
		frame.logmazzo.setText(game.mazzo.toString());
	}
	
}
