/*----------------------------
 * KUStudent.java
 * Warren Scipio
 * EECS - 168 Lab 7
 * sends methods to KUStudentTest
 * 10/16/2012
 */


public class KUStudent {

    String stud_fname;
    String stud_lname;
    String stud_kuid;
    String stud_dpt;
	
       
    public  void setStud_name(String fname, String lname){ // Set student's name.
        stud_fname = fname;
        stud_lname = lname;
    	
    }
   
    public void setStud_kuinfo(String kuid, String dpt){
         stud_kuid = kuid;
         stud_dpt = dpt;
        
    }
       
    
	// output format
    public void writeOutput(){
    	
    	System.out.println("Student: " +  stud_fname + stud_lname);
        System.out.println("KUID:" + stud_kuid);
        System.out.println("Department: " + stud_dpt);
    	
    }
    
	
}
