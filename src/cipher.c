/** Copyright (C) 2022 CrazylittleJ - All Rights Reserved
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 * Written by CrazylittleJ<me97.littlej@gmail.com>, Feb 2022
 * @brief Stream Cipher Example
 * @author crazylittleJ
 * @date 2022-02-23
 * @version 1.0
 **/

#include <cipher.h>

#define RANGE_ASCII_LOWER_BOUND    0x20    // 32(dec) space
#define RANGE_ASCII_UPPER_BOUND    0x7A    // 122(dec) z
#define RANGE_VALUE                0x5B    // 91(dec) space, 0-9, A-Z, a-z, ...

char theKey;

void deriveKey(char data) {
    int c1, c2 = 0;

    c1 = theKey;

    if (data & 0x4B) {
        data ^= 0x3E;
    } else {
        data += 0x4C;
    }

    c2 = data;

    c1 += c2;

    if (c1 > RANGE_ASCII_UPPER_BOUND)
        c1 = (RANGE_ASCII_LOWER_BOUND) + ((c1 - RANGE_ASCII_UPPER_BOUND) % RANGE_VALUE);

    if (c1 < RANGE_ASCII_LOWER_BOUND)
        c1 = (RANGE_ASCII_UPPER_BOUND) - ((RANGE_ASCII_LOWER_BOUND - c1) % RANGE_VALUE);

    theKey = c1;
}

void resetCipher(const char* key) {
    theKey = 0;

    while (*key) {
        deriveKey(*key);
        key++;
    }
}

void encrypt(const char* plaintext, char* encrypted) {
    int c1, c2 = 0;

    while (*plaintext) {
        c1 = *encrypted;
        c2 = *plaintext;
        c1 = c2 + theKey;
        if (c1 > RANGE_ASCII_UPPER_BOUND)
            c1 = (RANGE_ASCII_LOWER_BOUND) + ((c1  - RANGE_ASCII_UPPER_BOUND) % RANGE_VALUE);
        *encrypted = c1;
        deriveKey(*encrypted);
        encrypted++;
        plaintext++;
    }

    *encrypted = '\0';
}

void decrypt(char * plaintext, const char * encrypted) {
    int c1, c2 = 0;

    while (*encrypted) {
        c1 = *encrypted;
        c2 = *plaintext;
        c2 = c1 - theKey;
        if (c2 < RANGE_ASCII_LOWER_BOUND)
            c2 = (RANGE_ASCII_UPPER_BOUND) - ((RANGE_ASCII_LOWER_BOUND  - c2) % RANGE_VALUE);
        *plaintext = c2;
        deriveKey(*encrypted);
        plaintext++;
        encrypted++;
    }

    *plaintext = '\0';
}
