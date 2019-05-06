import java.awt.Color;
import java.awt.Graphics;

import javax.swing.JPanel;

/**
 * 
 * @author Ali Haydar Kurban
 *
 */
public class Rectangle extends JPanel implements Shape
{
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	private double width;
	private double height;
	private double cordinate_x;
	private double cordinate_y;
	String type;
	
	/**
	 * No parameter constructor
	 */
	public Rectangle()
	{
		width = 500.0;
		height = 600.0;
		cordinate_x = 0.0;
		cordinate_y = 0.0;
	}
	/**
	 * Gelen degiskenleri privattakilere atama
	 * @param temp_width width atamasi icin kullanilir
	 * @param temp_height height atamasi icin kullanilir 
	 */
	public Rectangle(double temp_width, double temp_height)
	{
		//Throw excepttion
		if(temp_width <= 0 || temp_height <= 0)
			 throw new IllegalArgumentException("Illegal Number for Rectangle\n");
		else
		{
			width = temp_width;
			height = temp_height;
			cordinate_x = 0.0;
			cordinate_y = 0.0;
		}
	}
	
	/**
	 * Gelen degiskenleri privattakilere atama
	 * @param temp_width width atamasi icin kullanilir
	 * @param temp_height height atamasi icin kullanilir 
	 * @param temp_cordinate_x cordinate_x atamasi icin kullanilir
	 * @param temp_cordinate_y cordinate_y atamasi icin kullanilir
	 */
	public Rectangle(double temp_width, double temp_height, double temp_cordinate_x, double temp_cordinate_y)
	{
		//Throw excepttion
		if(temp_width <= 0 || temp_height <= 0 || temp_cordinate_x < 0 || temp_cordinate_y < 0)
			 throw new IllegalArgumentException("Illegal Number for Rectangle\n");
		width = temp_width;
		height = temp_height;
		cordinate_x = temp_cordinate_x;
		cordinate_y = temp_cordinate_y;
	}
	
	/**
	 * 
	 * @return width eder
	 */
	public double getWidthh()
	{
		return width;
	}
	/**
	 * 
	 * @return height return eder
	 */
	public double getHeightt()
	{
		return height;
	}
	/**
	 * 
	 * @return cordinate_x return eder
	 */
	public double getCor_x()
	{
		return cordinate_x;
	}
	
	/**
	 * 
	 * @return cordinate_y reurn eder
	 */
	public double getCor_y()
	{
		return cordinate_y;
	}
	
	/**
	 * 
	 * @param widthValue width set etme icin kullanilir
	 */
	public void setWidth(double widthValue)
	{
		width = widthValue;
	}
	/**
	 * 
	 * @param heightValue height set etme icin kullanilir
	 */
	public void setHeight(double heightValue)
	{
		height = heightValue;
	}
	/**
	 * 
	 * @param cordinate_xValue cordinate_x set etme icin kullanilir
	 */
	public void setCor_x(double cordinate_xValue)
	{
		cordinate_x = cordinate_xValue;
	}
	
	/**
	 * 
	 * @param cordinate_yValue cordinate_y set etme icin kullanilir
	 */
	public void setCor_y(double cordinate_yValue)
	{
		cordinate_y = cordinate_yValue;
	}
	
	/**
	 * Cevre fanksiyonu
	 */
	@Override
	public double perimeter()
	{
		return(2 * (width + height)); 
	}
	
	/**
	 * Alan fonksiyonu
	 */
	@Override
	public double area()
	{
		return(width * height);
	}
	
	/**
	 * Koordinatlari bir arttirma
	 */
	@Override
	public Shape increment()
	{
		cordinate_x = cordinate_x + 1;
		cordinate_y = cordinate_y + 1;
		return this;
	}
	
	/**
	 * Koordinatlari bir azaltma
	 */
	@Override
	public Shape decrement()
	{
		cordinate_x = cordinate_x - 1;
		cordinate_y = cordinate_y - 1;
		return this;
	}
	
	/**
	 * 
	 * @return type return etme
	 */
	public String getType()
	{
		return type;
	}
	/**
	 * 
	 * @param typeValue type set etme icin kullanilir
	 */
	public void setType(String typeValue)
	{
		type = typeValue;
	}
	/**
	 * Rectangle cizdirme izlemi
	 */
	@Override
	public void draw(Graphics g)
	{
		if(this.getType() == "RECTANGLE") //Buyuk sekil cizdirirken renk beklirmek icin
		{
			g.setColor(Color.RED);
	        g.fillRect((int)this.getCor_x(),(int)this.getCor_y(),(int)this.getWidthh(),(int)this.getHeightt());
		}
		if(this.getType() == "rectangle") //Buyuk sekil cizdirirken renk beklirmek icin
		{
			g.setColor(Color.GREEN);
	        g.fillRect((int)this.getCor_x(),(int)this.getCor_y(),(int)this.getWidthh(),(int)this.getHeightt());
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
	public int compareTo(Object arg0) 
	{
		if(((Shape) arg0).area() > this.area())
			return -1;
		if(((Shape) arg0).area() < this.area())
			return 1;
		return 0;
	}
}