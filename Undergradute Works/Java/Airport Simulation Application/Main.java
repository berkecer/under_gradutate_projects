
public class Main {

	public static void main(String[] args) {
		/* Read File */
		try {InputReader.ReadFile(args[0]);} catch (Exception e){}
		/* Execute Input */
		InputLinesExecuter.ExecuteInput(InputReader.inputLines);
		/* Execute Program */
		AirportTower TOWER = new AirportTower();
		ProgramProcessor.ProcessStart(Integer.parseInt(args[2]),
				Integer.parseInt(args[3]), Integer.parseInt(args[4]),
				Integer.parseInt(args[5]), args[6],TOWER);
	}

}
