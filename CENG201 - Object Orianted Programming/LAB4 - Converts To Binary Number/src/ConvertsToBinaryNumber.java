import java.util.*;

public class ConvertsToBinaryNumber {
	
	public static Scanner input;

	public static void main (String[] args) {
		
		input = new Scanner(System.in); // create scanner object
		
		// given number to converts binary number
		int number;
		System.out.print("Enter a number: ");
		number = input.nextInt();
		
		// this function prints binary number 
		ConvertToBinaryNumber(number);
		
		// this function prints all combinations of number (1-10) except same number (1-1,2-2..)
		PrintsAllCombinationsOfNumber();
	}
	
	// this function prints binary number
	public static void ConvertToBinaryNumber (int number) {
		
		int[] binaryNumber = {0,0,0,0,0,0,0,0}; // array for keep remainder
		int quotient = number;
		int remainder = 0;
		
		// make a division and add remainder to binaryNumber array
		for (int index = 7; quotient != 0; index--) {
			
			remainder = quotient % 2;
			quotient = quotient / 2;
			
			binaryNumber[index] = remainder;
		}
		
		// prints binary numbers 
		System.out.print(number + " to binary form is ");
		for (int x = 0; x < binaryNumber.length; x++) {
			
			System.out.print(binaryNumber[x]);
		}
	}
	
	// this function prints all combinations of number (1-10) except same number (1-1,2-2..)
	public static void PrintsAllCombinationsOfNumber () {
		
		System.out.println("\n");
		
		for (int x = 1; x < 10; x++) {
			
			for (int y = 1; y < 10; y++) {
				
				// prints combinations except same number (1-1,2-2,3-3..)
				if (x != y) {
					
					System.out.println(x + " " + y);
				}
			}
			
			System.out.println("");
		}
	}
}
