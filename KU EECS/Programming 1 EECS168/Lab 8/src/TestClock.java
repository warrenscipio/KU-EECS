
public class TestClock {
	
	public static void main(String[] args){
		
		Clock myClock = new Clock();
		Clock myClock2 = new Clock();
		
		
		
		// first clock get info
		myClock.input();
		
		int number = myClock.getNumber();
		
		//set the hours minutes seconds
		myClock.setClock(number);
		
		//give output
		myClock.writeOut();
		
		//clock two info
		myClock2.input2();
		
		//set new number
		number = myClock2.getNumber();
		
		//assign new hours numbers and seconds
		myClock2.setClock(number);
		
		//output new time
		myClock2.writeOut();
		
		//add clocks better
		myClock.addClock(myClock2);
		
		//add two clocks together
		
		
		// ticks 
		myClock.tick();
		
		
		
	}

}
