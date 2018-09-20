
public class Node <Type> {

	public Type data;
	public Node<Type> next;
	
	public Node (Type data, Node<Type> next) {
		this.data = data;
		this.next = next;
	}
}
