package in.code;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;

public class Code {

	public Code() {
		// TODO Auto-generated constructor stub
	}

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		PrintWriter printWriter = new PrintWriter(new OutputStreamWriter(new FileOutputStream("1.txt"), "GBK"), true);
		printWriter.println("ÖÐ¹ú");
		printWriter.close();
		
		PrintWriter printWriter2 = new PrintWriter(System.out, true);
		BufferedReader reader = new BufferedReader(new InputStreamReader(new FileInputStream("1.txt"), "GBK"));
		String line = reader.readLine();
		printWriter2.println(line);
		reader.close();
	}

}
