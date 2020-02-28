
//利用栈的思想，符合弹栈，不符合压栈，最后栈空则有效
bool isValid(char * s){
    int len = strlen(s);
    if (len ==0) return true;
    char stack[len];
    int top = -1;
    for(int i=0; i<len; i++){
        if(top>=0 && stack[top] == '(' && s[i] == ')') top--;
        else if(top>=0 && stack[top] == '[' && s[i] == ']') top--;
        else if(top>=0 && stack[top] == '{' && s[i] == '}') top--;
        else{
            stack[++top] = s[i];
        }
    }
    if(top == -1) return true;
    return false;
}