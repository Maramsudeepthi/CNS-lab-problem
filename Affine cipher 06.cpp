#include <stdio.h>
int mod_inverse(int a, int m) {
    for (int x = 1; x < m; x++) if ((a * x) % m == 1) return x;
    return -1;
}
int main() {
    int a = 5, b = 8, choice;
    printf("Affine Cipher\n1. Encrypt\n2. Decrypt\nEnter choice: ");
    scanf("%d", &choice);
    getchar();

    if (choice == 1) {
        printf("Enter plain text (A-Z): ");
        char c;
        while ((c = getchar()) != '\n') if (c >= 'A' && c <= 'Z') printf("%c", (a * (c - 'A') + b) % 26 + 'A');
    } else if (choice == 2) {
        int a_values[] = {1, 3, 5, 7, 9, 11, 15, 17, 19, 21, 23, 25};
        for (int i = 0; i < 12; i++) for (int j = 0; j < 26; j++) {
            if ((a_values[i] * 4 + j) % 26 == 1 && (a_values[i] * 19 + j) % 26 == 20) {
                a = a_values[i]; b = j; break;
            }
        }
        printf("Guessed keys: a = %d, b = %d\nEnter cipher text (A-Z): ", a, b);
        char c;
        while ((c = getchar()) != '\n') if (c >= 'A' && c <= 'Z') printf("%c", mod_inverse(a, 26) * (c - 'A' - b + 26) % 26 + 'A');
    } else {
        printf("Invalid choice.\n");
    }
    return 0;
}
