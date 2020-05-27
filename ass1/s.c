#include<stdio.h>
int int_shifts_are_arithmetic() {
	unsigned int i=-7;
	return((i<<1)==-14);
}

int main() {
 int ans=int_shifts_are_arithmetic();
	printf("%d",ans);
}

