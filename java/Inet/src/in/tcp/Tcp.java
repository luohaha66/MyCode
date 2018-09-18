package in.tcp;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.net.ServerSocket;
import java.net.Socket;

public class Tcp {

	public Tcp() {
		// TODO Auto-generated constructor stub
	}

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		ServerSocket socket = new ServerSocket(10000);
		Socket socket2 = socket.accept();
		System.out.println(socket2.getInetAddress().getHostAddress());
		InputStream inputStream = socket2.getInputStream();
		BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(inputStream));
		System.out.println(bufferedReader.readLine());
		bufferedReader.close();
		inputStream.close();
		socket.close();
	}

}
