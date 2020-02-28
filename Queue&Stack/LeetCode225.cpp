typedef struct {
    int *data;
    int head, tail;
    int size, cnt;
} MyQueue;

MyQueue *myQueueCreate(int size){
    MyQueue *q = (MyQueue *)malloc(sizeof(MyQueue));
    q->data = (int *)malloc(sizeof(int) * size);
    q->head = q->tail = q->cnt = 0;
    q->size = size;
    return q;
    
}

void myQueuePush(MyQueue *obj, int x){
    if(obj == NULL) return ;
    if(obj->cnt == obj->size) return;
    obj->data[obj->tail++] = x;
    if(obj->tail == obj->size) obj->tail -= obj->size;
    obj->cnt +=1;
    return ;
}

int myQueuePop(MyQueue *obj){
    if(obj == NULL) return 0;
    if(obj->cnt == 0) return 0;
    obj->head += 1;
    if(obj->head == obj->size) obj->head -= obj->size;
    obj->cnt -=1;
    return 1;
}

int myQueueFront(MyQueue *obj){
    return obj->data[obj->head];
}

int myQueueEmpty(MyQueue *obj){
    return obj->cnt ==0;
}

void myQueueClear(MyQueue *obj){
    if(obj == NULL) return ;
    free(obj->data);
    free(obj);
    return ;
}

typedef struct {
    MyQueue *q1, *q2;
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
    int size = 1024;
    MyStack *s = (MyStack *)malloc(sizeof(MyStack));
    s->q1 = myQueueCreate(size);
    s->q2 = myQueueCreate(size);
    return s;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    if(!myQueueEmpty(obj->q1)){
        myQueuePush(obj->q1, x);
    }else {
        myQueuePush(obj->q2, x);
    }
    return ;
}

//用两个队列，除了最后一个元素，其他都放到另一个空栈里，丢掉最后一个
/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    MyQueue *p = myQueueEmpty(obj->q1) ? obj->q2 : obj->q1;
    MyQueue *q = myQueueEmpty(obj->q1) ? obj->q1 : obj->q2;
    int element = myQueueFront(p);
    myQueuePop(p);
    while(! myQueueEmpty(p)){
        myQueuePush(q, element);
        element = myQueueFront(p);
        myQueuePop(p);
    }
    return element;
}

//同理，但是最后一个也要
/** Get the top element. */
int myStackTop(MyStack* obj) {
    MyQueue *p = myQueueEmpty(obj->q1) ? obj->q2 : obj->q1;
    MyQueue *q = myQueueEmpty(obj->q1) ? obj->q1 : obj->q2;
    int element ;
    while(! myQueueEmpty(p)){
        element = myQueueFront(p);
        myQueuePop(p);
        myQueuePush(q, element);   
    }
    return element;
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    return myQueueEmpty(obj->q1)&&myQueueEmpty(obj->q2);
}

void myStackFree(MyStack* obj) {
    if(obj == NULL) return ;
    myQueueClear(obj->q1);
    myQueueClear(obj->q2);
    free(obj);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 
 * int param_2 = myStackPop(obj);
 
 * int param_3 = myStackTop(obj);
 
 * bool param_4 = myStackEmpty(obj);
 
 * myStackFree(obj);
*/