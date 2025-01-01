#include <stdio.h>
long long int modularExponentiation(long long int base, long long int exponent, long long int modulus) {
    long long int result = 1;
    base = base % modulus; 
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % modulus;
        }
        base = (base * base) % modulus;
        exponent = exponent / 2;
    }
    return result;

}

int main() {
    long long int base, exponent, modulus;
    printf("Enter Base (B): ");
    scanf("%lld", &base);
    printf("Enter Exponent (N): ");
    scanf("%lld", &exponent);
    printf("Enter Modulus (M): ");
    scanf("%lld", &modulus);
    if (modulus <= 1) {
        printf("Modulus M should be greater than 1.\n");
        return 1;
    }
    printf("Result: %lld\n", modularExponentiation(base, exponent, modulus));
    return 0;

}
