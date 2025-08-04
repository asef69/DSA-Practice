#include <stdio.h>


int myStrlen(char s[100]) {
    int length = 0;
    while (s[length] != '\0') {
        length++;
    }
    return length;
}


void myStrrev(char s[100]) {
    int start = 0, end = myStrlen(s) - 1;
    char temp;
    while (start < end) {
       
        temp = s[start];
        s[start] = s[end];
        s[end] = temp;
        start++;
        end--;
    }
}


int myStrcmp(char s[100], char t[100]) {
    int i = 0;
    while (s[i] != '\0' && t[i] != '\0') {
        if (s[i] != t[i]) {
            return s[i] - t[i]; 
        }
        i++;
    }
  
    return s[i] - t[i];
}


void myStrcpy(char to[100], char from[100]) {
    int i = 0;
    while (from[i] != '\0') {
        to[i] = from[i];
        i++;
    }
    to[i] = '\0'; 
}


void myStrcat(char s[100], char t[100], char dest[100]) {
    int i = 0, j = 0;
    while (s[i] != '\0') {
        dest[i] = s[i];
        i++;
    }
    while (t[j] != '\0') {
        dest[i] = t[j];
        i++;
        j++;
    }
    dest[i] = '\0';
}

void printString(char s[100]) {
    printf("%s\n", s);
}

int main() {
    char str1[100], str2[100], result[100];
    

    printf("Enter first string: ");
    fgets(str1, sizeof(str1), stdin);
    str1[myStrlen(str1) - 1] = '\0';  
    
    printf("Enter second string: ");
    fgets(str2, sizeof(str2), stdin);
    str2[myStrlen(str2) - 1] = '\0';  

   
    printf("Length of first string: %d\n", myStrlen(str1));
    printf("Length of second string: %d\n", myStrlen(str2));
    
    
    myStrrev(str1);
    printf("Reversed first string: ");
    printString(str1);
    
    
    int cmpResult = myStrcmp(str1, str2);
    if (cmpResult == 0) {
        printf("The strings are equal.\n");
    } else if (cmpResult < 0) {
        printf("First string is lexicographically smaller.\n");
    } else {
        printf("First string is lexicographically greater.\n");
    }
    
   
    myStrcpy(result, str1);
    printf("Copied string (str1 to result): ");
    printString(result);
    
    
    myStrcat(str1, str2, result);
    printf("Concatenated string (str1 + str2): ");
    printString(result);
    
    return 0;
}
