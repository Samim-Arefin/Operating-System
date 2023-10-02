/*
 *  Problem : RSA.cpp
 *  Created by Samim Arefin
*/

#include <bits/stdc++.h>
#include<numeric>

int find_d(int e, int phi)
{
	for(int d = 0 ; d < phi ; d++)
	{
		if(d*e % phi == 1) // d*e mod phi = 1
		{
			return d;
		}
	}
	return -1;
}

int __gcd(int a, int b)
{
    if( b == 0)
    {
       return a;
    }
    else
    {
        return __gcd(b, a % b);
    }
}

int find_e(int phi)
{
	for(int e = 2 ; e < phi ; e++)
	{
       if(__gcd(e, phi) == 1)
       {
        
           return e;
       }
	}
	return -1;
}

int main()
{
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int p = 29 , q = 2683, n , phi, e, d;

    n = p*q; //15
    phi = (p-1) * (q-1); // 8
    e = find_e(phi); // 1<e<phi Where gcd(e,phi) = 1
    d = find_d(e,phi); //d*e mod phi = 1
   

    int plainText,incryptedText = 1,decryptedText = 1;
    std::cin>>plainText;

    for(int i = 1; i <= e; i++) // incryptedText = plainText^e mod n
    {
       incryptedText = (plainText * incryptedText) % n;
    }
    
    for(int i = 1; i <= d; i++ ) // decryptedText = incryptedText^d mod n
    {
    	decryptedText = (decryptedText * incryptedText) % n;
    }

    std::cout << "Original message: " << plainText <<'\n';
    std::cout << "Encrypted message: " << incryptedText << '\n';
    std::cout << "Decrypted message: " << decryptedText << '\n';
}
