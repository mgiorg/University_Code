import javax.swing.*;
import java.awt.*;
public class Box extends JButton{
	boolean checked = false;
	boolean mark = false;
	boolean bomb = false;
	Integer nbombe;
	Integer riga;
	Integer colonna;
	

	public Box(int riga, int colonna) {
		this.checked = false;
		this.mark = false;
		this.bomb = false;
		this.nbombe = 0;
		
		this.riga = riga;
		this.colonna = colonna;
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
	public Integer getBombe() {
		return this.nbombe;
	}
	public Integer getRiga() {
		return this.riga;
	}
	public Integer getColonna() {
		return this.colonna;
	}


}
