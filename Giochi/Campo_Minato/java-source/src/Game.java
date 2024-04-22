import java.awt.Dimension;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Random;

import javax.swing.JOptionPane;

public class Game {
	private GUI frame;
	
	Integer DIM;
	Integer BOMBE;
	Boolean run = false;
	
	ArrayList<Integer> list = new ArrayList<Integer>();
	
	LinkedList<Box> listaBox = new LinkedList<Box>();
	
	public Game(GUI frame) {
		this.frame = frame;
		while(run == false) {
			String dim_campo = JOptionPane.showInputDialog(null, "Inserire dimensione del campo ");
			String num_bombe = JOptionPane.showInputDialog(null, "Inserire numero bombe: ");

			if (dim_campo == null || num_bombe == null) {
				// !L'utente ha cliccato annulla
				break;
			}

			try {
				int dim = Integer.parseInt(dim_campo);
				int bombe = Integer.parseInt(num_bombe);

				frame.insertBox(dim, bombe);
				run = true;
			} catch (NumberFormatException e) {
				JOptionPane.showMessageDialog(null, "Inserisci dati corretti",
						"Errore", JOptionPane.ERROR_MESSAGE);
			}
		}
		start();
		
	}
	
	public void init() {
		for (Box b : listaBox) {
			b.init();
		}
	}
	public void start() {
		
		DIM = frame.getDimension();
	    BOMBE = frame.getNumBombe();

		Random random = new Random();
	    while (list.size() < BOMBE) {
	        int randomIndex = random.nextInt(DIM * DIM);
	        if (!list.contains(randomIndex)) {
	            list.add(randomIndex);
	        }
	    }
		frame.boxEnabled(true);
	    
	    this.listaBox = frame.getListaBox();
	    for (Box b : listaBox) {
			b.setMark(false);
			b.setNumBombe(-1);
			b.setMark(false);

		 	int index = b.getIndex();
	        
	        if (list.contains(index)) {
	            b.setBomb(true);
	        }
	    }
		frame.update();
	}

	public void end() {
		frame.boxEnabled(false);
		JOptionPane.showMessageDialog(null, "Hai perso, Stupido!", "Errore", JOptionPane.ERROR_MESSAGE);
		frame.deleteBoxPanel();
		frame.setStatus(false, true);
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
						
						if ((isBombCiclo(row - 1, col - 1) || isBombCiclo(row - 1, col) || isBombCiclo(row - 1, col + 1) ||
								isBombCiclo(row, col - 1) 	 || isBombCiclo(row, col + 1) ||
								isBombCiclo(row + 1, col - 1) || isBombCiclo(row + 1, col) || isBombCiclo(row + 1, col + 1)) == false) {
							
							
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

	public void loseGame() {
		frame.showBombs();
		frame.write(null);
		frame.write("Hai perso la partita!");
		this.end();
	}
}