
public class LinkedList implements Stack {
	
	public Node node;
	
	LinkedList() {
		this.node = null;
	}
	
	public void push (Object o) {
		node = new Node(o, node);
	}
	
	public Object pop () {
		
		Node temp = node;
		
		if (temp != null) {
			node = node.next;
			return temp;
		}
		
		else {
			System.out.println("Stack is already empty! (return -> null)");
			return null;
		}
	}
	
	public void display() {
		
		Node temp = node;
		
		while (temp != null) {
			System.out.print(temp.data + " -> ");
			temp = temp.next;
		}
		
		if (temp == null) {
			System.out.println("NULL!");
		}
	}
	
	public boolean isEmpty () {
		
		if (node == null)
			return true;
		else
			return false;
	}
	
	public int size () {
		
		int size = 0;
		Node temp = node;
		
		while (temp != null) {
			size++;
			temp = temp.next;
		}
		
		return size;
	}
	
	
	
	
	/*
	public void addFirst (int value) {
		
		this.head = new Node(value, head);
	}
	
	public void addLast (int value) {
		
		if (head == null) {
			this.addFirst(value);
		}
		
		else {
			Node temp = head;
			
			while (temp.next != null) {
				temp = temp.next;
			}
			
			temp.next = new Node(value, null);
		}
	}
	
	public void deleteFirst () {
		
		this.head.data = this.head.next.data;
		this.head.next = this.head.next.next;
	}
	
	public void deleteLast () {
		
		if (head == null) {
			System.out.println("Already deleted.");
		}
		else {
			Node temp = head;
			
			while (temp.next.next != null) {
				temp = temp.next;
			}
			
			temp.next = null;
		}
	}
	
	public void printList() {
		
		if (head == null) {
			System.out.println("List is empty.");
		}
		else {
			
			while (head.next != null) {
				System.out.print(head.data + " ");
				head = head.next;
			}
			
			System.out.print("NULL");
		}
		
		
	}
	
	
	*/
	
}
