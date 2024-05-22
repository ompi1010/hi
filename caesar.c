#include <stdio.h>

// Function to perform encryption using Caesar cipher
void encrypt(char plaintext[], int key) {
    char ch;
    int i;

    for(i = 0; plaintext[i] != '\0'; ++i) {
        ch = plaintext[i];

        if(ch >= 'a' && ch <= 'z') {
            ch = ch + key;

            if(ch > 'z') {
                ch = ch - 'z' + 'a' - 1;
            }

            plaintext[i] = ch;
        }
        else if(ch >= 'A' && ch <= 'Z') {
            ch = ch + key;

            if(ch > 'Z') {
                ch = ch - 'Z' + 'A' - 1;
            }

            plaintext[i] = ch;
        }
    }
}

// Function to perform decryption using Caesar cipher
void decrypt(char ciphertext[], int key) {
    char ch;
    int i;

    for(i = 0; ciphertext[i] != '\0'; ++i) {
        ch = ciphertext[i];

        if(ch >= 'a' && ch <= 'z') {
            ch = ch - key;

            if(ch < 'a') {
                ch = ch + 'z' - 'a' + 1;
            }

            ciphertext[i] = ch;
        }
        else if(ch >= 'A' && ch <= 'Z') {
            ch = ch - key;

            if(ch < 'A') {
                ch = ch + 'Z' - 'A' + 1;
            }

            ciphertext[i] = ch;
        }
    }
}

int main() {
    char plaintext[100];
    int key = 3; // Key is set to 3 by default

    printf("Enter text to encrypt: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    // Encrypt the plaintext with the specified key
    encrypt(plaintext, key);
    printf("Encrypted text: %s\n", plaintext);

    // Decrypt the encrypted text with the same key
    decrypt(plaintext, key);
    printf("Decrypted text: %s\n", plaintext);

    return 0;
}
