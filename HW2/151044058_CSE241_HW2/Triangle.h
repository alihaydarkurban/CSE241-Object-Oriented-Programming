#ifndef TRIANGLE_H_
#define TRIANGLE_H_
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

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
	void draw(ofstream& file);	/*Buyuk sekil cizdirme	*/

private:
	/*Degiskenler	*/
	double length;
	double cordinate_x1, cordinate_x2, cordinate_x3;
	double cordinate_y1, cordinate_y2, cordinate_y3;
};

#endif