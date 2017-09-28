#include <iostream>
#include <stdio.h>

using namespace std;


int main()
{
	int len = 53;
	
	int fact[len];
	int mem;
	int rs;
	mem = 0;
		
	for(int i = 0; i < len; i++)
	{
		fact[i] = 0;
	}
	
	fact[len-1] = 1;
	mem = 0;
	
	for(int n = 2; n <=100; n++)
	{
		for(int i = 52; i >= 0; i--)
		{
			rs = fact[i]*n;
			fact[i] = (rs % 1000) + mem;
			mem = rs / 1000;
		}
	}
		
	for(int s = 0; s < len; s++)
	{
		if(s>0)		
		{
			if(fact[s]<100)
				cout<<"0";
			if(fact[s]<10)
				cout<<"0";
		}
			
		cout<<""<<fact[s];
	}
}
