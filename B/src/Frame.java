import java.awt.Color;
import java.awt.Dimension;
import java.awt.Font;
import java.awt.Graphics;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.MouseMotionListener;
import java.util.Random;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.SwingUtilities;
import javax.swing.Timer;

public class Frame extends JPanel implements MouseListener, KeyListener, ActionListener, MouseMotionListener {

	private JFrame window;
	private int size;
	AStarPathfinding pathfinding;
	Node startNode, endNode;
	ControlHandler ch;
	Timer timer;
	private boolean showSteps;

	private char currentKey = (char) 0;
	
	public static void main(String[] agrs) {
		Frame frame = new Frame();
	}

	public Frame() {
		size = 55;

		showSteps = true;

		ch = new ControlHandler(this);
		pathfinding = new AStarPathfinding(this, size);
		timer = new Timer(100, this);

		addMouseListener(this);
		addMouseListener(this);
		addMouseMotionListener(this);
		addKeyListener(this);
		setFocusable(true);
		setFocusTraversalKeysEnabled(false);

		window = new JFrame();
		window.setContentPane(this);
		window.setTitle("A* Pathfinding Visualization");
		window.getContentPane().setPreferredSize(new Dimension(1400, 900));
		window.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		window.pack();
		window.setLocationRelativeTo(null);
		window.setVisible(true);

//		ch.addAll();

		this.repaint();
	}

	public void paintComponent(Graphics g) {
		super.paintComponent(g);

		int height = this.getHeight();
		int width = this.getWidth();

		// Draw grid
		g.setColor(Color.lightGray);
		for (int i = 0; i < this.getHeight(); i += size) {
			for (int j = 0; j < this.getWidth(); j += size) {
				g.drawRect(j, i, size, size);
				;
			}
		}

		// Draw all border
		g.setColor(Color.black);
		for (int i = 0; i < pathfinding.getBorder().size(); i++) {
			g.fillRect(pathfinding.getBorder().get(i).getX() + 1, pathfinding.getBorder().get(i).getY() + 1, size - 1,
					size - 1);
		}

		// Draw all open nodes
		for (int i = 0; i < pathfinding.getOpen().size(); i++) {
			Node current = pathfinding.getOpen().get(i);
			g.setColor(Color.green);
			g.fillRect(current.getX() + 1, current.getY() + 1, size - 1, size - 1);
			drawInfo(current, g);
		}

		// Draw all closed node
		for (int i = 0; i < pathfinding.getClose().size(); i++) {
			Node current = pathfinding.getClose().get(i);

			g.setColor(Color.red);
			g.fillRect(current.getX() + 1, current.getY() + 1, size - 1, size - 1);
			drawInfo(current, g);
		}

		// Draw start node
		if (startNode != null) {
			g.setColor(Color.yellow);
			g.fillRect(startNode.getX() + 1, startNode.getY() + 1, size - 1, size - 1);
		}

		// Draw end node
		if (endNode != null) {
			g.setColor(Color.blue);
			g.fillRect(endNode.getX() + 1, endNode.getY() + 1, size - 1, size - 1);
		}

		for (int i = 0; i < pathfinding.getPathList().size(); i++) {
			Node current = pathfinding.getPathList().get(i);

			g.setColor(new Color(32, 233, 255));
			g.fillRect(current.getX() + 1, current.getY() + 1, size - 1, size - 1);

		}

	}

	public void drawInfo(Node current, Graphics g) {
		if (size > 50) {
			g.setFont(new Font("arial", Font.BOLD, 12));
			g.setColor(Color.black);
			g.drawString(Integer.toString(current.getfCost()), current.getX() + 4, current.getY() + 16);
			g.setFont(new Font("arial", Font.PLAIN, 11));
			g.drawString(Integer.toString(current.getgCost()), current.getX() + 4, current.getY() + size - 7);
			g.drawString(Integer.toString(current.gethCost()), current.getX() + size - 26, current.getY() + size - 7);
		}
	}

	public void createMap(MouseEvent e) {

		if (SwingUtilities.isLeftMouseButton(e)) {

			int mouseBoxX = e.getX() - (e.getX() % size);
			int mouseBoxY = e.getY() - (e.getY() % size);

			if (currentKey == 's') {

				if (startNode == null) {
					startNode = new Node(mouseBoxX, mouseBoxY);
				} else {
					startNode.setX(mouseBoxX);
					startNode.setY(mouseBoxY);
				}

				repaint();
			} else if (currentKey == 'e') {

				if (endNode == null) {
					endNode = new Node(mouseBoxX, mouseBoxY);
				} else {
					endNode.setX(mouseBoxX);
					endNode.setY(mouseBoxY);
				}

				repaint();
			} else {

				Node newBorder = new Node(mouseBoxX, mouseBoxY);
				pathfinding.addBorder(newBorder);

				repaint();
			}
		} else if (SwingUtilities.isRightMouseButton(e)) {
			int mouseBoxX = e.getX() - (e.getX() % size);
			int mouseBoxY = e.getY() - (e.getY() % size);

			// If 's' is pressed remove start node
			if (currentKey == 's') {
				if (startNode != null && mouseBoxX == startNode.getX() && startNode.getY() == mouseBoxY) {
					startNode = null;
					repaint();
				}
			}
			// If 'e' is pressed remove end node
			else if (currentKey == 'e') {
				if (endNode != null && mouseBoxX == endNode.getX() && endNode.getY() == mouseBoxY) {
					endNode = null;
					repaint();
				}
			}
			// Otherwise, remove wall
			else {
				int Location = pathfinding.searchBorder(mouseBoxX, mouseBoxY);
				if (Location != -1) {
					pathfinding.removeBorder(Location);
				}
				repaint();
			}
		}

	}

	public void start() {
		if (startNode != null && endNode != null) {
			pathfinding.start(startNode, endNode);
			timer.setDelay(300);
			timer.start();
		} else {
			System.out.println("ERROR: Needs start and end points to run.");
		}
	}

	@Override
	public void keyPressed(KeyEvent arg0) {
		char key = arg0.getKeyChar();
		currentKey = key;
	}

	@Override
	public void keyReleased(KeyEvent arg0) {
		currentKey = (char) 0;
	}

	@Override
	public void keyTyped(KeyEvent arg0) {
		// TODO Auto-generated method stub

	}

	@Override
	public void mouseClicked(MouseEvent arg0) {
		createMap(arg0);
	}

	@Override
	public void mouseEntered(MouseEvent arg0) {
		// TODO Auto-generated method stub

	}

	@Override
	public void mouseExited(MouseEvent arg0) {
		// TODO Auto-generated method stub

	}

	@Override
	public void mousePressed(MouseEvent arg0) {
		// TODO Auto-generated method stub

	}

	@Override
	public void mouseReleased(MouseEvent arg0) {
		// TODO Auto-generated method stub

	}

	@Override
	public void actionPerformed(ActionEvent arg0) {

		if (pathfinding.isRunning()) {
			pathfinding.findPath(pathfinding.getParentNode());
		}

		if (arg0.getActionCommand() != null) {
			if (arg0.getActionCommand().equals("run") && !pathfinding.isRunning()) {
				start();
			} else if (arg0.getActionCommand().equals("reset")) {
				pathfinding.reset();
				startNode = null;
				endNode = null;
			}
		}

		repaint();
	}

	@Override
	public void mouseDragged(MouseEvent arg0) {
		createMap(arg0);

	}

	@Override
	public void mouseMoved(MouseEvent arg0) {
		// TODO Auto-generated method stub

	}

	public boolean showSteps() {
		// TODO Auto-generated method stub
		return showSteps;
	}

}
