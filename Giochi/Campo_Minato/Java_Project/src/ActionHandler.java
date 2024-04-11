import javax.swing.*;

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

	Integer DIMENSIONE_CAMPO;
    Integer NUMERO_BOMBE;
    
    ArrayList<Integer> list = new ArrayList<Integer>();
    LinkedList<Box> listaBox = new LinkedList<Box>();


	public ActionHandler(GUI frame) {
		this.frame = frame;
		this.DIMENSIONE_CAMPO = frame.getDimension();
		this.NUMERO_BOMBE = frame.getNumBombe();
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
					reset();
					break;
			}
			
		}
		if(actionEvent.getSource().getClass().equals(Box.class)) {
			Box box = (Box) actionEvent.getSource();
			System.out.println(box.isBomb());

		}

    }

	public void start() {
		
		DIMENSIONE_CAMPO = frame.getDimension();
		System.out.println(DIMENSIONE_CAMPO.toString());
        NUMERO_BOMBE = frame.getNumBombe();
		System.out.println(NUMERO_BOMBE.toString());
		System.out.println(list.size());
        
        Random random = new Random();
       // Genera gli indici casuali per le bombe
	   int i = 0;
        while (list.size() < NUMERO_BOMBE) {
			
            int randomIndex = random.nextInt(DIMENSIONE_CAMPO*DIMENSIONE_CAMPO);
            if (!list.contains(randomIndex)) {
                list.add(randomIndex);
				System.out.println(list.get(i));
				++i;
            }
			
        }
    
        // for (Box b : listaBox) {
		// 	int index = listaBox.indexOf(b);
        //     b.setChecked(false);
        //     b.setMark(false);
        //     if (list.contains(index)) {
        //         b.setBomb(true);
        //     }


        //     listaBox.add(b);
        // }
		frame.setStatus(true, false, false);
		frame.log.setText(null);
		System.out.println("----gioco iniziato----\n\n");

	}
	public void end() {
		frame.setStatus(false, true, false);
		System.out.println("----gioco stoppato----\n\n");
	}
	public void reset() {
		frame.setStatus(false, false, true);
		frame.log.setText(null);
		System.out.println("----gioco resettato----\n\n");
	}

}
