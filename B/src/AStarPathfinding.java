import java.util.ArrayList;
import java.util.Collections;

public class AStarPathfinding {

	private int size;
	private Frame frame;
	private Node startNode, endNode, parentNode;
	private ArrayList<Node> border, open, close, path;
	private boolean running, complete, noPath;
	
	public AStarPathfinding(Frame frame, int size) {
		this.size = size;
		this.frame = frame;
		
		running = false;
		complete = false;
		
		open = new ArrayList<>();
		border = new ArrayList<>();
		close = new ArrayList<>();
		path = new ArrayList<>();
	}
	
	public void start(Node s, Node e) {
		running = true;
		startNode = s;
		startNode.setgCost(0);
		endNode = e;
		
		parentNode = s;
		
		//Add startNode to closeList
		addClose(startNode);
	}
		
public void findPath(Node parent) {
		
		Node openNode = null;
		
		System.out.println("Finding path...");
		
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				
				if(i==1 && j==1) {
					continue;
				}
				
				//find x, y of all node around parent
				int possibleX = (parent.getX() - size) + size*i;
				int possibleY = (parent.getY() - size) + size*j;
				
				System.out.println("X:" + possibleX + "Y:" + possibleY);
				
				int crossBorderX = parent.getX() + (possibleX - parent.getX());
				int crossBorderY = parent.getY() + (possibleY - parent.getY());

				// Disables ability to cut corners around borders
				if (searchBorder(crossBorderX, parent.getY()) != -1
						|| searchBorder(parent.getX(), crossBorderY) != -1) {
					continue;
				}

				
				//calculate all the value of the node
				calculateNodeValues(possibleX, possibleY, openNode, parent);
			}
		}
		
		parent = lowestFCostNode();
		
		if(parent == null) {
			System.out.println("No Path");
			noPath = true;
			running = false;
			frame.repaint();
			return;
		}
		
		if(Node.isEqual(parent, endNode)) {
			endNode.setParent(parent.getParent());
			System.out.println("Complete");
			connectPath();
			running = false;
			complete = true;
			frame.repaint();
			return;
		}
		
		removeOpen(parent);
		
		addClose(parent);
		
		parentNode = parent;
		
	}
	
	public void connectPath() {
		if (getPathList().size() == 0) {
			Node parentNode = endNode.getParent();
			
			int index = 0;
			System.out.println(index);
			while (!Node.isEqual(parentNode, startNode)) {
				addPath(parentNode);
				index ++;
				for (int i = 0; i < getClose().size(); i++) {
					Node current = getClose().get(i);

					if (Node.isEqual(current, parentNode)) {
						parentNode = current.getParent();
						break;
					}
				}
			}
			reverse(getPathList());
		}

	}
	
	public void calculateNodeValues(int possibleX, int possibleY, Node openNode, Node parent) {
		
		if (possibleX < 0 | possibleY < 0 | possibleX >= frame.getWidth() | possibleY >= frame.getHeight()) {
			return;
		}
		
		if (searchBorder(possibleX, possibleY) != -1 | searchClosed(possibleX, possibleY) != -1
				| searchOpen(possibleX, possibleY) != -1) {
			return;
		}
		
		openNode = new Node(possibleX, possibleY);
		
		openNode.setParent(parent);
		
		int diagonalCost = (int)Math.sqrt(2*size*size);
		
		//Calculate the gCost
		int GxCost = openNode.getX() - parent.getX();
		int GyCost = openNode.getY() - parent.getY();
		int gCost =parent.getgCost();
		
		if(GxCost != 0 && GyCost !=0) {
			gCost += diagonalCost;
		}else {
			gCost += size;
		}
		
		openNode.setgCost(gCost);
		
		//Calculate the hCost
		
		System.out.println("Endnode:" + endNode);
		System.out.println("OpenNdoe: " + openNode);
		
		int HxDiff = Math.abs(endNode.getX() - openNode.getX());
		int HyDiff = Math.abs(endNode.getY() - openNode.getY());
		int hCost = (int)Math.sqrt(HxDiff*HxDiff + HyDiff*HyDiff);
		
		openNode.sethCost(hCost);
		
		int fCost = gCost + hCost;
		
		openNode.setfCost(fCost);
		
		System.out.println("gCost: " + gCost);
		System.out.println("hCost: " + hCost);
		System.out.println("fCost: " + fCost);
		
		addOpen(openNode);
	}

	
	public Node lowestFCostNode() {
		if(open.size()>0) {
			// Bubble sort the open list
			Node temp = null;
			for (int i = 0; i < open.size(); i++) {
				for (int j = 0; j < open.size()- i -1; j++) {
					if (open.get(j).getfCost() > open.get(j + 1).getfCost()) {
						temp = open.get(j);
						open.set(j, open.get(j+1));
						open.set(j +1, temp);				}
				}
			}
			// Return the node with the lowest fCost
			return open.get(0);
		}
		
		return null;
	}
	//Add node to open node list
	public void addOpen(Node n) {
		if(!checkDuplicateOpenNode(n)) {
			open.add(n);
		}
	}
	
	//remove the node from openlist
	public void removeOpen(Node node) {
		for (int i = 0; i < open.size(); i++) {
			if (node.getX() == open.get(i).getX() && node.getY() == open.get(i).getY()) {
				open.remove(i);
			}
		}
	}

	public boolean checkDuplicateOpenNode(Node n) {
		for (int i = 0; i < open.size(); i++) {
			if (n.getX() == open.get(i).getX() && n.getY() == open.get(i).getY()) {
				return true;
			}
		}
		return false;
	}
	
	public boolean checkDuplicateCloseNode(Node n) {
		for (int i = 0; i < close.size(); i++) {
			if (n.getX() == close.get(i).getX() && n.getY() == close.get(i).getY()) {
				return true;
			}
		}
		return false;
	}
	
	//add node to close node list
	public void addClose(Node n) {
		if(!checkDuplicateCloseNode(n)) {
			close.add(n);
		}
	}
	
	public void addBorder(Node n) {
		if(!border.contains(n)) {
			border.add(n);
		}
	}
	
	public int searchClosed(int xSearch, int ySearch) {
		int Location = -1;

		for (int i = 0; i < close.size(); i++) {
			if (close.get(i).getX() == xSearch && close.get(i).getY() == ySearch) {
				Location = i;
				break;
			}
		}
		return Location;
	}
	
	public int searchOpen(int xSearch, int ySearch) {
		int Location = -1;

		for (int i = 0; i < open.size(); i++) {
			if (open.get(i).getX() == xSearch && open.get(i).getY() == ySearch) {
				Location = i;
				break;
			}
		}
		return Location;
	}
	
	public int searchBorder(int x, int y) {
		for(int i=0; i<border.size(); i++) {
			if(border.get(i).getX()==x && border.get(i).getY() == y) {
				return i;
			}
		}
		return -1;
	}
	
	public void removeBorder(int location) {
		border.remove(location);
	}
	
	public ArrayList<Node> getBorder() {
		return border;
	}

	public void setBorder(ArrayList<Node> border) {
		this.border = border;
	}

	public ArrayList<Node> getOpen() {
		return open;
	}

	public void setOpen(ArrayList<Node> open) {
		this.open = open;
	}

	public ArrayList<Node> getClose() {
		return close;
	}

	public void setClose(ArrayList<Node> close) {
		this.close = close;
	}

	public boolean isRunning() {
		return running;
	}

	public void setRunning(boolean running) {
		this.running = running;
	}

	public boolean isComplete() {
		return complete;
	}

	public void setComplete(boolean complete) {
		this.complete = complete;
	}

	public boolean isNoPath() {
		return noPath;
	}

	public void setNoPath(boolean noPath) {
		this.noPath = noPath;
	}

	public ArrayList<Node> getPathList(){
		return path;
	}
	
	public void addPath(Node n) {
		if (path.size() == 0) {
			path.add(n);
		} else {
			path.add(n);
		}
	}
	
	public void reset() {
		while(open.size() > 0) {
			open.remove(0);
		}
		
		while(close.size() > 0) {
			close.remove(0);
		}
		
		while(path.size() > 0) {
			path.remove(0);
		}
		
		while(border.size() >0) {
			border.remove(0);
		}
		
		startNode = null;
		endNode = null;
		
		noPath = false;
		running = false;
		complete = false;
	}
	
	public Node getParentNode() {
		return parentNode;
	}
	
	public void reverse(ArrayList<Node> list) {
		Collections.reverse(list);
	}
	
}
