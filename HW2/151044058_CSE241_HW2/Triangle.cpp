#include <iostream>
#include <fstream>

#include "Triangle.h"

Triangle :: Triangle()
{
	length = 600, cordinate_x1 = 300, cordinate_x2 = 0, cordinate_x3 = 600;
	cordinate_y1 = 0.0, cordinate_y2 = (600.0 * sqrt(3.0) / 2.0), cordinate_y3 = (600.0 * sqrt(3.0) / 2.0);
}

Triangle ::	Triangle(double temp_length)
{
	length = temp_length;
}

Triangle ::Triangle(double temp_length, double x1, double x2, double x3, double y1, double y2, double y3)
{
	length = temp_length;
	cordinate_x1 = x1;
	cordinate_x2 = x2;
	cordinate_x3 = x3;
	cordinate_y1 = y1;
	cordinate_y2 = y2;
	cordinate_y3 = y3;
}

double Triangle :: getLength()const 
{ 
	return length; 
}
double Triangle :: getCor_x1()const 
{ 
	return cordinate_x1; 
}
double Triangle :: getCor_x2()const 
{ 
	return cordinate_x2; 
}
double Triangle :: getCor_x3()const 
{ 
	return cordinate_x3; 
}
double Triangle :: getCor_y1()const 
{ 
	return cordinate_y1; 
}
double Triangle :: getCor_y2()const 
{ 
	return cordinate_y2; 
}
double Triangle :: getCor_y3()const 
{ 
	return cordinate_y3; 
}
void Triangle :: setLength(double lengthValue) 
{ 
	length = lengthValue; 
}
void Triangle :: setCor_x1(double cordinate_x1Value) 
{ 
	cordinate_x1 = cordinate_x1Value;
}
void Triangle :: setCor_x2(double cordinate_x2Value) 
{ 
	cordinate_x2 = cordinate_x2Value; 
}
void Triangle :: setCor_x3(double cordinate_x3Value) 
{ 
	cordinate_x3 = cordinate_x3Value; 
}
void Triangle :: setCor_y1(double cordinate_y1Value) 
{ 
	cordinate_y1 = cordinate_y1Value; 
}
void Triangle :: setCor_y2(double cordinate_y2Value) 
{ 
	cordinate_y2 = cordinate_y2Value;
}
void Triangle :: setCor_y3(double cordinate_y3Value) 
{ 
	cordinate_y3 = cordinate_y3Value; 
}
void Triangle :: draw(ofstream& file)
{
	if(file.is_open())
		file << "<polygon points=" << "\"" << getCor_x1() << " " << getCor_y1() << " " << getCor_x2() << " " << getCor_y2() << " " 
			 << getCor_x3() << " " << getCor_y3() << "\"" << " fill=\"red\" stroke=\"white\" />\n" ;

}