#include <stdio.h>
#include <string.h>

void columnar_Transposition_Encrypt(char message[], char key[]) {
    int message_Len = strlen(message);
    int keyLen = strlen(key) - 1; // Exclude the newline character from the key length
    int rows = (message_Len + keyLen - 1) / keyLen;
    char transpositionTable[rows][keyLen];

    int i, j, k = 0;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < keyLen; j++) {
            if (k < message_Len)
                transpositionTable[i][j] = message[k++];
            else
                transpositionTable[i][j] = ' ';
        }
    }

    for (i = 0; i < keyLen; i++) {
        int col = key[i] - '1';
        for (j = 0; j < rows; j++) {
            printf("%c", transpositionTable[j][col]);
        }
    }
    printf("\n");
}

int main() {
    char message[100], key[100];
    printf("Enter the message to encrypt: ");
    fgets(message, sizeof(message), stdin);
    printf("Enter the key for columnar transposition: ");
    fgets(key, sizeof(key), stdin);

    message[strcspn(message, "\n")] = '\0';
    key[strcspn(key, "\n")] = '\0';

    printf("\nEncrypted message: ");
    columnar_Transposition_Encrypt(message, key);
    return 0;
}

