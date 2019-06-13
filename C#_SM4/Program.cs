using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace SM4Test
{
    class Program
    {
        static void Main(string[] args)
        {
            String text = "125W34@89";
		    String key = "devzeng";
            Console.WriteLine("[明文]: " + text + " -> " + key);
		
		    String result1 = SM4Util.encrypt(text, key);
		    Console.WriteLine("[加密]: " + result1);
		
		    String result2 = SM4Util.decrypt(result1, key);
		    Console.WriteLine("[解密]: " + result2);
            
            Console.ReadKey();
        }
    }
}
