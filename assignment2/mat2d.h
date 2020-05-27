#include<iostream>
using namespace std;

//template <class T>
class  init_ar {
	private :
		bool ex=false;
		int row,column;
		int** a;
		int row_insert=0;
		//int N,M; 

	public :
		virtual void init(int N,int M) {
			if(ex) {
				throw std::invalid_argument( "logic error exception" );
			}
			else
			{		
				
				row=N;
				column=M;				
				a = new int*[N];
				for(int i = 0; i < N; ++i)
				{
					a[i] = new int[M];
					//a[i][j]=0;
				}
				ex=true;
			}
		}
		//template <int size>
		 virtual void append(float row_vals[]) {
			int size=sizeof(row_vals)/sizeof(float);
			//printf("%d ",size);
			if( (size+1)==column && row_insert<row) {
				for(int j=0;j<column;j++) 
					a[row_insert][j]=row_vals[j];
				row_insert++;
			} 
			else {
				throw std::invalid_argument( "out of range" );
			}
		}
		virtual float get(int i,int j) {
			if (i<row && i>=0 && j<column &&j>=0 )
				return a[i][j];
			else 
				throw std::invalid_argument( "out of range" );
		}
};

