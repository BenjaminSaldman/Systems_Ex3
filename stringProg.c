#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TXT 1024
#define WORD 30
int isEnd(char c);
int gimatric(char* c);
int checkLetter(char c);
int main()
{
    char word[WORD];
    char text[TXT];
    char a[TXT];
    char in;
    int index=0;   
    scanf("%s",word);
    index=0;
    scanf("%c",&in);
    while(in!='~')
    {
        scanf("%c",&in);
        text[index++]=in;
    }
    text[index]='\0';
    int size=0;
    size=gimatric(word);
    int first=1;
    printf("Gematria Sequences: ");
    for(int i=0;i<strlen(text);i++)
    {
        char temp[TXT];
        int counter=0;
        int index=i;
        int place=0;
        while(i < strlen(text) && counter<size && place<strlen(text))
        {
            temp[place++]=text[index++];
            temp[place]='\0';
            counter=gimatric(temp);
        }
        if(counter==size && checkLetter(temp[0])==1)
        {
            if(first==1){
                printf("%s",temp);
                first=0;
            }
            else{
                printf("~%s",temp);
            }
        }
    }
    printf("\n");
    printf("Atbash Sequences: ");

   

    return 0;
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
