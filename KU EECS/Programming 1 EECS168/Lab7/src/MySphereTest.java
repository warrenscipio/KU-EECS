
public class MySphereTest {
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		MyShere myBall = new MySphere();
		myBall.setDiameter (1.5);
                System.out.println("The diameter of the ball is " + myBall.getDiameter );
                double ballVolume = myBall.calculateVolume ;
                double ballSurface = myBall.calculateSurfaceArea ;
        
                System.out.printf("The volume is  %7.2f\n", ballVolume);
                System.out.printf("The surface area is %7.2f\n", ballSurface);
        
                myBall.setDiameter(2.5);
                System.out.println("The diameter of the ball is " + myBall.getDiameter );
                ballVolume = myBall.calculateVolume ;
                ballSurface = myBall.calculateSurfaceArea ;
                System.out.printf("The volume is  %7.2f\n", ballVolume);
                System.out.printf("The surface area is %7.2f\n ", ballSurface);
	}
}
