package edu.ku.eecs168.lab9;

import android.os.Bundle;

import java.util.Random;
import android.graphics.Color;
public class Lab9 extends AbsLab9 {
	private Random random;
	
	// TODO: Declare the instance variables that you will need to complete the assignment here.
		
		private int circleDiameter;
		private int N_circles;
		private int cur_circle;
		private int[] xArr;
		private int[] yArr;
	
	public void setNCircles(int addShapes_amount){
		
		N_circles = addShapes_amount;
		cur_circle = 4;
		xArr = new int[N_circles];
		yArr = new int[N_circles];
		
		for ( int i=0; i<xArr.length; i++)
			xArr[i] = 0;
		
		for ( int j=0; j<yArr.length; j++)
			yArr[j] = 0;
		
		circleDiameter = 100;
	}
	public Lab9() {
		// Instantiate an object of class Random
		// This allows me to get random numbers by calling random.nextInt(MAX_RAND_INT), where MAX_RAND_INT is the highest possible value
		random = new Random();
		
		// TODO: Initialize your instance variables here
		setNCircles(5);
		
	}
	
	@Override
	public void paint(Graphics canvas) {
		// Clear the canvas (don't change this part)
		canvas.clearRect(0, 0, canvas.getWidth(), canvas.getHeight());
		
	
	
		
		
		// random color
		 
			
			int myColor;
			int red = random.nextInt(256);
			int blue = random.nextInt(256);
			int green = random.nextInt(256);
	   	
		//getting random position for each array
			do{	 
				xArr [cur_circle]= random.nextInt(canvas.getWidth()-circleDiameter);
			 	 yArr [cur_circle]= random.nextInt(canvas.getHeight()-circleDiameter);
			
			 	 //loop to prevent random numbers from being 0
			}while ((xArr [cur_circle]==0)||(yArr [cur_circle]==0));
					
					
					
					
					
	
	 for(int i =0; i< N_circles; i++){
		 
		 int draw_index;
		 
	   	draw_index = (cur_circle+1+i) % N_circles;
	   	
			
	   	myColor = rgbToColor(red,blue,green,255);
	   	
	   	//if statement to not allow arrays still equal to zero to not be drawn
		 if( (xArr[draw_index]!=0) && (yArr[draw_index]!=0) ){
		 canvas.setColor(Color.BLACK);
		 canvas.drawOval(xArr[draw_index], yArr[draw_index],circleDiameter , circleDiameter);
		 }
		 
		 
	 }
	
	 
	 cur_circle ++;
	if( cur_circle >= N_circles)
		cur_circle = cur_circle - N_circles;

		// TODO: Add your code for painting the screen here.
		
	}
	
	public void setNCircles(){
	
	}
	
	@Override
	public void onDialogReturned(int num) {
		// You must call super.onDialogReturned to start the simulation
		super.onDialogReturned(num);
		setNCircles(num);
		repaint();
	}
	
	
	
	public void paint(){

		
		
		
	}
	
	
	
	
	
	
	
	
	
	
	


	// The setColor method of the Graphics class expects color to be specified as a single int.
	// This routine converts RGBalpha values into a single int that setColor can understand.
	// Specify the red, green, blue and alpha values as integers between 0 and 255.
	// Alpha is a transparency component - an alpha of 255 is fully opaque, 
	//   while an alpha of 0 is transparent.
	// The output of rgbToColor is an integer that is in the format expected by setColor,
	// which is specified by a hexidecimal value of the format 0xAARRGGBB
	static public int rgbToColor(int red, int green, int blue, int alpha) {
		int color = 0;
		color += blue;
		color += 256*green;
		color += 256*256*red;
		color += 256*256*256*alpha;
		return color;
	}
}
