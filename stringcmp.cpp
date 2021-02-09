#include<iostream>
#include<cstring>
using namespace std;
int main()
{
char ch[]=”Hello”;

char ch2[]=”Hi”;

int num = strcmp(ch, ch2);

if(num==0)

{

cout << “They are equal”;

}

else if(num < 0 )

{

cout << “ch is alphabetically smaller than ch2”;

}

else if(num> 1)

{

cout << “ch is alphabetically larger than ch2”;

}
return 0;
}
