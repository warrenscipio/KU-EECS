/*----------------------------
 * SeasonStartDay.java
 * Warren Scipio
 * EECS - 168 Lab 4
 * tells user the start of season
 * 9/18/2012
 */

import java.util.Scanner;

public class SeasonStartDay {
	
	
	public static void main(String[] args){
	
		
		
	int value = 0;
	
	Scanner input = new Scanner(System.in);
	
	do
	{
		//start program
		System.out.println("Enter 0 for Spring.");
		System.out.println("Enter 1 for Summer.");
		System.out.println("Enter 2 for Fall.");
		System.out.println("Enter 3 for Winter.");
		System.out.println("");
		System.out.print("Enter the season:");
		//input by user
		value = input.nextInt();
		System.out.println("--------------------");
		System.out.println("");
		
		//Seasons put to numbers
		
		if(value == 0){
			System.out.println("The start of Spring will be on Tuesday, March 20,2012.");		
	
		}else if (value == 1){
			System.out.println("The start of Summer will be on Wednesday, June 20,2012.");		
			
		}else if (value == 2 ){
			System.out.println("The start of Fall will be on Saturday, September 22,2012.");		
		
		}else if (value == 3) {
			System.out.println("The start of Winter will be on Friday, December 21,2012.");		
			
		}
			
		
	}while (value > 3 || value <0);
	
	
	
	
	
	
	
	
		
		
	}

}
