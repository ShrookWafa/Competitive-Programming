#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

vector<vector<int>>adj(2002),sets(2002);
vector<int>pre,post;
int p[2002];

void Pre(int s){
    pre.push_back(s);
    for(int i=0; i<adj[s].size(); i++){
            Pre(adj[s][i]);
    }
}
void Post(int s){
    for(int i=0; i<adj[s].size(); i++){
        Post(adj[s][i]);
    }
    post.push_back(s);
}

int Find(int x){
    return x==p[x]?x:p[x]=Find(p[x]);
}
bool same(int a, int b){
    return Find(a)==Find(b);
}
void Union(int a, int b){
    a = Find(a);
    b = Find(b);
    if(sets[a].size()<sets[b].size()) swap(a,b);
    for(int i=0; i<sets[b].size(); i++) sets[a].push_back(sets[b][i]);
    sets[b].clear();
    p[b]=a;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    //freopen("ethan_traverses_a_tree.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int t=1, T;
    cin >> T;
    while(t<=T){

        int n,k;
        cin >> n >> k;

        for(int i=0; i<n; i++){
            p[i]=i;
            sets[i].push_back(i);
        }

        int L[n]={0};
        int K=k;
        for(int i=0; i<n; i++){
            int x,y;
            cin >> x >> y;
            if(x) adj[i].push_back(x-1);
            if(y) adj[i].push_back(y-1);
        }
        Pre(0); Post(0);

        int f1=0, f2=0;
        for(int i=0; i<n; i++){
            if(!same(post[i],pre[i]))
                Union(post[i],pre[i]);
        }

        for(int i=0; i<2002; i++){
            if(sets[i].size()){
                for(int j=0; j<sets[i].size(); j++){
                    L[sets[i][j]]=k;
                }
                k--;
                if(!k){
                    k=K;
                    f2=1;
                }
            }
        }
        for(int i=0; i<n; i++) if(L[post[i]]!=L[pre[i]]) f1=1;

        cout << "Case #" << t << ": ";
        if(f1 || (k && !f2)) cout << "Impossible" << endl;
        else {
            for(int i=0; i<n; i++) cout << L[i] << " ";
            cout << endl;
        }

        pre.clear(); post.clear();
        for(int i=0; i<adj.size(); i++) adj[i].clear();
        for(int i=0; i<2002; i++) sets[i].clear();
        t++;

    }


    return 0;
}
