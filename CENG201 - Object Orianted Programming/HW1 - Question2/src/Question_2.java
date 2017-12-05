/*
 * @author	Huseyin Eren Guler
 * @since	2017-11-06 
 */

import java.util.*;

import javax.swing.JOptionPane;

public class Question_2 {

	private static Scanner input;
	
	public static void main (String[] args) {
		
		input = new Scanner (System.in);
		
		String firstString;
		System.out.print("Enter the first name: ");
		firstString = input.nextLine();
		
		JOptionPane.showMessageDialog(null, "sa");
		
		String secondString;
		System.out.print("Enter the second name: ");
		secondString = input.nextLine();
		
		String thirdString;
		System.out.print("Enter the third name: ");
		thirdString = input.nextLine();
		
		System.out.print("\nThe names in alphabetical order: ");
		
		// if true -> first string is less than second and third string
		if (firstString.compareTo(secondString) < 0 && firstString.compareTo(thirdString) < 0) {
			
			// if true -> second string is less than third string
			if (secondString.compareTo(thirdString) < 0) {
				System.out.println(firstString + ", " + secondString + ", " + thirdString);
			}
			
			// third string is less than second string
			else {
				System.out.println(firstString + ", " + thirdString + ", " + secondString);
			}
		}
		
		// if true -> first string is bigger than second and third string
		else if (firstString.compareTo(secondString) > 0 && firstString.compareTo(thirdString) > 0) {
			
			// if true -> second string is bigger than third string
			if (secondString.compareTo(thirdString) > 0) {
				System.out.println(thirdString + ", " + secondString + ", " + firstString);
			}
			
			// third string is bigger than second string
			else {
				System.out.println(secondString + ", " + thirdString + ", " + firstString);
			}
		}
		
		// first string is in the middle
		else {
			
			// if true -> second string is less than third string
			if (secondString.compareTo(thirdString) < 0) {
				System.out.println(secondString + ", " + firstString + ", " + thirdString);
			}
			
			// third string is less than second string
			else {
				System.out.println(thirdString + ", " + firstString + ", " + secondString);
			}
		}
	}
}
