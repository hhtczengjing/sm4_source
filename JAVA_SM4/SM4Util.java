package com.devzeng.crypt.sm4;

public class SM4Util {

	public static String encrypt(String text, String key) {
		//16的整数倍
		int offset = 0;
		if(text.getBytes().length%16 != 0) {
			offset = 16 - text.getBytes().length%16;
		}
		int length = text.getBytes().length + offset;
		//key->byte
		byte[] MK = new byte[16];
		for (int i = 0; i < key.getBytes().length; i++) {
			MK[i] = key.getBytes()[i];
		}
		//输入
		byte[] PlainText = new byte[length];
		for (int i = 0; i < text.getBytes().length; i++) {
			PlainText[i] = text.getBytes()[i];
		}
		//输出
		byte[] CipherText = new byte[length];
		SM4.SM4_Encrypt(MK, PlainText, CipherText);
		return DataUtil.byteArrayToHexStr(CipherText);
	}
	
	public static String decrypt(String text, String key) {
		//key->byte
		byte[] MK = new byte[16];
		for (int i = 0; i < key.getBytes().length; i++) {
			MK[i] = key.getBytes()[i];
		}
		int length = text.length()/2;
		//输入
		byte[] CipherText = new byte[length];
		byte[] TCipherText = DataUtil.hexStringToByteArray(text);
		for (int i = 0; i < TCipherText.length; i++) {
			CipherText[i] = TCipherText[i];
		}
		//输出
		byte[] PlainText = new byte[length];
		SM4.SM4_Decrypt(MK, CipherText, PlainText);
		return DataUtil.byteToString(PlainText);
	}
}