#ifndef RECTANGLE_H_
#define RECTANGLE_H_

#include "Shape.h"

using namespace std;
namespace HW5_151044058
{
	class Rectangle_Error{}; //Throw yapmak icin class
	class Rectangle : public Shape
	{

	public:
		Rectangle();	/*No parameter constructor*/
		Rectangle(double temp_width, double temp_height)throw(Rectangle_Error);	/*Iki parametreliconstructor*/
		Rectangle(double temp_width, double temp_height, double temp_cordinate_x, double temp_cordinate_y)throw(Rectangle_Error); /*Dort parametreliconstructor */
		
		double getWidth()const;	/*Width return eder	*/
		double getHeight()const; /*Height return eder	*/
		double getCor_x()const;	/*cordinate_x return eder	*/
		double getCor_y()const; /*cordinate_y return eder	*/
		void setWidth(double widthValue);	/*Width atar	*/
		void setHeight(double heightValue);	/*Height atar	*/
		void setCor_x(double cordinate_xValue);	/*cordinate_x atar	*/
		void setCor_y(double cordinate_yValue);	/*cordinate_y atar*/
		double perimeter()override; //Cevre uzunlugunu return eder
		double area()override;	//Alani return eder
		static double return_total_area(); // static alan fonksiyonu
		static double return_total_PL();	//static cevre fonksiyonu
		Shape& operator++()override;//Prefix ++
		Shape& operator++(int ingnore)override;//Postfix ++
		Shape& operator--()override;//Prefix ++
		Shape& operator--(int ingnore)override;//Postfix ++
		const Rectangle operator+(double bigger)const;	//Kenarlarina bir double eklenmis objeyi return eder
		const Rectangle operator-(double smaller)const;	//Kenarlarindan bir double cikartilmis objeyi return eder

		void draw_Shape(ostream& file)override;
		string getType()const;
		void setType(string typeValue);

	private:
		/*Degiskenler	*/
		static double static_total_area;
		static double static_total_PL;
		double width;
		double height;
		double cordinate_x;
		double cordinate_y;
		string type;
	};
}
#endif