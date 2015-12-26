import java.util.Scanner;

public class PrintTriangle {
	
	public static void main(String[] args){
	
	
		
		int width = 0;
		
		
		Scanner input = new Scanner(System.in);	
		
	System.out.println("Input integer greater than 0.");
		
	
	width = input.nextInt();
		
	
	

		for (int i=1; i <= width; i++){
	
			for (int k=1; k<=i; k++){
			
		
		System.out.print(" *");
		
			}
			System.out.println();
	}
		
	}

}
