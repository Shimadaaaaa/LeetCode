int sum(int n){
    int ans = 0;
    while(n>0){
        ans +=(n%10)*(n%10);
        n /= 10;
    }
    return ans;
}

//链表的思想，快慢指针，循环就是成环
bool isHappy(int n){
    int fast, slow;
    slow = n;
    fast = sum(n);
    while(fast != slow){
        slow = sum(slow);
        fast = sum(fast);
        fast = sum(fast);
        if(fast == 1 || slow == 1) break;
    }
    if(fast == 1 || slow == 1) return true;
    return false;
}