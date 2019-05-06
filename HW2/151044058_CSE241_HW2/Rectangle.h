#ifndef RECTANGLE_H_
#define RECTANGLE_H_
#include <iostream>	
#include <fstream>

using namespace std;

class Rectangle
{

public:
	Rectangle();	/*No parameter constructor*/
	Rectangle(double temp_width, double temp_height);	/*Iki parametreliconstructor*/
	Rectangle(double temp_width, double temp_height, double temp_cordinate_x, double temp_cordinate_y); /*Dort parametreliconstructor */
	
	double getWidth()const;	/*Width return eder	*/
	double getHeight()const; /*Height return eder	*/
	double getCor_x()const;	/*cordinate_x return eder	*/
	double getCor_y()const; /*cordinate_y return eder	*/
	void setWidth(double widthValue);	/*Width atar	*/
	void setHeight(double heightValue);	/*Height atar	*/
	void setCor_x(double cordinate_xValue);	/*cordinate_x atar	*/
	void setCor_y(double cordinate_yValue);	/*cordinate_y atar*/
	void draw(ofstream& file);	/*Buyuk sekil cizdirme	*/

private:
	/*Degiskenler	*/
	double width;
	double height;
	double cordinate_x;
	double cordinate_y;
};

#endif