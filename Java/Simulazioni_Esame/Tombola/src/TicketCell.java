import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.SwingConstants;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.Font;
import java.awt.GridLayout;

public class TicketCell extends JPanel {
    private static final Color SELECTED = Color.GREEN;
    private static final Color UNSELECTED = Color.WHITE;
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
        this.valueLabel.setFont(new Font(Font.MONOSPACED, Font.BOLD, 24));
        this.valueLabel.setHorizontalTextPosition(SwingConstants.CENTER);
        setLayout(new GridLayout(1, 1));
        add(this.valueLabel);
        setValue(value);
        setSelected(selected);
    }

    public int getValue() {
        return value;
    }

    public void setValue(int value) {
        this.value = value;
        valueLabel.setText(value > 0 && value <= 90 ? String.valueOf(value) : "");
        valueLabel.setHorizontalTextPosition(SwingConstants.CENTER);
        repaint();
    }

    public void setSelected(boolean selected) {
        if (selected) {
            setBackground(SELECTED);
        } else {
            setBackground(UNSELECTED);
        }
    }

    @Override
    public Dimension getPreferredSize() {
        return new Dimension(120, 100);
    }

}
