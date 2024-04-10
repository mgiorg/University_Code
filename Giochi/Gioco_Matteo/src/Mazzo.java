import java.util.*;

public class Mazzo {
	LinkedList<Carta> mazzo=new LinkedList<Carta>();
	
	public Mazzo() {
		for(Carta.Valore v: Carta.Valore.values()) {
			for(Carta.Seme s: Carta.Seme.values()) {
				mazzo.add(new Carta(v,s));
			}
		}
	}
	@Override
	public String toString() {
		String s=new String();
		for(Carta carta: mazzo) {
			s= s+ carta.toString()+'\n';
		}
		return s;
	}
	public void shuffle() {
		Collections.shuffle(mazzo);
	}
	public Carta getCard() {
		Carta first=mazzo.get(0);
		mazzo.removeFirst();
		return first;
	}
}
