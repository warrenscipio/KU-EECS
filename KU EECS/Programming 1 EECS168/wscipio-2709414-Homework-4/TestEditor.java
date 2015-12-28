import java.util.Scanner;


public class TestEditor {
	
	
	
	
	public static void main(String[] args){
	//creating object for LineEditor
		LineEditor lineEditor = new LineEditor();
		
		//declaring variables
		int choice;
		int start;
		int end;
		String inserting;
		String phrase;
		
		System.out.println("+++++++ LineEditor starts... +++++++");
		System.out.println();
		
		Scanner input = new Scanner(System.in); 
		System.out.println("* Write the text you want (maximum lengeth: 100):");
		phrase = input.nextLine();
		
		//setting letters and phrase0 to phrase
		lineEditor.setLetters(phrase);
		lineEditor.setStringLength(phrase.length(),phrase);
		
		//loop to stop user from starting with more than 100 chars
		  while((lineEditor.getStringLength() > 100) ){
		System.out.println("* Operation failed: You exceeded the maximum length.");
		System.out.println("* Write the text you want (maximum lengeth: 100):");
		phrase = input.nextLine();
		// calling method to set phrase equal to phrase0 and set letters variable
		lineEditor.setLetters(phrase);
		lineEditor.setStringLength(phrase.length(),phrase);
		
		  }
		 
		 
		// to loop user back to menu after completing a task
		do{
		 //makes sure user inputs 1, 2, 3 or 4
		 do{
			 
			 //menu
			 System.out.println();
			 System.out.println("--------------------------------------");
			 //lets user know how many chars they have
			 System.out.println("(char count: "+ lineEditor.getCharCount()+")");
			 
			 System.out.println("Choose from the menu:");
			 System.out.println("1: Insert");
			 System.out.println("2: Delete");
			 System.out.println("3: Replace");
			 System.out.println("4: Quit");
			 //what user chooses
			 choice = input.nextInt();
			 //if user chooses 1 but chars are already equal to 100
			 if ((choice==1)&&(lineEditor.getStringLength()==100)){
				// takes user back to menu without option 1
				 do{ 
				
				 System.out.println();
				 System.out.println("--------------------------------------");
				 System.out.println("Choose from the menu:");
				 System.out.println("1: XXXXXX(You can not insert any more text, count is at 100) ");
				 System.out.println("2: Delete");
				 System.out.println("3: Replace");
				 System.out.println("4: Quit");
		 
				 choice = input.nextInt();
				 //loops while user picks 1
				}while(choice ==1);
				 
			 }
			 
			 //loops while user doesnt not choose 1, 2, 3 or 4
		 }while ((choice >4) || (choice < 1));
		 
		 //if user wants to insert
		 if (choice == 1){
			
			 System.out.println();
			 System.out.println("* Enter the starting position:");
			 start = input.nextInt();
			 input.nextLine();
			 System.out.println();
			 System.out.println("* Enter the text you want to insert:");
				inserting = input.nextLine();
				System.out.println();
			//calls insert_text method	
			 lineEditor.insert_text(start,inserting);
			 //loop to stop user from inserting text that would make original text over 100
			  while(lineEditor.getCharCount()>100){
				  
				  System.out.println("* Operation failed: You exceeded the maximum length.");
				  System.out.println("* Enter the text you want to insert: (not more than "+ (100-lineEditor.getStringLength())+")");
				  //calls step back method
				  lineEditor.stepBack(inserting);
					inserting = input.nextLine();
			 //calls insert_text method a second time	  
			 lineEditor.insert_text(start,inserting);
			 }
			  //prints the chars in the array 
			 for(int i=0; i<lineEditor.getStringLength(); i++)
					System.out.print(lineEditor.getArray(i) );
		 // if user chooses to delete
		 }else if( choice == 2){
			 System.out.println();
			 System.out.println("* Enter the starting and ending position for deletion.");
			 start = input.nextInt();
			 end = input.nextInt();
			 //calls Delete_text method
			 lineEditor.delete_text(start,end);
			 // prints chars that are left in the array
			 for(int i=0; i<lineEditor.getStringLength(); i++)
					System.out.print(lineEditor.getArray(i) );
		 // if user wants to replace text	 
		 }else if( choice == 3){
			 System.out.println();
			 System.out.println("* Enter the starting and ending position for replacing.");
			 start = input.nextInt();
			 end = input.nextInt();
			 input.nextLine();
			 System.out.println();
			 System.out.println("* Enter the text you want to insert:");
				inserting = input.nextLine();
				System.out.println();
			 // calls Replace_text method
			 lineEditor.replace_text(start,end,inserting);
			 //prints the chars in the array
			 for(int i=0; i<lineEditor.getStringLength(); i++)
					System.out.print(lineEditor.getArray(i) );
		// if user quits	 
		 }else{
			 System.out.println("Good-Bye!");
		 }
		
		// loops until user quits
		}while (choice !=4);
		
		
		
		
	}
		
}