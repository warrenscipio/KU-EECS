
import java.lang.Math;

public class MySphere {
	

	//Define the constant PI.
	    private final double PI = 3.141592;
	    //The MySphere class has one instance variable; diameter
	    //Your code here:please fill the blanks.
	    public  double diameter;
	           
	    double r = diameter/2;
	   
	    //The MySphere class has four methods
	    public void setDiameter( double newDiameter ) {
	        diameter = newDiameter ;
	    }
	       
	    public  double getDiameter() {
	        return diameter ;
	    }
	   
	    public double calculateVolume() {
	         double volume = 0.0;
	         volume = (4/3)*PI*r*r*r;
	         return volume ;
	    }
	       
	    public double calculateSurfaceArea() {
	         double surfaceArea = 0.0;
	         surfaceArea = 4*PI*r*r;
	         return surfaceArea;
	    }


}
