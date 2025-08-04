#include <stdio.h>

double stringToDouble(char *str) {
    double result = 0.0, decimalPart = 0.0;
    int sign = 1, isDecimal = 0, decimalFactor = 1, i = 0;

    // Handle negative sign
    if (str[0] == '-') {
        sign = -1;
        i++;
    }

    // Convert the string to double
    while (str[i] != '\0') {
        if (str[i] == '.') {
            isDecimal = 1; // Switch to decimal part
        } else if (!isDecimal) {
            result = result * 10 + (str[i] - '0'); // Integer part
        } else {
            decimalPart = decimalPart * 10 + (str[i] - '0');
            decimalFactor *= 10; // Keep track of decimal places
        }
        i++;
    }

    // Combine integer and decimal parts
    result += decimalPart / decimalFactor;

    return result * sign;
}

int main() {
    char str1[50], str2[50];
    double num1, num2, sum;

    printf("Enter the first floating-point number string: ");
    scanf("%s", str1);
    printf("Enter the second floating-point number string: ");
    scanf("%s", str2);

    // Convert strings to doubles
    num1 = stringToDouble(str1);
    num2 = stringToDouble(str2);

    // Calculate the sum
    sum = num1 + num2;

    // Print the result
    printf("The sum of the floating-point numbers is: %.6f\n", sum);

    return 0;
}
