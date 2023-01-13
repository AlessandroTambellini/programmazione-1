int strlen(const char *s)
{
    int r;
    for (r = 0; s[r] != '\0'; r++)
        ;
    return r;
}

void strcpy(char *strd, const char *strs)
{
    int i;
    for (i = 0; strs[i] != '\0'; i++)
    {
        strd[i] = strs[i];
    }
    strd[i] = '\0';
}

// TODO: strcat