import java.util.*;

public class Main {
	public static void main(String[] args) {

		// Variabili possibili da dichiarare:
		boolean var_bool = true;
		byte var_byte = 127;
		int var_short = 32768;
		long var_long = 2343L;
		char var_char = 'c';
		String var_stringa = "La mia stringa";

		Scanner scanner = new Scanner(System.in);

		// Il dato String è una reference, non so cos'è ma le 
		// faremo noi
		/*
		System.out.println(var_stringa);
		System.out.println(var_stringa.toUpperCase());
		System.out.println(var_stringa);

		System.out.println("Dimmi il tuo nome");
		String nome = scanner.nextLine();

		System.out.println("Dimmi il tuo cognome");
		String cognome = scanner.nextLine();

		System.out.println("Dimmi la tua età");
		int eta = scanner.nextInt();
		scanner.nextLine();

		System.out.println("Dimmi in che città vivi");
		String citta = scanner.nextLine();

		System.out.println("Ciao " + nome + " " + cognome);
		System.out.println("Hai " + eta + " anni e vivi a " + citta);
		*/

		// Creazione di un array
		/*
		int[] numeri = new int[3];
		int[] arr = {10, 20, 30, 40};
		
		numeri[0] = 10;
		numeri[1] = 20;
		numeri[2] = 30;

		System.out.println(arr.length);

		String[][] classi = new String[3][5];
		for(int classe = 0; classe < classi.length; classe++) {
			
			for(int stud = 0; stud < classi[classe].length; stud++) {
				classi[classe][stud] = scanner.nextLine();
			}
		}

		for(int classe = 0; classe < classi.length; classe++) {
			System.out.println();
			for(int stud = 0; stud < classi[classe].length; stud++) {
				System.out.print(classi[classe][stud] + " ");
			}
		}
		System.out.println();
		*/

		// ArrayList<String> s = new ArrayList<String>();
		// ArrayList<String> s2 = new ArrayList<String>();
		// ArrayList<Integer> I = new ArrayList<Integer>();
		// ArrayList<Character> c = new ArrayList<Character>();

		// ArrayList<ArrayList<String>> matrice = new ArrayList<ArrayList<String>>();

		// s.add("Luca");
		// s.add("Marco");
		// s.add("Anna");

		// s2.add("Luca2");
		// s2.add("Marco2");
		// s2.add("Anna2");

		// matrice.add(s);
		// matrice.add(s2);

		// for(int i = 0; i < matrice.size(); ++i) {
		// 	System.out.println(matrice.get(i));
		// }

		// s.set(2, "Paola");
		// s.remove(0); // Toglie solo lo Zero
		// s.clear(); 	 // Pulisce tutto l'Array List

		// funzione(1);
		// funzione(2);
		Persona p1 = new Persona("Massimo", "Giordano", 20, "Blu");
		
		p1.cammina();

	}

	static void funzione(int num) {
		System.out.println("Stampa nella funzione numero " + num);
	}
}
