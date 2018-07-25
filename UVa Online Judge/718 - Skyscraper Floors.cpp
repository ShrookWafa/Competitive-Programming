#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<pair<ll,ll>>elv;
vector<vector<int>>adj(101);
int start[101],endd[101],vis[101];
bool flag = 0;
int f,e,st,en;

ll extended_euclid(ll a, ll b, ll &x, ll &y){
    if(a<0){
        ll r = extended_euclid(-a,b,x,y);
        x *= -1;
        return r;
    }
    if(b<0){
        ll r = extended_euclid(a,-b,x,y);
        y *= -1;
        return r;
    }
    if(b==0){
        x=1, y=0;
        return a;
    }
    ll g = extended_euclid(b, a%b, y, x);
    y -= a/b * x;
    return g;
}

ll dioph(ll a, ll b, ll c, ll &x, ll &y){
    ll g = extended_euclid(a,b,x,y);
    if(c%g == 0){
        x *= c/g;
        y *= c/g;
    }
    return g;
}


void BFS(int s){
    list<int> queue;
    vis[s] = 1;
    queue.push_back(s);
    while(!queue.empty()){
        s = queue.front();
        if(endd[s]){
            flag = 1;
            return;
        }
        queue.pop_front();
        for(auto i = adj[s].begin(); i != adj[s].end(); i++){
            if(!vis[*i]){
                vis[*i] = 1;
                queue.push_back(*i);
            }
        }
    }
}

int main()
{
   //freopen("out.txt","w",stdout);
   int n;
   cin >> n;
   while(n--){
        cin >> f >> e >> st >> en;
        for(int i=0; i<e; i++){
            int x,y;
            cin >> x >> y;
            elv.push_back(make_pair(x,y));
        }

        for(int i=0; i<e; i++){
            for(int j=i+1; j<e; j++){
                ll x1 = elv[i].first, y1 = elv[i].second;
                ll x2 = elv[j].first, y2 = elv[j].second;
                ll a=-1, b=-1;
                ll g = dioph(x1, -x2, y2-y1, a, b);
                int f1 = 0;
                if((y2-y1)%g==0){
                    ll lo = max(-a*g/x2, -b*g/x1);
                    for(ll k = lo; k <= 10000; k++){
                        ll a0 = a + k*x2/g;
                        ll b0 = b + k*x1/g;
                        if(a0>=0 && b0>=0 && y1+a0*x1<f && y2+b0*x2<f && y1+a0*x1 == y2+b0*x2){
                            f1=1;
                            break;
                        }
                    }
                }
                if(f1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        for(int i=0; i<e; i++){
            if(st>=elv[i].second && (st-elv[i].second)%elv[i].first==0) start[i]=1;
            if(en>=elv[i].second && (en-elv[i].second)%elv[i].first==0) endd[i]=1;
        }

        for(int i=0; i<e; i++){
            flag = 0;
            memset(vis, 0, sizeof vis);
            if(start[i]){
                BFS(i);
                if(flag){
                    cout << "It is possible to move the furniture." << endl;
                    break;
                }
            }
        }
        if(!flag){
            cout << "The furniture cannot be moved." << endl;
        }

        memset(start,0,sizeof start);
        memset(endd,0,sizeof endd);
        elv.clear();
        for(int i=0; i<adj.size(); i++) adj[i].clear();
   }

    return 0;
}
