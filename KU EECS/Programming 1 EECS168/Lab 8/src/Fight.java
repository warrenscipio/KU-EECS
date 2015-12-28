/*----------------------------
 * Fight.java
 * Warren Scipio
 * EECS - 168 Lab 7
 * calls methods from KUStudent to output kuinfo
 * 10/16/2012
 */

import java.util.Random;



public class Fight {
	
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Fighter fighter1 = new Fighter();
		Fighter fighter2 = new Fighter();
		
		

		boolean dead;
		
		
		
		
		
		
//asks for user input for the 2 fighters
		System.out.println("=====================================");
		System.out.println("Read fighter1 information from the keyboard");
		
		fighter1.input();
		
		System.out.println("=====================================");
		System.out.println("Read fighter2 information from the keyboard");
		
		fighter2.input();
			
		Random random = new Random();
		Double number = random.nextDouble();
		
		if ( number > .5){
			System.out.println(fighter1.getName() + " will attack first!");
			
		
			for(int i=1; i<=10; i++ ){
				
				
				System.out.println("round " + i+":");
			
			dead =	fighter1.attack(fighter2);
			if (dead){
				System.out.println(" "+fighter2.getName() + " is defeted!");
				System.exit(0);
			}
				
			dead = fighter2.attack(fighter1);
			if (dead){
				System.out.println(" "+fighter2.getName() + " is defeted!");
				System.exit(0);
			}
				
			
				
				
				
				
				
			}System.out.println("Time ran out! Its a tie!");
		
		}else{
			System.out.println(" "+fighter2.getName() + " will attack first!");
			
			  
       
			

			for(int i=1; i<=10; i++ ){
				
				
				System.out.println("round " + i+":");
			
			dead =	fighter2.attack(fighter1);
			if (dead){
				System.out.println(" "+fighter1.getName() + " is defeted!");
				System.exit(0);
			}
			
			dead =	fighter1.attack(fighter2);
			if (dead){
				System.out.println(" "+fighter2.getName() + " is defeted!");
				System.exit(0);
			}
			
				
				
	
			}System.out.println("Time ran out! Its a tie!"); 
			
			
			
			
			
			
			
			
		}
                
                
                
	         
 
	
	}
	

}

