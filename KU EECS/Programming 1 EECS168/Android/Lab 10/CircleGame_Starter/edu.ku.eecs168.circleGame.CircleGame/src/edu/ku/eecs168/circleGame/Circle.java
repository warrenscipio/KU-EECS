package edu.ku.eecs168.circleGame;

import android.graphics.Canvas;
import android.graphics.Color;
import edu.ku.swingemu.AndroidJApplet.Graphics;

public class Circle {

	private int xPosition;
	private int yPosition;
	private boolean visible;
	private int color;
	private int directionX;
	private int directionY;
	private boolean initialized;
	private int diameter;//>=50
	
	public Circle(){
		xPosition =0;
		yPosition =0;
		visible = true;
		color = 0;
		directionX = 1;
		directionY = 1;
		initialized = false;
		diameter = 100;
		
		
		
	}
	
	
	
	public void move (Graphics c){
		
		
		
		
		//check screen size
		if (xPosition >= c.getWidth()){
			xPosition = c.getWidth();
			directionX = -1*directionX;
		}
		if(yPosition >= c.getHeight()){
			yPosition =c.getHeight();
			directionY = -1*directionY;
		}
		//move circle
		xPosition = xPosition + directionX;
		yPosition = yPosition + directionY;
		
		
	}
	
	public void setXposition(int x){
		
		xPosition = x;
		
		
	}

	public void setYposition(int y){
		yPosition = y;
		
	}

	public void setVisible(boolean newValue){
		visible = newValue;
		
	}

	public void setColor(int theColor){
		color = theColor;
		
	}

	public void setDirectionX(int moveX){
		directionX = moveX;
		directionX += 1;
	}

	public void setDirectionY(int moveY){
		directionY = moveY;
		directionY += 1;
		
	}

	public void setInitialized(boolean newValue){
		initialized = newValue;
		
	}

	public void setDiameter(int dia){
		diameter = dia;
		
	}
	
	public int getXposition(){
		return xPosition-diameter;
		
	}
	
	public int getYposition(){
		return yPosition-diameter;
		
	}
	
	public boolean getVisible(){
		return visible;
		
	}
	
	public int getColor(){
		return color;
		
	}
	
	public int getDirectionX(){
		return directionX;
		
	}
	
	public int getDirectionY(){
		return directionY;
		
	}
	
	public boolean getInitialized(){
		return initialized;
		
	}
	
	public int getDiameter(){
		return diameter;
		
	}
	
	
	
	
	
	
	
	
	
	
	
	
}
