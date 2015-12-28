

public class LineEditor {

	//Declaring variables
	private int letters;
	private String phrase0;
    private char[] stringSet;
    private char[] stringNew;
    
	
	
    // when called takes a string
    public void setLetters(String phrase){	
		phrase0 = phrase;
		letters = phrase.length();
	 // that string is now set to phrase0(a private variable of this class) and letters(a private variable of this class) equal to the length 
	}
   
	// takes an int and a string
	public void setStringLength(int newLetters,String phrase){
		
		stringSet = new char[newLetters];
		//sets array to chars in string phrase0
		for ( int i=0; i<newLetters; i++){
           stringSet[i] = phrase0.charAt(i);
         }
		//stringSet array is now equal to string phrase0
	}
	//returns variable letters
	public int getCharCount(){
		return letters;
	}
	//returns length of array	
	public int getStringLength(){
		
		return stringSet.length;
	}
	
	//call to return piece of array
	public char getArray(int n){	
		return stringSet [n];
	}
	//return phrase0
	public String getPhrase(){
			return phrase0;
	}
	//return inserting string length
	public int getInsertLength(String insert){
	return insert.length();
	}
	//takes inserting string
	public void stepBack(String insert){
	letters = letters -insert.length();
	//letters is taken a step back in the insert method
	}
	

	
	//takes int for starting position and string to insert
	public void insert_text(int s, String insert){
		
		//makes letters add in the extra chars from the insert string
		letters = insert.length() + letters;
		
		//if statement to stop insert method if letters plus the chars from the insert string are greater than 100
		if (letters>100){
		// if not greater than 100 than continue on with insert method
		}else{
		//sets chars from insert variable to its own array
		stringNew = new char[insert.length()];
		for ( int i=0; i<insert.length(); i++)
           stringNew[i] = insert.charAt(i);
		
		//re-create stringSet array with new letters value
		stringSet = new char[letters];
		//loop to sync new stringSet array to new chars
		for ( int i=0; i<letters; i++){
         
			//if i equals starting position(s-1) than start inserting new chars
			if (i==(s-1)){
				//loop to sync stringSet array to the array that holds inserting chars
				for (int j=0;j<insert.length(); j++) {
					stringSet[i]=stringNew[j]; 
					i+=1;//i still increases by one inside inner for loop so when it exits i will be in the right spot
				}
				//for loop that kicks in after new chars are inserted to complete the old string 
				for ( ; i<letters; i++)
					stringSet[i] = phrase0.charAt(i-(insert.length()));
					
					phrase0 = new String(stringSet);
					// break to break out of the for loop to sync stringSet to new chars 
					break;
			}
          
			//if i is not equal to starting position(s-1) then keep assigning stringSet to its old chars
			stringSet[i] = phrase0.charAt(i);
		}
		}	
		
		
	}
	//takes starting position(s) and ending position(e)
	public void delete_text(int s, int e){
		
		 
		stringNew = new char[letters-e];
		//variable to see how many chars are left 
		int left = letters - ((e-s)+1);
		if (left<=0)
			letters=0;
		//creating array for chars left
		stringSet = new char[left];
		//for loop setting stringSet equal to old chars minus
		for ( int i=0; i<left; i++){
			
			//if i equals start position(s-1)  
			if(i == (s-1)){
			//for loop setting stringNew to to anything left in phrase0 after end position
			for ( int j=0; j<(letters-e); j++){
				stringNew[j]=phrase0.charAt(e+j);
				stringSet[i]= stringNew[j];
				i++;
			 }
			//letters needs to equal left for deleting again
			letters = left;
			//set phrase0 to stringSet for other tasks
			phrase0 = new String(stringSet);
			break;
		}
		// enter values for stringSet until user reaches start position
		stringSet[i] = phrase0.charAt(i);
		
		}	
		
	}
	//takes starting position and ending position and a string to insert
	public void replace_text(int s, int e, String i){
		//calls delete method
		delete_text(s,e);
		//calls insert method
		insert_text(s,i);
	// deletes the text and then inserts the string			
	}
}