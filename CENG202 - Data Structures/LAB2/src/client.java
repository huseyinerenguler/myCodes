import java.util.Arrays;

public class client {

	public static void main (String[] args) {
		
		int[] numbers = new int[5000];
	
		for (int x = 0; x < numbers.length; x++) {
			numbers[x] = x;
		}
		
		int value = 4000, resultIndex;
		long initialTime, finishTime;
		
		// ********** BAD ALGORITHM **********
		shuffleArray(numbers);
		initialTime = System.nanoTime();
		resultIndex = badAlgorithm(numbers, value);
		finishTime = System.nanoTime();
		
		System.out.println("BAD Algorithm Calculation Time: " + (finishTime - initialTime) + " nanoSeconds");
		if (resultIndex == -1) {
			System.out.println(value + " cannot be found!");}
		else {
			System.out.println(value + " was found in " + resultIndex + ". index of array.");}
		// ***********************************
		
		// ********* GOOD ALGORITHM **********
		Arrays.sort(numbers);
		initialTime = System.nanoTime();
		resultIndex = goodAlgorithm(numbers, value);
		finishTime = System.nanoTime();
		
		System.out.println("GOOD Algorithm Calculation Time: " + (finishTime - initialTime) + " nanoSeconds");
		if (resultIndex == -1) {
			System.out.println(value + " cannot be found!");}
		else {
			System.out.println(value + " was found in " + resultIndex + ". index of array.");}
		// ***********************************
		
	}
	
	public static int badAlgorithm (int[] arr, int value) {
		
		for (int index = 0; index < arr.length; index++) {
			
			if (arr[index] == value) {
				return index;
			}
		}
		
		return -1;
	}
	
	public static int goodAlgorithm (int[] arr, int value) {
		
		int firstIndex = 0;
		int lastIndex = arr.length - 1;
		int tempIndex;
		
		while (true) {
			
			tempIndex = (firstIndex + lastIndex) / 2;
			
			if (arr[tempIndex] < value) {
				firstIndex = tempIndex + 1;
			}
			else if (arr[tempIndex] > value) {
				lastIndex = tempIndex;
			}
			else {
				return tempIndex;
			}
		}
	}
	
	public static void shuffleArray (int[] arr) {
		
		int randomIndex1;
		int randomIndex2;
		int tempNumber;
		
		for (int index = 0; index < (arr.length*arr.length); index++) {
			
			randomIndex1 = (int)(Math.random() * arr.length);
			randomIndex2 = (int)(Math.random() * arr.length);
		
			tempNumber = arr[randomIndex1];
			arr[randomIndex1] = arr[randomIndex2];
			arr[randomIndex2] = tempNumber;
		}
	}
}
