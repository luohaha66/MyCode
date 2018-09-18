package in.collection;

import java.util.HashMap;
import java.util.Hashtable;
import java.util.LinkedHashMap;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Set;
import java.util.TreeMap;

public class collection {

	public collection() {
		// TODO Auto-generated constructor stub
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		/*ArrayList<Integer> col = new ArrayList<Integer>();
		for (Integer i = 0; i < 5; i++) {
			col.add(i);
		}
		Iterator<Integer> it = col.iterator();
		while (it.hasNext()) {
			System.out.println(it.next());
		}

		LinkedList<Integer> list = new LinkedList<Integer>();
		for (Integer i = 0; i < 5; i++) {
			list.add(i);
		}
		ListIterator<Integer> iterator = list.listIterator();
		while (iterator.hasNext()) {
			if (iterator.next() == 3) {
				iterator.add(6);
			}
		}
		System.out.println(list);
		list.pop();
		System.out.println(list);
		list.push(7);
		System.out.println(list);
		for (Integer integer : list) {
			System.out.println(integer);
		}
		Collections.reverse(list);
		System.out.println(list);
		Collections.sort(list);
		System.out.println(list);
		
		{
			HashSet<Integer> set = new HashSet<Integer>();
			set.add(2);
			set.add(4);
			set.add(3);
			set.add(5);
			System.out.println(set);
		}
		
		{
			LinkedHashSet<Integer> set = new LinkedHashSet<Integer>();
			set.add(2);
			set.add(4);
			set.add(3);
			set.add(5);
			System.out.println(set);
		}
		
		{
			TreeSet<Integer> set = new TreeSet<Integer>();
			set.add(2);
			set.add(4);
			set.add(3);
			set.add(5);
			System.out.println(set);
		}
		
		Integer[] a = {5, 9, 6, 3, 10};
		Arrays.sort(a);
		System.out.println(Arrays.binarySearch(a, 10));
		System.out.println(Arrays.toString(a));*/
		
		{
			Map<Integer, String> map = new HashMap<Integer, String>();
			map.put(1, "luo");
			map.put(3, "ha");
			map.put(0, "bb");
			Set<Integer> set = map.keySet(); //get all key
			System.out.println(set);
			System.out.println(map);
			
			Set<Entry<Integer, String>> en = map.entrySet();
			for(Entry<Integer, String> s : en) {
				System.out.println(s.getKey());
				System.out.println(s.getValue());
			}
		}
		
		{
			Map<Integer, String> map = new TreeMap<Integer, String>();
			map.put(1, "luo");
			map.put(3, "ha");
			map.put(0, "bb");
			Set<Integer> set = map.keySet(); //get all key
			System.out.println(set);
			System.out.println(map);
		}
		
		{
			Map<Integer, String> map = new Hashtable<Integer, String>();
			map.put(1, "luo");
			map.put(3, "ha");
			map.put(0, "bb");
			Set<Integer> set = map.keySet(); //get all key
			System.out.println(set);
			System.out.println(map);
		}
		
		{
			Map<Integer, String> map = new LinkedHashMap<Integer, String>();
			map.put(1, "luo");
			map.put(3, "ha");
			map.put(0, "bb");
			Set<Integer> set = map.keySet(); //get all key
			System.out.println(set);
			System.out.println(map);
		}
	}

}
