int lengthOfLongestSubstring(char* s) {
    if(strlen(s)==0)
    return 0;
    if(strlen(s)==1)
    return 1;
    char*p1=s;
    char*p2=s+1;
    int max=1;
    while(1)
    {
        char*tmp=p1;
        int q=0;
        while(p2-tmp!=0)
        {
            if(*tmp==*p2)
            {   
                q=1;
                break;
            }
            tmp++;
        }
        if(q==0)
        {
            if(p2-p1+1>max)
                max=p2-p1+1;
            if(p2-s+1!=strlen(s))
                p2++;
            else
            break;
        }
        else
        p1++;
    }
    return max;
}