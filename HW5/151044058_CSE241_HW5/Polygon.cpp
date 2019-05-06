#include "Circle.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Polygon.h"
#include "Shape.h"

namespace HW5_151044058
{
	Polygon :: Point2D :: Point2D()
	{
		//Empty
	}
	Polygon :: Point2D :: Point2D(double x, double y)
	{
		koor_x = x;
		koor_y = y;
	}
	void Polygon :: Point2D :: setKoor_x(double koor_xValue) //set koor_x
	{
		koor_x = koor_xValue;
	}

	void Polygon :: Point2D :: setKoor_y(double koor_yValue)	//set koor_y
	{
		koor_y = koor_yValue;
	}
	double Polygon :: Point2D :: getKoor_x()const // get koor_x
	{
		return koor_x;
	}
	double Polygon :: Point2D :: getKoor_y()const // get koor_y
	{
		return koor_y;
	}
}