#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

double c[1024][1024];
double a[1024][1024];
double b[1024][1024];

void print(double arr[][1024]) {
	int i,j;
	for(i=0;i<1024;i++) {
		for(j=0;j<1024;j++) {
			printf("%f   ",arr[i][j]);	
		}
	printf("\n");
	}
}

void generate(double arr[][1024]) {
	int i,j;	
	for(i=0;i<1024;i++) {
		for(j=0;j<1024;j++) {
			arr[i][j]=rand()%5;
		}
	}

}

void transpose(double b[][1024]) {
	int i,j,temp;
	for(i=0;i<1024;i++) {
		for(j=i+1;j<1024 ;j++) {
			temp=b[i][j];
			b[i][j]=b[j][i];
			b[j][i]=temp;
		}
	}
}

void matrix_multiplication(double p[][1024],double q[][1024]) {
	int i,j,k,temp;
	for(i=0;i<1024;i++) {
		for(j=0;j<1024;j++) {
			temp=0;
			for (k=0;k<1024;k=k+1) {
				temp = temp + p[i][k]*q[j][k];
			}
			c[i][j]=temp;
		}
	}			
}


int main() {
	struct timespec begin,end; 
	int i,j,k,m,n;
	double total_time;
	srand(time(NULL));	
	generate(a);
	generate(b);	
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&begin);
	printf("------------- Matrix Multiplication --------------------- \n");
	transpose(b);
	matrix_multiplication(a,b);
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&end);
	transpose(b);
	total_time=(end.tv_sec-begin.tv_sec)+(end.tv_nsec-begin.tv_nsec)*pow(10,-9);
	print(c);
	printf("Total execution time of program is %.12lf seconds. \n",total_time);
	return 0;
}
