import java.util.Scanner;

public class Basketball {
	
	private String opponent;
	private String team;
	private int points=0;
	private int tScore=0;
	private int oScore=0;
	private String scorer;
	
	
	
	public void input(){
		Scanner input = new Scanner(System.in);
		System.out.println("Welcome Basketball Fans!!");
		System.out.println("");
		
		System.out.print("Enter a team: ");
		team = input.next();
		System.out.print("Enter their opponent: ");
		opponent = input.next();
		
	}
	
	
	
	public void setTscore (int newPoints){
		tScore += newPoints;
		
		
	}
	
	public void setOscore (int newOpoints){
		oScore += newOpoints;
		
		
	}
	
	
	public void update(){
		Scanner input = new Scanner(System.in);
		
		
		
		
		
		
	
		
		System.out.println(team+" "+tScore+", "+opponent+" "+oScore);
		
		if(tScore > oScore)
		System.out.println("The " + team + "are winning!");
		
		if(tScore < oScore)
		System.out.println("The " + opponent + "are winning!");
		
		if(tScore == oScore)
		System.out.println("It is a tie right now!");
		
		
		
		
	
	
	}
	
	
	
	
	
	public String getOpponent(){
		return opponent;
	}
	
	public String getTeam(){
		
		return team;	
	}
	
	public int getPoints(){
		
		return points;
	}
	
	

}
