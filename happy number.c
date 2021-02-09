#include<stdio.h>
main()
{
    int n,i,temp=0,sum=0,a=0;
    printf("enter your number");
    scanf("%d",&n);

    while (sum!=1 && sum!=4)
    {  sum=0;
                while(n>0){
                temp=n%10;
                sum+=(temp*temp);
                n=n/10;



        }n=sum;

    }

    while(n){
            temp=n%10;
            sum=sum+(temp*temp);
            n=n/10;



    }
    if(sum==1){
        printf("Number is happy number");
    }
    else
    {
        printf("Number is not happy number");

    }
}
