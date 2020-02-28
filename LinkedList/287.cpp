
//利用链表的思想，每个数都指向其值所在下标的数，重复就会出现环
int findDuplicate(int* nums, int numsSize){
    int p=nums[0], q=nums[0];
    do{
        p=nums[p];
        q = nums[nums[q]];
    }while( p != q);   //找环，pq相遇 
    int cnt = 0;
    do{
        cnt+=1;
        p=nums[p];
    }while(p!=q); //求环长，一个不动，一个走一圈
    p=nums[0], q=nums[0];
    while(cnt--) q=nums[q]; //q先走个环长
    while(p!=q){
        p = nums[p];
        q = nums[q];
    }                  //相遇处及为直线长度，及环的起点
    return p;
}