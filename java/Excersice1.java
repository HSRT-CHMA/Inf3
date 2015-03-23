package bla;

/**
 * 
 * @author Georgia Excersice No. 1 Informatik 3
 * 
 */
public class Excersice1 {

	private static double[] original;
	private static double sum;
	private static double average;
	private static double[] reverseList;
	private static double[] sortedList;
	private static double[] palindrome;

	/**
	 * This method receives a string array, content of which is specified via
	 * Run > Run Configurations > Arguments, and modify it by calling all other
	 * methods
	 * 
	 * @param args
	 *            String-Array of arguments
	 */
	public static void main(String[] args) {
		original = modify(args);
		System.out.println("Original List : ");
		print(original);
		sum = sum(original);
		System.out.println("\nSum : " + sum);
		average = average(original);
		System.out.println("Average : " + average);
		reverseList = reverse(original);
		System.out.println("Reverse : ");
		print(reverseList);
		palindrome = palindrome(original);
		System.out.println("\nPalindrome : ");
		print(palindrome);
		sortedList = sort(original);
		System.out.println("\nSorted List : ");
		print(sortedList);
	}

	/**
	 * This method casts a string array into a double array by changing letters
	 * into ASCII-values and sum them
	 * 
	 * @param args
	 *            String-Array of arguments
	 * @return result double-Array of modified arguments
	 */
	public static double[] modify(String[] args) {
		double[] result = new double[args.length];

		for (int i = 0; i < args.length; i++) {
			String word = args[i];
			double ascii = 0;
			int start = 0;
			int end = 1;

			while ((start >= 0) && (end <= word.length())) {
				String letter = word.substring(start, end);

				if (!(letter.equals("0") | letter.equals("1")
						| letter.equals("2") | letter.equals("3")
						| letter.equals("4") | letter.equals("5")
						| letter.equals("6") | letter.equals("7")
						| letter.equals("8") | letter.equals("9"))) {
					char l = letter.charAt(0);
					int res = (int) l;
					ascii += res;
					args[i] = String.valueOf(ascii);
				}
				result[i] = Double.parseDouble(args[i]);
				start++;
				end++;
			}
		}
		return result;
	}

	/**
	 * This method prints a given array
	 * 
	 * @param numbers
	 *            double array
	 */
	public static void print(double[] numbers) {
		for (int i = 0; i < numbers.length; i++) {
			System.out.print(numbers[i] + " | ");
		}
	}

	/**
	 * This method returns the sum of a given array
	 * 
	 * @param numbers
	 *            double array
	 * @return sum The sum of numbers
	 */
	public static double sum(double[] numbers) {
		double sum = 0;
		for (int i = 0; i < numbers.length; i++) {
			sum += numbers[i];
		}
		return sum;
	}

	/**
	 * This method returns the average of all digits in a given array
	 * 
	 * @param numbers
	 *            double array
	 * @return average The average-value of numbers
	 */
	public static double average(double[] numbers) {
		double sum = sum(numbers);
		double average = sum / numbers.length;
		return average;
	}

	/**
	 * This method reverses a given array
	 * 
	 * @param numbers
	 *            double array
	 * @return reverse The reversed array of numbers
	 */
	public static double[] reverse(double[] numbers) {
		double[] reverse = new double[numbers.length];
		int index = numbers.length;
		for (int i = 0; i < numbers.length; i++) {
			index--;
			reverse[i] = numbers[index];
		}
		return reverse;
	}

	/**
	 * This method sorts a given array by using bubblesort
	 * 
	 * @param numbers
	 *            double array
	 * @return numbers The sorted version of numbers
	 */
	public static double[] sort(double[] numbers) {
		double tmp = 0;
		for (int n = numbers.length; n > 1; n--) {
			for (int i = 0; i < n - 1; i++) {
				if (numbers[i] > numbers[i + 1]) {
					tmp = numbers[i];
					numbers[i] = numbers[i + 1];
					numbers[i + 1] = tmp;
				}
			}
		}
		return numbers;
	}

	/**
	 * This method creates a palindrome of a given array
	 * 
	 * @param numbers
	 *            double array
	 * @return result The palindrome of numbers
	 */
	public static double[] palindrome(double[] numbers) {
		double[] result = new double[numbers.length * 2];
		double[] rev = new double[numbers.length];
		rev = reverse(numbers);
		int index = 0;

		for (int i = 0; i < numbers.length; i++) {
			result[i] = numbers[i];
		}

		for (int i = numbers.length; i < result.length; i++) {
			result[i] = rev[index];
			index++;
		}

		return result;

	}

}
