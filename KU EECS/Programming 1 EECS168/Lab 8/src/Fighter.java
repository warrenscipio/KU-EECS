import java.util.Random;
import java.util.Scanner;

/*----------------------------
 * Fighter.java
 * Warren Scipio
 * EECS - 168 Lab 7
 * sends methods to KUStudentTest
 * 10/21/2012
 */


public class Fighter {

    String opponentName;
    String fAttacker;
    String sAttacker;
    String player;
    
    double block;
    int damage;
    int blood_points;
	int defense_level;
	int attack_level;
	int opponentBlood;
	
	public void input(){
		Scanner input= new Scanner(System.in);
		
		System.out.print("Please give a first name for fighter one:");
		player = input.next();
		
		System.out.print("What is the blood points of the fighter?");
		blood_points = input.nextInt();
		
		while ((blood_points >50) || (blood_points < 0)){
			System.out.print("Blood points should be less than or equal to 50 and greater than 0, please re-enter:");
			blood_points = input.nextInt();
		}
		
		System.out.print("What is the defense level of the fighter?");
		 defense_level = input.nextInt();
		
		System.out.print("What is the attack level of the fighter?");
		 attack_level = input.nextInt();
		
		while ( ((defense_level + attack_level) > 50)|| ((defense_level + attack_level) < 0)){
			System.out.println("Defense level plus attack level must not be greater than 50 or less than 0.");
			System.out.print("Knowing this please re-enter Defense level a SPACE then attack level:");
			defense_level = input.nextInt();
			attack_level = input.nextInt();
		}
		System.out.println("");
	}
	
	private void syncHealth( int damage){
		
		blood_points -= damage;
		
	}

       
    
    public boolean attack(Fighter opponent) {
		
    	
    	boolean dead = false;
    	
    	Random random = new Random();
		Double accuracy = random.nextDouble();
    	
		block = 10.0/opponent.getDefense();
    	opponentBlood = opponent.getHealth();
		opponentName = opponent.getName();
		
		
    	if(block > accuracy){
    		
    		double attack_multiple = random.nextDouble();
    		damage = (int)(attack_multiple * attack_level)+1;
    		opponent.syncHealth(damage);
    		int healthLeft = (opponentBlood-damage);	
    	
    		System.out.print( "   " + player + " hits " + opponentName +". " + opponentName + " loses " + damage + " blood points");
    		
    		
    		if (healthLeft < 1){
    			dead = true;
    		}else{
    			
        	
        	System.out.println(", and has " + healthLeft + " left.");
    			
    			
    		}
    			
    		
    		
    		
    		
    	}else{
    		
    		System.out.println( "   " + player + " attacks " + opponentName + " but misses. " + opponentName + " has " + opponentBlood +" blood points left.");
    	
    	}
    	
    	
    	return dead;
    	
    }
    
    
	private int getDefense() {
		// TODO Auto-generated method stub
		return defense_level;
	}


	public String getName() {
		
		return player;
	}
	
	
	public int getHealth() {
		
		return blood_points;
	}
	
	


    
	
}
