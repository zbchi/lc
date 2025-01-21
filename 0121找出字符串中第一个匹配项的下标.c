int strStr(char* haystack, char* needle) {
    char* result =NULL;
    result = strstr(haystack,needle);
    if(result==NULL)
    return -1;
    return result - haystack+1;
}