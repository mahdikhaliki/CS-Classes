/**
 * The BST class is a binary search tree data structure that uses a Node class as its nodes.
 *
 * @author Mahdi Khaliki
 */

public class BST {
    private Node root;

    /**
     * The BST constructor initializes the root to be null upon object construction.
     */
    public BST() {
        root = null;
    }

    /**
     * Adds a Person object to the binary search tree.
     *
     * @param (Person person) (A Person object that needs to be added to the BST)
     */
    public void add(Person person) {
        Node traverse = root;
        Node parent = null;

        while(traverse != null) {
            parent = traverse;
            if(person.compareTo(traverse.val) < 0)
                traverse = traverse.left;
            else
                traverse = traverse.right;
        }

        if(parent == null)
            root = new Node(person, null, null);
        else if(person.compareTo(parent.val) < 0)
            parent.left = new Node(person, null, null);
        else
            parent.right = new Node(person, null, null);
    }

    /**
     * Goes through the BST and forms a String representing the inorder sequence.
     *
     * @return (String containing elements in the inorder sequence where each element is on a new line)
     */
    public String inorderString() {
        return inorderHelper(root, new StringBuilder());
    }

    /**
     * A helper function for inorderString(). This is where the actual inorder logic takes place.
     *
     * @return (String containing elements in the inorder sequence where each element is on a new line)
     */
    public String inorderHelper(Node root, StringBuilder inorder) {
        if (root == null)
            return inorder.toString();

        inorderHelper(root.left, inorder);
        inorder.append(root.val+"\n");
        inorderHelper(root.right, inorder);

        return inorder.toString().trim();
    }

    /**
     * The Node class contains a val (Person object), left, and right Nodes that are the children of the root Node.
     */
    static class Node {
        public Person val;
        public Node left, right;

        /**
         * The Node constructor initializes a node with the parameters passed in.
         */
        public Node(Person val, Node left, Node right) {
            this.val = val;
            this.left = left;
            this.right = right;
        }
    }

}
