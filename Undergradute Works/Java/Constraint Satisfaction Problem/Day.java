import java.util.ArrayList;

public class Day {
	public String name;
	public ArrayList<Exam> examsList = new ArrayList<Exam>();
	public ArrayList<Integer> yearsCounter = new ArrayList<Integer>();
	public int MaxExamCount;
	public int CurrentExamCount;
	
	
	public Day(String dayName,int max){
		name = dayName;
		MaxExamCount = max;
		CurrentExamCount = 0;
		for (int i = 0; i < 4; i++) {
			yearsCounter.add(0);
		}
	}
	
	public int AddExamIfPossible(Exam ex){
		int returnVal = -1;
		if(CurrentExamCount<MaxExamCount){
			if(ex.year.equals("1")||ex.year.equals("2")||ex.year.equals("3")){
				int level = Integer.parseInt(ex.year);
				if(CurrentExamCount == 0){
					examsList.add(ex);
					yearsCounter.set(level, yearsCounter.get(level)+1);
					returnVal = 1;
				}else{
					if(examsList.get(examsList.size()-1).year.equals(ex.year)){
						returnVal = 0;
					}else{
						examsList.add(ex);
						yearsCounter.set(level, yearsCounter.get(level)+1);
						returnVal = 1;
					}
				}
			}else if(ex.year.equals("4")){
				if(yearsCounter.get(3)<3){
					examsList.add(ex);
					yearsCounter.set(3, yearsCounter.get(3)+1);
					returnVal = 1;
				}
			}
		}
		if(returnVal == 1){
			CurrentExamCount++;
		}
		return returnVal;
	}
}
