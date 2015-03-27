/**
 * Import for Buffered Input Reader for Console Input
 */
import java.io.BufferedReader;
import java.io.InputStreamReader;

/**
 * Written on 2015-03-28
 * @author Christoph
 *
 */
public class start {

	public static void main(String[] args) {
		BufferedReader in = new BufferedReader (new InputStreamReader(System.in));
		String input = null;
		
		/**
		 * User Output to system console output
		 */
		System.out.println("Bitte geben Sie nun die Zahlen ein: ");
		
		/**
		 * try catch body to read from system console
		 */
		try{
			input = in.readLine();
		}catch(Exception e){
			System.out.println("Error occured at " +e.toString());
		}
		/**
		 * New Object of the Exercise Class an the Exercise Methods
		 */
		exercise e01 = new exercise(input);
		System.out.println(e01.toString());
	}
}