
public class CalculateFormulaWithArray {

	public static void main (String[] args) {
		
		double[] x = {0.5,0.2,0.3,0.4,0.1}; // array for keep number that is between 0 to 1
		double[] y = {0,1,1,0,1}; // array for keep number that is 0 or 1
		
		// array and loop for keep number that is multiplication of array x and y
		double[] xy = new double[x.length]; 
		for (int k = 0; k < x.length; k++) {

			xy[k] = x[k] * y[k];
		}
		
		// first formula
		double a = (function(y,1)*function(x,2) - function(x,1)*function(xy,1)) / 
				   (x.length*function(x,2) - Math.pow(function(x,1), 2));
		
		// second formula
		double b = (x.length*function(xy,1) - function(x,1)*function(y,1)) /
				   (x.length*function(x,2) - Math.pow(function(x,1), 2));
		
		System.out.println("Total of X array: " + function(x,1)); // prints total of numbers in first array (0 to 1)
		System.out.println("Total of Y array: " + function(y,1)); // prints total of numbers in second array (0 or 1)
		System.out.println("Total of XY array: " + function(xy,1)); // prints total of numbers in multiplication of first and second array
		System.out.printf("A formula result is: %.2f\n", a); // first formula result
		System.out.printf("B formula result is: %.2f\n", b); // second formula result
	}
	
	/* this function is sum of the numbers in array, according to power
	 * example: X array is 0,1,1,0 --> function(x,1) --> x0^1 + x1^1 + x2^1 + x3^1
	 * example: Y array is 0,1,1,0 --> function(y,4) --> y0^4 + y1^4 + y2^4 + y3^4 */
	public static double function (double[] array, int power) {
		
		double total = 0;
		
		// loop for sum of the numbers in array, according to power
		for (int x = 0; x < array.length; x++) {
			
			total = total + Math.pow(array[x], power); 
		}
		
		return total;
	}
}
