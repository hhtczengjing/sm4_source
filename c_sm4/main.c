//
//  main.c
//  Demo
//
//  Created by zengjing on 2017/6/10.
//  Copyright © 2017年 blog.devzeng.com. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "Util.h"

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
