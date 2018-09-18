/**
 * 
 */
package cn.tx;

import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Date;
import java.util.Random;
import java.util.Scanner;

public class Demo {
	public static int div(int a, int b) {
		int c = 1;
		int d;
		try {
			d = a / b;
			System.out.println("cccc");
			return c;
		} catch (Exception e) {
			c = 2;
			// TODO Auto-generated catch block
			e.printStackTrace();
			System.out.println("aaaa");
			return c;
		} finally {
			c = 3;
			System.out.println("bbbb");
		}
	}

	public static void parseStr(String str) {
		int length = str.length();
		for (int i = 0; i < length; i++) {
			char c = str.charAt(i);
			if (c >= 65 && c <= 90) {
				System.out.println("Big Number");
			} else if (c >= 97 && c <= 122) {
				System.out.println("Small number");
			} else if (c >= 48 && c <= 57) {
				System.out.println("Number");
			}
		}
	}

	public static void main(String[] args) {
		// div(5, 0);
		Scanner s = new Scanner(System.in);
		String string = s.nextLine();
		// parseStr(string);
		s.close();
		char[] css = { 'a', 'b', 'c' };
		System.out.println(string.toCharArray());
		System.out.println(String.valueOf(false));
		System.out.println(String.valueOf(css));
		System.out.println(string.toUpperCase());
		StringBuffer buffer = new StringBuffer("hello");
		buffer.append("world");
		System.out.println(buffer);
		System.out.println((int) Math.floor(Math.random()*100));
		System.out.println(new Random().nextGaussian());
		System.out.println(System.currentTimeMillis());
		System.out.println(System.getProperty("java.version"));
		System.out.println(Integer.MAX_VALUE);
		System.out.println(Integer.valueOf("9999"));
		Integer a = 8;
		System.out.println(a);
		System.out.println(new SimpleDateFormat("yyyy/MM/dd/ HH:mm:ss:SSS E a").format(new Date()));
		System.out.println(Calendar.getInstance());
	}

}
