#ifndef RECTANGLE_H_
#define RECTANGLE_H_
#include <iostream>	
#include <fstream>
#include <cmath>

using namespace std;
namespace HW4
{
	class Rectangle
	{

	public:
		Rectangle();	/*No parameter constructor*/
		Rectangle(double temp_width, double temp_height);	/*Iki parametreliconstructor*/
		Rectangle(double temp_width, double temp_height, double temp_cordinate_x, double temp_cordinate_y); /*Dort parametreliconstructor */
		
		double getWidth()const;	/*Width return eder	*/
		double getHeight()const; /*Height return eder	*/
		double getCor_x()const;	/*cordinate_x return eder	*/
		double getCor_y()const; /*cordinate_y return eder	*/
		void setWidth(double widthValue);	/*Width atar	*/
		void setHeight(double heightValue);	/*Height atar	*/
		void setCor_x(double cordinate_xValue);	/*cordinate_x atar	*/
		void setCor_y(double cordinate_yValue);	/*cordinate_y atar*/
		double perimeter_length()const; //Cevre uzunlugunu return eder
		double area()const;	//Alani return eder
		static double return_total_area(); // static alan fonksiyonu
		static double return_total_PL();	//static cevre fonksiyonu
		friend ostream& operator<<(ostream& file, Rectangle temp_rectangle); //  << operatoru ile dosyaya yazdirma fonksiyonu overload etme
		const Rectangle operator++();//Prefix ++
		const Rectangle operator++(int );//Postfix ++
		const Rectangle operator--();//Prefix ++
		const Rectangle operator--(int );//Postfix ++
		const Rectangle operator+(double bigger)const;	//Kenarlarina bir double eklenmis objeyi return eder
		const Rectangle operator-(double smaller)const;	//Kenarlarindan bir double cikartilmis objeyi return eder
		friend bool operator==(const Rectangle& rectangle1, const Rectangle& rectangle2 ); //Iki objenin alanlari ile kiyaslanip == olma fonksiyonu
		friend bool operator!=(const Rectangle& rectangle1, const Rectangle& rectangle2 );	//Iki objenin alanlari ile kiyaslanip != olma fonksiyonu
		friend bool operator>(const Rectangle& rectangle1, const Rectangle& rectangle2 );	//Iki objenin alanlari ile kiyaslanip > olma fonksiyonu
		friend bool operator<=(const Rectangle& rectangle1, const Rectangle& rectangle2 );	//Iki objenin alanlari ile kiyaslanip <= olma fonksiyonu

	private:
		/*Degiskenler	*/
		static double static_total_area;
		static double static_total_PL;
		double width;
		double height;
		double cordinate_x;
		double cordinate_y;
	};
}
#endif