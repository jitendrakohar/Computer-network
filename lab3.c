#include<stdlib.h>
#include<string.h>
#include<stdio.h>
char prod[3][10]={"A->aBa","B->bB","B->@"},input[10],stack[25];
int top=-1;
int j=0,k,l;
void push(char item){
stack[++top]=item;
}
void poop(){
top=top-1;
}
void display(){
int j;
for(j=top;j>=0;j--){
printf("%c",stack[j]);
}
}
void stackpush(char p){
if(p=='A')
{
pop();
for(j=strlen(prod[0])-1;j>=3;j--){
push(prod[0][j]);
}
}
else{

pop();
for(j=strlen(prod[1])-1;j>=3;j--)
push(prod[1][j]);
}
}
void main()
{
char c;int i;
printf("first (A)={a}\t");
printf("Follow(A)={$}\n");
printf("First(B)={b,@}\t");
printf("follow(B)={a}\n\n");
printf("\ta\tb\t$\n");
printf("A\t?s\n",prod[0]);
printf("B\t %s\t%s\n",prod[2],prod[0]);
printf("Entere the input string terminated with $ to parse :=");
scanf("%s",input);
for(i=0;input[i]!='\0';i++){
if((input[i]!='a')&&(input[i]!='$')&&input[i]!='$'){
printf("invalid string");
exit(0);
}
if(input[i-1]!='$'){
printf("\n\n Input string entered without end marksers $");
exit(0);
}
push('$');
exit('A');
printf("\n\n");
printf("Stack \tinput\t action");
printf("\n   \n");
while(i!=strlen(input)&&stack[top]!='$'){
printf("\n");
for(i=top;i>=0;i--)
printf("%c",stack[i]);
printf("\t");
for(l=i;l<strlen(input);l++)
printf("%c",input[l]);
printf("\t");
if(stack[top]=='A')
{
printf("A->aBa");
stackpush('A');
}
else if(stack[top]=='B'){
if(input[i]!='b'){
printf("B->@");
printf("it matched @");
pop();
}
else{
printf("B->bB");
stackpush('B');
}
}
else {
if(stack[top]==input[i]){
printf("pop %c",input[i]);
printf("\n Matched %c",input[i]);
pop();
i++;}
else
break;
}
}
if(stack[top]=='$' &&input[i]=='$'){
printf("\n $t \t $");
printf("\n valid string \n");
}
else 
printf("\n invalid string");
}
}

