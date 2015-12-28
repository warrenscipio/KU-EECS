/*----------------------------
 * OddSum.java
 * Warren Scipio
 * EECS - 168 Lab 4
 * adds up all odd numbers under number inputed
 * 9/18/2012
 */

import java.util.Scanner;

public class OddSum {
	
	public static void main(String[] args){
	
		//Declaed variables
		int number = 0; 
		int sum = 0;
		int x = 1;
		
		
		System.out.print("Please input a positive odd integer as the end Value: ");
		//user input :)
		Scanner input = new Scanner(System.in);
		number = input.nextInt();
		
		//Loop to add up odd numbers
		while( x<= number )
		{
			sum = (sum + x);
			x = (x + 2);
			
		}
		
		//final output
		System.out.print("The summation is: "+ sum);
		
		
	}

}
