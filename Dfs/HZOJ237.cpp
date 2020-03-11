#include <iostream>
using namespace std;

int n, num[15], cnt=0, mark[15];

void func(int left){
    if(left == 0){
         for(int i=0; i<cnt; i++){
            i && cout << ' ';
            cout << num[i];
        }
        cout << endl;
        return ;
    }
    for(int i=1; i<=n; i++){
        if(mark[i] == 0){
            mark[i] = 1;
            num[cnt++] = i;
            func(left-1);
            cnt--;
            mark[i] = 0;
        }
    }
}

int main(){
    cin >> n;
    func(n);
    return 0;
}