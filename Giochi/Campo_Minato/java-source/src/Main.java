import javax.swing.JOptionPane;

public class Main {
	public static void main(String[] args) {
		/*while(true) {
			String dim_campo = JOptionPane.showInputDialog(null, "Inserire dimensione del campo ");
			String num_bombe = JOptionPane.showInputDialog(null, "Inserire numero bombe: ");

			if(dim_campo == null || num_bombe == null) {
				//!L'utente ha cliccato annulla
				break;
			}

			try {
				int dim = Integer.parseInt(dim_campo);
				int bombe = Integer.parseInt(num_bombe);

				new GUI(dim, bombe);
			} catch (NumberFormatException e) {
				JOptionPane.showMessageDialog(null, "Inserisci dati corretti",
						"Errore", JOptionPane.ERROR_MESSAGE);
			}
		}*/
		new GUI();
		
	}
}
