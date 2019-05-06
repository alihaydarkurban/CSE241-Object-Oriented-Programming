#ifndef POLYGONVECT_H_
#define POLYGONVECT_H_
#include "Circle.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Polygon.h"
#include "Shape.h"

using namespace std;

namespace HW5_151044058
{
	class PolygonVect : public Polygon
	{
	public:
		PolygonVect(); //No parameter constructor
		
		PolygonVect(const Rectangle &rec);	//	conversion rec
		PolygonVect(const Triangle &tri);	//	conversion tri
		PolygonVect(const Circle &cir);		//	conversion cir

		
		int getSize()const;
		void setSize(int sizeValue);

		vector<PolygonVect :: Point2D> getVector_Point2D();

		double area(){}
		double perimeter(){}
		Shape& operator++(){} //Prefix ++
		Shape& operator++(int ingnore){} //Postfix ++
		Shape& operator--(){} //Prefix --
		Shape& operator--(int ingnore){} //Postfix --
		void draw_Shape(ostream& file)override;


		private:
		vector<Point2D> vec_point2d;
	};
}
#endif