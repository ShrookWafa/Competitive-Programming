#include <bits/stdc++.h>

using namespace std;

int binpow(int a, int b, int m) {
    a %= m;
    int res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}

int main()
{
    //freopen("out.txt", "w", stdout);
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        int ttt = binpow(n, k, 1000);

        // n^k = 10^(k * log(n))
        // k * log(n) consists of integer+decimal value
        // 10^x is some 1000... value with x zeros
        // what accounts for the digits added is the mantissa
        // which is the decimal value

        double p = k * log10(n) - floor(k * log10(n));
        int lll = pow(10, p)*100;

        cout << lll << "...";
        if(ttt < 100) cout << '0';
        if(ttt < 10) cout << '0';
        cout << ttt << endl;
    }

    return 0;
}
