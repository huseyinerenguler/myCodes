
public class RadixSortAlgorithm {

	public static void main (String[] args) {
		
		int lowestNumber = 0;
		int biggestNumber = 100000;
		int howMany = 256;
		
		int[] arr = new int[howMany];
		
		generateRandomNumber(arr, lowestNumber, biggestNumber, howMany);
		
		// Before Sorting
		System.out.print("Before sorting: ");
		for (int num : arr) {
			
			System.out.print(num + " ");
		}
		
		long startTime = System.currentTimeMillis();
		Radix_Sort(arr);
		long endTime = System.currentTimeMillis();
		
		
		// After Sorting
		System.out.print("\nAfter sorting: ");	
		for (int num : arr) {
				
			System.out.print(num + " ");
		}
		
		// Calculating time
		System.out.println("\nRadix Sort Calculating Time: " + (endTime - startTime) + " milliseconds..");
		
	}
	
	public static void generateRandomNumber (int[] arr, int lowestNumber, int biggestNumber, int howMany) {
		
		for (int x = 0; x < howMany; x++) {
			
			arr[x] = lowestNumber + (int)(Math.random() * biggestNumber);
		}
	}
	
	public static void Radix_Sort (int[] arr) {
		
		int temp;
		
		for (int z = 1; z <= 1000000; z*=10) {
			
			for (int y = 0; y < arr.length; y++) {
				
				for (int x = 0; x < arr.length - 1; x++) {
					
					if ( ((arr[x] / z) % 10) > ((arr[x+1] / z) % 10) ) {
						
						temp = arr[x];
						arr[x] = arr[x+1];
						arr[x+1] = temp;
					}
				}
			}
		}	
	}
	
}
