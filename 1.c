#include<stdio.h>
#include<math.h>
#include<stdbool.h>
int strStr(char* haystack, char* needle) {
    char* result =NULL;
    result = strstr(haystack,needle);
    if(result==NULL)
    return -1;
    return result - haystack+1;
}

int main()
{
   printf("%d",strStr("sadbutsad","sad"));
   return 0;
}