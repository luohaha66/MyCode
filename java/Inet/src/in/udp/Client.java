package in.udp;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;

public class Client {

	public Client() {
		// TODO Auto-generated constructor stub
	}

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		System.out.println(InetAddress.getLocalHost().getHostAddress());
		DatagramSocket udp = new DatagramSocket();
		System.out.println("Client Start");
		byte[] rec = "hello".getBytes();
		DatagramPacket dPacket = new DatagramPacket(rec, rec.length, InetAddress.getLocalHost(), 10000);
		udp.send(dPacket);
		udp.close();
	}

}
