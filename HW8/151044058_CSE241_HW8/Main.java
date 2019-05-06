
/**
 * Driver class that tests concrete collections.
 * (HashSet, ArrayList and LinkedList)
 * @author Ali Haydar Kurban
 *
 */
public class Main {

	/**
	 * Prints given string
	 * @param s string to be printed
	 */
	private static void print(String s) {
		System.out.println(s);
	}
	
	/**
	 * Prints a bunch of '=' symbos to seperate different tests with each other
	 */
	private static void printSeperator() {
		System.out.println("=============================================================================");
	}
	
	/**
	 * Tests all methods of HashSet class
	 */
	private static void HashSetTester() {
		printSeperator();
		print("Testing Hash Set <String>");
		HashSet<String> testHashSet = new HashSet<String>(String[].class);
		printSeperator();
		print("inserting 'ALI', 'HAYDAR', 'KURBAN' in order");
		testHashSet.add("ALI");
		print(testHashSet.toString());
		testHashSet.add("HAYDAR");
		print(testHashSet.toString());
		testHashSet.add("KURBAN");
		print(testHashSet.toString());

		
		print("cleaning hash set");
		testHashSet.clear();
		print(testHashSet.toString());
		boolean isEmpty = testHashSet.isEmpty();
		print("isEmpty return value: " + isEmpty);
		printSeperator();
		
		print("inserting 'ALI', 'HAYDAR', 'KURBAN' in order");
		testHashSet.add("ALI");
		print(testHashSet.toString());
		testHashSet.add("HAYDAR");
		print(testHashSet.toString());
		testHashSet.add("KURBAN");
		print(testHashSet.toString());
		
		print("checking if 'ALI' exists");
		if(testHashSet.contains("ALI"))
			print("exists");
		else print("does not exist");
		print("checking if 'JAVA' exists");
		if(testHashSet.contains("JAVA"))
			print("exists");
		else print("does not exist");
		printSeperator();
		
		
		print("calling remove with 'ALI'");
		boolean removeReturn = testHashSet.remove("ALI");
		print("return value: " + removeReturn);
		print(testHashSet.toString());
		print("calling remove with 'JAVA'");
		removeReturn = testHashSet.remove("JAVA");
		print("return value: " + removeReturn);
		print(testHashSet.toString());
		printSeperator();
		
		
		print("creating another hast set with values: 'JAVA', 'C++', 'C', 'KURBAN'");
		HashSet<String> testHashSet2 = new HashSet<String>(String[].class);
		testHashSet2.add("JAVA");
		testHashSet2.add("C++");
		testHashSet2.add("C");
		testHashSet2.add("HAYDAR");
		print(testHashSet2.toString());
		printSeperator();
		
		print("adding all elements of 2nd hast set to 1st hast set");
		testHashSet.addAll(testHashSet2);
		print(testHashSet.toString());
		printSeperator();
		
		
		print("checking if 1st hast set contains all of 2nd hast set");
		boolean containsAllResult = testHashSet.containsAll(testHashSet2);
		print("return value: " + containsAllResult);
		print("removing 'HAYDAR' and doing the same check");
		testHashSet.remove("HAYDAR");
		containsAllResult = testHashSet.containsAll(testHashSet2);
		print("return value: " + containsAllResult);
		printSeperator();
		
		print("removing all elements of 2nd hast set from 1st hast set");
		print("before: " + testHashSet.toString());
		testHashSet.removeAll(testHashSet2);
		print("after: " + testHashSet.toString());
		printSeperator();
		
		
		print("adding all elements of 2nd hast set to 1st hast set again");
		testHashSet.addAll(testHashSet2);
		print(testHashSet.toString());
		printSeperator();
		
		
		print("retaining elements of 2nd hast set in 1st hast set");
		print("before: " + testHashSet.toString());
		testHashSet.retainAll(testHashSet2);
		print("after: " + testHashSet.toString());
		printSeperator();
	}
	
	
	/**
	 * Tests all methods of HashSet class
	 */
	private static void HashSetTester2() {
		printSeperator();
		print("Testing Hash Set <Integer>");
		HashSet<Integer> testHashSet = new HashSet<Integer>(Integer[].class);
		printSeperator();
		print("inserting 15, 20, 25, 30 in order");
		testHashSet.add(15);
		print(testHashSet.toString());
		testHashSet.add(20);
		print(testHashSet.toString());
		testHashSet.add(25);
		print(testHashSet.toString());
		testHashSet.add(30);
		print(testHashSet.toString());

		
		print("cleaning hash set");
		testHashSet.clear();
		print(testHashSet.toString());
		boolean isEmpty = testHashSet.isEmpty();
		print("isEmpty return value: " + isEmpty);
		printSeperator();
		
		print("inserting 100, 200, 300 in order");
		testHashSet.add(100);
		print(testHashSet.toString());
		testHashSet.add(200);
		print(testHashSet.toString());
		testHashSet.add(300);
		print(testHashSet.toString());
		
		print("checking if 200 exists");
		if(testHashSet.contains(200))
			print("exists");
		else print("does not exist");
		print("checking if 250 exists");
		if(testHashSet.contains(250))
			print("exists");
		else print("does not exist");
		printSeperator();
		
		
		print("calling remove with 250");
		boolean removeReturn = testHashSet.remove(250);
		print("return value: " + removeReturn);
		print(testHashSet.toString());
		print("calling remove with 200");
		removeReturn = testHashSet.remove(200);
		print("return value: " + removeReturn);
		print(testHashSet.toString());
		printSeperator();
		
		
		print("creating another hast set with values: 10, 20, 30, 40");
		HashSet<Integer> testHashSet2 = new HashSet<Integer>(Integer[].class);
		testHashSet2.add(10);
		testHashSet2.add(20);
		testHashSet2.add(30);
		testHashSet2.add(40);
		print(testHashSet2.toString());
		printSeperator();
		
		print("adding all elements of 2nd hast set to 1st hast set");
		testHashSet.addAll(testHashSet2);
		print(testHashSet.toString());
		printSeperator();
		
		
		print("checking if 1st hast set contains all of 2nd hast set");
		boolean containsAllResult = testHashSet.containsAll(testHashSet2);
		print("return value: " + containsAllResult);
		print("removing 30 and doing the same check");
		testHashSet.remove(30);
		containsAllResult = testHashSet.containsAll(testHashSet2);
		print("return value: " + containsAllResult);
		printSeperator();
		
		print("removing all elements of 2nd hast set from 1st hast set");
		print("before: " + testHashSet.toString());
		testHashSet.removeAll(testHashSet2);
		print("after: " + testHashSet.toString());
		printSeperator();
		
		
		print("adding all elements of 2nd hast set to 1st hast set again");
		testHashSet.addAll(testHashSet2);
		print(testHashSet.toString());
		printSeperator();
		
		
		print("retaining elements of 2nd hast set in 1st hast set");
		print("before: " + testHashSet.toString());
		testHashSet.retainAll(testHashSet2);
		print("after: " + testHashSet.toString());
		printSeperator();
	}
	
	/**
	 * Tests all methods of ArrayList class
	 */
	private static void ArrayListTester() {
		printSeperator();
		print("Testing Array List <String>");
		ArrayList<String> testArrayList = new ArrayList<String>(String[].class);
		printSeperator();
		
		printSeperator();
		print("inserting 'ALI', 'HAYDAR', 'KURBAN' in order");
		testArrayList.add("ALI");
		print(testArrayList.toString());
		testArrayList.add("HAYDAR");
		print(testArrayList.toString());
		testArrayList.add("KURBAN");
		print(testArrayList.toString());

		
		print("cleaning array list");
		testArrayList.clear();
		print(testArrayList.toString());
		boolean isEmpty = testArrayList.isEmpty();
		print("isEmpty return value: " + isEmpty);
		printSeperator();
		
		print("inserting 'ALI', 'HAYDAR', 'KURBAN' in order");
		testArrayList.add("ALI");
		print(testArrayList.toString());
		testArrayList.add("HAYDAR");
		print(testArrayList.toString());
		testArrayList.add("KURBAN");
		print(testArrayList.toString());
		
		print("checking if 'ALI' exists");
		if(testArrayList.contains("ALI"))
			print("exists");
		else print("does not exist");
		print("checking if 'JAVA' exists");
		if(testArrayList.contains("JAVA"))
			print("exists");
		else print("does not exist");
		printSeperator();
		
		
		print("calling remove with 'ALI'");
		boolean removeReturn = testArrayList.remove("ALI");
		print("return value: " + removeReturn);
		print(testArrayList.toString());
		print("calling remove with 'JAVA'");
		removeReturn = testArrayList.remove("JAVA");
		print("return value: " + removeReturn);
		print(testArrayList.toString());
		printSeperator();
		
		
		print("creating another array list with values: 'JAVA', 'C++', 'C', 'KURBAN'");
		ArrayList<String> testArrayList2 = new ArrayList<String>(String[].class);
		testArrayList2.add("JAVA");
		testArrayList2.add("C++");
		testArrayList2.add("C");
		testArrayList2.add("HAYDAR");
		print(testArrayList2.toString());
		printSeperator();
		
		print("adding all elements of 2nd array list to 1st array list");
		testArrayList.addAll(testArrayList2);
		print(testArrayList.toString());
		printSeperator();
		
		
		print("checking if 1st array list contains all of 2nd array list");
		boolean containsAllResult = testArrayList.containsAll(testArrayList2);
		print("return value: " + containsAllResult);
		print("removing 'HAYDAR' and doing the same check");
		testArrayList.remove("HAYDAR");
		containsAllResult = testArrayList.containsAll(testArrayList2);
		print("return value: " + containsAllResult);
		printSeperator();
		
		print("removing all elements of 2nd array list from 1st array list");
		print("before: " + testArrayList.toString());
		testArrayList.removeAll(testArrayList2);
		print("after: " + testArrayList.toString());
		printSeperator();
		
		
		print("adding all elements of 2nd array list to 1st array list again");
		testArrayList.addAll(testArrayList2);
		print(testArrayList.toString());
		printSeperator();
		
		
		print("retaining elements of 2nd array list in 1st array list");
		print("before: " + testArrayList.toString());
		testArrayList.retainAll(testArrayList2);
		print("after: " + testArrayList.toString());
		printSeperator();
	}
	

	/**
	 * Tests all methods of ArrayList class
	 */
	private static void ArrayListTester2() {
		printSeperator();
		print("Testing Array List <Integer>");
		ArrayList<Integer> testArrayList = new ArrayList<Integer>(Integer[].class);
		printSeperator();
		
		printSeperator();
		print("inserting 15, 20, 25, 30 in order");
		testArrayList.add(15);
		print(testArrayList.toString());
		testArrayList.add(20);
		print(testArrayList.toString());
		testArrayList.add(25);
		print(testArrayList.toString());
		testArrayList.add(30);
		print(testArrayList.toString());
		
		
		print("cleaning array list");
		testArrayList.clear();
		print(testArrayList.toString());
		boolean isEmpty = testArrayList.isEmpty();
		print("isEmpty return value: " + isEmpty);
		printSeperator();
		
		print("inserting 100, 200, 300 in order");
		testArrayList.add(100);
		print(testArrayList.toString());
		testArrayList.add(200);
		print(testArrayList.toString());
		testArrayList.add(300);
		print(testArrayList.toString());
		
		print("checking if 200 exists");
		if(testArrayList.contains(200))
			print("exists");
		else print("does not exist");
		print("checking if 250 exists");
		if(testArrayList.contains(250))
			print("exists");
		else print("does not exist");
		printSeperator();
		
		
		print("calling remove with 250");
		boolean removeReturn = testArrayList.remove(250);
		print("return value: " + removeReturn);
		print(testArrayList.toString());
		print("calling remove with 200");
		removeReturn = testArrayList.remove(200);
		print("return value: " + removeReturn);
		print(testArrayList.toString());
		printSeperator();
		
		
		print("creating another array list with values: 10, 20, 30, 40");
		ArrayList<Integer> testArrayList2 = new ArrayList<Integer>(Integer[].class);
		testArrayList2.add(10);
		testArrayList2.add(20);
		testArrayList2.add(30);
		testArrayList2.add(40);
		print(testArrayList2.toString());
		printSeperator();
		
		print("adding all elements of 2nd array list to 1st array list");
		testArrayList.addAll(testArrayList2);
		print(testArrayList.toString());
		printSeperator();
		
		
		print("checking if 1st array list contains all of 2nd array list");
		boolean containsAllResult = testArrayList.containsAll(testArrayList2);
		print("return value: " + containsAllResult);
		print("removing 30 and doing the same check");
		testArrayList.remove(30);
		containsAllResult = testArrayList.containsAll(testArrayList2);
		print("return value: " + containsAllResult);
		printSeperator();
		
		print("removing all elements of 2nd array list from 1st array list");
		print("before: " + testArrayList.toString());
		testArrayList.removeAll(testArrayList2);
		print("after: " + testArrayList.toString());
		printSeperator();
		
		
		print("adding all elements of 2nd array list to 1st array list again");
		testArrayList.addAll(testArrayList2);
		print(testArrayList.toString());
		printSeperator();
		
		
		print("retaining elements of 2nd array list in 1st array list");
		print("before: " + testArrayList.toString());
		testArrayList.retainAll(testArrayList2);
		print("after: " + testArrayList.toString());
		printSeperator();
	}

	
	/**
	 * Tests all methods of LinkedList class
	 */
	private static void LinkedListTester() {
		printSeperator();
		print("Testing Linked List <Integer>");
		LinkedList<Integer> testLinkedList = new LinkedList<Integer>(Integer[].class);
		printSeperator();
		
		print("inserting 15, 20, 25, 30 in order");
		testLinkedList.offer(15);
		print(testLinkedList.toString());
		testLinkedList.offer(20);
		print(testLinkedList.toString());
		testLinkedList.offer(25);
		print(testLinkedList.toString());
		testLinkedList.offer(30);
		print(testLinkedList.toString());
		printSeperator();
		
		try {
			print("calling poll two times");
			testLinkedList.poll();
			print(testLinkedList.toString());
			testLinkedList.poll();
			print(testLinkedList.toString());
			printSeperator();
		} catch (Exception e) {
			e.printStackTrace();
		}
		
		print("cleaning linked list");
		testLinkedList.clear();
		print(testLinkedList.toString());
		boolean isEmpty = testLinkedList.isEmpty();
		print("isEmpty return value: " + isEmpty);
		printSeperator();
		
		print("inserting 100, 200, 300 in order");
		testLinkedList.offer(100);
		print(testLinkedList.toString());
		testLinkedList.offer(200);
		print(testLinkedList.toString());
		testLinkedList.offer(300);
		print(testLinkedList.toString());
		printSeperator();
		
		print("checking if 200 exists");
		if(testLinkedList.contains(200))
			print("exists");
		else print("does not exist");
		print("checking if 250 exists");
		if(testLinkedList.contains(250))
			print("exists");
		else print("does not exist");
		printSeperator();
		
		print("calling remove with 250");
		boolean removeReturn = testLinkedList.remove(250);
		print("return value: " + removeReturn);
		print(testLinkedList.toString());
		print("calling remove with 200");
		removeReturn = testLinkedList.remove(200);
		print("return value: " + removeReturn);
		print(testLinkedList.toString());
		printSeperator();
		
		print("creating another linked list with values: 10, 20, 30, 40");
		LinkedList<Integer> testLinkedList2 = new LinkedList<Integer>(Integer[].class);
		testLinkedList2.offer(10);
		testLinkedList2.offer(20);
		testLinkedList2.offer(30);
		testLinkedList2.offer(40);
		print(testLinkedList2.toString());
		printSeperator();
		
		print("adding all elements of 2nd linked list to 1st linked list");
		testLinkedList.addAll(testLinkedList2);
		print(testLinkedList.toString());
		printSeperator();
		
		print("checking if 1st linked list contains all of 2nd linked list");
		boolean containsAllResult = testLinkedList.containsAll(testLinkedList2);
		print("return value: " + containsAllResult);
		print("removing 30 and doing the same check");
		testLinkedList.remove(30);
		containsAllResult = testLinkedList.containsAll(testLinkedList2);
		print("return value: " + containsAllResult);
		printSeperator();
		
		print("removing all elements of 2nd linked list from 1st linked list");
		print("before: " + testLinkedList.toString());
		testLinkedList.removeAll(testLinkedList2);
		print("after: " + testLinkedList.toString());
		printSeperator();
		
		print("adding all elements of 2nd linked list to 1st linked list again");
		testLinkedList.addAll(testLinkedList2);
		print(testLinkedList.toString());
		printSeperator();
		
		print("retaining elements of 2nd list in 1st linked list");
		print("before: " + testLinkedList.toString());
		testLinkedList.retainAll(testLinkedList2);
		print("after: " + testLinkedList.toString());
		printSeperator();
	}

	/**
	 * Tests all methods of LinkedList class
	 */
	private static void LinkedListTester2() {
		printSeperator();
		print("Testing Linked List <String>");
		LinkedList<String> testLinkedList = new LinkedList<String>(String[].class);
		printSeperator();
		
		print("inserting '15', '20', '25', '30' in order");
		testLinkedList.offer("15");
		print(testLinkedList.toString());
		testLinkedList.offer("20");
		print(testLinkedList.toString());
		testLinkedList.offer("25");
		print(testLinkedList.toString());
		testLinkedList.offer("30");
		print(testLinkedList.toString());
		printSeperator();
		
		try {
			print("calling poll two times");
			testLinkedList.poll();
			print(testLinkedList.toString());
			testLinkedList.poll();
			print(testLinkedList.toString());
			printSeperator();
		} catch (Exception e) {
			e.printStackTrace();
		}
		
		print("cleaning linked list");
		testLinkedList.clear();
		print(testLinkedList.toString());
		boolean isEmpty = testLinkedList.isEmpty();
		print("isEmpty return value: " + isEmpty);
		printSeperator();
		
		print("inserting 100, 200, 300 in order");
		testLinkedList.offer("100");
		print(testLinkedList.toString());
		testLinkedList.offer("200");
		print(testLinkedList.toString());
		testLinkedList.offer("300");
		print(testLinkedList.toString());
		printSeperator();
		
		print("checking if '200' exists");
		if(testLinkedList.contains("200"))
			print("exists");
		else print("does not exist");
		print("checking if '250' exists");
		if(testLinkedList.contains("250"))
			print("exists");
		else print("does not exist");
		printSeperator();
		
		print("calling remove with '250'");
		boolean removeReturn = testLinkedList.remove("250");
		print("return value: " + removeReturn);
		print(testLinkedList.toString());
		print("calling remove with '200'");
		removeReturn = testLinkedList.remove("200");
		print("return value: " + removeReturn);
		print(testLinkedList.toString());
		printSeperator();
		
		print("creating another linked list with values: '10', '20', '30', '40'");
		LinkedList<String> testLinkedList2 = new LinkedList<String>(String[].class);
		testLinkedList2.offer("10");
		testLinkedList2.offer("20");
		testLinkedList2.offer("30");
		testLinkedList2.offer("40");
		print(testLinkedList2.toString());
		printSeperator();
		
		print("adding all elements of 2nd linked list to 1st linked list");
		testLinkedList.addAll(testLinkedList2);
		print(testLinkedList.toString());
		printSeperator();
		
		print("checking if 1st linked list contains all of 2nd linked list");
		boolean containsAllResult = testLinkedList.containsAll(testLinkedList2);
		print("return value: " + containsAllResult);
		print("removing '30' and doing the same check");
		testLinkedList.remove("30");
		containsAllResult = testLinkedList.containsAll(testLinkedList2);
		print("return value: " + containsAllResult);
		printSeperator();
		
		print("removing all elements of 2nd linked list from 1st linked list");
		print("before: " + testLinkedList.toString());
		testLinkedList.removeAll(testLinkedList2);
		print("after: " + testLinkedList.toString());
		printSeperator();
		
		print("adding all elements of 2nd linked list to 1st linked list again");
		testLinkedList.addAll(testLinkedList2);
		print(testLinkedList.toString());
		printSeperator();
		
		print("retaining elements of 2nd list in 1st linked list");
		print("before: " + testLinkedList.toString());
		testLinkedList.retainAll(testLinkedList2);
		print("after: " + testLinkedList.toString());
		printSeperator();
	}
	

	public static void main(String[] args) {
		HashSetTester();
		ArrayListTester();
		LinkedListTester();
		HashSetTester2();
		ArrayListTester2();
		LinkedListTester2();
	}
}