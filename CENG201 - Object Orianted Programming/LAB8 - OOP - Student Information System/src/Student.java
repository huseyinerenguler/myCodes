import java.text.DecimalFormat;

public class Student {

	private int ID;
	private boolean status;
	private double GPA;
	String name;
	
	public static int staticID = 0;
	public static int countOfObjects = 0;
	
	Student() {
		
		countOfObjects++;
		staticID++;
		
		ID = staticID;
		status = true;
		GPA = 0;
		name = "Name Surname";
	}
	
	public void setID (int ID) {
		
		this.ID = ID;
	}
	
	public int getID () {
		
		return this.ID;
	}
	
	public void setStatus (boolean status) {
		
		this.status = status;
		
		if (this.status == false) {
			
			setID(0);
			staticID--;
		}
	}
	
	public boolean getStatus () {
		
		return this.status;
	}
	
	public void setGPA (double GPA) {
		
		this.GPA = GPA;
	}
	
	public double getGPA () {
		
		return this.GPA;
	}
	
	public void setName (String name) {
		
		this.name = name;
	}
	
	public String getName () {
		
		return this.name;
	}
	
	public String toString () {
		
		if (this.status) {

			
			return 	"Name: " + this.name + "\n" +
					"ID: " + this.ID + "\n" +
					"GPA: " + new DecimalFormat("##.###").format(this.GPA);
		}
		
		else {
			return this.name + " is not a student at AYBU!";
		}
	}
	
}
























