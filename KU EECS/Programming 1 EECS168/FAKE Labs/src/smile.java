import javax.swing.JApplet;

import android.graphics.Color;

import java.awt.Graphics;


public class smile extends JApplet {
	
	public void paint(Graphics canvas){
	
	

		
		int myColor;
		
		
		int r  = random.nextInt(256);
		int g  = random.nextInt(256);
		int b  = random.nextInt(256);
		double theta = 2*Math.PI/(numShapes);
		int rad = 350, h=350, k=550;

		myColor = rgbToColor(r,g,b,255);
		canvas.clearRect(0, 0, canvas.getWidth(), canvas.getHeight());
		
		//large circle Center
		canvas.setColor(Color.BLACK);
		canvas.drawOval(20, 150, 750, 750);
		canvas.drawRect(20, 150, 750, 750);
		canvas.fillOval(20, 150, 10, 10);
		canvas.fillOval(395, 525, 10, 10);
		
		
		
		
		for(int i=1; i<=numShapes; i++){
		//Variables
		
		int x = (int) (h+rad*Math.cos(theta));
		int y = (int) (k+rad*Math.sin(theta));
		//random color for circles
		
		theta += theta;
		
		
		//random position
		canvas.setColor(myColor);
		canvas.fillOval(x, y, 100, 100);
		canvas.setColor(Color.BLACK);
		canvas.drawOval(x, y, 100, 100);
		
		canvas.drawRect(x, y, 100, 100);
	
	

		
		
		
		
		
	}
}
