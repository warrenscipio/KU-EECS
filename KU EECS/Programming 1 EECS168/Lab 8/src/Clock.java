import java.util.Scanner;


public class Clock {
	
	private int seconds;
	private int minutes;
	private int hours;
	private int number;
	
	
	
	public void input(){
		Scanner input= new Scanner(System.in);
		System.out.println(" Enter the Seconds:");
		number = input.nextInt();
		
		
	}
	
	public void input2(){
		Scanner input= new Scanner(System.in);
		System.out.println("Enter the Seconds for another Clock:");
		number = input.nextInt();
	}
	
public void currentC(){
	System.out.println("The Current clock time:");
	System.out.println("");
	
	
}
	
	
	//set seconds
	public void setSeconds(int newS){
		seconds = newS;
		
		
	}
	
	
	
public void setMinutes(int newM){
		
	  minutes = newM;
		
	}

public void setHours(int newH){
	hours = newH;
	
	
 
	
}

	
	
	public void setClock(int newSeconds)
	{
	 
		
	  int newH = newSeconds / 3600;
	  int newM = (newSeconds -(newH*3600)) / 60;
	  int newS = newSeconds -(newH*3600)-(newM*60);
	  
	  setHours(newH);
	  setMinutes(newM);
	  setSeconds(newS);		  
	}
	
	
	public void tick()
	{
	     //Validate seconds, hours and minutes
		
		System.out.println("The next ten ticks of the clock:");
	for (int i=0; i<10; i++){	
		seconds++;
		
	  if (seconds >=60){
		   minutes += 1;
		   seconds -= 60;
	  }
		 
	  
	  if (minutes >= 60){
		  hours +=1;
		  minutes-=60;
	  }
	  
	  if (hours >= 24)
		  hours -= 24;
		
	  
	  System.out.println(hours+":"+minutes+":"+seconds);
	  
	}
	  
	}
	
	
	public void addClock(Clock C)  //Passing the object of clock to the method.
	{
	   seconds += C.seconds;        // first add seconds
	     
	   //Validate seconds(they must be below 60)
	  if (seconds >= 60){
		  minutes +=1;
	  	seconds -= 60;
	  }
	   // next, add minutes
	   minutes += C.minutes;   
	   
	   
	   //Validate minutes(they must be below 60)    
	   if (minutes >= 60){
		hours += 1;
		minutes -= 60;
	   }
	   hours += C.hours;
	   //Rest of your code here
	   
	   System.out.println("The Current clock time:");
	   System.out.println(hours +":"+minutes+":"+seconds);
	   
		System.out.println("");
		
	   
	   
	}
	
	

	
	
public int getNumber() {
		
		return number;
	}
	

public int getSeconds() {
		
		return seconds;
	}
	

public int getMinutes() {
	
	return minutes;
}


public int getHours() {
	
	return hours;
}
	
	public void writeOut(){
		
		System.out.println(hours + ":"+ minutes+":"+seconds );
		System.out.println("");
		
	}
	
	
	

}
