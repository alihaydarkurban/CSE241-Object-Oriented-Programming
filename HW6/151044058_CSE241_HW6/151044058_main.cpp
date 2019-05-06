#include "Collection.h"
#include "Set.h"
#include "List.h"
#include "Queue.h"
#include "HashSet.h"
#include "HashSet.cpp"
#include "ArrayList.h"
#include "ArrayList.cpp"
#include "LinkedList.h"
#include "LinkedList.cpp"
#include "Iterator.h"
#include "Iterator.cpp"

using namespace std;
using namespace HW6_151044058;

void driver();

int main()
{ 	
	driver();
	return 0;
}

void driver()
{
	try
	{
		//HASHSET

		cout << "HASHSET VECTOR<INT> ICIN" << endl;
		vector<int> vector_deneme1; // Vektor olusturma

		HashSet<int, vector<int>> hashset_deneme1(vector_deneme1); //Hashset in template paremetrelerini verip olusturdugum vectoru contructora gonderme

		cout << "add Fonksiyonu" << endl;
		hashset_deneme1.add(3);
		hashset_deneme1.add(6); // add fonksiyonunun islemleri
		hashset_deneme1.add(9);
		hashset_deneme1.add(12);

		int e = 5;

		// collectionum e iceriyor mu testi
		if(hashset_deneme1.contains(e) == true)
			cout << "Belirtielen eleman " << e <<" collectionum da var!" << endl;
		else if(hashset_deneme1.contains(e) ==  false)
			cout << "Belirtielen eleman " << e <<" collectionum da yok!" << endl;

		// collectionun boslugunun testi
		if(hashset_deneme1.isEmpty() == true)
			cout << "Collection bos!!" << endl;
		else if(hashset_deneme1.isEmpty() == false)
			cout << "Collection bos degil!!" << endl;

		int size1 = 0;

		size1 = hashset_deneme1.size(); //size fonksiyonunun testi

		cout << "Belirtielen collectionun size' i : " << size1 << endl;

		int remove1 = 6; // collectiondan cikartmak istedigim eleman

		hashset_deneme1.remove(remove1); //remove fonksiyonunun testi

		vector<int> vector_deneme2 = {10,20,3}; // yeni vektor olusturma

		hashset_deneme1.addAll(vector_deneme2); //olusturdugum vektoru addAll ile gonderip test etme


		//constainsAll fonksiyonun testi
		if(hashset_deneme1.containsAll(vector_deneme2) == true)
			cout << "Benim collectionumdaki her eleman gelen collectionda bulunuyor" << endl;
		else if(hashset_deneme1.containsAll(vector_deneme2) ==  false)
			cout << "Benim collectionumdaki her eleman gelen collectionda bulunmuyor!!" << endl;

		//yeni vektor olusturma
		vector<int> vector_deneme3 = {8,20,9};

		//removeAll fonksiyonunun testi
		cout << "removeAll Fonksiyonu : " << endl;
		hashset_deneme1.removeAll(vector_deneme3);

		//retainAll fonsiyonunun testi 
		cout << "retainAll Fonksiyonu : " << endl;
		hashset_deneme1.retainAll(vector_deneme2);

		hashset_deneme1.clear(); //clear fonksiyonunun testi

	




		// ASAGIDAKI KISIMLARDAKI ISLEMLER USTTEKILER ILE AYNIDIR

		cout << "\nHASHSET SET<STRING> ICIN" << endl;

		set<string> set_deneme1;

		HashSet<string, set<string>> hashset_deneme2(set_deneme1);

		cout << "add Fonksiyonu" << endl;
		hashset_deneme2.add("3");
		hashset_deneme2.add("6");
		hashset_deneme2.add("9");
		hashset_deneme2.add("12");

		string e1 = "5";

		if(hashset_deneme2.contains(e1) == true)
			cout << "Belirtielen eleman " << e1 <<" collectionum da var!" << endl;
		else if(hashset_deneme2.contains(e1) ==  false)
			cout << "Belirtielen eleman " << e1 <<" collectionum da yok!" << endl;

		if(hashset_deneme2.isEmpty() == true)
			cout << "Collection bos!!" << endl;
		else if(hashset_deneme2.isEmpty() == false)
			cout << "Collection bos degil!!" << endl;

		int size2 = 0;

		size2 = hashset_deneme2.size();

		cout << "Belirtielen collectionun size' i : " << size2 << endl;

		string remove2 = "6";

		hashset_deneme2.remove(remove2);

		set<string> set_deneme2 = {"10","20","3"};

		hashset_deneme2.addAll(set_deneme2);


		if(hashset_deneme2.containsAll(set_deneme2) == true)
			cout << "Benim collectionumdaki her eleman gelen collectionda bulunuyor" << endl;
		else if(hashset_deneme2.containsAll(set_deneme2) ==  false)
			cout << "Benim collectionumdaki her eleman gelen collectionda bulunmuyor!!" << endl;

		set<string> set_deneme3 = {"8","20","9"};

		cout << "removeAll Fonksiyonu : " << endl;
		hashset_deneme2.removeAll(set_deneme3);

		cout << "retainAll Fonksiyonu : " << endl;
		hashset_deneme2.retainAll(set_deneme2);

		hashset_deneme2.clear();





		//ARRAYLIST

		cout << "\nARRAYLIST LIST<INT> ICIN" << endl;
		list<int> list_deneme1;

		ArrayList<int, list<int>> arraylist_deneme1(list_deneme1);

		cout << "add Fonksiyonu" << endl;
		arraylist_deneme1.add(1);
		arraylist_deneme1.add(2);
		arraylist_deneme1.add(3);
		arraylist_deneme1.add(3);
		arraylist_deneme1.add(4);
		arraylist_deneme1.add(4);

		int e3 = 1;

		if(arraylist_deneme1.contains(e3) == true)
			cout << "Belirtielen eleman " << e3 <<" collectionum da var!" << endl;
		else if(arraylist_deneme1.contains(e3) ==  false)
			cout << "Belirtielen eleman " << e3 <<" collectionum da yok!" << endl;

		if(arraylist_deneme1.isEmpty() == true)
			cout << "Collection bos!!" << endl;
		else if(arraylist_deneme1.isEmpty() == false)
			cout << "Collection bos degil!!" << endl;

		int size3 = 0;

		size3 = arraylist_deneme1.size();

		cout << "Belirtielen collectionun size' i : " << size3 << endl;

		int remove3 = 1;

		arraylist_deneme1.remove(remove3);

		list<int> list_deneme2 = {10,20,3};

		arraylist_deneme1.addAll(list_deneme2);


		if(arraylist_deneme1.containsAll(list_deneme2) == true)
			cout << "Benim collectionumdaki her eleman gelen collectionda bulunuyor" << endl;
		else if(arraylist_deneme1.containsAll(list_deneme2) ==  false)
			cout << "Benim collectionumdaki her eleman gelen collectionda bulunmuyor!!" << endl;

		list<int> list_deneme3 = {8,20,9};

		cout << "removeAll Fonksiyonu : " << endl;
		arraylist_deneme1.removeAll(list_deneme3);

		cout << "retainAll Fonksiyonu : " << endl;
		arraylist_deneme1.retainAll(list_deneme2);

		arraylist_deneme1.clear();





		cout << "\nARRAYLIST SET<STRING> ICIN" << endl;
		set<string> set_deneme4;

		ArrayList<string, set<string>> arraylist_deneme2(set_deneme4);

		cout << "add Fonksiyonu" << endl;
		arraylist_deneme2.add("ali");
		arraylist_deneme2.add("haydar");
		arraylist_deneme2.add("kurban");
		arraylist_deneme2.add("C++");
		arraylist_deneme2.add("C");

		string e5 = "C";

		if(arraylist_deneme2.contains(e5) == true)
			cout << "Belirtielen eleman " << e5 <<" collectionum da var!" << endl;
		else if(arraylist_deneme2.contains(e5) ==  false)
			cout << "Belirtielen eleman " << e5 <<" collectionum da yok!" << endl;

		if(arraylist_deneme2.isEmpty() == true)
			cout << "Collection bos!!" << endl;
		else if(arraylist_deneme2.isEmpty() == false)
			cout << "Collection bos degil!!" << endl;

		int size5 = 0;

		size5 = arraylist_deneme2.size();

		cout << "Belirtielen collectionun size' i : " << size5 << endl;

		string remove5 = "C";

		arraylist_deneme2.remove(remove5);

		set<string> set_deneme5 = {"10","20","3","GTU"};

		arraylist_deneme2.addAll(set_deneme5);


		if(arraylist_deneme2.containsAll(set_deneme5) == true)
			cout << "Benim collectionumdaki her eleman gelen collectionda bulunuyor" << endl;
		else if(arraylist_deneme2.containsAll(set_deneme5) ==  false)
			cout << "Benim collectionumdaki her eleman gelen collectionda bulunmuyor!!" << endl;

		set<string> set_deneme6 = {"8","20","9","ali","C++"};

		cout << "removeAll Fonksiyonu : " << endl;
		arraylist_deneme2.removeAll(set_deneme6);

		cout << "retainAll Fonksiyonu : " << endl;
		arraylist_deneme2.retainAll(set_deneme6);

		arraylist_deneme2.clear();






		//LINKEDLIST

		cout << "\nLINKEDLIST VECTOR<STRING> ICIN" << endl;
		vector<string> vector_deneme4;

		LinkedList<string, vector<string>> linkedlit_deneme1(vector_deneme4);

		cout << "add Fonksiyonu" << endl;
		linkedlit_deneme1.add("3.0");
		linkedlit_deneme1.add("6.0");
		linkedlit_deneme1.add("9.0");
		linkedlit_deneme1.add("12.0");


		string e4 = "3.0";

		if(linkedlit_deneme1.contains(e4) == true)
			cout << "Belirtielen eleman " << e4 <<" collectionum da var!" << endl;
		else if(linkedlit_deneme1.contains(e4) ==  false)
			cout << "Belirtielen eleman " << e4 <<" collectionum da yok!" << endl;

		if(linkedlit_deneme1.isEmpty() == true)
			cout << "Collection bos!!" << endl;
		else if(linkedlit_deneme1.isEmpty() == false)
			cout << "Collection bos degil!!" << endl;

		int size4 = 0;

		size4 = linkedlit_deneme1.size();

		cout << "Belirtielen collectionun size' i : " << size4 << endl;

		string remove4 = "6.0";

		linkedlit_deneme1.remove(remove4);

		vector<string> vector_deneme5 = {"10.0","20.0","3.0"};

		linkedlit_deneme1.addAll(vector_deneme5);


		if(linkedlit_deneme1.containsAll(vector_deneme5) == true)
			cout << "Benim collectionumdaki her eleman gelen collectionda bulunuyor" << endl;
		else if(linkedlit_deneme1.containsAll(vector_deneme5) ==  false)
			cout << "Benim collectionumdaki her eleman gelen collectionda bulunmuyor!!" << endl;

		vector<string> vector_deneme6 = {"8.0","20.0","9.0"};

		cout << "removeAll Fonksiyonu : " << endl;
		linkedlit_deneme1.removeAll(vector_deneme6);

		cout << "retainAll Fonksiyonu : " << endl;
		linkedlit_deneme1.retainAll(vector_deneme5);

		linkedlit_deneme1.clear();

		cout << "offer Fonksiyonu" << endl;
		linkedlit_deneme1.offer("4.0");




		cout << "\nLINKEDLIST LIST<STRING> ICIN" << endl;
		list<string> linkedlit_list1;

		LinkedList<string, list<string>> linkedlit_deneme2(linkedlit_list1);

		cout << "add Fonksiyonu" << endl;
		linkedlit_deneme2.add("ali");
		linkedlit_deneme2.add("haydar");
		linkedlit_deneme2.add("kurban");
		linkedlit_deneme2.add("C++");
		linkedlit_deneme2.add("C");

		string e7 = "C";

		if(linkedlit_deneme2.contains(e7) == true)
			cout << "Belirtielen eleman " << e7 <<" collectionum da var!" << endl;
		else if(linkedlit_deneme2.contains(e7) ==  false)
			cout << "Belirtielen eleman " << e7 <<" collectionum da yok!" << endl;

		if(linkedlit_deneme2.isEmpty() == true)
			cout << "Collection bos!!" << endl;
		else if(linkedlit_deneme2.isEmpty() == false)
			cout << "Collection bos degil!!" << endl;

		int size6 = 0;

		size6 = linkedlit_deneme2.size();

		cout << "Belirtielen collectionun size' i : " << size6 << endl;

		string remove7 = "C";

		linkedlit_deneme2.remove(remove7);

		list<string> linkedlit_list2 = {"10","20","3","GTU"};

		linkedlit_deneme2.addAll(linkedlit_list2);


		if(linkedlit_deneme2.containsAll(linkedlit_list2) == true)
			cout << "Benim collectionumdaki her eleman gelen collectionda bulunuyor" << endl;
		else if(linkedlit_deneme2.containsAll(linkedlit_list2) ==  false)
			cout << "Benim collectionumdaki her eleman gelen collectionda bulunmuyor!!" << endl;

		list<string> linkedlit_list3 = {"haydar","kurban","C++"};

		cout << "removeAll Fonksiyonu : " << endl;
		linkedlit_deneme2.removeAll(linkedlit_list3);

		cout << "retainAll Fonksiyonu : " << endl;
		linkedlit_deneme2.retainAll(linkedlit_list3);

		linkedlit_deneme2.clear();


		cout << "offer Fonksiyonu" << endl;
		linkedlit_deneme2.offer("OFFER");








		cout << "\nITERATOR CLASSININ TESTLERI" << endl;
		cout << "***************************" << endl;

		cout << "Iterator<int, list<int>>" << endl;
		list<int> iterator_list1 = {10,20,30,40};

		Iterator<int, list<int>> iterator_deneme1(iterator_list1);

		while(iterator_deneme1.hasNext())
		{
			cout << *iterator_deneme1.get_it_pointer() << " ";
			iterator_deneme1.next();
		}
		cout << endl;


		cout << "Iterator<string, list<string>>" << endl;
		list<string> iterator_list2 = {"ALI","HAYDAR","KURBAN"};

		Iterator<string, list<string>> iterator_deneme2(iterator_list2);

		while(iterator_deneme2.hasNext())
		{
			cout << *iterator_deneme2.get_it_pointer() << " ";
			iterator_deneme2.next();
		}
		cout << endl;


		cout << "Iterator<int, vector<int>>" << endl;	
		vector<int> iterator_vector1 = {50,60,70,80};

		Iterator<int, vector<int>> iterator_deneme3(iterator_vector1);

		while(iterator_deneme3.hasNext())
		{
			cout << *iterator_deneme3.get_it_pointer() << " ";
			iterator_deneme3.next();
		}
		cout << endl;


		cout << "Iterator<int, set<int>>" << endl;
		set<int> iterator_set1 = {90,100};

		Iterator<int, set<int>> iterator_deneme4(iterator_set1);

		while(iterator_deneme4.hasNext())
		{
			cout << *iterator_deneme4.get_it_pointer() << " ";
			iterator_deneme4.next();
		}
		cout << endl;



	}

	catch(HashSet_Error)
	{
		cerr << "HashSet icin gonderdigin collection bos!!!" << endl;
		cerr << "Program sonlandiriliyor" << endl;
		exit(1);
	}
	catch(ArrayList_Error)
	{
		cerr << "ArrayList icin gonderdigin collection bos!!!" << endl;
		cerr << "Program sonlandiriliyor" << endl;
		exit(1);
	}
	catch(LinkedList_Error)
	{
		cerr << "LinkedList icin gonderdigin collection bos!!!" << endl;
		cerr << "Program sonlandiriliyor" << endl;
		exit(1);
	}

}