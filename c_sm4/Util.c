//
//  Util.c
//  Demo
//
//  Created by zengjing on 2017/6/10.
//  Copyright © 2017年 blog.devzeng.com. All rights reserved.
//

#include "Util.h"
#include "SM4.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//十六进制 -> 字符串
unsigned char * pd_hex2Str(unsigned char arrB[],int length){
    int iLen = length*2+1;
    unsigned char* ch = (unsigned char*)malloc(sizeof(unsigned char)*iLen);
    unsigned char* p = ch;
    for (int i = 0; i < length; i++) {
        int intTmp = arrB[i];
        // 把负数转换为正数
        while (intTmp < 0) {
            intTmp = intTmp + 256;
        }
        // 小于0F的数需要在前面补0
        int fw = intTmp/16;
        int sw = intTmp%16;
        *p++ = pd_hex2Char(fw);
        *p++ = pd_hex2Char(sw);
    }
    *p = '\0';
    return ch;
}

//十六进制 -> 字符
unsigned char pd_hex2Char(int n) {
    unsigned char res = 0;
    if (n < 10) {
        res = n + '0';
    }
    else {
        switch(n){
            case 10:
                res = 'a';
                break;
            case 11:
                res = 'b';
                break;
            case 12:
                res = 'c';
                break;
            case 13:
                res = 'd';
                break;
            case 14:
                res = 'e';
                break;
            case 15:
                res = 'f';
                break;
        }
    }
    return res;
}

int pd_str2Int(unsigned char *str) {
    char c = str[0];
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

//加密
unsigned char * pd_sm4_encrypt(unsigned char text[], int length, unsigned char *sm4_crypt_key, unsigned int key_length) {
    //1.将明文的字符串转换为16进制字符串，不足的使用空字符替代
    unsigned int offset;
    if(length%16 == 0) {
        offset = 0;
    }
    else {
        offset = 16 - length%16;
    }
    unsigned int new_length = length + offset; //确保字符串是16的倍数
    //2.构造输入输出的存储空间
    unsigned char * input = (unsigned char *)malloc(sizeof(unsigned char)*new_length);
    unsigned char * output = (unsigned char *)malloc(sizeof(unsigned char)*new_length);
    memset(input, 0, new_length);
    memcpy(input, text, length);
    //2.将key转换成16进制的字符串
    unsigned char * key = (unsigned char *)malloc(sizeof(unsigned char)*16);
    memset(key, 0, 16);
    memcpy(key, sm4_crypt_key, key_length);
    //3.调用加密库进行加密
    SM4_Encrypt(key, input, output);
    unsigned char* result = pd_hex2Str(output, new_length);
    free(input);
    free(output);
    free(key);
    return result;
}

//解密
unsigned char * pd_sm4_decrypt(unsigned char text[], int length, unsigned char *sm4_crypt_key, unsigned int key_length) {
    //1.将key转换成16进制的字符串
    unsigned char * key = (unsigned char *)malloc(sizeof(unsigned char)*16);
    memset(key, 0, 16);
    memcpy(key, sm4_crypt_key, key_length);
    //2.将密文转成成16进制字符串
    unsigned int new_length = length / 2;
    unsigned char * input = (unsigned char *)malloc(sizeof(unsigned char)*new_length);
    unsigned char * output = (unsigned char *)malloc(sizeof(unsigned char)*new_length);
    for (int i = 0; i < new_length; i++) {
        int n_gw = pd_str2Int(&text[2*i]);
        int n_dw = pd_str2Int(&text[2*i+1]);
        int n_res = n_gw * 16 + n_dw;
        input[i] = n_res;
    }
    //3.调用解密库进行解密
    SM4_Decrypt(key, input, output);
    int kgPos;
    for(int i = 0; i < new_length; i++) {
        if (output[i] == 32) {
            kgPos = i;
            output[i] = '\0';
        }
    }
    free(input);
    //free(output);
    free(key);
    return output;
}
