package com.devzeng.crypt.sm4;

public class SM4Test {

	public static void main(String[] args) {
		String text = "125W34@89";
		String key = "devzeng";
		System.out.println("[明文]: " + text + " -> " + key);
		
		String result1 = SM4Util.encrypt(text, key);
		System.out.println("[加密]: " + result1);
		
		String result2 = SM4Util.decrypt(result1, key);
		System.out.println("[解密]: " + result2);
	}
}