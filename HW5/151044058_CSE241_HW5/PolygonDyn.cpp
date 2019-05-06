#include "Circle.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Polygon.h"
#include "Shape.h"
#include "PolygonDyn.h"

namespace HW5_151044058
{
	PolygonDyn :: PolygonDyn()
	{
		//Empty
	}
	PolygonDyn :: PolygonDyn(const PolygonDyn& pol1) // Copy constructor
	{
		int i;
		size = pol1.size;
		ptr = new Point2D[size];
		for(i=0; i<size; ++i)
		{
			ptr[i] = pol1.ptr[i];
		}
	}

	PolygonDyn :: ~PolygonDyn()// Destructor
	{
		delete [] ptr;
		ptr = nullptr;
	}

	PolygonDyn& PolygonDyn :: operator=(const PolygonDyn& pol1)// Assignment operator
	{
		if(size != pol1.size)
		{
			size = pol1.size;
			delete [] ptr;
			ptr = new Point2D[size];
		}
		for(int i=0; i<size; ++i)
		{
			ptr[i] = pol1.ptr[i];
		}
		return *this;
	} 

	PolygonDyn :: PolygonDyn(const Rectangle &rec) //	conversion rectangle
	{
		
		int temp_size = 4;
		size = temp_size;
		ptr = new Point2D[size]; //Yer ayirma
		Point2D p1(rec.getCor_x(),rec.getCor_y());
		ptr[0] = p1;
		Point2D p2(rec.getCor_x() + rec.getWidth() ,rec.getCor_y());
		ptr[1] = p2;
		Point2D p3(rec.getCor_x() + rec.getWidth(),rec.getCor_y() + rec.getHeight());
		ptr[2] = p3;
		Point2D p4(rec.getCor_x(),rec.getCor_y() + rec.getHeight());
		ptr[3] = p4;

	}

	PolygonDyn :: PolygonDyn(const Triangle &tri) //	conversion triangle
	{
		int temp_size = 3;
		size = temp_size;
		ptr = new Point2D[size];	//Yer ayirma

		Point2D p1(tri.getCor_x1(),tri.getCor_y1());
		ptr[0] = p1;
		Point2D p2(tri.getCor_x2(),tri.getCor_y2());
		ptr[1] = p2;
		Point2D p3(tri.getCor_x3(),tri.getCor_y3());
		ptr[2] = p3;
	}

	PolygonDyn :: PolygonDyn(const Circle &cir)  //conversion circle
	{
		const double PI = M_PI;
		int i,temp_size = 100;
		size = temp_size;
		ptr = new Point2D[size]; //Yer ayirma

		//Circle donusum formulu
		for(i = 1; i <= size; ++i)
		{
			Point2D p1(cir.getCenter_x()+(cir.getRadius()*sin(((2.0*PI)/100.0)*i)), cir.getCenter_y()+(cir.getRadius()*cos(((2.0*PI)/100.0)*i)));
			ptr[i-1] = p1;
		}
	}

	void PolygonDyn :: draw_Shape(ostream& file)
	{
		int i;

		file << "<polygon points=\"";
		for(i = 0; i < this->size; ++i)
		{
			file << this->ptr[i].getKoor_x()<<" "<< this->ptr[i].getKoor_y()<<" ";	 
		}
		file<< "\" fill=\"blue\" stroke=\"white\" />\n" ;
	}
	
	PolygonDyn :: Point2D& PolygonDyn::operator[](int index) // idex operatoru
	{
		if(index >= size)
			index = size - 1;

		return ptr[index];

	}
	int PolygonDyn :: getSize()const
	{
		return size;
	}
	void PolygonDyn :: setSize(int sizeValue)
	{
		size = sizeValue;
	}
}