#include <stdio.h>
#include <ctype.h>

int hexToInt(char *hexStr, int *result) {
    *result = 0;
    int value = 0;

    // Skip optional "0x" or "0X" prefix
    if (*hexStr == '0' && (*(hexStr + 1) == 'x' || *(hexStr + 1) == 'X')) {
        hexStr += 2;
    }

    while (*hexStr) {
        char c = *hexStr;

        if (isdigit(c)) {
            value = c - '0';
        } else if (c >= 'a' && c <= 'f') {
            value = c - 'a' + 10;
        } else if (c >= 'A' && c <= 'F') {
            value = c - 'A' + 10;
        } else {
            // Invalid character for a hexadecimal number
            return -1;
        }

        *result = (*result * 16) + value;
        hexStr++;
    }

    return 0;
}

int main() {
    char *hexStr = "0x1A3F";
    int result;

    if (hexToInt(hexStr, &result) == 0) {
        printf("Hexadecimal string %s as integer: %d\n", hexStr, result);
    } else {
        printf("Invalid hexadecimal string: %s\n", hexStr);
    }

    return 0;
}
