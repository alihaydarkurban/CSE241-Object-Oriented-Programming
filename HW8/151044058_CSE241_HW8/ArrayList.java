import java.lang.reflect.Array;

/**
 * ArrayList class that implements List interface.
 * 
 * @author Ali Haydar Kurban
 *
 */
public class ArrayList<E> implements List<E> {
	/**
	 * Array data container
	 */
	private E[] data;
	
	/**
	 * Array data type, explained in constructor
	 */
	private Class<E[]> arrayType;
	
	/**
	 * Space reserved for array, getting expanded when the limit is reached
	 */
	private int capacity;
	
	/**
	 * Total number of elements currently in the array
	 */
	private int size;
	
	/**
	 * Constructor, initializes values.
	 * @param arrayType this value is passed because there are no others ways to initialize generic Java arrays
	 */
	public ArrayList(Class<E[]> arrayType) {
		this.arrayType = arrayType;
		size = 0;
		capacity = 2;
		data = arrayType.cast(Array.newInstance(arrayType.getComponentType(), capacity));
	}
	
	/**
	 * Inner iterator class
	 * 
	 * @author Ali Haydar Kurban
	 */
	public class ArrayListIterator implements Iterator<E> {
		/**
		 * current position, default value is 0
		 */
		private int currentPosition = 0;
		
		/**
		 * iterator constructor, sets current position to 0
		 */
		public ArrayListIterator() {
			currentPosition = 0;
		}
		
		/**
		 * checks the array if the limit is reached
		 * 
		 * @return true if the limit has not reached, false otherwise
		 */
		@Override
		public boolean hasNext() {
			return currentPosition < size ? true : false;
		}

		/**
		 * returns the current element, advances position by 1
		 * 
		 * @return generic typed element
		 */
		@Override
		public E next() {
			E result = data[currentPosition];
			currentPosition++;
			return result;
		}

		/**
		 * removes current element and goes back to the previous element of removed
		 */
		@Override
		public void remove() {
			for(int i = currentPosition; i < size - 1; i++)
				data[i] = data[i + 1];
			size--;
			currentPosition--;
		}
		
	}

	/**
	 * returns new instance of iterator class
	 * 
	 * @return parameter object
	 */
	@Override
	public Iterator<E> iterator() {
		return new ArrayListIterator();
	}

	/**
	 * adds an element to the list.
	 * expands container if necessary.
	 * returns true all the time.
	 * 
	 * @param e element to be added
	 * @return true
	 */
	@Override
	public boolean add(E e) {
		if(size + 1 == capacity) {
			E[] tempData = arrayType.cast(Array.newInstance(arrayType.getComponentType(), capacity * 2));
			for(int i = 0; i < size; i++)
				tempData[i] = data[i];
			data = arrayType.cast(Array.newInstance(arrayType.getComponentType(), capacity * 2));
			for(int i = 0; i < size; i++)
				data[i] = tempData[i];
			capacity *= 2;
		}
		data[size] = e;
		size++;
		
		return true;
	}

	/**
	 * takes a collection of elements, adds them one by one to current collection
	 * 
	 * @param c collection to be added
	 */
	@Override
	public void addAll(Collection<E> c) {
		Iterator<E> cIter = c.iterator();
		while(cIter.hasNext()) {
			this.add(cIter.next());
		}
	}

	/**
	 * resets size value to 0.
	 */
	@Override
	public void clear() {
		size = 0;
	}

	/**
	 * iterates through the collection and
	 * compares each element to given parameter
	 * returns true if a match is found, false otherwise
	 * 
	 * @param e element to be checked
	 * @return true if parameter is in collection, false otherwise
	 */
	@Override
	public boolean contains(E e) {
		ArrayListIterator iter = new ArrayListIterator();
		while(iter.hasNext()) {
			if(iter.next().equals(e)) {
				return true;
			}
		}
		
		return false;
	}

	/**
	 * calls contains for each element of given container
	 * if all of them matches, returns true.
	 * returns false otherwise]
	 * 
	 * @param c collection to be checked
	 * @return true if all elements of parameter is in current collection
	 */
	@Override
	public boolean containsAll(Collection<E> c) {
		Iterator<E> cIter = c.iterator();
		int matchCount = 0;
		while(cIter.hasNext()) {
			if(this.contains(cIter.next())) {
				matchCount++;
			}
		}
		
		if(matchCount >= c.size())
			return true;
		else return false;
	}

	/**
	 * returns 0 if the size is 0
	 */
	@Override
	public boolean isEmpty() {
		if(size == 0)
			return true;
		return false;
	}

	/**
	 * removes given element from collection
	 * 
	 * @param e element to be removed
	 * @return true if the removal is successful, false otherwise
	 */
	@Override
	public boolean remove(E e) {
		ArrayListIterator iter = new ArrayListIterator();
		int elementIndex = 0;
		boolean hasFound = false;
		while(iter.hasNext()) {
			if(iter.next().equals(e)) {
				hasFound = true;
				break;
			}
			elementIndex++;
		}
		
		if(!hasFound)
			return false;
		
		for(int i = elementIndex; i < size - 1; i++)
			data[i] = data[i+1];
		
		size--;
		return true;
	}

	/**
	 * removes all of the elements given in parameter collection
	 * 
	 * @param c collection to be removed
	 */
	@Override
	public void removeAll(Collection<E> c) {
		Iterator<E> cIter = c.iterator();
		while(cIter.hasNext()) {
			E current = cIter.next();
			if(this.contains(current)) {
				this.remove(current);
			}
		}
	}

	/**
	 * only keeps the elements that are both
	 * in parameter collection and working collection
	 * 
	 * @param c collection to be retained
	 */
	@Override
	public void retainAll(Collection<E> c) {
		ArrayListIterator iter = new ArrayListIterator();
		LinkedList<E> toBeRemoved = new LinkedList<E>(arrayType);
		while(iter.hasNext()) {
			E current = iter.next();
			if(!c.contains(current) && this.contains(current)) {
				toBeRemoved.add(current);
			}
		}
		this.removeAll(toBeRemoved);
	}

	/**
	 * size getter value
	 * 
	 * @return value of size field
	 */
	@Override
	public int size() {
		return size;
	}

	/**
	 * 
	 * @return formatted string version of collection
	 */
	@Override
	public String toString() {
		StringBuilder sb = new StringBuilder();
		sb.append("[");
		ArrayListIterator iter = new ArrayListIterator();
		while(iter.hasNext()) {
			sb.append(iter.next());
			if(iter.hasNext())
				sb.append(", ");
		}
		sb.append("]");
		return sb.toString();
	}
}