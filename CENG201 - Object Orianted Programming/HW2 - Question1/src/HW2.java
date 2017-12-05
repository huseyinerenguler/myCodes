import java.util.*;

public class HW2 {

	static Scanner input = new Scanner(System.in);
	
	static int numberOfBooks = 0;
	static int numberOfPages = 0;
	static int numberOfWords = 5;
	
	public static void main (String[] args) {
		
		if (getInformationAboutBooks()) {
			
			String[][][] library = new String[numberOfBooks][numberOfPages][numberOfWords];
						
			fillPagesOfEachBooksWithRandomWords(library);
			
			displayBooksDetails(library);
			
			findSameWords(library);
		}	
	}
	
	public static boolean getInformationAboutBooks () {
		
		System.out.print("How many books do you have? : ");
		int _numberOfBooks = input.nextInt();
		
		if (_numberOfBooks < 1) {
			System.out.println("Number of books does not less than 1.");
			return false;
		}
		
		System.out.print("How many pages do they have? : ");
		int _numberOfPages = input.nextInt();
		
		if (_numberOfPages < 1) {
			System.out.println("Number of books does not less than 1.");
			return false;
		}
		
		numberOfBooks = _numberOfBooks;
		numberOfPages = _numberOfPages;
		return true;
	}
	
	public static void fillPagesOfEachBooksWithRandomWords (String[][][] library) {
		
		for (int bookIndex = 0; bookIndex < numberOfBooks; bookIndex++) {
			
			for (int pageIndex = 0; pageIndex < numberOfPages; pageIndex++) {
				
				for (int wordIndex = 0; wordIndex < numberOfWords; wordIndex++) {
					
					switch ((int)(Math.random() * 5)) {
					
					case 0:
						library[bookIndex][pageIndex][wordIndex] = "AA";
						break;
					case 1:
						library[bookIndex][pageIndex][wordIndex] = "BB";
						break;
					case 2:
						library[bookIndex][pageIndex][wordIndex] = "CC";
						break;
					case 3:
						library[bookIndex][pageIndex][wordIndex] = "DD";
						break;
					case 4:
						library[bookIndex][pageIndex][wordIndex] = "EE";
						break;
					}
				}
			}
		}
	}
	
	public static void displayBooksDetails (String[][][] library) {
		
		for (int bookIndex = 0; bookIndex < numberOfBooks; bookIndex++) {
			System.out.println("\nBook " + (bookIndex + 1) + ":");
			System.out.println("---------");
			
			for (int pageIndex = 0; pageIndex < numberOfPages; pageIndex++) {
				System.out.print("Page " + (pageIndex + 1) + ": ");
				
				for (int wordIndex = 0; wordIndex < numberOfWords; wordIndex++) {
					System.out.print(library[bookIndex][pageIndex][wordIndex] + " ");
				}
				
				System.out.println("");
			}
		}
	}
	
	public static void findSameWords (String[][][] library) {
		
		boolean isSame = false;
		
		System.out.println();
		for (int bookIndex = 0; bookIndex < numberOfBooks - 1; bookIndex++) {
			
			for (int pageIndex = 0; pageIndex < numberOfPages; pageIndex++) {
				
				for (int wordIndex = 0; wordIndex < numberOfWords; wordIndex++) {
	
					if (library[bookIndex][pageIndex][wordIndex] == library[bookIndex + 1][pageIndex][wordIndex]) {
						
						System.out.println("\"" + library[bookIndex][pageIndex][wordIndex] + "\" is the " + (wordIndex+1) + "th word on the Page "
											+ (pageIndex+1) + " of the books " + (bookIndex+1) + " and " + (bookIndex+2) + ".");
						isSame = true;
					}
				}
			}
		}	
		
		if (isSame == false) {
			System.out.println("Books have nothing in common.");
		}
	}
				
}