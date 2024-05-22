#include <stdio.h>
#include <string.h>
#include <ctype.h> // Added for toupper()

#define SIZE 6 // Increased to prevent buffer overflow

char table[SIZE][SIZE];

// Function to prepare the key by removing duplicate characters
void prepareKey(char *key) {
    int i, j, k;
    char temp[26] = {0};
    j = 0;
    for (i = 0; key[i] != '\0'; ++i) {
        if (!temp[toupper(key[i]) - 'A'] && key[i] != ' ') {
            table[j / SIZE][j % SIZE] = toupper(key[i]);
            temp[toupper(key[i]) - 'A'] = 1;
            ++j;
        }
    }
    for (k = 'A'; k <= 'Z'; ++k) {
        if (k != 'J' && !temp[k - 'A']) {
            table[j / SIZE][j % SIZE] = k;
            ++j;
        }
    }
}

// Function to find the position of a character in the table
void findPosition(char ch, int *row, int *col) {
    int i, j;
    if (ch == 'J')
        ch = 'I';
    for (i = 0; i < SIZE; ++i) {
        for (j = 0; j < SIZE; ++j) {
            if (table[i][j] == toupper(ch)) {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}

// Function to encrypt a pair of characters
void encryptPair(char a, char b) {
    int row1, col1, row2, col2;
    findPosition(a, &row1, &col1);
    findPosition(b, &row2, &col2);
    if (row1 == row2) {
        printf("%c%c", table[row1][(col1 + 1) % SIZE], table[row2][(col2 + 1) % SIZE]);
    } else if (col1 == col2) {
        printf("%c%c", table[(row1 + 1) % SIZE][col1], table[(row2 + 1) % SIZE][col2]);
    } else {
        printf("%c%c", table[row1][col2], table[row2][col1]);
    }
}

// Function to decrypt a pair of characters
void decryptPair(char a, char b) {
    int row1, col1, row2, col2;
    findPosition(a, &row1, &col1);
    findPosition(b, &row2, &col2);
    if (row1 == row2) {
        printf("%c%c", table[row1][(col1 - 1 + SIZE) % SIZE], table[row2][(col2 - 1 + SIZE) % SIZE]);
    } else if (col1 == col2) {
        printf("%c%c", table[(row1 - 1 + SIZE) % SIZE][col1], table[(row2 - 1 + SIZE) % SIZE][col2]);
    } else {
        printf("%c%c", table[row1][col2], table[row2][col1]);
    }
}

// Function to remove whitespace from the input message
void removeWhitespace(char *text) {
    int i, j = 0;
    for (i = 0; text[i] != '\0'; ++i) {
        if (!isspace(text[i])) {
            text[j++] = text[i];
        }
    }
    text[j] = '\0';
}

// Function to encrypt the plaintext
void encrypt(char *text) {
    int i;
    for (i = 0; i < strlen(text); i += 2) {
        if (text[i] == text[i + 1]) {
            text[i + 1] = 'X';
        }
        encryptPair(text[i], text[i + 1]);
    }
}

// Function to decrypt the ciphertext
void decrypt(char *text) {
    int i;
    for (i = 0; i < strlen(text); i += 2) {
        decryptPair(text[i], text[i + 1]);
    }
}

int main() {
    char key[27]; // Increased size to accommodate the null terminator
    char message[1001]; // Increased size to accommodate the null terminator

    printf("Enter the key (no spaces, all uppercase letters): ");
    fgets(key, sizeof(key), stdin);
    removeWhitespace(key);

    printf("Enter the message to be encrypted: ");
    fgets(message, sizeof(message), stdin);
    removeWhitespace(message); // Remove whitespace from the message

    // Prepare the key
    prepareKey(key);

    // Encrypt the message
    printf("Encrypted message: ");
    encrypt(message);

    // Decrypt the message
    printf("\nDecrypted message: ");
    decrypt(message);

    return 0;
}