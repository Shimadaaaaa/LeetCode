#include <iostream>
using namespace std;

int n, m, sx, sy;
char m_map[505][505];
int dir[4][2] = {1,0,0,1,-1,0,0,-1};


int func(int x, int y){
    for(int i=0; i<4 ; i++){
        int tx = x+dir[i][0];
        int ty = y+dir[i][1];
        if(m_map[tx][ty] == 'g') return 1;
        if(m_map[tx][ty] == '.'){
            m_map[tx][ty] = '*';
            if(func(tx, ty)){
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    cin >> m >> n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> m_map[i][j];
            if(m_map[i][j] == 's'){
                sx = i;
                sy = j;
            }
        }
    }
    if(func(sx,sy)) cout << "yes" << endl;
    else cout << "no" << endl;
    return 0;
}