
import java.util.LinkedList;
import java.util.Queue; 

public class test 
{
	static class Node
	{
	    int data;
	    Node left;
	    Node right;

	    Node(int data){
	        this.data = data;
	        left = null;
	        right =null;
	    }
	}

	static int depthOfTree(Node root, int d) {
	  if(root == null) {
	    return d;
	  }
	  int left = d;
	  int right = d;
	  if(root.left != null) {
	    left = depthOfTree(root.left, d+1);
	  }
	  if(root.right != null) {
	    right = depthOfTree(root.right, d+1);
	  }
	  return Math.max(left, right);
	}

	static void printLevelOrder(Node root, int depth)
	{
	    if(root == null)
	        return;

	    Queue<Node> q =new LinkedList<Node>();

	    q.add(root);            
	    while(true)
	    {               
	        int nodeCount = q.size();
	        if(nodeCount == 0)
	            break;
	        for(int i=0; i<depth; i++) {
	          System.out.print("  ");
	        }
	        while(nodeCount > 0)
	        {    
	            Node node = q.peek();
	            System.out.print("("+node.data + ")");

	            q.remove();

	            if(node.left != null)
	                q.add(node.left);
	            if(node.right != null)
	                q.add(node.right);

	            if(nodeCount>1){
	               System.out.print(", ");
	            }
	            nodeCount--;    
	        }
	        depth--;
	        System.out.println();
	    }
	}       
	public static void main(String[] args) 
	{           
	    Node root = new Node(6);
	    root.left = new Node(3);
	    root.right = new Node(2);
	    root.left.left = new Node(8);
	    root.left.right = new Node(9);
	    root.right.right = new Node(-2);
	    root.right.left = new Node(3);
	    int d = depthOfTree(root, 1);
	    //System.out.println(d);
	    printLevelOrder(root, d);    
	   }

}
