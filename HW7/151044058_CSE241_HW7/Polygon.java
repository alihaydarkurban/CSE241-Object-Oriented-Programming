import javax.swing.JPanel;

/**
 * 
 * @author Ali Haydar Kurban
 *
 */
public abstract class Polygon extends JPanel implements Shape 
{
	
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;

	/**
	 * 
	 * @author Ali Haydar Kurban 
	 * 	
	 */
	public class Point2D
	{
		public Point2D()
		{
			//Empty
		}
		
		public Point2D(double x, double y)
		{
			koor_x = x;
			koor_y = y;
		}
		public void setKoor_x(double koor_xValue)
		{
			koor_x = koor_xValue;
		}
		public void setKoor_y(double koor_yValue)
		{
			koor_y = koor_yValue;
		}
		public double getKoor_x()
		{
			return koor_x;
		}
		public double getKoor_y()
		{
			return koor_y;
		}
		
		protected double koor_x;
		protected double koor_y;
	}

}