/*
 * This program gets two strings from user and calculate
 * similarity between strings according to some formulas.
 *
 * @author	Huseyin Eren Guler
 * @since	2017-11-06
 */

import java.util.Scanner;

public class Question_1 {
	
	private static Scanner input;

	public static void main (String[] args) {
		
		input = new Scanner(System.in); // input object
		
		// this array keeps requirement characters for the input strings
		char[] requirements = {'a', 'b', 'c', 'd', 'e'};
		
		// this variable keeps the number of strings to gets from the user
		int totalStrings = 2;
		
		// this array keeps the strings that are gets from the user
		String[] inputString = getString(totalStrings, requirements);
		
		// this 3-dimensional array keeps input strings in first dimension, requirements in second dimension and the number of letters in third dimension.
		char[][][] inputStringSituations = determineStringSituations(inputString, requirements);
		
		/* 
		 * FORMULA;
		 * 									number of distinct letters in common
		 * 			  __________________________________________________________________________________
		 * 				(number of distinct letters in FIRST) + (number of distinct letters in SECOND)
		 *  										  _________________
		 *  												  2
		 */
		String commonLetters = findCommonLetters(inputStringSituations); // number of distinct letters in common
		String distinctLettersInFýrst = findDistinctLetters(inputString[0]); // number of distinct letters in first string
		String distinctLettersInSecond = findDistinctLetters(inputString[1]); // number of distinct letters in second string
		
		 // calculates the formula then keeps result in result variable
		double result = (commonLetters.length() / ((distinctLettersInFýrst.length() + distinctLettersInSecond.length()) / 2.0));
				
		System.out.printf("Result: %.2f", result);
	}
	
	// this function gets strings from user and return array of those strings
	public static String[] getString (int totalStrings, char[] requirements) {
		
		// this array keeps the strings that are gets from the user
		String[] inputString = new String[totalStrings];
		
		String str;
		for (int x = 0; x < totalStrings; x++) {
			
			System.out.print("Enter " + (x+1) + ". string: ");
			
			// gets a lower case string 
			str = input.nextLine().toLowerCase();
			
			// if the string that gets from the user meets the requirements, we accept this string
			if (controlLetters(str, requirements)) {
				inputString[x] = str;
			}
			
			// else display error message and decrease x to gets string again
			else {
				controlLettersErrorMessage(requirements);
				x--;
			}
		}
		
		return inputString;
	}
	
	// this function determines the string situation according to requirements, then return those situations in 3d array
	public static char[][][] determineStringSituations (String[] inputString, char[] requirements) {
		
		//										FIRST: CREATE AN ARRAY FOR THE SITUATIONS
		
		/* this array keeps string in first dimension, letters in second dimension
		 * and letters numbers in third dimension.
		 * Example: requirements = a,b,c,d,e
		 * 			JavaTest -> (a,2)(b,0)(c,0)(d,0)(e,1) 
		 */
		char[][][] inputStringSituations = new char[inputString.length][requirements.length][requirements.length];
		
		// loop for the determine situations every string
		for (int x = 0; x < inputString.length; x++) {
			
			// loop for the determine requirements every string
			for (int z = 0; z < requirements.length; z++) {
				
				inputStringSituations[x][0][z] = requirements[z]; // copy requirements to second dimension
				inputStringSituations[x][1][z] = '0'; // in first, all data is 0 in third dimension
			}
		}
		
		//										SECOND: EDIT ARRAY ACCORDING TO REQUIREMENTS
		
		char ch; // keep characters in the string
		
		// loop for the determine all string situations 
		for (int x = 0; x < inputString.length; x++) {
			
			// loop for the processing every character in the string
			for (int index = 0; index < inputString[x].length(); index++) {
				
				ch = inputString[x].charAt(index); // assign a character from input string according to index number 
				
				// loop for the compare a character and situations and if exists increment its numbers
				for (int z = 0; z < inputStringSituations[0][0].length; z++) {
					
					// if the character matches, the number of that characters increases
					if (ch == inputStringSituations[x][0][z]) {
						
						inputStringSituations[x][1][z]++; // increment process
						break;
					}
				}
			}
		}
		
		return inputStringSituations;
	}
	
	// this function returns true if a word that entered meets the requirements, OR it does not, returns false
	public static boolean controlLetters (String word, char[] requirements) {
		
		boolean control = false;
		
		// loop for the compare every letters in string
		for (int x = 0; x < word.length(); x++) {
			
			control = false;
			
			// loop for the compare every requirements and a letter, respectively
			for (int y = 0; y < requirements.length; y++) {
				
				// if a letter meets the requirements, control is true and next to compare other letter in string
				if (word.charAt(x) == requirements[y]) {
					control = true;
					break;
				}
				
			}
			
			// if control is false, this means word that entered does not meets the requirements
			if (control == false) {
				return false;
			}
		}
		
		return true;
	}
	
	// if a word that entered does not meets the requirements, this function will call and display error message
	public static void controlLettersErrorMessage (char[] requirements) {
		
		System.out.print("ERROR!! Please use only \"");
		
		for (char ch: requirements) {
			
			System.out.print(" " + ch);
		}
		
		System.out.println(" \"\n");
	}
	
	// this function find common letters in all strings then return those common letters in a string
	public static String findCommonLetters (char[][][] inputStringSituations) {
		
		String commonLetters = "";
		
		for (int x = 0; x < inputStringSituations.length-1; x++) {
			
			for (int z = 0; z < inputStringSituations[0][1].length; z++) {
				
				if (inputStringSituations[x][1][z] > '0') {
					
					if (inputStringSituations[x+1][1][z] > '0') {
						
						commonLetters += inputStringSituations[x][0][z];
					}
				}
			}
		}
		
		return commonLetters;
	}
	
	// this function find and return number of distinct letters in a word
	public static String findDistinctLetters (String word) {
		
		String distinctLetters = "" + word.charAt(0); // add first character in word
		boolean control = false;
		
		for (int x = 1; x < word.length(); x++) {
			
			control = false;
			
			for (int y = 0; y < distinctLetters.length(); y++) {
				
				if (word.charAt(x) == distinctLetters.charAt(y)) {
					control = true;
				}
			}
			
			if (control == false) {
				distinctLetters += word.charAt(x);
			}
		}
		
		return distinctLetters;
	}

}
