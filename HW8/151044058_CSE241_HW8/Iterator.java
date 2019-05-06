/**
 * Iterator interface.
 * Every collection iterator needs to implement this interface
 * 
 * @author Ali Haydar Kurban
 *
 * @param <E>
 */
public interface Iterator<E> {
	/**
	 * Returns true if the iteration has more elements
	 * @return true if limit has not reached
	 */
	public boolean hasNext();
	
	/**
	 * Returns the next element in the iteration and advances the iterator
	 * @return next element
	 */
	public E next();
	
	/**
	 * Removes from the underlying collection the last element returned by this iterator
	 */
	public void remove();
}