#include "ArrayList.h"

namespace HW6_151044058
{
	template<typename E, typename C_Collection>
	ArrayList<E, C_Collection> :: ArrayList()
	{
		//cout << "No parameter" << endl;
	}

	template<typename E, typename C_Collection>
	ArrayList<E, C_Collection> :: ArrayList(C_Collection temp_collection)
	{
		AL = temp_collection;			
	}

	template<typename E, typename C_Collection>
	bool ArrayList<E, C_Collection> :: isEmpty()
	{
		if(AL.empty())
			return true;
		else
			return false;	
	}

	template<typename E, typename C_Collection>
	int ArrayList<E, C_Collection> :: size()
	{
		int size_counter = 0;
		for(auto it = AL.begin(); it != AL.end(); ++it)					
			size_counter +=1;

		return size_counter;
		
	}

	template<typename E, typename C_Collection>
	void ArrayList<E, C_Collection> :: clear()
	{	
		cout << "Collectionun clear fonksiyonundan onceki hali : " << endl;
		for(auto it = AL.begin(); it != AL.end(); ++it)
			cout << *it << " ";
		
		AL.clear();
		
		cout << endl;
		cout << "Collectionun clear fonksiyonundan sonraki hali : " << endl;
		for(auto it = AL.begin(); it != AL.end(); ++it)
			cout << *it << " ";
		cout << "Collectionun size' i : " << AL.size() << endl;
	}

	template<typename E, typename C_Collection>
	bool ArrayList<E, C_Collection> :: contains(E e)
	{
		for(auto it = AL.begin(); it != AL.end(); ++it)
		{
			if(*it == e)
				return true;
		}
		return false;
	}

	template<typename E, typename C_Collection>
	void ArrayList<E, C_Collection> :: add(E e)
	{
		auto it2 = AL.end();
		it2 = AL.insert(it2,e);
		
		for(auto it = AL.begin(); it != AL.end(); ++it)
			cout << *it  << " ";
		cout << endl;
	}

	template<typename E, typename C_Collection>
	void ArrayList<E, C_Collection> :: remove(E e)
	{
		cout << "Collectionun "<< e << " cikartilmamis hali : " << endl;
		for(auto it = AL.begin(); it != AL.end(); ++it)
			cout << *it << " ";
		
		for(auto it = AL.begin(); it != AL.end(); ++it)
		{
			if(*it == e)
			{
				it = AL.erase(it);
				it--;
				break; // Sadece 1 tane siler
			}

		}
		cout << endl;
		cout << "Collectionun " << e <<" cikartilmis hali : " << endl;
		for(auto it = AL.begin(); it != AL.end(); ++it)
			cout << *it << " ";

		cout << endl;
	}

	template<typename E, typename C_Collection>
	void ArrayList<E, C_Collection> :: addAll(C_Collection c)
	{	
		if(c.size() <= 0 )
			throw ArrayList_Error();

		cout << "Gelen collectionun benim collectionuma eklenmis hali :" << endl;
		auto it = c.begin(); 
		auto it2 = AL.end();

		for(int i = 0; i < c.size(); ++i)
		{
			it2 = AL.insert(it2,*it);
			it++;
			it2++;
		}

		for(auto it = AL.begin(); it != AL.end(); ++it)
			cout << *it << " ";
		cout << endl;
	}

	template<typename E, typename C_Collection>
	bool ArrayList<E, C_Collection> :: containsAll(C_Collection c)
	{
		if(c.size() <= 0 )
			throw ArrayList_Error();

		int control = 0;
		for(auto it = AL.begin(); it != AL.end(); ++it)
		{
			for(auto it2 = c.begin(); it2 != c.end(); ++it2)
			{
				if(*it == *it2)
					control = -1;

			}
			if(control != -1)
				return false;
			control = 0;
		}
		return true;
	}

	template<typename E, typename C_Collection>
	void ArrayList<E, C_Collection> :: removeAll(C_Collection c)
	{
		if(c.size() <= 0 )
			throw ArrayList_Error();

		for(auto it = AL.begin(); it != AL.end(); ++it)
		{
			for(auto it2 = c.begin(); it2 != c.end(); ++it2)
			{
				if(*it == *it2)
				{
					it = AL.erase(it);
					it = AL.begin();
				}
			}					
		}
		cout << "Benim collectionumda kalan elemanlar : " << endl;
		for(auto it = AL.begin(); it != AL.end(); ++it)
			cout << *it << " ";
		cout << endl;	
					
	}

	template<typename E, typename C_Collection>
	void ArrayList<E, C_Collection> :: retainAll(C_Collection c)
	{
		if(c.size() <= 0 )
			throw ArrayList_Error();
		
		int control = 0;

		for(auto it = AL.begin(); it != AL.end(); ++it)
		{
			for(auto it2 = c.begin(); it2 != c.end(); ++it2)
			{
				if(*it == *it2)
					control = -1; 

			}
			if(control != -1)
			{
				it = AL.erase(it);
				it = AL.begin();
			}
			control = 0;
		}
		cout << "Benim collectionumda kalan elemanlar : " << endl;
		for(auto it = AL.begin(); it != AL.end(); ++it)
			cout << *it << " ";
		cout << endl;		
	}
}