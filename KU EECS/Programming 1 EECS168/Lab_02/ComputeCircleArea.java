
/*---------------------------------------------------------------
*
* ComputeCircleArea.java
* Warren Scipio w538s936@ku.edu
* EECS-168 Lab 2
* gives area of circle with a radius of ___
*
* 08/28/12
*
------------------------------------------------------------------*/


import java.util.Scanner;

public class ComputeCircleArea{

	public static void main(String[] args){
	
		System.out.println("Type a radius:");		
		
		double PI = 3.141592;
		double radius;

		Scanner input = new Scanner(System.in);
		radius = input.nextDouble( );

		System.out.println("the area of a circle with the radius of " + radius + " is " + PI * radius);

	}

}
