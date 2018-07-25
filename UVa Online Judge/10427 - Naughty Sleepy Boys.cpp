#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

long long power(long long base, long long power) {
    long long result = 1;
    while(power > 0) {
        if(power&1)
            result = (result*base);
        base = (base * base);
        power = power / 2;
    }
    return result;
}

string convert(ll X){
    string s = "";
    while(X){
        s += X%10+'0';
        X /= 10;
    }
    reverse(s.begin(),s.end());
    return s;
}

int main(){

    ll N;
    while(cin >> N){
        int cnt=1;
        if(N<10){
            cout << N << endl;
            continue;
        }
        while(N > 9*power(10,cnt-1)*cnt){
            N -= 9*power(10,cnt-1)*cnt;
            cnt++;
        }
        int d = (N-1)%cnt;
        ll x = (N-1)/cnt + power(10,cnt-1);
        string s = convert(x);
        cout << s[d] << endl;
    }


    return 0;
}
