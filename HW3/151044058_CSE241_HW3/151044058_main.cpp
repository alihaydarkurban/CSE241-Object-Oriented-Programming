#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cmath>
#include <vector>

#include "Rectangle.h"
#include "Triangle.h"
#include "Circle.h"
#include "ComposedShape.h"


/*
	ALI HAYDAR KURBAN 151044058
*/

using namespace std;
/*STATIC DEGERLERIN ILKLENDIRILMESI */
double Triangle :: static_total_area = 0.0;
double Triangle :: static_total_PL = 0.0; 
double Rectangle :: static_total_area = 0.0;
double Rectangle :: static_total_PL = 0.0;
double Circle :: static_total_area = 0.0;
double Circle :: static_total_PL = 0.0; 

void driver();
void function_tester();

int main()
{ 
	driver();
	cout << endl << "************************************************************************" << endl;
	function_tester();
	return 0;
}

void driver()
{
	/******************************************************************************************************/
	double width = 900;
	double height = 780;
	double small_width = 57;
	double small_height = 118;
	double small_radius = 19;
	double small_length = 74;
	double rCorx = 0;
	double rCory = 0; 
	
	/*RECTENGLE ICINE RECTANGLE	*/
	Rectangle main_rectangle1(width,height,rCorx,rCory);
	Rectangle small_rectangle1(small_width,small_height);
	ComposedShape shapes1(main_rectangle1, small_rectangle1);
	shapes1.setBigChar('R');
	shapes1.setSmallChar('R');
	shapes1.optimalFit();

	cout << "*************************************************************" << endl;
	/*RECTENGLE ICINE TRIANGLE	*/
	Rectangle main_rectangle2(width,height,rCorx,rCory);
	Triangle small_triangle1(small_length);
	ComposedShape shapes2(main_rectangle2, small_triangle1);
	shapes2.setBigChar('R');
	shapes2.setSmallChar('T');
	shapes2.optimalFit();

	cout << "*************************************************************" << endl;
	/*RECTENGLE ICINE CIRCLE	*/
	Rectangle main_rectangle3(width,height,rCorx,rCory);
	Circle small_circle1(small_radius);
	ComposedShape shapes3(main_rectangle3, small_circle1);
	shapes3.setBigChar('R');
	shapes3.setSmallChar('C');
	shapes3.optimalFit();

/******************************************************************************************************/

	double length = 900;
	small_width = 90;
	small_height = 75;
	small_radius = 28;
	small_length = 95;
	double tCorx1 = length / 2.0, tCorx2 = 0.0, tCorx3 = length;
	double tCory1 = 0.0, tCory2 = length * sqrt(3.0) / 2.0, tCory3 = length * sqrt(3.0) / 2.0;



	cout << "*************************************************************" << endl;
	/*TRIANGLE ICINE RECTANGLE	*/
	Triangle main_triangle1 (length, tCorx1, tCorx2, tCorx3, tCory1, tCory2, tCory3);
	Rectangle small_rectangle2(small_width, small_height);
	ComposedShape shapes4(main_triangle1, small_rectangle2);
	shapes4.setBigChar('T');
	shapes4.setSmallChar('R');
	shapes4.optimalFit();

	cout <<  "*************************************************************" << endl;
	/*TRIANGLE ICINE TRIANGLE	*/
	Triangle main_triangle2 (length, tCorx1, tCorx2, tCorx3, tCory1, tCory2, tCory3);
	Triangle small_triangle2(small_length);
	ComposedShape shapes5(main_triangle2, small_triangle2);
	shapes5.setBigChar('T');
	shapes5.setSmallChar('T');
	shapes5.optimalFit();
	
	cout <<"*************************************************************" << endl;
	/*TRIANGLE ICINE CIRCLE	*/
	Triangle main_triangle3 (length, tCorx1, tCorx2, tCorx3, tCory1, tCory2, tCory3);
	Circle small_circle2(small_radius);
	ComposedShape shapes6(main_triangle3, small_circle2);
	shapes6.setBigChar('T');
	shapes6.setSmallChar('C');
	shapes6.optimalFit();

/******************************************************************************************************/

	double radius = 879;
	small_width = 90;
	small_height = 75;
	small_radius = 37;
	small_length = 111;
	double cCorx = radius, cCory = radius;

	cout <<"*************************************************************" << endl;
	/*CIRCLE ICINE RECTANGLE	*/
	Circle main_circle1 (radius,cCorx,cCory);
	Rectangle small_rectangle3(small_width,small_height);
	ComposedShape shapes7(main_circle1, small_rectangle3);
	shapes7.setBigChar('C');
	shapes7.setSmallChar('R');
	shapes7.optimalFit();

	cout << "*************************************************************" << endl;
	/*CIRCLE ICINE TRIANGLE	*/
	Circle main_circle2 (radius,cCorx,cCory);
	Triangle small_triangle3(small_length);
	ComposedShape shapes8(main_circle2, small_triangle3);
	shapes8.setBigChar('C');
	shapes8.setSmallChar('T');
	shapes8.optimalFit();

	cout <<"*************************************************************" << endl;
	/*CIRCLE ICINE CIRCLE	*/
	Circle main_circle3(radius,cCorx,cCory);
	Circle small_circle3(small_radius);
	ComposedShape shapes9(main_circle3, small_circle3);
	shapes9.setBigChar('C');
	shapes9.setSmallChar('C');
	shapes9.optimalFit();
}

void function_tester()
{
	ofstream file1;
	file1.open("output_rectangle.svg");	/*Dosya acma	*/

	Rectangle r1(100,100,0,0);

	file1 << "<svg viewBox=\"1.1\"\n" << "baseProfile=\"full\"\n" << "xmlns=\"http:/" << "/www.w3.org/2000/svg\">\n";
	file1 << r1;
	file1 << "</svg>";
	file1.close();

	cout << "*****RECTANGLE*****"<<endl;
	cout << "Alan = " << r1.area()  << " " << "Cevre = " << r1.perimeter_length() << endl;
	cout << "En = " << r1.getWidth() << " " << "Boy = " << r1.getHeight() << " " << "x koordinati = " << r1.getCor_x() << " " << "y koordinati = " << r1.getCor_y() << endl;
	r1 = r1 + 15;
	cout << "Kenar uzunluklari arttirildiktan sonraki degerler" << endl;
	cout << "En = " << r1.getWidth() << " " << "Boy = " << r1.getHeight() << endl;
	r1 = r1 - 30;
	cout << "Kenar uzunluklari azaltildiktan sonraki degerler" << endl;
	cout << "En = " << r1.getWidth() << " " << "Boy = " << r1.getHeight() << endl;
	cout << "Prefix ++ isleminden sonraki koordinatlar" << endl;
	++r1;
	cout <<"x koordinati = " << r1.getCor_x() << " " << "y koordinati = " << r1.getCor_y() << endl;
	cout << "Postfix ++ isleminden sonraki koordinatlar" << endl;
	r1++;
	cout <<"x koordinati = " << r1.getCor_x() << " " << "y koordinati = " << r1.getCor_y() << endl;
	cout << "Prefix -- isleminden sonraki koordinatlar" << endl;
	--r1;
	cout <<"x koordinati = " << r1.getCor_x() << " " << "y koordinati = " << r1.getCor_y() << endl;
	cout << "Prefix -- isleminden sonraki koordinatlar" << endl;
	r1--;
	cout <<"x koordinati = " << r1.getCor_x() << " " << "y koordinati = " << r1.getCor_y() << endl;

	Rectangle r2(50,50);
	cout << "Birinci objenin alani = " << r1.area() << endl;
	cout << "Ikinci objenin alani = " << r2.area() << endl;

	if(r1 == r2)
		cout << "Alanlar esit" << endl;
	if(r1 != r2)
		cout << "Alanlar esit degil" << endl;
	if(r1 > r2)
		cout << "Birinci objenin alani daha buyuktur" << endl;
	if(r1 <= r2)
		cout << "Ikinci objenin alani birinci objeden buyuk veya esittir" << endl;

	cout << endl << "*****CIRCLE*****"<<endl;

	ofstream file2;
	file2.open("output_circle.svg");	/*Dosya acma	*/

	Circle c1(200,200,200);

	file2 << "<svg viewBox=\"1.1\"\n" << "baseProfile=\"full\"\n" << "xmlns=\"http:/" << "/www.w3.org/2000/svg\">\n";
	file2 << c1;
	file2 << "</svg>";
	file2.close();

	cout << "Alan = " << c1.area()  << " " << "Cevre = " << c1.perimeter_length() << endl;
	cout << "Yaricap = " << c1.getRadius() << " " << "x merkezi = " << c1.getCenter_x() << " " << "y merkezi = " << c1.getCenter_y() << endl;
	c1 = c1 + 15;
	cout << "Yaricap uzunlugu arttirildiktan sonraki degeri" << endl;
	cout << "Yaricap = " << c1.getRadius() << endl;
	c1 = c1 - 30;
	cout << "Yaricap uzunlugu azaltildiktan sonraki degeri" << endl;
	cout << "Yaricap = " << c1.getRadius() << endl;
	cout << "Prefix ++ isleminden sonraki koordinatlar" << endl;
	++c1;
	cout << "x merkezi = " << c1.getCenter_x() << " " << "y merkezi = " << c1.getCenter_y() << endl;
	cout << "Postfix ++ isleminden sonraki koordinatlar" << endl;
	c1++;
	cout << "x merkezi = " << c1.getCenter_x() << " " << "y merkezi = " << c1.getCenter_y() << endl;
	cout << "Prefix -- isleminden sonraki koordinatlar" << endl;
	--c1;
	cout << "x merkezi = " << c1.getCenter_x() << " " << "y merkezi = " << c1.getCenter_y() << endl;
	cout << "Postfix -- isleminden sonraki koordinatlar" << endl;
	c1--;
	cout << "x merkezi = " << c1.getCenter_x() << " " << "y merkezi = " << c1.getCenter_y() << endl;

	Circle c2(185,185,185);

	cout << "Birinci objenin alani = " << c1.area() << endl;
	cout << "Ikinci objenin alani = " << c2.area() << endl;

	if(c1 == c2)
		cout << "Alanlar esit" << endl;
	if(c1 != c2)
		cout << "Alanlar esit degil" << endl;
	if(c1 > c2)
		cout << "Birinci objenin alani daha buyuktur" << endl;
	if(c1 <= c2)
		cout << "Ikinci objenin alani birinci objeden buyuk veya esittir" << endl;

	cout << endl << "*****TRIANGLE*****"<<endl;

	ofstream file3;
	file3.open("output_triangle.svg");

	double length = 300;
	double tCorx1 = length / 2.0, tCorx2 = 0.0, tCorx3 = length;
	double tCory1 = 0.0, tCory2 = length * sqrt(3.0) / 2.0, tCory3 = length * sqrt(3.0) / 2.0;

	Triangle t1(length, tCorx1, tCorx2, tCorx3, tCory1, tCory2, tCory3);
	file3 << "<svg viewBox=\"1.1\"\n" << "baseProfile=\"full\"\n" << "xmlns=\"http:/" << "/www.w3.org/2000/svg\">\n";
	file3 << t1;
	file3 << "</svg>";
	file3.close();

	cout << "Alan = " << t1.area()  << " " << "Cevre = " << t1.perimeter_length() << endl;
	cout << "Kenar uzunlugu  = " << t1.getLength() << " " << "x1 koordinati = " << t1.getCor_x1() << " " << "y1 koordinati = " << t1.getCor_y1() <<
			" " << "x2 koordinati = " << t1.getCor_x2() << " " << "y2 koordinati = " << t1.getCor_y2() << 
			" " << "x3 koordinati = " << t1.getCor_x3() << " " << "y3 koordinati = " << t1.getCor_y3() << endl;
	t1 = t1 + 30;
	cout << "Kenar uzunlugu arttirildiktan sonraki degeri" << endl;
	cout << "Kenar uzunlugu = " << t1.getLength() << endl;
	t1 = t1 - 30;
	cout << "Kenar uzunlugu azaltildiktan sonraki degeri" << endl;
	cout << "Kenar uzunlugu  = " << t1.getLength() << endl;
	cout << "Prefix ++ isleminden sonraki koordinatlar" << endl;
	++t1;
	cout << "x1 koordinati = " << t1.getCor_x1() << " " << "y1 koordinati = " << t1.getCor_y1() <<
			" " << "x2 koordinati = " << t1.getCor_x2() << " " << "y2 koordinati = " << t1.getCor_y2() << 
			" " << "x3 koordinati = " << t1.getCor_x3() << " " << "y3 koordinati = " << t1.getCor_y3() << endl;
	t1++;
	cout << "Postfix ++ isleminden sonraki koordinatlar" << endl;
	cout << "x1 koordinati = " << t1.getCor_x1() << " " << "y1 koordinati = " << t1.getCor_y1() <<
			" " << "x2 koordinati = " << t1.getCor_x2() << " " << "y2 koordinati = " << t1.getCor_y2() << 
			" " << "x3 koordinati = " << t1.getCor_x3() << " " << "y3 koordinati = " << t1.getCor_y3() << endl;

	cout << "Prefix -- isleminden sonraki koordinatlar" << endl;
	--t1;
	cout << "x1 koordinati = " << t1.getCor_x1() << " " << "y1 koordinati = " << t1.getCor_y1() <<
			" " << "x2 koordinati = " << t1.getCor_x2() << " " << "y2 koordinati = " << t1.getCor_y2() << 
			" " << "x3 koordinati = " << t1.getCor_x3() << " " << "y3 koordinati = " << t1.getCor_y3() << endl;
	t1--;
	cout << "Postfix -- isleminden sonraki koordinatlar" << endl;
	cout << "x1 koordinati = " << t1.getCor_x1() << " " << "y1 koordinati = " << t1.getCor_y1() <<
			" " << "x2 koordinati = " << t1.getCor_x2() << " " << "y2 koordinati = " << t1.getCor_y2() << 
			" " << "x3 koordinati = " << t1.getCor_x3() << " " << "y3 koordinati = " << t1.getCor_y3() << endl;

	double length2 = 310;
	double t2Corx1 = length2 / 2.0, t2Corx2 = 0.0, t2Corx3 = length2;
	double t2Cory1 = 0.0, t2Cory2 = length2 * sqrt(3.0) / 2.0, t2Cory3 = length2 * sqrt(3.0) / 2.0;
	Triangle t2(length2, t2Corx1, t2Corx2, t2Corx3, t2Cory1, t2Cory2, t2Cory3);

	cout << "Birinci objenin alani = " << t1.area() << endl;
	cout << "Ikinci objenin alani = " << t2.area() << endl;

	if(t1 == t2)
		cout << "Alanlar esit" << endl;
	if(t1 != t2)
		cout << "Alanlar esit degil" << endl;
	if(t1 > t2)
		cout << "Birinci objenin alani daha buyuktur" << endl;
	if(t1 <= t2)
		cout << "Ikinci objenin alani birinci objeden buyuk veya esittir" << endl;

}