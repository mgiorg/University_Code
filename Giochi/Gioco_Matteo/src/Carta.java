
public class Carta {
	private final Valore v;
	private final Seme s;
	
	public Carta(Valore v, Seme s) {
		this.v=v;
		this.s=s;
	}
	
	public enum Valore{
		Asso, Due, Tre, Quattro, Cinque, Sei, Sette, Otto, Nove, Dieci, Jack, Regina, Re
	}
	public enum Seme{
		Cuori, Quadri, Fiori, Picche
	}
	
	public Valore getValore() {
		return v;
	}
	
	public Seme getSeme() {
		return s;
	}
	
	@Override
	public String toString() {
		return v+" di "+s;
	}
	
	public static Carta cartaCasuale() {
		Valore[] v=Valore.values();
		Seme[] s=Seme.values();
		int v_index=(int) (Math.random()*13);
		int s_index=(int) (Math.random()*4);
		return new Carta(v[v_index],s[s_index]);
	}
}
