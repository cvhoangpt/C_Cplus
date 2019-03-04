import java.awt.Dimension;
import java.awt.Insets;

import javax.swing.JButton;

/* This class manages all components used on the main
 * control panel (bottom left) Meant to remove some
 * excessive graphics code from "Frame.java" class
 * by Devon Crawford
 */
public class ControlHandler {
	private Frame frame;
	private JButton run;
	private JButton reset;

	Dimension npD;
	
	public ControlHandler(Frame frame) {
		
		// Set up JButtons
		run = new JButton();
		run.setText("run");
		run.setName("run");
		run.setFocusable(false);
		run.addActionListener(frame);
		//run.setActionCommand("run");
		run.setMargin(new Insets(0,0,0,0));
		run.setVisible(true);
		run.setBounds(116, frame.getHeight()-88, 52, 22);
		frame.add(run);

		reset = new JButton();
		reset.setText("reset");
		reset.setName("reset");
		reset.setFocusable(false);
		reset.addActionListener(frame);
	//reset.setActionCommand("reset");
		reset.setMargin(new Insets(0,0,0,0));
		reset.setVisible(true);
		reset.setBounds(172, frame.getHeight()-88, 52, 22);
		frame.add(reset);
		
	}
//	public void position() {
//		// Set button bounds
//		run.setBounds(116, frame.getHeight()-88, 52, 22);
//	}

	
//	// Adds all components to frame
//	public void addAll() {
//		frame.add(run);
//	}
}