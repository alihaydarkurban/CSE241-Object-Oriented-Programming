import java.awt.Color;
import java.awt.Graphics;
import java.util.ArrayList;

/**
 * 
 * @author Ali Haydar Kurban
 *
 */
public class PolygonVect extends Polygon 
{
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	private ArrayList<Point2D> polygonVect_Array;
	private double alan;
	private double cevre;
	public PolygonVect()
	{
		//Empty
	}
	
	/**
	 * 
	 * @param rec objesini PolygonVect ye donusturme constructorudur
	 */
	public PolygonVect(Rectangle rec)
	{
		polygonVect_Array = new ArrayList<Point2D>();
		
		Point2D p1 = new Point2D(rec.getCor_x(),rec.getCor_y());
		polygonVect_Array.add(p1);
		
		Point2D p2 = new Point2D(rec.getCor_x() + rec.getWidthh() ,rec.getCor_y());
		polygonVect_Array.add(p2);
		
		Point2D p3 = new Point2D(rec.getCor_x() + rec.getWidthh(),rec.getCor_y() + rec.getHeightt());
		polygonVect_Array.add(p3);
		
		Point2D p4 = new Point2D(rec.getCor_x(),rec.getCor_y() + rec.getHeightt());
		polygonVect_Array.add(p4);
		
		alan = rec.area();
		cevre = rec.perimeter();
	}
		
	/**
	 * 
	 * @param tri objesini PolygonVect ye donusturme constructorudur
	 */
	public PolygonVect(Triangle tri)
	{
		polygonVect_Array = new ArrayList<Point2D>();
		
		Point2D p1 = new Point2D(tri.getCor_x1(),tri.getCor_y1());
		polygonVect_Array.add(p1);
		
		Point2D p2 = new Point2D(tri.getCor_x2(),tri.getCor_y2());
		polygonVect_Array.add(p2);
		
		Point2D p3 = new Point2D(tri.getCor_x3(),tri.getCor_y3());
		polygonVect_Array.add(p3);
		
		alan = tri.area();
		cevre = tri.perimeter();
				
	}
	/**
	 * 
	 * @param cir objesini PolygonVect ye donusturme constructorudur
	 */
	public PolygonVect(Circle cir)
	{
		polygonVect_Array = new ArrayList<Point2D>();
		int i;
		int temp_size = 100;

		for(i = 1; i <= temp_size; ++i)
		{
			Point2D p1 = new Point2D(cir.getRadius()*2+ 2* (cir.getRadius()*Math.sin(((2.0*Math.PI)/100.0)*i)), cir.getRadius()*2+ 2*(cir.getRadius()*Math.cos(((2.0*Math.PI)/100.0)*i)));
			polygonVect_Array.add(p1);
		}
		
		alan = cir.area();
		cevre = cir.perimeter();
	}
	
	/**
	 * Alan fonksiyonu
	 */
	public double area()
	{
		return alan;
	}
	/**
	 * Cevre fonksiyonu
	 */
	public double perimeter()
	{
		return cevre;
	}
	

	@Override
	public void draw(Graphics g)
	{
		int [] array1 = new int [polygonVect_Array.size()];
		int [] array2 = new int [polygonVect_Array.size()];
		for(int i = 0; i < polygonVect_Array.size(); ++i)
		{
			array1[i] = (int)(polygonVect_Array.get(i)).getKoor_x();
			array2[i] = (int)(polygonVect_Array.get(i)).getKoor_y();
		}
		g.setColor(Color.BLUE);
		g.fillPolygon(array1, array2,polygonVect_Array.size());
	}

	@Override
	public void paintComponent(Graphics g)
	{
		super.paintComponent(g);
		draw(g);
	}

	/**
	 * Alanlarin kiyaslanmasina gore compareTo fonksiyonunun override hali
	 */
	@Override
	public int compareTo(Object arg0)
	{
		if(((Shape) arg0).area() > this.area())
			return -1;
		if(((Shape) arg0).area() < this.area())
			return 1;
		return 0;
	}
	/**
	 * 
	 */
	@Override
	public Shape increment()
	{
		return this;
	}
	/**
	 * 
	 */
	@Override
	public Shape decrement()
	{
		return null;
	}
}