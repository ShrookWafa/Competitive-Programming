#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll fib[50];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    //freopen("out.txt","w",stdout);
    fib[0]=1;
    fib[1]=2;
    for(int i=2; i<50; i++) fib[i] = fib[i-1]+fib[i-2];

    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        ll sol=0, m=n;
        while(m>0){
            int temp;
            for(int i=0; i<50; i++){
                if(fib[i]<=m) temp=i;
                else break;
            }
            sol += pow(2,temp)+0.001;
            m -= fib[temp];
        }
        string s="";
        while(sol){
            s += (sol%2)+'0';
            sol/=2;
        }
        reverse(s.begin(),s.end());
        cout << s << endl;
    }


    return 0;
}
