
public class GenerateRandomAndFindPrimeNumber {

	public static void main (String[] args) {
		
		int howMany = 1000;
		int limit = 1000000;
		
		int[] randomNumber = generateRandomNumber(howMany, limit);
		
		int numberOfPrime = 0;

		for (int x = 0; x < randomNumber.length; x++) {
			
			if (isPrimeNumber(randomNumber[x])) {
				
				numberOfPrime++;
			}
		}
		
		System.out.println("Number of prime is: " + numberOfPrime);
		System.out.println("Number of not prime is: " + (randomNumber.length - numberOfPrime));
		
	}
	
	public static int[] generateRandomNumber (int howMany, int limit) {
		
		int[] randomNumber = new int[howMany];
		
		for (int x = 0; x < howMany; x++) {
			
			randomNumber[x] = (int)(Math.random() * limit);
		}
		
		return randomNumber;
	}
	
	public static boolean isPrimeNumber (int number) {
		
		for (int x = 2; x < number; x++) {
			
			if (number % x == 0) {
				
				return false;
			}
		}
		
		return true;
	}
	
}
