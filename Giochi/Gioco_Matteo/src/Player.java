import java.util.*;

public class Player {
	LinkedList<Carta> mano;
	int punteggio;
	
	public Player() {
		this.punteggio=0;
		this.mano=new LinkedList<Carta>();
	}
	
	public int getPunteggio() {
		return this.punteggio;
	}
	
	public void addPunteggio(int p) {
		this.punteggio+=p;
	}
	
	public LinkedList<Carta> getMano(){
		return mano;
	}
	public void addCard(Carta c) {
		mano.add(c);
	}
	public void removeCards(int[] i) {
		int j=0;
		for(int index:i) {
			mano.remove(index-1-j);
			j++;
		}
	}
	
	@Override
	public String toString() {
		String s= new String();
		for (Carta c: mano) {
			s= s+c.toString()+'\n';
		}
		return s;
	}
}
