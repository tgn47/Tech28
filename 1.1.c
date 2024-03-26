#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Function to check the validity of the credit card number using the Luhn algorithm
bool checkValidity(const char *cardNumber) {
    int length = strlen(cardNumber);
    int sum = 0;
    bool isSecond = false;

    for (int i = length - 1; i >= 0; i--) {
        int digit = cardNumber[i] - '0';

        if (isSecond) {
            digit *= 2;
            if (digit > 9) {
                digit -= 9;
            }
        }

        sum += digit;
        isSecond = !isSecond;
    }

    return (sum % 10 == 0);
}

int main() {
    char cardNumber[20];

    // Input the credit card number from the user
    printf("Enter the credit card number: ");
    scanf("%s", cardNumber);

    // Check the validity of the credit card number
    if (!checkValidity(cardNumber)) {
        printf("INVALID\n");
        return 0;
    }

    // Determine the type of credit card based on its length and starting digits
    int length = strlen(cardNumber);
    if (length == 15 && (strncmp(cardNumber, "34", 2) == 0 || strncmp(cardNumber, "37", 2) == 0)) {
        printf("AMEX\n");
    } else if (length == 16 && (strncmp(cardNumber, "51", 2) == 0 || strncmp(cardNumber, "52", 2) == 0 ||
                                strncmp(cardNumber, "53", 2) == 0 || strncmp(cardNumber, "54", 2) == 0 ||
                                strncmp(cardNumber, "55", 2) == 0)) {
        printf("MASTERCARD\n");
    } else if ((length == 13 || length == 16) && cardNumber[0] == '4') {
        printf("VISA\n");
    } else {
        printf("INVALID\n");
    }

    return 0;
}