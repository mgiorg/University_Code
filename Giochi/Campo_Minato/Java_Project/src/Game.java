import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Random;

public class Game {
	private GUI frame;
	
	Integer DIM;
	Integer BOMBE;
	
	ArrayList<Integer> list = new ArrayList<Integer>();
	
	LinkedList<Box> listaBox = new LinkedList<Box>();
	
	public Game(GUI frame) {
		this.frame = frame;
		start();
		
	}
	public void start() {
		DIM = frame.getDimension();
		System.out.println(DIM.toString());
		
	    BOMBE = frame.getNumBombe();
		System.out.println(BOMBE.toString());
		
		System.out.println(list.size());
		
		Random random = new Random();
	    // Genera gli indici casuali per le bombe
	    int i = 0;
	    while (list.size() < BOMBE) {
			
	        int randomIndex = random.nextInt(DIM * DIM);
	        if (!list.contains(randomIndex)) {
	            list.add(randomIndex);
				++i;
	        }
			
	    }
	    
	    this.listaBox = frame.getListaBox();
	    for (Box b : listaBox) {
	    	
		 	int index = b.getIndex();
		 	System.out.println(index);
	        b.setChecked(false);
	        b.setMark(false);
	        if (list.contains(index)) {
	            b.setBomb(true);
	            System.out.println("Bomba true");
	        }
	    }
	    //frame.update();
	}
	
	public void init() {
		for(Box b : listaBox) {
			b.init();
		}
	}
	
	public Boolean isCellaCorretta(Box b) {
		int row = b.getRiga();
		int col = b.getColonna();
		
		if (row >= 0 && col >= 0 && row < DIM && col < DIM) {
			return true;
		}
			
		else {
			return false;
		}
	}
	
	public Boolean isBomb(Box b) {
		return b.isBomb();
	}
	public Boolean isBombCiclo(int row, int col) {
		for(Box b : this.listaBox) {
			if(b.getColonna() == col && b.getRiga() == row) {
				if(b.isBomb()) {
					return true;
				}
			}
		}
		return false;
	}
	
	public Boolean completato() {
		int contatore = 0;
		for(Box b : listaBox) {
			if(b.isMarked() == false) {
				contatore++;
			}
		}
		if (contatore == BOMBE) {
			return true;
		}
		else return false;
	}
	public Boolean percorribile(Box b) {
		if (this.isCellaCorretta(b) && this.isBomb(b) == false) {
			return true;
		}
		else return false;
	}
	
	public Integer contaBombe(int row, int col) {
		
		for(Box b : this.listaBox) {
			if(b.getRiga() == row && b.getColonna() == col) {
				
				if(this.isBomb(b) && b.isMarked() == false) {
					return 1;
				}
				
				if(b.getNumBombe() == -1 && b.isMarked()) {
					b.setNumBombe(0);
					System.out.println("Conta Bombe");
					b.setNumBombe(	contaBombe(row + 1, col - 1) +
							 		contaBombe(row, col - 1) +
							 		contaBombe(row - 1, col - 1) +
							 		contaBombe(row + 1, col) +
							 		contaBombe(row - 1, col) +
							 		contaBombe(row + 1, col + 1) +
							 		contaBombe(row, col + 1) +
							 		contaBombe(row - 1, col + 1));
				}
			}
		}
		return 0;
	}
	public Boolean cercaVuoti(int row, int col) {
		for(Box b : listaBox) {
			if(b.getColonna() == col && b.getRiga() == row) {
				
				if(this.completato()) {
					return true;
				}
				else {
					
					if(!b.isMarked()) {
						b.setMark(true); 
						System.out.println("Bomba marcata");
						
						if ((isBombCiclo(row - 1, col - 1) || isBombCiclo(row - 1, col) || isBombCiclo(row - 1, col + 1) ||
								isBombCiclo(row, col - 1) 	 || isBombCiclo(row, col + 1) ||
								isBombCiclo(row + 1, col - 1) || isBombCiclo(row + 1, col) || isBombCiclo(row + 1, col + 1)) == false) {
							
							
							System.out.println("Cerca Vuoti");
							return 	cercaVuoti(row-1, col-1) ||
									cercaVuoti(row, col-1) ||
									cercaVuoti(row+1, col-1) ||
									cercaVuoti(row-1, col) ||
									cercaVuoti(row+1, col) ||
									cercaVuoti(row-1, col+1) ||
									cercaVuoti(row, col+1) ||
									cercaVuoti(row+1, col+1);
						}
						else this.contaBombe(row, col);
					}
				}
			}
		}
		return false;
	}
}