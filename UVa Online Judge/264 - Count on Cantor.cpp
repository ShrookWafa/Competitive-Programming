#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    vector<pair<int,int>>vec;

    int sum=2,j=1,f=1,cnt=0;
    for(int k=0; k<10000000; k++){
        vec.push_back(make_pair(sum-j,j));

        cnt++;
        if(cnt == sum-1){
           sum++;
           cnt=0;
           if(f){
             j = sum-1;
             f = 0;
           }else{
             j = 1;
             f = 1;
           }
        }
        else{
            if(f) j++;
            else j--;
        }
    }
    int n;
    while(cin >> n){
        printf("TERM %d IS %d/%d\n",n,vec[n-1].first,vec[n-1].second);
    }
}
