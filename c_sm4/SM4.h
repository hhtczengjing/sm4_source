//
//  SM4.h
//  Demo
//
//  Created by zengjing on 2017/6/10.
//  Copyright © 2017年 blog.devzeng.com. All rights reserved.
//

#ifndef SM4_h
#define SM4_h

#define SM4_ENCRYPT     1
#define SM4_DECRYPT     0

#ifdef __cplusplus
extern "C" {
#endif

void SM4_KeySchedule(unsigned char MK[],  unsigned int rk[]);

void SM4_Encrypt(unsigned char MK[],unsigned char PlainText[], unsigned char CipherText[]);

void SM4_Decrypt(unsigned char MK[],unsigned char CipherText[], unsigned char PlainText[]);
    
#ifdef __cplusplus
}
#endif

#endif /* SM4_h */
