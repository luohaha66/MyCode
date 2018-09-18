package in.udp;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;

public class Inet {

	public Inet() {
		// TODO Auto-generated constructor stub
	}

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		System.out.println(InetAddress.getLocalHost().getHostAddress());
		DatagramSocket udp = new DatagramSocket(10000);
		System.out.println("Server Start");
		byte[] rec = new byte[1024];
		DatagramPacket dPacket = new DatagramPacket(rec, rec.length);
		udp.receive(dPacket);
		String data = new String(dPacket.getData());
		System.out.println(data);
		udp.close();
	}
}
