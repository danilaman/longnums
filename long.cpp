#include <iostream>
#include <stdlib.h>

using namespace std;

void fact(int longfact[], int fac, int len)
{
	int mem, rs;
	mem = 0;
	
	for(int n = 2; n <= fac; n++)
	{
		for(int i = len-1; i >=0; i--)
		{
			rs = longfact[i]*n;
			longfact[i] = (rs%10000)+mem;
			mem = rs / 10000;
		}
	}
}

void showNum(int numtoshow[], int len)
{
	for(int s = 0; s < len; s++)
	{
		
		if(numtoshow[s] == 0)
		{
			cout<<"0";
		}
		
		if(true)		
		{
			if(numtoshow[s]<1000)
				cout<<"0";
			if(numtoshow[s]<100)
				cout<<"0";
			if(numtoshow[s]<10)
				cout<<"0";
		}
		
		if(numtoshow[s] > 0)
		cout<<""<<numtoshow[s];
	}
	
	cout<<endl<<endl;
}

void addition(int bignum1[], int bignum2[], int bigsum[], int len)
{
	int mem, rs;
	mem = 0;
	
	for(int i = len-1; i >=0; i--)
	{
		rs = bignum1[i]+bignum2[i];
		bigsum[i] = (rs % 10000)+mem;
		mem = rs / 10000;
	}
}

void subtraction(int bnum1[], int bnum2[], int bigsub[], int len)
{
	int mem, rs;
	mem = 0;
	
	for(int i = len-1; i >=0; i--)
	{
		rs = bnum1[i] - mem;
		if(rs >= bnum2[i])
		{
			bigsub[i] = bnum1[i] - mem - bnum2[i];
			mem = 0;
		}
		else
		{
			bigsub[i] = 10000 + bnum1[i] - mem - bnum2[i];
			mem = 1;
		}
	}
}

 
void copyarrays(int from[], int to[], int len)
{
	for(int n = 0; n < len; n++)
	{
		to[n] = from[n];
	}
}

void multstep(int numb[], int smallnum, int smres[], int len, int dec)//добавить умножение на степени десятки
{
	int mem, rs;
	mem = 0;
	
	copyarrays(numb, smres, len);
	
	for(int i = len-1; i >= 0; i--)
	{
		rs = smres[i]*smallnum;
		smres[i] = (rs%10000)+mem;
		mem = rs/10000;
	}
	
	while(dec > 0)
	{
		for(int i = len-1; i >= 0; i--)
		{
			rs = smres[i]*10000;
			smres[i] = (rs%10000)+mem;
			mem = rs/10000;
		}
		dec--;
	}
}


void mult(int bnum1[], int bnum2[], int multres[], int add[], int len)
{	
	for(int i = len-1; i >= 0; i--)
	{
		multstep(bnum1, bnum2[i], multres, len, (len-1-i));
		addition(multres, add, add, len);
	}
}

int main()
{
	int len1 = 101; //52 small
	int fact80[len1];
	int fact100[len1];
	int bigsum[len1];
	int bigmul[len1];
	int smres[len1];
	int add[len1];
	int sub[len1];
	
	int factsum[len1];
	
	for(int i = 0; i < len1; i++)
	{
		fact80[i] = 0;
		fact100[i] = 0;
		bigsum[i] = 0;
		bigmul[i] = 0;
		smres[i] = 0;
		add[i] = 0;
		sub[i] = 0;
	}
	
	fact100[len1-1] = 1;
	fact80[len1-1] = 1;
	
	fact(fact80, 80, len1);
	fact(fact100, 100, len1);
	addition(fact80, fact100, bigsum, len1);
	mult(fact80, fact100, smres, add, len1);
	subtraction(fact100, fact80, sub, len1);
	
	cout<<"80!\n";
	showNum(fact80, len1);
	cout<<"100!\n";
	showNum(fact100, len1);
	cout<<"100!+80!\n";
	showNum(bigsum, len1);
	cout<<"100!-80!\n";
	showNum(sub, len1);
	cout<<"100!*80\n!";
	showNum(add, len1);
	
}
