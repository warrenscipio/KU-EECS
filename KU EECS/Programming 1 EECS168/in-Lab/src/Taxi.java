import java.util.Scanner;



public class Taxi {
	public static void main(String[] args){
		
		int[] numbers;
		int number;
		Scanner input = new Scanner(System.in);
		
		System.out.println("Enter Integer:");
		
		number = input.nextInt();
		
		numbers= new int[number];
		
		for( int i=0;i<number;i++)
			numbers[i]=i;
	
		for(int a=1;a<number; a++){
			
			for(int b=1;b<number; b++){
				
			
				
				for(int c=1;c<number; c++){
					
				
					for(int d=1;d<number; d++){
						
						if((a!=b)&&(a!=c)&&(a!=d)&&(b!=c)&&(b!=d)&&(c!=d)){
							if((a*a*a)+(b*b*b) == (c*c*c)+(d*d*d)){
								System.out.print( a +" " + b+" " + c+" " + d );
								System.out.println();
							}
						}
					}
			
				}
			
			}
			
			
		}
		
		
		
		
		
	}

}
