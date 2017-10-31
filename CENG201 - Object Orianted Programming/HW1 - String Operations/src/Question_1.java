import java.util.*;

public class Question_1 {
	
	private static Scanner input;

	public static void main (String[] args) {
		
		input = new Scanner(System.in); // create input object
		
		String[] inputString = new String[2];
		char[][][] inputStringSituations = new char[][][] { { {'a','b','c','d','e'} , {'0','0','0','0','0'} },
															{ {'a','b','c','d','e'} , {'0','0','0','0','0'} } };
		
															
		inputStringSituations[0][0][0] = input.nextLine().charAt(0);													
															
		System.out.print("Enter first string: ");
		inputString[0] = input.nextLine();
		
		System.out.print("Enter second string: ");
		inputString[1] = input.nextLine();
		
		char ch;
		
		for (int x = 0; x < inputString.length; x++) {
			
			for (int index = 0; index < inputString[0].length(); index++) {
				
				ch = inputString[x].charAt(index);
				
				for (int z = 0; z < inputStringSituations[0][0].length; z++) {
					
					if (ch == inputStringSituations[x][0][z]) {
						
						inputStringSituations[x][1][z]++;
						break;
					}
				}
			}
		}
		
		// her kelime için harfler alýndý, formul uygulanacak sadece.
		
		
		
		
		
		System.out.print(inputStringSituations[0][0][0]);
		System.out.println(inputStringSituations[0][1][0]);
		
		System.out.print(inputStringSituations[0][0][1]);
		System.out.println(inputStringSituations[0][1][1]);
		
		System.out.print(inputStringSituations[0][0][2]);
		System.out.println(inputStringSituations[0][1][2]);
		
		System.out.print(inputStringSituations[0][0][3]);
		System.out.println(inputStringSituations[0][1][3]);
		
		System.out.print(inputStringSituations[0][0][4]);
		System.out.println(inputStringSituations[0][1][4]);
		
		
		
		
		
		
		
		
		
		
		
		
		/*
		String firstString; // first string that given from user
		String secondString; // second string that given from user
		
		System.out.print("Enter first string: ");
		firstString = input.nextLine();
		
		System.out.print("Enter second string: ");
		secondString = input.nextLine();
				
		char[][] firstStringSituation = new char[][] { {'a','b','c','d','e'} , {'0'} };
		char[][] secondStringSituation = new char[][] { {'a','b','c','d','e'} , {'0'} };		
		char ch;
		
		for (int x = 0; x < firstString.length(); x++) {
			
			ch = firstString.charAt(x);
			
			for (int y = 0; y < firstStringSituation[0].length; y++) {
				
				if (ch == firstStringSituation[0][y]) {
					
					firstStringSituation[0][y]++;
				}
			}
		}
		
		for (int x = 0; x < secondString.length(); x++) {
			
			ch = secondString.charAt(x);
			
			for (int y = 0; y < secondStringSituation[0].length; y++) {
				
				if (ch == secondStringSituation[0][y]) {
					
					secondStringSituation[0][y]++;
				}
			}
		}
			*/
		
	}
}
