bool isPalindrome(int x) {
    if(x<0)
    return false;
    int tmp=x;
    int result=0;

    int e=0;
    while(tmp>0)
    {
        tmp/=10;
        e++;
    }
    tmp=x;
    while(tmp>0)
    {
        result+=(tmp%10)*pow(10,e-1);
        tmp/=10;
        e--;
    }
    if(result==x)
    return true;
    else
    return false;
}