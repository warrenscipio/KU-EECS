import java.util.Random;

public class SelectionSortTest {
	public static void main(String[] agrs) {

		int number = 0;
		Random random;
		random = new Random();
		int[] numberSet = new int[10];

		for (int i = 0; i < 10; i++) {

			number = random.nextInt(100);
			numberSet[i] = number;

		}

		System.out.println("* Generating 10 random integers in range (0,100):");

		for (int i = 0; i < 10; i++)
			System.out.print(numberSet[i] + " ");
		System.out.println();
		System.out.println("* Sorted numbers:");

		selectionSort(numberSet);
		System.out.println("Done.");

	}

	public static void selectionSort(int[] arr) {

		int minIndex, tmp;
		int length = arr.length;

		for (int i = 0; i < length - 1; i++) {
			minIndex = i;

			for (int j = i + 1; j < length; j++) {
				if (arr[j] < arr[minIndex])
					minIndex = j;
			}
			if (minIndex != i) {
				// swap two values
				tmp = arr[i];
				arr[i] = arr[minIndex];
				arr[minIndex] = tmp;

			}

			System.out.print("round " + (i + 1) + ": ");

			for (int k = 0; k < length; k++)
				System.out.print(arr[k] + " ");
			System.out.println();
		}

	}

}
