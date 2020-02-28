
//左右两侧向中间接
int max(int a, int b){
    if(a>=b) return a;
    return b;
}

int trap(int* height, int heightSize){
    int l=0, r=heightSize-1;
    int max_l = 0, max_r = 0;
    int ans = 0;
    while(l<=r){
        max_l = max(max_l, height[l]);
        max_r = max(max_r, height[r]);
        if(max_l<max_r){
            ans += max_l-height[l];
            l++;
        }
        else{
            ans += max_r-height[r];
            r--;
        }
    }
    return ans;
}