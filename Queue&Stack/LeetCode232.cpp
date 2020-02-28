typedef struct {
    int *data;
    int top;
}MyStack;

MyStack *myStackCreate(int size){
    MyStack *s = (MyStack*)malloc(sizeof(MyStack));
    s->data = (int *)malloc(sizeof(int) * size);
    s->top =-1;
    return s;
}

void myStackPush(MyStack* obj, int x) {
    obj->top += 1;
    obj->data[obj->top] = x;
}

int myStackPop(MyStack* obj) {
    return obj->data[obj->top--];
}

int myStackTop(MyStack* obj) {
    return obj->data[obj->top];
}

int myStackEmpty(MyStack* obj) {
    return obj->top == -1;
}

void myStackFree(MyStack* obj) {
    if(obj == NULL) return ;
    free(obj->data);
    free(obj);
    return ;
}

typedef struct {
     MyStack *s1, *s2;
} MyQueue;

/** Initialize your data structure here. */

MyQueue* myQueueCreate() {
    int size = 1024;
   MyQueue *q = (MyQueue*)malloc(sizeof(MyQueue));
    q->s1 = myStackCreate(size);
    q->s2 = myStackCreate(size);
    return q;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
    myStackPush(obj->s1, x);
}

//从一个栈全倒进另一个空栈
/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
    if(myStackEmpty(obj->s2)){
        while(!myStackEmpty(obj->s1)){
            myStackPush(obj->s2, myStackPop(obj->s1));
        }
    }
    return myStackPop(obj->s2);
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
    if(myStackEmpty(obj->s2)){
        while(!myStackEmpty(obj->s1)){
            myStackPush(obj->s2, myStackPop(obj->s1));
        }
    }
    return myStackTop(obj->s2);
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
    return myStackEmpty(obj->s1)&&myStackEmpty(obj->s2);
}

void myQueueFree(MyQueue* obj) {
    if(obj == NULL) return ;
    myStackFree(obj->s1);
    myStackFree(obj->s2);
    free(obj);
    return ;
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/