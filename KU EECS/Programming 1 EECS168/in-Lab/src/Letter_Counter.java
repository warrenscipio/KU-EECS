import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;



public class Letter_Counter {
	public static void main(String[] args){
		
		String[] lines;
		String find;
		int count=0;
		char[] charArray = new char[58];
		int[] numberArray = new int[26];
		
		
		
		Scanner input = new Scanner(System.in);
		
		System.out.println("Enter the name of the file.");
		find = input.nextLine();
		
		String fileName = find;
		
		Scanner inputStream =null;
		
		try {
			inputStream = new Scanner(new File(fileName));
		} catch (FileNotFoundException e) {
			
			System.out.println("Error finding the file");
			e.printStackTrace();
		}
		
		while(inputStream.hasNextLine()){
			String line = inputStream.nextLine();
			//System.out.println(line);
		count++;
		}
		
		lines = new String[count];
		
		try {
			inputStream = new Scanner(new File(fileName));
		} catch (FileNotFoundException e) {
			
			System.out.println("Error finding the file");
			e.printStackTrace();
		}
		
		int num=0;
		while(inputStream.hasNextLine()){
			
			lines[num] = inputStream.nextLine();
			
			num++;
			}
		
		inputStream.close();
		
		for (int i=0;i<58;i++){
			charArray[i]=(char) ('A'+i);
			
		}
		
		for (int i=0;i<26;i++){
			numberArray[i]=0;
			
		}
		
		for (int i=0;i<count;i++){
			
			for (int j=0; j<lines[i].length();j++){
			
				for(int k=0; k<26;k++){
				while((lines[i].charAt(j)==charArray[k])||(lines[i].charAt(j)==charArray[k+32])){
					numberArray[k]++;
					break;
				}
					
			
				}
			}
			
		}
		
		
		
		

		for (int i=0;i<26;i++){
		
			System.out.println(charArray[i]+": " + numberArray[i]);
			
		}
		
		
		String newFile;
		PrintWriter outputStream = null;
		System.out.println();
		System.out.println("Enter the name of the file you want to create.");
		newFile = input.nextLine();
		
		
		try {
			outputStream = new PrintWriter(newFile);
		} catch (FileNotFoundException e) {
			
			System.out.println("Error making file the file");
			e.printStackTrace();
		}
		outputStream.println("The file contains the following letters:");
		for (int i=0;i<26;i++){
			
			outputStream.println(charArray[i]+": " + numberArray[i]);
			
		}
		outputStream.close();
		System.out.println("Those files were written to " + newFile);
		
		
		
		
		
	}

}
