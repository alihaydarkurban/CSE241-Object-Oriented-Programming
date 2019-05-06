#ifndef ITERATOR_H_
#define ITERATOR_H_
#include <iterator>
#include <iostream>

using namespace std;

namespace HW6_151044058
{
	template<typename E, typename C_Collection>
	class Iterator
	{
		public:
			Iterator();

			Iterator(C_Collection obje_temp);

			bool hasNext();
		
			E next();

			void remove();

			typename C_Collection :: iterator get_it_pointer();

		private:
			C_Collection obje;	

			typename C_Collection :: iterator it_pointer;
	};
}
#endif