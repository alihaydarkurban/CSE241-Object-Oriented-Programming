import java.awt.Color;
import java.awt.Graphics;

/**
 * 
 * @author Ali Haydar Kurban
 *
 */
public class PolygonDyn extends Polygon 
{
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	private Point2D [] point2D_Array;
	private	int size; // dynamic array size
	private double alan;
	private double cevre;
	

	@Override
	public void draw(Graphics g)
	{
		int [] array1 = new int [point2D_Array.length];
		int [] array2 = new int [point2D_Array.length];
		for(int i = 0; i < point2D_Array.length; ++i)
		{
			array1[i] = (int)point2D_Array[i].getKoor_x();
			array2[i] = (int)point2D_Array[i].getKoor_y();
		}
		g.setColor(Color.BLACK);
		g.fillPolygon(array1, array2,point2D_Array.length);
	}
	

	@Override
	public void paintComponent(Graphics g)
	{
		super.paintComponent(g);
		draw(g);
	}
	
	/**
	 * 
	 */
	public PolygonDyn()
	{
		//Empty
	}
	
	/**
	 * 
	 * @param rec objesini PolygonDyn ye donusturme constructorudur
	 */
	public PolygonDyn(Rectangle rec)
	{
		int temp_size = 4;
		size = temp_size;
		point2D_Array = new Point2D[size];
		
		Point2D p1 = new Point2D(rec.getCor_x(),rec.getCor_y());
		point2D_Array[0] = p1;
		
		Point2D p2 = new Point2D(rec.getCor_x() + rec.getWidthh() ,rec.getCor_y());
		point2D_Array[1] = p2;
		
		Point2D p3 = new Point2D(rec.getCor_x() + rec.getWidthh(),rec.getCor_y() + rec.getHeightt());
		point2D_Array[2] = p3;
		
		Point2D p4 = new Point2D(rec.getCor_x(),rec.getCor_y() + rec.getHeightt());
		point2D_Array[3] = p4;
		
		alan = rec.area();
		cevre = rec.perimeter();
	}
	
	/**
	 * 
	 * @param tri objesini PolygonDyn ye donusturme constructorudur
	 */
	public PolygonDyn(Triangle tri)
	{
		int temp_size = 3;
		size = temp_size;
		point2D_Array = new Point2D[size];

		Point2D p1 = new Point2D(tri.getCor_x1(),tri.getCor_y1());
		point2D_Array[0] = p1;
		
		Point2D p2 = new Point2D(tri.getCor_x2(),tri.getCor_y2());
		point2D_Array[1] = p2;
		
		Point2D p3 = new Point2D(tri.getCor_x3(),tri.getCor_y3());
		point2D_Array[2] = p3;
	
		alan = tri.area();
		cevre = tri.perimeter();
	}
	
	
	/**
	 * 
	 * @param cir objesini PolygonDyn ye donusturme constructorudur
	 */
	public PolygonDyn(Circle cir)
	{
		int i;
		int temp_size = 100;
		size = temp_size;
		
		point2D_Array = new Point2D[size];

		for(i = 1; i <= size; ++i)
		{
			Point2D p1 = new Point2D(cir.getRadius()*2 + 2 * (cir.getRadius()* Math.sin(((2.0*Math.PI)/100.0)*i)), cir.getRadius()*2 + 2*(cir.getRadius()*Math.cos(((2.0*Math.PI)/100.0)*i)));
			point2D_Array[i-1] = p1;
		}
		alan = cir.area();
		cevre = cir.perimeter();
	}
	
	/**
	 * 
	 * @return size return eder
	 */
	public int getSizeeee()
	{
		return size;
	}
	
	/**
	 * 
	 * @param sizeValue size a set etmek icin kullanilir
	 */
	public void setSize(int sizeValue)
	{
		size = sizeValue;
	}

	/**
	 * Alan methodu
	 */
	public double area()
	{
		return alan;
	}
	
	/**
	 * Cevre methodu
	 */
	public double perimeter()
	{
		return cevre;
	}
	
	/**
	 * Koordinatlari bir arttirir
	 */
	@Override
	public Shape increment()
	{
		for(int i = 0; i < point2D_Array.length; ++ i)
		{
			point2D_Array[i].setKoor_x(point2D_Array[i].getKoor_x() + 1);
			point2D_Array[i].setKoor_y(point2D_Array[i].getKoor_y() + 1);
		}
		return this;
	}
	
	/**
	 * Koordinatlari bir azaltir
	 */
	@Override
	public Shape decrement()
	{
		for(int i = 0; i < point2D_Array.length; ++ i)
		{
			point2D_Array[i].setKoor_x(point2D_Array[i].getKoor_x() - 1);
			point2D_Array[i].setKoor_y(point2D_Array[i].getKoor_y() - 1);
		}
		return this;
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

}