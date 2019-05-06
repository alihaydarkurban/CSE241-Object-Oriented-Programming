#ifndef CIRCLE_H_
#define CIRCLE_H_

#include "Shape.h"

using namespace std;
namespace HW5_151044058
{
	class Circle_Error{}; //Throw yapmak icin class
	class Circle : public Shape
	{

	public:
		Circle(); /*No parameter constructor*/
		Circle(double temp_radius)throw(Circle_Error); /*Bir parametreli contructor*/	
		Circle(double temp_radius, double cX, double cY)throw(Circle_Error);	/*Iki parametreli constructor	*/

		double getRadius()const;	/*radius return eder	*/
	 	double getCenter_x()const;	/*center_x return eder	*/
		double getCenter_y()const;	/*center_y return eder	*/
		void setRadius(double radiusValue); /*radius atar */
		void setCenter_x(double center_xValue);	/*center_x atar	*/
		void setCenter_y(double center_yValue);	/*center_y	atar*/
		double perimeter()override;	//Cevre fonksiyonu
		double area()override;	//Alan fonksiyonu
		static double return_total_area();	//Static alan fonksiyonu
		static double return_total_PL();	//Static cevre fonksiyounu
		Shape& operator++()override; //Prefix ++ 
		Shape& operator++(int ignore)override; //Postfix ++ 
		Shape& operator--()override; //Prefix --
		Shape& operator--(int ignore)override; //Postfix -- 
		const Circle operator+(double bigger)const; //Radiusa double ekler ve objeyi return eder
		const Circle operator-(double smaller)const;	//Radiustan double cikarir ve return eder
	
		string getType()const;
		void setType(string typeValue);

		void draw_Shape(ostream& file)override;

	private:
		/*Degiskenler*/
		static double static_total_area;
		static double static_total_PL;
		double radius;
		double center_x;
		double center_y;
		string type;
		string poly_type;
	};
}

#endif