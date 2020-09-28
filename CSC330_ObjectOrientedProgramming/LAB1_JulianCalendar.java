package edu.cuny.csi.csc330.lab1;

/**
 * LAB 1
 * CSC 330
 * Purpose: Generates a non-leap year perpetual Julian Calendar 
 * @author lji
 *
 */

public class JulianCalendar {
	
	// Max number of Days in a month 
	static private  final int MAX_DAY = 31; 
	
	// abbreviated Month names 
	static private  final String [] MONTH_NAMES = {
		"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
	};
	
	// day length of each month 
	static private final  int [] MONTH_SIZES = {
		31, 28, 31,30,31, 30, 31, 31, 30, 31, 30, 31
	};

	/**
	 * display The "DAY" Column Heading 
	 */
	static private void displayDayHeading() {
		System.out.printf("%6s", "Day");
		
	}
	
	/**
	 * display Month names between Day .... Day
	 */
	static private void displayHeading() {
		displayDayHeading(); 
		
		for(int i = 0 ; i < MONTH_NAMES.length ; ++i )  {
			System.out.printf("%5s", MONTH_NAMES[i]);
		}
		
		displayDayHeading(); 
	}
	

	static public void display() {
		displayHeading(); // display heading 
		
		/**
		 * Complete the logic to display a Julian cal given the pre-populated arrays defined by the Class
		 * 
		 * 
		 * 
		 * 
		 */
		
		for (int i = 1; i  <= 31; ++i) { // begin
			
			int NumOfDays = i;
			int noNum = 00;
			
			System.out.printf("%n %5d", i); //print day numbers
			
			//calendar printing
			for (int j = 0; j < MONTH_SIZES.length; ++j) { // the loop will print out the first.. second.. third.. etc... of each month
				if ((i > 28) && (MONTH_SIZES[j] == 28)) { // if the month is only 28 days then print 0 for day 29, 30, and 31.
					System.out.printf("  %03d", noNum);
					NumOfDays += MONTH_SIZES[j];
				}
				else if((i > 30) && (MONTH_SIZES[j] == 30)) { // if the month is only 30 days then print 0 for day 31.
					System.out.printf("  %03d", noNum);
					NumOfDays += MONTH_SIZES[j];
				}
				else { // print out the days
					System.out.printf("  %03d", NumOfDays); 
					NumOfDays += MONTH_SIZES[j];
				}
			}
			
			System.out.printf("%5d", i);
		}
		
		}
		
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// invoke display method 
		JulianCalendar.display(); 
	}
}