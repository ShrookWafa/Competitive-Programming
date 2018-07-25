#include <bits/stdc++.h>

using namespace std;

int parent[5010][35];
vector<vector<int>> adj(5010);
int dep[5001];

void dfs(int in, int p){
    parent[in][0]=p;
    dep[in]=dep[p]+1;
    for(int i=0; i<adj[in].size(); i++){
        int child = adj[in][i];
        if(child!=p){
            dfs(child,in);
        }
    }
}

void pre(int N){
    for(int j=1; (1<<j)<=N; j++){
        for(int i=0; i<=N; i++){
            if(parent[i][j-1]!=-1){
                parent[i][j]=parent[parent[i][j-1]][j-1];
            }
        }
    }
}

int query(int u, int v){
    if(dep[u]>dep[v])
        swap(u,v);
    for(int k=25; k>=0; k--){
        if((dep[v]-(1<<k))>=dep[u]){
            v=parent[v][k];
        }
    }
     if(u==v)
        return u;
    for(int k=26; k>=0; k--){
        if(parent[u][k]!=-1 && parent[u][k]!=parent[v][k]){
            v=parent[v][k];
            u=parent[u][k];
        }
    }
    return parent[u][0];
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n;
    while(cin >> n && n!=0){

           memset(parent,-1,sizeof parent);
           memset(dep,0,sizeof dep);
           adj.assign(n+1,vector<int>(0));
           int m=n-1;
           while(m){
                int x,y;
                scanf("%d %d",&x,&y);
                adj[x].push_back(y);
                adj[y].push_back(x);
                m--;
           }
           dfs(1,0);
           pre(n);
           int l;
           cin >> l;
           while(l){
                int a,b;
                scanf("%d %d",&a,&b);

                int pp=query(a,b);

                int d1 = dep[a]-dep[pp];
                int d2 = dep[b]-dep[pp];

                if(d1<d2) swap(a,b);

                int aa = a;
                int bb = a;
                int deg1 = (d1+d2)/2;

                while(deg1){
                    aa = parent[aa][0];
                    deg1--;
                }
                bb = parent[aa][0];

                if((d1+d2)%2==0){
                    printf("The fleas meet at %d.\n",aa);
                }
                else if((d1+d2)%2==1){
                    if(bb>aa) swap(bb,aa);
                    printf("The fleas jump forever between %d and %d.\n",bb,aa);
                }
                l--;
           }
    }

    return 0;

}
