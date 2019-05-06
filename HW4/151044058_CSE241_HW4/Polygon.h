#ifndef POLYGON_H_
#define POLYGON_H_
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

namespace HW4
{
	class Polygon
	{

	public:
		class Point2D
		{
		public:
			Point2D(); // No parameter constructor
			Point2D(double x, double y);  // Two parameters constuructor
			void setKoor_x(double koor_xValue) //set koor_x
			{
				koor_x = koor_xValue;
			}
			void setKoor_y(double koor_yValue)	//set koor_y
			{
				koor_y = koor_yValue;
			}
			double getKoor_x()const // get koor_x
			{
				return koor_x;
			}
			double getKoor_y()const // get koor_y
			{
				return koor_y;
			}
		private:
			double koor_x;
			double koor_y;
		};


		Polygon(); //No parameter constructor
		Polygon(const Polygon& pol1); // Copy constructor
		~Polygon(); // Destructor
		Polygon& operator=(const Polygon& pol1); // Assignment operator
		Polygon(vector<Point2D> vec);
		Polygon(const Rectangle &rec);	//	conversion rec
		Polygon(const Triangle &tri);	//	conversion tri
		Polygon(const Circle &cir);		//	conversion cir
		Polygon(const Point2D& point);  //	conversion point

		//Operator overloading
		friend bool operator==(const Polygon& pol1, const Polygon& pol2);
		friend bool operator!=(const Polygon& pol1, const Polygon& pol2);
		friend Polygon operator+(const Polygon& pol1, const Polygon& pol2);
		friend ostream& operator<<(ostream& file, Polygon temp_pol);
		Point2D& operator[](int index);
		string getType()const;

		void setType(string typeValue);
		int getSize()const;
		void setSize(int sizeValue);
		
		Point2D * ptr; //Pointer

	private:
		
		int size; // dynamic array size
		string type;

	};
}
#endif