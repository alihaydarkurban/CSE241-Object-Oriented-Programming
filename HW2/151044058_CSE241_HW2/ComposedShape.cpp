#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <cstdlib>

#include "ComposedShape.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Circle.h"

ComposedShape :: ComposedShape()
{
	/*Empty*/
}

/*Mainden gelen objeleri ComposedShape deki objelere atar.	*/
ComposedShape :: ComposedShape(Rectangle Cmain_rectangle, Rectangle Csmall_rectangle)
{
	main_rectangle = Cmain_rectangle;
	small_rectangle = Csmall_rectangle;

}
/*Mainden gelen objeleri ComposedShape deki objelere atar.	*/
ComposedShape :: ComposedShape(Rectangle Cmain_rectangle, Triangle Csmall_triangle)
{
	main_rectangle = Cmain_rectangle;
	small_triangle = Csmall_triangle;

}
/*Mainden gelen objeleri ComposedShape deki objelere atar.	*/
ComposedShape :: ComposedShape(Rectangle Cmain_rectangle, Circle Csmall_circle)
{
	main_rectangle = Cmain_rectangle;
	small_circle = Csmall_circle;

}
/*Mainden gelen objeleri ComposedShape deki objelere atar.	*/
ComposedShape :: ComposedShape(Triangle Cmain_triangle, Rectangle Csmall_rectangle)
{
	main_triangle = Cmain_triangle;
	small_rectangle = Csmall_rectangle;
}
/*Mainden gelen objeleri ComposedShape deki objelere atar.	*/
ComposedShape :: ComposedShape(Triangle Cmain_triangle, Triangle Csmall_triangle)
{
	main_triangle = Cmain_triangle;
	small_triangle = Csmall_triangle;
}
/*Mainden gelen objeleri ComposedShape deki objelere atar.	*/
ComposedShape :: ComposedShape(Triangle Cmain_triangle, Circle Csmall_circle)
{
	main_triangle = Cmain_triangle;
	small_circle = Csmall_circle;
}
/*Mainden gelen objeleri ComposedShape deki objelere atar.	*/
ComposedShape :: ComposedShape(Circle Cmain_circle, Rectangle Csmall_rectangle)
{
	main_circle = Cmain_circle;
	small_rectangle = Csmall_rectangle;
}
/*Mainden gelen objeleri ComposedShape deki objelere atar.	*/
ComposedShape :: ComposedShape(Circle Cmain_circle, Triangle Csmall_triangle)
{
	main_circle = Cmain_circle;
	small_triangle = Csmall_triangle;
}
/*Mainden gelen objeleri ComposedShape deki objelere atar.	*/
ComposedShape :: ComposedShape(Circle Cmain_circle, Circle Csmall_circle)
{
	main_circle = Cmain_circle;
	small_circle = Csmall_circle;
	
}

inline vector <Rectangle> ComposedShape :: getVector_Rectangle() { return rec_vector; }
inline vector <Triangle> ComposedShape :: getVector_Triangle() { return tri_vector; }
inline vector <Circle> ComposedShape :: getVector_Circle(){	return cir_vector; }

inline char ComposedShape :: getbigChar()const { return bigChar; }
inline char ComposedShape :: getsmallChar()const { return smallChar; }

void ComposedShape :: setBigChar(char bigCharValue) 
{ 
	bigChar = bigCharValue; 
}
void ComposedShape :: setSmallChar(char smallCharValue) 
{ 
	smallChar = smallCharValue; 
}

void ComposedShape :: optimalFit()
{
	if((getbigChar() == 'R' || getbigChar() == 'r') && (getsmallChar() == 'R' || getsmallChar() == 'r'))	/*Gelen karaktere gore gerekli fonksiyonu cagirma	*/
		fitting_rec_in_rec(main_rectangle, small_rectangle);
		
	else if((getbigChar() == 'R' || getbigChar() == 'r') && (getsmallChar() == 'T' || getsmallChar() == 't'))	/*Gelen karaktere gore gerekli fonksiyonu cagirma	*/	
		fitting_rec_in_tri(main_rectangle, small_triangle);

	else if((getbigChar() == 'R' || getbigChar() == 'r') && (getsmallChar() == 'C' || getsmallChar() == 'c')) 	/*Gelen karaktere gore gerekli fonksiyonu cagirma	*/
		fitting_rec_in_cir(main_rectangle, small_circle);

	else if((getbigChar() == 'T' || getbigChar() == 't') && (getsmallChar() == 'R' || getsmallChar() == 'r')) 	/*Gelen karaktere gore gerekli fonksiyonu cagirma	*/
		fitting_tri_in_rec(main_triangle, small_rectangle);

	else if((getbigChar() == 'T' || getbigChar() == 't') && (getsmallChar() == 'T' || getsmallChar() == 't')) 	/*Gelen karaktere gore gerekli fonksiyonu cagirma	*/
		fitting_tri_in_tri(main_triangle, small_triangle);

	else if((getbigChar() == 'T' || getbigChar() == 't') && (getsmallChar() == 'C' || getsmallChar() == 'c')) 	/*Gelen karaktere gore gerekli fonksiyonu cagirma	*/
		fitting_tri_in_cir(main_triangle, small_circle);

	else if((getbigChar() == 'C' || getbigChar() == 'c') && (getsmallChar() == 'R' || getsmallChar() == 'r')) 	/*Gelen karaktere gore gerekli fonksiyonu cagirma	*/
		fitting_cir_in_rec(main_circle, small_rectangle);

	else if((getbigChar() == 'C' || getbigChar() == 'c') && (getsmallChar() == 'T' || getsmallChar() == 't')) 	/*Gelen karaktere gore gerekli fonksiyonu cagirma	*/
		fitting_cir_in_tri(main_circle, small_triangle);

	else if((getbigChar() == 'C' || getbigChar() == 'c') && (getsmallChar() == 'C' || getsmallChar() == 'c')) 	/*Gelen karaktere gore gerekli fonksiyonu cagirma	*/
		fitting_cir_in_cir(main_circle, small_circle);

	else	/*Hatali karakter gelmesi durumu	*/
		cerr << "EROR!! THERE IS NOT ANY MATCHING FUNTION" << endl;
	
}

/*Kucuk rectangle cizdirme fonksiyonu	*/
void ComposedShape :: draw(ofstream& file, const vector<Rectangle>)
{
	int i;
	for(i = 0; i < rec_vector.size(); ++i)
	{
		if(file.is_open())
		{
			file << "<rect  x=" << "\"" << rec_vector[i].getCor_x() << "\"" << " y=" << "\"" << rec_vector[i].getCor_y() <<  "\"" << " width=" <<  "\""  << rec_vector[i].getWidth()  <<
				 "\"" << " height=" <<  "\"" <<   rec_vector[i].getHeight() << "\"" << " fill=\"green\" stroke=\"white\" />\n" ;
		}

	}
}

/*Kucuk triangle cizdirme fonksiyonu	*/
void ComposedShape :: draw(ofstream& file , const vector<Triangle>)
{
	int i;
	for(i = 0; i <tri_vector.size(); ++i )
	{
		if(file.is_open())
		{
			file << "<polygon points=" << "\"" << tri_vector[i].getCor_x1() << " " << tri_vector[i].getCor_y1() << " " << tri_vector[i].getCor_x2() << " " << tri_vector[i].getCor_y2() << " " 
			 << tri_vector[i].getCor_x3() << " " << tri_vector[i].getCor_y3() << "\"" << " fill=\"green\" stroke=\"white\" />\n" ;
		}
	}


}

/*Kucuk circle cizdirme fonksiyonu	*/
void ComposedShape :: draw(ofstream& file, const vector<Circle>)
{
	int i;
	for(i = 0; i < cir_vector.size(); ++i)
 	{
 		if(file.is_open())
 		{
 			file << "<circle cx=" << "\"" << cir_vector[i].getCenter_x() << "\"" << " cy=" << "\"" << cir_vector[i].getCenter_y() << "\"" << " r="
			 << "\"" << cir_vector[i].getRadius() << "\"" <<  " fill=\"green\" stroke=\"black\" />\n";
 		}
 	}
}


/*Bu fonksiyon once buyuk Rectangle cizdirir ve sonra hesaplamalari yapar koordinatlari vektore attiktan sonra kucuk rectangle cizdirir	*/
void ComposedShape :: fitting_rec_in_rec(Rectangle main_rectangle, Rectangle small_rectangle)
{	
	ofstream file;
	file.open("Rec_rec.svg");

	if(file.is_open())
		file << "<svg viewBox=\"1.1\"\n" << "baseProfile=\"full\"\n" << "xmlns=\"http:/" << "/www.w3.org/2000/svg\">\n";

	main_rectangle.draw(file);	/*Buyuk rectangle cizdirir	*/

	int i;
	decltype(i) j;
	auto total_rectangle = 0;
	int counter_x = main_rectangle.getWidth() / small_rectangle.getWidth() ;
	int counter_y = main_rectangle.getHeight() / small_rectangle.getHeight();
	auto start_x = 0.0;
	auto start_y = 0.0;
	small_rectangle.setCor_x(start_x);
	small_rectangle.setCor_y(start_y);

	int temp_mainWidth = main_rectangle.getWidth();
	int temp_mainHeight = main_rectangle.getHeight();
	int temp_smallWidth = small_rectangle.getWidth();
	int temp_smallHeight = small_rectangle.getHeight();

	/*Dikdorgenlerin koseleri ters sekilde birbirinin katiysa tam sigar o yuzden bu kosul var. Bosta yer kalmaz	*/
	if((temp_mainWidth % temp_smallHeight == 0) && (temp_mainHeight % temp_smallWidth == 0) )	
	{
		counter_x = main_rectangle.getHeight() / small_rectangle.getWidth() ;
		counter_y = main_rectangle.getWidth() / small_rectangle.getHeight();

		double temp1 = small_rectangle.getWidth();
		double temp2 = small_rectangle.getHeight();

		small_rectangle.setWidth(temp2);
		small_rectangle.setHeight(temp1);

		/*DONGULER ILE DIKDORTGENLERI SVG DOSYASINA YAZDIM	*/
		for(i = 0; i < counter_x; ++i)
		{
			for(j = 0; j < counter_y; ++j)
			{
				rec_vector.push_back(small_rectangle);

				start_x = start_x + small_rectangle.getWidth();
				small_rectangle.setCor_x(start_x);

				total_rectangle = total_rectangle + 1;
			}
			start_x = 0.0;
			small_rectangle.setCor_x(start_x);
			start_y = start_y + small_rectangle.getHeight();
			small_rectangle.setCor_y(start_y);
		}

		if(total_rectangle > 0)
		{
			cout << "I can fit at " <<  total_rectangle << " small shapes into the main container. "<< endl	
				 << "The empty area (red) in " << (main_rectangle.getWidth() * main_rectangle.getHeight()) - (total_rectangle *small_rectangle.getWidth() * small_rectangle.getHeight()) << "." << endl;
		}
		else
			cerr << "Eror!! I can not fit any rectangle to rectangle" << endl;
	}

	else
	{
		start_x = 0.0;
		start_y = 0.0;
		small_rectangle.setCor_x(start_x);
		small_rectangle.setCor_y(start_y);

		/*DONGULER ILE DIKDORTGENLERI YANYANA SVG DOSYASINA YAZDIM	*/
		for(i = 0; i < counter_y; ++i)
		{
			for(j = 0; j < counter_x; ++j)
			{
				rec_vector.push_back(small_rectangle);

				start_x = start_x + small_rectangle.getWidth();
				small_rectangle.setCor_x(start_x);
				total_rectangle = total_rectangle + 1;
			}
			start_x = 0.0;
			small_rectangle.setCor_x(start_x);
			start_y = start_y + small_rectangle.getHeight();
			small_rectangle.setCor_y(start_y);
		}

		double new_space_x = main_rectangle.getWidth() - (counter_x * small_rectangle.getWidth() );
		int new_counter_x = 0;
		int new_counter_y = 0;

		if(new_space_x >= small_rectangle.getHeight() )
		{
			new_counter_x = new_space_x / small_rectangle.getHeight();
			new_counter_y = main_rectangle.getHeight() / small_rectangle.getWidth();	
			start_x = counter_x * small_rectangle.getWidth();
			start_y = 0.0;
			small_rectangle.setCor_x(start_x);
			small_rectangle.setCor_y(start_y);

			double temp3 = small_rectangle.getWidth();
			double temp4 = small_rectangle.getHeight();

			small_rectangle.setWidth(temp4);
			small_rectangle.setHeight(temp3);

			/*DONGULER ILE DIKDORTGENLERI YAN CEVIRIP SAG TARAFTA SVG DOSYASINA YAZDIM	*/
			for(i = 0; i < new_counter_y; ++i)
			{
				for(j = 0; j < new_counter_x; ++j)
				{
					rec_vector.push_back(small_rectangle);

					start_x = start_x + small_rectangle.getWidth();
					small_rectangle.setCor_x(start_x);

					total_rectangle = total_rectangle + 1;
				}

				start_x = counter_x * small_rectangle.getHeight();
				start_y = start_y + small_rectangle.getHeight();
				small_rectangle.setCor_x(start_x);
				small_rectangle.setCor_y(start_y);
				
			}
		}

		int new_space_y = main_rectangle.getHeight() - (counter_y * small_rectangle.getHeight());	

		int new_counter_x1 = 0;
		int new_counter_y1 = 0;

		if(new_space_y >= small_rectangle.getWidth())	
		{
			new_counter_x1 = main_rectangle.getWidth()  / small_rectangle.getHeight();
			new_counter_y1 = new_space_y / small_rectangle.getWidth();

			start_x = 0.0;
			start_y = counter_y * small_rectangle.getHeight();
			small_rectangle.setCor_x(start_x);
			small_rectangle.setCor_y(start_y);	

			double temp1 = small_rectangle.getWidth();
			double temp2 = small_rectangle.getHeight();

			small_rectangle.setWidth(temp2);
			small_rectangle.setHeight(temp1);

			/*DONGULER ILE DIKDORTGENLERI YAN CEVIRIP ALT TARAFA SVG DOSYASINA YAZDIM	*/
			for(i = 0; i < new_counter_y1; ++i)
			{
				for(j = 0; j < new_counter_x1; ++j)
				{
					rec_vector.push_back(small_rectangle);

					start_x = start_x + small_rectangle.getWidth();
					small_rectangle.setCor_x(start_x);

					total_rectangle = total_rectangle + 1;
				}

				start_x = 0.0;
				start_y = start_y + small_rectangle.getHeight();
				small_rectangle.setCor_x(start_x);
				small_rectangle.setCor_y(start_y);				
			}
		}
	}

	if(total_rectangle > 0)
	{
		cout << "I can fit at " <<  total_rectangle << " small shapes into the main container. "<< endl							/*Ekrana bilgileri bastirma	*/
			 << "The empty area (red) in " << (main_rectangle.getWidth() * main_rectangle.getHeight()) - (total_rectangle *small_rectangle.getWidth() * small_rectangle.getHeight()) << "." << endl;
	}
	else
		cerr << "Eror!! I can not fit any rectangle to rectangle" << endl;

	draw(file,rec_vector);	/*Vektore atanan objeleri kullanarak kucuk rectangle cizer	*/

	if(file.is_open())
		file << "\n</svg>";	
	
	file.close();
}
/*Bu fonksiyon once buyuk Rectangle cizdirir ve sonra hesaplamalari yapar koordinatlari vektore attiktan sonra kucuk triangle cizdirir	*/
void ComposedShape :: fitting_rec_in_tri(Rectangle main_rectangle, Triangle small_triangle)
{
	ofstream file;
	file.open("Rec_tri.svg");

	if(file.is_open())
		file << "<svg viewBox=\"1.1\"\n" << "baseProfile=\"full\"\n" << "xmlns=\"http:/" << "/www.w3.org/2000/svg\">\n";

	main_rectangle.draw(file);	/*Buyuk rectangle cizdirir	*/

	int i;
	decltype(i) j;
	double x1 = small_triangle.getLength() / 2.0 , y1 = 0.0;
	double x2 = 0.0,  y2 = small_triangle.getLength() * sqrt(3.0) / 2.0;
	double x3 = small_triangle.getLength() , y3 = small_triangle.getLength() * sqrt(3.0) / 2.0;

	small_triangle.setCor_x1(x1), small_triangle.setCor_y1(y1);
	small_triangle.setCor_x2(x2), small_triangle.setCor_y2(y2);
	small_triangle.setCor_x3(x3), small_triangle.setCor_y3(y3);

	int counter_x1 = main_rectangle.getWidth() / small_triangle.getLength();
	int counter_y1 = main_rectangle.getHeight() / (small_triangle.getLength() * sqrt(3.0) / 2.0);

	auto total_triangle = 0;

	/*BU DONGULERLE UCGENLERI DUZ SEKILDE SVG DOSYASINA BASTIRDIM*/
	for(i = 0; i < counter_y1; ++i)
	{
		for(j = 0; j < counter_x1; ++j)
		{
			tri_vector.push_back(small_triangle);

			total_triangle = total_triangle + 1;	/*Objeyi vektore atama */

			x1 = x1 + small_triangle.getLength() ;
			x2 = x2 + small_triangle.getLength() ;	/*Koordinatlarin yenilenmesi	*/
			x3 = x3 + small_triangle.getLength() ;
			small_triangle.setCor_x1(x1);
			small_triangle.setCor_x2(x2);
			small_triangle.setCor_x3(x3);
		}
		x1 = small_triangle.getLength() / 2.0;
		x2 = 0.0;
		x3 = small_triangle.getLength();
		y1 = y1 + (small_triangle.getLength() * sqrt(3.0) / 2.0);
		y2 = y2 + (small_triangle.getLength() * sqrt(3.0) / 2.0);	/*Koordinatlarin yenilenmesi 	*/
		y3 = y3 + (small_triangle.getLength() * sqrt(3.0) / 2.0);
		
		small_triangle.setCor_x1(x1);
		small_triangle.setCor_x2(x2);
		small_triangle.setCor_x3(x3);	
		small_triangle.setCor_y1(y1);	/*Koordinatlarin yenilenmesi	*/
		small_triangle.setCor_y2(y2);
		small_triangle.setCor_y3(y3);
	}

	int counter_x2 = (main_rectangle.getWidth() - (small_triangle.getLength() / 2.0)) / small_triangle.getLength();	/*Dongu sayisini bulma	*/

	x1 = small_triangle.getLength() / 2.0 , y1 = 0.0;
	x2 = (small_triangle.getLength() / 2.0) + small_triangle.getLength(), y2 =  0.0; /*koordinatlarin belirlenmesi	*/
	x3 = small_triangle.getLength(), y3 = small_triangle.getLength() * sqrt(3.0) / 2.0;

	small_triangle.setCor_x1(x1);
	small_triangle.setCor_x2(x2);
	small_triangle.setCor_x3(x3);	
	small_triangle.setCor_y1(y1);
	small_triangle.setCor_y2(y2);
	small_triangle.setCor_y3(y3);

	/*BU DONGULERLE UCGENLERI TERS SEKILDE SVG DOSYASINA BASTIRDIM*/
	for(i = 0 ; i < counter_y1; ++i)
	{
		for(j = 0; j < counter_x2; ++j)
		{
			tri_vector.push_back(small_triangle);	/*Objeyi vektore atama */

			total_triangle = total_triangle + 1;

			x1 = x1 + small_triangle.getLength() ;
			if((x2 + small_triangle.getLength()) <= main_rectangle.getWidth())
				x2 = x2 + small_triangle.getLength() ;
			x3 = x3 + small_triangle.getLength() ;
			small_triangle.setCor_x1(x1);
			small_triangle.setCor_x2(x2);
			small_triangle.setCor_x3(x3);	
		}

		x1 = small_triangle.getLength() / 2.0;
		x2 = (small_triangle.getLength() / 2.0) + small_triangle.getLength();
		x3 = small_triangle.getLength();
		y1 = y1 + (small_triangle.getLength() * sqrt(3.0) / 2.0);		/*Koordinatların yenilenmesi	*/
		y2 = y2 + (small_triangle.getLength() * sqrt(3.0) / 2.0);
		y3 = y3 + (small_triangle.getLength() * sqrt(3.0) / 2.0);

		small_triangle.setCor_x1(x1);
		small_triangle.setCor_x2(x2);
		small_triangle.setCor_x3(x3);
		small_triangle.setCor_y1(y1);
		small_triangle.setCor_y2(y2);
		small_triangle.setCor_y3(y3);
	}

	if(total_triangle > 0)
    		cout << "I can fit at " <<  total_triangle << " small shapes into the main container. "<< endl									
		 		 << "The empty area (red) in " << (main_rectangle.getWidth() * main_rectangle.getHeight()) - (total_triangle * small_triangle.getLength() * small_triangle.getLength() * sqrt(3.0) / 4.0) << "." << endl;
	else
		cerr << "Eror!! I can not fit any triangle to rectangle" << endl;
	
	draw(file, tri_vector);	/*Vektore atanan objeleri kullanarak kucuk triangle cizer	*/

	if(file.is_open())
		file << "\n</svg>";	
	
	file.close();
}
/*Bu fonksiyon once buyuk Rectangle cizdirir ve sonra hesaplamalari yapar koordinatlari vektore attiktan sonra kucuk circle cizdirir	*/
void ComposedShape :: fitting_rec_in_cir(Rectangle main_rectangle, Circle small_circle)
{
	const double PI = M_PI;

	ofstream file;
	file.open("Rec_cir.svg");

	if(file.is_open())
		file << "<svg viewBox=\"1.1\"\n" << "baseProfile=\"full\"\n" << "xmlns=\"http:/" << "/www.w3.org/2000/svg\">\n";

	main_rectangle.draw(file);	/*Buyuk rectangle cizdirir	*/

	int i;
	decltype(i) j;
	int counter_x = main_rectangle.getWidth() / (2 * small_circle.getRadius());
	int counter_temp_y = main_rectangle.getHeight() / (2 * small_circle.getRadius());
	int counter_y = 2 * main_rectangle.getHeight() / ((small_circle.getRadius() +small_circle.getRadius()*sqrt(3.0)));		/*Baslangic noktalarinin ve dongu sayilarinin bulunmasi	*/
	
	double new_center_x = small_circle.getRadius();  
	double new_center_y = small_circle.getRadius();

	int total_circle_1 = counter_x * counter_temp_y;	/*Duz bir sekilde daireleri yerlestirince kac adet daire sigivaginin sayisi	*/
	
	auto total_circle_2 = 0;

	double center_x = small_circle.getRadius();
	double center_y = small_circle.getRadius();

	small_circle.setCenter_x(new_center_x);
	small_circle.setCenter_y(new_center_y);

	/*ASAGIDAKI DONGULER ILE DAIRELERIN BASLANGIC NOKTALARINI KESISTIKLERI YER YAPARAK KAC ADET SIGACAGINI BULDUM 	*/
	for(i = 0; i < counter_y; ++i)
	{
		for(j = 0; j < counter_x; ++j)
		{	
			new_center_x = new_center_x + 2 * small_circle.getRadius();

			if((new_center_x + small_circle.getRadius()) <= main_rectangle.getWidth() && (new_center_y + small_circle.getRadius() * sqrt(3.0)) <= main_rectangle.getHeight())
				total_circle_2 = total_circle_2 + 1;									
		}

		if(i % 2 == 1)
			new_center_x = small_circle.getRadius();
			
		else if(i % 2 == 0)
			new_center_x =  2 * small_circle.getRadius();
		
		if((new_center_y + small_circle.getRadius() * sqrt(3.0)) <= main_rectangle.getHeight() )
		{
			new_center_y = new_center_y + small_circle.getRadius() * sqrt(3.0);
			total_circle_2 = total_circle_2 + 1;
		}

	}

	if(total_circle_1 >= total_circle_2)	
	{
		center_x = small_circle.getRadius();
		center_y = small_circle.getRadius();

		small_circle.setCenter_x(center_x);
		small_circle.setCenter_y(center_y);

		counter_x = main_rectangle.getWidth() / (2 * small_circle.getRadius());	
		counter_temp_y =  main_rectangle.getHeight() / (2 * small_circle.getRadius());

		for(i = 0; i < counter_temp_y; ++i)
		{
			for(j = 0; j < counter_x; ++j)
			{
				cir_vector.push_back(small_circle);	/*Vektore objeyi atama	*/

				center_x = center_x + 2 * small_circle.getRadius();	
				small_circle.setCenter_x(center_x);	
			}
			center_x = small_circle.getRadius();
			center_y = center_y + 2 * small_circle.getRadius();	
			small_circle.setCenter_x(center_x);
			small_circle.setCenter_y(center_y);
		}
	}

	else
	{
		counter_y = 2 * main_rectangle.getHeight() / ((small_circle.getRadius() + small_circle.getRadius() * sqrt(3.0)));	/*Normal olmasi gereknenden fazla dondurmek icin tastigi yerlerde sgv ye ekleme yapilmaz	*/

		new_center_x = small_circle.getRadius();
		new_center_y = small_circle.getRadius();

		small_circle.setCenter_x(new_center_x);
		small_circle.setCenter_y(new_center_y);

		/*ASAGIDAKI DONGULER ILE DAIRELERIN BASLANGIC NOKTALARINI KESISTIKLERI YER YAPARAK SVG DOSYASINA YAZDIM 	*/
		for(i = 0; i < counter_y; ++i)
		{
			for(j = 0; j < counter_x; ++j)
			{			
				if((new_center_x + small_circle.getRadius()) <= main_rectangle.getWidth() && (new_center_y + small_circle.getRadius() * sqrt(3.0)) <= main_rectangle.getHeight())
				{
					cir_vector.push_back(small_circle);

					if(new_center_x + small_circle.getRadius() <= main_rectangle.getWidth())	/*Tasmadigi surece ekleme yapma	*/
					{
						new_center_x = new_center_x + 2 * small_circle.getRadius();
						small_circle.setCenter_x(new_center_x);
					}	
				}						
			}
			if(i % 2 == 1)
			{	
				new_center_x = small_circle.getRadius();	/*Koordinatlari yenileme	*/
				small_circle.setCenter_x(new_center_x);	
			
			}	
			else if(i % 2 == 0)
			{
				new_center_x =  2 * small_circle.getRadius();	/*Koordinatlari yenileme	*/
				small_circle.setCenter_x(new_center_x);
			}

			if((new_center_y + small_circle.getRadius() * sqrt(3.0)) <= main_rectangle.getHeight() )	/*Tasmadigi surece ekleme yapma	*/
			{
				new_center_y = new_center_y + small_circle.getRadius() * sqrt(3.0);
				small_circle.setCenter_y(new_center_y);
			}	
		}	
	}	

 	if(total_circle_1 <= 0 && total_circle_2 <= 0)	/*Hic daire sigmama durumu	*/
			cerr << "Eror!! I can not fit any circle to rectangle" << endl;

	else if(total_circle_1 >= total_circle_2)
		cout << "I can fit at " <<  total_circle_1 << " small shapes into the main container. "<< endl	                     /*Ekrana bilgileri bastirma	*/
					 << "The empty area (red) in " << (main_rectangle.getWidth() * main_rectangle.getHeight()) - (total_circle_1 * PI * small_circle.getRadius() * small_circle.getRadius()) << "." << endl;
	
	else if(total_circle_2 > total_circle_1)
		cout << "I can fit at " <<  total_circle_2 << " small shapes into the main container. "<< endl				/*Ekrana bilgileri bastirma	*/
				 	 << "The empty area (red) in " << (main_rectangle.getWidth() * main_rectangle.getHeight()) - (total_circle_2 * PI * small_circle.getRadius() * small_circle.getRadius()) << "." << endl;

 	draw(file, cir_vector);	/*Vektor kullanilarak vektore atamasi yapilan kucuk circle cizdirilir	*/

	if(file.is_open())
		file << "\n</svg>";	
	
	file.close();
}

void ComposedShape :: fitting_tri_in_rec(Triangle main_triangle, Rectangle small_rectangle)
{
	ofstream file;
	file.open("Tri_rec.svg");

	if(file.is_open())
		file << "<svg viewBox=\"1.1\"\n" << "baseProfile=\"full\"\n" << "xmlns=\"http:/" << "/www.w3.org/2000/svg\">\n";

	main_triangle.draw(file);	/*Buyuk triangle cizdirir	*/

	int i;
	decltype(i) j;
	double temp_length = main_triangle.getLength();
	double start_x = small_rectangle.getHeight() / sqrt(3.0);	
	double start_y = ((temp_length / 2.0) * sqrt(3.0) ) - (small_rectangle.getHeight());
	small_rectangle.setCor_x(start_x);
	small_rectangle.setCor_y(start_y);

	auto total_rectangle = 0;
	int counter_y = (temp_length * sqrt(3.0) / 2.0 ) / small_rectangle.getHeight();	/*Dongu sayisini bulma	*/
	int counter_x = temp_length / small_rectangle.getWidth();
	temp_length = temp_length - (small_rectangle.getHeight() / sqrt(3.0));

	/*BU DONGULER ILE DIKDORTGENLERI UCGENIN ICINE TASMAYACAK SEKILDE YERLESTIRDIM	*/
	for(i = 0; i < counter_y ; ++i)
	{
		for(j = 0; j < counter_x ; ++j)
		{
			if(start_x + small_rectangle.getWidth() <= temp_length)
			{
				rec_vector.push_back(small_rectangle);	/*Vektore objeyi atama	*/

				start_x = start_x + small_rectangle.getWidth();	/*Koordinatlarin yenilenmesi	*/
				small_rectangle.setCor_x(start_x);
				total_rectangle = total_rectangle + 1;
			}		
		}

		temp_length = temp_length - (small_rectangle.getHeight() / sqrt(3.0));	/*Ucgen icicn gecici uzunluklarin bulunması	*/
		counter_x = temp_length / small_rectangle.getWidth();		/*Yeni dongu sayisi	*/
		
		start_x = small_rectangle.getHeight() / sqrt(3.0);
		start_x = start_x + ((i + 1) * (small_rectangle.getHeight() / sqrt(3.0)) );	/*Koordinatlarin yenilenmesi	*/
		start_y = start_y - small_rectangle.getHeight();

		small_rectangle.setCor_x(start_x);
		small_rectangle.setCor_y(start_y);

	}

	if(total_rectangle > 0)
    	cout << "I can fit at " <<  total_rectangle << " small shapes into the main container. "<< endl												/*Bilgilendirme 	*/
		 		 << "The empty area (red) in " << (main_triangle.getLength() * main_triangle.getLength() * sqrt(3.0) / 4.0) - (total_rectangle * small_rectangle.getWidth() * small_rectangle.getHeight()) << "." << endl;
	else
		cerr << "Eror!! I can not fit any rectangle to triangle" << endl;	

	draw(file, rec_vector);	/*Vektoru kullanarak kucuk rectangle cizdirilir	*/

	if(file.is_open())
		file << "\n</svg>";	
	
	file.close();
}

void ComposedShape :: fitting_tri_in_tri(Triangle main_triangle, Triangle small_triangle)
{
	ofstream file;
	file.open("Tri_tri.svg");

	if(file.is_open())
		file << "<svg viewBox=\"1.1\"\n" << "baseProfile=\"full\"\n" << "xmlns=\"http:/" << "/www.w3.org/2000/svg\">\n";

	main_triangle.draw(file);

	int i;
	decltype(i) j;
	double x1 = main_triangle.getLength() / 2.0;
	double y1 = 0.0;
	double x2 = (main_triangle.getLength() / 2.0) - (small_triangle.getLength() / 2.0);
	double y2 = small_triangle.getLength() * sqrt(3.0) / 2.0;
	double x3 = main_triangle.getLength() / 2.0 + small_triangle.getLength() / 2.0;
	double y3 = small_triangle.getLength() * sqrt(3.0) / 2.0;

	small_triangle.setCor_x1(x1), small_triangle.setCor_x2(x2), small_triangle.setCor_x3(x3);	/*Koordinatlari atama	*/
	small_triangle.setCor_y1(y1), small_triangle.setCor_y2(y2), small_triangle.setCor_y3(y3);

	int counter_y = ((main_triangle.getLength() * sqrt(3.0) / 2.0 ) / (small_triangle.getLength() * sqrt(3.0) / 2.0));
	int counter_x = main_triangle.getLength() / small_triangle.getLength() ;
	auto total_triangle = 0;

	/*BU DONGULERLE UCGENLERI DUZ SEKILDE SVG DOSYASINA BASTIRDIM*/
	for(i = 0; i < counter_y; ++i)
	{
		for(j = 0 ; j < i + 1; ++j)
		{

			tri_vector.push_back(small_triangle);	/*Vektore objeyi atama	*/
			
			total_triangle = total_triangle + 1;

			x1 = x1 + small_triangle.getLength();
			x2 = x2 + small_triangle.getLength();	/*Koordinatlari yenileme	*/
			x3 = x3 + small_triangle.getLength();

			small_triangle.setCor_x1(x1), small_triangle.setCor_x2(x2), small_triangle.setCor_x3(x3);
		}

		x1 = main_triangle.getLength() / 2.0;
		x2 = main_triangle.getLength() / 2.0 - small_triangle.getLength() / 2.0;	/*Koordinatlari yenileme	*/
		x3 = main_triangle.getLength() / 2.0 + small_triangle.getLength() / 2.0;

		if((i + 1) < counter_y)
		{
			x1 = x1 - ((i+1) * (small_triangle.getLength() / 2.0));
			x2 = x2 - ((i+1) * (small_triangle.getLength() / 2.0));	/*Koordinatlari yenileme	*/
			x3 = x3 - ((i+1) * (small_triangle.getLength() / 2.0));
		}

		y1 = y1 + (small_triangle.getLength() * sqrt(3.0) / 2.0);
		y2 = y2 + (small_triangle.getLength() * sqrt(3.0) / 2.0);	/*Koordinatlari yenileme	*/
		y3 = y3 + (small_triangle.getLength() * sqrt(3.0) / 2.0);

		small_triangle.setCor_x1(x1), small_triangle.setCor_x2(x2), small_triangle.setCor_x3(x3);
		small_triangle.setCor_y1(y1), small_triangle.setCor_y2(y2), small_triangle.setCor_y3(y3);

	}

	int counter_y1 = counter_y - 1;

	x1 = (main_triangle.getLength() / 2.0) - (small_triangle.getLength() / 2.0);
	y1 = small_triangle.getLength() * sqrt(3.0) / 2.0;
	x2 = (main_triangle.getLength() / 2.0) + (small_triangle.getLength() / 2.0); /*Koordinatlari belirleme*/
	y2 = small_triangle.getLength() * sqrt(3.0) / 2.0;
	x3 = main_triangle.getLength() / 2.0;
	y3 = small_triangle.getLength() * sqrt(3.0) ;

	small_triangle.setCor_x1(x1), small_triangle.setCor_x2(x2), small_triangle.setCor_x3(x3);
	small_triangle.setCor_y1(y1), small_triangle.setCor_y2(y2), small_triangle.setCor_y3(y3);


	/*BU DONGULERLE UCGENLERI TERS SEKILDE SVG DOSYASINA BASTIRDIM*/
	for(i = 0; i < counter_y1; ++i)
	{
		for(j = 0; j < i + 1; ++j)
		{
			tri_vector.push_back(small_triangle);	/*Vektore objeyi atama	*/

			total_triangle = total_triangle + 1;

			x1 = x1 + small_triangle.getLength() ;
			x2 = x2 + small_triangle.getLength() ;		/*Koordinatlari yenileme	*/
			x3 = x3 + small_triangle.getLength() ;
			small_triangle.setCor_x1(x1), small_triangle.setCor_x2(x2), small_triangle.setCor_x3(x3);
		}

		x1 = (main_triangle.getLength() / 2.0) - (small_triangle.getLength() / 2.0);
		x2 = (main_triangle.getLength() / 2.0) + (small_triangle.getLength() / 2.0);		/*Koordinatlari yenileme	*/
		x3 = main_triangle.getLength() / 2.0;
		
		x1 = x1 - ((i + 1) * (small_triangle.getLength() / 2.0));
		x2 = x2 - ((i + 1) * (small_triangle.getLength() / 2.0));		/*Koordinatlari yenileme	*/
		x3 = x3 - ((i + 1) * (small_triangle.getLength() / 2.0));

		y1 = y1 + (small_triangle.getLength() * sqrt(3.0) / 2.0);
		y2 = y2 + (small_triangle.getLength() * sqrt(3.0) / 2.0);		/*Koordinatlari yenileme	*/
		y3 = y3 + (small_triangle.getLength() * sqrt(3.0) / 2.0);

		small_triangle.setCor_x1(x1), small_triangle.setCor_x2(x2), small_triangle.setCor_x3(x3);
		small_triangle.setCor_y1(y1), small_triangle.setCor_y2(y2), small_triangle.setCor_y3(y3);
	
	}

	if(total_triangle > 0)
    	cout << "I can fit at " <<  total_triangle << " small shapes into the main container. "<< endl																
		 	 << "The empty area (red) in " << (main_triangle.getLength() * main_triangle.getLength() * sqrt(3.0) / 4.0) - (total_triangle * small_triangle.getLength() * small_triangle.getLength() * sqrt(3.0) / 4.0) << "." << endl;
	else
		cerr << "Eror!! I can not fit any triangle to triangle" << endl;

	draw(file, tri_vector);	/*Vektoru kullanarak kucuk triangle seklini cizdirme	*/

	if(file.is_open())
		file << "\n</svg>";	
	
	file.close();
}

void ComposedShape :: fitting_tri_in_cir(Triangle main_triangle, Circle small_circle)
{
	const double PI = M_PI;

	ofstream file;
	file.open("Tri_cir.svg");

	if(file.is_open())
		file << "<svg viewBox=\"1.1\"\n" << "baseProfile=\"full\"\n" << "xmlns=\"http:/" << "/www.w3.org/2000/svg\">\n";

	main_triangle.draw(file);	/*Buyuk triangle seklini cizdirme	*/

	int i;
	decltype(i) j;
	auto total_circle = 0;
	double center_x = main_triangle.getLength() / 2.0;	/*Koordinatlarin belirlenmesi	*/
	double center_y = 2 * small_circle.getRadius();

	small_circle.setCenter_x(center_x), small_circle.setCenter_y(center_y);	


	int counter_y = 2 * (main_triangle.getLength() * sqrt(3.0)  / 2.0 ) / (3 * small_circle.getRadius()) ;	/*Fazla dongu sayisi bulma. Burda tasan kisim svg ye yazdirilmayacak	*/

	/*BU DONGULERLE DAİRELERİ KESISIM NOKTALARINA YENI DAIRE GELICEK SEKILDE SVG DOSYASINA YAZDIRDIM	*/
	for(i = 0; i < counter_y; ++i)	
	{
		for(j = 0; j < i + 1 ; ++j)
		{
			cir_vector.push_back(small_circle);	/*Vektore objeyi atama	*/

			total_circle = total_circle + 1;

			center_x = center_x + (small_circle.getRadius() * 2);	
			small_circle.setCenter_x(center_x);
			
		}
		center_x = main_triangle.getLength() / 2.0;	
		center_x = center_x - ((i + 1) * small_circle.getRadius());	/*Koordinatlarin yenilenmesi	*/
		small_circle.setCenter_x(center_x);

		center_y = center_y + (small_circle.getRadius() * sqrt(3.0));

		if(center_y + small_circle.getRadius() <= main_triangle.getLength() * sqrt(3.0) / 2.0)	/*Tasma durumunun kontrolu	*/
			small_circle.setCenter_y(center_y);
		else	
			break;
	}

	if(total_circle > 0)
    	cout << "I can fit at " <<  total_circle << " small shapes into the main container. "<< endl										/*Bilgilendirme 	*/
		 	 << "The empty area (red) in " << (main_triangle.getLength() * main_triangle.getLength() * sqrt(3.0) / 4.0) - (total_circle * small_circle.getRadius() * small_circle.getRadius() * PI) << "." << endl;
	else
		cerr << "Eror!! I can not fit any circle to triangle" << endl;	

	draw(file, cir_vector);	/*Vektoru kullanarak kucuk circle sekillerini cizdirme	*/

	if(file.is_open())
		file << "\n</svg>";	
	
	file.close();

}

void ComposedShape :: fitting_cir_in_rec(Circle main_circle, Rectangle small_rectangle)
{
	const double PI = M_PI;

	ofstream file;
	file.open("Cir_rec.svg");

	if(file.is_open())
		file << "<svg viewBox=\"1.1\"\n" << "baseProfile=\"full\"\n" << "xmlns=\"http:/" << "/www.w3.org/2000/svg\">\n";

	main_circle.draw(file);	/*Buyuk circle seklini cizdirme	*/

	int i;
	decltype(i) j;
	auto total_rectangle = 0;
	auto cordinate_x = 0.0;
	auto cordinate_y = 0.0;	

	double radius = main_circle.getRadius();
	double small_width = small_rectangle.getWidth();
	double small_height = small_rectangle.getHeight();
	

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
				
				rec_vector.push_back(small_rectangle);	/*Vektore objeyi atama	*/

				total_rectangle = total_rectangle + 1;	
			
				cordinate_x = cordinate_x + small_width;
			}
			cordinate_x = cordinate_x + 1;			/*Dikdortgen sigmazsa 1 arttirma 	*/		
		}
		cordinate_x = 0.0;
		cordinate_y = cordinate_y + small_height;	/*Korrdinatlarin guncellenmesi	*/
	}   

	if(total_rectangle > 0)
    	cout << "I can fit at " <<  total_rectangle << " small shapes into the main container. "<< endl					/*Bilgilendirme	*/
		 	 << "The empty area (red) in " << (PI * main_circle.getRadius() * main_circle.getRadius()) - (total_rectangle * small_rectangle.getWidth() * small_rectangle.getHeight()) << "." << endl;
	else
		cerr << "Eror!! I can not fit any rectangle to circle" << endl;

	draw(file, rec_vector);	/*Vektoru kullanarak kucuk rectangle cizdirme	*/

	if(file.is_open())
		file << "\n</svg>";	
	
	file.close();
}

void ComposedShape :: fitting_cir_in_tri(Circle main_circle, Triangle small_triangle)
{
	const double PI = M_PI;

	ofstream file;
	file.open("Cir_tri.svg");

	if(file.is_open())
		file << "<svg viewBox=\"1.1\"\n" << "baseProfile=\"full\"\n" << "xmlns=\"http:/" << "/www.w3.org/2000/svg\">\n";

	main_circle.draw(file);	/*Buyuk circle seklini cizdirme	*/


	int i;
	decltype(i) j;
	auto total_triangle = 0;
	auto cordinate_x = 0.0;
	auto cordinate_y = 0.0;	
	double cordinate_x2, cordinate_x3, cordinate_y2, cordinate_y3;
	double small_length = small_triangle.getLength();
	double radius = main_circle.getRadius();

	/*BU DONGULERDE UCGENİN BUTUN KOSELERI CEMBER DENKLEMİ KULLANILARAK DAIRENIN ICINDE MI BULUNUR VE ONA GORE UCGENLER DUZ SEKILDE BASTIRILIR. (REFERANS cordinate_x ve cordinate_y NOKTALARINA GORE ISLEM YAPILIR)*/
	for(i = 0; i <= (2 * radius) ; ++i)
	{
		for(j = 0; j <= (2 *radius); ++j)
		{	
			/*BU DONGULERDE UCGENİN BUTUN KOSELERI CEMBER DENKLEMİ KULLANILARAK DAIRENIN ICINDE MI BULUNUR VE ONA GORE UCGENLER DUZ SEKILDE BASTIRILIR*/
			if( ( ( (cordinate_x - radius ) * (cordinate_x - radius) + (cordinate_y - radius ) * (cordinate_y - radius ) ) <= (radius * radius) )&&
				( ( (cordinate_x + (small_length / 2.0 ) - radius ) * (cordinate_x + (small_length / 2.0 ) - radius) + (cordinate_y - (small_length * sqrt(3.0) / 2.0) - radius) * (cordinate_y - (small_length * sqrt(3.0) / 2.0) - radius)) <= (radius * radius) ) &&
				( ( (cordinate_x + small_length - radius) * (cordinate_x + small_length - radius) + ((cordinate_y - radius ) * (cordinate_y - radius )) <= (radius * radius)))		
			   ) 
			{

				small_triangle.setCor_x1(cordinate_x);
				small_triangle.setCor_x2(cordinate_x + (small_length / 2.0));
				small_triangle.setCor_x3(cordinate_x + small_length);
				small_triangle.setCor_y1(cordinate_y);
				small_triangle.setCor_y2(cordinate_y - (small_length * sqrt(3.0) / 2.0));
				small_triangle.setCor_y3(cordinate_y);

				tri_vector.push_back(small_triangle);	/*Objeyi vektore atma	*/

				cordinate_x = cordinate_x + small_length;	/*Koordinat icerdeyse ucgen uzunlugu kadar artirma	*/
				
				total_triangle = total_triangle + 1;

			}
			cordinate_x = cordinate_x + 1;	/*Koordinat disardaysa ucgen 1 artirma	*/			
		}
		cordinate_x = 0.0;				/*Koordinatlarin guncellenmesi	*/
		cordinate_y = cordinate_y + (small_length * sqrt(3.0) / 2);
	}

	cordinate_x = 0.0;
	cordinate_y = 0.0;

	/*BU DONGULERDE UCGENİN BUTUN KOSELERI CEMBER DENKLEMİ KULLANILARAK DAIRENIN ICINDE MI BULUNUR VE ONA GORE UCGENLER TERS SEKILDE BASTIRILIR. (REFERANS cordinate_x ve cordinate_y NOKTALARINA GORE ISLEM YAPILIR)*/
	for(i = 0; i <= (2 * radius) ; ++i)
	{
		for(j = 0; j <= (2 *radius); ++j)
		{	
			/*BU DONGULERDE UCGENİN BUTUN KOSELERI CEMBER DENKLEMİ KULLANILARAK DAIRENIN ICINDE MI BULUNUR VE ONA GORE UCGENLER DUZ SEKILDE BASTIRILIR*/
			if( ( ( (cordinate_x + 3 * small_length / 2.0 - radius) * (cordinate_x + 3 * small_length / 2.0 - radius) + (cordinate_y - small_length * sqrt(3.0) / 2.0 - radius) *(cordinate_y - small_length * sqrt(3.0) / 2.0 - radius) ) <= (radius * radius))&&
				( ( (cordinate_x - radius ) * (cordinate_x - radius) + (cordinate_y - radius ) * (cordinate_y - radius ) ) <= (radius * radius) )&&
				( ( (cordinate_x + (small_length / 2.0 ) - radius ) * (cordinate_x + (small_length / 2.0 ) - radius) + (cordinate_y - (small_length * sqrt(3.0) / 2.0) - radius) * (cordinate_y - (small_length * sqrt(3.0) / 2.0) - radius)) <= (radius * radius) ) &&
				( ( (cordinate_x + small_length - radius) * (cordinate_x + small_length - radius) + ((cordinate_y - radius ) * (cordinate_y - radius )) <= (radius * radius)))	
			   	
			   ) 
			{
				small_triangle.setCor_x1(cordinate_x + (small_length / 2.0));
				small_triangle.setCor_x2(cordinate_x + small_length + (small_length / 2.0 ));
				small_triangle.setCor_x3(cordinate_x + small_length);
				small_triangle.setCor_y1(cordinate_y - (small_length * sqrt(3.0) / 2.0));
				small_triangle.setCor_y2(cordinate_y - (small_length * sqrt(3.0) / 2.0));
				small_triangle.setCor_y3(cordinate_y);

				tri_vector.push_back(small_triangle);	/*Objeyi vektore atma	*/

				cordinate_x = cordinate_x + small_length;	/*Koordinat icerdeyse ucgen uzunlugu kadar artirma	*/
				total_triangle = total_triangle + 1;

			}
			cordinate_x = cordinate_x + 1;		/*Koordinat disardaysa ucgen 1 artirma	*/		
		}
		cordinate_x = 0.0;
		cordinate_y = cordinate_y + (small_length * sqrt(3.0) / 2);	/*Koordinatlarin guncellenmesi	*/
	}

	if(total_triangle > 0)
    		cout << "I can fit at " <<  total_triangle << " small shapes into the main container. "<< endl					/*Bilgilendirme	*/
		 		 << "The empty area (red) in " << (PI * main_circle.getRadius() * main_circle.getRadius()) - (total_triangle * small_triangle.getLength() * small_triangle.getLength() * sqrt(3.0) / 4.0) << "." << endl;
	else
			cerr << "Eror!! I can not fit any triangle to circle" << endl;

	draw(file, tri_vector);	/*Vektoru kullanarak kucuk triangle cizdirme	*/

	if(file.is_open())
		file << "\n</svg>";	
	
	file.close();
}

void ComposedShape :: fitting_cir_in_cir(Circle main_circle, Circle small_circle)
{
	const double PI = M_PI;
	
	ofstream file;
	file.open("Cir_cir.svg");

	if(file.is_open())
		file << "<svg viewBox=\"1.1\"\n" << "baseProfile=\"full\"\n" << "xmlns=\"http:/" << "/www.w3.org/2000/svg\">\n";

	main_circle.draw(file);	/*Buyuk circle seklini cizdirme	*/


	int i;
	decltype(i) j;
	auto total_circle = 0;

	double center_x = small_circle.getRadius(); 
	double center_y = small_circle.getRadius();
	double radius = main_circle.getRadius();
	double small_radius = small_circle.getRadius();

	int counter_y = (4 * radius) / ((small_radius + small_radius * sqrt(3.0)));	/*Dongu sayisni bulma. Fazla bulunup tasan kisim konulmaz	*/
	int counter_x = 2 * radius;

	/*BU DONGULERDE DAIRELERIN ICINE DAIRELERI IKI NOKTA ARASINDAKI UZAKLIK YARICAPTAN KUCUK OLMA KOSULU ILE SVG DOSYASINA YERLESTIRDIM*/
	for(i = 0; i < counter_y; ++i)
	{
		for(j = 0; j < counter_x; ++j)
		{	
			if(sqrt(((radius - center_x) * (radius - center_x)) + ((radius - center_y) * (radius - center_y)) ) <= (radius - small_radius) )	/*Iki nokta arası uzaklık formulu	*/
			{
				small_circle.setCenter_x(center_x);
				small_circle.setCenter_y(center_y);

				cir_vector.push_back(small_circle);	/*Vektore objeyi atma	*/

				total_circle = total_circle + 1;
			}							
			center_x = center_x + 2 * small_radius;	
		}
		if(i % 2 == 1)
			center_x = small_radius;	
		
		else if(i % 2 == 0)	
			center_x =  2 * small_radius;	
	
		center_y = center_y + small_radius * sqrt(3.0);

	}

	if(total_circle > 0)
    	cout << "I can fit at " <<  total_circle << " small shapes into the main container. "<< endl
		 	 << "The empty area (red) in " << (PI * main_circle.getRadius() * main_circle.getRadius()) - (total_circle * small_circle.getRadius() * small_circle.getRadius() * PI) << "." << endl;
	else
		cerr << "Eror!! I can not fit any circle to circle" << endl;

	draw(file, cir_vector);	/*Vektoru kullanarak kucuk circler cizdirme	*/

	if(file.is_open())
		file << "\n</svg>";	
	
	file.close();
}