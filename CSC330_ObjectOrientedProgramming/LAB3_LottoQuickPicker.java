/**
 * LAB 3 -  Lotto QuickPicker Game 
 */
package edu.cuny.csi.csc330.lab3;
import java.util.*;
import edu.cuny.csi.csc330.util.*;
import java.math.BigInteger;

public class LottoQuickPicker {
	
	// constants  specific to current game - BUT NOT ALL GAMES 
	public final static int DEFAULT_GAME_COUNT = 1; 
	private final static String GAME_NAME = "Lotto"; 
	private final static int SELECTION_POOL_SIZE = 59; 
	private final static int SELECTION_COUNT = 6;
	private int gameCount;
	private Integer[] lottery;


	public LottoQuickPicker() { //constructor
		init(DEFAULT_GAME_COUNT); 
	}
	
	public LottoQuickPicker(int games) { //constructor for multiple games
		init(games);
	}
  

	private void init(int games) {
		/**
		 * 
		 * Now what ... START FROM HERE 
		 * What additional methods do you need?
		 * What additional data properties/members do you need? 
		 */
		//setting variables
		gameCount = games; // gamecount is the number of games that will be played
	}
	
	private void displayLottery() {
		//obtaining lottery numbers
		for (int j=1; j<=gameCount; j++) { // this loop will go one game at a time
			System.out.print("("+j+") ");
			lottery = new Integer[SELECTION_COUNT];
			for (int count=0; count<SELECTION_COUNT; count++) { // obtaining the 6 random numbers
				lottery[count] = Randomizer.generateInt(1,SELECTION_POOL_SIZE); // put into lottery
			}
			Arrays.sort(lottery); //sort the lottery then print out the numbers for the one game
				for (int count=0; count<SELECTION_COUNT; count++) {
					System.out.printf(" %02d", lottery[count]);
				}
				System.out.print("\n");
			}
		
	}
	
	/**
	 * 
	 */
	public void displayTicket() {
		
		/**
		 * display heading 
		 * 
		 * for i in gameCount 
		 * 		generate selectionCount number of unique random selections in ascending order 
		 * 
		 * display footer 
		 */
		
		// display ticket heading 
		displayHeading(); 
		
		/**
		 * Display selected numbers 
		 */
		displayLottery();
		
		// display ticket footer 
		displayFooter(); 
		return;
	}
	
	protected void displayHeading() {
		System.out.println("=====================");
		Date date=new Date();
		System.out.println("GISELLE'S "+GAME_NAME);
		System.out.println(date.toString());
		
	}
	
	protected void displayFooter() {
		System.out.printf("The odds of winning is 1 out of " + "%,d" + " in each game. \n", calculateOdds());
		 System.out.println("Lab Assignment 3 CSC 330");
		 System.out.println("=====================");
		
	}
	
	/**
	 * in the calculateOdds() method, I imported the java class known as BigInteger.
	 * I used this class because the factorial for numbers >20 were too big for the memory to handle.
	 * Each integer was set as an object, using the BigIntger class.
	 * Then I used loops to multiply each object in a way it would calculate the factorial. Each object represents a specific number which is 
	 * commented below.
	 * After calculating, the final value (total), I converted the value back into a long since the method returned a long.
	 * 
	 * @return
	 */
	private long calculateOdds() {
		// the equation is n!/r!(n-r)!
		//setting variables
		BigInteger num1 = BigInteger.ONE; //this will represent n!
		BigInteger num2 = BigInteger.ONE; //this will be r!
		BigInteger num3 = BigInteger.ONE;//this will be (n-r)!
		BigInteger total = BigInteger.ONE; //this is the result of putting all the equations together
		
		for (int j=1; j <= (SELECTION_POOL_SIZE); j++) {
			num1 = num1.multiply(BigInteger.valueOf(j));
		}

		for (int i=1; i<=SELECTION_COUNT; i++) {
			num2 = num2.multiply(BigInteger.valueOf(i));
		}
		for (int k=1; k<=((SELECTION_POOL_SIZE) - SELECTION_COUNT); k++) {
			num3 = num3.multiply(BigInteger.valueOf(k));
		}
		
		//calculating the equation all together
    	total = num1.divide(num3.multiply(num2));
		
		return total.longValue();
	}
  

	/**
	 * @param args 
	 */
	public static void main(String[] args) {
		// takes an optional command line parameter specifying number of QP games to be generated
		//  By default, generate 1  
		int numberOfGames  = DEFAULT_GAME_COUNT; 
		
		if(args.length > 0) {  // if user provided an arg, assume it to be a game count
			numberOfGames = Integer.parseInt(args[0]);  // [0] is the 1st element!
		}
		
		LottoQuickPicker lotto = new LottoQuickPicker(numberOfGames);
		// now what 
		 
		lotto.displayTicket(); 
		
		
		// COMMENT THIS OUT WHEN YOU'RE DONE ... 
		System.out.println("Leaving ...");

	}

}
