#include<stdio.h>

int lower_one_mask(int n) {
	int i,m=1;
	for(i=1;i<n;i++) {
		m=(m<<1)|m;
	}
	printf("0x%X",m);
}

int main() {
	int n;
	printf("Enter the value of n \n");
	scanf("%d",&n);
	lower_one_mask(n);
}	

