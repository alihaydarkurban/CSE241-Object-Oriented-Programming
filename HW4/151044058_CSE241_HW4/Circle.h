#ifndef CIRCLE_H_
#define CIRCLE_H_
#include <iostream>
#include <fstream>
#include <cmath>
#include <string>

using namespace std;
namespace HW4
{
	class Circle
	{

	public:
		Circle(); /*No parameter constructor*/
		Circle(double temp_radius); /*Bir parametreli contructor*/	
		Circle(double temp_radius, double cX, double cY);	/*Iki parametreli constructor	*/

		double getRadius()const;	/*radius return eder	*/
	 	double getCenter_x()const;	/*center_x return eder	*/
		double getCenter_y()const;	/*center_y return eder	*/
		void setRadius(double radiusValue); /*radius atar */
		void setCenter_x(double center_xValue);	/*center_x atar	*/
		void setCenter_y(double center_yValue);	/*center_y	atar*/
		double perimeter_length()const;	//Cevre fonksiyonu
		double area()const;	//Alan fonksiyonu
		static double return_total_area();	//Static alan fonksiyonu
		static double return_total_PL();	//Static cevre fonksiyounu
		friend ostream& operator<<(ostream& file, Circle temp_circle); //Dosyaya yazdirmak icin << operatorunu overload etme fonksiyonu
		const Circle operator++(); //Prefix ++ 
		const Circle operator++(int ); //Postfix ++ 
		const Circle operator--(); //Prefix --
		const Circle operator--(int ); //Postfix -- 
		const Circle operator+(double bigger)const; //Radiusa double ekler ve objeyi return eder
		const Circle operator-(double smaller)const;	//Radiustan double cikarir ve return eder
		friend bool operator==(const Circle& circle1, const Circle& circle2 ); // Alanlari esit mi diye == overload etme fonksiyonu
		friend bool operator!=(const Circle& circle1, const Circle& circle2 );	// Alanlardan esit degilm mi diye != overload etme fonksiyonu
		friend bool operator>(const Circle& circle1, const Circle& circle2 );	//Alanlardan buyuk olani bulmak icin > verload etme
		friend bool operator<=(const Circle& circle1, const Circle& circle2 );	//Alanlardan  kucuk esit olani bulmak icin <= overload etme
		string getType()const;
		void setType(string typeValue);

	private:
		/*Degiskenler*/
		static double static_total_area;
		static double static_total_PL;
		double radius;
		double center_x;
		double center_y;
		string type;
	};
}

#endif