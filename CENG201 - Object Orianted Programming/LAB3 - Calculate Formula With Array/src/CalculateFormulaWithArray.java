import java.util.*;

public class CalculateFormulaWithArray {

	public static void main (String[] args) {
		
		double[] x = {0.5,0.2,0.3,0.4,0.1};
		double[] y = {0,1,1,0,1};
		
		double[] xy = new double[x.length];
		for (int k = 0; k < x.length; k++) {
			xy[k] = x[k] * y[k];
		}
		
		double a = (function(y,1)*function(x,2) - function(x,1)*function(xy,1)) / 
				   (x.length*function(x,2) - Math.pow(function(x,1), 2));
		
		double b = (x.length*function(xy,1) - function(x,1)*function(y,1)) /
				   (x.length*function(x,2) - Math.pow(function(x,1), 2));
		
		System.out.println("Total of X array: " + function(x,1));
		System.out.println("Total of Y array: " + function(y,1));
		System.out.println("Total of XY array: " + function(xy,1));
		System.out.println("A formula result is: " + a);
		System.out.println("B formula result is: " + b);
	}
	
	public static double function (double[] array, int power) {
		
		double total = 0;
		
		for (int x = 0; x < array.length; x++) {
			
			total = total + Math.pow(array[x], power);
		}
		
		return total;
	}
}
