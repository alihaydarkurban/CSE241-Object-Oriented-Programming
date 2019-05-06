import java.awt.Color;
import java.awt.Graphics;

import javax.swing.JPanel;
/**
 * 
 * @author Ali Haydar Kurban
 *
 */
public class Circle extends JPanel implements Shape 
{
	
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	/**
	 * Raius degiskeni
	 */
	private	double radius;
	/**
	 * center_x degiskeni
	 */
	private double center_x;
	/**
	 * center_y degiskeni
	 */
	private double center_y;
	/**
	 * type degiskeni buyuk sekil kucuk sekil ayirt edebilmek icin
	 */
	String type;

	
	/**
	 * No parameter constructor
	 */
	public Circle()
	{
		radius = 500.0; 
		center_x = 500.0;
		center_y = 500.0;
	}
	
	/**
	 * Gelen radius degerini privatetaki radiusa atar
	 * @param temp_radius radius a atamak yapmak icin kullanilir
	 */
	public Circle(double temp_radius)
	{
		//Throw excepttion
		if(temp_radius <=0 )
			throw new IllegalArgumentException("Illegal Number for Circle\n");
		else
			radius = temp_radius;
	}
	
	/**
	 * Gelen degerleri private degiskenlere atar
	 * @param temp_radius radius a atama yapmak icin kullanilir
	 * @param cX center_x atama yapmak icin kullanilir
	 * @param cY center_y atama yapmak icin kullanilir
	 */
	public Circle(double temp_radius, double cX, double cY)
	{
		//Throw excepttion
		if(temp_radius <= 0 || cX < 0 || cY < 0)
		{
			throw new IllegalArgumentException("Illegal Number for Circle\n");
		}
		else
		{
			radius = temp_radius;
			center_x = cX;
			center_y = cY;	
		}
		
	}
	
	/**
	 * 
	 * @return radius  u return eder
	 */
	public double getRadius()
	{
		return radius; 
	}
	/**
	 * 
	 * @return center_x return eder
	 */
	public double getCenter_x()
	{
		return center_x;
	}
	
	/**
	 * 
	 * @return center_y return eder
	 */
	public double getCenter_y()
	{
		return center_y;
	}
	
	/**
	 * 
	 * @param radiusValue radius' u set etme
	 */
	public void setRadius(double radiusValue)
	{
		radius = radiusValue; 
	}
	
	/**
	 * 
	 * @param center_xValue conter_x' i set etme
	 */
	public void setCenter_x(double center_xValue)
	{
		center_x = center_xValue;
	}
	
	/**
	 * 
	 * @param center_yValue center_y' i set etme
	 */
	public void setCenter_y(double center_yValue)
	{
		center_y = center_yValue;
	}

	/**
	 * Cevre fonksiyonu
	 */

	@Override
	public double perimeter()
	{
		return(2 * Math.PI * radius);
	}
	
	/**
	 * Alan fonksiyonu
	 */
	@Override
	public double area()
	{
		return(Math.PI * radius * radius);
	}
	
	/**
	 * Koordinatlari arttirma
	 */
	@Override
	public Shape increment()
	{
		center_x = center_x + 1;
		center_y = center_y + 1;
		return this;
	}
	
	/**
	 * Koordinatlari azaltma
	 */
	@Override
	public Shape decrement()
	{
		center_x = center_x - 1;
		center_y = center_y - 1;
		return this;
	}
	
	/**
	 * 
	 * @return type return eder(buyuk sekil kucuk sekil icin)
	 */
	public String getType()
	{
		return type;
	}
	
	/**
	 * 
	 * @param typeValue tyope' a set etme icin kullanilir
	 */
	public void setType(String typeValue)
	{
		type = typeValue;
	}
	
	/**
	 * Circle cizdirme islemi
	 */
	@Override
	public void draw(Graphics g)
	{
		if(this.getType() == "CIRCLE") //Buyuk sekil cizdirirken renk beklirmek icin
		{
			g.setColor(Color.RED);
	        g.fillOval((int)this.getCenter_x(),(int)this.getCenter_y(),(int)this.getRadius()*2,(int)this.getRadius()*2);
		}
		if(this.getType() == "circle") //Buyuk sekil cizdirirken renk beklirmek icin
		{
			g.setColor(Color.GREEN);
	        g.fillOval((int)this.getCenter_x(),(int)this.getCenter_y(),(int)this.getRadius()*2,(int)this.getRadius()*2);
		}
	}
	
	/**
	 * JPanle in override edilmis fonksiyonu draw fonksiyonunu cagiririz
	 */
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
	public int compareTo(Object arg0) {
		if(((Shape) arg0).area() > this.area())
			return -1;
		if(((Shape) arg0).area() < this.area())
			return 1;
		
		return 0;
	}
}