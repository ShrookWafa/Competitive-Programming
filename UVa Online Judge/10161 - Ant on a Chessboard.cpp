#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll n;
    while(cin >> n && n){
        int a = ceil(sqrt(n));
        int b = sqrt(n);
        int row,col;
        if(a*a - n < n - b*b){
            if(a%2==0){
                row = a;
                col = a*a - n + 1;
            }else{
                col = a;
                row = a*a - n + 1;
            }
        }else if(a*a - n > n - b*b){
            if(b%2==0){
                row = b + 1;
                col = n - b*b;
            }else{
                col = b + 1;
                row = n - b*b;
            }
        }else{
            if(a%2){
                row = 1;
                col = a;
            }else{
                row = a;
                col = 1;
            }
        }
        cout << row << " " << col << endl;
    }

    return 0;
}
