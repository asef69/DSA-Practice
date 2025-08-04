#include<stdio.h>
#include<string.h>
int Equal(char *S, char *T){
     int lenS = strlen(S), lenT = strlen(T);
    if (lenS != lenT) {
        return 0;
    }
    int freqS[26] = {0}, freqT[26] = {0};
    for (int i = 0; i < lenS; i++) {
        freqS[S[i] - 'a']++;
        freqT[T[i] - 'a']++;
    }

    for (int i = 0; i < 26; i++) {
        if (freqS[i] != freqT[i]) {
            return 0;
        }
    }
    return 1;
}
int main(){
     char S[1001], T[1001];
    scanf("%s", S);
    scanf("%s", T);
    if (Equal(S, T)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

}