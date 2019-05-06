#include "Rectangle.h"

namespace HW5_151044058
{
	Rectangle :: Rectangle() : width(500), height(600), cordinate_x(0), cordinate_y(0)
	{
		static_total_area = static_total_area + area(); //Satatic alani arttirir
		static_total_PL = static_total_PL + perimeter();	//Static cevreyi arttirir
	}

	Rectangle :: Rectangle(double temp_width, double temp_height)throw(Rectangle_Error)
	{
		if(temp_width <= 0 || temp_height <= 0) //Uzunluklarin negatif gelmesi durumda throw yaptim
			throw Rectangle_Error();

		width = temp_width;
		height = temp_height;
		static_total_area = static_total_area + area();	//Satatic alani arttirir
		static_total_PL = static_total_PL + perimeter(); 	//Static cevreyi arttirir
	}

	Rectangle :: Rectangle(double temp_width, double temp_height, double temp_cordinate_x, double temp_cordinate_y)throw(Rectangle_Error)
	{
		//Uzunluklarin ve koordinatlarin hatali gelmesi durumda throw yapiyorum
		if(temp_width <= 0 || temp_height <= 0 || temp_cordinate_x < 0 || temp_cordinate_y < 0 ||
			temp_cordinate_x > temp_width || temp_cordinate_x > temp_height || 
			temp_cordinate_y > temp_width || temp_cordinate_y > temp_height)
			throw Rectangle_Error();
		width = temp_width;
		height = temp_height;
		cordinate_x = temp_cordinate_x;
		cordinate_y = temp_cordinate_y;
		static_total_area = static_total_area + area();	//Satatic alani arttirir
		static_total_PL = static_total_PL + perimeter();	//Static cevreyi arttirir
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

	double Rectangle :: perimeter()
	{ 
		return(2 * (width + height)); 
	}
	double Rectangle :: area() 
	{
		return(width * height);
	}

	string Rectangle :: getType()const
	{
		return type;
	}
	void Rectangle :: setType(string typeValue)
	{
		type = typeValue;
	}

	void Rectangle :: draw_Shape(ostream& file)
	{
		if(this->getType() == "RECTANGLE") //Buyuk sekil cizdirirken renk beklirmek icin
		{
			file << "<rect  x=" << "\"" << this->getCor_x() << "\"" << " y=" << "\"" << this->getCor_y() <<  "\"" << " width=" <<  "\""  << this->getWidth()  <<
			"\"" << " height=" <<  "\"" <<  this->getHeight() << "\"" << " fill=\"red\" stroke=\"white\" />\n" ;	
		}
		else if(this->getType() == "rectangle") //Kucuk sekil cizdirirken renk belirlemek icin
		{
			file << "<rect  x=" << "\"" << this->getCor_x() << "\"" << " y=" << "\"" << this->getCor_y() <<  "\"" << " width=" <<  "\""  << this->getWidth()  <<
			"\"" << " height=" <<  "\"" <<  this->getHeight() << "\"" << " fill=\"green\" stroke=\"white\" />\n" ;
		}

	}

	Shape& Rectangle :: operator++()//Prefix ++ islemi
	{
		cordinate_x = cordinate_x + 1;
		cordinate_y = cordinate_y + 1;
		return *this;
	}
	Shape& Rectangle :: operator++(int ignore)//Postfix ++ islemi 
	{
		double cordinate_x_temp = cordinate_x;
		double cordinate_y_temp = cordinate_y;

		cordinate_x_temp = cordinate_x_temp + 1;
		cordinate_y_temp = cordinate_y_temp + 1;
		cordinate_x = cordinate_x_temp;
		cordinate_y = cordinate_y_temp;
		return *this;
	}

	Shape& Rectangle :: operator--()//Prefix -- islemi
	{
		cordinate_x = cordinate_x - 1;
		cordinate_y = cordinate_y - 1;
		return *this;
	}
	Shape& Rectangle :: operator--(int ignore)//Postfix -- islemi
	{
		double cordinate_x_temp = cordinate_x;
		double cordinate_y_temp = cordinate_y;

		cordinate_x_temp = cordinate_x_temp - 1;
		cordinate_y_temp = cordinate_y_temp - 1;
		cordinate_x = cordinate_x_temp;
		cordinate_y = cordinate_y_temp;
		return *this;
	}

	const Rectangle Rectangle :: operator+(double bigger)const //Kenarina bir double eklenmis objeyi return eder
	{
		return(Rectangle( (width + bigger),(height + bigger) ) );
	}

	const Rectangle Rectangle :: operator-(double smaller)const	//Kenarindan bir double cikartilmis ojeyi return eder
	{
		return(Rectangle( (width - smaller), (height - smaller) ) );
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