
public class Client {
	
	public static void main (String[] args) {
		
		LinkedList list = new LinkedList();
	
		/*
		System.out.println("List is empty? " + list.isEmpty()); // true olmal�
		
		list.push("TEST");
		list.push(5);
		list.push(18);

		list.display(); // 18 -> 5 -> 3 -> NULL olmal�
		System.out.println("SIZE: " + list.size()); // 3 olmal�
		
		list.push(21);
		list.pop();
		list.pop();
		
		list.display(); // 5 -> 3 -> NULL olmal�
		System.out.println("SIZE: " + list.size()); // 2 olmal�
		*/
		
		
		String str = "muyusnac";
		
		for (int index = 0; index < str.length(); index++) {	
			list.push(str.charAt(index));
		}
		
		list.display();
		
		int listSize = list.size();
		for (int index = 0; index < listSize; index++) {
			System.out.print(((Node)list.pop()).data);
		}	
		
	}
}
