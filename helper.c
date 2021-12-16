#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "strings.h"
int valid_char(char word[], char c)
{
    if(c==' ')
        return 0;
    return contains(word,c);
}
int contains(char word[],char c)
{
    if(c==' ')
        return 1;
    for(int i=0;i<strlen(word);i++)
    {
        if(word[i]==c)
            return 1;
    }
    return 0;
}
int isAnagram(char word[],char c[])
{
    char anagramed[WORD];
    for(int i=0;i<strlen(c);i++)
    {
        if(contains(word,c[i])==0)
            return 0;
    }
    int index=0;
    for(int i=0;i<strlen(c);i++)
    {
        if(c[i]!=' ')
            anagramed[index++]=c[i];
    }
    anagramed[index]='\0';
    if(strlen(anagramed)!=strlen(word))
        return 0;
    int abc1[26];
    int abc2[26];
    memset(abc1,0,sizeof(abc1));
    memset(abc2,0,sizeof(abc2));
    for(int i=0;i<strlen(word);i++)
    {
        if(word[i]>='a' && word[i]<='z')
            abc1[word[i]-'a']++;
        else
            abc1[word[i]-'a']++;

        if(anagramed[i]>='a' && anagramed[i]<='z')
            abc2[anagramed[i]-'a']++;
        else
            abc2[anagramed[i]-'a']++; 
    }
    for(int i=0;i<26;i++)
    {
        if(abc1[i]!=abc2[i])
            return 0;
    }
    return 1;
}
int isEnd(char c)
{
    if(c!='\0' && c!='\t' && c!='\n')
    {
        return 1;
    }
    return 0;
}
int gimatric(char *c)
{
    int i=0;
    int counter=0;
    while(c[i]){
    if(((c[i]>='a' && c[i]<='z') || (c[i]>='A' && c[i]<='Z')))
    {

       if(c[i]>='a' && c[i]<='z')
    {
        counter+= c[i]-'a'+1;
    }
    else{
        counter+= c[i]-'A'+1;
    }
    }
    else{
        counter+=0;
    }
    i++;
    }
    return counter;
}
int checkLetter(char c)
{
    if(c>='A' && c<='Z')
        return 1;
    if(c>='a' && c<='z')
        return 1;
    return 0;
}

char reversed(char given)
{
    if (given >= 'A' && given <= 'Z')
    {
        int num = ((int)given + 26) - 2 * ((int)given - 64) + 1;
        return (char)num;
    }
    else if (given >= 'a' && given <= 'z')
    {
        int num = ((int)given + 26) - 2 * ((int)given - 96) + 1;
        return (char)num;
    }
    else return given;
}

int containsReversed(char word[], char given)
{
    for (int i = 0; i < strlen(word); i++)
    {
        if (word[i] == reversed(given))
            return 1;
    }
    return 0;
}