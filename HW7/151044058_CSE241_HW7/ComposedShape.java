import java.awt.Color;
import java.awt.Graphics;
import java.util.ArrayList;

import javax.swing.JPanel;
/**
 * 
 * @author Ali Haydar Kurban
 *
 */
public class ComposedShape extends JPanel implements Shape 
{
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	/**
	 * Rectangle referanslari
	 */
	private Rectangle main_rectangle, small_rectangle;
	/**
	 * Triangle referanslari
	 */
	private Triangle main_triangle, small_triangle;
	/**
	 * Circle referanslari
	 */
	private Circle main_circle, small_circle;
	/**
	 * Cizdirilecek sekillerin hangisi olduguna karar vermek icin karaterler 
	 */
	private char bigChar, smallChar;
	/**
	 *  
	 */
	private Shape [] shape_Array;

	/**
	 * No parameter constructor
	 */
	public ComposedShape()
	{
		//Empty
	}

	/**
	 * Gelen degiskenleri privattaki degiskenlere atama
	 * @param Cmain_rectangle buyuk sekil
	 * @param Csmall_rectangle kucuk sekil
	 */
	public ComposedShape(Rectangle Cmain_rectangle, Rectangle Csmall_rectangle)
	{
		main_rectangle = Cmain_rectangle;
		small_rectangle = Csmall_rectangle;
	}
	
	/**
	 * Gelen degiskenleri privattaki degiskenlere atama
	 * @param Cmain_rectangle buyuk sekil
	 * @param Csmall_triangle kucuk sekil
	 */
	public ComposedShape(Rectangle Cmain_rectangle, Triangle Csmall_triangle)
	{
		main_rectangle = Cmain_rectangle;
		small_triangle = Csmall_triangle;
	}
	
	/**
	 * Gelen degiskenleri privattaki degiskenlere atama
	 * @param Cmain_rectangle buuyk sekil
	 * @param Csmall_circle kuuck sekil
	 */
	public ComposedShape(Rectangle Cmain_rectangle, Circle Csmall_circle)
	{
		main_rectangle = Cmain_rectangle;
		small_circle = Csmall_circle;
	}
	/**
	 * Gelen degiskenleri privattaki degiskenlere atama
	 * @param Cmain_triangle buyuk sekil
	 * @param Csmall_rectangle kucuk sekil
	 */
	public ComposedShape(Triangle Cmain_triangle, Rectangle Csmall_rectangle)
	{
		main_triangle = Cmain_triangle;
		small_rectangle = Csmall_rectangle;
	}
	/**
	 * Gelen degiskenleri privattaki degiskenlere atama
	 * @param Cmain_triangle buuyk sekil
	 * @param Csmall_triangle kucuk sekil
	 */
	public ComposedShape(Triangle Cmain_triangle, Triangle Csmall_triangle)
	{
		main_triangle = Cmain_triangle;
		small_triangle = Csmall_triangle;
	}
	/**
	 * Gelen degiskenleri privattaki degiskenlere atama
	 * @param Cmain_triangle buyuk sekil
	 * @param Csmall_circle kucuk sekil
	 */
	public ComposedShape(Triangle Cmain_triangle, Circle Csmall_circle)
	{
		main_triangle = Cmain_triangle;
		small_circle = Csmall_circle;
	}
	/**
	 * Gelen degiskenleri privattaki degiskenlere atama
	 * @param Cmain_circle buyuk sekil
	 * @param Csmall_rectangle kucuk sekil
	 */
	public ComposedShape(Circle Cmain_circle, Rectangle Csmall_rectangle)
	{
		main_circle = Cmain_circle;
		small_rectangle = Csmall_rectangle;
	}
	/**
	 * Gelen degiskenleri privattaki degiskenlere atama
	 * @param Cmain_circle buyuk sekil
	 * @param Csmall_triangle kuuck sekil
	 */
	public ComposedShape(Circle Cmain_circle, Triangle Csmall_triangle)
	{
		main_circle = Cmain_circle;
		small_triangle = Csmall_triangle;
	}
	/**
	 * Gelen degiskenleri privattaki degiskenlere atama
	 * @param Cmain_circle buyuk sekil
	 * @param Csmall_circle kucuk sekil
	 */
	public ComposedShape(Circle Cmain_circle, Circle Csmall_circle)
	{
		main_circle = Cmain_circle;
		small_circle = Csmall_circle;
	}

	/**
	 *  Karakter kontrolune gore uygun methodu cagirir
	 * @return num (Kac adet sekil sigdigini return eder)
	 */
	public int optimalFit()
	{
		int num = 0;
		if((getbigChar() == 'R' || getbigChar() == 'r') && (getsmallChar() == 'R' || getsmallChar() == 'r'))
			num = fitting_rec_in_rec(main_rectangle, small_rectangle);
			
		else if((getbigChar() == 'R' || getbigChar() == 'r') && (getsmallChar() == 'T' || getsmallChar() == 't'))
			num = fitting_rec_in_tri(main_rectangle, small_triangle);

		else if((getbigChar() == 'R' || getbigChar() == 'r') && (getsmallChar() == 'C' || getsmallChar() == 'c'))
			num = fitting_rec_in_cir(main_rectangle, small_circle);

		else if((getbigChar() == 'T' || getbigChar() == 't') && (getsmallChar() == 'R' || getsmallChar() == 'r'))	
			num = fitting_tri_in_rec(main_triangle, small_rectangle);

		else if((getbigChar() == 'T' || getbigChar() == 't') && (getsmallChar() == 'T' || getsmallChar() == 't'))
			num = fitting_tri_in_tri(main_triangle, small_triangle);

		else if((getbigChar() == 'T' || getbigChar() == 't') && (getsmallChar() == 'C' || getsmallChar() == 'c'))
			num = fitting_tri_in_cir(main_triangle, small_circle);

		else if((getbigChar() == 'C' || getbigChar() == 'c') && (getsmallChar() == 'R' || getsmallChar() == 'r'))
			num = fitting_cir_in_rec(main_circle, small_rectangle);

		else if((getbigChar() == 'C' || getbigChar() == 'c') && (getsmallChar() == 'T' || getsmallChar() == 't'))
			num = fitting_cir_in_tri(main_circle, small_triangle);

		else if((getbigChar() == 'C' || getbigChar() == 'c') && (getsmallChar() == 'C' || getsmallChar() == 'c'))
			num = fitting_cir_in_cir(main_circle, small_circle);
		else
			//Throw excepttion
			 throw new IllegalArgumentException("Illegal Character for ComposedShape\n");
	
		return num;
	}

	/**
	 * 
	 * @return bigChar return eder
	 */
	public char getbigChar()
	{
		return bigChar;
	}
	/**
	 * 
	 * @return smallChar return eder
	 */
	public char getsmallChar()
	{
		return smallChar;
	}

	/**
	 * bigChar set eder
	 * @param bigCharValue bigChar a atamak icin
	 */
	public void setBigChar(char bigCharValue)
	{
		bigChar = bigCharValue; 
	}
	/**
	 * smallChar set eder
	 * @param smallCharValue smallChar a atamak icin
	 */
	public void setSmallChar(char smallCharValue)
	{
		smallChar = smallCharValue; 
	}
	
	/**
	 * Ic ice sekilleri cizdirir
	 */
	@Override
	public void draw(Graphics g)
	{
		shape_Array[0].draw(g);
	
		int size = shape_Array.length;
		
		if(getsmallChar() == 'R' || getsmallChar() == 'r')
		{
			for(int i = 1 ;i < size; ++i)
			{
				g.setColor(Color.GREEN);
				g.fillRect((int)((Rectangle)(shape_Array[i])).getCor_x(),(int)((Rectangle)(shape_Array[i])).getCor_y(),
						(int)((Rectangle)(shape_Array[i])).getWidthh(),(int)((Rectangle)(shape_Array[i])).getHeightt());
				g.setColor(Color.WHITE);
				g.drawRect((int)((Rectangle)(shape_Array[i])).getCor_x(),(int)((Rectangle)(shape_Array[i])).getCor_y(),
						(int)((Rectangle)(shape_Array[i])).getWidthh(),(int)((Rectangle)(shape_Array[i])).getHeightt());	
			}
		}
		else if(getsmallChar() == 'C' || getsmallChar() == 'c')
		{
			for(int i = 1 ;i < size; ++i)
			{
				g.setColor(Color.GREEN);
				g.fillOval((int)((Circle)(shape_Array[i])).getCenter_x(),(int)((Circle)(shape_Array[i])).getCenter_y(),
						(int)((Circle)(shape_Array[i])).getRadius()*2,(int)((Circle)(shape_Array[i])).getRadius()*2);
				g.setColor(Color.WHITE);
				g.drawOval((int)((Circle)(shape_Array[i])).getCenter_x(),(int)((Circle)(shape_Array[i])).getCenter_y(),
						(int)((Circle)(shape_Array[i])).getRadius()*2,(int)((Circle)(shape_Array[i])).getRadius()*2);
			}
		}
		
		else if(getsmallChar() == 'T' || getsmallChar() == 't')
		{
			for(int i = 1; i < size; ++i)
			{
				g.setColor(Color.GREEN);
		        g.fillPolygon(new int []{(int)((Triangle)(shape_Array[i])).getCor_x1(),(int)((Triangle)(shape_Array[i])).getCor_x2(),(int)((Triangle)(shape_Array[i])).getCor_x3()}, 
		        			  new int []{(int)((Triangle)(shape_Array[i])).getCor_y1(),(int)((Triangle)(shape_Array[i])).getCor_y2(),(int)((Triangle)(shape_Array[i])).getCor_y3()},3);
			
		        g.setColor(Color.WHITE);
		        g.drawPolygon(new int []{(int)((Triangle)(shape_Array[i])).getCor_x1(),(int)((Triangle)(shape_Array[i])).getCor_x2(),(int)((Triangle)(shape_Array[i])).getCor_x3()}, 
		        			  new int []{(int)((Triangle)(shape_Array[i])).getCor_y1(),(int)((Triangle)(shape_Array[i])).getCor_y2(),(int)((Triangle)(shape_Array[i])).getCor_y3()},3);
			}
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
	 * 
	 */
	@Override
	public int compareTo(Object arg0) 
	{
		return 0;
	}
	/**
	 * 
	 */
	@Override
	public double area()
	{
		return 0.0;
	}
	/**
	 * 
	 */
	@Override
	public double perimeter()
	{
		return 0.0;
	}
	/**
	 * 
	 */
	@Override
	public Shape increment()
	{
		//Empty
		return null;
	}
	/**
	 * 
	 */
	@Override
	public Shape decrement()
	{
		//Empty
		return null;
	}
	/**
	 * 
	 * @param main_rectangle buyuk sekil
	 * @param small_rectangle kucuk sekil
	 * @return total_rectangle return eder kac sekil sigdigidir (Rectangle icine rectengle)
	 */
	private int fitting_rec_in_rec(Rectangle main_rectangle, Rectangle small_rectangle)
	{
		ArrayList<Shape> Array1 = new ArrayList<Shape>();
		main_rectangle.setType("RECTANGLE");
		small_rectangle.setType("rectangle");

		Array1.add(main_rectangle);
		
		double small_rectangle_width = small_rectangle.getWidthh();
		double small_rectangle_height = small_rectangle.getHeightt();

		int i,j;
		int total_rectangle = 0;
		int counter_x = (int)(main_rectangle.getWidthh() / small_rectangle.getWidthh());
		int counter_y = (int)(main_rectangle.getHeightt() / small_rectangle.getHeightt());
		double start_x = 0.0;
		double start_y = 0.0;
		small_rectangle.setCor_x(start_x);
		small_rectangle.setCor_y(start_y);

		int temp_mainWidth = (int)main_rectangle.getWidthh();
		int temp_mainHeight = (int)main_rectangle.getHeightt();
		int temp_smallWidth = (int)small_rectangle.getWidthh();
		int temp_smallHeight = (int)small_rectangle.getHeightt();

		//Dikdorgenlerin koseleri ters sekilde birbirinin katiysa tam sigar o yuzden bu kosul var. Bosta yer kalmaz	
		if((temp_mainWidth % temp_smallHeight == 0) && (temp_mainHeight % temp_smallWidth == 0) )	
		{
			
			counter_x = (int)(main_rectangle.getHeightt() / small_rectangle.getWidthh());
			counter_y = (int)(main_rectangle.getWidthh() / small_rectangle.getHeightt());

			double temp1 = small_rectangle.getWidthh();
			double temp2 = small_rectangle.getHeightt();

			small_rectangle.setWidth(temp2);
			small_rectangle.setHeight(temp1);

			for(i = 0; i < counter_x; ++i)
			{
				for(j = 0; j < counter_y; ++j)
				{
					Array1.add(small_rectangle);
					small_rectangle = new Rectangle(small_rectangle_width,small_rectangle_height,start_x,start_y);
					start_x = start_x + small_rectangle.getWidthh();
					small_rectangle.setCor_x(start_x);

					total_rectangle = total_rectangle + 1;
				}
				start_x = 0.0;
				small_rectangle.setCor_x(start_x);
				start_y = start_y + small_rectangle.getHeightt();
				small_rectangle.setCor_y(start_y);
			}
		}

		else
		{
			start_x = 0.0;
			start_y = 0.0;
			small_rectangle.setCor_x(start_x);
			small_rectangle.setCor_y(start_y);

			for(i = 0; i < counter_y; ++i)
			{
				for(j = 0; j < counter_x; ++j)
				{
					
					Array1.add(small_rectangle);
					small_rectangle = new Rectangle(small_rectangle_width,small_rectangle_height,start_x,start_y);
					start_x = start_x + small_rectangle.getWidthh();
					small_rectangle.setCor_x(start_x);
					total_rectangle = total_rectangle + 1;
					
				}
				start_x = 0.0;
				small_rectangle.setCor_x(start_x);
				start_y = start_y + small_rectangle.getHeightt();
				small_rectangle.setCor_y(start_y);
			}	
		}
		
		int Array1_size = Array1.size();
	
		shape_Array = new Shape[Array1_size];
		
		Array1.toArray(shape_Array);
		

		//Ekrana bilgileri yazdirma
		if(total_rectangle > 0)
		{
			System.out.printf("I can fit at %d small shapes into the main container.\nThe empty area (red) in %.3f.\n",
					total_rectangle,main_rectangle.area() - total_rectangle *  small_rectangle.area());		 
		}
		else
			System.out.printf("Eror!! I can not fit any rectangle to rectangle\n");
		
		return total_rectangle;
			
	}
	/**
	 * 
	 * @param main_rectangle buyuk sekil
	 * @param small_triangle kucuk sekil
	 * @return total_triangle return eder kac sekil sigdigidir (Rectangle icine triangle) 
	 */
	private int fitting_rec_in_tri(Rectangle main_rectangle, Triangle small_triangle)
	{
		ArrayList<Shape> Array2 = new ArrayList<Shape>();
		main_rectangle.setType("RECTANGLE");	
		small_triangle.setType("triangle");		
		
		Array2.add(main_rectangle);
		
		int i,j;
		double x1 = small_triangle.getLength() / 2.0 , y1 = 0.0;
		double x2 = 0.0,  y2 = small_triangle.getLength() * Math.sqrt(3.0) / 2.0;
		double x3 = small_triangle.getLength() , y3 = small_triangle.getLength() * Math.sqrt(3.0) / 2.0;

		double L = small_triangle.getLength();
		
		small_triangle.setCor_x1(x1);
		small_triangle.setCor_y1(y1);
		small_triangle.setCor_x2(x2);
		small_triangle.setCor_y2(y2);
		small_triangle.setCor_x3(x3);
		small_triangle.setCor_y3(y3);

		int counter_x1 = (int)(main_rectangle.getWidthh() / small_triangle.getLength());
		int counter_y1 = (int)(main_rectangle.getHeightt() / (small_triangle.getLength() * Math.sqrt(3.0) / 2.0));

		int total_triangle = 0;

		for(i = 0; i < counter_y1; ++i)
		{
			for(j = 0; j < counter_x1; ++j)
			{
				Array2.add(small_triangle);
				
				small_triangle = new Triangle(L,x1,x2,x3,y1,y2,y3);

				total_triangle = total_triangle + 1;	

				x1 = x1 + small_triangle.getLength() ;
				x2 = x2 + small_triangle.getLength() ;	
				x3 = x3 + small_triangle.getLength() ;
				small_triangle.setCor_x1(x1);
				small_triangle.setCor_x2(x2);
				small_triangle.setCor_x3(x3);
			}
			x1 = small_triangle.getLength() / 2.0;
			x2 = 0.0;
			x3 = small_triangle.getLength();
			y1 = y1 + (small_triangle.getLength() * Math.sqrt(3.0) / 2.0);
			y2 = y2 + (small_triangle.getLength() * Math.sqrt(3.0) / 2.0);	
			y3 = y3 + (small_triangle.getLength() * Math.sqrt(3.0) / 2.0);
			
			small_triangle.setCor_x1(x1);
			small_triangle.setCor_x2(x2);
			small_triangle.setCor_x3(x3);	
			small_triangle.setCor_y1(y1);	
			small_triangle.setCor_y2(y2);
			small_triangle.setCor_y3(y3);
		}

		int counter_x2 = (int)((main_rectangle.getWidthh() - (small_triangle.getLength() / 2.0)) / small_triangle.getLength());	

		x1 = small_triangle.getLength() / 2.0;
		y1 = 0.0;
		x2 = (small_triangle.getLength() / 2.0) + small_triangle.getLength();
		y2 =  0.0; 
		x3 = small_triangle.getLength();
		y3 = small_triangle.getLength() * Math.sqrt(3.0) / 2.0;

		small_triangle.setCor_x1(x1);
		small_triangle.setCor_x2(x2);
		small_triangle.setCor_x3(x3);	
		small_triangle.setCor_y1(y1);
		small_triangle.setCor_y2(y2);
		small_triangle.setCor_y3(y3);

		small_triangle = new Triangle(L,x1,x2,x3,y1,y2,y3);
		
		for(i = 0 ; i < counter_y1; ++i)
		{
			for(j = 0; j < counter_x2; ++j)
			{
				Array2.add(small_triangle);
				
				small_triangle = new Triangle(L,x1,x2,x3,y1,y2,y3);
				total_triangle = total_triangle + 1;

				x1 = x1 + small_triangle.getLength() ;
				if((x2 + small_triangle.getLength()) <= main_rectangle.getWidthh())
					x2 = x2 + small_triangle.getLength() ;
				x3 = x3 + small_triangle.getLength() ;
				small_triangle.setCor_x1(x1);
				small_triangle.setCor_x2(x2);
				small_triangle.setCor_x3(x3);	
			}

			x1 = small_triangle.getLength() / 2.0;
			x2 = (small_triangle.getLength() / 2.0) + small_triangle.getLength();
			x3 = small_triangle.getLength();
			y1 = y1 + (small_triangle.getLength() * Math.sqrt(3.0) / 2.0);		
			y2 = y2 + (small_triangle.getLength() * Math.sqrt(3.0) / 2.0);
			y3 = y3 + (small_triangle.getLength() * Math.sqrt(3.0) / 2.0);

			small_triangle.setCor_x1(x1);
			small_triangle.setCor_x2(x2);
			small_triangle.setCor_x3(x3);
			small_triangle.setCor_y1(y1);
			small_triangle.setCor_y2(y2);
			small_triangle.setCor_y3(y3);
		}
		
		int Array2_size = Array2.size();
			
		shape_Array = new Shape[Array2_size];
		
		Array2.toArray(shape_Array);
		
		if(total_triangle > 0)
		{
			System.out.printf("I can fit at %d small shapes into the main container.\nThe empty area (red) in %.3f.\n",
					total_triangle, main_rectangle.area() - total_triangle *  small_triangle.area());		 
		}
		else
			System.out.printf("Eror!! I can not fit any triangle to rectangle\n");
		
		return total_triangle;
	}
	/**
	 * 
	 * @param main_rectangle buyuk sekil
	 * @param small_circle kucuk sekil
	 * @return total_circle_1 return eder kac sekil sigdigidir (Rectangle icine circle)
	 */
	private	int fitting_rec_in_cir(Rectangle main_rectangle, Circle small_circle)
	{
		ArrayList<Shape> Array3 = new ArrayList<Shape>();
		main_rectangle.setType("RECTANGLE");
		small_circle.setType("circle");

		Array3.add(main_rectangle);

		int i,j;
		int counter_x = (int)(main_rectangle.getWidthh() / (2 * small_circle.getRadius()));
		int counter_temp_y = (int)(main_rectangle.getHeightt() / (2 * small_circle.getRadius()));
		int counter_y = (int)(2.0 * main_rectangle.getHeightt() / ((small_circle.getRadius() +small_circle.getRadius() * Math.sqrt(3.0))));
		
		double new_center_x = small_circle.getRadius();  
		double new_center_y = small_circle.getRadius();

		double R = small_circle.getRadius();
		
		int total_circle_1 = counter_x * counter_temp_y;	//Duz bir sekilde daireleri yerlestirince kac adet daire sigivaginin sayisi
		
		int total_circle_2 = 0;

		double center_x = small_circle.getRadius();
		double center_y = small_circle.getRadius();

		small_circle.setCenter_x(new_center_x);
		small_circle.setCenter_y(new_center_y);

		//ASAGIDAKI DONGULER ILE DAIRELERIN BASLANGIC NOKTALARINI KESISTIKLERI YER YAPARAK KAC ADET SIGACAGINI BULDUM 
		for(i = 0; i < counter_y; ++i)
		{
			for(j = 0; j < counter_x; ++j)
			{	
				new_center_x = new_center_x + 2 * small_circle.getRadius();

				if((new_center_x + small_circle.getRadius()) <= main_rectangle.getWidthh() && (new_center_y + small_circle.getRadius() * Math.sqrt(3.0)) <= main_rectangle.getHeightt())
					total_circle_2 = total_circle_2 + 1;									
			}

			if(i % 2 == 1)
				new_center_x = small_circle.getRadius();
				
			else if(i % 2 == 0)
				new_center_x =  2 * small_circle.getRadius();
			
			if((new_center_y + small_circle.getRadius() * Math.sqrt(3.0)) <= main_rectangle.getHeightt() )
			{
				new_center_y = new_center_y + small_circle.getRadius() * Math.sqrt(3.0);
				total_circle_2 = total_circle_2 + 1;
			}

		}

		if(total_circle_1 >= total_circle_2)	
		{
			center_x = 0.0;
			center_y = 0.0;

			small_circle.setCenter_x(center_x);
			small_circle.setCenter_y(center_y);

			counter_x = (int)(main_rectangle.getWidthh() / (2 * small_circle.getRadius()));	
			counter_temp_y =(int)(main_rectangle.getHeightt() / (2 * small_circle.getRadius()));

			for(i = 0; i < counter_temp_y; ++i)
			{
				for(j = 0; j < counter_x; ++j)
				{
					Array3.add(small_circle);
					
					small_circle = new Circle(R,center_x,center_y);
					
					center_x = center_x + 2 * small_circle.getRadius();	
					small_circle.setCenter_x(center_x);	
				}
				center_x = 0.0;
				center_y = center_y + 2 * small_circle.getRadius();	
				small_circle.setCenter_x(center_x);
				small_circle.setCenter_y(center_y);
			}
		}

		else
		{
			counter_y = (int)(2.0 * main_rectangle.getHeightt() / ((small_circle.getRadius() + small_circle.getRadius() * Math.sqrt(3.0))));

			new_center_x = 0.0;
			new_center_y = 0.0;

			small_circle.setCenter_x(new_center_x);
			small_circle.setCenter_y(new_center_y);

			/*ASAGIDAKI DONGULER ILE DAIRELERIN BASLANGIC NOKTALARINI KESISTIKLERI YER YAPARAK SVG DOSYASINA YAZDIM 	*/
			for(i = 0; i < counter_y; ++i)
			{
				for(j = 0; j < counter_x; ++j)
				{			
					if((new_center_x + small_circle.getRadius()) <= main_rectangle.getWidthh() && (new_center_y + small_circle.getRadius() * Math.sqrt(3.0)) <= main_rectangle.getHeightt())
					{
	
						Array3.add(small_circle);
						
						small_circle = new Circle(R,new_center_x,new_center_y);
						
						if(new_center_x + small_circle.getRadius() <= main_rectangle.getWidthh())	
						{
							new_center_x = new_center_x + 2 * small_circle.getRadius();
							small_circle.setCenter_x(new_center_x);
						}	
					}						
				}
				if(i % 2 == 1)
				{	
					new_center_x = 0.0;	
					small_circle.setCenter_x(new_center_x);	
				
				}	
				else if(i % 2 == 0)
				{
					new_center_x = small_circle.getRadius();	
					small_circle.setCenter_x(new_center_x);
				}

				if((new_center_y + small_circle.getRadius() * Math.sqrt(3.0)) <= main_rectangle.getHeightt() )
				{
					new_center_y = new_center_y + small_circle.getRadius() * Math.sqrt(3.0);
					small_circle.setCenter_y(new_center_y);
				}	
			}	
		}	

		int Array3_size = Array3.size();
		
		shape_Array = new Shape[Array3_size];
		
		Array3.toArray(shape_Array);
		
		
		
		//Ekrana bilgileri yazdirma
	 	if(total_circle_1 <= 0 && total_circle_2 <= 0)	/*Hic daire sigmama durumu	*/
			System.out.printf("Eror!! I can not fit any circle to rectangle\n");

		else if(total_circle_1 >= total_circle_2)
			System.out.printf("I can fit at %d small shapes into the main container.\nThe empty area (red) in %.3f.\n",
					total_circle_1, main_rectangle.area() - total_circle_1 *  small_circle.area());
		
		else if(total_circle_2 > total_circle_1)
			System.out.printf("I can fit at %d small shapes into the main container.\nThe empty area (red) in %.3f.\n",
					total_circle_2, main_rectangle.area() - total_circle_2 *  small_circle.area());
	
	 	return total_circle_1;
	
	}
	
	/**
	 * 
	 * @param main_triangle buyuk sekil
	 * @param small_rectangle kucuk sekil
	 * @return total_rectangle return eder kac sekil sigdigidir (Triangle icine rectangle)
	 */
	private int fitting_tri_in_rec(Triangle main_triangle, Rectangle small_rectangle)
	{
		ArrayList<Shape> Array4 = new ArrayList<Shape>();
		
		main_triangle.setType("TRIANGLE");
		small_rectangle.setType("rectangle");
		
		Array4.add(main_triangle);

		int i,j;
		double temp_length = main_triangle.getLength();
		double start_x = small_rectangle.getHeightt() / Math.sqrt(3.0);	
		double start_y = ((temp_length / 2.0) * Math.sqrt(3.0) ) - (small_rectangle.getHeightt());
		small_rectangle.setCor_x(start_x);
		small_rectangle.setCor_y(start_y);

		int total_rectangle = 0;
		int counter_y = (int)((temp_length * Math.sqrt(3.0) / 2.0 ) / small_rectangle.getHeightt());	/*Dongu sayisini bulma	*/
		int counter_x = (int)(temp_length / small_rectangle.getWidthh());
		temp_length = temp_length - (small_rectangle.getHeightt() / Math.sqrt(3.0));

		double small_rectangle_width = small_rectangle.getWidthh();
		double small_rectangle_height = small_rectangle.getHeightt();
		
		
		for(i = 0; i < counter_y ; ++i)
		{
			for(j = 0; j < counter_x ; ++j)
			{
				if(start_x + small_rectangle.getWidthh() <= temp_length)
				{
					
					Array4.add(small_rectangle);
					small_rectangle = new Rectangle(small_rectangle_width,small_rectangle_height,start_x,start_y);

					start_x = start_x + small_rectangle.getWidthh();	
					small_rectangle.setCor_x(start_x);
					total_rectangle = total_rectangle + 1;
				}		
			}

			temp_length = temp_length - (small_rectangle.getHeightt() / Math.sqrt(3.0));	
			counter_x = (int)(temp_length / small_rectangle.getWidthh());		
			
			start_x = small_rectangle.getHeightt() / Math.sqrt(3.0);
			start_x = start_x + ((i + 1) * (small_rectangle.getHeightt() / Math.sqrt(3.0)) );	
			start_y = start_y - small_rectangle.getHeightt();

			small_rectangle.setCor_x(start_x);
			small_rectangle.setCor_y(start_y);

		}

		int Array4_size = Array4.size();
			
		shape_Array = new Shape[Array4_size];
		
		Array4.toArray(shape_Array);
		
		
		if(total_rectangle > 0)
			System.out.printf("I can fit at %d small shapes into the main container.\nThe empty area (red) in %.3f.\n",
					total_rectangle, main_triangle.area() - total_rectangle * small_rectangle.area());
		else
			System.out.printf("Eror!! I can not fit any rectangle to triangle\n");
		
		return total_rectangle;
	}
	/**
	 * 
	 * @param main_triangle buyuk sekil
	 * @param small_triangle kucuk sekil
	 * @return total_triangle return eder kac sekil sigdigidir (Triangle icine triangle)
	 */
	private	int fitting_tri_in_tri(Triangle main_triangle, Triangle small_triangle)
	{
		ArrayList<Shape> Array5 = new ArrayList<Shape>();
	
		main_triangle.setType("TRIANGLE");
		small_triangle.setType("triangle");	
		
		Array5.add(main_triangle);

		int i, j;
		double x1 = main_triangle.getLength() / 2.0;
		double y1 = 0.0;
		double x2 = (main_triangle.getLength() / 2.0) - (small_triangle.getLength() / 2.0);
		double y2 = small_triangle.getLength() * Math.sqrt(3.0) / 2.0;
		double x3 = main_triangle.getLength() / 2.0 + small_triangle.getLength() / 2.0;
		double y3 = small_triangle.getLength() * Math.sqrt(3.0) / 2.0;
		double L = small_triangle.getLength();

		small_triangle.setCor_x1(x1);
		small_triangle.setCor_x2(x2);
		small_triangle.setCor_x3(x3);
		small_triangle.setCor_y1(y1);
		small_triangle.setCor_y2(y2);
		small_triangle.setCor_y3(y3);

		int counter_y = (int)((main_triangle.getLength() * Math.sqrt(3.0) / 2.0 ) / (small_triangle.getLength() * Math.sqrt(3.0) / 2.0));

		int total_triangle = 0;

		for(i = 0; i < counter_y; ++i)
		{
			for(j = 0 ; j < i + 1; ++j)
			{
				Array5.add(small_triangle);
				small_triangle = new Triangle(L,x1,x2,x3,y1,y2,y3);
				total_triangle = total_triangle + 1;

				x1 = x1 + small_triangle.getLength();
				x2 = x2 + small_triangle.getLength();	
				x3 = x3 + small_triangle.getLength();

				small_triangle.setCor_x1(x1);
				small_triangle.setCor_x2(x2);
				small_triangle.setCor_x3(x3);
			}

			x1 = main_triangle.getLength() / 2.0;
			x2 = main_triangle.getLength() / 2.0 - small_triangle.getLength() / 2.0;	
			x3 = main_triangle.getLength() / 2.0 + small_triangle.getLength() / 2.0;

			if((i + 1) < counter_y)
			{
				x1 = x1 - ((i+1) * (small_triangle.getLength() / 2.0));
				x2 = x2 - ((i+1) * (small_triangle.getLength() / 2.0));	
				x3 = x3 - ((i+1) * (small_triangle.getLength() / 2.0));
			}

			y1 = y1 + (small_triangle.getLength() * Math.sqrt(3.0) / 2.0);
			y2 = y2 + (small_triangle.getLength() * Math.sqrt(3.0) / 2.0);	
			y3 = y3 + (small_triangle.getLength() * Math.sqrt(3.0) / 2.0);

			small_triangle.setCor_x1(x1);
			small_triangle.setCor_x2(x2);
			small_triangle.setCor_x3(x3);
			small_triangle.setCor_y1(y1);
			small_triangle.setCor_y2(y2);
			small_triangle.setCor_y3(y3);

		}

		int counter_y1 = counter_y - 1;

		x1 = (main_triangle.getLength() / 2.0) - (small_triangle.getLength() / 2.0);
		y1 = small_triangle.getLength() * Math.sqrt(3.0) / 2.0;
		x2 = (main_triangle.getLength() / 2.0) + (small_triangle.getLength() / 2.0); 
		y2 = small_triangle.getLength() * Math.sqrt(3.0) / 2.0;
		x3 = main_triangle.getLength() / 2.0;
		y3 = small_triangle.getLength() * Math.sqrt(3.0) ;

		small_triangle.setCor_x1(x1);
		small_triangle.setCor_x2(x2);
		small_triangle.setCor_x3(x3);
		small_triangle.setCor_y1(y1);
		small_triangle.setCor_y2(y2);
		small_triangle.setCor_y3(y3);

		for(i = 0; i < counter_y1; ++i)
		{
			for(j = 0; j < i + 1; ++j)
			{
				Array5.add(small_triangle);
				small_triangle = new Triangle(L,x1,x2,x3,y1,y2,y3);
				total_triangle = total_triangle + 1;

				x1 = x1 + small_triangle.getLength();
				x2 = x2 + small_triangle.getLength();	
				x3 = x3 + small_triangle.getLength();
				small_triangle.setCor_x1(x1);
				small_triangle.setCor_x2(x2);
				small_triangle.setCor_x3(x3);
			}

			x1 = (main_triangle.getLength() / 2.0) - (small_triangle.getLength() / 2.0);
			x2 = (main_triangle.getLength() / 2.0) + (small_triangle.getLength() / 2.0);
			x3 = main_triangle.getLength() / 2.0;
			
			x1 = x1 - ((i + 1) * (small_triangle.getLength() / 2.0));
			x2 = x2 - ((i + 1) * (small_triangle.getLength() / 2.0));	
			x3 = x3 - ((i + 1) * (small_triangle.getLength() / 2.0));

			y1 = y1 + (small_triangle.getLength() * Math.sqrt(3.0) / 2.0);
			y2 = y2 + (small_triangle.getLength() * Math.sqrt(3.0) / 2.0);
			y3 = y3 + (small_triangle.getLength() * Math.sqrt(3.0) / 2.0);

			small_triangle.setCor_x1(x1);
			small_triangle.setCor_x2(x2);
			small_triangle.setCor_x3(x3);
			small_triangle.setCor_y1(y1); 
			small_triangle.setCor_y2(y2);
			small_triangle.setCor_y3(y3);
		}

		int Array5_size = Array5.size();
		
		shape_Array = new Shape[Array5_size];
		
		Array5.toArray(shape_Array);
		
		
		if(total_triangle > 0)
			System.out.printf("I can fit at %d small shapes into the main container.\nThe empty area (red) in %.3f.\n",
					total_triangle, main_triangle.area() - total_triangle * small_triangle.area());
		else
			System.out.printf("Eror!! I can not fit any triangle to triangle\n");
		
		return total_triangle;
	
	}
	
	/**
	 * 
	 * @param main_triangle buyuk sekil
	 * @param small_circle kucuk sekil
	 * @return total_circle return eder kac sekil sigdigidir
	 */
	private int fitting_tri_in_cir(Triangle main_triangle, Circle small_circle)
	{
		ArrayList<Shape> Array6 = new ArrayList<Shape>();
		
		main_triangle.setType("TRIANGLE");
		small_circle.setType("circle");
		
		Array6.add(main_triangle);
		int i,j;
		int total_circle = 0;
		double center_x = main_triangle.getLength() / 2.0 - small_circle.getRadius();	
		double center_y = small_circle.getRadius();
		double R = small_circle.getRadius();
		
		small_circle.setCenter_x(center_x);
		small_circle.setCenter_y(center_y);	


		int counter_y = (int)(2.0 * (main_triangle.getLength() * Math.sqrt(3.0)  / 2.0 ) / (3 * small_circle.getRadius()));

		
		for(i = 0; i < counter_y; ++i)	
		{
			for(j = 0; j < i + 1 ; ++j)
			{
				Array6.add(small_circle);
				small_circle = new Circle(R,center_x,center_y);
				total_circle = total_circle + 1;

				center_x = center_x + (small_circle.getRadius() * 2);	
				small_circle.setCenter_x(center_x);
				
			}
			center_x = main_triangle.getLength() / 2.0;	
			center_x = center_x - ((i + 2) * small_circle.getRadius());	
			small_circle.setCenter_x(center_x);

			center_y = center_y + (small_circle.getRadius() * Math.sqrt(3.0));

			if(center_y + small_circle.getRadius() <= main_triangle.getLength() * Math.sqrt(3.0) / 2.0)
				small_circle.setCenter_y(center_y);
			else	
				break;
		}
		
		int Array6_size = Array6.size();
	
		shape_Array = new Shape[Array6_size];
		
		Array6.toArray(shape_Array);

		if(total_circle > 0)
			System.out.printf("I can fit at %d small shapes into the main container.\nThe empty area (red) in %.3f.\n",
					total_circle, main_triangle.area() - total_circle * small_circle.area());
		else
			System.out.printf("Eror!! I can not fit any circle to triangle\n");
		
		return total_circle;
				
	}
	/**
	 * 
	 * @param main_circle buyuk sekil
	 * @param small_rectangle kucuk sekil
	 * @return total_rectangle return eder kac sekil sigdigidir
	 */
	private int fitting_cir_in_rec(Circle main_circle, Rectangle small_rectangle)
	{
		ArrayList<Shape> Array7 = new ArrayList<Shape>();
		
		main_circle.setType("CIRCLE");
		small_rectangle.setType("rectangle");
		
		main_circle.setCenter_x(0.0);
		main_circle.setCenter_y(0.0);
		Array7.add(main_circle);
		int i,j;
		int total_rectangle = 0;
		double cordinate_x = 0.0;
		double cordinate_y = 0.0;	

		double radius = main_circle.getRadius();
		double small_width = small_rectangle.getWidthh();
		double small_height = small_rectangle.getHeightt();
		double small_rectangle_width = small_rectangle.getWidthh(); 
		double small_rectangle_height = small_rectangle.getHeightt();

		/*BU DONGULERDE DIKTORGENIN BUTUN KOSELERI CEMBER DENKLEMİ KULLANILARAK DAIRENIN ICINDE MI BULUNUR VE ONA GORE DIKDORTGENLER BASTIRILIR. (REFERANS cordinate_x ve cordinate_y NOKTALARINA GORE ISLEM YAPILIR)*/
		for(i = 0; i < (2 * radius); ++i )
		{
			for(j = 0; j < (2 * radius); ++j)
			{
				/*BU DONGULERDE DIKTORGENIN BUTUN KOSELERI CEMBER DENKLEMİ KULLANILARAK DAIRENIN ICINDE MI BULUNUR VE ONA GORE DIKDORTGENLER BASTIRILIR. */
				if( ( ( (cordinate_x - radius ) * (cordinate_x - radius) + (cordinate_y - radius ) * (cordinate_y - radius ) ) <= (radius * radius) )&&
					( ( (cordinate_x - radius ) * (cordinate_x - radius) + (cordinate_y + small_height - radius) * (cordinate_y + small_height - radius)) <= (radius * radius) ) &&
					( ( (cordinate_x + small_width - radius) * (cordinate_x + small_width - radius) + ((cordinate_y - radius ) * (cordinate_y - radius )) <= (radius * radius)))&&	
					( ( (cordinate_x + small_width - radius) * (cordinate_x + small_width - radius) + ((cordinate_y + small_height - radius ) * (cordinate_y + small_height - radius )) <= (radius * radius)))	
				   ) 
				{
					small_rectangle.setCor_x(cordinate_x);
					small_rectangle.setCor_y(cordinate_y);
					
					small_rectangle = new Rectangle(small_rectangle_width,small_rectangle_height,cordinate_x,cordinate_y);
					Array7.add(small_rectangle);
					
					total_rectangle = total_rectangle + 1;	
				
					cordinate_x = cordinate_x + small_width;
				}
				cordinate_x = cordinate_x + 1;			/*Dikdortgen sigmazsa 1 arttirma 	*/		
			}
			cordinate_x = 0.0;
			cordinate_y = cordinate_y + small_height;	/*Korrdinatlarin guncellenmesi	*/
		}   

		int Array7_size = Array7.size();
		
		shape_Array = new Shape[Array7_size];
		
		Array7.toArray(shape_Array);
		
		if(total_rectangle > 0)
			System.out.printf("I can fit at %d small shapes into the main container.\nThe empty area (red) in %.3f.\n",
					total_rectangle, main_circle.area() - total_rectangle * small_rectangle.area());
		else
			System.out.printf("Eror!! I can not fit any rectangle to circle\n");
		
		return total_rectangle;
	}
	
	/**
	 * 
	 * @param main_circle buyuk sekil
	 * @param small_triangle kucuk sekil
	 * @return total_triangle return eder kac sekil sigdigidir
	 */
	private int fitting_cir_in_tri(Circle main_circle, Triangle small_triangle)
	{
		ArrayList<Shape> Array8 = new ArrayList<Shape>();
		main_circle.setType("CIRCLE");
		small_triangle.setType("triangle");
	
		main_circle.setCenter_x(0.0);
		main_circle.setCenter_y(0.0);
		Array8.add(main_circle);
		
		int i,j;
		int total_triangle = 0;
		double cordinate_x = 0.0;
		double cordinate_y = 0.0;	
		double small_length = small_triangle.getLength();
		double radius = main_circle.getRadius();

		/*BU DONGULERDE UCGENİN BUTUN KOSELERI CEMBER DENKLEMİ KULLANILARAK DAIRENIN ICINDE MI BULUNUR VE ONA GORE UCGENLER DUZ SEKILDE BASTIRILIR. (REFERANS cordinate_x ve cordinate_y NOKTALARINA GORE ISLEM YAPILIR)*/
		for(i = 0; i <= (2 * radius) ; ++i)
		{
			for(j = 0; j <= (2 *radius); ++j)
			{	
				/*BU DONGULERDE UCGENİN BUTUN KOSELERI CEMBER DENKLEMİ KULLANILARAK DAIRENIN ICINDE MI BULUNUR VE ONA GORE UCGENLER DUZ SEKILDE BASTIRILIR*/
				if( ( ( (cordinate_x - radius ) * (cordinate_x - radius) + (cordinate_y - radius ) * (cordinate_y - radius ) ) <= (radius * radius) )&&
					( ( (cordinate_x + (small_length / 2.0 ) - radius ) * (cordinate_x + (small_length / 2.0 ) - radius) + (cordinate_y - (small_length * Math.sqrt(3.0) / 2.0) - radius) * (cordinate_y - (small_length * Math.sqrt(3.0) / 2.0) - radius)) <= (radius * radius) ) &&
					( ( (cordinate_x + small_length - radius) * (cordinate_x + small_length - radius) + ((cordinate_y - radius ) * (cordinate_y - radius )) <= (radius * radius)))		
				   ) 
				{

					small_triangle.setCor_x1(cordinate_x);
					small_triangle.setCor_x2(cordinate_x + (small_length / 2.0));
					small_triangle.setCor_x3(cordinate_x + small_length);
					small_triangle.setCor_y1(cordinate_y);
					small_triangle.setCor_y2(cordinate_y - (small_length * Math.sqrt(3.0) / 2.0));
					small_triangle.setCor_y3(cordinate_y);
					
					double x1 = small_triangle.getCor_x1();
					double x2 = small_triangle.getCor_x2();
					double x3 = small_triangle.getCor_x3();
					
					double y1 = small_triangle.getCor_y1();
					double y2 = small_triangle.getCor_y2();
					double y3 = small_triangle.getCor_y3();
					
					small_triangle = new Triangle(small_length,x1,x2,x3,y1,y2,y3);
					
					Array8.add(small_triangle);
					

					cordinate_x = cordinate_x + small_length;	/*Koordinat icerdeyse ucgen uzunlugu kadar artirma	*/
					
					total_triangle = total_triangle + 1;

				}
				cordinate_x = cordinate_x + 1;	/*Koordinat disardaysa ucgen 1 artirma	*/			
			}
			cordinate_x = 0.0;				/*Koordinatlarin guncellenmesi	*/
			cordinate_y = cordinate_y + (small_length * Math.sqrt(3.0) / 2);
		}

		cordinate_x = 0.0;
		cordinate_y = 0.0;

		/*BU DONGULERDE UCGENİN BUTUN KOSELERI CEMBER DENKLEMİ KULLANILARAK DAIRENIN ICINDE MI BULUNUR VE ONA GORE UCGENLER TERS SEKILDE BASTIRILIR. (REFERANS cordinate_x ve cordinate_y NOKTALARINA GORE ISLEM YAPILIR)*/
		for(i = 0; i <= (2 * radius) ; ++i)
		{
			for(j = 0; j <= (2 *radius); ++j)
			{	
				/*BU DONGULERDE UCGENİN BUTUN KOSELERI CEMBER DENKLEMİ KULLANILARAK DAIRENIN ICINDE MI BULUNUR VE ONA GORE UCGENLER DUZ SEKILDE BASTIRILIR*/
				if( ( ( (cordinate_x + 3 * small_length / 2.0 - radius) * (cordinate_x + 3 * small_length / 2.0 - radius) + (cordinate_y - small_length * Math.sqrt(3.0) / 2.0 - radius) *(cordinate_y - small_length * Math.sqrt(3.0) / 2.0 - radius) ) <= (radius * radius))&&
					( ( (cordinate_x - radius ) * (cordinate_x - radius) + (cordinate_y - radius ) * (cordinate_y - radius ) ) <= (radius * radius) )&&
					( ( (cordinate_x + (small_length / 2.0 ) - radius ) * (cordinate_x + (small_length / 2.0 ) - radius) + (cordinate_y - (small_length * Math.sqrt(3.0) / 2.0) - radius) * (cordinate_y - (small_length * Math.sqrt(3.0) / 2.0) - radius)) <= (radius * radius) ) &&
					( ( (cordinate_x + small_length - radius) * (cordinate_x + small_length - radius) + ((cordinate_y - radius ) * (cordinate_y - radius )) <= (radius * radius)))	
				   	
				   ) 
				{
					small_triangle.setCor_x1(cordinate_x + (small_length / 2.0));
					small_triangle.setCor_x2(cordinate_x + small_length + (small_length / 2.0 ));
					small_triangle.setCor_x3(cordinate_x + small_length);
					small_triangle.setCor_y1(cordinate_y - (small_length * Math.sqrt(3.0) / 2.0));
					small_triangle.setCor_y2(cordinate_y - (small_length * Math.sqrt(3.0) / 2.0));
					small_triangle.setCor_y3(cordinate_y);
					
					double x1 = small_triangle.getCor_x1();
					double x2 = small_triangle.getCor_x2();
					double x3 = small_triangle.getCor_x3();
					
					double y1 = small_triangle.getCor_y1();
					double y2 = small_triangle.getCor_y2();
					double y3 = small_triangle.getCor_y3();
					
					small_triangle = new Triangle(small_length,x1,x2,x3,y1,y2,y3);
					
					Array8.add(small_triangle);
					
					cordinate_x = cordinate_x + small_length;	/*Koordinat icerdeyse ucgen uzunlugu kadar artirma	*/
					total_triangle = total_triangle + 1;

				}
				cordinate_x = cordinate_x + 1;		/*Koordinat disardaysa ucgen 1 artirma	*/		
			}
			cordinate_x = 0.0;
			cordinate_y = cordinate_y + (small_length * Math.sqrt(3.0) / 2);	/*Koordinatlarin guncellenmesi	*/
		}

		int Array8_size = Array8.size();

		shape_Array = new Shape[Array8_size];
		
		Array8.toArray(shape_Array);
		
		
		if(total_triangle > 0)
			System.out.printf("I can fit at %d small shapes into the main container.\nThe empty area (red) in %.3f.\n",
					total_triangle, main_circle.area() - total_triangle * small_triangle.area());
		else
			System.out.printf("Eror!! I can not fit any triangle to circle\n");
		
		return total_triangle;
		
	}
	/**
	 * 
	 * @param main_circle buyuk sekil
	 * @param small_circle kucuk sekil
	 * @return total_circle return eder kac sekil sigdigidir
	 */
	private int fitting_cir_in_cir(Circle main_circle, Circle small_circle)
	{
		ArrayList<Shape> Array9 = new ArrayList<Shape>();
		
		main_circle.setType("CIRCLE");
		small_circle.setType("circle");
		
		main_circle.setCenter_x(0.0);
		main_circle.setCenter_y(0.0);
		
		Array9.add(main_circle);

		int i,j;
		int total_circle = 0;

		double center_x = 0.0; 
		double center_y = 0.0;
		double radius = main_circle.getRadius();
		double small_radius = small_circle.getRadius();


		int counter_y = (int)((4 * radius) / ((small_radius + small_radius * Math.sqrt(3.0))));	/*Dongu sayisni bulma. Fazla bulunup tasan kisim konulmaz	*/
		int counter_x = (int)(2 * radius);

		/*BU DONGULERDE DAIRELERIN ICINE DAIRELERI IKI NOKTA ARASINDAKI UZAKLIK YARICAPTAN KUCUK OLMA KOSULU KULLANDIM*/
		for(i = 0; i < counter_y; ++i)
		{
			for(j = 0; j < counter_x; ++j)
			{	
				if(Math.sqrt(((radius - center_x - small_radius) * (radius - center_x- small_radius)) + ((radius - center_y - small_radius) * (radius - center_y - small_radius))) <= (radius - small_radius) )	/*Iki nokta arası uzaklık formulu	*/
				{
					small_circle.setCenter_x(center_x);
					small_circle.setCenter_y(center_y);
					
					Array9.add(small_circle);
					small_circle = new Circle(small_radius,center_x,center_y);
					
					total_circle = total_circle + 1;
				}							
				center_x = center_x + 2 * small_radius;	
			}
			if(i % 2 == 1)
				center_x = 0.0;	
			
			else if(i % 2 == 0)	
				center_x =  small_radius;	
		
			center_y = center_y + small_radius * Math.sqrt(3.0);

		}

		int Array9_size = Array9.size();
		
		shape_Array = new Shape[Array9_size];
		
		Array9.toArray(shape_Array);		
		
		if(total_circle > 0)
			System.out.printf("I can fit at %d small shapes into the main container.\nThe empty area (red) in %.3f.\n",
					total_circle, main_circle.area() - total_circle * small_circle.area());
		else
			System.out.printf("Eror!! I can not fit any circle to circle\n");
		
		return total_circle;
	}
}