
import java.text.Collator;
import java.util.Scanner;

public class SortStudent {

	public static void main(String[] args) {
		int numOfStu;

		Students[] student;

		Students sort = new Students();
		Scanner input = new Scanner(System.in);

		// add your code here

		System.out.println("Enter the number of Students:");
		numOfStu = input.nextInt();

		student = new Students[numOfStu];

		for (int i = 0; i < numOfStu; i++) {
			student[i] = new Students();
			student[i].readInput();

		}

		System.out.println();

		System.out.println("*Sort by name:");
		bubbleSort(student, 1);
		// output sorted array
		for (int i = 0; i < student.length; i++) {
			System.out.println(student[i].getId() + " " + student[i].getName());
		}

		System.out.println();

		System.out.println("*Sort by id:");
		bubbleSort(student, 0);
		// output sorted array
		for (int i = 0; i < student.length; i++) {
			System.out.println(student[i].getId() + " " + student[i].getName());
		}

	}

	public static void bubbleSort(Students[] arrb, int sortType) {

		Collator myCollator = Collator.getInstance();
		boolean comp_a;
		boolean swapped = true;
		Students temp = null;

		int k = 0;

		if (sortType == 1) {

			while (swapped) {
				swapped = false;
				k++;

				for (int j = 0; j < arrb.length - k; j++) {
					comp_a = myCollator.compare(arrb[j].getName(),
							arrb[j + 1].getName()) > 0;
					if (comp_a) {
						temp = arrb[j];
						arrb[j] = arrb[j + 1];
						arrb[j + 1] = temp;
						swapped = true;
					}
				}

			}

		} else {

			swapped = true;
			int j = 0;

			while (swapped) {
				swapped = false;
				j++;

				// Compare the first and the second and so on...
				for (int i = 0; i < arrb.length - j; i++) {

					if (arrb[i].getId() > arrb[i + 1].getId()) {
						temp = arrb[i];
						arrb[i] = arrb[i + 1];
						arrb[i + 1] = temp;

						swapped = true;
					}
				}
			}

		}

	}
}
	
	
	
	
	
	

