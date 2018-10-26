/**
 * @author Berk Ecer
 *
 */
public class ProgramProcessor {
	public static void ProcessStart(int ExecutionTime,int FuelConsump,
	int LandingTime,int TakeoffTime,String QueueType, AirportTower TOWER){
		for (int i = 1; i < ExecutionTime; i++) {
			System.out.println("--- Time : " +i + " ---\n");
			for (Plane pl : Plane.planeList) {
				if(pl.getArrivalTime() == i){
					TOWER.AddPlaneToLandingQueue(pl);
				}
			}
			TOWER.DirectPlaneToLandingRunAway(i, LandingTime);
			TOWER.FreeLandingRunAways(i, LandingTime);
			
			TOWER.DirectPlaneToTakeoffRunAway(i, TakeoffTime);
			TOWER.FreeTakeOffRunAway(i, TakeoffTime);
			
			
		}
		
	}
}
