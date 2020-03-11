#include <iostream>
using namespace std;

// void p(int *num, int m){
//     for(int i=0; i<m; i++){
//         i && cout << " ";
//         cout << num[i];
//     }
//     cout << endl;
// }

// void func(int s, int n,int m, int *num, int cnt){
//     for(int i=s; i<=n; i++){
//         if(cnt == m) break;
//         num[cnt++] = i;
//         func(i+1, n, m, num, cnt);
//         if (cnt == m) p(num, m);
//         cnt--;
//     }
// }

// int main(){
//     int m, n;
//     cin >> n >> m;
//     int num[m], cnt = 0;
//     func(1,n, m, num, cnt);
//     return 0;
// }

int n, m, num[15], cnt;

void func(int s, int left){
    if(left == 0){
        for(int i=0; i<cnt; i++){
            i && cout << ' ';
            cout << num[i];
        }
        cout << endl;
        return ;
    }
    for(int i=s; i<=n-left+1; i++){
        num[cnt] = i;
        cnt++;
        func(i+1, left-1);
        cnt--;
    }
}

int main(){
    cin >> n >> m;
    func(1,m);
    return 0;
}