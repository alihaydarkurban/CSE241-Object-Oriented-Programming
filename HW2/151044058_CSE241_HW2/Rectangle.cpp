#include <iostream>
#include <fstream>

#include "Rectangle.h"

Rectangle :: Rectangle() : width(500), height(600), cordinate_x(0), cordinate_y(0)
{
	/*Empty	*/
}

Rectangle :: Rectangle(double temp_width, double temp_height)
{
	width = temp_width;
	height = temp_height;
}

Rectangle :: Rectangle(double temp_width, double temp_height, double temp_cordinate_x, double temp_cordinate_y)
{
	width = temp_width;
	height = temp_height;
	cordinate_x = temp_cordinate_x;
	cordinate_y = temp_cordinate_y;
}

double Rectangle :: getWidth()const 
{ 
	return width; 
}

double Rectangle :: getHeight()const 
{ 
	return height; 
}

double Rectangle ::  getCor_x()const	
{ 
	return cordinate_x; 
}

double Rectangle :: getCor_y()const 
{ 
	return cordinate_y; 
}

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

void Rectangle :: draw(ofstream& file)
{
	if(file.is_open())
		file << "<rect  x=" << "\"" << getCor_x() << "\"" << " y=" << "\"" << getCor_y() <<  "\"" << " width=" <<  "\""  << getWidth()  <<
			"\"" << " height=" <<  "\"" <<  getHeight() << "\"" << " fill=\"red\" stroke=\"white\" />\n" ;
}