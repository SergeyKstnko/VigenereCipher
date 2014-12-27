/**
* vigenere.c
*
*@author Sergii Kostenko
*
* Implements Vigenere Cipher. 
*
* Usage: ./vigenere any_secret_word
*
* Takes in a secret word from you in the command line and the sentence you would
* like to encrypt. Iterates over letters of the secret words to shift every next
* letter of the message. 
*
**/

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
 
int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Please enter your secret word\n");
        return 1;
    }
    
    //check if all characters of the argv are alphabetical
    for (int i = 0; i < strlen(argv[1]); i++) 
    {
        const char *h = argv[1];
        if (isalpha(h[i]))  
        {  
        }
        else
        {
            printf("%c is not a letter\n", h[i]);  
            return 1;
        }
    }
    //finish cheching every character for alphabetical


        //get string from the user to cipher
        string s = GetString();
        int k, count = 0;
        const char *h = argv[1];
        //check and shift only letters
        for (int i = 0; i < strlen(s); i++)
        {
            if (isalpha(s[i]))
            {
                //finding j for Kj
                int j = fmod(count, strlen(argv[1]));
                if (isupper(h[j]))
                {
                    k = h[j] - 65;
                }
                else
                {
                    k = h[j] - 97;
                }
                
                //encipher every letter
                int l = s[i], result;
                //find remainder
                if (isupper(s[i]))
                {
                    //if the shift is bigger than alphabet then wrap up to the beggining
                    if ( (l + fmod(k,26)) > 90)
                    { 
                        result = fmod((l + fmod(k,26)),91) + 65; 
                    }
                    else
                    { 
                        result = l + fmod(k,26); 
                    }
                }
                else
                {
                    if ( (l + fmod(k,26)) > 122 )
                    { 
                        result = fmod((l + fmod(k,26)),123) + 97; 
                    }
                    else
                    { 
                        result = l + fmod(k,26); 
                    }
                }
                printf("%c", result);
                count++;
               
            }
            //print non-alphabetic characters
            else
            {
                printf("%c", s[i]);
            }
        }
        printf("\n");
}


