import java.util.Stack;

public class client {

	public static TreeNode createBinaryTree() {
		
		TreeNode rootNode = new TreeNode(40);
		TreeNode node20 = new TreeNode(20);
		TreeNode node10 = new TreeNode(10);
		TreeNode node30 = new TreeNode(30);
		TreeNode node60 = new TreeNode(60);
		TreeNode node50 = new TreeNode(50);
		TreeNode node70 = new TreeNode(70);
		
		rootNode.left = node20;
		rootNode.right = node60;
		
		node20.left = node10;
		node20.right = node30;
		
		node60.left = node50;
		node60.right = node70;
		
		return rootNode;
		
	}
	
	// recursive
	public static void inOrderRecursive (TreeNode node) {
		
		if (node == null) 
			return;
		
		inOrderRecursive(node.left);
		System.out.print(node.data + " ");
		inOrderRecursive(node.right);
	}
	
	// iterative
	public static void inOrderIterative (TreeNode root) {
		
        Stack<TreeNode> stack = new Stack<TreeNode>();
        
        TreeNode node = root;
         
        while (node != null) {
            stack.push(node);
            node = node.left;
        }
         
        while (stack.size() > 0) {
           
            node = stack.pop();
            System.out.print(node.data + " ");
            
            if (node.right != null) {
                node = node.right;
                 
                while (node != null) {
                    stack.push(node);
                    node = node.left;
                }
            }
        }	
	}
	
	public static void main (String[] args) {
		
		TreeNode root = createBinaryTree();
		
		System.out.print("Recursive: ");
		inOrderRecursive(root);
		
		System.out.print("\nIterative: ");
		inOrderIterative(root);
	}
	
	
}
