#include <stdio.h>
int main()
{
	int x,y;
	scanf("%d%d",&x,&y);
	int a,b;
	a=(4*x-y)/2;
	b=(x-a);
	if(y%2==1 || b<0 || a<0)
		printf("No answer\n");
	else
		printf("%d %d\n",a,b);
	return 0;
}
