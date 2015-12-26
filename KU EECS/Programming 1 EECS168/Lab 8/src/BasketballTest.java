import java.util.Scanner;

public class BasketballTest {
	
	public static void main(String[] args){
		
		Basketball game = new Basketball();

		String scorer;
		int points=0;
		
		
		
		game.input();
		
		
	do{	
		System.out.println("Enter a score: ");
	
		Scanner input = new Scanner(System.in);

		scorer = input.next();
		points = input.nextInt();	
		
		
		
		while((scorer.compareTo(game.getOpponent()) != 0) && ((scorer.compareTo(game.getTeam()) != 0))){
			System.out.println("Choose a team that is playing");
			
			System.out.println(game.getTeam() + " or " + game.getOpponent());
			
			
			scorer = input.next();
			points = input.nextInt();
			
			
			if((scorer.compareTo(game.getOpponent()) != 0))
				game.setOscore(points);
				
			if ((scorer.compareTo(game.getTeam()) != 0))
				game.setTscore(points);
			
			
		}
	
		game.update();
		
	}while (points<=10);
		
	}

}
