package in.io;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;

public class io {

	public io() {
		// TODO Auto-generated constructor stub
	}

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		/*File file = new File("text.txt");
		file.createNewFile();
		FileWriter writer = new FileWriter(file, true);
		writer.write("hello world\r\n");
		writer.write("i love you\r\n");
		writer.flush();
		writer.close();
		FileReader reader = new FileReader(file);
		char[] buff = new char[50];
		reader.read(buff);
		System.out.println(buff);
		reader.close();*/
		
		/*FileReader reader = new FileReader("text.txt");
		BufferedReader bufferedReader = new BufferedReader(reader);
		String string = null;
		while((string = bufferedReader.readLine()) != null) {	
			System.out.println(string);
		}
		bufferedReader.close();
		FileWriter writer = new FileWriter("text.txt", true);
		BufferedWriter bufferedWriter = new BufferedWriter(writer);
		bufferedWriter.write("i love China");
		bufferedWriter.newLine();
		bufferedWriter.close();*/
		
		/*FileOutputStream outputStream = new FileOutputStream("text.txt", true);
		outputStream.write(new String("hello world").getBytes());
		outputStream.close();
		FileInputStream inputStream = new FileInputStream("text.txt");
		byte[] bs = new byte[100];
		Integer integer = inputStream.read(bs);
	    System.out.println(new String(bs, 0, integer));
	    System.out.println(new String(inputStream.readAllBytes()));
	    inputStream.close();*/
		
		/*FileOutputStream fileOutputStream = new FileOutputStream("text.txt", true);
		BufferedOutputStream outputStream = new BufferedOutputStream(fileOutputStream);
		outputStream.write(new String("i love you").getBytes());
		outputStream.close();
		FileInputStream fileInputStream = new FileInputStream("text.txt");
		BufferedInputStream inputStream = new BufferedInputStream(fileInputStream);
		System.out.println(new String(inputStream.readAllBytes()));
		inputStream.close();*/
		
		/*InputStreamReader streamReader = new InputStreamReader(System.in);
		BufferedReader bufferedReader = new BufferedReader(streamReader);
		String line = bufferedReader.readLine();
		OutputStreamWriter streamWriter = new OutputStreamWriter(System.out);
		streamWriter.write(line);
		streamWriter.flush();*/
		
		PrintWriter printWriter = new PrintWriter(System.out);
		printWriter.println("hello");
		printWriter.flush();
		printWriter.close();
	}

}