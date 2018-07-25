#include <bits/stdc++.h>

using namespace std;

int dx[8]={ 1,  2, 1, 2, -1, -2, -1, -2};
int dy[8]={-2, -1, 2, 1, -2, -1,  2,  1};
char board[5][6] = {"11111","01111","00 11","00001","00000"};
char c[5][6];

int diff(char c[5][6], char b[5][6]){
        int d=0;
        for(int i=0; i<5; i++){
            for(int j=0; j<5; j++){
                if(c[i][j]!=b[i][j])
                    d++;
            }
        }
        return d;
}

bool bound(int x, int y) {
    return x >= 0 && x < 5 && y >= 0 && y < 5;
}

int flag=0,cnt=0,sol=10000;

void Search(int x, int y, int prevx, int prevy){
    if(cnt>10){
        return;
    }
    if(diff(c,board)==0){
        flag=1;
        if(cnt<sol)
            sol=cnt;
        return;
    }

    for(int i=0; i<8; i++){
        int a = x+dx[i];
        int b = y+dy[i];

        if(dx[i]==prevx && dy[i]==prevy) continue;

        if(bound(a, b)){
            swap(c[x][y], c[a][b]);
            cnt++;
            Search(a, b, -dx[i], -dy[i]);
            swap(c[x][y], c[a][b]);
            cnt--;
        }
    }
}

int main(){
    //freopen("out.txt", "w", stdout);
    int T;
    cin >> T;
    cin.ignore();
    while(T--){
        int x,y;
        for(int j=0; j<5; j++){
            for(int k=0; k<5; k++){
                c[j][k] = cin.get();
                if(c[j][k]==' '){
                    x=j;
                    y=k;
                }
            }
            cin.ignore();
        }

        Search(x,y,0,0);

        if(flag){
            printf("Solvable in %d move(s).\n", sol);
        }else{
            printf("Unsolvable in less than 11 move(s).\n");
        }
        flag=0;
        cnt=0;
        sol=10000;
    }

    return 0;
}
