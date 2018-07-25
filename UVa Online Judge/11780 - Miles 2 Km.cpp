#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll fib[50];
double mem[1001];

double dp(int n, int i){
    if(i>15 || fib[i]>n || n==0) return 0;

    if(mem[n]!=-1) return mem[n];

    double d1 = dp(n, i+1);
    double d2 = dp(n-fib[i], i) + fib[i+1];
    double d3 = dp(n-fib[i], i+1) + fib[i+1];

    double a1 = abs(n*1.6 - d1);
    double a2 = abs(n*1.6 - d2);
    double a3 = abs(n*1.6 - d3);

    double b = min(a1, min(a2, a3));
    if(b==a1) mem[n]=d1;
    else if(b==a2) mem[n]=d2;
    else if(b==a3) mem[n]=d3;
    return mem[n];
}


int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    //freopen("out.txt","w",stdout);
    fib[0]=1;
    fib[1]=2;
    for(int i=2; i<50; i++) fib[i] = fib[i-1]+fib[i-2];

    for(int i=0; i<=1000; i++) mem[i]=-1;

    int n;
    while(cin >> n && n){
        cout << fixed << setprecision(2) << abs(n*1.6-dp(n,0)) << endl;
    }


    return 0;
}
