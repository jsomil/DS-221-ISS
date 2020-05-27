#include<iostream>
#include "mat2d.h"

using namespace std;

int main() {

	init_ar a;
	a.init(2,3);
	//a.init(2,3);
	float rs[]={2,3,4};
	/*for (int ac=0;ac<5;ac++ )
		printf("%f ",rs[ac]);
	
*/
	a.append(rs);
	for(int i=0;i<2;i++) {
		for(int j=0;j<3;j++) {
			cout<<a.get(i,j) ;
		}
	} 
}


