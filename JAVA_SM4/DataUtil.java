package com.devzeng.crypt.sm4;

public class DataUtil {
	
	public static int hexCharToInt(char c) {
		if (c >= '0' && c <= '9') {
	        return (c - '0');
	    }
	    if (c == 'a') {
	        return 10;
	    }
	    else if(c == 'b'){
	        return 11;
	    }
	    else if(c == 'c'){
	        return 12;
	    }
	    else if(c == 'd'){
	        return 13;
	    }
	    else if(c == 'e'){
	        return 14;
	    }
	    else if(c == 'f'){
	        return 15;
	    }
	    return 0;
	}

	public static String byteToString(byte[] byteArray) {
        return new String(byteArray).trim();
	}
	
	public static String byteArrayToHexStr(byte[] byteArray) {
		if(byteArray == null) {
			return null;
		}
		char[] hexArray = "0123456789abcdef".toCharArray();
		char[] hexChars = new char[byteArray.length*2];
		for (int i = 0; i < byteArray.length; i++) {
			int v = byteArray[i]&0xFF;
			hexChars[i*2] = hexArray[v >>> 4];
			hexChars[i*2+1] = hexArray[v & 0x0F];
		}
		return new String(hexChars);
	}
	
	public static byte[] hexStringToByteArray(String hexStr) {
		int length = hexStr.length()/2;
		byte[] result = new byte[length];
		for (int i = 0; i < length; i++) {
			int n_gw = hexCharToInt(hexStr.charAt(2*i));
			int n_dw = hexCharToInt(hexStr.charAt(2*i+1));
			int n_re = n_gw * 16 + n_dw;
			result[i] = (byte)n_re;
		}
		return result;
	}
}