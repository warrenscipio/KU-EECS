import java.io.FileNotFoundException;
import java.io.File;
import java.util.Scanner;


public class numberBlock {
	public static void main(String[]args){
		String[] lines;
		String find;
		int count =0;
		Scanner input = new Scanner(System.in);
		System.out.println("enter the file you want to read.");
		find = input.nextLine();
		
		String fileName = find;
		Scanner inputStream = null;
		
			try {
				inputStream = new Scanner(new File(fileName));
			} catch (FileNotFoundException e) {
				
				System.out.println("Error did not find file");
				e.printStackTrace();
			}
			
		while(inputStream.hasNextLine()){
			String line = inputStream.nextLine();
			
			count++;
		}
		
		lines = new String[count];
		
		try {
			inputStream = new Scanner(new File(fileName));
		} catch (FileNotFoundException e) {
			
			System.out.println("Error did not find file");
			e.printStackTrace();
		}
		
		int num=0;
		while(inputStream.hasNextLine()){
			lines[num] = inputStream.nextLine();
		
			num++;
		}
		
		int sum =0;
		String space=" ";
		for(int i=0;i<count;i++){
			
			for (int j=0;j<lines[i].length()-1;j++){
				
				if(lines[i].charAt(j)==space.charAt(0)){
					char number=lines[i].charAt(j+1);
					if(Character.isDigit(number)){
						lines[i].indexOf(j)= 'X';
					}
					//if((number<='0')||(number>='1')){
						//lines[i].
						
					//}
					
					
				}
						
						
			
			
			}
			
			
		}
		
		
		for(int i=0;i<count;i++){
			System.out.println(lines[i]);
			
		}
	
	
	
	}

}
