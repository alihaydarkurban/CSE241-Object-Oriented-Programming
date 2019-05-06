#ifndef QUEUE_H_
#define QUEUE_H_

#include "Collection.h"

namespace HW6_151044058
{
	template<typename E, typename C_Collection>
	class Queue : public Collection<E, C_Collection>
	{
		public:

			virtual void offer(E e) = 0;
			virtual E element() = 0;
			virtual E poll() = 0;

	};	
}

#endif