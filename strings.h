#ifndef _STRINGS_H_
#define _STRINGS_H_
#define TXT 1024
#define WORD 30
int isEnd(char c);
int gimatric(char* c);
int checkLetter(char c);
char reversed(char given);
int containsReversed(char word[], char given);
int contains(char word[],char c);
int isAnagram(char word[],char c[]);
int valid_char(char word[],char c);
#endif
