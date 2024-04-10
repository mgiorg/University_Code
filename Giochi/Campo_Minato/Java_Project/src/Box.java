import javax.swing.*;
import java.awt.*;
public class Box extends JButton{
	Boolean checked=false;
	int nbombe;
	Boolean mark=false;

	public Box(){
		this.checked=false;
		this.nbombe=0;
		this.mark=false;
		this.setSize(10, 10);
	}
}
