## SM4加解密算法

### C语言版本

```
int main(int argc, char **argv) {
    printf("-------SM4加解密使用流程-------\n");
    
    unsigned char input[] = "125W34@89";
    unsigned char key[] = "devzeng";
    unsigned int key_length = 9;
    int length = sizeof(input);
    printf("[明文]: %s:%d -> %s:%d\n", input, length, key, key_length);
    
    //加密
    unsigned char *result1 = pd_sm4_encrypt(input, length, key, key_length);
    printf("[加密]: %s\n", result1);
    
    //解密
    unsigned char *result2 = pd_sm4_decrypt(result1, 32, key, key_length);
    printf("[解密]: %s\n", result2);
    
    //free
    free(result1);
    free(result2);
    
    return 0;
}
```

### Java语言版本

```
public static void main(String[] args) {
	String text = "125W34@89";
	String key = "devzeng";
	System.out.println("[明文]: " + text + " -> " + key);
	
	String result1 = SM4Util.encrypt(text, key);
	System.out.println("[加密]: " + result1);
		
	String result2 = SM4Util.decrypt(result1, key);
	System.out.println("[解密]: " + result2);
}
```

### C#语言版本

```
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
```