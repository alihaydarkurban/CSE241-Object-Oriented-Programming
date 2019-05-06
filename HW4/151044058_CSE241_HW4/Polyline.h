#ifndef POLYLINE_H_
#define POLYLINE_H_
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

namespace HW4
{
	class Polyline
	{
		public:
			friend ostream& operator<<(ostream& file, Polyline temp_poli); // Polyline cizdirme islemi
			Polygon temp_polygon;	//Polygon objesi kullaniliyor
	};
}

#endif