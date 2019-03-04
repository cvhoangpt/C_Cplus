
public class Node {

	private int x, y, hCost, gCost, fCost;
	private Node parent;
	
	public Node(int x, int y) {
		this.x = x;
		this.y = y;
	}

	public int getX() {
		return x;
	}

	public void setX(int x) {
		this.x = x;
	}

	public int getY() {
		return y;
	}

	public void setY(int y) {
		this.y = y;
	}

	public int gethCost() {
		return hCost;
	}

	public void sethCost(int hCost) {
		this.hCost = hCost;
	}

	public int getgCost() {
		return gCost;
	}

	public void setgCost(int gCost) {
		this.gCost = gCost;
	}

	public int getfCost() {
		return fCost;
	}

	public void setfCost(int fCost) {
		this.fCost = fCost;
	}

	public Node getParent() {
		return parent;
	}

	public void setParent(Node parent) {
		this.parent = parent;
	}
	
	public static boolean isEqual(Node node1, Node node2) {
		if((node1.getX() == node2.getX()) && (node1.getY() == node2.getY())) {
			return true;
		}
		return false;
	}
	
	public String toString() {
		return "X:" + x + ", Y:" +y;
	}
	
}
