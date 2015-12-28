/*----------------------------
 * DoOddSum.java
 * Warren Scipio
 * EECS - 168 Lab 4
 * adds up all odd numbers under number inputed
 * 9/18/2012
 */
import java.util.Scanner;

public class DoOddSum {


	
	public void main(String[] args){
		
		//Declaring variables
		int number = 0; 
		int value = 0;
		int x = 0;
		
		
		System.out.print("Please input a positive odd integer as the end Value: ");
		
		//Getting user input
		Scanner input = new Scanner(System.in);
		number = input.nextInt();
		
		//Loop adding up odd numbers
		do
		{
			value = x + value;
			x = x + 1; 
			
			
		}while (x <= number);
		
		System.out.print("The summation is: "+ value);
		
		
	}

}
