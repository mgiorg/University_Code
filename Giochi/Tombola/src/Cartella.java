import java.awt.GridLayout;

public class Cartella extends JPanel {

	private LinkedList<Integer> listaNumeri = new LinkedList<Integer>();
	private LinkedList<JPanel> listaColonne 	= new LinkedList<JPanel>();
	

	public Cartella() {
		this.getContentPane().setLayout(new GridLayout(1, 9));

		Random random = new Random();
		for (int i = 0; i < 15; i++) {
			int randomNumber = random.nextInt(max - min + 1) + min;
			listaNumeri.add(randomNumber);
		}

		for(int i = 0; i < 9; ++i) {
			JPanel colonna = new JPanel(new GridLayout(3, 1));

			for(int j = 0; j < 3; ++j) {

				Cella c = new Cella(null, null);
				colonna.add(c);
				listaCelle.add(c);
			}
			listaColonne.add(colonna);
			this.add(colonna);
		}
	}
}
