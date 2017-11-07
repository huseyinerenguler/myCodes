/*
 * @author	Huseyin Eren Guler
 * @since	2017-11-06
 */

import java.util.Scanner;

public class Question_3 {

	private static Scanner input;
	
	public static void main (String[] args) {
	
		input = new Scanner(System.in);
		
		// gets input like a string from the user 
		String inputString;
		System.out.print("Enter some integers: ");
		inputString = input.nextLine();
		
		// initialize an array that keeps every word in a string according to space character
		String[] letters = inputString.split(" ");
		
		// if try block has an error, catch block will be executed and display error message
		try {
			int countNumber = 0;
			int totalNumber = 0;
			
			// loop for the transform every number that type is string to integer
			for (int x = 0; x < letters.length; x++) {
				
				// if user entered zero, next entries will not be evaluated
				if (Integer.parseInt(letters[x]) == 0) {
					break;
				}
				
				// calculate total number and increase count of number
				totalNumber += Integer.parseInt(letters[x]);
				countNumber++;				
			}
			
			System.out.println("The total is: " + totalNumber);
			System.out.printf("The average is: %.2f", (double)totalNumber / countNumber);
		
		} 
		catch (NumberFormatException e) {
			
			System.out.print("Please enter numbers only.");
		}
	}
}
