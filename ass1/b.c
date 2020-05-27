#include<stdio.h>
unsigned rotate_left(unsigned x, int n) {
	int right_shift,left_shift;
//printf("%d",sizeof(x));
	right_shift=x>>(sizeof(x)*8-n);
	left_shift=x<<n;
	printf("ox%X",left_shift|right_shift);
	return(1);
}

int main() {
	int n,k,x;
	printf("Enter the value of n \n");
	scanf("%X",&x);
	scanf("%d",&n);
	rotate_left(x,n);
}
