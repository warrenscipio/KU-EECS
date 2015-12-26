import java.util.Scanner;
import java.util.Random;


public class Rearranging_Cartons {
	
	public static void main(String[] args){
		
		boolean same=false;
		int count=0;
		int numberCarts;
		Random random;
		int[] newCarts;
		int[] carts;
		int temp =0;
		random = new Random();
		Scanner input = new Scanner(System.in);
		
		System.out.println("Sample input:");
		numberCarts = input.nextInt();
		
		carts = new int[numberCarts];
		newCarts = new int[numberCarts];
		
		for (int i=0;i<numberCarts;i++){
			carts[i]=i+1;//random.nextInt(100);
			
		}
		
		for(int i=0;i<numberCarts;i++)
			System.out.print(carts[i]+" ");
		System.out.println();
	
		for(int i=0;i<numberCarts;i++)
			newCarts[i]= input.nextInt();
		
		System.out.println();
		for(int i=0;i<numberCarts;i++)
			System.out.print(newCarts[i]+" ");
		
			
		System.out.println((carts[1]==newCarts[1]));
		
	
		for()
		
		do{
			
			
			
			
			
			
			
			
			
		}while ((count<7)||(same));
		
		
		
		
		
		
		
	}

}
