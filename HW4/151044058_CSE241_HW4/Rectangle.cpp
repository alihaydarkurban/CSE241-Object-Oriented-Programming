#include <iostream>
#include <fstream>

#include "Rectangle.h"

namespace HW4
{
	Rectangle :: Rectangle() : width(500), height(600), cordinate_x(0), cordinate_y(0)
	{
		static_total_area = static_total_area + area(); //Satatic alani arttirir
		static_total_PL = static_total_PL + perimeter_length();	//Static cevreyi arttirir
	}

	Rectangle :: Rectangle(double temp_width, double temp_height)
	{
		width = temp_width;
		height = temp_height;
		static_total_area = static_total_area + area();	//Satatic alani arttirir
		static_total_PL = static_total_PL + perimeter_length(); 	//Static cevreyi arttirir
	}

	Rectangle :: Rectangle(double temp_width, double temp_height, double temp_cordinate_x, double temp_cordinate_y)
	{
		width = temp_width;
		height = temp_height;
		cordinate_x = temp_cordinate_x;
		cordinate_y = temp_cordinate_y;
		static_total_area = static_total_area + area();	//Satatic alani arttirir
		static_total_PL = static_total_PL + perimeter_length();	//Static cevreyi arttirir
	}

	inline double Rectangle :: getWidth()const { return width; }

	inline double Rectangle :: getHeight()const { return height; }

	inline double Rectangle ::  getCor_x()const	{ return cordinate_x; }

	inline double Rectangle :: getCor_y()const { return cordinate_y; }

	void Rectangle :: setWidth(double widthValue) 
	{ 
		width = widthValue; 
	}

	void Rectangle :: setHeight(double heightValue) 
	{ 
		height = heightValue; 
	}

	void Rectangle :: setCor_x(double cordinate_xValue) 
	{ 
		cordinate_x = cordinate_xValue;
	}

	void Rectangle :: setCor_y(double cordinate_yValue) 
	{ 
		cordinate_y = cordinate_yValue; 
	}

	double Rectangle :: perimeter_length()const
	{ 
		return(2 * (width + height)); 
	}
	double Rectangle :: area()const 
	{
		return(width * height);
	}

	ostream& operator<<(ostream& file, Rectangle temp_rectangle)	//Dosyaya yazar ve file' i return eder
	{

		file << "<rect  x=" << "\"" << temp_rectangle.getCor_x() << "\"" << " y=" << "\"" << temp_rectangle.getCor_y() <<  "\"" << " width=" <<  "\""  << temp_rectangle.getWidth()  <<
			"\"" << " height=" <<  "\"" <<  temp_rectangle.getHeight() << "\"" << " fill=\"red\" stroke=\"white\" />\n" ;

		return file;
	}

	const Rectangle Rectangle :: operator++()//Prefix ++ islemi
	{
		cordinate_x = cordinate_x + 1;
		cordinate_y = cordinate_y + 1;
		return Rectangle(width, height, cordinate_x, cordinate_y);
	}
	const Rectangle Rectangle :: operator++(int ignore)//Postfix ++ islemi 
	{
		double cordinate_x_temp = cordinate_x;
		double cordinate_y_temp = cordinate_y;

		cordinate_x_temp = cordinate_x_temp + 1;
		cordinate_y_temp = cordinate_y_temp + 1;
		cordinate_x = cordinate_x_temp;
		cordinate_y = cordinate_y_temp;
		return Rectangle(width, height, cordinate_x, cordinate_y);
	}

	const Rectangle Rectangle :: operator--()//Prefix -- islemi
	{
		cordinate_x = cordinate_x - 1;
		cordinate_y = cordinate_y - 1;
		return Rectangle(width, height, cordinate_x, cordinate_y);
	}
	const Rectangle Rectangle :: operator--(int ignore)//Postfix -- islemi
	{
		double cordinate_x_temp = cordinate_x;
		double cordinate_y_temp = cordinate_y;

		cordinate_x_temp = cordinate_x_temp - 1;
		cordinate_y_temp = cordinate_y_temp - 1;
		cordinate_x = cordinate_x_temp;
		cordinate_y = cordinate_y_temp;
		return Rectangle(width, height, cordinate_x, cordinate_y);
	}

	const Rectangle Rectangle :: operator+(double bigger)const //Kenarina bir double eklenmis objeyi return eder
	{
		return(Rectangle( (width + bigger),(height + bigger) ) );
	}

	const Rectangle Rectangle :: operator-(double smaller)const	//Kenarindan bir double cikartilmis ojeyi return eder
	{
		return(Rectangle( (width - smaller), (height - smaller) ) );
	}

	bool operator==(const Rectangle& rectangle1, const Rectangle& rectangle2 ) // Iki objenin alanlarinin == oldugunu kontrol eder
	{
		double const min = 0.0001;	//Double sayilarin karsilastirilmasi icin
		return(abs(rectangle1.area() - rectangle2.area()) < min);
	}
	bool operator!=(const Rectangle& rectangle1, const Rectangle& rectangle2 ) // Ustteki  == operetorunun NOT' ini cagirir
	{
		return(!(rectangle1 == rectangle2));
	}
	bool operator>(const Rectangle& rectangle1, const Rectangle& rectangle2 )	//Alan buyuklugunu kiyaslar
	{
		double const min = 0.00001;	//Double sayilarin karsilastirilmasi icin
		return((rectangle1.area() - rectangle2.area()) > min);
	}
	bool operator<=(const Rectangle& rectangle1, const Rectangle& rectangle2 )	 //Ustteki > operatorunun NOT ini cagirir
	{
		return(!(rectangle1 > rectangle2));
	}

	double Rectangle :: return_total_area()	//static fonksiyondur. Toplam static alani return eder.
	{
		return static_total_area;
	}
	double Rectangle :: return_total_PL()	//static fonksiyondur. Toplam static cevreyi return eder.
	{
		return static_total_PL;
	}
}