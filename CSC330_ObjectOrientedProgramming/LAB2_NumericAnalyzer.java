package edu.cuny.csi.csc330.lab2;

import java.util.Arrays;

// LAB 2
// Purpose: To gather perform different calculations using classes and display it

public class NumericAnalyzer {
	//declaring and setting variables
	private int count = 0;
	private int min = 0;
	private int max = 0;
	private int mean = 0;
	private int range = 0;
	private int median = 0;
	private int sum = 0;
	private int variance = 0;
	private double standardDev = 0;
	
	private void analyze(int[] arr) { // sorting and analyzing the integers
		Arrays.sort(arr);
		//display sort
		for (int i = 0; i < arr.length; i++) {
			System.out.printf(" %s", arr[i]);
		}
	}
	
	private void calculate(int arr[], int length){ // calculating and setting every variable
		//count
		count = length;
	
		if (arr.length > 1) {
			//min and max
			min = arr[0];
			max = arr[length-1];
			//range
			range = max - min;
			//sum then mean
			for (int i = 0; i < length; i++) {
				sum+=arr[i];
			}
			mean = sum / arr.length;
			//median
			if(arr.length % 2 != 0) { //if the length of an array is even
				median = arr[arr.length/2];
			}
			else { //if the length of an array is odd
				median = ((arr[arr.length/2] + arr[(arr.length/2) - 1])/2);
			}
			//variance
			for (int i = 0; i < length; i++) {
				arr[i]= (int) Math.pow(arr[i]-mean,2);
				variance+=arr[i];
			}
			variance = variance / arr.length;
			//standard dev
			standardDev = Math.sqrt(variance);
		}
		else {
			min = arr[0];
			max = arr[0];
			sum = arr[0];
			mean = arr[0];
			median = arr[0];
		}

		
	}
	
	private void display(){ // display output
		String fmtString = "%-20s %,15d\n";
		String fmtString2= "%-20s %,15f\n";
		System.out.printf(fmtString, "\nCount: ", count);
		System.out.printf(fmtString, "Min: ", min);
		System.out.printf(fmtString, "Max: ", max);
		System.out.printf(fmtString, "Range: ", range);
		System.out.printf(fmtString, "Sum: ", sum);
		System.out.printf(fmtString, "Mean: ", mean);
		System.out.printf(fmtString, "Median: ", median);
		System.out.printf(fmtString, "Variance: ", variance);
		System.out.printf(fmtString2, "Standard Deviation: ", standardDev);
	}
	
	private static boolean isNumeric(String input) {
		try
		{
		Integer.parseInt(input); //checks if the input is able to turn into an int
		return true;
		}
		catch (Exception e) //if an exception or error is found, then return false.
		{
		return false;
		}
	}

	public static void main(String[] args) {
		// setting variables
		int[] arr;
		arr = new int[args.length];
		NumericAnalyzer object = new NumericAnalyzer();
		
	if (args.length == 0) { // no arguments
		System.out.print("There are no arguments to be found.");
		System.exit(1);
	}
	//gathering via arguments
	else if (args.length > 0) { // if there are arguments, push via command line args
		for (int i = 0; i < args.length; i++) {
		if(!NumericAnalyzer.isNumeric(args[i])) {
				System.err.println("Expecting Numeric Data: " + args[i]);
				System.exit(2); // exit code for invalid data 
		}
			arr[i] = Integer.parseInt(args[i]);
		}
		// analyze
		object.analyze(arr);
		//count
		object.calculate(arr, args.length);
		//display
		object.display();	
	}


	

	System.exit(0);
	}
}