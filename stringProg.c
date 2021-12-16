#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "strings.h"
int main()
{
    char word[WORD];
    char text[TXT];
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
        while(index < strlen(text) && counter<size && place<strlen(text)) //check if change index to i
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
    char assist[TXT];
    int b = 0;
    first = 1;
    for (int i = 0; i < strlen(text) - 1; i++)
    {
        if (text[i] == reversed(word[0]))
        {
            assist[b++] = text[i];
            for (int j = 1; j < strlen(word); j++)
            {
                i++;
                if ((checkLetter(text[i]) == 0) || (text[i] == reversed(word[j])))
                {
                    assist[b++] = text[i];
                    if ((j == strlen(word) - 1) && (assist[--b] == reversed(word[strlen(word) - 1])))
                    {
                        if (first == 1)
                        {
                            printf("%s", assist);
                            first = 0;
                        }
                        else
                        {
                            printf("~%s", assist);
                        }
                        memset(assist, 0, sizeof(assist));
                        b = 0;
                    }
                }
                else 
                {
                    memset(assist, 0, sizeof(assist));
                    b = 0;
                    break;
                }
            }
            i--;
        } 
        else if (text[i] == reversed(word[strlen(word) - 1]))  
        {
            assist[b++] = text[i];
            for (int j = (strlen(word) - 2); j >= 0; j--)
            {
                i++;
                if ((checkLetter(text[i]) == 0) || (text[i] == reversed(word[j])))
                {
                     assist[b++] = text[i];
                     if ((j == 0) && (assist[--b] == reversed(word[0]))) 
                    {
                        if (first == 1)
                        {
                            printf("%s", assist);
                            first = 0;
                        }
                        else
                        {
                            printf("~%s", assist);
                        }
                        memset(assist, 0, sizeof(assist));
                        b = 0;
                    }
                }
                else
                {
                    memset(assist, 0, sizeof(assist));
                    b = 0;
                    break;
                }
            }
            i--;
        } 
    }
    printf("\n");
    printf("Anagram Sequences: ");
    first=1;
    for(int i=0;i<strlen(text);i++)
    {
        char temp[TXT];
        int index=i;
        int place=0;
        int charcount=0;
        while(i < strlen(text) && place<strlen(text) && charcount<strlen(word))
        {
            temp[place]=text[index];
            if(valid_char(word,temp[place])==1)
                charcount++;
            ++place;
            ++index;
        }
        temp[place]='\0';
        if(isAnagram(temp,word)==1 && valid_char(word,temp[0])==1)
        {
            if(first==1){
                printf("%s",temp);
                first=0;
            }
            else
                printf("~%s",temp);
        }
    }


   

    return 0;
}
