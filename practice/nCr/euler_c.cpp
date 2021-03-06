#include <bits/stdc++.h>
#define SIZE (100000+3)
using namespace std;

vector<long long> f(SIZE,1);

long long pow(int a, int b, int MOD){
    long long x=1;
    long long y=a;
    while(b > 0){
        if(b%2 == 1){
            x=(x*y);
            if(x>MOD) x%=MOD;
        }
        y = (y*y);
        if(y>MOD) y%=MOD;
        b /= 2;
    }
    return x;
}

long long InverseEuler(int n, int MOD){
    return pow(n,MOD-2,MOD);
}


long long C(int n, int r, int MOD){
   return (f[n]*((InverseEuler(f[r], MOD) * InverseEuler(f[n-r], MOD)) % MOD)) % MOD;
}

int main(){
    long long MOD = 1000000000+7;
    for (int i=2; i<=SIZE;i++)
        f[i]= (f[i-1]*i) % MOD;
    for(int i=0; i<=10; i++){
        for(int j=0; j<=i; j++){
            cout << C(i,j,1000000000+7) << " ";
        }
        cout << endl;
    }
}
