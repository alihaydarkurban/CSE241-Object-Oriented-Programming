#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

#include "Circle.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Polygon.h"

namespace HW4
{
	Polygon :: Polygon()
	{/*Empty*/}
	Polygon :: Polygon(const Polygon& pol1) // Copy constructor
	{
		int i;
		size = pol1.size;
		ptr = new Point2D[size];
		type=pol1.getType();
		for(i=0; i<size; ++i)
		{
			ptr[i] = pol1.ptr[i];
		}
	}

	Polygon :: ~Polygon()// Destructor
	{
		delete [] ptr;
	}

	Polygon& Polygon :: operator=(const Polygon& pol1)// Assignment operator
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

	Polygon::Point2D::Point2D()
	{

	}
	Polygon::Point2D::Point2D(double x, double y)
	{
		koor_x = x;
		koor_y = y;
	}

	Polygon :: Polygon(vector<Point2D> vec) //Noktaraları temsil etme fonksiyonu
	{
		int temp_size;
		temp_size = vec.size();

		size = temp_size;
		ptr = new Point2D[size];
		for(int i=0; i<size; ++i)
		{
			ptr[i] = vec[i];
		}

	}
	Polygon :: Polygon(const Rectangle &rec) //	conversion rectangle
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

	Polygon :: Polygon(const Triangle &tri) //	conversion triangle
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

	Polygon :: Polygon(const Circle &cir)  //conversion circle
	{
		const double PI = M_PI;
		int i,temp_size = 100;
		size = temp_size;
		ptr = new Point2D[size]; //Yer ayirma

		//Circle donusum formulu
		for(i=1;i<=size;++i)
		{
			if(cir.getType() == "B") // Buyuk daire anlaminda 
			{
				Point2D p1(cir.getCenter_x()+(cir.getRadius()*sin(((2.0*PI)/100.0)*i)), cir.getCenter_y()+(cir.getRadius()*cos(((2.0*PI)/100.0)*i)));
				ptr[i-1] = p1;
			}
			else if(cir.getType() == "b") // Kucuk daire anlaminda
			{
				Point2D p1(cir.getCenter_x()+(cir.getRadius()*sin(((2.0*PI)/100.0)*i)), cir.getCenter_y()+(cir.getRadius()*cos(((2.0*PI)/100.0)*i)) );
				ptr[i-1] = p1;
			}
		}
	}

	Polygon :: Polygon(const Point2D& point) //conversion point
	{
		int temp_size = 1;
		size = temp_size;
		ptr = new Point2D[size];

		ptr[0] = point;
	}

	bool operator==(const Polygon& pol1, const Polygon& pol2) //Esitlik operatoru (Noktalar aynı mu diye bakar)
	{
		int i;
		if(pol1.size != pol2.size)
			return false;
		else if(pol1.size == pol2.size)
		{
			for(i = 0; i < pol1.size; ++i)
			{
				if(pol1.ptr[i] != pol2.ptr[i])
					return false;
			}
		}
		return true;
	}

	bool operator!=(const Polygon& pol1, const Polygon& pol2) //Esit olmama operatoru
	{
		return(!(pol1 == pol2));
	}

	Polygon operator+(const Polygon& pol1, const Polygon& pol2) // + operatoru
	{
		Polygon temp_polyogon;

		int i,j,k=0, temp_size;
		temp_size = pol1.size + pol2.size;

		temp_polyogon.size= temp_size;
		temp_polyogon.ptr = new Polygon::Point2D[temp_polyogon.size];

		for(i=0; i < pol1.size; ++i) //Ilk size a kadar don ve yeni olusturulan objeye atama yapar
		{
			temp_polyogon.ptr[i] = pol1.ptr[i];
		}

		for(j=i-1; j < temp_size; ++j)	//Ilk size dan total size a kadar doner ve yeni olusturulan objeye atama yapar
		{
			temp_polyogon.ptr[j] = pol2.ptr[k];
			k++;
		}

		return temp_polyogon;
	}
	ostream& operator<<(ostream& file, Polygon temp_pol)
	{
		int i;
		if(temp_pol.getType() == "B")	//Buyuk sekil ise
		{
			file << "<svg viewBox=\"1.1\"\n" << "baseProfile=\"full\"\n" << "xmlns=\"http:/" << "/www.w3.org/2000/svg\">\n";
			file << "<polygon points=\"";
			for(i=0;i<temp_pol.size;++i)
			{
				file <<temp_pol.ptr[i].getKoor_x()<<" "<< temp_pol.ptr[i].getKoor_y()<<" ";	 
			}
			file<< "\" fill=\"red\" stroke=\"white\" />\n" ;
		}
		else if(temp_pol.getType() == "b") //Kucuk sekil ise
		{
			file << "<polygon points=\"";
			for(i=0;i<temp_pol.size;++i)
			{
				file <<temp_pol.ptr[i].getKoor_x()<<" "<< temp_pol.ptr[i].getKoor_y()<<" ";
				 
			}
			file<< "\" fill=\"green\" stroke=\"white\" />\n" ;
		}


	}
	Polygon::Point2D& Polygon::operator[](int index) // idex operatoru
	{
		if(index >= size)
			index = size - 1;

		return ptr[index];

	}
	/*Setter ve getter */
	string Polygon :: getType()const
	{
		return type;
	}
	void Polygon :: setType(string typeValue)
	{
		type = typeValue;
	}

	int Polygon :: getSize()const
	{
		return size;
	}
	void Polygon :: setSize(int sizeValue)
	{
		size = sizeValue;
	}
}