import java.util.*;

public class StringOperations {
	
	private static Scanner input;
	
	public static void main(String[] args) {
		
		input = new Scanner(System.in); // scanner object
		
		// give a string from user
		System.out.print("Please enter a string: ");
		String letter = input.nextLine();
		
		// give a index number for change character in this index
		System.out.print("Please enter a index number: ");
		int index = input.nextInt();
		
		// if index number is valid for string
		if (index < letter.length()) {
			
			char ch = letter.charAt(index); // keep character in index number
			
			// if character is lower case, change to upper case
			if (Character.isLowerCase(ch)) {
				
				ch = Character.toUpperCase(ch);
			}
			
			// else character is upper case, change to lower case
			else {
				
				ch = Character.toLowerCase(ch);
			}
			
			// edit and print new string
			letter = letter.substring(0, index) + ch + letter.substring(index+1, letter.length());
			
			System.out.println("Output: " + letter);
		}
		
		// else index number is invalid for string, print error message
		else {
			
			System.out.println("ERROR!! Number that you entered is bigger than string that you entered length.");
		}
	}
}
