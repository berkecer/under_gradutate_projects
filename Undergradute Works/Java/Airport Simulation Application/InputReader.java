import java.io.BufferedReader;
import java.io.FileReader;
import java.util.ArrayList;

/**
 * @author Berk Ecer
 *
 */
/* Takes path of input file and read 
 * it line by line then stores it inputLines at Main 
*/
public class InputReader { 
	/* Program read each line from input.txt then store it to the inputLine list */
	static ArrayList<String> inputLines = new ArrayList<String>();
	
	public static void ReadFile(String inputFile) throws Exception{
		BufferedReader reader;
		try {
			reader = new BufferedReader(new FileReader(inputFile));
			String line = null;

			while ((line = reader.readLine()) != null) {
				inputLines.add(line);
			}
			reader.close();

		} catch (Exception e) {
			/* General Exception Handled */
		}
		

	}
}

