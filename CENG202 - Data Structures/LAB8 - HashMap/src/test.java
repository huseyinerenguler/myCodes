import java.util.Scanner;

public class test {

	static Scanner input = new Scanner(System.in);
	
	public static void main (String[] args) {
	
		HashMap<String, String> hashMap = new HashMap<String, String>();
		
		hashMap.put("fatih", "fatih1");
		hashMap.put("enes", "enes2");
		hashMap.put("huseyin", "huseyin3");
		hashMap.put("yusuf", "yusuf4");
		hashMap.put("ogulcan", "ogulcan5");
		
		//hashMap.display();
		
		System.out.print("Login: ");
		String username = input.next();
		
		System.out.print("Password: ");
		String password = input.next();
		
		hashMap.check(username, password);
		System.out.println("STOP!");
		
	}
	
	
	
}
