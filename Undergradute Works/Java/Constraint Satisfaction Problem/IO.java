import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class IO {
	/* This method reads lines from given input file */
	public static ArrayList<String> ReadInput(String fileName) throws IOException{
		ArrayList<String> inputLines = new ArrayList<String>();
		BufferedReader br = new BufferedReader(new FileReader(fileName));
		try {
		    String line = br.readLine();

		    while (line != null) {
		    	if(!line.equals("")){
		    		inputLines.add(line);
		    	}
		    	line = br.readLine();
		    }
		    
		} finally {
		    br.close();
		}
		return inputLines;
	}
	
	/* This method prints the output lines to a file */
	public static void PrintOutput(String fileName,ArrayList<String> outputLines) throws IOException{
		try {
			File file = new File(fileName);
			if (!file.exists()) {
				file.createNewFile();
			}

			FileWriter fw = new FileWriter(file.getAbsoluteFile());
			BufferedWriter bw = new BufferedWriter(fw);
			for (String line : outputLines) {
				bw.write(line + "\n");
			}
			bw.close();

		}catch (IOException e) {
			e.printStackTrace();
		}
	}
}
