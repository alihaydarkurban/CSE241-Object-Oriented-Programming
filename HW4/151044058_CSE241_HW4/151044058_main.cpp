#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cmath>
#include <vector>

#include "Rectangle.h"
#include "Triangle.h"
#include "Circle.h"
#include "ComposedShape.h"
#include "Polyline.h"
#include "Polygon.h"

/*
	ALI HAYDAR KURBAN 151044058
*/
namespace //unname namespace
{
	double width;
	double height;
	double small_width;
	double small_height;
	double small_radius;
	double small_length;
	double rCorx;
	double rCory; 
	double length;
	double tCorx1, tCorx2, tCorx3;
	double tCory1, tCory2, tCory3;
	double radius;
	double cCorx, cCory;
}
using namespace std;
using namespace HW4; // use the namespace

//Static variables
double Triangle :: static_total_area = 0.0;
double Triangle :: static_total_PL = 0.0; 
double Rectangle :: static_total_area = 0.0;
double Rectangle :: static_total_PL = 0.0; 
double Circle :: static_total_area = 0.0;
double Circle :: static_total_PL = 0.0; 

void driver();

int main()
{ 
	driver();
	return 0;
}

void driver()
{

	width = 900;
	height = 730;
	small_width = 59;
	small_height = 118;
	small_radius = 19;
	small_length = 74;
	rCorx = 0;
	rCory = 0; 
	
	/*RECTENGLE ICINE RECTANGLE	*/
	Rectangle main_rectangle1(width,height,rCorx,rCory);
	Rectangle small_rectangle1(small_width,small_height);
	ComposedShape shapes1(main_rectangle1, small_rectangle1);
	shapes1.setBigChar('R');
	shapes1.setSmallChar('R');
	shapes1.optimalFit();
	ofstream file1;
	file1.open("rec_rec.svg");	/*Dosya acma	*/
	file1 << shapes1;

	cout << "*************************************************************" << endl;
	/*RECTENGLE ICINE TRIANGLE	*/
	Rectangle main_rectangle2(width,height,rCorx,rCory);
	Triangle small_triangle1(small_length);
	ComposedShape shapes2(main_rectangle2, small_triangle1);
	shapes2.setBigChar('R');
	shapes2.setSmallChar('T');
	shapes2.optimalFit();
	ofstream file2;
	file2.open("rec_tri.svg");	/*Dosya acma	*/
	file2 << shapes2;

	cout << "*************************************************************" << endl;
	/*RECTENGLE ICINE CIRCLE	*/
	Rectangle main_rectangle3(width,height,rCorx,rCory);
	Circle small_circle1(small_radius);
	ComposedShape shapes3(main_rectangle3, small_circle1);
	shapes3.setBigChar('R');
	shapes3.setSmallChar('C');
	shapes3.optimalFit();
	ofstream file3;
	file3.open("rec_cir.svg");	/*Dosya acma	*/
	file3 << shapes3;

/******************************************************************************************************/

	length = 900;
	small_width = 90;
	small_height = 75;
	small_radius = 28;
	small_length = 95;
	tCorx1 = length / 2.0, tCorx2 = 0.0, tCorx3 = length;
	tCory1 = 0.0, tCory2 = length * sqrt(3.0) / 2.0, tCory3 = length * sqrt(3.0) / 2.0;



	cout << "*************************************************************" << endl;
	/*TRIANGLE ICINE RECTANGLE	*/
	Triangle main_triangle1 (length, tCorx1, tCorx2, tCorx3, tCory1, tCory2, tCory3);
	Rectangle small_rectangle2(small_width, small_height);
	ComposedShape shapes4(main_triangle1, small_rectangle2);
	shapes4.setBigChar('T');
	shapes4.setSmallChar('R');
	shapes4.optimalFit();
	ofstream file4;
	file4.open("tri_rec.svg");	/*Dosya acma	*/
	file4 << shapes4;

	cout <<  "*************************************************************" << endl;
	/*TRIANGLE ICINE TRIANGLE	*/
	Triangle main_triangle2 (length, tCorx1, tCorx2, tCorx3, tCory1, tCory2, tCory3);
	Triangle small_triangle2(small_length);
	ComposedShape shapes5(main_triangle2, small_triangle2);
	shapes5.setBigChar('T');
	shapes5.setSmallChar('T');
	shapes5.optimalFit();
	ofstream file5;
	file5.open("tri_tri.svg");	/*Dosya acma	*/
	file5 << shapes5;
	
	cout <<"*************************************************************" << endl;
	/*TRIANGLE ICINE CIRCLE	*/
	Triangle main_triangle3 (length, tCorx1, tCorx2, tCorx3, tCory1, tCory2, tCory3);
	Circle small_circle2(small_radius);
	ComposedShape shapes6(main_triangle3, small_circle2);
	shapes6.setBigChar('T');
	shapes6.setSmallChar('C');
	shapes6.optimalFit();
	ofstream file6;
	file6.open("tri_cir.svg");	/*Dosya acma	*/
	file6 << shapes6;

/******************************************************************************************************/

	radius = 879;
	small_width = 90;
	small_height = 75;
	small_radius = 37;
	small_length = 111;
	cCorx = radius, cCory = radius;

	cout <<"*************************************************************" << endl;
	/*CIRCLE ICINE RECTANGLE	*/
	Circle main_circle1 (radius,cCorx,cCory);
	Rectangle small_rectangle3(small_width,small_height);
	ComposedShape shapes7(main_circle1, small_rectangle3);
	shapes7.setBigChar('C');
	shapes7.setSmallChar('R');
	shapes7.optimalFit();
	ofstream file7;
	file7.open("cir_rec.svg");	/*Dosya acma	*/
	file7 << shapes7;

	cout << "*************************************************************" << endl;
	/*CIRCLE ICINE TRIANGLE	*/
	Circle main_circle2 (radius,cCorx,cCory);
	Triangle small_triangle3(small_length);
	ComposedShape shapes8(main_circle2, small_triangle3);
	shapes8.setBigChar('C');
	shapes8.setSmallChar('T');
	shapes8.optimalFit();
	ofstream file8;
	file8.open("cir_tri.svg");	/*Dosya acma	*/
	file8 << shapes8;

	cout <<"*************************************************************" << endl;
	/*CIRCLE ICINE CIRCLE	*/
	Circle main_circle3(radius,cCorx,cCory);
	Circle small_circle3(small_radius);
	ComposedShape shapes9(main_circle3, small_circle3);
	shapes9.setBigChar('C');
	shapes9.setSmallChar('C');
	shapes9.optimalFit();
	ofstream file9;
	file9.open("cir_cir.svg");	/*Dosya acma	*/
	file9 << shapes9;

	width = 520;
	height = 300; 
	rCorx = 0;
	rCory = 0;

	/*Polyline sekillleri icin ornekler*/

	Rectangle main_rectangle4(width,height,rCorx,rCory);

	Polyline p1;
	p1.temp_polygon = Polygon(main_rectangle4);

	ofstream file10;
	file10.open("polyline_1.svg");	/*Dosya acma	*/
	file10 << p1;

	length = 500;
	tCorx1 = length / 2.0, tCorx2 = 0.0, tCorx3 = length;
	tCory1 = 0.0, tCory2 = length * sqrt(3.0) / 2.0, tCory3 = length * sqrt(3.0) / 2.0;

	Triangle main_triangle4 (length, tCorx1, tCorx2, tCorx3, tCory1, tCory2, tCory3);
	Polyline p2;
	p2.temp_polygon = Polygon(main_triangle4);

	ofstream file11;
	file11.open("polyline_2.svg");
	file11 << p2;


	radius = 750;
	cCorx = radius, cCory = radius;
	Circle main_circle4 (radius,cCorx,cCory);

	main_circle4.setType("B"); //Circle cizdirmek icin type atamasi yapiyorum

	Polyline p3;
	p3.temp_polygon = Polygon(main_circle4);

	ofstream file12;
	file12.open("polyline_3.svg");
	file12 << p3;

}