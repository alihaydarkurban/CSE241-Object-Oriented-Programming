#ifndef COLLECTION_H_
#define COLLECTION_H_

#include <iostream>
#include <vector>
#include <set>
#include <list>
#include <queue>
#include <iterator>
#include <string>
#include <cstdlib>
#include "Iterator.h"


using namespace std;

namespace HW6_151044058
{
	template<typename E, typename C_Collection>
	class Collection 
	{
		public:
			//virtual iterator() = 0;
			virtual void add(E e) = 0;
			virtual void addAll(C_Collection c) = 0;
			virtual void clear() = 0;
			virtual bool contains(E e) = 0;
			virtual bool containsAll(C_Collection c) = 0;
			virtual bool isEmpty() = 0;
			virtual void remove(E e) = 0;
			virtual void removeAll(C_Collection c) = 0;
			virtual void retainAll(C_Collection c) = 0;
			virtual int size() = 0;
	};
}

#endif