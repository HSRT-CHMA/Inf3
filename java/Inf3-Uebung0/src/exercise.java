/**
 * Imports for the values ArrayList
 */
import java.util.ArrayList;

/**
 * Written on 2015-03-28
 * @author Christoph Mayer
 *
 */
public class exercise {
	private ArrayList<String> values = new ArrayList<String>();
//	private String in = null;
	
	public exercise(String in){
		
//		this.in = in;
	}
	
	/**
	 * Exercise 1: Sum up all values
	 * @return result of the exercise - sum
	 */
	private double e01(){
		double result = 0;
		
		for(int i=0; i<values.size(); i++){
			result = result + Double.valueOf(values.get(i));
		}
		
		return result;
	}
	
	/**
	 * Exercise 2: Average Value of the values
	 * @return result of the exercise - average
	 */
	private double e02(){
		return e01()/values.size();
	}
	
	/**
	 * Exercise 3: Return values in opposite direction
	 * @return result of the exercise - opposite
	 */
	private String e03(){
		String result = null;
		
		for(int i=values.size(); i>=0; i--){
			result = result + " " + values.get(i);
		}
		
		return result;
	}
	
	/**
	 * Exercise 4: Sort values
	 * @return result of the exercise - sort
	 */
	private String e04(){
		return null;
	}
	
	/**
	 * Exercise 5: Palindrome
	 * For Loop gets the values in the normal direction
	 * at the end, exercise 03 (opposite direction) will be called
	 * @return result of the exercise - palindrome
	 */
	private String e05(){
		String result = null;
		
		for(int i=0; i<values.size(); i++){
			result = result + " " + values.get(i);
		}
		
		return result + " " +e03();
	}
	
	/**
	 * Overwritten toString Method - Output which consists the different exercises
	 */
	@Override
	public String toString(){
		return "\nExercise 1: " +e01()+ "\nExercise 2: " +e02()+ "\nExercise 3: " +e03()+ "\nExercise 4: " +e04()+ "\nExercise 5: " +e05();
	}
}