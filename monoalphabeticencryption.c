#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to perform monoalphabetic encryption
void monoalphabeticEncrypt(char *plaintext, char *key) {
    int i;
    for (i = 0; plaintext[i]; i++) {
        if (isalpha(plaintext[i])) {
            char base = islower(plaintext[i]) ? 'a' : 'A';
            int position = tolower(plaintext[i]) - 'a';
            plaintext[i] = islower(plaintext[i]) ? tolower(key[position]) : toupper(key[position]);
        }
    }
}

int main() {
    char plaintext[100];
    char key[26];  // Key should contain all 26 letters in a different order

    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    printf("Enter the key (26 unique letters): ");
    fgets(key, sizeof(key), stdin);

    // Remove newlines from input
    plaintext[strcspn(plaintext, "\n")] = '\0';
    key[strcspn(key, "\n")] = '\0';

    if (strlen(key) != 26) {
        printf("Error: Key must contain 26 unique letters.\n");
        return 1;
    }

    // Check for duplicate letters in the key
    for (int i = 0; i < 25; i++) {
        for (int j = i + 1; j < 26; j++) {
            if (key[i] == key[j]) {
                printf("Error: Key contains duplicate letters.\n");
                return 1;
            }
        }
    }

    monoalphabeticEncrypt(plaintext, key);

    printf("Encrypted text: %s\n", plaintext);

    return 0;
}
