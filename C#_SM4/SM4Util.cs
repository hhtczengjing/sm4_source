using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace SM4Test
{
    /// <summary>
    /// SM4 C#版本加解密库
    /// </summary>
    class SM4Util
    {
        /// <summary>
        /// 加密
        /// </summary>
        /// <param name="text">明文</param>
        /// <param name="key">key</param>
        /// <returns>密文</returns>
        public static String encrypt(String text, String key) 
        {
            //16的整数倍
            int offset = 0;
            byte[] textBytes = Encoding.UTF8.GetBytes(text);
            if (textBytes.Length % 16 != 0)
            {
                offset = 16 - textBytes.Length % 16;
            }
            int length = textBytes.Length + offset;
            //key->byte
            byte[] keyBytes = Encoding.UTF8.GetBytes(key);
            byte[] MK = new byte[16];
            for (int i = 0; i < keyBytes.Length; i++)
            {
                MK[i] = keyBytes[i];
            }
            //输入
            byte[] PlainText = new byte[length];
            for (int i = 0; i < textBytes.Length; i++)
            {
                PlainText[i] = textBytes[i];
            }
            //输出
            byte[] CipherText = new byte[length];
            SM4.SM4_Encrypt(MK, PlainText, CipherText);
            return DataUtil.byteArrayToHexStr(CipherText);
        }

        /// <summary>
        /// 解密
        /// </summary>
        /// <param name="text">密文</param>
        /// <param name="key">key</param>
        /// <returns>明文</returns>
        public static String decrypt(String text, String key)
        {
            //key->byte
            byte[] MK = new byte[16];
            byte[] keyBytes = Encoding.UTF8.GetBytes(key);
            for (int i = 0; i < keyBytes.Length; i++)
            {
                MK[i] = keyBytes[i];
            }
            int length = text.Length / 2;
            //输入
            byte[] CipherText = new byte[length];
            byte[] TCipherText = DataUtil.hexStringToByteArray(text);
            for (int i = 0; i < TCipherText.Length; i++)
            {
                CipherText[i] = TCipherText[i];
            }
            //输出
            byte[] PlainText = new byte[length];
            SM4.SM4_Decrypt(MK, CipherText, PlainText);
            return DataUtil.byteToString(PlainText);
        }
    }
}
