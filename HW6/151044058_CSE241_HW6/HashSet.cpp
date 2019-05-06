#include "HashSet.h"

namespace HW6_151044058
{
	template<typename E, typename C_Collection>
	HashSet<E, C_Collection> :: HashSet()
	{
		//Empty
	}

	template<typename E, typename C_Collection>
	HashSet<E, C_Collection> :: HashSet(C_Collection temp_collection)
	{
		HS = temp_collection;	// Gelen collectionu benim collectionuma atar		
	}

	template<typename E, typename C_Collection>
	bool HashSet<E, C_Collection> :: contains(E e)
	{
		for(auto it = HS.begin(); it != HS.end(); ++it) // Collectionu basindan sonuna doner e' yi bulursa true bulamazsa false return eder
		{
			if(*it == e)
				return true;
		}
		return false;
	}

	template<typename E, typename C_Collection>
	void HashSet<E, C_Collection> :: add(E e)
	{
		auto it2 = HS.end();
		if(!(contains(e))) // contains fonksiyonu cagirilir, bu fonksiyon benim collectionum da e var mi diye bakar, eger yoksa e yi ekler 
			it2 = HS.insert(it2,e); // Ekleme islemi
		
		for(auto it = HS.begin(); it != HS.end(); ++it)
			cout << *it  << " ";
	
		cout << endl;		
	}

	template<typename E, typename C_Collection>
	bool HashSet<E, C_Collection> :: isEmpty() //Colection bos ise false return eder
	{
		if(HS.empty())
			return true;
		else
			return false;	
	}

	template<typename E, typename C_Collection>
	int HashSet<E, C_Collection> :: size()
	{
		int size_counter = 0;
		for(auto it = HS.begin(); it != HS.end(); ++it)	//Collectionu basindan sonuna doner size_counteri arttirir ve return eder			
			size_counter +=1;

		return size_counter;	
	}

	template<typename E, typename C_Collection>
	void HashSet<E, C_Collection> :: remove(E e) //Belirtilen elemani collectionda bulursa siler
	{
		cout << "Collectionun "<< e << " cikartilmamis hali : " << endl;
		for(auto it = HS.begin(); it != HS.end(); ++it)
			cout << *it << " ";
		
		for(auto it = HS.begin(); it != HS.end(); ++it)
		{
			if(*it == e)
			{
				it = HS.erase(it);
				it--;
			}

		}
		cout << endl;
		cout << "Collectionun " << e <<" cikartilmis hali : " << endl;
		for(auto it = HS.begin(); it != HS.end(); ++it)
			cout << *it << " ";

		cout << endl;
	}

	template<typename E, typename C_Collection>
	void HashSet<E, C_Collection> :: clear()
	{	
		cout << "Collectionun clear fonksiyonundan onceki hali : " << endl;
		for(auto it = HS.begin(); it != HS.end(); ++it)
			cout << *it << " ";

		HS.clear();

		cout << endl;
		cout << "Collectionun clear fonksiyonundan sonraki hali : " << endl;
		for(auto it = HS.begin(); it != HS.end(); ++it)
			cout << *it << " ";
		cout << "Collectionun size' i : " << HS.size() << endl;
		
	}

	template<typename E, typename C_Collection>
	void HashSet<E, C_Collection> :: addAll(C_Collection c)
	{	
		if(c.size() <= 0 )
			throw HashSet_Error();

		cout << "Gelen collectionun benim collectionuma eklenmis hali :" << endl;
		auto it = c.begin(); 
		auto it2 = HS.end();

		for(int i = 0; i < c.size(); ++i) //Gelen collectionun size' i kadar donen dongu ile o eleman bendeki collectionda yoksa ekleme yapiyorum varsa eklemiyorum
		{
			if(!contains(*it))
			{
				it2 = HS.insert(it2,*it);
				it++;
				it2++;
			}
			else
				it++;
		}

		for(auto it = HS.begin(); it != HS.end(); ++it)
			cout << *it << " ";
		cout << endl;	
	}

	template<typename E, typename C_Collection>
	bool HashSet<E, C_Collection> :: containsAll(C_Collection c)
	{
		if(c.size() <= 0 )
			throw HashSet_Error();

		int control = 0;
		for(auto it = HS.begin(); it != HS.end(); ++it)
		{
			for(auto it2 = c.begin(); it2 != c.end(); ++it2)
			{
				if(*it == *it2)
					control =1;
			}
			if(control != 1)
				return false;
			control = 0;
		}
		return true;
	}

	template<typename E, typename C_Collection>
	void  HashSet<E, C_Collection> :: removeAll(C_Collection c) //Benim collectionumdan gelen collectiondaki ayni olanlari cikartir farklilar kalir
	{
		if(c.size() <= 0 )
			throw HashSet_Error();

		for(auto it = HS.begin(); it != HS.end(); ++it)
		{
			for(auto it2 = c.begin(); it2 != c.end(); ++it2)
			{
				if(*it == *it2)
				{
					it = HS.erase(it);
					it = HS.begin();
				}
			}					
		}
		cout << "Benim collectionumda kalan elemanlar : " << endl;
		for(auto it = HS.begin(); it != HS.end(); ++it)
			cout << *it << " ";
		cout << endl;				
	}

	template<typename E, typename C_Collection>
	void HashSet<E, C_Collection> :: retainAll(C_Collection c) //Benim collectionum ile bana gelen collectiondaki ayni elemanlari benim collectionumda tutar digerlerini siler.
	{
		if(c.size() <= 0 )
			throw HashSet_Error();
		
		int control = 0;
		for(auto it = HS.begin(); it != HS.end(); ++it)
		{
			for(auto it2 = c.begin(); it2 != c.end(); ++it2)
			{
				if(*it == *it2)
					control = -1; 

			}
			if(control != -1)
			{
				it = HS.erase(it);
				it = HS.begin();
			}
			control = 0;
		}

		cout << "Benim collectionumda kalan elemanlar : " << endl;
		for(auto it = HS.begin(); it != HS.end(); ++it)
			cout << *it << " ";
		cout << endl;
	}
}