import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class TicketCell extends JButton {
	private static final Color SELECTED = Color.WHITE;
	private static final Color UNSELECTED = Color.GREEN;
	private int value;

	public TicketCell() {
		super("");
		this.setSize(45, 45);
		this.setBackground(UNSELECTED); // Imposta il colore di sfondo predefinito
		addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				toggleSelection(); // Chiamata al metodo per invertire la selezione del bottone
			}
		});
	}

	// Metodo per impostare il valore del ticket (se necessario)
	public void setValue(int value) {
		this.value = value;
		setText(String.valueOf(value));
	}

	// Metodo per ottenere il valore del ticket (se necessario)
	public int getValue() {
		return value;
	}

	// Metodo per invertire la selezione del bottone
	private void toggleSelection() {
		if (getBackground() == UNSELECTED) {
			setBackground(SELECTED);
		} else {
			setBackground(UNSELECTED);
		}
	}
}
