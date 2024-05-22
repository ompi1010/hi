#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define ALPHABET_SIZE 26

char *encrypt(char *plaintext, char *key);
char *decrypt(char *ciphertext, char *key);

int main() {
    char plaintext[100], key[ALPHABET_SIZE] = "QWERTYUIOPASDFGHJKLZXCVBNM", ciphertext[100];
    
    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    
    // Remove newline character
    plaintext[strcspn(plaintext, "\n")] = '\0';

    strcpy(ciphertext, encrypt(plaintext, key));
    printf("Encrypted text: %s\n", ciphertext);
    
    printf("Decrypted text: %s\n", decrypt(ciphertext, key));

    return 0;
}

char *encrypt(char *plaintext, char *key) {
    static char ciphertext[100];
    int i;
    
    for (i = 0; plaintext[i] != '\0'; i++) {
        if (isalpha(plaintext[i])) {
            char base = isupper(plaintext[i]) ? 'A' : 'a';
            ciphertext[i] = key[plaintext[i] - base];
        } else {
            ciphertext[i] = plaintext[i];
        }
    }
    ciphertext[i] = '\0';
    return ciphertext;
}

char *decrypt(char *ciphertext, char *key) {
    static char plaintext[100];
    int i;
    
    for (i = 0; ciphertext[i] != '\0'; i++) {
        if (isalpha(ciphertext[i])) {
            char base = isupper(ciphertext[i]) ? 'A' : 'a';
            plaintext[i] = 'A' + (strchr(key, toupper(ciphertext[i])) - key);
            if (islower(ciphertext[i]))
                plaintext[i] = tolower(plaintext[i]);
        } else {
            plaintext[i] = ciphertext[i];
        }
    }
    plaintext[i] = '\0';
    return plaintext;
}
