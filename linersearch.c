
#include <stdio.h>
#define MAX 5

int  linearSearch(int *a,int n)
{
    int i,pos=-1;

    for(i=0;i< MAX; i++)
    {
        if(a[i]==n)
        {
            pos++;
            break;
        }
    }
    return pos;
}

int main()
{
    int i,n,arr[MAX];
    int num;
    int position;

    printf("\nEnter array elements 5:\n");
    for(i=0;i< MAX;i++)
        scanf("%d",&arr[i]);

    printf("\nNow enter element to search :");
    scanf("%d",&num);
    position=linearSearch(arr,num);

    if(position==-1)
        printf("Element not found.\n");
    else
        printf("Element found\n");

    return 0;
}
