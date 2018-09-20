import java.util.ArrayList;
import java.util.Map;

public class HashMap <K,V> {

	HashEntity[] map;
	
	HashMap() {
		map = new HashEntity[20];
	}
	
	public void put(K username, V password) {
		
		HashEntity<K,V> entity = new HashEntity<K,V>(username, password);
		
		int total = 0;
		for (int i = 0; i < username.toString().length(); i++) {
			total += ((int)username.toString().charAt(i));
		}
		
		
		int index = total % map.length;
		
		while (true) {
			if (map[index] == null) {
				map[index] = entity;
				return;
			}
			else {
				if (index + 1 ==  map.length) {
					index = 0;
				}
				else {
					index++;
				}
			}
		}
	}
	
	public void check (K key, V value) {
		
		int index = 0;
		
		while (true) {
			
			if (map[index] != null) {
			
				if (map[index].getKey().toString().equals(key.toString())) {
					if (map[index].getValue().toString().equals(value.toString())) {
						System.out.println("Authentication Successful!");
						return;
					}
					else {
						System.out.println("Authentication Fail!");
						return;
					}
				}
			}
			
			if (index + 1 == map.length)
				index = 0;
			else
				index++;
		}
	}
	
	public void display() {
		
		for (int i = 0; i < map.length; i++) {
			
			if (map[i] != null) {
				System.out.println("Key: " + map[i].getKey());
				System.out.println("Value: " + map[i].getValue() + "\n");
			}
			
		}
	}
	
}









