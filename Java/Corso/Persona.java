public class Persona {
    String nome;
    String cognome;
    int eta;
    String colore_prefe;

    Persona(String nome, String cognome, int eta, String colore_prefe) {
        this.nome = nome;
        this.cognome = cognome;
        this.eta = eta;
        this.colore_prefe = colore_prefe;
    }

    void saluta() {
        System.out.println("Ciao sono " + nome);
    }
    void cammina() {
        System.out.println("Sto camminando...");
    }
}
