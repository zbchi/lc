/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generateMatrix(int n, int* returnSize, int** returnColumnSizes) 
{
    *returnSize=n;
    //创建数组
    int ** ans=(int **)malloc(sizeof(int*)*n);//二维数组/一维数组的数组/指针
    *returnColumnSizes=(int*)malloc(sizeof(int)*n);//一维数组

    //分配
    for(int i=0;i<n;i++)
    {
        ans[i]=(int*)malloc(sizeof(int)*n);//一维数组
        (*returnColumnSizes)[i]=n;
    }

    //设置每次循环的起始位置
    int startX=0;
    int startY=0;


    while()
    {








        if(n%2==1)
        
    }

}