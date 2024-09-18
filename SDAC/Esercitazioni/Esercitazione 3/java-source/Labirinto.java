public class Labirinto {

    private static enum Cella { VUOTA, PIENA };

    private int n;
    private Cella m[][];
    private boolean marcata[][];

    public Labirinto(int n) {
        super();
        this.n = n;
        this.m = new Cella[n][n];
        this.marcata = new boolean[n][n];
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                m[i][j] = Cella.VUOTA;
                marcata[i][j] = false;
            }
        }
    }

    public void setPiena(int r, int c) {
        this.m[r][c] = Cella.PIENA;
    }
    public void setMarcata(int r, int c) {
        this.marcata[r][c] = true;
    }
    public boolean isMarcata(int r, int c) {
        return marcata[r][c];
    }
    public boolean isPiena(int r, int c) {
        if(m[r][c].equals(Cella.PIENA)) return true;
        return false;
    }

    private boolean uscita(int r, int c) {
        if(r == (this.n -1) && c == (this.n -1)) {
            setMarcata(r, c);
            return true;
        }
        return false;
    }

    public boolean percorribile(int r, int c) {
        if(r >= 0 && c >= 0 && r < this.n && c < this.n) {
            if(m[r][c].equals(Cella.VUOTA) && marcata[r][c] == false) {
                return true;
            }
        }
        return false;
    }

    private boolean uscitaRaggiungibileDa(int r, int c) {
        if(uscita(r, c)) return true;
        if(percorribile(r, c)) {
            setMarcata(r, c);
            return uscitaRaggiungibileDa(r+1, c) || uscitaRaggiungibileDa(r, c+1) || 
                   uscitaRaggiungibileDa(r-1, c) || uscitaRaggiungibileDa(r, c-1);
        }
        return false;
    }

    public boolean risolvibile() {
        return uscitaRaggiungibileDa(0, 0);
    }

    public String toString() {
        String lab = "";
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                if(isPiena(i, j)) lab+= "#";
                else {
                    if(isMarcata(i, j)) lab+= "+";
                    else lab+= ".";
                }
            }
            lab+= "\n";
        }
        return lab;
    }
}
