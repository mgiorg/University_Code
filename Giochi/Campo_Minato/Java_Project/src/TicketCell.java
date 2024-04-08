
import javax.swing.*;
import java.awt.*;

public class TicketCell extends JPanel {
	private static final Color SELECTED = Color.WHITE;
	private static final Color UNSELECTED = Color.GREEN;
	private int value;
	JLabel valueLabel;

	public TicketCell() {
		this(0, false);
	}
	public TicketCell(int value) {
		this(value, false);
	}
	public TicketCell(int value, boolean selected) {
		this.valueLabel = new JLabel();
		this.valueLabel.setFont(new Font(Font.MONOSPACED, Font.BOLD, 10));
		this.valueLabel.setHorizontalTextPosition(SwingConstants.CENTER);
		setLayout(new GridLayout(1, 1));
		add(this.valueLabel);
		setValue(value);
		setSelected(selected);
	}

	public int getValue() {
		return value;
	}
	public void setValue(int cas) {
		this.value = cas;
		valueLabel.setText(cas > 0 && cas < 100 ?  String.valueOf(cas): "");
		valueLabel.setHorizontalTextPosition(SwingConstants.CENTER);
		repaint();
	}

	public void setSelected(boolean selected) {
		if(selected) {
			setBackground(SELECTED);
		}
		else {
			setBackground(UNSELECTED);
		}
	}

	@Override
	public Dimension getPreferredSize() {
		return new Dimension(10, 10);
	}
	public void actionListener() {
		//* Da IMPLEMENTARE
	}
}
