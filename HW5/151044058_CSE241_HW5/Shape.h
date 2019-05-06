#ifndef SHAPE_H
#define SHAPE_H
#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

namespace HW5_151044058
{
	class Shape 
	{
	public:
		virtual double area() = 0; //Pure virtual function
		virtual double perimeter() = 0; //Pure virtual function

		virtual Shape& operator++() = 0; //Prefix ++
		virtual Shape& operator++(int ingnore) = 0; //Postfix ++
		virtual Shape& operator--() = 0; //Prefix --
		virtual Shape& operator--(int ingnore) = 0; //Postfix --
		
		bool operator==(Shape& other);
		bool operator!=(Shape& other);
		bool operator>(Shape& other);
		bool operator<=(Shape& other);

		virtual void draw_Shape(ostream& file) = 0;
		friend ostream& operator<< (ostream &file, Shape& obje); //Overloaded global operator<< can be used for printing the shapes to SVG files
	};
}

#endif 