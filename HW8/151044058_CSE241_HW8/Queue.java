

/**
 * Queue Interface
 * 
 * @author Ali Haydar Kurban
 *
 * @param <E>
 */
public interface Queue<E> extends Collection<E> {
	/**
	 * Retrieves, but does not remove, the head of this queue.
	 * @return head of the queue
	 */
	public E element();
	
	/**
	 * Inserts the specified element into this queue
	 * @param e element to be inserted
	 */
	public void offer(E e);
	
	/**
	 * Retrieves and removes the head of this queue, or throws if this queue is empty
	 * @return first element
	 * @throws Exception if queue is empty
	 */
	public E poll() throws Exception;
}