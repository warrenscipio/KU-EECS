/*----------------------------
 * OldMacDonald.java
 * Warren Scipio
 * EECS - 168 Lab 7
 * sends methods to TestOldMacDonald
 * 10/16/2012
 */

public class OldMacDonald {

	private Animal myAnimal;
	
	
	
	
	
	public Animal getAnimal(){
		return myAnimal;
		
	}
	
	
	
	public void setAnimal(Animal newAnimal){
		this.myAnimal = newAnimal;
	}
	
	
	
	
	
	
	
	public void sing() {
		//tp get moo and cow
	String	animal = myAnimal.getType();
	String	sound = myAnimal.getSound();
		//song with user input
		System.out.println("Old MacDonald had a farm, EE-I-EE-I-O");
		System.out.println("And on the farm he had a "+ animal + " EE-I-EE-I-O");
		System.out.println("With a "+sound+"-"+sound+" here, and a " + sound+"-"+sound + " there,");
		System.out.println("Here a " + sound+", there a "+ sound+", everywhere a " +sound+"-"+sound+",");
		System.out.println("Old MacDonald had a farm, EE-I-EE-I-O");
		
	}

}
