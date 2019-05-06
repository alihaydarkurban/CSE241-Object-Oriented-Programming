

/**
 * Top interface.
 * Every other collection relates to this
 * 
 * @author Ali Haydar Kurban
 * 
 * @param <E>
 */
public interface Collection<E> {
	/**
	 * Returns an iterator over the collection
	 * @return an iterator object
	 */
	public Iterator<E> iterator();
	
	/**
	 * Ensures that this collection contains the specified element
	 * @param e element to be added
	 * @return true by default
	 */
	public boolean add(E e);
	
	/**
	 * Adds all of the elements in the specified collection to this
	 * collection
	 * @param c collection to be added
	 */
	public void addAll(Collection<E> c);
	
	/**
	 * Removes all of the elements from this collection 
	 */
	public void clear();
	
	/**
	 * Returns true if this collection contains the specified element.
	 * @param e element needs to be checked
	 * @return true if collection has element
	 */
	public boolean contains(E e);
	
	/**
	 * Returns true if this collection contains all of the elements in the specified collection.
	 * @param c collection needs to be checked
	 * @return true if collection has collection
	 */
	public boolean containsAll(Collection<E> c);
	
	/**
	 * Returns true if this collection contains no elements
	 * @return true if collections size is 0
	 */
	public boolean isEmpty();
	
	/**
	 * Removes a single instance of the specified element from this collection, if it is present 
	 * @param e element to be removed
	 * @return true if element is present, false otherwise
	 */
	public boolean remove(E e);
	
	/**
	 * Removes all of this collection's elements that are also contained in the specified collection
	 * @param c collection to be removed
	 */
	public void removeAll(Collection<E> c);
	
	/**
	 * Retains only the elements in this collection that are contained in the specified collection
	 * @param c collection to be retained
	 */
	public void retainAll(Collection<E> c);
	
	/**
	 * Returns the number of elements in this collection
	 * @return size of collection
	 */
	public int size();
}