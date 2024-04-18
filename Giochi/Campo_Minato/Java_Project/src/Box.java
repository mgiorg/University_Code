import javax.swing.*;
import java.awt.*;
public class Box extends JButton{
	boolean checked = false;
	boolean mark = false;
	boolean bomb = false;
	Integer nbombe;
	Integer riga;
	Integer colonna;
	Integer index;
	

	public Box(int riga, int colonna) {
		this.riga = riga;
		this.colonna = colonna;
		init();
	}
	public void init() {
		this.checked = false;
		this.mark = false;
		this.bomb = false;
		this.nbombe = -1;
	}

	public boolean isChecked() {
		return this.checked;
	}
	public void setChecked(boolean checked) {
		this.checked = checked;
	}
	public boolean isMarked() {
		return this.mark;
	}
	public void setMark(boolean mark) {
		this.mark = mark;
	} 
	public boolean isBomb() {
		return this.bomb;
	}
	public void setBomb(boolean bomb) {
		this.bomb = bomb;
	}
	public Integer getNumBombe() {
		return this.nbombe;
	}
	public void setNumBombe(int i) {
		this.nbombe = i;
	}
	public Integer getRiga() {
		return this.riga;
	}
	public Integer getColonna() {
		return this.colonna;
	}
	public Integer getIndex() {
		return this.index;
	}
	public void setIndex(int i) {
		this.index = i;
	}
	
//	@Override
//	protected void paintComponent(Graphics gr) {
//		super.paintComponents(gr);
//		
//		gr.setColor(Color.GREEN);
//		gr.fillRect(0,  0,  getWidth(), getHeight());
//	}
}
