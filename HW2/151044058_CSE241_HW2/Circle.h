#ifndef CIRCLE_H_
#define CIRCLE_H_
#include <iostream>
#include <fstream>

using namespace std;

class Circle
{

public:
	Circle(); /*No parameter constructor*/
	Circle(double temp_radius); /*Bir parametreli contructor*/	
	Circle(double temp_radius, double cX, double cY);	/*Iki parametreli constructor	*/

	double getRadius()const;	/*radius return eder	*/
 	double getCenter_x()const;	/*center_x return eder	*/
	double getCenter_y()const;	/*center_y return eder	*/
	void setRadius(double radiusValue); /*radius atar */
	void setCenter_x(double center_xValue);	/*center_x atar	*/
	void setCenter_y(double center_yValue);	/*center_y	atar*/
	void draw(ofstream& file);	/*Buyuk sekil cizdirme fonksiyonu	*/

private:
	/*Degiskenler*/
	double radius;
	double center_x;
	double center_y;
};

#endif