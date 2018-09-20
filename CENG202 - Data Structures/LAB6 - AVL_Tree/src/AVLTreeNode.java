
public class AVLTreeNode <T> {
	
	T data;
	AVLTreeNode<T> left;
	AVLTreeNode<T> right;
	int height;
	
	AVLTreeNode (T data) {
		this(data, null, null);
	}
	
	AVLTreeNode (T data, AVLTreeNode<T> left, AVLTreeNode<T> right) {
		this.data = data;
		this.left = left;
		this.right = right;
		this.height = 0;
		
	}
}
