#include <bits/stdc++.h>

using namespace std;

int tree[4300000];
int lazy[4300000]={-1};
int b[1100000];
int n;

//si segment index, ss segment start, se segment end
void build(int si, int ss, int se){
	if (ss == se)
         tree[si] = b[ss];
	else {
		 int mid = (ss + se) / 2;
         build (si*2, ss, mid);
         build (si*2+1, mid+1, se);
         tree[si] = tree[si*2] + tree[si*2+1];
	}
}

void propagate(int si, int ss, int se){
    if(lazy[si]==2){
        tree[si] = (se-ss+1) - tree[si];
        if(ss!=se){
            if(lazy[si*2]==1 || lazy[si*2]==0){
                lazy[si*2] = lazy[si*2]^1;
            }else if(lazy[si*2]==2){
                lazy[si*2] = -1;
            }else{
                lazy[si*2] = 2;
            }
            if(lazy[si*2+1]==1 || lazy[si*2+1]==0){
                lazy[si*2+1] = lazy[si*2+1]^1;
            }else if(lazy[si*2+1]==2){
                lazy[si*2+1] = -1;
            }else{
                lazy[si*2+1] = 2;
            }
        }
    }
    else if(lazy[si]==1 || lazy[si]==0){
        tree[si] = (se-ss+1) * lazy[si];
        if (ss != se){
            lazy[si*2]  = lazy[si];
            lazy[si*2+1]  = lazy[si];
        }
    }
    lazy[si] = -1;
}

int sum(int si, int ss, int se, int qs, int qe){
    if (lazy[si] != -1)
        propagate(si,ss,se);

    if (ss>se || ss>qe || se<qs)
        return 0;

    if (ss>=qs && se<=qe)
        return tree[si];

    int mid = (ss + se)/2;
    return sum(2*si, ss, mid, qs, qe) + sum(2*si+1, mid+1, se, qs, qe);
}

void updateRange(int si, int ss, int se, int us, int ue, int diff){
    if (lazy[si] != -1)
        propagate(si, ss, se);

    if (ss>se || ss>ue || se<us)
        return;

    if (ss>=us && se<=ue){
        lazy[si]=diff;
        propagate(si,ss,se);
        return;
    }
    int mid = (ss+se)/2;
    updateRange(si*2, ss, mid, us, ue, diff);
    updateRange(si*2+1, mid+1, se, us, ue, diff);

    tree[si] = tree[si*2] + tree[si*2+1];
}

int main()
{
    //freopen("out.txt","w",stdout);
    int T;
    cin >> T;
    int j=1;
    while(j<=T){

        memset(lazy,-1,sizeof lazy);
        memset(tree,0,sizeof tree);
        memset(b,0,sizeof b);

        printf("Case %d:\n",j);

        string pirates="";
        int M;
        cin >> M;
        while(M){
            int T;
            cin >> T;
            string p;
            cin >> p;
            for(int i=0; i<T; i++)
                pirates += p;
            M--;
        }

        n=pirates.length();

        for(int i=0; i<n; i++){
            if(pirates[i]=='1')
                b[i+1]=1;
        }
        build(1,1,n);

        int Q;
        cin >> Q;
        int k=1;
        while(Q){
            char c;
            int x,y;
            cin >> c >> x >> y;
            x++; y++;

            if(c=='F')
                updateRange(1,1,n,x,y,1);
            else if(c=='E')
                updateRange(1,1,n,x,y,0);
            else if(c=='I')
                updateRange(1,1,n,x,y,2);
            else if(c=='S'){
                int ans = sum(1,1,n,x,y);
                printf("Q%d: %d\n",k,ans);
                k += 1;
            }
            Q--;
        }
        j++;
    }

    return 0;
}
