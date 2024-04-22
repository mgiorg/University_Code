public class GUI_Cartella extends JFrame {

	JButton vedi_estratti  = new JButton("Vedi Estratti");
	JButton soglia_attuale = new JButton("Soglia Attuale");

	Cartella cartella;

	Integer numero_cartella;

	public GUI_Cartella() {

		super("Cartella della Tombola");
		this.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
		this.getContentPane().setLayout(new BorderLayout());
		this.pack();

		this.add(vedi_estratti, BorderLayout.NORTH);
		this.add(soglia_attuale, BorderLayout.NORTH);

		cartella = new Cartella();
		this.add(cartella, BorderLayout.CENTER);

		

	}
}
