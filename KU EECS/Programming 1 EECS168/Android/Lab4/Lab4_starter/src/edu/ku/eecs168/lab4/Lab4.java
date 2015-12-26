package edu.ku.eecs168.lab4;

import edu.ku.swingemu.AndroidJApplet;

public class Lab4 extends AndroidJApplet {

	@Override
	public void paint(Graphics canvas) {
		
		canvas.drawOval(100, 50, 200, 200);
		canvas.fillOval(155, 100, 10, 20);
		canvas.fillOval(230, 100, 10, 20);
		canvas.drawArc(150, 160, 100, 50, 180, 180);

	}

}
