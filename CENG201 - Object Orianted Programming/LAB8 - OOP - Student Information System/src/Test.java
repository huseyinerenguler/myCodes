
public class Test {
	
	public static void main (String[] args) {
		
		Student student1 = new Student();
		student1.setName("Enes Asana");
		student1.setGPA(Math.random() * 4);
		
		Student student2 = new Student();
		student2.setName("Huseyin Eren Guler");
		student2.setGPA(Math.random() * 4);
		
		Student student3 = new Student();
		student3.setName("Latif Bahadir Altun");
		student3.setStatus(false);
		
		Student student4 = new Student();
		student4.setName("Fatih Gocer");
		student4.setStatus(false);
		
		Student student5 = new Student();
		student5.setName("Tuba Cetin");
		student5.setGPA(Math.random() * 4);
		
		
		System.out.println(student1.toString() + "\n");
		System.out.println(student2.toString() + "\n");
		System.out.println(student3.toString() + "\n");
		System.out.println(student4.toString() + "\n");
		System.out.println(student5.toString() + "\n");
		
		System.out.println("Total object count is: " + Student.countOfObjects);
	}
	
}