#include "Iterator.h"

namespace HW6_151044058
{
	template<typename E, typename C_Collection>
	Iterator<E, C_Collection> :: Iterator()
	{
		//Empty
	}

	template<typename E, typename C_Collection>
	Iterator<E, C_Collection> :: Iterator(C_Collection obje_temp)
	{
		obje = obje_temp;
		it_pointer = obje.begin();
	}

	template<typename E, typename C_Collection>
	bool Iterator<E, C_Collection> :: hasNext()
	{	
		if(it_pointer != obje.end())
			return true;
		else
			return false;
	}

	template<typename E, typename C_Collection>
	E Iterator<E, C_Collection> :: next()
	{
		it_pointer++;
		return *it_pointer;
	}

	template<typename E, typename C_Collection>
	void Iterator<E, C_Collection> :: remove()
	{
		it_pointer--;
		it_pointer = obje.erase(it_pointer);		
	}

	template<typename E, typename C_Collection>
	typename C_Collection :: iterator Iterator<E, C_Collection> :: get_it_pointer()
	{
		return it_pointer;
	}

}