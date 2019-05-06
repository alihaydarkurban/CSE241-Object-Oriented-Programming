import java.awt.Graphics;

/**
 * 
 * @author Ali Haydar Kurban
 *
 */
public interface Shape extends Comparable
{
	public double area();
	public double perimeter();
	public Shape increment();
	public Shape decrement();
	public void draw(Graphics g);
}