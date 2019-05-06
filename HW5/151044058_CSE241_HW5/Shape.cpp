#include "Shape.h"

namespace HW5_151044058
{
	bool Shape :: operator==(Shape& other)
	{
		double const min = 0.00001;	//Double sayilarin karsilastirilmasi icin
		return(abs(this->area() - other.area()) < min);
	}
	bool Shape :: operator!=(Shape& other)
	{
		return(!(*this == other));
	}
	bool Shape :: operator>(Shape& other)
	{
		double const min = 0.00001;	//Double sayilarin karsilastirilmasi icin
		return((this->area() - other.area()) > min);
	}
	bool Shape :: operator<=(Shape& other)
	{
		return(!(*this > other));
	}
	ostream& operator<<(ostream &file, Shape& obje)
	{
		file << "<svg viewBox=\"1.1\"\n" << "baseProfile=\"full\"\n" << "xmlns=\"http:/" << "/www.w3.org/2000/svg\">\n";
		obje.draw_Shape(file); //virtual bir fonksiyon oldugu icin runtime da hangi objeyse onun draw_Shape fonksiyonunu cagirir
		file <<"</svg>\n";
		return file;
	}
}