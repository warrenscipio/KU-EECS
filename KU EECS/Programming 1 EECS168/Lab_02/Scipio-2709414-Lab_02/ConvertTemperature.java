/*---------------------------------------------------------------
*
* ConvertTemperature.java
* Warren Scipio w538s936@ku.edu
* EECS-168 Lab 2
* converts fahrenheit to celsius
*
* 08/28/12
*
------------------------------------------------------------------*/

import java.util.Scanner;

public class ConvertTemperature{

	public static void main(String[] args){

	System.out.println("Enter the temperature in Fahrenheit: ");

	double fahrenheit;
	
	Scanner keyboard = new Scanner(System.in);
	fahrenheit = keyboard.nextDouble( );

	System.out.println(fahrenheit + "degrees Fahrenheit =");

	System.out.println((fahrenheit - 32)*5/9 + " celsius");
	}
}
	
