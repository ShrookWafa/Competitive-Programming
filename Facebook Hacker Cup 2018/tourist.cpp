#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool comp(pair<int, string> p1, pair<int, string> p2){
       return p1.first > p2.first;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    //freopen("tourist.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int t=1,T;
    cin >> T;
    while(t<=T){
        ll n,k,v;
        cin >> n >> k >> v;
        vector<pair<int,string>>vec,vec2;
        for(int i=n; i>0; i--){
            string s;
            cin >> s;
            vec.push_back(make_pair(i,s));
        }
        ll rf = (k*v)%n;
        if(rf==0) rf=n;
        rf--;
        while(k--){
            vec2.push_back(vec[rf]);
            rf--;
            if(rf<0) rf=n-1;
        }
        sort(vec2.begin(),vec2.end(),comp);
        cout << "Case #" << t << ": ";
        for(int i=0; i<vec2.size(); i++){
            cout << vec2[i].second << " ";
        }
        cout << endl;
        t++;
    }


    return 0;
}
