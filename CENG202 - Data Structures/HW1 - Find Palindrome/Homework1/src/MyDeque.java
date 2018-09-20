
// head ekleme cýkarma tamam.
// tail ekleme cýkarma yap, ilk item icin taili head'e esitle.

public class MyDeque <Type> {

	public Node<Type> head;
	public Node<Type> tail;
	
	MyDeque() {
		this.head = null;
		this.tail = null;
	}
	
	public void push (Type o) {
		
		head = new Node<Type>(o, head);
		
		if (this.size() == 1) {
			this.tail = this.head;
		}
	}
	
	public Type pop () {
		
		Node<Type> temp = head;
		
		if (temp != null) {
			if (this.head == this.tail) {
				this.tail = null;
			}
			
			head = head.next;
			return temp.data;
		}
		else {
			System.out.println("Stack is already empty! (return -> null)");
			return null;
		}
	}
		
	public void inject (Type o) {
		
		if (this.size() == 0) {
			this.push(o);
		}
		else {
			Node<Type> temp = new Node<Type>(o, null);
			tail.next = temp;
			temp = tail;
		}
	}
	
	public Type eject () {
		
		Node<Type> temp = head;
		
		if (temp == tail) {
			return this.pop();
		}
		else {
			
			while (temp.next != tail) {
				temp = temp.next;
			}
			
			temp.next = tail.next;
			Type data = tail.data;
			tail = temp;

			return data;
		}
	}
	
	public String display() {
		
		Node<Type> temp = head;
		String str = "";
		
		while (temp != null) {
			str += (temp.data + " -> ");
			temp = temp.next;
		}
		
		if (temp == null) {
			str += "NULL";
		}
		
		return str;
	}
	
	public int size () {
		
		int size = 0;
		Node<Type> temp = head;
		
		while (temp != null) {
			size++;
			temp = temp.next;
		}
		
		return size;
	}
	
	
	public String toString() {
		return this.display();
	}
}
