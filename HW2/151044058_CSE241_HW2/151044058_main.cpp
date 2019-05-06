#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cmath>
#include <vector>

#include "Rectangle.h"
#include "Triangle.h"
#include "Circle.h"
#include "ComposedShape.h"

using namespace std;

int main()
{ 
	cout << endl;
	/*RECTENGLE ICINE RECTANGLE	*/
	Rectangle main_rectangle1(900,800,0,0);
	Rectangle small_rectangle1(57,118);
	ComposedShape shapes1(main_rectangle1, small_rectangle1);
	shapes1.setBigChar('R');
	shapes1.setSmallChar('R');
	shapes1.optimalFit();

	cout << endl << "*************************************************************" << endl;
	/*RECTENGLE ICINE TRIANGLE	*/
	Rectangle main_rectangle2(900,800,0,0);
	Triangle small_triangle1(74);
	ComposedShape shapes2(main_rectangle2, small_triangle1);
	shapes2.setBigChar('R');
	shapes2.setSmallChar('T');
	shapes2.optimalFit();

	cout << endl << "*************************************************************" << endl;
	/*RECTENGLE ICINE CIRCLE	*/
	Rectangle main_rectangle3(900,800,0,0);
	Circle small_circle1(20);
	ComposedShape shapes3(main_rectangle3, small_circle1);
	shapes3.setBigChar('R');
	shapes3.setSmallChar('C');
	shapes3.optimalFit();

	cout << endl << "*************************************************************" << endl;
	/*TRIANGLE ICINE RECTANGLE	*/
	Triangle main_triangle1 (900.0, 900.0/2.0, 0.0, 900.0, 0.0, 900.0 * sqrt(3.0) / 2.0, 900.0 * sqrt(3.0) / 2.0);
	Rectangle small_rectangle2(90,75);
	ComposedShape shapes4(main_triangle1, small_rectangle2);
	shapes4.setBigChar('T');
	shapes4.setSmallChar('R');
	shapes4.optimalFit();

	cout << endl << "*************************************************************" << endl;
	/*TRIANGLE ICINE TRIANGLE	*/
	Triangle main_triangle2 (900.0, 900.0/2.0, 0.0, 900.0, 0.0, 900.0 * sqrt(3.0) / 2.0, 900.0 * sqrt(3.0) / 2.0);
	Triangle small_triangle2(95);
	ComposedShape shapes5(main_triangle2, small_triangle2);
	shapes5.setBigChar('T');
	shapes5.setSmallChar('T');
	shapes5.optimalFit();
	
	cout << endl << "*************************************************************" << endl;
	/*TRIANGLE ICINE CIRCLE	*/
	Triangle main_triangle3 (900.0, 900.0/2.0, 0.0, 900.0, 0.0, 900.0 * sqrt(3.0) / 2.0, 900.0 * sqrt(3.0) / 2.0);
	Circle small_circle2(28);
	ComposedShape shapes6(main_triangle3, small_circle2);
	shapes6.setBigChar('T');
	shapes6.setSmallChar('C');
	shapes6.optimalFit();

	cout << endl << "*************************************************************" << endl;
	/*CIRCLE ICINE RECTANGLE	*/
	Circle main_circle1 (879,879,879);
	Rectangle small_rectangle3(90,75);
	ComposedShape shapes7(main_circle1, small_rectangle3);
	shapes7.setBigChar('C');
	shapes7.setSmallChar('R');
	shapes7.optimalFit();

	cout << endl << "*************************************************************" << endl;
	/*CIRCLE ICINE TRIANGLE	*/
	Circle main_circle2 (879,879,879);
	Triangle small_triangle3(111);
	ComposedShape shapes8(main_circle2, small_triangle3);
	shapes8.setBigChar('C');
	shapes8.setSmallChar('T');
	shapes8.optimalFit();

	cout << endl << "*************************************************************" << endl;
	/*CIRCLE ICINE CIRCLE	*/
	Circle main_circle3(879,879,879);
	Circle small_circle3(37);
	ComposedShape shapes9(main_circle3, small_circle3);
	shapes9.setBigChar('C');
	shapes9.setSmallChar('C');
	shapes9.optimalFit();

	return 0;
}