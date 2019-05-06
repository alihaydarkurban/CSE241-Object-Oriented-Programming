#include <iostream>
#include <fstream>

#include "Circle.h"

Circle :: Circle() : radius(500), center_x(500), center_y(500)
{ 
	static_total_area = static_total_area + area(); //Static alani arttirma
	static_total_PL = static_total_PL + perimeter_length(); // Static Cevreyi arttirma
}

Circle :: Circle(double temp_radius)
{
	radius = temp_radius;
	static_total_area = static_total_area + area(); //Static alani arttirma
	static_total_PL = static_total_PL + perimeter_length();	// Static Cevreyi arttirma
}

Circle :: Circle(double temp_radius, double cX, double cY)
{
	radius = temp_radius;
	center_x = cX;
	center_y = cY;
	static_total_area = static_total_area + area(); //Static alani arttirma
	static_total_PL = static_total_PL + perimeter_length();// Static Cevreyi arttirma
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
double Circle :: perimeter_length()const
{
	const double PI = M_PI;
	return(2 * PI * radius);
}
double Circle :: area()const
{
	const double PI = M_PI;
	return(PI * radius * radius);
}
ostream& operator<<(ostream& file, Circle temp_circle) // << operatorunun overload etme ve file return etme
{
	file << "<circle cx=" << "\"" << temp_circle.getCenter_x() << "\"" << " cy=" << "\"" <<  temp_circle.getCenter_y() << "\"" << " r="
		 << "\"" << temp_circle.getRadius() << "\"" <<  " fill=\"red\" stroke=\"white\" />\n";

	return file;
}

const Circle Circle :: operator++() //Prefix
{
	center_x = center_x + 1;
	center_y = center_y + 1;
	return Circle(radius, center_x, center_y);
}
const Circle Circle :: operator++(int ignore) //Postfix
{
	double center_x_temp = center_x;
	double center_y_temp = center_y;
	center_x_temp = center_x_temp + 1;
	center_y_temp = center_y_temp + 1;
	center_x = center_x_temp;
	center_y = center_y_temp;

	return Circle(radius, center_x, center_y);
}

const Circle Circle :: operator--() //Prefix
{
	center_x = center_x - 1;
	center_y = center_y - 1;
	return Circle(radius, center_x, center_y);
}
const Circle Circle :: operator--(int ignore) //Postfix
{
	double center_x_temp = center_x;
	double center_y_temp = center_y;
	center_x_temp = center_x_temp - 1;
	center_y_temp = center_y_temp - 1;
	center_x = center_x_temp;
	center_y = center_y_temp;

	return Circle(radius, center_x, center_y);
}

const Circle Circle :: operator+(double bigger)const // Radiusa double ekler ve objeyi return eder
{
	return(Circle((radius + bigger),center_x,center_y));
}

const Circle Circle :: operator-(double smaller)const	// Radiusdan double cikarir ve objeyi return eder
{
	return(Circle((radius - smaller),center_x,center_y));
}
bool operator==(const Circle& circle1, const Circle& circle2 ) //Alan kiyaslamasi yaparak == operatorunu overload etme
{
	double const min = 0.00001;	//Double sayilarin karsilastirilmasi icin
	return (abs(circle1.area()-circle2.area()) < min);
}

bool operator!=(const Circle& circle1, const Circle& circle2 )	//Alan kiyaslamasi yaparak != operatorunu overload etme
{
	return(!(circle1 == circle2));
}
bool operator>(const Circle& circle1, const Circle& circle2)	//Alan kiyaslamasi yaparak > operatorunu overload etme
{
	double const min = 0.00001;	//Double sayilarin karsilastirilmasi icin
	return((circle1.area() - circle2.area()) > min);
}
bool operator<=(const Circle& circle1, const Circle& circle2)	//Alan kiyaslamasi yaparak <= operatorunu overload etme
{
	return(!(circle1 > circle2)); 
}
double Circle :: return_total_area() //Static toplam alani return eder
{
	return static_total_area;
}
double Circle :: return_total_PL() //Static toplam cevreyi return eder
{
	return static_total_PL;
}