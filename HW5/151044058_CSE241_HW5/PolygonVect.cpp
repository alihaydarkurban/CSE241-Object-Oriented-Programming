#include "Circle.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Polygon.h"
#include "Shape.h"
#include "PolygonVect.h"

namespace HW5_151044058
{
	PolygonVect :: PolygonVect()
	{
		//Empty
	}
	
	PolygonVect :: PolygonVect(const Rectangle &rec) //	conversion rectangle
	{	
		Point2D p1(rec.getCor_x(),rec.getCor_y());
		vec_point2d.push_back(p1);
		Point2D p2(rec.getCor_x() + rec.getWidth() ,rec.getCor_y());
		vec_point2d.push_back(p2);
		Point2D p3(rec.getCor_x() + rec.getWidth(),rec.getCor_y() + rec.getHeight());
		vec_point2d.push_back(p3);
		Point2D p4(rec.getCor_x(),rec.getCor_y() + rec.getHeight());
		vec_point2d.push_back(p4);
		

	}

	PolygonVect :: PolygonVect(const Triangle &tri) //	conversion triangle
	{
		Point2D p1(tri.getCor_x1(),tri.getCor_y1());
		vec_point2d.push_back(p1);
		Point2D p2(tri.getCor_x2(),tri.getCor_y2());
		vec_point2d.push_back(p2);
		Point2D p3(tri.getCor_x3(),tri.getCor_y3());
		vec_point2d.push_back(p3);
	}

	PolygonVect :: PolygonVect(const Circle &cir)  //conversion circle
	{
		const double PI = M_PI;
		int i,temp_size = 100;

		for(i = 1; i <= temp_size; ++i)
		{
			Point2D p1(cir.getCenter_x()+(cir.getRadius()*sin(((2.0*PI)/100.0)*i)), cir.getCenter_y()+(cir.getRadius()*cos(((2.0*PI)/100.0)*i)));
			vec_point2d.push_back(p1);
		}
	}

	void PolygonVect :: draw_Shape(ostream& file)
	{
		int i;

		file << "<polygon points=\"";
		for(i = 0; i < this->vec_point2d.size(); ++i)
		{
			file << this->vec_point2d[i].getKoor_x()<<" "<< this->vec_point2d[i].getKoor_y()<<" ";	 
		}
		file<< "\" fill=\"black\" stroke=\"white\" />\n" ;

	}

	vector<PolygonVect :: Point2D> PolygonVect :: getVector_Point2D()
	{
		return vec_point2d;
	}
	
}