#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

#include "Circle.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Polygon.h"
#include "Polyline.h"

namespace HW4
{

	ostream& operator<<(ostream& file, Polyline temp_poli)
	{
		int i;
		file << "<svg viewBox=\"1.1\"\n" << "baseProfile=\"full\"\n" << "xmlns=\"http:/" << "/www.w3.org/2000/svg\">\n";
		if(temp_poli.temp_polygon.getType() == "B")	//Circle icin
		{
			for(i=0;i<temp_poli.temp_polygon.getSize() - 1; ++i)
			{
				file << "<polyline points=\"" << temp_poli.temp_polygon.ptr[i].getKoor_x()<<" "<< temp_poli.temp_polygon.ptr[i].getKoor_y() << " " << temp_poli.temp_polygon.ptr[i+1].getKoor_x()<<" "
				<< temp_poli.temp_polygon.ptr[i+1].getKoor_y()<<" " << "\" style=\"fill:none;stroke:red;stroke-width:8\"" <<" />\n";
			}
		}
		else //Diger sekiller icin
		{
			for(i=0;i<temp_poli.temp_polygon.getSize() - 1; ++i)
			{
				file << "<polyline points=\"" << temp_poli.temp_polygon.ptr[i].getKoor_x()<<" "<< temp_poli.temp_polygon.ptr[i].getKoor_y() << " " << temp_poli.temp_polygon.ptr[i+1].getKoor_x()<<" "
				<< temp_poli.temp_polygon.ptr[i+1].getKoor_y()<<" " << "\" style=\"fill:none;stroke:red;stroke-width:8\"" <<" />\n";
			}
		}
		file <<"</svg>\n";
	}
	
}