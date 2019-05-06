all: exe

exe:
	g++ -std=c++0x -c Rectangle.cpp
	g++ -std=c++0x -c Triangle.cpp
	g++ -std=c++0x -c Circle.cpp
	g++ -std=c++0x -c ComposedShape.cpp
	g++ -std=c++0x -c 151044058_main.cpp
	g++ -std=c++0x -c Polygon.cpp
	g++ -std=c++0x -c Polyline.cpp

	g++ -o exe Rectangle.o Triangle.o Circle.o ComposedShape.o Polygon.o Polyline.o 151044058_main.o

clean:
	rm *.o exe
