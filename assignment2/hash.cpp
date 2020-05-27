#include<iostream>
#include<map>
#include<list>
#include<stdio.h>
using namespace std;
int **hash;
void insert(int key, int value)	{
	int i,j=0;
	i=key%10;
	while(hash[i][j] != 0)
		j++;
	hash[i][j]=value;
}
int main()	{
	
	//map<int,char*> dict;
	//dict d;
	list<int> mylist;
	hash=new int*[10];
	for(int i=0;i<10;i++)	{
		hash[i]=new int[10];
	}
	insert(9,10);
	insert(19,81);
	insert(1,10);
	insert(9,1);
	insert(19,8);
	insert(1,10);
	insert(9,10);
	insert(19,811);
	insert(1,10);
	insert(9,120);
	insert(19,821);
	insert(1,10);
	insert(9,104);
	insert(19,841);
	insert(1,10);
	insert(9,1250);
	insert(19,851);
	insert(1,10);
	printf("%d	%d",hash[1][2],hash[9][10]);
}
