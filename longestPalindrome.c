#include <stdio.h>

void createSubstring(char *string, int startIndex, int length, int totalLength) {
   char result[length + 1];
   int resultIndex = 0;
   for (int currentIndex = startIndex; currentIndex < startIndex + length; currentIndex++) {
       result[resultIndex] = string[currentIndex];
       resultIndex++;
   }
   result[length] = '\0';
   printf("%s\n", result);
}

void findLongestPalindrome(char *string, int totalLength) {
   int maxPalindromeLength = 1;
   int startOfPalindrome = 0;

   for (int centerIndex = 0; centerIndex < totalLength; centerIndex++) {
       int leftPointer = centerIndex, rightPointer = centerIndex;
       while (leftPointer >= 0 && rightPointer < totalLength && string[leftPointer] == string[rightPointer]) {
           leftPointer--;
           rightPointer++;
       }
       if (rightPointer - leftPointer - 1 > maxPalindromeLength) {
           maxPalindromeLength = rightPointer - leftPointer - 1;
           startOfPalindrome = leftPointer + 1;
       }
   }

   for (int centerIndex = 0; centerIndex < totalLength - 1; centerIndex++) {
       int leftPointer = centerIndex, rightPointer = centerIndex + 1;
       while (leftPointer >= 0 && rightPointer < totalLength && string[leftPointer] == string[rightPointer]) {
           leftPointer--;
           rightPointer++;
       }
       if (rightPointer - leftPointer - 1 > maxPalindromeLength) {
           maxPalindromeLength = rightPointer - leftPointer - 1;
           startOfPalindrome = leftPointer + 1;
       }
   }

   createSubstring(string, startOfPalindrome, maxPalindromeLength, totalLength);
}

int stringLen(char* inputString){
    int countChar = 0;
    int index = 0;
    while(inputString[index] != '\0'){
        countChar ++;
        index++;
    }
    return countChar;
}

int main() {
   char inputString[1000];
   fgets(inputString, 1000, stdin);
   int stringLength = stringLen(inputString);
   if (inputString[stringLength - 1] == '\n') {
       inputString[stringLength - 1] = '\0';
   }
   stringLength = stringLen(inputString);
   findLongestPalindrome(inputString, stringLength);
   return 0;
}
