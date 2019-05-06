#ifndef COMPOSEDSHAPE_H_
#define COMPOSEDSHAPE_H_
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

#include "Rectangle.h"
#include "Circle.h"			/*Diger header dileri cagirma	*/
#include "Triangle.h"

using namespace std;

class ComposedShape
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
	
	void optimalFit();	/*Bu fonksiyon icerisinde gelen karaktere gore yetkili fonksiyon cagirilir	*/

	vector <Rectangle> getVector_Rectangle();	/*Kucuk sekilllere icin atama yapilacak vektor	*/

	vector <Triangle> getVector_Triangle();	/*Kucuk sekilllere icin atama yapilacak vektor	*/

	vector <Circle> getVector_Circle(); /*Kucuk sekilllere icin atama yapilacak vektor	*/

	char getbigChar()const;	/*Karakter return eder	*/
	char getsmallChar()const;	/*Karakter return eder	*/

	void setBigChar(char bigCharValue);	/*Karakter atar	*/
	void setSmallChar(char smallCharValue);	/*Karakter atar	*/



private:
	/*Degiskenler*/
	vector <Rectangle> rec_vector;
	vector <Triangle> tri_vector;
	vector <Circle> cir_vector;

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

	void draw(ofstream& file, const vector<Rectangle>);	/*Kucuk sekiller icin cizdirme fonksiyonu	*/
	void draw(ofstream& file, const vector<Triangle>);	/*Kucuk sekiller icin cizdirme fonksiyonu	*/
	void draw(ofstream& file, const vector<Circle>);	/*Kucuk sekiller icin cizdirme fonksiyonu	*/

};

#endif