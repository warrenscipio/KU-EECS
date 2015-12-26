/*----------------------------
 * TestOldMacDonald.java
 * Warren Scipio
 * EECS - 168 Lab 7
 * calls methods and sings old macdonald song
 * 10/16/2012
 */

public class TestOldMacDonald {
	
	
	
	
	public static void main(String[] args){ 
		 //Create an animal and an OldMacDonald object
		 Animal animalA = new Animal();
		 OldMacDonald md = new OldMacDonald();
		 
		
		//Tell the animal what type it is and what sound it makes
		 animalA.setSound("moo");
		 animalA.setType("cow");
		 
		 //Tell OldMacDonald which animal to sing about
		 md.setAnimal(animalA);

		 //Tell OldMacDonald to sing
		 md.sing();

		}

}
