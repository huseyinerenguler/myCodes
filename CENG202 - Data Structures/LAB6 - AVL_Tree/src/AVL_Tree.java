
public class AVL_Tree <T> {

	AVLTreeNode<T> root;
	
	AVL_Tree () {
		root = null;
	}
	
	private int height (AVLTreeNode<T> node) {
		if (node == null)
			return -1;
		else
			return node.height;
	}
	
	public AVLTreeNode<T> insert (T data, AVLTreeNode<T> root) {
		
		if (root == null) {
			return new AVLTreeNode<T>(data, null, null);}
		
		if ((Integer)data < (Integer)root.data) {
			root.left = insert(data, root.left);}
		
		else if ((Integer)data > (Integer)root.data) {
			root.right = insert(data, root.right);}
		
		return balance(root);
	}
	
	private AVLTreeNode<T> balance (AVLTreeNode<T> root) {
		
		if (root == null) {
			return root;}
		
		if (height(root.left) - height(root.right) > 1) {
			
			if (height(root.left.left) >= height(root.left.right)) {
				root = this.rotateWithLeftChild(root);}
			else {
				root = this.doubleWithLeftChild(root);}
		}
		
		else if (height(root.right) - height(root.left) > 1) {
			
			if (height(root.right.right) >= height(root.right.left)) {
				root = this.rotateWithRightChild(root);}
			else {
				root = this.doubleWithRightChild(root);}
		}
		
		root.height = Math.max(height(root.left), height(root.right)) +1;
		return root;
	}
	
	private AVLTreeNode<T> rotateWithLeftChild (AVLTreeNode<T> node) {
		
		AVLTreeNode<T> temp = node.left;
		node.left = temp.right;
		temp.right = node;
		
		node.height = Math.max(height(node.left), height(node.right)) +1;
		temp.height = Math.max(height(temp.left), node.height) +1;
		
		return temp;
	}
	
	private AVLTreeNode<T> doubleWithLeftChild (AVLTreeNode<T> root) {
		root.left = this.rotateWithRightChild(root.left);
		return rotateWithLeftChild(root);
	}
	
	private AVLTreeNode<T> rotateWithRightChild (AVLTreeNode<T> node) {
		
		AVLTreeNode<T> temp = node.right;
		node.right = temp.left;
		temp.left = node;
		
		node.height = Math.max(height(node.left), height(node.right)) +1;
		temp.height = Math.max(height(temp.right), node.height) +1;
		
		return temp;
	}
	
	private AVLTreeNode<T> doubleWithRightChild (AVLTreeNode<T> root) {
		root.right = this.rotateWithLeftChild(root.right);
		return rotateWithRightChild(root);
	}
	
	public void preOrderDisplay(AVLTreeNode<T> root) {
	
		if (root != null) {
			System.out.print(root.data + ", ");
			this.preOrderDisplay(root.left);
			this.preOrderDisplay(root.right);
		}
	}

	
	
	
	
	
}
