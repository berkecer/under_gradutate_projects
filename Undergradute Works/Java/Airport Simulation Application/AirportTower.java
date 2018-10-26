/**
 * @author TheDementor
 *
 */
public class AirportTower {
	public MyQueue Landing_Queue_1 = new MyQueue();
	public MyQueue Landing_Queue_2 = new MyQueue();
	public MyQueue TakeOff_Queue_3 = new MyQueue();
	
	public AirportRunAway Landing_RunAway_1 = new AirportRunAway();
	public AirportRunAway Landing_RunAway_2 = new AirportRunAway();
	public AirportRunAway TakeOff_RunAway_3 = new AirportRunAway();

	public void AddPlaneToLandingQueue(Plane pl){
		if (Landing_Queue_1.getPlane_Count() <= Landing_Queue_2.getPlane_Count() ) {
			Landing_Queue_1.AddToQueue(pl);
			System.out.println("KULE CEVABI: " + pl.getPlane_Name() + " ucagi landing_queue_1'ye sokuldu.");
		} else {
			Landing_Queue_2.AddToQueue(pl);
			System.out.println("KULE CEVABI: " + pl.getPlane_Name() + " ucagi landing_queue_2'ye sokuldu.");
		}
		
		System.out.println("QUEUE 1:");
		for (int i = 0; i < Landing_Queue_1.getPlane_Count(); i++) {
			System.out.println("-> " +Landing_Queue_1.getPlane_List()[i].getPlane_Name());
		}
		
		System.out.println("QUEUE 2:");
		for (int i = 0; i < Landing_Queue_2.getPlane_Count(); i++) {
			System.out.println("-> " +Landing_Queue_2.getPlane_List()[i].getPlane_Name());
		}
		
	}
	
	public void DirectPlaneToLandingRunAway(int time, int LandingTime){
		/* QUEUE 1 ---> RUN AWAY 1 */
		if(Landing_Queue_1.getPlane_Count()>0){
			if(Landing_RunAway_1.IsEmpty){
				Plane pl = new Plane();
				pl = Landing_Queue_1.getPlane_List()[0];
				pl.setStartLandingTime(time);
				pl.setEndOfLandingTime(time + LandingTime);
				Landing_Queue_1.RemoveFromQueue();
				Landing_RunAway_1.CurrentPlane=pl;
				Landing_RunAway_1.WhenWillEmpty=time + LandingTime;
				Landing_RunAway_1.IsEmpty=false;
				System.out.println(pl.getPlane_Name() + " ucagi pist 1 e iniyorr!");
			}else{
				//System.out.println("Inis pisti 1 doludur.!");
			}
		}else{
			//System.out.println("Inis Sýrasý 1 de uçak yok.!");
		}
		/* QUEUE 2 ---> RUN AWAY 2*/
		if(Landing_Queue_2.getPlane_Count()>0){
			if(Landing_RunAway_2.IsEmpty){
				Plane pl = new Plane();
				pl = Landing_Queue_2.getPlane_List()[0];
				pl.setStartLandingTime(time);
				pl.setEndOfLandingTime(time + LandingTime);
				Landing_Queue_2.RemoveFromQueue();
				Landing_RunAway_2.CurrentPlane=pl;
				Landing_RunAway_2.WhenWillEmpty=time + LandingTime;
				Landing_RunAway_2.IsEmpty=false;
				System.out.println(pl.getPlane_Name() + " ucagi pist 2 e iniyorr!");
			}else{
				//System.out.println("Inis pisti 2 doludur.!");
			}
		}else{
			//System.out.println("Inis Sýrasý 2 de uçak yok.!");
		}
	}

	public void FreeLandingRunAways(int time,int LandingTime){
		/* FOR RUN AWAY 1 */
		if(Landing_RunAway_1.WhenWillEmpty == time){
			Plane pl = Landing_RunAway_1.CurrentPlane;
			Landing_RunAway_1.CurrentPlane=null;
			Landing_RunAway_1.IsEmpty=true;
			Landing_RunAway_1.WhenWillEmpty=0;
			pl.setCurrentStatus("L");
			for (Plane pls : Plane.planeList) {
				if(pl.getPlane_ID() == pls.getPlane_ID()){
					pls.setCurrentStatus("L");
				}
			}
			TakeOff_Queue_3.AddToQueue(pl);
			System.out.println(pl.getPlane_Name() + " ucagi basariyla inis yaptý kalkis icin sýraya girdi!");
			
		}
		/* FOR RUN AWAY 2 */
		if(Landing_RunAway_2.WhenWillEmpty == time){
			Plane pl = Landing_RunAway_2.CurrentPlane;
			Landing_RunAway_2.CurrentPlane=null;
			Landing_RunAway_2.IsEmpty=true;
			Landing_RunAway_2.WhenWillEmpty=0;
			pl.setCurrentStatus("L");
			for (Plane pls : Plane.planeList) {
				if(pl.getPlane_ID() == pls.getPlane_ID()){
					pls.setCurrentStatus("L");
				}
			}
			TakeOff_Queue_3.AddToQueue(pl);
			System.out.println(pl.getPlane_Name() + " ucagi basariyla inis yaptý kalkis icin sýraya girdi!");
			
		}
		
		
		/* RECALL DIRECT TO LANDING RUN AWAYS */
		DirectPlaneToLandingRunAway(time,LandingTime);
	}

	public void DirectPlaneToTakeoffRunAway(int time,int TakeoffTime){
		/* QUEUE 1 ---> RUN AWAY 1 */
		if(TakeOff_Queue_3.getPlane_Count()>0){
			if(TakeOff_RunAway_3.IsEmpty){
				Plane pl = new Plane();
				pl = TakeOff_Queue_3.getPlane_List()[0];
				pl.setStartTakeOffTime(time);
				pl.setEndOfTakeOffTime(time + TakeoffTime);
				TakeOff_Queue_3.RemoveFromQueue();
				TakeOff_RunAway_3.CurrentPlane=pl;
				TakeOff_RunAway_3.WhenWillEmpty=time + TakeoffTime;
				TakeOff_RunAway_3.IsEmpty=false;
				System.out.println(pl.getPlane_Name() + " ucagi kalkis yapiyor!");
				System.out.println("TAKEOFF QUEUE: ");
				for (int j = 0; j < TakeOff_Queue_3.getPlane_Count(); j++) {
					System.out.println("->" + TakeOff_Queue_3.getPlane_List()[j].getPlane_Name());
				}
			}else{
				//System.out.println("Inis pisti 1 doludur.!");
			}
		}else{
			//System.out.println("Inis Sýrasý 1 de uçak yok.!");
		}
	}

	public void FreeTakeOffRunAway(int time,int TakeoffTime){
		if(TakeOff_RunAway_3.WhenWillEmpty == time){
			Plane pl = TakeOff_RunAway_3.CurrentPlane;
			TakeOff_RunAway_3.CurrentPlane=null;
			TakeOff_RunAway_3.IsEmpty=true;
			TakeOff_RunAway_3.WhenWillEmpty=0;
			pl.setCurrentStatus("E");
			for (Plane pls : Plane.planeList) {
				if(pl.getPlane_ID() == pls.getPlane_ID()){
					pls.setCurrentStatus("E");
				}
			}
			System.out.println(pl.getPlane_Name() + " ucagi basariyla sistemi terk etti!");
			
		}
		DirectPlaneToTakeoffRunAway(time, TakeoffTime);
	}
}
