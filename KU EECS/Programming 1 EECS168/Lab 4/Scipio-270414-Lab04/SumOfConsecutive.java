/*----------------------------
 * SumOfConsecutive.java
 * Warren Scipio
 * EECS - 168 Lab 4
 * calculates the summation of consecutive positive integers from k to n
 * 9/18/2012
 */
import java.util.Scanner;

public class SumOfConsecutive {
	
	public static void main(String[] args){
		
	//Declare Variables	
	int k; 
	int n;
	int i;
	int sum = 0;
	
	Scanner input = new Scanner(System.in);	
	
	System.out.println("Welcome! This program calculates the summation of consecutive intergers.");
	System.out.println("");
		
	System.out.print("Please input a positive integer as the initial value: ");
	//user input n
	n = input.nextInt();
	System.out.print("Please input a positive integer as the end value: ");
	//user input k
	k = input.nextInt();
	
	//adding up numbers in between n and k
	for (i = n; i <= k; i++)
		sum = sum + i;
		
		System.out.print("The summation is: "+ sum);
		
	}
		
		
		
		
		
		
		
		
	
	
	
	
	
	
	
	}


