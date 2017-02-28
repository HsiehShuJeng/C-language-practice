#include<stdio.h>
#include<stdlib.h>
#include<time.h>
long long recursiveFac(int);
long long iterativeFac(int);
int main()
{
	int selection; 
	while(selection!=-1)
	{
		scanf("%d", &selection);
		printf("Recursive result=%lli\n", recursiveFac(selection));
		printf("Iterative result=%lli\n", iterativeFac(selection));
	};
	system("PAUSE");
	return 0;
}

long long recursiveFac(int n)
{
	return n>=1 ? n * recursiveFac(n-1) : 1;
}
long long iterativeFac(int n)
{
	int i;
	long long answer=1;
	for (i=1; i<=n; i++){
		answer*=i;
	}
	return answer;
}

