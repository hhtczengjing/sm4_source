using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace SM4Test
{
    public static class CharAtExtension
    {
        public static char CharAt(this string str, int index)
        {
            if ((index >= str.Length) || (index < 0))
            {
                return '\0';
            }
            return str.Substring(index, 1).ToCharArray()[0];
        }
    }

    class DataUtil
    {
        public static int hexCharToInt(char c)
        {
            if (c >= '0' && c <= '9')
            {
                return (c - '0');
            }
            if (c == 'a')
            {
                return 10;
            }
            else if (c == 'b')
            {
                return 11;
            }
            else if (c == 'c')
            {
                return 12;
            }
            else if (c == 'd')
            {
                return 13;
            }
            else if (c == 'e')
            {
                return 14;
            }
            else if (c == 'f')
            {
                return 15;
            }
            return 0;
        }

        public static String byteToString(byte[] byteArray)
        {
            return Encoding.UTF8.GetString(byteArray).Trim();
        }

        public static String byteArrayToHexStr(byte[] byteArray) 
        {
		    if(byteArray == null) {
			    return null;
		    }
		    char[] hexArray = "0123456789abcdef".ToCharArray();
		    char[] hexChars = new char[byteArray.Length*2];
		    for (int i = 0; i < byteArray.Length; i++)
            {
			    int v = byteArray[i]&0xFF;
			    hexChars[i*2] = hexArray[v >> 4];
			    hexChars[i*2+1] = hexArray[v & 0x0F];
		    }
		    return new String(hexChars);
	    }

        public static byte[] hexStringToByteArray(String hexStr)
        {
            int length = hexStr.Length / 2;
            byte[] result = new byte[length];
            for (int i = 0; i < length; i++)
            {
                int n_gw = hexCharToInt(hexStr.CharAt(2 * i));
                int n_dw = hexCharToInt(hexStr.CharAt(2 * i + 1));
                int n_re = n_gw * 16 + n_dw;
                result[i] = (byte)n_re;
            }
            return result;
        }

    }
}
