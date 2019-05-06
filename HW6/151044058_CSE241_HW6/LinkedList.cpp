#include "LinkedList.h"


namespace HW6_151044058
{
	template<typename E, typename C_Collection>
	LinkedList<E, C_Collection> :: LinkedList()
	{
		//Empty
	}

	template<typename E, typename C_Collection>
	LinkedList<E, C_Collection> :: LinkedList(C_Collection temp_collection)
	{
		LL = temp_collection;
	}
	
	template<typename E, typename C_Collection>
	bool LinkedList<E, C_Collection> :: contains(E e)
	{
		for(auto it = LL.begin(); it != LL.end(); ++it)
		{
			if(*it == e)
				return true;
		}
		return false;
	}
	
	template<typename E, typename C_Collection>
	void LinkedList<E, C_Collection> :: add(E e)
	{
		auto it2 = LL.end();
		it2 = LL.insert(it2,e);
		
		for(auto it = LL.begin(); it != LL.end(); ++it)
			cout << *it  << " ";
	
		cout << endl;
	}
	
	template<typename E, typename C_Collection>
	bool LinkedList<E, C_Collection> :: isEmpty()
	{
		if(LL.empty())
			return true;
		else
			return false;
	}
	
	template<typename E, typename C_Collection>
	int LinkedList<E, C_Collection> :: size()
	{
		int size_counter = 0;
		for(auto it = LL.begin(); it != LL.end(); ++it)					
		{
			size_counter +=1;
		}
		return size_counter;

	}
	
	template<typename E, typename C_Collection>
	void LinkedList<E, C_Collection> :: remove(E e)
	{
		cout << "Collectionun "<< e << " cikartilmamis hali : " << endl;
		for(auto it = LL.begin(); it != LL.end(); ++it)
			cout << *it << " ";
		
		for(auto it = LL.begin(); it != LL.end(); ++it)
		{
			if(*it == e)
			{
				it = LL.erase(it);
				it--;
			}

		}
		cout << endl;
		cout << "Collectionun " << e <<" cikartilmis hali : " << endl;
		for(auto it = LL.begin(); it != LL.end(); ++it)
			cout << *it << " ";

		cout << endl;


	}

	template<typename E, typename C_Collection>
	void LinkedList<E, C_Collection> :: clear()
	{
		cout << "Collectionun clear fonksiyonundan onceki hali : " << endl;
		for(auto it = LL.begin(); it != LL.end(); ++it)
			cout << *it << " ";

		LL.clear();

		cout << endl;
		cout << "Collectionun clear fonksiyonundan sonraki hali : " << endl;
		for(auto it = LL.begin(); it != LL.end(); ++it)
			cout << *it << " ";
		cout << "Collectionun size' i : " << LL.size() << endl;

	}
	
	template<typename E, typename C_Collection>
	void LinkedList<E, C_Collection> :: addAll(C_Collection c)
	{
		if(c.size() <= 0)
			throw LinkedList_Error();

		cout << "Gelen collectionun benim collectionuma eklenmis hali :" << endl;
		auto it = c.begin(); 
		auto it2 = LL.end();

		for(int i = 0; i < c.size(); ++i)
		{
			if(!contains(*it))
			{
				it2 = LL.insert(it2,*it);
				it++;
				it2++;
			}
			else
				it++;
		}

		for(auto it = LL.begin(); it != LL.end(); ++it)
			cout << *it << " ";
		cout << endl;		
	}
	
	template<typename E, typename C_Collection>
	bool LinkedList<E, C_Collection> :: containsAll(C_Collection c)
	{
		if(c.size() <= 0)
			throw LinkedList_Error();

		int control = 0;
		for(auto it = LL.begin(); it != LL.end(); ++it)
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
	void LinkedList<E, C_Collection> :: removeAll(C_Collection c)
	{
		if(c.size() <= 0)
			throw LinkedList_Error();

		for(auto it = LL.begin(); it != LL.end(); ++it)
		{
			for(auto it2 = c.begin(); it2 != c.end(); ++it2)
			{
				if(*it == *it2)
				{
					it = LL.erase(it);
					it = LL.begin();
				}
			}					
		}
		cout << "Benim collectionumda kalan elemanlar : " << endl;
		for(auto it = LL.begin(); it != LL.end(); ++it)
			cout << *it << " ";
		cout << endl;
	}
	
	template<typename E, typename C_Collection>
	void LinkedList<E, C_Collection> :: retainAll(C_Collection c)
	{
		if(c.size() <= 0)
			throw LinkedList_Error();

		int control = 0;

		for(auto it = LL.begin(); it != LL.end(); ++it)
		{
			for(auto it2 = c.begin(); it2 != c.end(); ++it2)
			{
				if(*it == *it2)
					control = -1; 

			}
			if(control != -1)
			{
				it = LL.erase(it);
				it = LL.begin();
			}
			control = 0;
		}

		cout << "Benim collectionumda kalan elemanlar : " << endl;
		for(auto it = LL.begin(); it != LL.end(); ++it)
			cout << *it << " ";
		cout << endl;

	}

	template<typename E, typename C_Collection>
	void LinkedList<E, C_Collection> :: offer(E e)
	{
		auto it2 = LL.end();
		it2 = LL.insert(it2,e);
		
		for(auto it = LL.begin(); it != LL.end(); ++it)
			cout << *it  << " ";
	
		cout << endl;
	}

	template<typename E, typename C_Collection>
 	E LinkedList<E, C_Collection> :: poll()
	{
		if(!LL.empty())
		{
			auto temp = LL.begin();

			auto it = LL.begin();
			it = LL.erase(it);
			it--;

			return *temp;
		}
	}

	template<typename E, typename C_Collection>
	E LinkedList<E, C_Collection> :: element()
	{
		if(!LL.empty())
		{
			auto temp = LL.begin();
			return *temp;
		}
	}

}