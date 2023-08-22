
#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    int temp;
    while(1){
        temp = a%b;
        if(temp == 0)
            return b;

        a = b;
        b = temp;
    }
}

int main(){
    double p,q,n,e,msg,phi,d;
    cout<<"Enter two prime number: ";
    cin>>p>>q;
    cout<<"\nEnter Message Data: ";
    cin>>msg;

    n = p*q; //public key;
    phi = (p-1)*(q-1);
    e = 2;
    while(e<phi){
        if(gcd(e, phi) == 1)
            break;
        else
            e++;
    }

    d = (1.0+(2*phi))/e;
    double ppt = (pow(msg, e)); ppt = fmod(ppt, n); //private key
    double oMsg = pow(ppt, d); oMsg = fmod(oMsg, n); // decryption

    cout<<"Encrypt data -> "<<ppt<<endl;
    cout<<"After Decrypt data-> "<<oMsg<<endl;

}
