
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int i=0,j=0,c=0,z,h,sema=1;
char input[100],ac[40],stack[100],action[30];
int ctrl(int);
void add(int);
int search(int);
int search2(int);
int search3(int);
int main()
{
    gets(input);
    c=strlen(input);
    input[c]='$';
    stack[i]='0';
    stack[i+1]='\0';
    i++;
    printf("Stack\t\t\tInput\t\t\t\t\tAction\n");
    for(;j<=c;i++,j++){
        int b=strlen(stack);
        if(sema==0){
            printf("%s\t\t\t%s\t\t\t\n",stack,input);
            printf("INVALID SYNTAX!!!");
            break;
        }
        if(input[j]=='$' && action[0]=='a'){
            printf("%s\t\t\t%s\t\t\tAccept",stack,input);
            break;
        }
        if(input[j]=='i' && input[j+1]=='d'){
            if(ctrl(b)==1){
                printf("%s\t\t\t%s\t\t\t%s\n",stack,input,action);
                stack[i]=input[j];
                stack[i+1]=input[j+1];
                stack[i+2]='\0';
                input[j]=' ';
                input[j+1]=' ';
                i++;
                j++;
                add(b);

            }
            else{
                add(b);
                i=strlen(stack)-1;
                j--;
            }
        }
        else{
            if(ctrl(b)==1){
               printf("%s\t\t\t%s\t\t\t%s\n",stack,input,action);
               stack[i]=input[j];
               stack[i+1]='\0';
               input[j]=' ';
               add(b);

            }
            else{
                add(b);
                i=strlen(stack)-1;
                j--;
            }


        }


    }
}
int ctrl(int b){
        if(input[j] == 'i' && input[j+1]=='d'){
            if(stack[b-1]=='0'){
                strcpy(action,"SHIFT 5");
                return 1;

            }
            else if(stack[b-1]=='4'){
                strcpy(action,"SHIFT 5");
                return 1;

            }
            else if(stack[b-1]=='6'){
                strcpy(action,"SHIFT 5");
                return 1;

            }
            else if(stack[b-1]=='7'){
                strcpy(action,"SHIFT 5");
                return 1;

            }
            else{
                sema=0;
            }
        }
        else if(input[j]=='+'){
            if(stack[b-1]=='1'){
                strcpy(action,"SHIFT 6");
                return 1;
            }
            else if(stack[b-1]=='2'){
                strcpy(action,"r2");
                add(b);
                return -1;
            }
            else if(stack[b-1]=='3'){
                strcpy(action,"r4");
                add(b);
                return -1;
            }
            else if(stack[b-1]=='5'){
                strcpy(action,"r6");
                add(b);
                return -1;
            }
            else if(stack[b-1]=='8'){
                strcpy(action,"SHIFT 6");
                return 1;
            }
            else if(stack[b-1]=='9'){
                strcpy(action,"r1");
                add(b);
                return -1;
            }
            else if(stack[b-1]=='0' && stack[b-2]=='1'){
                strcpy(action,"r3");
                add(b);
                return -1;
            }
            else if(stack[b-1]=='1' && stack[b-2]=='1'){
                strcpy(action,"r5");
                add(b);
                return -1;
            }
            else{
                sema=0;
            }

        }
        else if(input[j]=='*'){
            if(stack[b-1]=='2'){
                strcpy(action,"SHIFT 7");
                return 1;
            }
            else if(stack[b-1]=='3'){
                strcpy(action,"r4");
                add(b);
                return -1;
            }
            else if(stack[b-1]=='5'){
                strcpy(action,"r6");
                add(b);
                return -1;
            }
            else if(stack[b-1]=='9'){
                strcpy(action,"SHIFT 7");
                return 1;
            }
            else if(stack[b-1]=='0' && stack[b-2]=='1'){
                strcpy(action,"r3");
                add(b);
                return -1;
            }
            else if(stack[b-1]=='1' && stack[b-2]=='1'){
                strcpy(action,"r5");
                add(b);
                return -1;
            }
            else{
                sema=0;
            }
        }
        else if(input[j]=='('){
            if(stack[b-1]=='0'){
                    strcpy(action,"SHIFT 4");
                    return 1;
                }
            else if(stack[b-1]=='4'){
                strcpy(action,"SHIFT 4");
                return 1;
            }
            else if(stack[b-1]=='6'){
                strcpy(action,"SHIFT 4");
                return 1;
            }
            else if(stack[b-1]=='7'){
                strcpy(action,"SHIFT 4");
                return 1;
            }
            else{
                sema=0;
            }
        }
        else if(input[j]==')'){
            if(stack[b-1]=='2'){
                strcpy(action,"r2");
                add(b);
                return -1;
            }
            else if(stack[b-1]=='3'){
                strcpy(action,"r4");
                add(b);
                return -1;
            }
            else if(stack[b-1]=='5'){
                strcpy(action,"r6");
                add(b);
                return -1;
            }
            else if(stack[b-1]=='8'){
                strcpy(action,"SHIFT 11");
                return 1;
            }
            else if(stack[b-1]=='9'){
                strcpy(action,"r1");
                add(b);
                return -1;
            }
            else if(stack[b-1]=='0' && stack[b-2]=='1'){
                strcpy(action,"r3");
                add(b);
                return -1;
            }
            else if(stack[b-1]=='1' && stack[b-2]=='1'){
                strcpy(action,"r5");
                add(b);
                return -1;
        }
           else{
            sema=0;
           }
        }
        else if(input[j]=='$'){
            if(stack[b-1]=='1' && strlen(stack) == 3){
                strcpy(action,"acc");
                return -1;
            }
            else if(stack[b-1]=='2'){
                strcpy(action,"r2");
                add(b);
                return -1;
            }
            else if(stack[b-1]=='3'){
                strcpy(action,"r4");
                add(b);
                return -1;
            }
            else if(stack[b-1]=='5'){
                strcpy(action,"r6");
                add(b);
                return -1;
            }
            else if(stack[b-1]=='9'){
                strcpy(action,"r1");
                add(b);
                return -1;
            }
            else if(stack[b-1]=='0'&& stack[b-2]=='1'){
                strcpy(action,"r3");
                add(b);
                return -1;
            }

            else if(stack[b-1]=='1' && stack[b-2]=='1'){
                strcpy(action,"r5");
                add(b);
                return -1;
            }
            else{
                sema=0;
            }

        }

}

int search(int z){
    int count1=0;
    int count2=0;
    int k;
    int m;
    for(k=z-1;k>=0;k--){
        if(stack[k]=='E'){
           count1=1;
           break;
        }
    }
    for(m=k-1;m>=0;m--){
        if(stack[m]=='('){
            count2=1;
            break;
        }
    }
    h = m-1;
    if(count1==1 && count2==1 && k>m)
        return 1;
    else return -1;
}
int search2(int z){
    int count1=0;
    int count2=0;
    int k;
    int m;
    for(k=z+1;k<strlen(stack);k++){
        if(stack[k]=='*'){
           count1=1;
           break;
        }
    }
    for(m=z+1;m<strlen(stack);m++){
        if(stack[m]=='F'){
            count2=1;
            break;
        }
    }
    if(count1==1 && count2==1 && m>k)
        return 1;
    else return -1;
}
int search3(int z){
    int count1=0;
    int count2=0;
    int k;
    int m;
    for(k=z+1;k<strlen(stack);k++){
        if(stack[k]=='+'){
           count1=1;
           break;
        }
    }
    for(m=z+1;m<strlen(stack);m++){
        if(stack[m]=='T'){
            count2=1;
            break;
        }
    }
    if(count1==1 && count2==1 && m>k)
        return 1;
    else return -1;
}


void add(int b){
   if(action[0]=='S' && action[7]=='\0'){
    stack[i+1]=action[6];
    stack[i+2]='\0';
    i++;
   }
   else if(action[0]=='S' && action[8]=='\0'){
    stack[i+1]=action[6];
    stack[i+2]=action[7];
    stack[i+3]='\0';
    i++;
   }
   else if(action[0]=='r'){
    if(action[1]=='6'){
       for(z=strlen(stack)-1; z>=0; z--){
       if(stack[z]=='i' && stack[z+1]=='d')
         {
           if(stack[z-1]=='0'){
               strcpy(action,"Reduce 6 use goto [0,F]");
               printf("%s\t\t\t%s\t\t\t%s\n",stack,input,action);
               stack[z+1]='3';
               stack[z]='F';
               stack[z+2]='\0';
           }
           else if(stack[z-1]=='4'){
               strcpy(action,"Reduce 6 use goto [4,F]");
               printf("%s\t\t\t%s\t\t\t%s\n",stack,input,action);
               stack[z+1]='3';
               stack[z]='F';
               stack[z+2]='\0';
           }
           else if(stack[z-1]=='6'){
               strcpy(action,"Reduce 6 use goto [6,F]");
               printf("%s\t\t\t%s\t\t\t%s\n",stack,input,action);
               stack[z+1]='3';
               stack[z]='F';
               stack[z+2]='\0';
           }
           else if(stack[z-1]=='7'){
               strcpy(action,"Reduce 6 use goto [7,F]");
               printf("%s\t\t\t%s\t\t\t%s\n",stack,input,action);
               stack[z+1]='1';
               stack[z+2]='0';
               stack[z]='F';
               stack[z+3]='\0';
           }
           break;
         }
    }
    }
    else if(action[1]=='5'){
       for(z=strlen(stack)-1; z>=0; z--){
       if(stack[z]==')')
         {
         if(search(z)==1){
            if(stack[h]=='0'){
               strcpy(action,"Reduce 5 use goto [0,F]");
               printf("%s\t\t\t%s\t\t\t%s\n",stack,input,action);
               stack[h+2]='3';
               stack[h+1]='F';
               stack[h+3]='\0';
           }
           else if(stack[z-1]=='4'){
               strcpy(action,"Reduce 5 use goto [4,F]");
               printf("%s\t\t\t%s\t\t\t%s\n",stack,input,action);
               stack[h+2]='3';
               stack[h+1]='F';
               stack[h+3]='\0';
           }
           else if(stack[z-1]=='6'){
               strcpy(action,"Reduce 5 use goto [6,F]");
               printf("%s\t\t\t%s\t\t\t%s\n",stack,input,action);
               stack[h+2]='3';
               stack[h+1]='F';
               stack[h+3]='\0';
           }
           else if(stack[h]=='7'){
               strcpy(action,"Reduce 5 use goto [7,F]");
               printf("%s\t\t\t%s\t\t\t%s\n",stack,input,action);
               stack[h+2]='1';
               stack[h+3]='0';
               stack[h+1]='F';
               stack[h+4]='\0';
           }
         }
           break;
         }
    }
    }
    else if(action[1]=='4'){
       for(z=strlen(stack)-1; z>=0; z--){
       if(stack[z]=='F')
         {
             if(stack[z-1]=='0'){
               strcpy(action,"Reduce 4 use goto [0,T]");
               printf("%s\t\t\t%s\t\t\t%s\n",stack,input,action);
               stack[z+1]='2';
               stack[z]='T';
               stack[z+2]='\0';
           }
           else if(stack[z-1]=='4'){
               strcpy(action,"Reduce 4 use goto [4,T]");
               printf("%s\t\t\t%s\t\t\t%s\n",stack,input,action);
               stack[z+1]='2';
               stack[z]='T';
               stack[z+2]='\0';
           }
           else if(stack[z-1]=='6'){
               strcpy(action,"Reduce 4 use goto [6,T]");
               printf("%s\t\t\t%s\t\t\t%s\n",stack,input,action);
               stack[z+1]='9';
               stack[z]='T';
               stack[z+2]='\0';
           }
           break;
         }
    }
    }
    else if(action[1]=='3'){
       for(z=strlen(stack)-1; z>=0; z--){
       if(stack[z]=='T')
         {
        if(search2(z)==1){
            if(stack[z-1]=='0'){
               strcpy(action,"Reduce 3 use goto [0,T]");
               printf("%s\t\t\t%s\t\t\t%s\n",stack,input,action);
               stack[z+1]='2';
               stack[z]='T';
               stack[z+2]='\0';
           }
           else if(stack[z-1]=='4'){
               strcpy(action,"Reduce 3 use goto [4,T]");
               printf("%s\t\t\t%s\t\t\t%s\n",stack,input,action);
               stack[z+1]='2';
               stack[z]='T';
               stack[z+2]='\0';
           }
           else if(stack[z-1]=='6'){
               strcpy(action,"Reduce 3 use goto [6,T]");
               printf("%s\t\t\t%s\t\t\t%s\n",stack,input,action);
               stack[z+1]='9';
               stack[z]='T';
               stack[z+2]='\0';
           }
        }
           break;
         }
    }
    }
    else if(action[1]=='2'){
       for(z=strlen(stack)-1; z>=0; z--){
       if(stack[z]=='T')
         {
            if(stack[z-1]=='0'){
               strcpy(action,"Reduce 2 use goto [0,E]");
               printf("%s\t\t\t%s\t\t\t%s\n",stack,input,action);
               stack[z+1]='1';
               stack[z]='E';
               stack[z+2]='\0';
           }
           else if(stack[z-1]=='4'){
               strcpy(action,"Reduce 2 use goto [4,E]");
               printf("%s\t\t\t%s\t\t\t%s\n",stack,input,action);
               stack[z+1]='8';
               stack[z]='E';
               stack[z+2]='\0';
           }
           else if(stack[z-1]=='1'){
               strcpy(action,"Reduce 2 use goto [1,E]");
               printf("%s\t\t\t%s\t\t\t%s\n",stack,input,action);
               stack[z+1]='1';
               stack[z]='E';
               stack[z+2]='\0';
           }
           break;
         }
    }
    }
    else if(action[1]=='1'){
       for(z=strlen(stack)-1; z>=0; z--){
       if(stack[z]=='E')
         {
           if(search3(z)==1){
            if(stack[z-1]=='0'){
               strcpy(action,"Reduce 1 use goto [0,E]");
               printf("%s\t\t\t%s\t\t\t%s\n",stack,input,action);
               stack[z+1]='1';
               stack[z]='E';
               stack[z+2]='\0';
           }
           else if(stack[z-1]=='4'){
               strcpy(action,"Reduce 1 use goto [4,E]");
               printf("%s\t\t\t%s\t\t\t%s\n",stack,input,action);
               stack[z+1]='8';
               stack[z]='E';
               stack[z+2]='\0';
           }
           else if(stack[z-1]=='1'){
               strcpy(action,"Reduce 1 use goto [1,E]");
               printf("%s\t\t\t%s\t\t\t%s\n",stack,input,action);
               stack[z+1]='1';
               stack[z]='E';
               stack[z+2]='\0';
           }
           }
           break;
         }
    }
    }
   }
}

