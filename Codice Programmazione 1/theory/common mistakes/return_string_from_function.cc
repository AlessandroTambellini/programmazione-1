#include <cstring>

char *crypt(char word[], int cryptKey)
{
    int wordLen = strlen(word);
    char cryptedWord[wordLen];
    for (int i = 0; i < wordLen; i++)
    {
        char cryptedChar = (char)((((word[i] - 'a') + cryptKey) % 26) + 'a');
        cryptedWord[i] = cryptedChar;
    }
    return cryptedWord; // this address is deleted once the fuction is executed!!!
}

int main()
{
    char buffer[256];
    int cryptKey = 34;
    /* buffer = crypt(buffer, cryptKey); */ // See comment above
}