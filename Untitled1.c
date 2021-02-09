#include<stdio.h>
main()
{
    int i,j,a[i][j],b[i][j],c[i][j];
    printf("enter 9 number for first metrix");
    for(i=0;i<=2;i++)
    {
      for(j=0;j<=2;j++)
        scanf("%d",&a[i][j]);
    }

     printf("enter 9 number for second metrix");
    for(i=0;i<=2;i++){
        for(j=0;j<=2;j++)
        scanf("%d",&b[i][j]);}
        for(i=0;i<=2;i++)
        {
            for(j=0;j<=2;j++)
            {
                c[i][j]=a[i][j]+b[i][j];
                printf("%d ",c[i][j]);
            }printf("\n");

        }
}

