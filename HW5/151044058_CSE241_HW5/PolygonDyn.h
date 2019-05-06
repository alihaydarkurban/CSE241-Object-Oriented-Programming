#ifndef POLYGONDYN_H_
#define POLYGONDYN_H_
#include "Circle.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Polygon.h"
#include "Shape.h"

using namespace std;

namespace HW5_151044058
{
	class PolygonDyn : public Polygon
	{

	public:
		PolygonDyn(); //No parameter constructor
		
		PolygonDyn(const PolygonDyn& pol1); // Copy constructor
		~PolygonDyn(); // Destructor
		PolygonDyn& operator=(const PolygonDyn& pol1); // Assignment operator
		
		PolygonDyn(const Rectangle &rec);	//	conversion rec
		PolygonDyn(const Triangle &tri);	//	conversion tri
		PolygonDyn(const Circle &cir);		//	conversion cir

		Point2D& operator[](int index);
		
		
		int getSize()const;
		void setSize(int sizeValue);


		double area(){}
		double perimeter(){}
		Shape& operator++(){} //Prefix ++
		Shape& operator++(int ingnore){} //Postfix ++
		Shape& operator--(){} //Prefix --
		Shape& operator--(int ingnore){} //Postfix --
		void draw_Shape(ostream& file)override;

		Point2D * ptr;
	private:

		int size; // dynamic array size
		string type;

	};
}
#endif