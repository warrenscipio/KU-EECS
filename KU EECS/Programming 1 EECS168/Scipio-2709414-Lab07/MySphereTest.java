
/*----------------------------
 * MySphereTest.java
 * Warren Scipio
 * EECS - 168 Lab 7
 * finds volume and surface area of ball
 * 10/16/2012
 */

import java.util.Scanner;

public class MySphereTest {
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		MySphere myBall = new MySphere();
		Scanner input= new Scanner(System.in);
		int answer;
	//start of loop
	do{
		//asks for user input
		System.out.print("Enter the diameter of the ball:");
	
		myBall.setDiameter (input.nextDouble( ));
		
				
		
                System.out.println("The diameter of the ball is " + myBall.getDiameter() );
                double ballVolume = myBall.calculateVolume() ;
                double ballSurface = myBall.calculateSurfaceArea() ;
        
                System.out.printf("The volume is  %7.2f\n", ballVolume);
                System.out.printf("The surface area is %7.2f\n", ballSurface);
        
            	//asks for user input to repeat
                System.out.println("Do you want to try another ball?");
                System.out.print("Please enter 1 for yes, 0 for No:");
                
                answer = input.nextInt();
          // if true repeat      
	}while(answer==1);         
    System.out.println("Goodbye!");
	
	}
	

}
