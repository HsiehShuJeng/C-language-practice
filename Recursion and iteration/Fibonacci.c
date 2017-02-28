#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int recursiveFibonacci(int number);
int main()
{
	int number=1;
	clock_t begin, end; double time;
	while(number!=-1){
		scanf("%d", &number);
		if(number==-1) break;
		begin=clock(); printf("Recursive result=%d\n", recursiveFibonacci(number)); end=clock();
		printf("Elapsed time:%fs\n",(double)(end-begin)/CLOCKS_PER_SEC);
		begin=clock(); printf("Iterative result=%d\n", iterativeFibonacci(number)); end=clock();
		printf("Elapsed time:%fs\n",(double)(end-begin)/CLOCKS_PER_SEC);
	}
	system("PAUSE");
}

int recursiveFibonacci(int number)
{
	if(number==0) return 0;
	else if (number==1) return 1;
	else return recursiveFibonacci(number-1)+recursiveFibonacci(number-2);
}
int iterativeFibonacci(int number)
{
	int a=0, b=1, c, i;
	if(number==0) return 0;
	else if (number==1) return 1;
	else{
		for(i=2; i<=number; i++){
			c=a+b;
			a=b;
			b=c;}}
	return c;
}
