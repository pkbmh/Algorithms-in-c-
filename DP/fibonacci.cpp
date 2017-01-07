#include <bits/stdc++.h>
using namespace std;

#define llu long long unsigned int 

void multiply(llu fib_matrix[][2] , llu m1[][2] , llu m2[][2]) {
	
	llu x = m1[0][0]*m2[0][0]+m1[0][1]*m2[1][0];
	llu y  = m1[0][0]*m2[0][1]+m1[0][1]*m2[1][1];
	llu z = m1[1][0]*m2[0][0]+m1[1][1]*m2[1][0];
	llu t = m1[1][0]*m2[0][1]+m1[1][1]*m2[1][1];
	
	fib_matrix[0][0] = x;
	fib_matrix[0][1] = y;
	fib_matrix[1][0] = z;
	fib_matrix[1][1] = t;
	//cout<<fib_matrix[0][0]<<endl;
}
void fibonacci(llu fib_matrix[][2] , llu n)
{
	llu ans;
	llu tmp[2][2] = {{1 , 1} , {1 , 0}};
	if(n == 1 || n == 0)
	return;
	
	fibonacci(fib_matrix , n/2);
	
	multiply(fib_matrix , fib_matrix , fib_matrix);
	
	if(n % 2 != 0)
	multiply(fib_matrix , fib_matrix , tmp);
	
	//cout<<n<<" "<<fib_matrix[0][0]<<" " <<fib_matrix[0][1]<<" "<<fib_matrix[1][0]<<" "<<fib_matrix[1][1]<<endl;
} 
int main()
{
	llu fib_matrix[2][2] = {{1 , 1} , {1 , 0}};
	llu n;
	scanf("%llu", &n);
	
	fibonacci(fib_matrix , n-1);
	printf("%llu\n", fib_matrix[0][0]);
	
return 0;
}
	
