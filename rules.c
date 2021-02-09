#include<stdio.h>
void main(){
    int unit=0;
    float charge1=0,fuel = 0,govcharge2 = 0,meter = 25,totalbill = 0;
    printf("Enter Units:");
    scanf("%d",&unit);

    if(unit <= 50){
        charge1 = 0.5*charge1;
    }
    else if(unit <= 100){
        charge1 = 1.00;
    }
    else if(unit <=200){
        charge1 = 1.50;
    }

    fuel = (charge1 * 0.4);
    govcharge2 = (charge1*0.10) + fuel;
    totalbill = charge1 + govcharge2 + fuel;

    printf("%f",totalbill);
}
