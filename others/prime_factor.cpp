#include <iostream>
#include <vector>
#include <cstdio>
 using namespace std;

int main()
{
    
    long long int number,div;
    int t;
    scanf("%d" , &t);
//    while(t--) {    
 //   printf("Enter a number to know its prime factor: ");    
    scanf("%lld",&number);
    
  //  printf("\nThe prime factors of %lld are: \n\n",number);
    
    div = 2;
    
    while(number!=0){
        if(number%div!=0)
            div = div + 1;
        else {
            number = number / div;
            printf("%lld ",div);
            if(number==1)
                break;
        }
    }
  //  printf("%lld\n" , div-1);
   // }
    return 0;
}
