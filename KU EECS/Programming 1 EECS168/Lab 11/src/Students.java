import java.util.Scanner;

public class Students {

	private int id;
	private String name;

	public String getName() {
		return name;
	}

	public int getId() {
		return id;
	}

	public void setName() {

	}

	public void setId() {

	}

	public void readInput() {
		Scanner input = new Scanner(System.in);

		System.out.print("Enter students's name and ID number: ");
		name = input.next();
		id = input.nextInt();

	}

}
