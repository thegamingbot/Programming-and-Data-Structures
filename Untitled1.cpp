#include <iostream>
using namespace std;

long long modular(long long base, long long exp, int mod)
{
   long long res = 1;
   while (exp > 0)
   {
    	if (exp % 2 == 1)
    		res= (res * base) % mod;
      	exp = exp >> 1;
      	base = (base * base) % mod;
   }
   return res;
}
int main()
{
   long long b, e;
   int mod, i = 0;
   long long a[1000];
   while(cin>>b)
   {
		cin>>b;
   		cin>>e;
   		cin>>mod;
   		a[i++] = modular(b, e , mod);
   }
   for(int j = 0; j <= i; j++)
   		cout<<a[j];
   return 0;
}
