import java.util.ArrayList;

/**
 * @author Berk Ecer
 *
 */
public class InputLinesExecuter {
	public static void ExecuteInput(ArrayList<String> IL){
		for (String line : IL) {
			String line_pieces[] = line.split("\t");
			Plane newPlane = new Plane();
			newPlane.setArrivalTime(Integer.parseInt(line_pieces[0]));
			newPlane.setPlane_Name(line_pieces[1]);
			newPlane.setPlane_Fuel(Integer.parseInt(line_pieces[2]));
			newPlane.setPlane_ID(Plane.GenerateUniqueID());
			newPlane.setCurrentStatus("F");
			
			/* Add this plane to the plane list at main */
			Plane.planeList.add(newPlane);
			
		}
	}
}
