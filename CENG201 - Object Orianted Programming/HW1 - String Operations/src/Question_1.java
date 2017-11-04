import java.util.*;

public class Question_1 {
	
	private static Scanner input;

	public static void main (String[] args) {
		
		input = new Scanner(System.in); // input object
		
		char[] requirements = {'a', 'b', 'c', 'd', 'e'};
		int totalStrings = 2;
		String[] inputString = new String[totalStrings];
		
		String str;
		for (int x = 0; x < totalStrings; x++) {
			
			System.out.print("Enter " + (x+1) + ". string: ");
			
			str = input.nextLine().toLowerCase();
			
			if (controlLetters(str, requirements)) {
				inputString[x] = str;
			}
			
			else {
				x--;
			}
		}
		
		char[][][] inputStringSituations = determineStringSituations(inputString, requirements);
		
		/* FORMULA IS,
		 * 									number of distinct letters in common
		 * 			  __________________________________________________________________________________
		 * 				(number of distinct letters in FIRST) + (number of distinct letters in SECOND)
		 *  										  _________________
		 *  												  2
		 */
		String commonLetters = findCommonLetters(inputStringSituations);
		String distinctLettersInFýrst = findDistinctLetters(inputString[0]);
		String distinctLettersInSecond = findDistinctLetters(inputString[1]);
		
		double result = (commonLetters.length() / ((distinctLettersInFýrst.length() + distinctLettersInSecond.length()) / 2.0));
				
		System.out.printf("Result: %.2f", result);
	}
	
	public static char[][][] determineStringSituations (String[] inputString, char[] requirements) {
		
		/* this array keeps string in first dimension, letters in second dimension
		 * and letters numbers in third dimension.
		 *  Example: JavaTest -> (a,2)(b,0)(c,0)(d,0)(e,1) */
		char[][][] inputStringSituations = new char[inputString.length][requirements.length][requirements.length];
		
		for (int x = 0; x < inputString.length; x++) {
			
			for (int z = 0; z < requirements.length; z++) {
				
				inputStringSituations[x][0][z] = requirements[z];
				inputStringSituations[x][1][z] = '0';
			}
		}
													
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
		
		for (int x = 0; x < word.length(); x++) {
			
			control = false;
			
			for (int y = 0; y < requirements.length; y++) {
				
				if (word.charAt(x) == requirements[y]) {
					
					control = true;
					break;
				}
				
			}
			
			if (control == false) {
				
				controlLettersErrorMessage(requirements);
				return false;
			}
		}
		
		return true;
	}
	
	public static void controlLettersErrorMessage (char[] requirements) {
		
		System.out.print("ERROR!! Please use only \"");
		
		for (char ch: requirements) {
			
			System.out.print(" " + ch);
		}
		
		System.out.println(" \"\n");
	}
	
	public static String findCommonLetters (char[][][] inputStringSituations) {
		
		String commonLetters = "";
		
		for (int x = 0; x < 1; x++) {
			
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
	
	public static String findDistinctLetters (String word) {
		
		String distinctLetters = "" + word.charAt(0);
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
