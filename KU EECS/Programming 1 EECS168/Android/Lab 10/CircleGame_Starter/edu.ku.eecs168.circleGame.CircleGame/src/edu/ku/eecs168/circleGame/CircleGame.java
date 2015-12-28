package edu.ku.eecs168.circleGame;

import android.view.MenuItem;
import android.view.MotionEvent;

import java.util.Random;

import edu.ku.eecs168.circleGame.R;
import android.graphics.Color;
public class CircleGame extends AbsCircleGame {
    private Random random;	
    private long startTime = -1;
    private long currentTime = -1;
	
    private int seconds;
    private long MAX_TIME;

    private int nCircles;
    private int score;
    private Circle arrayCircle[];
    
	public CircleGame() {
	  //This is how the timers are initialized
	  //To restart the timer you can set these variables to
	  // -1
		startTime = -1;
		currentTime = -1;
		seconds = 30;
		score =0;
		//This will start our program drawing 1 circle
        redrawCircles(1);
        
	}
	
	public void redrawCircles(int n){
	    random = new Random();
	    MAX_TIME = 1000L * seconds;
	    nCircles =n;
	    
	    //TODO create and initialize an array of Circles
	    // of size nCircles
	    
	    
	    for (int i=0; i < nCircles; i++){
	    	arrayCircle[i] = new Circle();
	    }
	    
	}
	
	
	@Override
	public void paint(Graphics canvas) {
		// Clear the canvas (don't change this part)
		canvas.clearRect(0, 0, canvas.getWidth(), canvas.getHeight());
		random = new Random();
		
		int count = 0;
		
		
		
		for(int i=0; i<nCircles;i++){
			Circle circle = arrayCircle[i];
			int r = random.nextInt(256);
			int b = random.nextInt(256);
			int g = random.nextInt(256);
			
			
			
			if(!circle.getInitialized()){	
				circle.setYposition(random.nextInt(canvas.getWidth()));
				circle.setXposition(random.nextInt(canvas.getHeight()));
				circle.setDirectionX(random.nextInt(2));
				circle.setDirectionY(random.nextInt(2));
				circle.setColor(rgbToColor(r,g,b,255));
				circle.setInitialized(true);
	
			
			}
		//TODO For each circle
		    // If the circle does not have X and Y values within the screen (is not initialized)
		    // then get new x and y values
			if(circle.getVisible()){
			// if the circle is visible
		    // then call the circle's move method with the canvas object as the input parameter
				canvas.drawOval(circle.getXposition(), circle.getYposition(),circle.getDiameter(), circle.getDiameter());
				canvas.setColor(circle.getColor());
				canvas.fillOval(circle.getXposition(), circle.getYposition(),circle.getDiameter(), circle.getDiameter());
				
				circle.move(canvas);
			
			}else{count++;}
			
		// If there are no visible circles then call the resetGame with nCircles++
			
			if (count == nCircles){
			redrawCircles(nCircles+1);
			i=0;
			}
		    // If they also haven't had the directions, color, or diameter(optional) set,
		    // then set those values as well
		    // mark the circle as initialized
		
			
	
		    
		}
		canvas.setColor(Color.BLACK);
		if ( currentTime - startTime <= MAX_TIME){		
		    canvas.drawString("Score: "+score, 30, 30);
		}else{
		    canvas.drawString("GAME OVER", canvas.getWidth()/2-30 , canvas.getHeight()/2 -30);
		    canvas.drawString("  Score: "+score, canvas.getWidth()/2 ,canvas.getHeight()/2 + 30);
		    canvas.drawString("Seconds: "+seconds, canvas.getWidth()/2 ,canvas.getHeight()/2 + 60);
		}
	}
	
	@Override
	public boolean onTouchEvent(MotionEvent e){
	    super.onTouchEvent(e);
	    
	    // our times have not been initialized
	    if (startTime <0 ){
	        startTime = e.getEventTime();
	        currentTime = e.getEventTime();
	     
	    // We have been initialized just get current time    
	    }else{
	        currentTime = e.getEventTime();
	    }
	    
	    
	    //This line keeps the user from being able to swipe the circles
	    // And stops the touch recognition after time is done
	    if ( e.getActionMasked() != MotionEvent.ACTION_DOWN 
	            || currentTime - startTime >= MAX_TIME){
        
	        return false;
	    }
	    
	    
	    //The coordinates for user touch
	    float touchX = e.getRawX();
	    float touchY = e.getRawY()-100;
	    
	    
	    for (int i = 0; i < nCircles; i++){
	        
	    	Circle circle = arrayCircle[i];
	      
	        // *circle's center (x,y) and radius, and visibility 
	         
	        int centerX = (int) (circle.getXposition()+(circle.getDiameter()/2.0));
	        int centerY = (int) (circle.getYposition()+(circle.getDiameter()/2.0));
	        int radius = (circle.getDiameter()/2);
            boolean isVisible = true;

	        boolean inCircle = Math.pow(touchX - centerX, 2) + Math.pow(touchY - centerY, 2)< Math.pow(radius, 2); 
	        
	        if (inCircle && isVisible){
	           score++;
	          
	         setVisible(false);
	 
	        }
	        
	    }
	  
	    return false;
	}
	
	@Override
	public void onDialogReturned(int num) {
		// You must call super.onDialogReturned to start the simulation
	    super.onDialogReturned(num);
	
		//The user has just set the time to num
		seconds = num;
		score = 0;
		currentTime = -1;
		startTime = -1;
		redrawCircles(1);
	}
	
	   @Override
	public boolean onOptionsItemSelected(MenuItem item) {
           
	       //Restart Game has just been pressed
	       if(item.getItemId() == R.id.b2){
	           score = 0;
	           currentTime = -1;
	           startTime = -1;
	           redrawCircles(1);
	        }
	       return super.onOptionsItemSelected(item);
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
