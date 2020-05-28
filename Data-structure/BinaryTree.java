import java.util.*;

class Node{
	int value;
	Node left;
	Node right;

	public Node(int value){
		this.value = value;
		left = null;
		right = null;
	}
}
public class BinaryTree{
	Node root; // This is a root node of Tree
	
	public Node addRecursive(Node current, int value){
		if(current == null) return new Node(value);
		if(value < current.value){
				current.left = addRecursive(current.left, value);
		} else if(value > current.value){
			  current.right = addRecursive(current.right, value);
		}
		return current;
	}
	
	public void add(int value){
		root = addRecursive(root, value);
	}

	// Traverse tree
	public void NLR(Node node){
		if(node != null){
			System.out.println(node.value);
			NLR(node.left);
			NLR(node.right);
		}
	}
	public void LRN(Node node){
		if(node != null){
			LRN(node.left);
			LRN(node.right);
			System.out.println(node.value);
		}
	}
	// Find a element
	public int findNode(Node current, int x){
		if(current != null) {

			if(current.value == x){
				return current.value;
			}
			if(x < current.value) return findNode(current.left, x);
			if(x > current.value) return findNode(current.right, x);
		}
		return -1;
	}
	// Delete element
	public Node deleteElement(Node current, int value){
		if(current == null) return null;
		if(value == current.value) {
			// Node is leaf
			if(current.left == null && current.right == null) return null;
			// Node is one child
			else if(current.right == null) {
				return current.left;
			}
			else if(current.left == null){
				return current.right;
			}
			// Node have two child
			int smallestValue = findSmallestValue(current.right);
			current.value = smallestValue;
			current.right = deleteElement(current.right, smallestValue);
			return current;
		}
		if(value > current.value){
			current.right = deleteElement(current.right, value);
		}
		if(value < current.value){
			current.left = deleteElement(current.left, value);
		}
		return current;
	}
	private int findSmallestValue(Node root){
		return root.left == null ? root.value : findSmallestValue(root.left);
	}
	public void delete(int value) {
		root = deleteElement(root, value);
	}
	public void traverseLevelOrder(){
		if(root == null) return;
		Queue<Node> nodes = new LinkedList<>();
		nodes.add(root);
		while(!nodes.isEmpty()){
			Node node = nodes.remove();
			System.out.print(" " + node.value);
			if(node.left != null) {
				nodes.add(node.left);
			}
			if(node.right != null){
				nodes.add(node.right);
			}
		}
	}
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		BinaryTree tree = new BinaryTree();
		
		tree.add(6);
		tree.add(4);
		tree.add(3);
		tree.add(5);
		tree.add(8);
		tree.add(7);
		tree.add(10);
		tree.add(9);
	//	tree.add(11);

		tree.NLR(tree.root);	
		tree.delete(10);
		//tree.delete(10);
		System.out.println("After deleted");
		tree.NLR(tree.root);
		//tree.LRN(tree.root);
		System.out.println();
		tree.traverseLevelOrder();
		//int value;
		//value = sc.nextInt();
		//int result = tree.findNode(tree.root, value);
		//System.out.println("Find element: " + result);
	}
}

