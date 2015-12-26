/*----------------------------
 * ServiceCharge.java
 * Warren Scipio
 * EECS - 168 Lab 3
 * assess a service charge for a check
 * 9/11/2012
 */
import java.util.Scanner;

public class ServiceCharge {

	public static void main(String[] args){
	
		double amount;
		
		double serviceCharge;
		
		Scanner input = new Scanner(System.in); 
		System.out.print(" Enter the check amount: ");
		
		amount = input.nextDouble();
		
		if (amount <=10 ){
			serviceCharge =  1;
			System.out.println("Your service charge will be $" + serviceCharge);
		} else if (amount <= 100){
			serviceCharge = (amount*.1);
			System.out.println("Your service charge will be $" + serviceCharge);
		} else if ( amount <= 1000){
			serviceCharge = ((amount*.05)+5);
			System.out.println("Your service charge will be $" + serviceCharge);
		} else if ( amount > 1000){
			serviceCharge = ((amount*.01)+40);
			System.out.println("Your service charge will be $" + serviceCharge);
		}
		
		
		
		
	}
}
