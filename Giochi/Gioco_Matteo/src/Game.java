
public class Game {
	Player player;
	int turno;
	Mazzo mazzo;
	Boolean end=false;
	
	public Game() {
		this.player=new Player();
		this.mazzo=new Mazzo();
		mazzo.shuffle();
		this.turno=0;
	}
	
	public void pesca() {
		this.player.addCard(mazzo.getCard());
	}
	public void nextTurn() {
		if (this.turno==0) {
			for(int i = 0; i<5; i++) {
				pesca();
			}
			this.turno++;
			return;
		}
		if(this.turno>=1 && this.turno<=5) {
			int[] numeriprova= {1,2,3};
			player.removeCards(numeriprova);
			int ncards=numeriprova.length;
			while(ncards!=0) {
				pesca();
				ncards--;
			}
			this.turno++;
			return;
		}
		else this.end=true;
		return;
	}
	public void reset() {
		this.player=new Player();
		this.mazzo=new Mazzo();
		mazzo.shuffle();
		this.turno=0;
		this.end=false;
	}
}
