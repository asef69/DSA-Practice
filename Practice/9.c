#include <stdio.h>

int stringToInt(char *str) {
    int num = 0, sign = 1, i = 0;

    // Check for negative sign
    if (str[0] == '-') {
        sign = -1;
        i++;
    }

    // Convert each character to an integer
    while (str[i] != '\0') {
        num = num * 10 + (str[i] - '0');
        i++;
    }

    return sign * num;
}

int main() {
    char str1[20], str2[20], str3[20], str4[20];
    int num1, num2, num3, num4, sum;

    printf("Enter first integer string: ");
    scanf("%s", str1);
    printf("Enter second integer string: ");
    scanf("%s", str2);
    printf("Enter third integer string: ");
    scanf("%s", str3);
    printf("Enter fourth integer string: ");
    scanf("%s", str4);

    // Convert strings to integers
    num1 = stringToInt(str1);
    num2 = stringToInt(str2);
    num3 = stringToInt(str3);
    num4 = stringToInt(str4);

    // Calculate the sum
    sum = num1 + num2 + num3 + num4;

    printf("The sum of the integers is: %d\n", sum);

    return 0;
}
