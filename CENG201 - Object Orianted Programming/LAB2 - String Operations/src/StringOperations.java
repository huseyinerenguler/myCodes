import java.util.*;

public class StringOperations {
	
	private static Scanner input;
	
	public static void main(String[] args) {
		
		input = new Scanner(System.in);
		
		System.out.print("Please enter a string: ");
		String letter = input.nextLine();
		
		System.out.print("Please enter a index number: ");
		int index = input.nextInt();
		
		if (index < letter.length()) {
			
			char ch = letter.charAt(index);
			
			if (Character.isLowerCase(ch)) {
				
				ch = Character.toUpperCase(ch);
			}
			else {
				
				ch = Character.toLowerCase(ch);
			}
			
			letter = letter.substring(0, index) + ch + letter.substring(index+1, letter.length());
			
			System.out.println("Output: " + letter);
		}
		else {
			
			System.out.println("ERROR!! Number that you entered is bigger than string that you entered length.");
		}
		
	}

}
