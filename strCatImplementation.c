#include <stdio.h>

int strLen(char *inputStr)
{
    int length = 0;
    while (inputStr[length] != '\0')
    {
        length++;
    }
    return length;
}

void strCat(char *strSrc)
{
    char strDest[100];
    printf("Enter the destination string\n");
    fgets(strDest, 100, stdin);

    int lenDest = strLen(strDest);
    if (lenDest > 0 && strDest[lenDest - 1] == '\n')
    {
        strDest[lenDest - 1] = '\0';
    }

    lenDest = strLen(strDest);
    int count = strLen(strSrc);

    for (int index = 0; index < lenDest; index++)
    {
        strSrc[count + index] += strDest[index];
    }

    strSrc[count + lenDest] = '\0';
}

int main()
{
    char strSrc[1000];
    printf("Enter the source string\n");
    fgets(strSrc, 1000, stdin);

    int lenSrc = strLen(strSrc);
    if (lenSrc > 0 && strSrc[lenSrc - 1] == '\n')
    {
        strSrc[lenSrc - 1] = '\0';
    }
  
    strCat(strSrc);
    printf("The concatenated string is: \n");
    printf("%s", strSrc);

    return 0;
}
