import javax.swing.*;
import java.awt.*;


public class GUI extends JFrame{
	private static final long serialVersionUID = 1L;
	final JButton Start= new JButton("Start");
	final JButton Reset= new JButton("Reset");
	final JButton Stop=new JButton("Stop");
	final JButton Pesca=new JButton("Pesca");
	final JPanel UpperPane= new JPanel();
	final JPanel CentralPane= new JPanel();
	final JPanel LowerPane= new JPanel();
	public Boolean GameRun=false;
	private Boolean GameEnd=false;
	private Boolean GameStop=false;
	final JPanel LogPane=new JPanel();
	final JTextArea Log=new JTextArea(50,25);
	final JTextArea logmazzo=new JTextArea(50,25);
	final JTextArea Hand=new JTextArea(50,25);
	final JButton Passa=new JButton("Passa");
	final JCheckBox p1 = new JCheckBox("1");
	final JCheckBox p2 = new JCheckBox("2");
	final JCheckBox p3 = new JCheckBox("3");
	final JCheckBox p4 = new JCheckBox("4");
	final JCheckBox p5 = new JCheckBox("5");
	
	
	public GUI() {
		super("PokerGame");
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.getContentPane().setLayout(new BorderLayout());
		
		Act act=new Act(this);
		Start.addActionListener(act);
		Stop.addActionListener(act);
		Reset.addActionListener(act);
		Pesca.addActionListener(act);
		Passa.addActionListener(act);
		
		UpperPane.setLayout(new FlowLayout());
		CentralPane.setLayout(new FlowLayout());
		LowerPane.setLayout(new FlowLayout());
		
		this.getContentPane().add(UpperPane,BorderLayout.NORTH);
		this.getContentPane().add(CentralPane,BorderLayout.CENTER);
		this.getContentPane().add(LowerPane,BorderLayout.SOUTH);
		this.getContentPane().add(LogPane,BorderLayout.EAST);
		this.getContentPane().add(logmazzo, BorderLayout.WEST);
		
		CentralPane.add(Hand);
		LowerPane.add(Start);
		LowerPane.add(Reset);
		LowerPane.add(Stop);
		LowerPane.add(Pesca);
		Stop.setEnabled(false);
		Reset.setEnabled(false);
		Pesca.setEnabled(false);
		
		UpperPane.setLayout(new FlowLayout());
		UpperPane.add(p1);
		UpperPane.add(p2);
		UpperPane.add(p3);
		UpperPane.add(p4);
		UpperPane.add(p5);
		UpperPane.add(Passa);
		Passa.setEnabled(false);
		
		
		
		LogPane.setLayout(new BorderLayout());
		JScrollPane SLog=new JScrollPane(Log);
    	SLog.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_ALWAYS);
		LogPane.add(SLog,BorderLayout.CENTER);
		Log.setEditable(false);
		logmazzo.setEditable(false);
		Hand.setEditable(false);
		
		
		Log.append("BENVENUTO SCEMO \n");
		
		this.pack();
    	this.setLocationRelativeTo(null);
    	this.setVisible(true);
	}
	
	public void write(String s) {
		Log.append(s+'\n');
	}
	
	public void setStatus(Boolean Run,Boolean Stop,Boolean End) {
		this.GameRun=Run;
		this.GameStop=Stop;
		this.GameEnd=End;
		update();
	}
	
	public void update() {
		if(GameRun) {
			Start.setEnabled(false);
			Stop.setEnabled(true);
			Reset.setEnabled(true);
			Pesca.setEnabled(true);
			Passa.setEnabled(true);
		}
		if(GameStop) {
			Start.setEnabled(true);
			Stop.setEnabled(false);
			Reset.setEnabled(false);
			Pesca.setEnabled(false);
			Passa.setEnabled(false);
		}
		if(GameEnd) {
			Start.setEnabled(false);
			Stop.setEnabled(true);
			Reset.setEnabled(true);
			Pesca.setEnabled(false);
			Passa.setEnabled(false);
		}
	}
}
