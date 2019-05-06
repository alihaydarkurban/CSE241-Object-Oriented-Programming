#include "Circle.h"

namespace HW5_151044058
{
	Circle :: Circle() : radius(500), center_x(500), center_y(500)
	{ 
		static_total_area = static_total_area + area(); //Static alani arttirma
		static_total_PL = static_total_PL + perimeter(); // Static Cevreyi arttirma
	}

	Circle :: Circle(double temp_radius)throw(Circle_Error)
	{
		//Radius un negatif gelmesi durumunda throw yaptim
		if(temp_radius <= 0)
			throw Circle_Error();
		radius = temp_radius;
		static_total_area = static_total_area + area(); //Static alani arttirma
		static_total_PL = static_total_PL + perimeter();	// Static Cevreyi arttirma
	}

	Circle :: Circle(double temp_radius, double cX, double cY)throw(Circle_Error)
	{
		//Radiusun ve koordinatlarin hatali gelemsi durumunda throw yaptim
		if(temp_radius <= 0 || cX < 0 || cY < 0 ||
			cX > temp_radius || cY > temp_radius)
			throw Circle_Error();
		radius = temp_radius;
		center_x = cX;
		center_y = cY;
		static_total_area = static_total_area + area(); //Static alani arttirma
		static_total_PL = static_total_PL + perimeter();// Static Cevreyi arttirma
	}

	inline double Circle :: getRadius()const { return radius; }
	inline double Circle :: getCenter_x()const { return center_x; }
	inline double Circle :: getCenter_y()const { return center_y; }

	void Circle :: setRadius(double radiusValue) 
	{ 
		radius = radiusValue; 
	}
	void Circle :: setCenter_x(double center_xValue) 
	{ 
		center_x = center_xValue; 
	}
	void Circle :: setCenter_y(double center_yValue) 
	{ 
		center_y = center_yValue; 
	}
	string Circle :: getType()const
	{
		return type;
	}
	void Circle :: setType(string typeValue)
	{
		type = typeValue;
	}
	double Circle :: perimeter()
	{
		const double PI = M_PI;
		return(2 * PI * radius);
	}
	double Circle :: area()
	{
		const double PI = M_PI;
		return(PI * radius * radius);
	}
	void Circle :: draw_Shape(ostream& file)
	{
		if(this->getType() == "CIRCLE")//Buyuk sekillleri kirmizi yazdirmak icin
		{
			file << "<circle cx=" << "\"" << this->getCenter_x() << "\"" << " cy=" << "\"" <<  this->getCenter_y() << "\"" << " r="
				 << "\"" << this->getRadius() << "\"" <<  " fill=\"red\" stroke=\"white\" />\n";
		}
		else if(this->getType() == "circle")//Kucuk sekillleri yesil yazdirmak icin
		{
			file << "<circle cx=" << "\"" << this->getCenter_x() << "\"" << " cy=" << "\"" <<  this->getCenter_y() << "\"" << " r="
				 << "\"" << this->getRadius() << "\"" <<  " fill=\"green\" stroke=\"white\" />\n";
		}

	}

	Shape& Circle :: operator++() //Prefix
	{
		center_x = center_x + 1;
		center_y = center_y + 1;
		return *this;
	}
	Shape& Circle :: operator++(int ignore) //Postfix
	{
		double center_x_temp = center_x;
		double center_y_temp = center_y;
		center_x_temp = center_x_temp + 1;
		center_y_temp = center_y_temp + 1;
		center_x = center_x_temp;
		center_y = center_y_temp;

		return *this;
	}

	Shape& Circle :: operator--() //Prefix
	{
		center_x = center_x - 1;
		center_y = center_y - 1;
		return *this;
	}
	Shape& Circle :: operator--(int ignore) //Postfix
	{
		double center_x_temp = center_x;
		double center_y_temp = center_y;
		center_x_temp = center_x_temp - 1;
		center_y_temp = center_y_temp - 1;
		center_x = center_x_temp;
		center_y = center_y_temp;

		return *this;
	}

	const Circle Circle :: operator+(double bigger)const // Radiusa double ekler ve objeyi return eder
	{
		return(Circle((radius + bigger),center_x,center_y));
	}

	const Circle Circle :: operator-(double smaller)const	// Radiusdan double cikarir ve objeyi return eder
	{
		return(Circle((radius - smaller),center_x,center_y));
	}

	double Circle :: return_total_area() //Static toplam alani return eder
	{
		return static_total_area;
	}
	double Circle :: return_total_PL() //Static toplam cevreyi return eder
	{
		return static_total_PL;
	}
}