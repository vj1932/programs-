#include<stdio.h>
main()
{
    int l,u,x,i,flag=0;
    printf("enter two number");
    scanf("%d%d",&l,&u);
    for(x=l+1;x<u;x++)
    {
        for(i=2;i<x;i++)
        {

            if(x%i==0)
            {
                flag=1;
                break;
            }
             if(x%i!=0)
            {
                flag=0;


            }

        }
        if(flag==0)
        {


        printf("%d\n",x);}
    }
}
