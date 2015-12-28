/*----------------------------
 * KUStudentTest.java
 * Warren Scipio
 * EECS - 168 Lab 7
 * calls methods from KUStudent to output kuinfo
 * 10/16/2012
 */

import java.util.Scanner;


public class KUStudentTest {
	
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		KUStudent myInfo = new KUStudent();
		Scanner input= new Scanner(System.in);
		
		
	
		
//asks for user input
		System.out.println("Please input the student's name (firstname lastname)");
		
	
		//breaks first name and last name apart
		String fname = input.next();
		String lname = input.next();
		//asks for user input		
          System.out.println("Please input the student's KUID and department:");
           //breaks up department and kuid
           String kuid = input.next();
           String dpt = input.next();
           
               
                //sets Stud_name and Stud_kuinfo
                myInfo.setStud_name(fname, lname);
                myInfo.setStud_kuinfo(kuid, dpt);
                
                // calls writeOutput
                myInfo.writeOutput();
        
                
                
                
	         
 
	
	}
	

}
