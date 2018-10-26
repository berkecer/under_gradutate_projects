import java.util.ArrayList;

/**
 * @author Berk Ecer
 *
 */
public class Plane {
	/* Program create planes for input and put them this Plane list */
	static ArrayList<Plane> planeList = new ArrayList<Plane>();
	/*Keep every single ID of planes*/
	public static ArrayList<Integer> ListOfPlaneIDs = new ArrayList<Integer>();
	
	/* Directly Comes From Input */
	private String Plane_Name;
	private int Plane_Fuel;
	private int Plane_ID;
	private String CurrentStatus;
	private int ArrivalTime;
	
	/* Will be calculated later */
	private int StartLandingTime;
	private int EndOfLandingTime;
	
	private int StartTakeOffTime;
	private int EndOfTakeOffTime;
	
	
	/* 
	  Generates Random Integer. 
	  If that integer already stored in list create another. 
	*/
	public static int GenerateUniqueID(){
		int checker = 1;
		int newID = 99999999;
		while(checker == 1){
			newID = (int)(Math.random()*1000000);
			if(ListOfPlaneIDs.contains(newID)){
				/* Continue and create another random integer */
			}else{
				/* List does not contain that integer */
				ListOfPlaneIDs.add(newID);
				checker = 0;
			}
		}
		
		return newID;
	}
	
	/* GETTERS AND SETTERS FOR PRIVATE VARIABLES */
	
	/**
	 * @return the plane_Name
	 */
	public String getPlane_Name() {
		return Plane_Name;
	}
	/**
	 * @param plane_Name the plane_Name to set
	 */
	public void setPlane_Name(String plane_Name) {
		Plane_Name = plane_Name;
	}
	/**
	 * @return the plane_Fuel
	 */
	public int getPlane_Fuel() {
		return Plane_Fuel;
	}
	/**
	 * @param plane_Fuel the plane_Fuel to set
	 */
	public void setPlane_Fuel(int plane_Fuel) {
		Plane_Fuel = plane_Fuel;
	}
	/**
	 * @return the plane_ID
	 */
	public int getPlane_ID() {
		return Plane_ID;
	}
	/**
	 * @param plane_ID the plane_ID to set
	 */
	public void setPlane_ID(int plane_ID) {
		Plane_ID = plane_ID;
	}
	/**
	 * @return the currentStatus
	 */
	public String getCurrentStatus() {
		return CurrentStatus;
	}
	/**
	 * @param currentStatus the currentStatus to set
	 */
	public void setCurrentStatus(String currentStatus) {
		CurrentStatus = currentStatus;
	}
	/**
	 * @return the arrivalTime
	 */
	public int getArrivalTime() {
		return ArrivalTime;
	}
	/**
	 * @param arrivalTime the arrivalTime to set
	 */
	public void setArrivalTime(int arrivalTime) {
		ArrivalTime = arrivalTime;
	}
	/**
	 * @return the startLandingTime
	 */
	public int getStartLandingTime() {
		return StartLandingTime;
	}
	/**
	 * @param startLandingTime the startLandingTime to set
	 */
	public void setStartLandingTime(int startLandingTime) {
		StartLandingTime = startLandingTime;
	}
	/**
	 * @return the endOfLandingTime
	 */
	public int getEndOfLandingTime() {
		return EndOfLandingTime;
	}
	/**
	 * @param endOfLandingTime the endOfLandingTime to set
	 */
	public void setEndOfLandingTime(int endOfLandingTime) {
		EndOfLandingTime = endOfLandingTime;
	}
	/**
	 * @return the startTakeOffTime
	 */
	public int getStartTakeOffTime() {
		return StartTakeOffTime;
	}
	/**
	 * @param startTakeOffTime the startTakeOffTime to set
	 */
	public void setStartTakeOffTime(int startTakeOffTime) {
		StartTakeOffTime = startTakeOffTime;
	}
	/**
	 * @return the endOfTakeOffTime
	 */
	public int getEndOfTakeOffTime() {
		return EndOfTakeOffTime;
	}
	/**
	 * @param endOfTakeOffTime the endOfTakeOffTime to set
	 */
	public void setEndOfTakeOffTime(int endOfTakeOffTime) {
		EndOfTakeOffTime = endOfTakeOffTime;
	}
	
	
}
