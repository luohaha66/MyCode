package in.fileio;

import java.io.File;
import java.io.IOException;

public class fileio {

	public fileio() {
		// TODO Auto-generated constructor stub
	}

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
//		File dir = new File("file/file1/file2");
//		dir.mkdirs();
//		dir.delete();
		File file = new File("file/file1");
		file.createNewFile();
		System.out.println(file.getAbsolutePath());
		File[] root = File.listRoots();
		for(File a : root) {
			System.out.println(a);
		}
		File[] child = file.listFiles();
		for(File b : child) {
			System.out.println(b);
		}
//		file.delete();
		
		
	}

}
