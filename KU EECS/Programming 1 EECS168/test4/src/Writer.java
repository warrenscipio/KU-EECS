
import java.io.FileNotFoundException;
import java.io.File;
import java.util.Scanner;
import java.io.PrintWriter;


public class Writer {
	public static void main(String[]args){
		String[] lines;
		String find;
		int count =0;
		Scanner input = new Scanner(System.in);
		System.out.println("enter the file you want to read.");
		find = input.nextLine();
		
		String fileName = "goread.txt";
		PrintWriter inputStream = null;
		
			try {
				inputStream = new PrintWriter(fileName);
			} catch (FileNotFoundException e) {
				
				System.out.println("Error did not find file");
				e.printStackTrace();
			}
			
	System.out.println("enter 3 lines");
	
	for (int i =1;i<=3;i++){
		String line=input.nextLine();
		inputStream.println(i + " " + line);
		
	}
	inputStream.close();
	
	System.out.println("yay");
	}

}
