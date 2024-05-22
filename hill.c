#include <stdio.h>
#include <string.h>
#include <ctype.h>

void encryption(char msg[], int key[][3]) {
    int len = strlen(msg);

    // Ensure that the length of the message is divisible by 3
    while (len % 3 != 0) {
        msg[len] = 'X';
        len++;
    }

    // Convert characters to uppercase
    for (int i = 0; i < len; i++) {
        msg[i] = toupper(msg[i]);
    }

    // Encrypt the entire message using the provided key
    for (int i = 0; i < len; i += 3) {
        int ciper[3] = {msg[i] - 'A', msg[i + 1] - 'A', msg[i + 2] - 'A'};
        int encrypted[3] = {0};

        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                encrypted[j] += key[j][k] * ciper[k];
            }
            encrypted[j] %= 26;
        }

        for (int j = 0; j < 3; j++) {
            msg[i + j] = (encrypted[j] + 'A');
        }
    }

    // Ensure null termination of the string
    msg[len] = '\0';

    printf("%s\n", msg);
}

int main() {
    int key[3][3];
    char msg[100];

    printf("Enter the 3x3 matrix key (9 integers): ");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &key[i][j]);
        }
    }

    printf("Enter the message (maximum 99 characters): ");
    scanf("%s", msg);

    printf("The encrypted message is: ");
    encryption(msg, key);

    return 0;
}