import java.awt.Color;
import java.awt.Graphics;

import javax.swing.JPanel;

/**
 * 
 * @author Ali Haydar Kurban
 *
 */
public class Triangle extends JPanel implements Shape  
{
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	private double length;
	private double cordinate_x1, cordinate_x2, cordinate_x3;
	private double cordinate_y1, cordinate_y2, cordinate_y3;
	String type;
	
	/**
	 * No parameter constructor
	 */
	public Triangle()
	{
		length = 600.0;
		cordinate_x1 = 300.0;
		cordinate_x2 = 0.0;
		cordinate_x3 = 600.0;
		cordinate_y1 = 0.0;
		cordinate_y2 = (600.0 * Math.sqrt(3.0) / 2.0); 
		cordinate_y3 = (600.0 * Math.sqrt(3.0) / 2.0);
	}
	
	/**
	 * Gelen degiskeni privattaki degiskene atar
	 * @param temp_length length icin kullanilir
	 */
	public Triangle(double temp_length)
	{
		//Throw excepttion
		if(temp_length <= 0)
			throw new IllegalArgumentException("Illegal Number for Triangle\n");
		else
			length = temp_length;
	}
	
	/**
	 * Gelen degiskenleri privattaki degiskenlere atar
	 * @param temp_length length icin kullanilir
	 * @param x1 cordinate_x1 icin kullanilir
	 * @param x2 cordinate_x2 icin kullanilir
	 * @param x3 cordinate_x3 icin kullanilir
	 * @param y1 cordinate_y1 icin kullanilir
	 * @param y2 cordinate_y2 icin kullanilir
	 * @param y3 cordinate_y3 icin kullanilir
	 */
	public Triangle(double temp_length, double x1, double x2, double x3, double y1, double y2, double y3)
	{
		//Throw excepttion
		if(temp_length <= 0 || x1 < 0 || x2 < 0 || x3 < 0 || y1 < 0 || y2 < 0 || y3 < 0)
		{
			throw new IllegalArgumentException("Illegal Number for Triangle\n");
		}
		else
		{
			length = temp_length;
			cordinate_x1 = x1;
			cordinate_x2 = x2;
			cordinate_x3 = x3;
			cordinate_y1 = y1;
			cordinate_y2 = y2;
			cordinate_y3 = y3;
		}
	}

	/**
	 * 
	 * @return length return eder
	 */
	public double getLength()
	{
		return length;
	}
	
	/**
	 * 
	 * @return cordinate_x1 return eder
	 */
	public double getCor_x1()
	{
		return cordinate_x1;
	}
	
	/**
	 * 
	 * @return cordinate_x2 return eder
	 */
	public double getCor_x2()
	{
		return cordinate_x2;
	}
	
	/**
	 * 
	 * @return cordinate_x3 return eder
	 */
	public double getCor_x3()
	{
		return cordinate_x3;
	}
	
	/**
	 * 
	 * @return cordinate_y1 return eder
	 */
	public double getCor_y1()
	{
		return cordinate_y1;
	}
	
	/**
	 * 
	 * @return cordinate_y2 return eder
	 */
	public double getCor_y2()
	{
		return cordinate_y2;
	}
	
	/**
	 * 
	 * @return cordinate_y3 return eder
	 */
	public double getCor_y3()
	{
		return cordinate_y3;
	}
	
	/**
	 * 
	 * @param lengthValue length set etme icin kullanilir
	 */
	public void setLength(double lengthValue)
	{
		length = lengthValue; 
	}
	
	/**
	 * 
	 * @param cordinate_x1Value cordinate_x1 set etme icin kullanilir
	 */
	public void setCor_x1(double cordinate_x1Value)
	{
		cordinate_x1 = cordinate_x1Value;
	}
	
	/**
	 * 
	 * @param cordinate_x2Value cordinate_x2 set etme icin kullanilir
	 */
	public void setCor_x2(double cordinate_x2Value)
	{
		cordinate_x2 = cordinate_x2Value;
	}
	
	/**
	 * 
	 * @param cordinate_x3Value cordinate_x3 set etme icin kullanilir
	 */
	public void setCor_x3(double cordinate_x3Value)
	{
		cordinate_x3 = cordinate_x3Value;
	}
	
	/**
	 * 
	 * @param cordinate_y1Value cordinate_y1 set etme icin kullanilir
	 */
	public void setCor_y1(double cordinate_y1Value)
	{
		cordinate_y1 = cordinate_y1Value;
	}
	
	/**
	 * 
	 * @param cordinate_y2Value cordinate_y2 set etme icin kullanilir
	 */
	public void setCor_y2(double cordinate_y2Value)
	{
		cordinate_y2 = cordinate_y2Value;
	}
	/**
	 * 
	 * @param cordinate_y3Value cordinate_y3 set etme icin kullanilir
	 */
	public void setCor_y3(double cordinate_y3Value)
	{
		cordinate_y3 = cordinate_y3Value; 
	}
	
	/**
	 * Cevre fonksiyonu
	 */
	@Override
	public double perimeter()
	{
		return(3.0 * length);
	}
	
	/**
	 * Alan fonksiyonu
	 */
	@Override
	public double area()
	{
		return(length * length * Math.sqrt(3.0) / 4.0 );
	}
	
	/**
	 * Koordinatleri bir arttirma
	 */
	@Override
	public Shape increment()
	{
		cordinate_x1 = cordinate_x1 + 1;
		cordinate_x2 = cordinate_x2 + 1;
		cordinate_x3 = cordinate_x3 + 1;
		cordinate_y1 = cordinate_y1 + 1;
		cordinate_y2 = cordinate_y2 + 1;
		cordinate_y3 = cordinate_y3 + 1;
		
		return this;
	}
	
	/**
	 * Koordinatlari bir azaltma
	 */
	@Override
	public Shape decrement()
	{
		cordinate_x1 = cordinate_x1 - 1;
		cordinate_x2 = cordinate_x2 - 1;
		cordinate_x3 = cordinate_x3 - 1;
		cordinate_y1 = cordinate_y1 - 1;
		cordinate_y2 = cordinate_y2 - 1;
		cordinate_y3 = cordinate_y3 - 1;
		
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
	 * Triangle cizdirme islemi
	 */
	@Override
	public void draw(Graphics g)
	{
		if(this.getType() == "TRIANGLE") //Buyuk sekil cizdirirken renk beklirmek icin
		{
			g.setColor(Color.RED);
	        g.fillPolygon(new int []{(int)this.getCor_x1(),(int)this.getCor_x2(),(int)this.getCor_x3()}, 
	        			  new int []{(int)this.getCor_y1(),(int)this.getCor_y2(),(int)this.getCor_y3()},3);
		}
		if(this.getType() == "triangle") //Buyuk sekil cizdirirken renk beklirmek icin
		{
			g.setColor(Color.GREEN);
	        g.fillPolygon(new int []{(int)this.getCor_x1(),(int)this.getCor_x2(),(int)this.getCor_x3()}, 
	        			  new int []{(int)this.getCor_y1(),(int)this.getCor_y2(),(int)this.getCor_y3()},3);
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