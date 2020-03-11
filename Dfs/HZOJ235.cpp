#include <iostream>
using namespace std;

int n, num[15], cnt;

void p(){
    for(int i=0; i<cnt; i++){
        i && cout << " ";
        cout << num[i];
    }
    cout << endl;
}

void func(int s){
    for(int i=s; i<=n; i++){
        num[cnt++] = i;
        p();
        func(i+1);
        cnt--;
    }
}


int main(){
    cin >> n;
    func(1);
    return 0;
}