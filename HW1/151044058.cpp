/*
	ALI HAYDAR KURBAN 151044058 CSE-241 HW1
*/
#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
using namespace std;

const double PI = 3.14;	/*Alan hesabi icin pi sayisi 	*/

enum class Shapes 
{
        RECTANGLE, TRIANGLE, CIRCLE       
};

void mainRectangle(ofstream& file);	/*Buyuk dikdortgen cizdirme fonksiyonu	*/
void mainTriangle(ofstream& file);	/*Buyuk ucgen cizdirme fonksiyonu	*/
void mainCircle(ofstream& file);	/*Buyuk daire cizdirme fonksiyonu	*/
void smallCircle_to_Rectangle(ofstream& file ,const int width ,const int height); /*Dikdorgenin icine daire koyma fonksiyonu	*/
void smallTriangle_to_Rectangle(ofstream& file , const int width , const int height);	/*Dikdorgenin icine ucgen koyma fonksiyonu	*/
void smallRectangle_to_Rectangle(ofstream& file ,const int width ,const int height);	/*Dikdorgenin icine dikdortgen koyma fonksiyonu	*/
void smallTriangle_to_Triangle(ofstream& file  , const int length);	/*Ucgenin icine ucgen koyma fonskiyonu	*/
void smallCircle_to_Triangle(ofstream& file ,const int length);	/*Ucgenin icine daire koyma fonskiyonu	*/
void smallRectangle_to_Triangle(ofstream& file , const int length);	/*Ucgenin icine dikdortgen koyma fonskiyonu	*/
void small_Circle_to_Circle(ofstream& file ,const int radius);	/*Dairenin icine daire koyma fonskiyonu	*/
void small_Triangle_to_Circle(ofstream& file ,const int radius);	/*Dairenin icine ucgen koyma fonskiyonu	*/
void small_Rectangle_to_Circle(ofstream& file ,const int radius);	/*Dairenin icine dikdortgen koyma fonskiyonu	*/



int main()
{
	ofstream file;
	file.open("output.svg");	/*Dosya acma	*/

	cout <<	"Please enter the main container shape (R, C, T)" << endl;
	
	Shapes main_ch;	/*Obje olusturma	*/
	
	char ch;
	cin >> ch;

	if(ch == 'R' || ch == 'r')	/*Rectangle icin sartlar	*/
	{
		main_ch = Shapes :: RECTANGLE;
		if(main_ch == Shapes :: RECTANGLE)
			mainRectangle(file);
	}			
	else if(ch == 'T' || ch == 't')	/*Triangle icin sartlar	*/
	{
		main_ch = Shapes :: TRIANGLE;
		if(main_ch == Shapes :: TRIANGLE)
			mainTriangle(file);
	}		
	else if(ch == 'C' || ch == 'c')	/*Circle icin sartlar	*/
	{
		main_ch = Shapes :: CIRCLE;
		if(main_ch == Shapes :: CIRCLE )
			mainCircle(file);
	}	
	else
		cerr << endl << "You have entered incorrect character!!!" <<endl;	/*Htali sekil secme durumu	*/

	file << "\n</svg>";	/*svg kodunu bitirme	*/
	file.close();	/*Dosyayi kapatma	*/

	return 0;
}

void mainRectangle(ofstream& file)
{
	cout <<"Please enter the width" << endl;
	int width,height;
	cin >> width;	
	cout <<"Please enter the height" << endl;
	cin >> height;

	if(width <= 0 || height <= 0)	/*Inputlarin kontrolu	*/
    	cerr << endl <<"Eror!!! You have entered incorrect number!!!" <<endl;

    else
    {    	
		string s1 = "<svg viewBox=\"1.1\"\n"; 
		string s2 = "baseProfile=\"full\"\n";
		string s3 = "width=" , s_tirnak = "\""  , s4 = " height="  ,s5 = "\n";
		string s6 = "xmlns=\"http:/" , s7 = "/www.w3.org/2000/svg\">\n";
		string s8 = "<rect width=\"100%\" height=\"100%\" fill=\"red\"/>\n";
		string total;
		auto str_width = to_string(width);
		auto str_height = to_string(height);
		
		total = s1 + s2 + s3 + s_tirnak + str_width + s_tirnak + s4 +s_tirnak + str_height + s_tirnak + s5 + s6 + s7 + s8;	/*Stringleri toplama	*/

		if(file.is_open())
			file << total;

		cout <<	"Please enter the small shape (R, C, T)" << endl;
		
		Shapes small_ch;	/*Obje olusturma	*/
		char ch;
		cin >> ch;

		if(ch == 'C' || ch == 'c')		/*Circle koymak icin sartlar	*/
		{
			small_ch = Shapes :: CIRCLE;
			if(small_ch == Shapes :: CIRCLE )
				smallCircle_to_Rectangle(file ,  width , height);
		}		
		else if(ch == 'T' || ch == 't')	/*Triangle koymak icin sartlar	*/
		{
			small_ch = Shapes :: TRIANGLE;
			if(small_ch == Shapes :: TRIANGLE)
				smallTriangle_to_Rectangle(file ,  width , height);
		}		
		else if(ch == 'R' || ch == 'r')	/*Rectangle koymak icin sartlar	*/
		{
			small_ch = Shapes :: RECTANGLE;
			if(small_ch == Shapes :: RECTANGLE)
				smallRectangle_to_Rectangle(file , width , height);
		}
		else
			cerr << endl << "Eror!!! You have entered incorrect character!!!" <<endl;			/*Hatali sekil secme durumu	*/	
	}
}

void mainTriangle(ofstream& file)
{
	cout <<"Please enter the length" << endl;
	int length;
	cin >> length;

	if(length <= 0)		/*Input kontrolu	*/
    	cerr << endl <<"Eror!!! You have entered incorrect number!!!" <<endl;

    else
    {
    	string s1 = "<svg width=" ,  s_tirnak = "\"" , s2 = " height="; 
		string s3 = " xmlns=\"http:/" , s4 = "/www.w3.org/2000/svg\">\n";
		string s5 = "<polygon points=" , s6 = " fill=\"red\" />\n" ;
		string bosluk = " ";
		string total;
		auto str_length_1 = to_string(length);
		auto str_length_2 = to_string(length * sqrt(3.0) / 2.0 );	/*Uzunlularin bulunup string yapılmasi	*/
		auto str_length_3 = to_string(length / 2.0);
		auto sifir = to_string(0);
		
		total = s1 + s_tirnak + str_length_1 + s_tirnak + s2 + s_tirnak + str_length_2 + s_tirnak + 
				s3 + s4 + s5 + s_tirnak + str_length_3 + bosluk + sifir + bosluk + sifir + bosluk + 	/*Stringleri toplama*/
				str_length_2 + bosluk + str_length_1 + bosluk + str_length_2 + s_tirnak + s6;

		if(file.is_open())
			file << total;

		cout <<	"Please enter the small shape (R, C, T)" << endl;

		Shapes small_ch;	/*Obje olusturma	*/
		char ch;
		cin >> ch;

		if(ch == 'C' || ch == 'c')	/*Circle koymak icin sartlar	*/
		{
			small_ch = Shapes :: CIRCLE;
			if(small_ch == Shapes :: CIRCLE )
				smallCircle_to_Triangle(file , length);
		}			
		else if(ch == 'T' || ch == 't')	/*Triangle koymak icin sartlar	*/
		{
			small_ch = Shapes :: TRIANGLE;
			if(small_ch == Shapes :: TRIANGLE)
				smallTriangle_to_Triangle(file , length);
		}		
		else if(ch == 'R' || ch == 'r')	/*Rectangle koymak icin sartlar	*/
		{
			small_ch = Shapes :: RECTANGLE;
			if(small_ch == Shapes :: RECTANGLE)
				smallRectangle_to_Triangle(file , length);
		}
		else
			cerr << endl << "Eror!!! You have entered incorrect character!!!" <<endl;	   	/*Hatali sekil secme durumu	*/
    }		
}

void mainCircle(ofstream& file)
{
	cout << "Please enter the radius" << endl;
	int radius;
	cin >> radius;

	if(radius <= 0)		/*Input kontrolu	*/
    	cerr << endl <<"Eror!!! You have entered incorrect number!!!" <<endl;

    else
    {
    	string s1 = "<svg width=" ,  s_tirnak = "\"" , s2 = " height="; 
		string s3 = " xmlns=\"http:/" , s4 = "/www.w3.org/2000/svg\">\n";
		string s5 = "<circle cx=" , s6 = " cy=" , s7 = " r=" , s8 = " fill=\"red\" />\n";
		string total;
		auto str_radius = to_string(radius);
		auto str_diameter = to_string(2 * radius); 	/*Sayilari stringe cevirme islemi	*/

		total = s1 + s_tirnak + str_diameter + s_tirnak + s2 + s_tirnak + 
				str_diameter + s_tirnak + s3 + s4 + s5 + s_tirnak + str_radius + 	/*String toplama islemi	*/
				s_tirnak + s6 + s_tirnak + str_radius + s_tirnak +
				s7 + s_tirnak + str_radius + s_tirnak + s8 ;

		if(file.is_open())
			file << total;

		cout <<	"Please enter the small shape (R, C, T)" << endl;

		Shapes small_ch;	/*Obje olusturma	*/
		char ch;
		cin >> ch;

		if(ch == 'C' || ch == 'c')	/*Circle koymak icin sartlar	*/
		{
			small_ch = Shapes :: CIRCLE;
			if(small_ch == Shapes :: CIRCLE )
				small_Circle_to_Circle(file , radius);
		}
				
		else if(ch == 'T' || ch == 't')	/*Triangle koymak icin sartlar	*/
		{
			small_ch = Shapes :: TRIANGLE;
			if(small_ch == Shapes :: TRIANGLE)
				small_Triangle_to_Circle(file , radius);
		}
			
		else if(ch == 'R' || ch == 'r')	/*Rectangle koymak icin sartlar	*/
		{
			small_ch = Shapes :: RECTANGLE;
			if(small_ch == Shapes :: RECTANGLE)
				small_Rectangle_to_Circle(file , radius);
		}
		else
			cerr << endl << "Eror!! You have entered incorrect character!!!" <<endl;	/*Hatali sekil secme durumu	*/		
	}
}

void smallCircle_to_Rectangle(ofstream& file , const int width , const int height)	
{
	cout <<"Please enter the radius" << endl;
	int radius;
	cin >> radius;	

	if(radius <= 0)	/*Input kontrolu	*/
    	cerr << endl <<"Eror!!! You have entered incorrect number!!!" <<endl;
    
    else
    {
		string s1 = "<circle cx=" , s_tirnak = "\"" , s2 = " cy=" ,s3 = " r=" , s4 = " fill=\"green\" stroke=\"black\"/>\n";
		string total;

		int i , j;
		int counter_x = width / (2 * radius);
		int counter_temp_y = height / (2 * radius);
		int counter_y = 2 * height / ((radius +radius*sqrt(3.0)));		/*Baslangic noktalarinin ve dongu sayilarinin bulunmasi	*/
		double new_center_x = radius;  
		double new_center_y = radius;

		int total_circle_1 = counter_x * counter_temp_y;	/*Duz bir sekilde daireleri yerlestirince kac adet daire sigivaginin sayisi	*/
		int total_circle_2 = 0;

		auto str_radius = to_string(radius);
		int center_x = radius;
		int center_y = radius;
		auto str_centerX = to_string(center_x);
		auto str_centerY = to_string(center_y);

		/*ASAGIDAKI DONGULER ILE DAIRELERIN BASLANGIC NOKTALARINI KESISTIKLERI YER YAPARAK KAC ADET SIGACAGINI BULDUM 	*/
		for(i = 0; i < counter_y; ++i)
		{
			for(j = 0; j < counter_x; ++j)
			{	
				new_center_x = new_center_x + 2 * radius;

				if((new_center_x + radius) <= width && (new_center_y + radius * sqrt(3.0)) <= height)
					total_circle_2 = total_circle_2 + 1;									
			}

			if(i % 2 == 1)
				new_center_x = radius;
				
			else if(i % 2 == 0)
				new_center_x =  2 * radius;
			
			if((new_center_y + radius * sqrt(3.0)) <= height )
			{
				new_center_y = new_center_y + radius * sqrt(3.0);
				total_circle_2 = total_circle_2 + 1;
			}

		}

		if(total_circle_1 <= 0 && total_circle_2 <= 0)	/*Hic daire sigmama durumu	*/
			cerr << "Eror!! I can not fit any circle to rectangle" << endl;

		else
		{
			if(total_circle_1 >= total_circle_2)	/*1. yontem ile daha fazla sigarsa o sekli svg dosyasina yazma durumu	*/
			{
				center_x = radius;
				center_y = radius;

				counter_x = width / (2 * radius);	/*Merkezleri ayarlama	*/
				counter_temp_y = height / (2 * radius);

				for(i = 0; i < counter_temp_y; ++i)
				{
					for(j = 0; j < counter_x; ++j)
					{
						str_centerX = to_string(center_x);	/*Stringe cevirme islemleri*/
						center_x = center_x + 2 * radius;	
						str_centerY = to_string(center_y);

						total = s1 + s_tirnak + str_centerX + s_tirnak + s2 + s_tirnak + str_centerY + s_tirnak + s3 + s_tirnak + str_radius + s_tirnak + s4; /*Sting toplama islemi*/

						if(file.is_open())
							file << total;
					}
					center_x = radius;
					center_y = center_y + 2 * radius;	/*Merkz noktalari guncelleme	*/
				}
				cout << "I can fit at " <<  total_circle_1 << " small shapes into the main container. "<< endl	                     /*Ekrana bilgileri bastirma	*/
					 << "The empty area (red) in " << (width * height) - (total_circle_1 * PI * radius * radius) << "." << endl;
			}

			else
			{
				counter_y = 2 * height / ((radius + radius * sqrt(3.0)));	/*Normal olmasi gereknenden fazla dondurmek icin tastigi yerlerde sgv ye ekleme yapilmaz	*/
		
				new_center_x = radius;
				new_center_y = radius;	/*Merkezleri guncelleme	*/

				/*ASAGIDAKI DONGULER ILE DAIRELERIN BASLANGIC NOKTALARINI KESISTIKLERI YER YAPARAK SVG DOSYASINA YAZDIM 	*/
				for(i = 0; i < counter_y; ++i)
				{
					for(j = 0; j < counter_x; ++j)
					{			
						if((new_center_x + radius) <= width && (new_center_y + radius * sqrt(3.0)) <= height)
						{
							str_centerX = to_string(new_center_x );
							str_centerY = to_string(new_center_y );	

							total = s1 + s_tirnak + str_centerX + s_tirnak + s2 + s_tirnak + str_centerY + s_tirnak + s3 + s_tirnak + str_radius + s_tirnak + s4;
						
							if(file.is_open())
								file << total;	

							if(new_center_x + radius <= width)	/*Tasmadigi surece ekleme yapma	*/
								new_center_x = new_center_x + 2 * radius;
						}						
					}
					if(i % 2 == 1)
						new_center_x = radius;
						
					else if(i % 2 == 0)
						new_center_x =  2 * radius;

					if((new_center_y + radius * sqrt(3.0)) <= height )	/*Tasmadigi surece ekleme yapma	*/
						new_center_y = new_center_y + radius * sqrt(3.0);
				}
				cout << "I can fit at " <<  total_circle_2 << " small shapes into the main container. "<< endl				/*Ekrana bilgileri bastirma	*/
				 	 << "The empty area (red) in " << (width * height) - (total_circle_2 * PI * radius * radius) << "." << endl;
			}	
		}
    }	
}

void smallRectangle_to_Rectangle(ofstream& file ,const int width ,const int height)
{
	int small_width, small_height;
	int start_x = 0 , start_y = 0;

	cout <<"Please enter the width" << endl;
	cin >> small_width;	
	cout <<"Please enter the height" << endl;
	cin >> small_height;

	if(small_width <= 0 || small_height <= 0)	/*Input kontrolleri	*/
    	cerr << endl <<"Eror!!! You have entered incorrect number!!!" <<endl;

    else
    {
		string s1 = "<rect  x=" , s2 = " y=" , s3 = " width=" , s4 = " height=" ;
		string s5 = " fill=\"green\" stroke=\"white\" />\n" , s_tirnak ="\"";
		string total;
	    
	    int i,j;
		int counter_x = 0 , counter_y = 0;
		int total_rectangle = 0;
		auto str_small_widht = to_string(small_width);	/*Bilgileri stringe cevirme	*/
		auto str_small_height = to_string(small_height); 

		if((width % small_height == 0) && (height % small_width == 0) )	/*Dikdorgenlerin koseleri ters sekilde birbirinin katiysa tam sigar o yuzden bu kosul var. Bosta yer kalmaz	*/
		{
			counter_x = height / small_width;
			counter_y = width / small_height;	/*Dongu sayisini bulma	*/

			auto str_start_x = to_string(start_x);
			auto str_start_y = to_string(start_y);	/*Bilgileri stringe cevirme	*/

			/*DONGULER ILE DIKDORTGENLERI SVG DOSYASINA YAZDIM	*/
			for(i = 0; i < counter_x; ++i)
			{
				for(j = 0; j < counter_y; ++j)
				{
					str_start_x = to_string(start_x);
					str_start_y = to_string(start_y);
					total = s1 + s_tirnak + str_start_x + s_tirnak + s2 + s_tirnak + str_start_y +
					 		s_tirnak + s3 + s_tirnak + str_small_height + s_tirnak + s4 + s_tirnak +
					 		str_small_widht + s_tirnak + s5;

					 if(file.is_open())
					 	file << total;

					start_x = start_x + small_height;	/*Baslangic noktalarini guncellleme	*/
					total_rectangle = total_rectangle + 1;
				}

				start_x = 0;
				start_y = start_y + small_width ;
			}
			cout << "I can fit at " <<  total_rectangle << " small shapes into the main container. "<< endl							/*Ekrana bilgileri bastirma	*/
				 << "The empty area (red) in " << (width * height) - (total_rectangle *small_width * small_height) << "." << endl;

		}

		else	/*Dikdorgenlerin koselerinin birbirinin tam kati olmamasi durumu. Bosta yer kalir	*/
		{
			total_rectangle = 0;
			counter_x = width / small_width;
			counter_y = height / small_height;

			auto str_start_x = to_string(start_x);
			auto str_start_y = to_string(start_y);

			/*DONGULER ILE DIKDORTGENLERI YANYANA SVG DOSYASINA YAZDIM	*/
			for(i = 0; i < counter_y; ++i)
			{
				for(j = 0; j < counter_x; ++j)
				{
					str_start_x = to_string(start_x);
					str_start_y = to_string(start_y);
					total = s1 + s_tirnak + str_start_x + s_tirnak + s2 + s_tirnak + str_start_y +
					 		s_tirnak + s3 + s_tirnak + str_small_widht + s_tirnak + s4 + s_tirnak +
					 		str_small_height + s_tirnak + s5;

					 if(file.is_open())
					 	file << total;

					start_x = start_x + small_width;
					total_rectangle = total_rectangle + 1;
				}

				start_x = 0;
				start_y = start_y + small_height ;
			}

			int new_space_x = width - (counter_x * small_width);	/*Sag tarafta bosluk varsa onun kontrolu	*/
			int new_counter_x = 0;
			int new_counter_y = 0;

			if(new_space_x >= small_height )	/*Sag tarafta bosluk varsa ve dikdortgen donduruldugu zaman oraya sigiyorsa bu islem yapilir	*/
			{

				new_counter_x = new_space_x / small_height;
				new_counter_y = height / small_width;	/*Yeni dongu sayisi belirleme	*/

				start_x = counter_x * small_width;
				start_y = 0;					/*Yeni noktalar belirlenir	*/

				/*DONGULER ILE DIKDORTGENLERI YAN CEVIRIP SAG TARAFTA SVG DOSYASINA YAZDIM	*/
				for(i = 0; i < new_counter_y; ++i)
				{
					for(j = 0; j < new_counter_x; ++j)
					{
						str_start_x = to_string(start_x);
						str_start_y = to_string(start_y);
						total = s1 + s_tirnak + str_start_x + s_tirnak + s2 + s_tirnak + str_start_y +
						 		s_tirnak + s3 + s_tirnak + str_small_height + s_tirnak + s4 + s_tirnak +
						 		str_small_widht + s_tirnak + s5;

						 if(file.is_open())
						 	file << total;

						start_x = start_x + small_height;
						total_rectangle = total_rectangle + 1;
					}

					start_x = counter_x * small_width;;
					start_y = start_y + small_width;
					
				}
			}

			int new_space_y = height - (counter_y * small_height);	/*Alt tarafta bosluk varsa onun kontrolu	*/

			int new_counter_x1 = 0;
			int new_counter_y1 = 0;

			if(new_space_y >= small_width)	/*Alt tarafta bosluk varsa ve dikdortgen donduruldugu zaman oraya sigiyorsa bu islem yapilir	*/
			{
				new_counter_x1 = width / small_height ;
				new_counter_y1 = new_space_y / small_width;		/*Yeni dongu sayisi belirleme	*/

				start_x = 0;
				start_y = counter_y * small_height;	/*Yeni noktalar belirlenir	*/

				/*DONGULER ILE DIKDORTGENLERI YAN CEVIRIP ALT TARAFTA SVG DOSYASINA YAZDIM	*/
				for(i = 0; i < new_counter_y1; ++i)
				{

					for(j = 0; j < new_counter_x1; ++j)
					{
						str_start_x = to_string(start_x);
						str_start_y = to_string(start_y);
						total = s1 + s_tirnak + str_start_x + s_tirnak + s2 + s_tirnak + str_start_y +
						 		s_tirnak + s3 + s_tirnak + str_small_height + s_tirnak + s4 + s_tirnak +
						 		str_small_widht + s_tirnak + s5;

						 if(file.is_open())
						 	file << total;

						start_x = start_x + small_height;
						total_rectangle = total_rectangle + 1;
					}

					start_x = 0;
					start_y = start_y + small_width ;				
				}
			}
			if(total_rectangle != 0)
				cout << "I can fit at " <<  total_rectangle << " small shapes into the main container. "<< endl									/*Ekrana bilgileri bastirma	*/
					 << "The empty area (red) in " << (width * height) - (total_rectangle *small_width * small_height) << "." << endl;
		}
		if(total_rectangle <= 0)
			cerr << "Eror!! I can not fit any rectangle to rectangle" << endl;
    }	
}

void smallTriangle_to_Rectangle(ofstream& file ,const int width ,const int height)
{
	cout <<"Please enter the length" << endl;

	int length;
	cin >> length;

	if(length <= 0)		/*Input kontrolu	*/
    	cerr << endl <<"Eror!!! You have entered incorrect number!!!" <<endl;
    else
    {
    	string s1 = "\n<polygon points=" , s2 =" fill=\"green\"  stroke=\"white\" />" , s_tirnak = "\"" , bosluk = " " ;
		string total;

    	double x1 = length / 2.0;
		double y1 = 0.0 ;		/*Koordinatlarin belirlenmesi	*/
		double x2 = 0.0;
		double y2 = length * sqrt(3.0) / 2.0;
		double x3 = static_cast <double> (length);
		double y3 = length * sqrt(3.0) / 2.0;


		auto s_x1 = to_string(x1);
		auto s_y1 = to_string(y1);
		auto s_x2 = to_string(x2);
		auto s_y2 = to_string(y2);	/*Koordinatlari stringe cevirme	*/
		auto s_x3 = to_string(x3);
		auto s_y3 = to_string(y3);

		int counter_x1 = width / length ;
		int counter_y1 = height / (length * sqrt(3.0) / 2.0);	/*Dongu sayisini bulma	*/
		int i , j;
		int total_triangle = 0;

		/*BU DONGULERLE UCGENLERI DUZ SEKILDE SVG DOSYASINA BASTIRDIM*/
		for(i = 0; i < counter_y1; ++i)
		{

			for(j = 0; j < counter_x1; ++j)
			{
				total = s1 + s_tirnak + s_x1 + bosluk + s_y1 + bosluk + s_x2 + bosluk + 
					s_y2 + bosluk + s_x3 + bosluk + s_y3 + s_tirnak + s2;

				if(file.is_open())
					 file << total;

				total_triangle = total_triangle + 1;

				x1 = x1 + length ;
				x2 = x2 + length ;	/*Koordinatlarin yenilenmesi	*/
				x3 = x3 + length ;
				s_x1 = to_string(x1);
				s_x2 = to_string(x2);
				s_x3 = to_string(x3);
			}
			x1 = length / 2.0;
			x2 = 0.0;
			x3 = static_cast <double> (length);
			y1 = y1 + (length * sqrt(3.0) / 2.0);
			y2 = y2 + (length * sqrt(3.0) / 2.0);	/*Koordinatlarin yenilenmesi 	*/
			y3 = y3 + (length * sqrt(3.0) / 2.0);
			s_x1 = to_string(x1);
			s_x2 = to_string(x2);
			s_x3 = to_string(x3);	/*Stringe cevirme islemleri	*/
			s_y1 = to_string(y1);
			s_y2 = to_string(y2);
			s_y3 = to_string(y3);
		}

		int counter_x2 = (width - (length / 2.0)) / length;	/*Dongu sayisini bulma	*/

		x1 = length / 2.0;
		y1 = 0.0;
		x2 = (length / 2.0) + length;	/*koordinatlarin belirlenmesi	*/
		y2 =  0.0;
		x3 = length;
		y3 = length * sqrt(3.0) / 2.0;

		s_x1 = to_string(x1);
		s_x2 = to_string(x2);
		s_x3 = to_string(x3);
		s_y1 = to_string(y1);	/*Stiringe cevirme islemi	*/
		s_y2 = to_string(y2);
		s_y3 = to_string(y3);

		/*BU DONGULERLE UCGENLERI TERS SEKILDE SVG DOSYASINA BASTIRDIM*/
		for(i = 0 ; i < counter_y1; ++i)
		{
			for(j = 0; j < counter_x2; ++j)
			{
				total = s1 + s_tirnak + s_x1 + bosluk + s_y1 + bosluk + s_x2 + bosluk + 
					s_y2 + bosluk + s_x3 + bosluk + s_y3 + s_tirnak + s2;

				if(file.is_open())
					 file << total;

				total_triangle = total_triangle + 1;

				x1 = x1 + length ;
				if((x2 + length) <= width)	/*Koordinatlarin yenilenmesi 	*/
					x2 = x2 + length ;
				x3 = x3 + length ;
				s_x1 = to_string(x1);
				s_x2 = to_string(x2);
				s_x3 = to_string(x3);
			}

			x1 = length / 2.0;
			x2 = (length / 2.0) + length;
			x3 = length;
			y1 = y1 + (length * sqrt(3.0) / 2.0);
			y2 = y2 + (length * sqrt(3.0) / 2.0);
			y3 = y3 + (length * sqrt(3.0) / 2.0);

			s_x1 = to_string(x1);
			s_x2 = to_string(x2);
			s_x3 = to_string(x3);	/*Stringe cevirme islemleri	*/
			s_y1 = to_string(y1);
			s_y2 = to_string(y2);
			s_y3 = to_string(y3);
		}
		if(total_triangle > 0)
    		cout << "I can fit at " <<  total_triangle << " small shapes into the main container. "<< endl									/*Bilgilendirme	*/
		 		 << "The empty area (red) in " << (width * height) - (total_triangle * length * length * sqrt(3.0) / 4.0) << "." << endl;
		else
			cerr << "Eror!! I can not fit any triangle to rectangle" << endl;
    }
}

void smallTriangle_to_Triangle(ofstream& file  ,const int length)
{
	cout <<"Please enter the length" << endl;

	int small_length;
	cin >> small_length;

	if(small_length <= 0)	/*Input kontrolu	*/
    	cerr << endl <<"Eror!!! You have entered incorrect number!!!" <<endl;
	
	else
	{	
		string s1 = "\n<polygon points=" , s2 =" fill=\"green\"  stroke=\"white\" />" , s_tirnak = "\"" , bosluk = " " ;
		string total;

		int i,j;
		double x1 = length / 2.0;
		double y1 = 0.0 ;
		double x2 = length / 2.0 - small_length / 2.0;	/*Koordinatlarin belirlenmesi	*/
		double y2 = small_length * sqrt(3.0) / 2.0;
		double x3 = length / 2.0 + small_length / 2.0;
		double y3 = small_length * sqrt(3.0) / 2.0;

		int counter_y = ((length * sqrt(3.0) / 2.0 ) / (small_length * sqrt(3.0) / 2.0));
		int counter_x = length / small_length ;
		int total_triangle = 0;

		auto s_x1 = to_string(x1);
		auto s_y1 = to_string(y1);
		auto s_x2 = to_string(x2);	/*Stringe cevirme islemi	*/
		auto s_y2 = to_string(y2);
		auto s_x3 = to_string(x3);
		auto s_y3 = to_string(y3);

		/*BU DONGULERLE UCGENLERI DUZ SEKILDE SVG DOSYASINA BASTIRDIM*/
		for(i = 0; i < counter_y; ++i)
		{
			for(j = 0 ; j < i + 1; ++j)
			{

				total = s1 + s_tirnak + s_x1 + bosluk + s_y1 + bosluk + s_x2 + bosluk + 
					s_y2 + bosluk + s_x3 + bosluk + s_y3 + s_tirnak + s2;

				if(file.is_open())
					 file << total;

				total_triangle = total_triangle + 1;

				x1 = x1 + small_length ;
				x2 = x2 + small_length ;	/*Koordinatlari yenileme	*/
				x3 = x3 + small_length ;
				s_x1 = to_string(x1);
				s_x2 = to_string(x2);
				s_x3 = to_string(x3);
			}

			x1 = length / 2.0;
			x2 = length / 2.0 - small_length / 2.0;	/*Koordinatlari yenileme	*/
			x3 = length / 2.0 + small_length / 2.0;

			if((i + 1) < counter_y)
			{
				x1 = x1 - ((i+1) * (small_length / 2.0));
				x2 = x2 - ((i+1) * (small_length / 2.0));	/*Koordinatlari yenileme	*/
				x3 = x3 - ((i+1) * (small_length / 2.0));
			}


			y1 = y1 + (small_length * sqrt(3.0) / 2.0);
			y2 = y2 + (small_length * sqrt(3.0) / 2.0);	/*Koordinatlari yenileme	*/
			y3 = y3 + (small_length * sqrt(3.0) / 2.0);
			s_x1 = to_string(x1);
			s_x2 = to_string(x2);	
			s_x3 = to_string(x3);
			s_y1 = to_string(y1);	/*Stringe cevirme	*/
			s_y2 = to_string(y2);
			s_y3 = to_string(y3);

		}

		int counter_y1 = counter_y - 1;

		x1 = (length / 2.0) - (small_length / 2.0);
		y1 = small_length * sqrt(3.0) / 2.0;
		x2 = (length / 2.0) + (small_length / 2.0); /*Koordinatlari belirleme*/
		y2 = small_length * sqrt(3.0) / 2.0;
		x3 = length / 2.0;
		y3 = small_length * sqrt(3.0) ;


		s_x1 = to_string(x1);
		s_x2 = to_string(x2);
		s_x3 = to_string(x3);	/*Stringe cevirme	*/
		s_y1 = to_string(y1);
		s_y2 = to_string(y2);
		s_y3 = to_string(y3);

		/*BU DONGULERLE UCGENLERI TERS SEKILDE SVG DOSYASINA BASTIRDIM*/
		for(i = 0; i < counter_y1; ++i)
		{
			for(j = 0; j < i + 1; ++j)
			{

				total = s1 + s_tirnak + s_x1 + bosluk + s_y1 + bosluk + s_x2 + bosluk + 
					s_y2 + bosluk + s_x3 + bosluk + s_y3 + s_tirnak + s2;

				if(file.is_open())
					 file << total;

				total_triangle = total_triangle + 1;

				x1 = x1 + small_length ;
				x2 = x2 + small_length ;		/*Koordinatlari yenileme	*/
				x3 = x3 + small_length ;
				s_x1 = to_string(x1);
				s_x2 = to_string(x2);
				s_x3 = to_string(x3);
			}

			x1 = (length / 2.0) - (small_length / 2.0);
			x2 = (length / 2.0) + (small_length / 2.0);		/*Koordinatlari yenileme	*/
			x3 = length / 2.0;
			
			x1 = x1 - ((i + 1) * (small_length / 2.0));
			x2 = x2 - ((i + 1) * (small_length / 2.0));		/*Koordinatlari yenileme	*/
			x3 = x3 - ((i + 1) * (small_length / 2.0));

			y1 = y1 + (small_length * sqrt(3.0) / 2.0);
			y2 = y2 + (small_length * sqrt(3.0) / 2.0);		/*Koordinatlari yenileme	*/
			y3 = y3 + (small_length * sqrt(3.0) / 2.0);
			s_x1 = to_string(x1);
			s_x2 = to_string(x2);
			s_x3 = to_string(x3);
			s_y1 = to_string(y1);	/*Stringe cevirme	*/
			s_y2 = to_string(y2);
			s_y3 = to_string(y3);

		}
		if(total_triangle > 0)
    		cout << "I can fit at " <<  total_triangle << " small shapes into the main container. "<< endl																/*Bilgilendirme	*/
		 		 << "The empty area (red) in " << (length * length * sqrt(3.0) / 4.0) - (total_triangle * small_length * small_length * sqrt(3.0) / 4.0) << "." << endl;
		else
			cerr << "Eror!! I can not fit any triangle to triangle" << endl;	
	}	
}

void smallCircle_to_Triangle(ofstream& file ,const int length)
{	
	cout <<"Please enter the radius" << endl;
	int radius;
	cin >> radius;	

	if(radius <= 0)		/*Input kontrolu	*/
    	cerr << endl <<"Eror!!! You have entered incorrect number!!!" <<endl;

    else
    {
    	string s1 = "<circle cx=" , s_tirnak = "\"" , s2 = " cy=" ,s3 = " r=" , s4 = " fill=\"green\" stroke=\"black\"/>\n";
		string total;

    	int i , j;
    	int total_circle = 0;
		double center_x = length / 2.0;	/*Koordinatlarin belirlenmesi	*/
		double center_y = 2 * radius;	

		auto str_centerX = to_string(center_x);
		auto str_centerY = to_string(center_y);	/*Stringe cevirme	*/
		auto str_radius = to_string(radius);

		int counter_y = 2 * (length * sqrt(3.0)  / 2 ) / (3 * radius) ;	/*Fazla dongu sayisi bulma. Burda tasan kisim svg ye yazdirilmayacak	*/

		/*BU DONGULERLE DAİRELERİ KESISIM NOKTALARINA YENI DAIRE GELICEK SEKILDE SVG DOSYASINA YAZDIRDIM	*/
		for(i = 0; i < counter_y; ++i)	
		{
			for(j = 0; j < i + 1 ; ++j)
			{
					total = s1 + s_tirnak + str_centerX + s_tirnak + s2 + s_tirnak + str_centerY + s_tirnak + s3 + s_tirnak + str_radius + s_tirnak + s4;

					if(file.is_open())
						file << total;

					total_circle = total_circle + 1;

					center_x = center_x + (radius * 2);	/*Koordinatlarin yenilenmesi	*/
					str_centerX = to_string(center_x);	/*Stringe cevirme	*/
					
			}
			center_x = length / 2.0;	
			center_x = center_x - ((i + 1) * radius );	/*Koordinatlarin yenilenmesi	*/
			str_centerX = to_string(center_x);	/*Stringe cevirme	*/
			center_y = center_y + (radius * sqrt(3.0));

			if(center_y + radius <= length * sqrt(3.0) / 2.0)	/*Tasma durumunun kontrolu	*/
				str_centerY = to_string(center_y);
			else	
				break;
		}
    	if(total_circle > 0)
    		cout << "I can fit at " <<  total_circle << " small shapes into the main container. "<< endl										/*Bilgilendirme 	*/
		 		 << "The empty area (red) in " << (length * length * sqrt(3.0) / 4.0) - (total_circle * radius * radius * PI) << "." << endl;
		else
			cerr << "Eror!! I can not fit any circle to triangle" << endl;	
    }
}

void smallRectangle_to_Triangle(ofstream& file ,const int length) 
{
	double small_width, small_height;
	double temp_length = length;
	cout <<"Please enter the width" << endl;
	cin >> small_width;	
	cout <<"Please enter the height" << endl;
	cin >> small_height;

	if(small_width <= 0 || small_height <= 0)	/*Inputlarin kontrolu	*/
    	cerr << endl <<"Eror!!! You have entered incorrect number!!!" <<endl;	

    else 
    {
		string s1 = "<rect  x=" , s2 = " y=" , s3 = " width=" , s4 = " height=" ;
		string s5 = " fill=\"green\" stroke=\"white\" />\n" , s_tirnak ="\"";
		string total;

    	double start_x = small_height / sqrt(3.0) ;	/*Koordinat noktalarinin bulunmasi	*/
		double start_y = ((temp_length / 2.0) * sqrt(3.0) ) - (small_height);
		auto str_small_widht = to_string(small_width);
		auto str_small_height = to_string(small_height); 		/*Stringe cevirme	*/
		auto str_start_y = to_string(start_y);
		auto str_start_x = to_string(start_x);

		int total_rectangle = 0;
		int counter_y = (temp_length * sqrt(3.0) / 2.0 ) / small_height;	/*Dongu sayisini bulma	*/
		int counter_x = temp_length / small_width;
		temp_length = temp_length - (small_height / sqrt(3.0));

		int i,j;
		
		/*BU DONGULER ILE DIKDORTGENLERI UCGENIN ICINE TASMAYACAK SEKILDE YERLESTIRDIM	*/
		for(i = 0; i < counter_y ; ++i)
		{
			for(j = 0; j < counter_x ; ++j)
			{
				if(start_x + small_width <= temp_length)
				{
					total = s1 + s_tirnak + str_start_x + s_tirnak + s2 + s_tirnak + str_start_y +
					 	s_tirnak + s3 + s_tirnak + str_small_widht + s_tirnak + s4 + s_tirnak +
					 	str_small_height + s_tirnak + s5;

					if(file.is_open())
					 	file << total;
					start_x = start_x + small_width;	/*Koordinatlarin yenilenmesi	*/
					str_start_x = to_string(start_x);	/*Stringe cevirme	*/
					total_rectangle = total_rectangle + 1;
				}		
			}

			temp_length = temp_length - (small_height / sqrt(3.0));	/*Ucgen icicn gecici uzunluklarin bulunması	*/
			counter_x = temp_length / small_width;		/*Yeni dongu sayisi	*/
			
			start_x = small_height / sqrt(3.0);
			start_x = start_x + ((i + 1) * (small_height / sqrt(3.0)) );	/*Koordinatlarin yenilenmesi	*/
			start_y = start_y - small_height;
			str_start_y = to_string(start_y);
			str_start_x = to_string(start_x);	/*Stringe cevirme	*/

		}
		if(total_rectangle > 0)
    		cout << "I can fit at " <<  total_rectangle << " small shapes into the main container. "<< endl												/*Bilgilendirme 	*/
		 		 << "The empty area (red) in " << (length * length * sqrt(3.0) / 4.0) - (total_rectangle * small_width * small_height) << "." << endl;
		else
			cerr << "Eror!! I can not fit any rectangle to triangle" << endl;	
    }
}

void small_Circle_to_Circle(ofstream& file ,const int radius)	
{
	cout <<"Please enter the radius" << endl;
	double small_radius;
	cin >> small_radius;	

	if(small_radius <= 0)	/*Input kontrolu	*/
    	cerr << endl <<"Eror!!! You have entered incorrect number!!!" <<endl;

    else
    {
    	int i , j ,total_circle = 0;

		string s1 = "<circle cx=" , s_tirnak = "\"" , s2 = " cy=" ,s3 = " r=" , s4 = " fill=\"green\" stroke=\"black\"/>\n";
		string total;

		double center_x = small_radius ;
		double center_y = small_radius;	/*Koordinatlarin bulunmasi	*/

		auto str_centerX = to_string(center_x);
		auto str_centerY = to_string(center_y);	/*Stringe cevirme	*/
		auto str_radius = to_string(small_radius);

		int counter_y = (4 * radius) / ((small_radius + small_radius * sqrt(3.0)));	/*Dongu sayisni bulma. Fazla bulunup tasan kisim konulmaz	*/
		int counter_x = 2 * radius;

		/*BU DONGULERDE DAIRELERIN ICINE DAIRELERI IKI NOKTA ARASINDAKI UZAKLIK YARICAPTAN KUCUK OLMA KOSULU ILE SVG DOSYASINA YERLESTIRDIM*/
		for(i = 0; i < counter_y; ++i)
		{
			for(j = 0; j < counter_x; ++j)
			{	
				if(sqrt(((radius - center_x) * (radius - center_x)) + ((radius - center_y) * (radius - center_y)) ) <= (radius - small_radius) )	/*Iki nokta arası uzaklık formulu	*/
				{
					total = s1 + s_tirnak + str_centerX + s_tirnak + s2 + s_tirnak + str_centerY + s_tirnak + s3 + s_tirnak + str_radius + s_tirnak + s4;

					if(file.is_open())
						file << total;

					total_circle = total_circle + 1;
				}							
				center_x = center_x + 2 * small_radius;	/*Koordinatlari yenileme	*/
				str_centerX = to_string(center_x );		/*Stringe cevirme	*/		
			}

				if(i % 2 == 1)
					center_x = small_radius;	/*Koordinatlari yenileme	*/
				
				else if(i % 2 == 0)	
					center_x =  2 * small_radius;	/*Koordinatlari yenileme	*/
			
				center_y = center_y + small_radius * sqrt(3.0);
				str_centerX = to_string(center_x );	/*Stringe cevirme	*/	
				str_centerY = to_string(center_y );
		}
		if(total_circle > 0)
    		cout << "I can fit at " <<  total_circle << " small shapes into the main container. "<< endl										/*Bilgilendirme	*/
		 		 << "The empty area (red) in " << (PI * radius * radius) - (total_circle * small_radius * small_radius * PI) << "." << endl;
		else
			cerr << "Eror!! I can not fit any circle to circle" << endl;

    }
}

void small_Triangle_to_Circle(ofstream& file ,const int radius)
{
	cout <<"Please enter the length" << endl;

	double small_length;
	cin >> small_length;

	if(small_length <= 0)	/*Input kontrolu	*/
    	cerr << endl <<"Eror!!! You have entered incorrect number!!!" <<endl;
    else
    {
		string s1 = "\n<polygon points=" , s2 =" fill=\"green\"  stroke=\"white\" />" , s_tirnak = "\"" , bosluk = " " ;
		string total, s_x1, s_x2, s_x3, s_y1, s_y2, s_y3;   	
    	
    	int i ,j,total_triangle = 0;
		double cordinate_x = 0.0;
		double cordinate_y = 0.0;	/*Koordinatlarin bulunmasi	*/
		double cordinate_x2, cordinate_x3,cordinate_y2,cordinate_y3;

		/*BU DONGULERDE UCGENİN BUTUN KOSELERI CEMBER DENKLEMİ KULLANILARAK DAIRENIN ICINDE MI BULUNUR VE ONA GORE UCGENLER DUZ SEKILDE BASTIRILIR. (REFERANS cordinate_x ve cordinate_y NOKTALARINA GORE ISLEM YAPILIR)*/
		for(i = 0; i <= (2 * radius) ; ++i)
		{
			for(j = 0; j <= (2 *radius); ++j)
			{	
				/*BU DONGULERDE UCGENİN BUTUN KOSELERI CEMBER DENKLEMİ KULLANILARAK DAIRENIN ICINDE MI BULUNUR VE ONA GORE UCGENLER DUZ SEKILDE BASTIRILIR*/
				if( ( ( (cordinate_x - radius ) * (cordinate_x - radius) + (cordinate_y - radius ) * (cordinate_y - radius ) ) <= (radius * radius) )&&
					( ( (cordinate_x + (small_length / 2.0 ) - radius ) * (cordinate_x + (small_length / 2.0 ) - radius) + (cordinate_y - (small_length * sqrt(3.0) / 2.0) - radius) * (cordinate_y - (small_length * sqrt(3.0) / 2.0) - radius)) <= (radius * radius) ) &&
					( ( (cordinate_x + small_length - radius) * (cordinate_x + small_length - radius) + ((cordinate_y - radius ) * (cordinate_y - radius )) <= (radius * radius)))		
				   ) 
				{
		
	 				s_x1 = to_string(cordinate_x);
					s_x2 = to_string(cordinate_x + (small_length / 2.0));
					s_x3 = to_string(cordinate_x + small_length);		/*koordinatlari bulma ve stringe cevirme	*/
					s_y1 = to_string(cordinate_y);
					s_y2 = to_string(cordinate_y  - (small_length * sqrt(3.0) / 2.0));
					s_y3 = to_string(cordinate_y);
					
					total = s1 + s_tirnak + s_x1 + bosluk + s_y1 + bosluk + s_x2 + bosluk + 
							s_y2 + bosluk + s_x3 + bosluk + s_y3 + s_tirnak + s2;

					if(file.is_open())
					 	file << total;

					 cordinate_x = cordinate_x + small_length;	/*Koordinat icerdeyse ucgen uzunlugu kadar artirma	*/
					 total_triangle = total_triangle + 1;

				}
				cordinate_x = cordinate_x + 1;	/*Koordinat disardaysa ucgen 1 artirma	*/
				
			}
			cordinate_x = 0.0;				/*Koordinatlarin guncellenmesi	*/
			cordinate_y = cordinate_y + (small_length * sqrt(3.0) / 2);
		}

		cordinate_x = 0.0;
		cordinate_y = 0.0;

		/*BU DONGULERDE UCGENİN BUTUN KOSELERI CEMBER DENKLEMİ KULLANILARAK DAIRENIN ICINDE MI BULUNUR VE ONA GORE UCGENLER TERS SEKILDE BASTIRILIR. (REFERANS cordinate_x ve cordinate_y NOKTALARINA GORE ISLEM YAPILIR)*/
		for(i = 0; i <= (2 * radius) ; ++i)
		{
			for(j = 0; j <= (2 *radius); ++j)
			{	
				/*BU DONGULERDE UCGENİN BUTUN KOSELERI CEMBER DENKLEMİ KULLANILARAK DAIRENIN ICINDE MI BULUNUR VE ONA GORE UCGENLER DUZ SEKILDE BASTIRILIR*/
				if( ( ( (cordinate_x + 3 * small_length / 2.0 - radius) * (cordinate_x + 3 * small_length / 2.0 - radius) + (cordinate_y - small_length * sqrt(3.0) / 2.0 - radius) *(cordinate_y - small_length * sqrt(3.0) / 2.0 - radius) ) <= (radius * radius))&&
					( ( (cordinate_x - radius ) * (cordinate_x - radius) + (cordinate_y - radius ) * (cordinate_y - radius ) ) <= (radius * radius) )&&
					( ( (cordinate_x + (small_length / 2.0 ) - radius ) * (cordinate_x + (small_length / 2.0 ) - radius) + (cordinate_y - (small_length * sqrt(3.0) / 2.0) - radius) * (cordinate_y - (small_length * sqrt(3.0) / 2.0) - radius)) <= (radius * radius) ) &&
					( ( (cordinate_x + small_length - radius) * (cordinate_x + small_length - radius) + ((cordinate_y - radius ) * (cordinate_y - radius )) <= (radius * radius)))	
				   	
				   ) 
				{
					
					s_x1 = to_string(cordinate_x + (small_length / 2.0));
					s_x2 = to_string(cordinate_x + small_length + (small_length / 2.0 ));
					s_x3 = to_string(cordinate_x + small_length);						/*koordinatlari bulma ve stringe cevirme	*/
					s_y1 = to_string(cordinate_y - (small_length * sqrt(3.0) / 2.0));
					s_y2 = to_string(cordinate_y - (small_length * sqrt(3.0) / 2.0)) ;
					s_y3 = to_string(cordinate_y);
					
					total = s1 + s_tirnak + s_x1 + bosluk + s_y1 + bosluk + s_x2 + bosluk + 
							s_y2 + bosluk + s_x3 + bosluk + s_y3 + s_tirnak + s2;

					if(file.is_open())
					 	file << total;

					 cordinate_x = cordinate_x + small_length;	/*Koordinat icerdeyse ucgen uzunlugu kadar artirma	*/
					 total_triangle = total_triangle + 1;

				}
				cordinate_x = cordinate_x + 1;		/*Koordinat disardaysa ucgen 1 artirma	*/
				
			}
			cordinate_x = 0.0;
			cordinate_y = cordinate_y + (small_length * sqrt(3.0) / 2);	/*Koordinatlarin guncellenmesi	*/
		}
    	if(total_triangle > 0)
    		cout << "I can fit at " <<  total_triangle << " small shapes into the main container. "<< endl					/*Bilgilendirme	*/
		 		 << "The empty area (red) in " << (PI * radius * radius) - (total_triangle * small_length * small_length * sqrt(3.0) / 4.0) << "." << endl;
		else
			cerr << "Eror!! I can not fit any triangle to circle" << endl;
    }
}

void small_Rectangle_to_Circle(ofstream& file ,const int radius)
{
	double small_width, small_height;
	double start_x = 0 , start_y = 0;
	cout <<"Please enter the width" << endl;	
	cin >> small_width;	
	cout <<"Please enter the height" << endl;
	cin >> small_height;	

	if(small_width <= 0 || small_height <= 0)	/*Inputlarin kontrolu	*/
    	cerr << endl <<"Eror!!! You have entered incorrect number!!!" <<endl;	
    else
    {
		string s1 = "<rect  x=" , s2 = " y=" , s3 = " width=" , s4 = " height=" ;
		string s5 = " fill=\"green\" stroke=\"white\" />\n" , s_tirnak ="\"";
		string total , str_start_x ,str_start_y;

    	int i ,j ,total_rectangle = 0;
		double cordinate_x = 0.0;
		double cordinate_y = 0.0;	/*Koordinatlarin belirlenmesi	*/

		auto str_small_widht = to_string(small_width);
		auto str_small_height = to_string(small_height); 	/*Stringe cevrilmesi	*/

		/*BU DONGULERDE dıkdortgenın BUTUN KOSELERI CEMBER DENKLEMİ KULLANILARAK DAIRENIN ICINDE MI BULUNUR VE ONA GORE DIKDORTGENLER BASTIRILIR. (REFERANS cordinate_x ve cordinate_y NOKTALARINA GORE ISLEM YAPILIR)*/
		for(i = 0; i < (2 * radius); ++i )
		{
			for(j = 0; j < (2 * radius); ++j)
			{
				/*BU DONGULERDE dıkdortgenın BUTUN KOSELERI CEMBER DENKLEMİ KULLANILARAK DAIRENIN ICINDE MI BULUNUR VE ONA GORE DIKDORTGENLER BASTIRILIR. */
				if( ( ( (cordinate_x - radius ) * (cordinate_x - radius) + (cordinate_y - radius ) * (cordinate_y - radius ) ) <= (radius * radius) )&&
					( ( (cordinate_x - radius ) * (cordinate_x - radius) + (cordinate_y + small_height - radius) * (cordinate_y + small_height - radius)) <= (radius * radius) ) &&
					( ( (cordinate_x + small_width - radius) * (cordinate_x + small_width - radius) + ((cordinate_y - radius ) * (cordinate_y - radius )) <= (radius * radius)))&&	
					( ( (cordinate_x + small_width - radius) * (cordinate_x + small_width - radius) + ((cordinate_y + small_height - radius ) * (cordinate_y + small_height - radius )) <= (radius * radius)))	
				   ) 
				{
					str_start_x = to_string(cordinate_x);
					str_start_y = to_string(cordinate_y);	/*Stringe cevirme*/

					total = s1 + s_tirnak + str_start_x + s_tirnak + s2 + s_tirnak + str_start_y +
					 		s_tirnak + s3 + s_tirnak + str_small_widht + s_tirnak + s4 + s_tirnak +
					 		str_small_height + s_tirnak + s5;

					 if(file.is_open())
					 	file << total;
					 total_rectangle = total_rectangle + 1;	
				
					 cordinate_x = cordinate_x + small_width;	/*Dikdortgen sigarsa x koordinati widht kadar arttirma 	*/

				}

				cordinate_x = cordinate_x + 1;			/*Dikdortgen sigmazsa 1 arttirma 	*/		
			}

			cordinate_x = 0.0;
			cordinate_y = cordinate_y + small_height;	/*Korrdinatlarin guncellenmesi	*/
		}   
		if(total_rectangle > 0)
    		cout << "I can fit at " <<  total_rectangle << " small shapes into the main container. "<< endl									/*Bilgilendirme	*/
		 		 << "The empty area (red) in " << (PI * radius * radius) - (total_rectangle * small_width * small_height) << "." << endl;
		else
			cerr << "Eror!! I can not fit any rectangle to circle" << endl;
    }
}