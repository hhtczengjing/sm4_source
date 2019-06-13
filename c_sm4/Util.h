//
//  Util.h
//  Demo
//
//  Created by zengjing on 2017/6/10.
//  Copyright © 2017年 blog.devzeng.com. All rights reserved.
//

#ifndef Util_h
#define Util_h

unsigned char * pd_hex2Str(unsigned char arrB[], int length);

unsigned char pd_hex2Char(int n);

int pd_str2Int(unsigned char *str);

//加密
unsigned char * pd_sm4_encrypt(unsigned char text[], int length, unsigned char *sm4_crypt_key, unsigned int key_length);

//解密
unsigned char * pd_sm4_decrypt(unsigned char text[], int length, unsigned char *sm4_crypt_key, unsigned int key_length);

#endif /* Util_h */
