/*----------------------------
 * MySphere.java
 * Warren Scipio
 * EECS - 168 Lab 7
 * methods to MySphereTest
 * 10/16/2012
 */

import java.lang.Math;

public class MySphere {
	

	//Define the constant PI.
	    private final double PI = 3.141592;
	    //The MySphere class has one instance variable; diameter
	    //Your code here:please fill the blanks.
	    private  double diameter;
	           
	    
	   
	    //The MySphere class has four methods
	    public void setDiameter( double newDiameter ) {
	        diameter = newDiameter ;
	    }
	       
	    public  double getDiameter() {
	        return diameter ;
	    }
	   //calculates volume then returns to test
	    public double calculateVolume() {
	         double volume = 0.0;
	         volume = (4.0/3)*PI*(diameter/2)*(diameter/2)*(diameter/2);
	         return volume ;
	    }
	  //calculates surfacearea then returns to test 
	    public double calculateSurfaceArea() {
	         double surfaceArea = 0.0;
	         surfaceArea = 4.0*PI*(diameter/2)*(diameter/2);
	         return surfaceArea;
	    }

}
