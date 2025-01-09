#include <stdio.h>
#include<string.h>
 
int main() {    
    char inputString[200];
    printf("Enter input string:\n");
    fgets(inputString, 200, stdin);
    inputString[strcspn(inputString, "\n")]='\0';
    
    char subString[200];
    char replaceString[200];
    
    printf("enter substring:\n");
    scanf("%s", subString);
    int length = strlen(subString);
    int found = strstr(inputString, subString)-inputString;
    if( strstr(inputString, subString) == NULL){
        printf("The substring does not exist in the string");
        return 0;
    }
    
    printf("enter replacement string:\n");
    scanf("%s", replaceString);
    
    printf("The input string after replacement is:\n");
    int index=0;
    while(inputString[index] != '\0'){
        if(index != found){
            printf("%c", inputString[index]);
        }else{
            printf("%s ", replaceString);
            index += length;
        }
        index++;
    }
    return 0;
}
