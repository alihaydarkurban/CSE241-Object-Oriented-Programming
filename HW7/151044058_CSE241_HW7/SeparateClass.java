import javax.swing.JFrame;

/**
 * 
 * @author Ali Haydar Kurban
 *
 */
public class SeparateClass 
{
	/**
	 * Alanlarina gore siralama fonksiyonu
	 * @param shape_Array icinde shape vardir
	 */
	public static void sortShapes(Shape [] shape_Array)
	{
		int i,j;

		System.out.printf("Before Sorting\n");

		//Siralanmamis halini bastirir
		for(i = 0; i < shape_Array.length; ++i)
			System.out.printf("%.2f ", shape_Array[i].area());
			

		//Sirala islemi
		for(i = 0; i < shape_Array.length; ++i)
		{		
			for(j = i+1; j < shape_Array.length; ++j)
			{
				if(shape_Array[i].area() > shape_Array[j].area())
				{
					Shape [] temp = new Shape[1];
					temp[0] = shape_Array[i];
					shape_Array[i] = shape_Array[j];
					shape_Array[j] = temp[0];
				}
			}
		}
		//Siralanmis halini bastirir
		System.out.printf("\nAfter Sorting\n");
		for(i = 0; i < shape_Array.length; ++i)
			System.out.printf("%.2f ", shape_Array[i].area());
		System.out.printf("\n");
	}
	
	/**
	 * 
	 * @param shape_Array icinde shape vardir
	 * @return temp_Shape return eder. Convert edilmis halini
	 */
	public static Shape [] convertAll (Shape [] shape_Array)
	{
		Shape [] temp_Shape = new Shape[shape_Array.length];
		
		for(int i = 0; i < shape_Array.length; ++i)
		{
			if(shape_Array[i] instanceof Rectangle)
			{
				PolygonVect Pol1 = new PolygonVect((Rectangle)shape_Array[i]);
				temp_Shape[i] = (Shape)Pol1;
			}
			else if(shape_Array[i] instanceof Triangle)
			{
				PolygonVect Pol1 = new PolygonVect((Triangle)shape_Array[i]);
				temp_Shape[i] = (Shape)Pol1;
			}
			else if(shape_Array[i] instanceof Circle)
			{
				PolygonVect Pol1 = new PolygonVect((Circle)shape_Array[i]);
				temp_Shape[i] = (Shape)Pol1;
			}
		}
		return temp_Shape;
	}

	 /**
	  * Shape' leri cizdirir
	  * @param shape_Array icinde shape vardir
	  */
	public static void drawAll(Shape [] shape_Array)
	{
		String [] Name = new String [21];
		Name [0] = "RECTANGLE Rectangle";
		Name [1] = "RECTANGLE Triangle";
		Name [2] = "RECTANGLE Circle";
		Name [3] = "TRIANGLE Rectagle";
		Name [4] = "TRIANGLE Triangle";
		Name [5] = "TRIANGLE Circle";
		Name [6] = "CIRCLE Rectangle";
		Name [7] = "CIRCLE Triangle";
		Name [8] = "CIRCLE Circle";
		Name [9] = "PolygonDyn Rectangle";
		Name [10] = "PolygonDyn Triangle";
		Name [11] = "PolygonDyn Circle";
		Name [12] = "PolygonVect Rectangle";
		Name [13] = "PolygonVect Triangle";
		Name [14] = "PolygonVect Circle";
		Name [15] = "Inner Rectangle";
		Name [16] = "Inner Triangle";
		Name [17] = "Inner Circle";
		Name [18] = "Container Rectangle";
		Name [19] = "Container Triangle";
		Name [20] = "Container Circle";
		
		for(int i = 0; i < shape_Array.length; ++i)
		{
			JFrame temp_JFrame = new JFrame();
			if(shape_Array[i] instanceof Rectangle)
			{
				temp_JFrame.add((Rectangle)shape_Array[i]);
			}
			
			else if(shape_Array[i] instanceof Circle)
			{
				temp_JFrame.add((Circle)shape_Array[i]);
			}
			
			else if(shape_Array[i] instanceof Triangle)
			{
				temp_JFrame.add((Triangle)shape_Array[i]);
			}
			
			else if(shape_Array[i] instanceof ComposedShape)
			{
				temp_JFrame.add((ComposedShape)shape_Array[i]);
			}
			
			else if(shape_Array[i] instanceof PolygonDyn)
			{
				temp_JFrame.add((PolygonDyn)shape_Array[i]);
			}
			
			else if(shape_Array[i] instanceof PolygonVect)
			{
				temp_JFrame.add((PolygonVect)shape_Array[i]);
			}
			temp_JFrame.setTitle(Name[i]);
			temp_JFrame.setSize(1000, 1000);
			temp_JFrame.setVisible(true);
			temp_JFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

		}
	}
}