#include "stackLL.h"
#include <string.h>

/*
Alternate Solution 
bool isValid(char * s){
    int length=strlen(s);
    if(length==0){return true;}
    if(length%2==1){return false;}
    int stackpointer=0;
    char* stack=(char*)malloc(length*sizeof(char));
    
    for(int i=0;i<length;i++){
        switch(*(s+i)){
            case '(':
                *(stack+stackpointer)='a';
                stackpointer++;
                break;
            case '{':
                *(stack+stackpointer)='b';
                stackpointer++;
                break;
            case '[':
                *(stack+stackpointer)='c';
                stackpointer++;
                break;
            case ')':
                if(stackpointer>0){
                    if(*(stack+stackpointer-1)!='a'){
                    return false;
                }
                else{
                    *(stack+stackpointer-1)=NULL;
                    stackpointer--;
                }
                }
                else{
                    return false;
                } 
                break;
            case '}':
                if(stackpointer>0){
                    if(*(stack+stackpointer-1)!='b'){
                    return false;
                }
                else{
                    *(stack+stackpointer-1)=NULL;
                    stackpointer--;
                }
                }
                else{
                    return false;
                } 
                break;
            case ']':
                if(stackpointer>0){
                    if(*(stack+stackpointer-1)!='c'){
                    return false;
                }
                else{
                    *(stack+stackpointer-1)=NULL;
                    stackpointer--;
                }
                }
                else{
                    return false;
                } 
                break;
        }
    }
    if(stackpointer==0){return true;}
    else{return false;}
}
*/
bool isBalanced(char String[]) {
    stackLLInit();
    int i = 0;
    int len = strlen(String);
    for (i = 0; i < len ; i++) {
        if (String[i] == '[' || String[i] == '(' || String[i] == '{') {
            pushStackLL(String[i]);
        } else {

            if ((String[i] == ']' && topStackLL() == '[')  ||
                (String[i] == '}' && topStackLL() == '{') ||
                (String[i] == ')' && topStackLL() == '(')) {
                popStackLL();
            } else if ((String[i] == ']' && topStackLL() != '[')  ||
                (String[i] == '}' && topStackLL() != '{') ||
                (String[i] == ')' && topStackLL() != ')')) {
                return false;
            } 
        }
    }

    return isStackLLEmpty();  
}
int main() {
   char String[15];
   while(1) {
       printf("Enter String : ");
       scanf("%s",String);
       printf("isBalanced : %s\n", isBalanced(String) ? "yes" : "no");
   }
}
