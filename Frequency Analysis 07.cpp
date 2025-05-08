#include <stdio.h>
#include <string.h>
#define MAX_LEN 500
void count_frequency(char *ciphertext, int freq[256]) {
    for (int i = 0; i < strlen(ciphertext); i++) {
        if (ciphertext[i] != ' ') {
            freq[(int)ciphertext[i]]++;
        }
    }
}
void print_frequencies(int freq[256]) {
    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            printf("Character '%c' appears %d times\n", i, freq[i]);
        }
    }
}
void decrypt_message(char *ciphertext, char *key) {
    for (int i = 0; i < strlen(ciphertext); i++) {
        if (ciphertext[i] != ' ') {
            ciphertext[i] = key[(int)ciphertext[i]];  // Decrypt using the key
        }
    }
    printf("Decrypted message: %s\n", ciphertext);
}
int main() {
    char ciphertext[MAX_LEN] = "53‡‡†305))6*;4826)4‡.)4‡);806*;48†8¶60))85;;]8*;:‡*8†83 (88)5*†;46(;88*96*?;8)*‡(;485);5*†2:*‡(;4956*2(5*—4)8¶8* ;4069285);)6†8)4‡‡;1(‡9;48081;8:8‡1;48†85;4)485†528806*81 (‡9;48;(88;4(‡?34;48)4‡;161;:188;‡?;";
    int freq[256] = {0};
    count_frequency(ciphertext, freq);
    printf("Frequency Analysis of Ciphertext:\n");
    print_frequencies(freq);
    char key[256] = {0};
    key['5'] = 'e';
    key['3'] = 't';
    key['8'] = 'h'; 
    decrypt_message(ciphertext, key);
    return 0;
}
