import java.io.BufferedWriter;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.Writer;
import java.util.ArrayList;

/**
 * @author Berk Ecer
 *
 */
/* Takes path of output file and write 
 * each line stored in outputLines at Main 
*/
public class OutputWriter {
	/* Program store every output line to the outputLine list */
	static ArrayList<String> outputLines = new ArrayList<String>();
	
	public static void outputPrint(String outputFile){
		try (Writer writer = new BufferedWriter(new OutputStreamWriter(new FileOutputStream(outputFile), "utf-8"))) {
		    for (String string : outputLines) {
		    	writer.write(string + "\n");
			}
		} catch (IOException ex){
		    System.out.println("IO Exception handled while output");
		} 
	}
}
