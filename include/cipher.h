/** Copyright (C) 2022 CrazylittleJ - All Rights Reserved
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 * Written by CrazylittleJ<me97.littlej@gmail.com>, Feb 2022
 * @brief Stream Cipher Example
 * @author crazylittleJ
 * @date 2022-02-23
 * @version 1.0
 **/

#ifndef CIPHER_H_
#define CIPHER_H_

#include <stdio.h>
#include <stdlib.h>

void deriveKey(char data);
void resetCipher(const char * key);
void encrypt(const char * plaintext, char * encrypted);
void decrypt(char * plaintext, const char * encrypted);

#endif  // CIPHER_H_
