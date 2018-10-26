/**
 * @author Berk Ecer
 *
 */
public class MyQueue {
	private Plane[] Plane_List = new Plane[100];
	private int Plane_Count=0;
	private int Indexer = -1;
	
	
	public void AddToQueue(Plane pl){
		Indexer++;
		Plane_List[Indexer] = pl;
		Plane_Count++;
	}
	
	public void RemoveFromQueue(){
		if(Plane_Count>0){
			Plane[] newList = new Plane[100];
			for (int i = 0; i < Plane_Count; i++) {
				if(i==0){
					// do nothing == delete first element
				}else{
					newList[i-1]=Plane_List[i];
				}
			}
			Plane_List = newList;
			Plane_Count--;
			Indexer--;
		}
	}

	/* GETTERS AND SETTERS */

	/**
	 * @return the plane_List
	 */
	public Plane[] getPlane_List() {
		return Plane_List;
	}
	/**
	 * @param plane_List the plane_List to set
	 */
	public void setPlane_List(Plane[] plane_List) {
		Plane_List = plane_List;
	}
	/**
	 * @return the plane_Count
	 */
	public int getPlane_Count() {
		return Plane_Count;
	}
	/**
	 * @param plane_Count the plane_Count to set
	 */
	public void setPlane_Count(int plane_Count) {
		Plane_Count = plane_Count;
	}
	
	
}
