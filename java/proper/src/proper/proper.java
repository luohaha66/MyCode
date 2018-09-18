package proper;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.Serializable;
import java.util.ArrayList;
import java.util.List;

public class proper implements Serializable{
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	private String name;
	private Integer age;
	private Integer grade;

	public proper(String name, Integer age, Integer grade) {
		super();
		this.name = name;
		this.age = age;
		this.grade = grade;
	}

	public proper() {
		// TODO Auto-generated constructor stub
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public Integer getAge() {
		return age;
	}

	public void setAge(Integer age) {
		this.age = age;
	}

	public Integer getGrade() {
		return grade;
	}

	public void setGrade(Integer grade) {
		this.grade = grade;
	}

	@Override
	public String toString() {
		return "proper [name=" + name + ", age=" + age + ", grade=" + grade + "]";
	}

	public static void main(String[] args) throws IOException, ClassNotFoundException {
		// TODO Auto-generated method stub
		/*Properties properties = new Properties();
		properties.setProperty("1", "luo");
		properties.setProperty("2", "ha");
		properties.setProperty("3", "ha");
		System.out.println(properties);
		System.out.println(properties.getProperty("1"));
		PrintWriter writer = new PrintWriter("1.txt");
		properties.list(writer);
		writer.close();
		properties.load(new FileReader("1.txt"));
		System.out.println(properties);*/
		
		List<proper> list = new ArrayList<proper>();
		ObjectOutputStream outputStream = new ObjectOutputStream(new FileOutputStream("2.txt"));
		for(int i = 0; i < 10; i++) {
			proper proper = new proper("luohaha" + i, i, i);
			list.add(proper);
		}
		outputStream.writeObject(list);
		outputStream.close();
		
		ObjectInputStream inputStream = new ObjectInputStream(new FileInputStream("2.txt"));
		@SuppressWarnings("unchecked")
		List<proper> list2= (List<proper>)inputStream.readObject();
		for(proper proper2 : list2) {
			System.out.println(proper2);
		}
		inputStream.close();
	}
}
