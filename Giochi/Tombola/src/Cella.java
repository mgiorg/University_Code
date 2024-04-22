public class Cella extends JPanel {
	Integer numero;
	Integer indice;

	public Cella(Integer numero, Integer indice) {
		this.numero = numero;
		this.indice = indice;

		this.setBackground(null);
		this.setBorderPainted(false);
		this.setOpaque(true);
		this.setPreferredSize(new Dimension(60, 60));
		this.setFont(new Font("Times New Roman", Font.BOLD, 20));
	}

	public Integer getNumero() {
		return this.numero;
	}

	public Integer getIndice() {
		return this.indice;
	}
}
