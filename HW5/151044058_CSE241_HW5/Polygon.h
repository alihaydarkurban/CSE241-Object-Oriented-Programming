#ifndef POLYGON_H_
#define POLYGON_H_
#include "Circle.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Polygon.h"
#include "Shape.h"

using namespace std;

namespace HW5_151044058
{
	class Polygon : public Shape
	{

	public:
		class Point2D
		{
		public:
			Point2D(); // No parameter constructor
			Point2D(double x, double y);  // Two parameters constuructor
			void setKoor_x(double koor_xValue); //set koor_x
			void setKoor_y(double koor_yValue);	//set koor_y
			double getKoor_x()const; // get koor_x
			double getKoor_y()const; // get koor_y

		protected:
			double koor_x;
			double koor_y;
		};
		
		//Pure virtual functions
		double area(){}
		double perimeter(){}
		Shape& operator++(){} //Prefix ++
		Shape& operator++(int ingnore){} //Postfix ++
		Shape& operator--(){} //Prefix --
		Shape& operator--(int ingnore){} //Postfix --
		void draw_Shape(ostream& file){}

	};
}
#endif