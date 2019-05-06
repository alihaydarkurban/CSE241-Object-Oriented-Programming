#include "Triangle.h"

namespace HW5_151044058
{
	Triangle :: Triangle()
	{
		length = 600, cordinate_x1 = 300, cordinate_x2 = 0, cordinate_x3 = 600;
		cordinate_y1 = 0.0, cordinate_y2 = (600.0 * sqrt(3.0) / 2.0), cordinate_y3 = (600.0 * sqrt(3.0) / 2.0);
		
		static_total_area = static_total_area + area(); //static alani arttirma;
		static_total_PL = static_total_PL + perimeter();	//static cevreyi arttirma
	}

	Triangle ::	Triangle(double temp_length)throw(Triangle_Error)
	{
		//Uzunlugun negatif gelmesi durumunda throw yaptim
		if(temp_length <= 0)
			throw Triangle_Error();
		length = temp_length;
		static_total_area = static_total_area + area(); //static alani arttirma;
		static_total_PL = static_total_PL + perimeter(); //static cevreyi arttirma
	}

	Triangle ::Triangle(double temp_length, double x1, double x2, double x3, double y1, double y2, double y3)throw(Triangle_Error)
	{
		//Uzunlugun ve koordinatlarin hatali gelmesi durumunda throw yaptim
		if(temp_length <= 0 || x1 < 0 || x2 < 0 || x3 < 0 || y1 < 0 || y2 < 0 || y3 < 0 ||
		   x1 > temp_length || x2 > temp_length || x3 > temp_length ||
		   y1 > temp_length || y2 > temp_length || y3 > temp_length)
			throw Triangle_Error();

		length = temp_length;
		cordinate_x1 = x1;
		cordinate_x2 = x2;
		cordinate_x3 = x3;
		cordinate_y1 = y1;
		cordinate_y2 = y2;
		cordinate_y3 = y3;
		static_total_area = static_total_area + area(); //static alani arttirma;
		static_total_PL = static_total_PL + perimeter(); //static cevreyi arttirma
	}

	double Triangle :: getLength()const { return length; }
	inline double Triangle :: getCor_x1()const { return cordinate_x1; }
	inline double Triangle :: getCor_x2()const { return cordinate_x2; }
	inline double Triangle :: getCor_x3()const { return cordinate_x3; }
	inline double Triangle :: getCor_y1()const { return cordinate_y1; }
	inline double Triangle :: getCor_y2()const { return cordinate_y2; }
	inline double Triangle :: getCor_y3()const { return cordinate_y3; }

	void Triangle :: setLength(double lengthValue) 
	{ 
		length = lengthValue; 
	}
	void Triangle :: setCor_x1(double cordinate_x1Value) 
	{ 
		cordinate_x1 = cordinate_x1Value;
	}
	void Triangle :: setCor_x2(double cordinate_x2Value) 
	{ 
		cordinate_x2 = cordinate_x2Value; 
	}
	void Triangle :: setCor_x3(double cordinate_x3Value) 
	{ 
		cordinate_x3 = cordinate_x3Value; 
	}
	void Triangle :: setCor_y1(double cordinate_y1Value) 
	{ 
		cordinate_y1 = cordinate_y1Value; 
	}
	void Triangle :: setCor_y2(double cordinate_y2Value) 
	{ 
		cordinate_y2 = cordinate_y2Value;
	}
	void Triangle :: setCor_y3(double cordinate_y3Value) 
	{ 
		cordinate_y3 = cordinate_y3Value; 
	}

	string Triangle :: getType()const
	{
		return type;
	}
	void Triangle :: setType(string typeValue)
	{
		type = typeValue;
	}

	double Triangle :: perimeter()
	{
		return(3 * length);	/*Cevre uzunlugu	*/
	}
	double Triangle :: area()
	{
		return(length * length * sqrt(3.0) / 4.0 );	/*Alan	*/
	}

	void Triangle :: draw_Shape(ostream& file)
	{
		if(this->getType() == "TRIANGLE") //Buyuk sekilleri kirmizi cizdirmak icin kosul 
		{
			file << "<polygon points=" << "\"" << this->getCor_x1() << " " << this->getCor_y1() << " " << this->getCor_x2() << " " << this->getCor_y2() << " " 
			 << this->getCor_x3() << " " << this->getCor_y3() << "\"" << " fill=\"red\" stroke=\"white\" />\n" ;
		}
		else if(this->getType() == "triangle")	//Kucuk sekilleri yesil cizdirmak icin kosul 
		{
			file << "<polygon points=" << "\"" << this->getCor_x1() << " " << this->getCor_y1() << " " << this->getCor_x2() << " " << this->getCor_y2() << " " 
			 << this->getCor_x3() << " " << this->getCor_y3() << "\"" << " fill=\"green\" stroke=\"white\" />\n" ;
		}	
	}

	Shape& Triangle :: operator++() //Prefix ++ islemi
	{
		cordinate_x1 = cordinate_x1 + 1;
		cordinate_x2 = cordinate_x2 + 1;
		cordinate_x3 = cordinate_x3 + 1;
		cordinate_y1 = cordinate_y1 + 1;
		cordinate_y2 = cordinate_y2 + 1;
		cordinate_y3 = cordinate_y3 + 1;

		return *this;
	}

	Shape& Triangle :: operator++(int ignore)	//Postfix ++ islemi
	{
		double cordinate_x1_temp = cordinate_x1;
		double cordinate_x2_temp = cordinate_x2;
		double cordinate_x3_temp = cordinate_x3;
		double cordinate_y1_temp = cordinate_y1;		
		double cordinate_y2_temp = cordinate_y2;
		double cordinate_y3_temp = cordinate_y3;
		cordinate_x1_temp = cordinate_x1_temp + 1;
		cordinate_x2_temp = cordinate_x2_temp + 1;
		cordinate_x3_temp = cordinate_x3_temp + 1;
		cordinate_y1_temp = cordinate_y1_temp + 1;
		cordinate_y2_temp = cordinate_y2_temp + 1;
		cordinate_y3_temp = cordinate_y3_temp + 1;

		cordinate_x1 = cordinate_x1_temp, cordinate_x2 = cordinate_x2_temp, cordinate_x3 = cordinate_x3_temp;
		cordinate_y1 = cordinate_y1_temp, cordinate_y2 = cordinate_y2_temp, cordinate_y3 = cordinate_y3_temp;

		return *this;
	}

	Shape& Triangle :: operator--()	//Prefix -- islemi
	{
		cordinate_x1 = cordinate_x1 - 1;
		cordinate_x2 = cordinate_x2 - 1;
		cordinate_x3 = cordinate_x3 - 1;
		cordinate_y1 = cordinate_y1 - 1;
		cordinate_y2 = cordinate_y2 - 1;
		cordinate_y3 = cordinate_y3 - 1;

		return *this;
	}

	Shape& Triangle :: operator--(int ignore) //Postfix -- islemi
	{
		double cordinate_x1_temp = cordinate_x1;
		double cordinate_x2_temp = cordinate_x2;
		double cordinate_x3_temp = cordinate_x3;
		double cordinate_y1_temp = cordinate_y1;		
		double cordinate_y2_temp = cordinate_y2;
		double cordinate_y3_temp = cordinate_y3;
		cordinate_x1_temp = cordinate_x1_temp - 1;
		cordinate_x2_temp = cordinate_x2_temp - 1;
		cordinate_x3_temp = cordinate_x3_temp - 1;
		cordinate_y1_temp = cordinate_y1_temp - 1;
		cordinate_y2_temp = cordinate_y2_temp - 1;
		cordinate_y3_temp = cordinate_y3_temp - 1;

		cordinate_x1 = cordinate_x1_temp, cordinate_x2 = cordinate_x2_temp, cordinate_x3 = cordinate_x3_temp;
		cordinate_y1 = cordinate_y1_temp, cordinate_y2 = cordinate_y2_temp, cordinate_y3 = cordinate_y3_temp;

		return *this;
	}

	const Triangle Triangle :: operator+(double bigger)const // Kenara bir doubl eklenmis objeyi return eder 
	{
		return(Triangle((length + bigger),cordinate_x1, cordinate_x2, cordinate_x3, cordinate_y1, cordinate_y2, cordinate_y3));
	}

	const Triangle Triangle :: operator-(double smaller)const	//Kenardan bir double cikartilmis objeyi return eder
	{
		return(Triangle((length - smaller),cordinate_x1, cordinate_x2, cordinate_x3, cordinate_y1, cordinate_y2, cordinate_y3));
	}

	double Triangle :: return_total_area()	//static fonksiyondur. Toplam static alani return eder.
	{
		return static_total_area;
	}
	double Triangle :: return_total_PL()	//static fonksiyondur. Toplam static cevreyi return eder.
	{
		return static_total_PL;
	}
}