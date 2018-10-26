import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;

public class Main {

	public static void main(String[] args) throws IOException {
		ArrayList<String> COURSES = IO.ReadInput("Courses.txt");
		ArrayList<String> TIMESLOTS = IO.ReadInput("Timeslots.txt");
		
		ArrayList<Exam> EXAMS = new ArrayList<Exam>();

		String year = "";
		for (String string : COURSES) {
			if (string.length() < 2) {
				year = string;
			} else {
				Exam ex = new Exam(string, year);
				EXAMS.add(ex);
			}
		}

		
		int MinimumDayCount = Math.round(roundUp(((double) EXAMS.size() / (double) TIMESLOTS.size())));
		
		String weekdays[] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday" };
		ArrayList<Day> Schedule = new ArrayList<Day>();
		

		
		int controller = 0;
		while(controller != EXAMS.size()){
			controller = 0;
			Collections.shuffle(EXAMS);
			Schedule.clear();
			for (int i = 0; i < MinimumDayCount; i++) {
				Day d = new Day(weekdays[i % 5], TIMESLOTS.size());
				Schedule.add(d);
			}
			for (Exam exam : EXAMS) {
				for (Day day : Schedule) {
					int done = day.AddExamIfPossible(exam);
					if (done == 1) {
						controller++;
						break;
					}
				}
			}
		}
		
		ArrayList<String> outputLines = new ArrayList<String>();
		for (Day day : Schedule) {
			int i = 0;
			for (Exam e : day.examsList) {
				outputLines.add(e.lectureName + " "+day.name+" " + TIMESLOTS.get(i%TIMESLOTS.size()));
				i++;
			}
			outputLines.add("\n");
		}

		IO.PrintOutput("Schedule.txt", outputLines);
		

	}

	public static int roundUp(double d) {
		return (d > (int) d) ? (int) d + 1 : (int) d;
	}

}
