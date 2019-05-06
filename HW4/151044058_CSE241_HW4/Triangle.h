#ifndef TRIANGLE_H_
#define TRIANGLE_H_
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

namespace HW4
{
	class Triangle
	{

	public:
		Triangle();	/*No parameter constructor	*/
		Triangle(double temp_length); /*Bir parametreli constructor*/
		Triangle(double temp_length, double x1, double x2, double x3, double y1, double y2, double y3); /*Yedi parametreliconstructor */

		double getLength()const;	/*Length return eder	*/
		double getCor_x1()const;	/*cordinate_x1 return eder	*/
		double getCor_x2()const;	/*cordinate_x2 return eder	*/
		double getCor_x3()const;	/*cordinate_x3 return eder	*/
		double getCor_y1()const;	/*cordinate_y1 return eder	*/
		double getCor_y2()const;	/*cordinate_y2 return eder	*/
		double getCor_y3()const;	/*cordinate_y3 return eder	*/
		void setLength(double lengthValue);	/*Length atar	*/
		void setCor_x1(double cordinate_x1Value);	/*cordinate_x1 atar	*/
		void setCor_x2(double cordinate_x2Value);	/*cordinate_x2 atar	*/
		void setCor_x3(double cordinate_x3Value);	/*cordinate_x3 atar	*/
		void setCor_y1(double cordinate_y1Value);	/*cordinate_y1 atar	*/
		void setCor_y2(double cordinate_y2Value);	/*cordinate_y2 atar	*/
		void setCor_y3(double cordinate_y3Value);	/*cordinate_y3 atar	*/
		double perimeter_length()const;	//Cevre uzunlugu fonsksiyonu
		double area()const;	//Alan fonksiyonu
		static double return_total_area();	//static alan fonksiyonu
		static double return_total_PL(); //static cevre fonksiyonu
		friend ostream& operator<<(ostream& file, Triangle temp_triangle);	// << operatoru ile dosyaya yazdirma fonksiyonu overload etme
		const Triangle operator++();//Prefix
		const Triangle operator++(int );//Postfix
		const Triangle operator--();//Prefix
		const Triangle operator--(int );//Postfix
		const Triangle operator+(double bigger)const;	// Kenara bir doubl eklenmis objeyi return eder 
		const Triangle operator-(double smaller)const;	// Kenara bir doubl cikartilmis objeyi return eder 
		friend bool operator==(const Triangle& triangle1, const Triangle& triangle2 ); //Iki objenin alanlari ile kiyaslanip == olma fonksiyonu
		friend bool operator!=(const Triangle& triangle1, const Triangle& triangle2 );	//Iki objenin alanlari ile kiyaslanip != olma fonksiyonu
		friend bool operator>(const Triangle& triangle1, const Triangle& triangle2 );	//Iki objenin alanlari ile kiyaslanip > olma fonksiyonu
		friend bool operator<=(const Triangle& triangle1, const Triangle& triangle2 );	//Iki objenin alanlari ile kiyaslanip <= olma fonksiyonu

	private:
		/*Degiskenler	*/
		static double static_total_area;
		static double static_total_PL;
		double length;
		double cordinate_x1, cordinate_x2, cordinate_x3;
		double cordinate_y1, cordinate_y2, cordinate_y3;
	};

}

#endif