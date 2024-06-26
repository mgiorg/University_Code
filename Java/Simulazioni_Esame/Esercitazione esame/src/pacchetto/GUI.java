package pacchetto;
import javax.swing.*;
import java.util.*; 
import java.awt.*;

public class GUI extends JFrame {
    JPanel top = new JPanel(new BorderLayout());
    JPanel mid = new JPanel(new BorderLayout());
    JPanel bottom = new JPanel(new BorderLayout());

    JTextField server = new JTextField("127.0.0.1");
    JTextField port = new JTextField("4400");

    JButton connectButton = new JButton("Connect");
    JButton disconnectButton = new JButton("Disconnect");
    JButton startButton = new JButton("Start");
    JButton stopButton = new JButton("Stop");
    JButton clearButton = new JButton("Clear");

    JPanel logPanel = new JPanel(new BorderLayout());
    JTextArea logArea = new JTextArea(100, 40);
    JScrollPane logPane = new JScrollPane(logArea);

    JPanel pdfPanel = new JPanel(new BorderLayout());
    JTextArea pdfArea = new JTextArea(100, 40);
    JScrollPane pdfPane = new JScrollPane(pdfArea);

    JPanel mp3Panel = new JPanel(new BorderLayout());
    JTextArea mp3Area = new JTextArea(100, 40);
    JScrollPane mp3Pane = new JScrollPane(mp3Area);

    Boolean connected, run;

    public GUI() {
        super("Massimo Giordano 2084173");
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setLayout(new BorderLayout());

        top.add(new JLabel("Server Address"));
        top.add(server);
        top.add(new JLabel("Port"));
        top.add(port);
        top.add(connectButton);
        top.add(disconnectButton);

        this.add(top, BorderLayout.NORTH);

        logPanel.setBorder(BorderFactory.createTitledBorder("Log"));
        pdfPanel.setBorder(BorderFactory.createTitledBorder(".pdf"));
        mp3Panel.setBorder(BorderFactory.createTitledBorder(".mp3"));

        mid.add(logPanel);
        mid.add(pdfPanel);
        mid.add(mp3Panel);

        this.add(mid, BorderLayout.CENTER);


        this.pack();
        this.setVisible(true);
    }
    public String getServer() {
        return server.getText();
    }
    public int getPort() {
        return Integer.parseInt(port.getText());
    }
    public void setStatus(Boolean connected, Boolean run) {
        this.connected = connected;
        this.run = run;
        update();
    }
    public void update() {
        
    }
}
