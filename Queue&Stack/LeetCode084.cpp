typedef struct Stack{
    int *data;
    int size, top;
}Stack;

Stack *init(int n){
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->data = (int *)malloc(sizeof(int) * n);
    s->size = n;
    s->top = -1;
    return s;
}

int empty(Stack *s){
    return s->top == -1;
}

int top(Stack *s){
    return s->data[s->top];
}

int expand(Stack *s) {
    int extr_size = s->size;
    int *p;
    while (extr_size) {
        p = (int *)realloc(s->data, sizeof(int) * (s->size + extr_size));
        if (p) break;
        extr_size /= 2;
    }
    if (p == NULL) return 0;
    s->size += extr_size;
    s->data = p;
    return 1;
}

int push(Stack *s, int val){
    if(s == NULL) return 0;
    if(s->top == s->size) expand(s);
    s->data[++s->top] = val;
    return 1;
}

int pop(Stack *s){
    if(s == NULL) return 0;
    if(empty(s)) return 0;
    s->top--;
    return s->data[s->top+1];
}

void clear(Stack * s){
    if(s == NULL) return ;
    free(s->data);
    free(s);
    return ;
}

int max(int a, int b){
    return a>b ? a: b;
}

int largestRectangleArea(int* heights, int heightsSize){
    Stack *s = init(1000000);
    push(s,-1);
    int maxarea = 0;
    for(int i=0; i<heightsSize; i++){
        while(top(s)!=-1 && heights[top(s)]>=heights[i]){
            maxarea = max(maxarea, heights[pop(s)]*(i -top(s)-1));
        }
        push(s,i);
    }
    while(top(s) != -1){
        maxarea = max(maxarea, heights[pop(s)] * (heightsSize - top(s) - 1));
    }
    clear(s);
    return maxarea;
}