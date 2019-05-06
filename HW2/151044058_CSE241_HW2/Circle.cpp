#include <iostream>
#include <fstream>

#include "Circle.h"

Circle :: Circle() : radius(500), center_x(500), center_y(500)
{ 
	/*Empty	*/
}

Circle :: Circle(double temp_radius)
{
	radius = temp_radius;
}

Circle :: Circle(double temp_radius, double cX, double cY)
{
	radius = temp_radius;
	center_x = cX;
	center_y = cY;
}

inline double Circle :: getRadius()const {	return radius; }
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
void Circle :: draw(ofstream& file)
{
	if(file.is_open())
		file << "<circle cx=" << "\"" << getCenter_x() << "\"" << " cy=" << "\"" <<  getCenter_y() << "\"" << " r="
			 << "\"" << getRadius() << "\"" <<  " fill=\"red\" stroke=\"white\" />\n";
}