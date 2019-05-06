all: exe

exe:
	g++ -std=c++0x -c Collection.cpp
	g++ -std=c++0x -c Set.cpp
	g++ -std=c++0x -c List.cpp
	g++ -std=c++0x -c Queue.cpp
	g++ -std=c++0x -c HashSet.cpp
	g++ -std=c++0x -c ArrayList.cpp
	g++ -std=c++0x -c LinkedList.cpp
	g++ -std=c++0x -c Iterator.cpp
	g++ -std=c++0x -c 151044058_main.cpp

	g++ -o exe Collection.o Set.o List.o Queue.o HashSet.o ArrayList.o LinkedList.o Iterator.o 151044058_main.o

clean:
	rm *.o exe
