#ifndef COMPOSEDSHAPE_H_
#define COMPOSEDSHAPE_H_

#include "Rectangle.h"
#include "Circle.h"			/*Diger header dileri cagirma	*/
#include "Triangle.h"
#include "Polygon.h"
#include "Shape.h"

using namespace std;

namespace HW5_151044058
{
	class ComposedShape_Error{}; //Throw yapmak icin class
	class ComposedShape : public Shape
	{
	public:

		ComposedShape();	/*No parameter constructor	*/

		/*BUTUN CIZDIRILICEK SEKIL KOMBINASYONLARI ICIN CONSTRUCTOR*/
		ComposedShape(Rectangle Cmain_rectangle, Rectangle Csmall_rectangle);
		ComposedShape(Rectangle Cmain_rectangle, Triangle Csmall_triangle);
		ComposedShape(Rectangle Cmain_rectangle, Circle Csmall_circle);
		ComposedShape(Triangle Cmain_triangle, Rectangle Csmall_rectangle);
		ComposedShape(Triangle Cmain_triangle, Triangle Csmall_triangle);
		ComposedShape(Triangle Cmain_triangle, Circle Csmall_circle);
		ComposedShape(Circle Cmain_circle, Rectangle Csmall_rectangle);
		ComposedShape(Circle Cmain_circle, Triangle Csmall_triangle);
		ComposedShape(Circle Cmain_circle, Circle Csmall_circle);

		~ComposedShape(); //Destructor


		void optimalFit()throw(ComposedShape_Error);	/*Bu fonksiyon icerisinde gelen karaktere gore yetkili fonksiyon cagirilir	*/

		char getbigChar()const;	/*Karakter return eder	*/
		char getsmallChar()const;	/*Karakter return eder	*/

		void setBigChar(char bigCharValue);	/*Karakter atar	*/
		void setSmallChar(char smallCharValue);	/*Karakter atar	*/

		double area(){}
		double perimeter(){}
		Shape& operator++(){} //Prefix ++
		Shape& operator++(int ingnore){} //Postfix ++
		Shape& operator--(){} //Prefix --
		Shape& operator--(int ingnore){} //Postfix --
		void draw_Shape(ostream& file);


	private:

		vector <Shape* > vec_Shape; //Shape vectoru

		Rectangle main_rectangle, small_rectangle;
		Triangle main_triangle, small_triangle;
		Circle main_circle, small_circle;

		char bigChar, smallChar;

		void fitting_rec_in_rec(Rectangle main_rectangle, Rectangle small_rectangle);	/*Rectangle icine rectangle yerlestirmek icin gerekli fonksiyon (Koordinatları gerekli bilgileri vektore atar ve çizdirir) 	*/
		void fitting_rec_in_tri(Rectangle main_rectangle, Triangle small_triangle);	/*Rectangle icine triangle yerlestirmek icin gerekli fonksiyon (Koordinatları gerekli bilgileri vektore atar ve çizdirir) 	*/
		void fitting_rec_in_cir(Rectangle main_rectangle, Circle small_circle);/*Rectangle icine circle yerlestirmek icin gerekli fonksiyon (Koordinatları gerekli bilgileri vektore atar ve çizdirir) 	*/
		void fitting_tri_in_rec(Triangle main_triangle, Rectangle small_rectangle);/*Triangle icine rectangle yerlestirmek icin gerekli fonksiyon (Koordinatları gerekli bilgileri vektore atar ve çizdirir) 	*/
		void fitting_tri_in_tri(Triangle main_triangle, Triangle small_triangle);/*Triangle icine triangle yerlestirmek icin gerekli fonksiyon (Koordinatları gerekli bilgileri vektore atar ve çizdirir) 	*/
		void fitting_tri_in_cir(Triangle main_triangle, Circle small_circle);/*Triangle icine circle yerlestirmek icin gerekli fonksiyon (Koordinatları gerekli bilgileri vektore atar ve çizdirir) 	*/
		void fitting_cir_in_rec(Circle main_circle, Rectangle small_rectangle);/*Circle icine rectangle yerlestirmek icin gerekli fonksiyon (Koordinatları gerekli bilgileri vektore atar ve çizdirir) 	*/
		void fitting_cir_in_tri(Circle main_circle, Triangle small_triangle);/*Circle icine triangle yerlestirmek icin gerekli fonksiyon (Koordinatları gerekli bilgileri vektore atar ve çizdirir) 	*/
		void fitting_cir_in_cir(Circle main_circle, Circle small_circle);/*Circle icine circle yerlestirmek icin gerekli fonksiyon (Koordinatları gerekli bilgileri vektore atar ve çizdirir) 	*/


	};
}
#endif