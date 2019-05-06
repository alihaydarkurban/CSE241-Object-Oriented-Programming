#ifndef HASHSET_H_
#define HASHSET_H_

#include "Set.h"

namespace HW6_151044058
{
	class HashSet_Error{};
	template<typename E, typename C_Collection>
	class HashSet : public Set<E, C_Collection>
	{
		public:

			HashSet(); // No parameter constructor

			HashSet(C_Collection temp_collection); // Gelen collectionu kendi collectionuma atama constructoru

			bool contains(E e)override; // e elemani var mi diye kontrol eder

			void add(E e)override; // e' yi sona ekler

			bool isEmpty()override; // Bos mu dolu mu kontrolu yapar

			int size()override; //Size i bulur

			void remove(E e)override; // e eger varsa onu siler 

			void clear()override; // Butun herseyi siler

			void addAll(C_Collection c)override; // Bende olan collectiona baska bir collection ekler 

			bool containsAll(C_Collection c)override; // Benim collectionumda olan her eleman gelen collectionda varsa true return eder

			void removeAll(C_Collection c)override; // Iki collectionda da ortak olanlari benim collectionumdan siler

			void retainAll(C_Collection c)override; // Iki collectionda da farkli olanlari benim collectionumdan siler aynilari kalir


		private:
			C_Collection HS; //Collection tipim
	};

}

#endif