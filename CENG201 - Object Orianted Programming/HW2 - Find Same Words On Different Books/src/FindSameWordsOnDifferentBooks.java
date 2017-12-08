/*
 * Name:	Huseyin Eren Guler
 * ID:		15050111014
 * Date:	08.12.2017
 * 
 * Purpose:	Assume that we have several books in our library. All of the books have the same number of pages 
 * 			and each of the pages consist of 5 random words. This program find the books that cover 
 * 			the same word on the same page and in the same order and displays it.
 */

import java.util.Scanner;

public class FindSameWordsOnDifferentBooks {

	static Scanner input = new Scanner(System.in);
	
	static int numberOfBooks = 0; // keeps the number of books 
	static int numberOfPages = 0; // keeps the number of pages
	static int numberOfWords = 5; // keeps the number of words
	
	public static void main (String[] args) {
		
		// if number of books and pages are bigger than zero, this condition is true
		if (getInformationAboutBooks()) {
			
			// create three-dimensional array with the number of books, pages and words
			String[][][] library = new String[numberOfBooks][numberOfPages][numberOfWords];
						
			fillPagesOfEachBooksWithRandomWords(library);
			
			displayBooksDetails(library);
			
			findSameWords(library);
		}	
	}
	
	// This function gets number of books and pages from user and if those numbers are invalid display error message
	// Valid -> return true,	invalid -> return false
	public static boolean getInformationAboutBooks () {
		
		System.out.print("How many books do you have? : ");
		int _numberOfBooks = input.nextInt();
		
		// if number of books is less than 1, display error message
		if (_numberOfBooks < 1) {
			System.out.println("Number of books does not less than 1.");
			return false;
		}
		
		System.out.print("How many pages do they have? : ");
		int _numberOfPages = input.nextInt();
		
		// if number of pages is less than 1, display error message
		if (_numberOfPages < 1) {
			System.out.println("Number of pages does not less than 1.");
			return false;
		}
		
		numberOfBooks = _numberOfBooks;
		numberOfPages = _numberOfPages;
		return true;
	}
	
	// This function fill pages of each books with random words -> (AA, BB, CC, DD, EE)
	public static void fillPagesOfEachBooksWithRandomWords (String[][][] library) {
		
		// loop for to fill every book
		for (int bookIndex = 0; bookIndex < numberOfBooks; bookIndex++) {
			
			// loop for to fill book with pages
			for (int pageIndex = 0; pageIndex < numberOfPages; pageIndex++) {
				
				// loop for to fill every page with random words
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
	
	// This function displays book details
	public static void displayBooksDetails (String[][][] library) {
		
		// loop for the display number of books
		for (int bookIndex = 0; bookIndex < numberOfBooks; bookIndex++) {
			System.out.println("\nBook " + (bookIndex + 1) + ":");
			System.out.println("---------");
			
			// loop for the display number of pages
			for (int pageIndex = 0; pageIndex < numberOfPages; pageIndex++) {
				System.out.print("Page " + (pageIndex + 1) + ": ");
				
				// loop for the display words in page
				for (int wordIndex = 0; wordIndex < numberOfWords; wordIndex++) {
					System.out.print(library[bookIndex][pageIndex][wordIndex] + " ");
				}
				
				System.out.println("");
			}
		}
	}
	
	// This function find same words on same pages with every different books, then display it
	public static void findSameWords (String[][][] library) {
		
		boolean isSame = false; // control variable is default false
		
		System.out.println("\nAll Combinations:");
		System.out.println("-------------------");
		
		// loop for the first book
		for (int firstBookIndex = 0; firstBookIndex < numberOfBooks - 1; firstBookIndex++) {
			
			// loop for the second book
			for (int secondBookIndex = firstBookIndex + 1; secondBookIndex < numberOfBooks; secondBookIndex++) {
				
				// loop for to control every page
				for (int pageIndex = 0; pageIndex < numberOfPages; pageIndex++) {
					
					// loop for to compare words on pages
					for (int wordIndex = 0; wordIndex < numberOfWords; wordIndex++) {
		
						// if we found a same word on different books, display this word and it's pages and books 
						if (library[firstBookIndex][pageIndex][wordIndex] == library[secondBookIndex][pageIndex][wordIndex]) {
							
							System.out.println("\"" + library[firstBookIndex][pageIndex][wordIndex] + "\" is the " + (wordIndex + 1) + "th word on the Page "
												+ (pageIndex + 1) + " of the books " + (firstBookIndex + 1) + " and " + (secondBookIndex + 1) + ".");
							
							isSame = true; // if we found at least one same word, control variable is true
						}
					}
				}
			}
		}
		
		// if we not found a same word in all of combinations, display information message
		if (isSame == false) {
			System.out.println("Books have nothing in common.");
		}
	}
				
}