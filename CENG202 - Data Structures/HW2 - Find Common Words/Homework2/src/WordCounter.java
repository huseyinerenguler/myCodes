import java.io.File;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Locale;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;

public class WordCounter {

	static Scanner input = new Scanner(System.in);
	
	public static void main (String[] args) {
		
		String tomsawyer = "\"The Adventures of Tom Sawyer\" by Mark Twain";
		String totc = "\"Tale of Two Cities\" by Charles Dickens";
		String dyssy10 = "\"The Odyssey\" by Homer";

		String message = "1) " + tomsawyer + "\n" +
						 "2) " + totc + "\n" +
						 "3) " + dyssy10 + "\n" +
						 "Choice Book: ";

		String book;
		while (true) {
			
			System.out.print(message);
			
			int choice = input.nextInt();
			
			if (choice == 1) {
				book = "tomsawyer.txt"; break; }
				
			else if (choice == 2) {
				book = "totc.txt"; break; }
				
			else if (choice == 3) {
				book = "dyssy10.txt"; break; }
			
			else {
				System.out.println("You entered wrong choice. Try Again.\n"); }
		}
		
		System.out.print("Enter Threshold Value: ");
		int thresholdValue = input.nextInt();
		
		/////////////////////////////////////////////////////////////////////////////
		
		HashMap<String, Integer> bookHashMap = new HashMap<String, Integer>();
		Set<Map.Entry<String, Integer>> bookHashSet = bookHashMap.entrySet();
		
		HashMap<String, Integer> commonHashMap = new HashMap<String, Integer>();	
		
		try {
			
			// commonHashMap Filled
			Scanner sc = new Scanner(new File("commonwords.txt"));
		    sc.useDelimiter("[^a-zA-Z']");
		    String str;
		    while (sc.hasNext()) {
		    	str = sc.next().toLowerCase(Locale.ENGLISH);
		    	commonHashMap.put(str, 1);
		    }
		    sc.close();
		    
		    
		    // bookHashMap Filled
		    sc = new Scanner(new File(book));
		    sc.useDelimiter("[^a-zA-Z']");
	    
		    // Add the non-common words in the book to HashMap.
		    while(sc.hasNext()) {
		    	str = sc.next().toLowerCase(Locale.ENGLISH);
		    
		    	if (!commonHashMap.containsKey(str)) {
		    		
		    		if (bookHashMap.containsKey(str)) {
		    			bookHashMap.put(str, bookHashMap.get(str)+1); }
			    	else {
			    		bookHashMap.put(str, 1); }
		    	}
		    }
		    sc.close();
		    
		}
		
		catch (Exception e) {
			System.out.println(e);
		}
		
		
	    // Display Part.
		Iterator<Map.Entry<String, Integer>> iterator = bookHashSet.iterator();
		
		//System.out.println("Words");
		while(iterator.hasNext()) {
			
			Map.Entry<String, Integer> x = iterator.next();
			
			String key = x.getKey();
			int value = x.getValue();
			
			if (value > thresholdValue && key.length() > 0) {
				System.out.println(key + ": " + value); 
			}
		}
	}
}