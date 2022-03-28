/** Copyright (C) 2022 CrazylittleJ - All Rights Reserved
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 * Written by CrazylittleJ<me97.littlej@gmail.com>, Feb 2022
 * @brief Stream Cipher Example
 * @author crazylittleJ
 * @date 2022-02-25
 * @version 1.0
 **/

#include <main.h>

int main(void) {
    char* rootKey = "Yak tebe ne liubyty";
    char* message = "The password is \"KGB257CIA1902\"";
    char encrypted[40];
    char decrypted[40];

    printf("plaintext message : %s\n", message);

    resetCipher(rootKey);
    encrypt(message, encrypted);

    printf("encrypted message : %s\n", encrypted);

    resetCipher(rootKey);
    decrypt(decrypted, encrypted);

    printf("decrypted message : %s\n", decrypted);
    return 0;
}
