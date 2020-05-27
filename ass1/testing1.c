#include<stdio.h>
int int_shifts_are_arithmetic() {
	unsigned int i=-7;
	//printf("%d",i<<1);
	if((i<<1)==-14)
		return(1);
	else
		return(0);
}

int main() {
 int ans=int_shifts_are_arithmetic();
	printf("%d",ans);
}
