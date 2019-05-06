#include "Rectangle.h"
#include "Triangle.h"
#include "Circle.h"
#include "ComposedShape.h"
#include "Polygon.h"
#include "PolygonDyn.h"
#include "PolygonVect.h"
#include "Shape.h"

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
using namespace HW5_151044058; // use the namespace

//Static variables
double Triangle :: static_total_area = 0.0;
double Triangle :: static_total_PL = 0.0; 
double Rectangle :: static_total_area = 0.0;
double Rectangle :: static_total_PL = 0.0; 
double Circle :: static_total_area = 0.0;
double Circle :: static_total_PL = 0.0; 

void driver();
void test_functions();

void printALL(vector<Shape * > shape_vector); //Global fonksiyon
void printPoly(vector<Shape * > shape_vector2); //Global fonksiyon
void sortShapes(vector<Shape * > shape_vector3); //Global fonksiyon
void convertAll(vector<Shape * > shape_vector4);

int main()
{ 
	driver();
	test_functions();
	return 0;
}

void printALL(vector<Shape * > shape_vector)
{
	ofstream file;
	string filename[12];

	//Dosya isimleri
	filename[0] = "printALL_1(rec_rec).svg";
	filename[1] = "printALL_2(rec_tri).svg";
	filename[2] = "printALL_3(rec_cir).svg";
	filename[3] = "printALL_4(tri_rec).svg";
	filename[4] = "printALL_5(tri_tri).svg";
	filename[5] = "printALL_6(tri_cir).svg";
	filename[6] = "printALL_7(cir_rec).svg";
	filename[7] = "printALL_8(cir_tri).svg";
	filename[8] = "printALL_9(cir_cir).svg";
	filename[9] = "printALL_7(REC).svg";
	filename[10] = "printALL_8(TRI).svg";
	filename[11] = "printALL_9(CIR).svg";
	
	int i;

	for(i = 0; i < shape_vector.size(); ++i)
	{
		file.open(filename[i]);	//Dosyayi acma

		file << *shape_vector[i]; //Shape classindaki <<  operator ile sekilleri cizme

		file.close(); //Dosyayi kapama
	}
}

void printPoly(vector<Shape * > shape_vector2)
{
	ofstream file;
	string filename[6];

	//Dosya isimleri
	filename[0] = "printPoly_1(dyn rec).svg";
	filename[1] = "printPoly_2(vect REC).svg";
	filename[2] = "printPoly_3(vect tri).svg";
	filename[3] = "printPoly_4(dyn TRI).svg";
	filename[4] = "printPoly_5(dyn cir).svg";
	filename[5] = "printPoly_6(vect CIR).svg";

	int i;

	for(i = 0; i < shape_vector2.size(); ++i)
	{
		file.open(filename[i]); //Dosya acma

		file << *shape_vector2[i]; //Shape classindaki << operator ile sekilleri cizme

		file.close(); //Dosya kapama
	}
}

void sortShapes(vector<Shape * > shape_vector3)
{
	int i,j;

	Shape* temp; //Geicici Shape pointiri olusturma

	cout << "Before the sorting : " << endl;

	//Siralanmamis halini bastirir
	for(i = 0; i < shape_vector3.size(); ++i)
		cout << shape_vector3[i]->area() << " ";

	//Sirala islemi
	for(i = 0; i < shape_vector3.size(); ++i)
	{		
		for(j = i+1; j < shape_vector3.size(); ++j)
		{
			if(shape_vector3[i]->area() > shape_vector3[j]->area())
			{
				temp  = shape_vector3[i];
				shape_vector3[i] = shape_vector3[j];
				shape_vector3[j] = temp;
			}
		}
	}
	//Siralanmis halini bastirir
	cout << endl;
	cout << "After the sorting : " << endl;
	for(i = 0; i < shape_vector3.size(); ++i)
		cout << shape_vector3[i]->area() << " ";
	cout << endl;
}

void convertAll(vector<Shape * > shape_vector4)
{
	cout << "I can not do it" << endl;
}

void driver()
{
	try
	{
		vector<Shape * > shape_vector; //printALL icin
		vector<Shape * > shape_vector2; //printPoly icin
		vector<Shape * > shape_vector3; //sortShape icin

		//Degiskenlerin degerleri
		width = 900;
		height = 730;
		small_width = 59;
		small_height = 118;
		small_radius = 19;
		small_length = 74;
		rCorx = 0;
		rCory = 0; 
		
		//RECTANGLE ICINE RECTANGLE	
		Rectangle main_rectangle1(width,height,rCorx,rCory);
		//Sadece bir rectangle shape i batirmak icin tip atamasi(buyuk sekiller kirmizi renkte eger main_rectangle1.setType("rectangle"); olsaydi yesil basardi)
		main_rectangle1.setType("RECTANGLE"); 
		Rectangle small_rectangle1(small_width,small_height);
		ComposedShape shapes1(main_rectangle1, small_rectangle1);
		shapes1.setBigChar('R');
		shapes1.setSmallChar('R');
		shapes1.optimalFit();

		PolygonDyn poly1(main_rectangle1); //PolygonDyn nin conversion constructuronu cagirma


		Shape * dyn1_obje = &poly1; //Shape pointirina poly1 in referencesi ni atama 
		shape_vector2.push_back(dyn1_obje); //printPoly icin vectore koyma
		
		Shape * obje1 = &shapes1; //ComposedShaped objesinin referencesi ni shape pointira atama
		shape_vector.push_back(obje1); //printAll icin vektore koyma

		Shape * area_obje1 = &small_rectangle1; //rectangle objesinin referencesini shape pointira atama
		shape_vector3.push_back(area_obje1); //sortAll icin vektore koyma


		cout << "*************************************************************" << endl;
		//RECTANGLE ICINE TRIANGLE	
		Rectangle main_rectangle2(width,height,rCorx,rCory);
		Triangle small_triangle1(small_length);
		ComposedShape shapes2(main_rectangle2, small_triangle1);
		shapes2.setBigChar('R');
		shapes2.setSmallChar('T');
		shapes2.optimalFit();

		//shapes1 = shapes2;

		PolygonVect poly2(main_rectangle2);	//PolygonVect nin conversion constructuronu cagirma

		Shape * vect1_obje = &poly2;	//Shape pointirina poly2 in referencesi ni atama 
		shape_vector2.push_back(vect1_obje); //printPoly icin vectore koyma

		
		Shape * obje2 = &shapes2;	//ComposedShaped objesinin referencesi ni shape pointira atama
		shape_vector.push_back(obje2);	//printAll icin vektore koyma

		Shape * area_obje2 = &small_triangle1;	//triangle objesinin referencesini shape pointira atama
		shape_vector3.push_back(area_obje2);	//sortAll icin vektore koyma

		cout << "*************************************************************" << endl;
		//RECTANGLE ICINE CIRCLE
		Rectangle main_rectangle3(width,height,rCorx,rCory);
		Circle small_circle1(small_radius);
		ComposedShape shapes3(main_rectangle3, small_circle1);
		shapes3.setBigChar('R');
		shapes3.setSmallChar('C');
		shapes3.optimalFit();
		
		Shape * obje3 = &shapes3;	//ComposedShaped objesinin referencesi ni shape pointira atama
		shape_vector.push_back(obje3);	//printAll icin vektore koyma

		Shape * area_obje3 = &small_circle1;	//circle objesinin referencesini shape pointira atama
		shape_vector3.push_back(area_obje3);	//sortAll icin vektore koyma

	/////////////////////////////////////////////////////////////////////////////////////////////

		//Degiskenlerin degerleri
		length = 900;
		small_width = 110;
		small_height = 75;
		small_radius = 28;
		small_length = 95;
		tCorx1 = length / 2.0, tCorx2 = 0.0, tCorx3 = length;
		tCory1 = 0.0, tCory2 = length * sqrt(3.0) / 2.0, tCory3 = length * sqrt(3.0) / 2.0;



		cout << "*************************************************************" << endl;
		//TRIANGLE ICINE RECTANGLE
		Triangle main_triangle1 (length, tCorx1, tCorx2, tCorx3, tCory1, tCory2, tCory3);
		//Sadece bir triangle shape i batirmak icin tip atamasi(buyuk sekiller kirmizi renkte eger main_triangle1.setType("triangle"); olsaydi yesil basardi)
		main_triangle1.setType("TRIANGLE");	
		Rectangle small_rectangle2(small_width, small_height);
		ComposedShape shapes4(main_triangle1, small_rectangle2);
		shapes4.setBigChar('T');
		shapes4.setSmallChar('R');
		shapes4.optimalFit();

		PolygonVect poly3(main_triangle1);	//PolygonVect nin conversion constructuronu cagirma

		Shape * vect2_obje = &poly3;	//Shape pointirina poly3 in referencesi ni atama 
		shape_vector2.push_back(vect2_obje);	//printPoly icin vectore koyma
		
		Shape * obje4 = &shapes4;	//ComposedShaped objesinin referencesi ni shape pointira atama
		shape_vector.push_back(obje4);	//printAll icin vektore koyma

		Shape * area_obje4 = &small_rectangle2;	//rectangle objesinin referencesini shape pointira atama
		shape_vector3.push_back(area_obje4);	//sortAll icin vektore koyma

		cout <<  "*************************************************************" << endl;
		//TRIANGLE ICINE TRIANGLE
		Triangle main_triangle2 (length, tCorx1, tCorx2, tCorx3, tCory1, tCory2, tCory3);
		Triangle small_triangle2(small_length);
		ComposedShape shapes5(main_triangle2, small_triangle2);
		shapes5.setBigChar('T');
		shapes5.setSmallChar('T');
		shapes5.optimalFit();

		PolygonDyn poly4(main_triangle2);	//PolygonDyn nin conversion constructuronu cagirma

		Shape * dyn2_obje = &poly4;		//Shape pointirina poly4 in referencesi ni atama 
		shape_vector2.push_back(dyn2_obje);	//printPoly icin vectore koyma
		

		Shape * obje5 = &shapes5;	//ComposedShaped objesinin referencesi ni shape pointira atama
		shape_vector.push_back(obje5);	//printAll icin vektore koyma

		Shape * area_obje5 = &small_triangle2;	//triangle objesinin referencesini shape pointira atama
		shape_vector3.push_back(area_obje5);	//sortAll icin vektore koyma
		
		cout <<"*************************************************************" << endl;
		//TRIANGLE ICINE CIRCLE
		Triangle main_triangle3 (length, tCorx1, tCorx2, tCorx3, tCory1, tCory2, tCory3);
		Circle small_circle2(small_radius);
		ComposedShape shapes6(main_triangle3, small_circle2);
		shapes6.setBigChar('T');
		shapes6.setSmallChar('C');
		shapes6.optimalFit();
		
		Shape * obje6 = &shapes6;	//ComposedShaped objesinin referencesi ni shape pointira atama
		shape_vector.push_back(obje6);	//printAll icin vektore koyma

		Shape * area_obje6 = &small_circle2;	//circle objesinin referencesini shape pointira atama
		shape_vector3.push_back(area_obje6);	//sortAll icin vektore koyma

	////////////////////////////////////////////////////////////////////////////////////////////

		//Degiskenlerin degerleri
		radius = 879;
		small_width = 120;
		small_height = 75;
		small_radius = 37;
		small_length = 111;
		cCorx = radius, cCory = radius;

		cout <<"*************************************************************" << endl;
		//CIRCLE ICINE RECTANGLE
		Circle main_circle1 (radius,cCorx,cCory);
		//Sadece bir circle shape i batirmak icin tip atamasi(buyuk sekiller kirmizi renkte eger main_circle1.setType("CIRCLE"); olsaydi yesil basardi)
		main_circle1.setType("CIRCLE");
		Rectangle small_rectangle3(small_width,small_height);
		ComposedShape shapes7(main_circle1, small_rectangle3);
		shapes7.setBigChar('C');
		shapes7.setSmallChar('R');
		shapes7.optimalFit();

		PolygonDyn poly5(main_circle1);	//PolygonDyn nin conversion constructuronu cagirma

		Shape * dyn3_obje = &poly5;	//Shape pointirina poly5 in referencesi ni atama 
		shape_vector2.push_back(dyn3_obje);	//printPoly icin vectore koyma
		
		Shape * obje7 = &shapes7;	//ComposedShaped objesinin referencesi ni shape pointira atama
		shape_vector.push_back(obje7);	//printAll icin vektore koyma

		Shape * area_obje7 = &small_rectangle3;	//rectangle objesinin referencesini shape pointira atama
		shape_vector3.push_back(area_obje7);	//sortAll icin vektore koyma


		cout << "*************************************************************" << endl;
		//CIRCLE ICINE TRIANGLE	
		Circle main_circle2 (radius,cCorx,cCory);
		Triangle small_triangle3(small_length);
		ComposedShape shapes8(main_circle2, small_triangle3);
		shapes8.setBigChar('C');
		shapes8.setSmallChar('T');
		shapes8.optimalFit();

		PolygonVect poly6(main_circle2);	//PolygonVect nin conversion constructuronu cagirma

		Shape * vect3_obje = &poly6;	//Shape pointirina poly6 in referencesi ni atama 
		shape_vector2.push_back(vect3_obje);	//printPoly icin vectore koyma

		
		Shape * obje8 = &shapes8;	//ComposedShaped objesinin referencesi ni shape pointira atama
		shape_vector.push_back(obje8);	//printAll icin vektore koyma

		Shape * area_obje8 = &small_triangle3;	//triangle objesinin referencesini shape pointira atama
		shape_vector3.push_back(area_obje8);	//sortAll icin vektore koyma
		

		cout <<"*************************************************************" << endl;
		//CIRCLE ICINE CIRCLE
		Circle main_circle3(radius,cCorx,cCory);
		Circle small_circle3(small_radius);
		ComposedShape shapes9(main_circle3, small_circle3);
		shapes9.setBigChar('C');
		shapes9.setSmallChar('C');
		shapes9.optimalFit();
	
		Shape * obje9 = &shapes9;	//ComposedShaped objesinin referencesi ni shape pointira atama
		shape_vector.push_back(obje9);	//printAll icin vektore koyma


		Shape * obje10 = &main_rectangle1; //Ustteki main_rectangle1.setType("RECTANGLE"); tek basina bastirmak icin referansini shape pointira atma
		shape_vector.push_back(obje10); //printAll icin vektore atma

		Shape * obje11 = &main_triangle1;	//Ustteki main_triangle1.setType("TRIANGLE"); tek basina bastirmak icin referansini shape pointira atma
		shape_vector.push_back(obje11);	//printAll icin vektore atma

		Shape * obje12 = &main_circle1;	//Ustteki main_circle1.setType("CIRCLE"); tek basina bastirmak icin referansini shape pointira atma
		shape_vector.push_back(obje12);	//printAll icin vektore atma


		Shape * area_obje9 = &small_circle3;	//circle objesinin referencesini shape pointira atama
		shape_vector3.push_back(area_obje9);	//sortAll icin vektore koyma

		printALL(shape_vector); //printAll fonksiyonunu shape_vector ile cagirma
		printPoly(shape_vector2); // printPoly fonksiyonunu shape_vector_2 ile cagirma
		cout << endl;
		sortShapes(shape_vector3); //sortShape fonksiyonunu shape_vector_3 ile cagirma

	}

	//Cacth varsa yakalar ve programi sonlandirir
	catch(Rectangle_Error)
	{
		cerr << "Invalid Value For Rectangle" << endl;
		cerr << "Exiting" << endl;
		exit(1);
	}
	catch(Circle_Error)
	{
		cerr << "Invalid Value For Circle" << endl;
		cerr << "Exiting" << endl;
		exit(1);
	}
	catch(Triangle_Error)
	{
		cerr << "Invalid Value For Triangle" << endl;
		cerr << "Exiting" << endl;
		exit(1);
	}
	catch(ComposedShape_Error)
	{
		cerr << "THERE IS NOT ANY MATCHING FUNCTION" << endl;
		cerr << "Exiting" << endl;
		exit(1);
	}
}

void test_functions()
{
	try
	{
		Circle cir_deneme1(100.0,100.0,100.0);
		Circle cir_deneme2(50.0,50.0,50.0);

		Rectangle rec_deneme1(10.0,20.0,0.0,0.0);
		Rectangle rec_deneme2(20.0,10.0,0.0,0.0);

		Triangle tri_deneme1(30.0, 30.0/2.0, 0.0, 30.0, 0.0, 30.0 * sqrt(3.0) / 2.0, 30.0 * sqrt(3.0) / 2.0);

		Shape* deneme1 = &cir_deneme1;
		Shape* deneme2 = &cir_deneme2;
		Shape* deneme3 = &rec_deneme1;
		Shape* deneme4 = &rec_deneme2;
		Shape* deneme5 = &tri_deneme1;


		if(*deneme3 == *deneme4){
			cout << "1.Alan : " << deneme3->area() << endl;
			cout << "2.Alan : " <<  deneme4->area() << endl;
			cout << "Alanlari esit" << endl;
		}

		if(*deneme3 != *deneme4){
			cout << "1.Alan : " <<  deneme3->area() << endl;
			cout << "2.Alan : " <<  deneme4->area() << endl;
			cout << "Alanlari esit degil" << endl;
		}
		cout << "*****************************************" << endl;
		if(*deneme3 == *deneme1){
			cout << "1.Alan : " << deneme3->area() << endl;
			cout << "2.Alan : " <<  deneme1->area() << endl;
			cout << "Alanlari esit" << endl;
		}

		if(*deneme3 != *deneme1){
			cout << "1.Alan : " <<  deneme3->area() << endl;
			cout << "2.Alan : " <<  deneme1->area() << endl;
			cout << "Alanlari esit degil" << endl;
		}
		cout << "*****************************************" << endl;
		if(*deneme2 == *deneme5){
			cout << "1.Alan : " << deneme2->area() << endl;
			cout << "2.Alan : " <<  deneme5->area() << endl;
			cout << "Alanlari esit" << endl;
		}

		if(*deneme2 != *deneme5){
			cout << "1.Alan : " <<  deneme2->area() << endl;
			cout << "2.Alan : " <<  deneme5->area() << endl;
			cout << "Alanlari esit degil" << endl;
		}
		cout << "*****************************************" << endl;
		if(*deneme2 > *deneme1){
			cout << "1.Alan : " << deneme2->area() << endl;
			cout << "2.Alan : " <<  deneme1->area() << endl;
			cout << "Ilk alan daha buyuk" << endl;
		}

		if(*deneme2 <= *deneme1){
			cout << "1.Alan : " <<  deneme2->area() << endl;
			cout << "2.Alan : " <<  deneme1->area() << endl;
			cout << "Ikinci alan daha buyuk" << endl;
		}
		cout << "*****************************************" << endl;
		if(*deneme5 > *deneme3){
			cout << "1.Alan : " << deneme5->area() << endl;
			cout << "2.Alan : " <<  deneme3->area() << endl;
			cout << "Ilk alan daha buyuk" << endl;
		}

		if(*deneme5 <= *deneme3){
			cout << "1.Alan : " <<  deneme5->area() << endl;
			cout << "2.Alan : " <<  deneme3->area() << endl;
			cout << "Ikinci alan daha buyuk" << endl;
		}
		cout << "*****************************************" << endl;

		cout << "Prefix ++ isleminden once" << endl;
		cout << "Center_x : " << cir_deneme1.getCenter_x() << endl;
		cout << "Center_y : " << cir_deneme1.getCenter_y() << endl;

		++(*deneme1);

		cout << "Prefix ++ isleminden sonra" << endl;
		cout << "Center_x : " << cir_deneme1.getCenter_x() << endl;
		cout << "Center_y : " << cir_deneme1.getCenter_y() << endl;

		--(*deneme1);

		cout << "Prefix -- isleminden sonra" << endl;
		cout << "Center_x : " << cir_deneme1.getCenter_x() << endl;
		cout << "Center_y : " << cir_deneme1.getCenter_y() << endl;



		cout << "Prefix ++ isleminden once" << endl;
		cout << "Koordinat_x : " << rec_deneme1.getCor_x() << endl;
		cout << "Koordinat_x : " << rec_deneme1.getCor_y() << endl;

		(*deneme3)++;

		cout << "Postfix ++ isleminden sonra" << endl;
		cout << "Koordinat_x : " << rec_deneme1.getCor_x() << endl;
		cout << "Koordinat_x : " << rec_deneme1.getCor_y() << endl;
		
		(*deneme3)--;

		cout << "Postfix -- isleminden sonra" << endl;
		cout << "Koordinat_x : " << rec_deneme1.getCor_x() << endl;
		cout << "Koordinat_x : " << rec_deneme1.getCor_y() << endl;
	}
	catch(Rectangle_Error)
	{
		cerr << "Invalid Value For Rectangle" << endl;
		cerr << "Exiting" << endl;
		exit(1);
	}
	catch(Circle_Error)
	{
		cerr << "Invalid Value For Circle" << endl;
		cerr << "Exiting" << endl;
		exit(1);
	}
	catch(Triangle_Error)
	{
		cerr << "Invalid Value For Triangle" << endl;
		cerr << "Exiting" << endl;
		exit(1);
	}
}