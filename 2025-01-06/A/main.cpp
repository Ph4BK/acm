#include <bits/stdc++.h>
using namespace std;

int main(){
    int newWord = 0;
    unordered_set<string>dictionary;
    char* novel = (char*)malloc(sizeof(char) * 5000000);
    gets(novel);
    char* word = strtok(novel, " ");
    while (word) {
        if ('A' <= word[0] && word[0] <= 'Z') {
            word[0] = word[0] - 'A' + 'a';
        }
        int len = strlen(word);
        if (word[len - 1] == ',' || word[len - 1] == '.' || word[len - 1] == '!' || word[len - 1] == '?') {
            word[len - 1] = '\0';
        }
        if (dictionary.contains(word) == 0) {
            newWord++;
            dictionary.insert(word);
        }
        word = strtok(nullptr, " ");
    }
    int n;
    scanf("%d", &n);
    getchar();
    unordered_set<string>wordlist;
    char temp[2200];
    gets(temp);
    char* know = strtok(temp, " ");
    while (know) {
        if (wordlist.contains(know) == 0) {
            wordlist.insert(know);
            if (dictionary.contains(know)) {
                newWord--;
            }
        }
        know = strtok(nullptr, " ");
    }
    printf("%d\n", newWord);
    free(novel);
    return 0;
}
