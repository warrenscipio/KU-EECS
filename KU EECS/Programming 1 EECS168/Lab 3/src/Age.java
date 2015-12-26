/*----------------------------
 * Age.java
 * Warren Scipio
 * EECS - 168 Lab 3
 * tells you what you are depending on your age
 * 9/11/2012
 */



import java.util.Scanner;

public class Age {
	public static void main(String[] args){
		
		double age;
		
		System.out.println("Enter your age:");
		
		Scanner input = new Scanner(System.in);
		
		age = input.nextDouble( ); 
		
		
	if ( age < 0 ){
		System.out.println("you are an abomination!!!!");
		
	} else if ( age <= 1 ){
		System.out.println("you are a baby!");
		
	} else if (( age >1 ) && (age <= 3)){
		System.out.println("you are a toddler!");
	} else if (( age > 3) && ( age < 13)){
		System.out.println("you are a child!");
	} else if (( age >= 13) && (age < 20 )){
		System.out.println("you are a teenager!");
	} else if (( age >= 20) && ( age < 65)){
		System.out.println("you are an adult!");
	} else if ( age >= 65){
		System.out.println("you are a senio citizen!");
	}
		
		
		
	}
}
