#include <iostream>
#include <cstring>
#include "crypt.h"
#include <cmath>

using namespace std;

void crypt(char *word, int cryptKey)
{
    int wordLen = strlen(word);
    for (int i = 0; i < wordLen; i++)
    {
        char cryptedChar = (char)((((word[i] - 'a') + cryptKey) % 26) + 'a');
        word[i] = cryptedChar;
    }
}

void decrypt(char *word, int cryptKey)
{
    int wordLen = strlen(word);
    for (int i = 0; i < wordLen; i++)
    {
        int subtraction = (((word[i] - 'a') - (cryptKey % 26)));
        char decryptedChar = subtraction < 0 ? (char)(26 + subtraction + 'a') : (char)(subtraction + 'a');
        word[i] = decryptedChar;
    }
}