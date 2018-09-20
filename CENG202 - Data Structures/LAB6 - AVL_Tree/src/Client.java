
public class Client {

	public static void main (String[] args) {
		
		AVL_Tree<Integer> avl = new AVL_Tree<Integer>();
		
		avl.root = avl.insert(35, avl.root);
		avl.root = avl.insert(95, avl.root);
		avl.root = avl.insert(85, avl.root);
		avl.root = avl.insert(65, avl.root);
		avl.root = avl.insert(45, avl.root);
		avl.root = avl.insert(100, avl.root);
		avl.root = avl.insert(70, avl.root);
		avl.root = avl.insert(10, avl.root);
		avl.root = avl.insert(50, avl.root);
		avl.root = avl.insert(20, avl.root);
		
		avl.preOrderDisplay(avl.root);
		
	}
}
