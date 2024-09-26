#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX 500
typedef struct {
 char items[MAX];
 int top;
} Stack;
void initStack(Stack* s) {
 s->top = -1;
}
bool isFull(Stack* s) {
 return s->top == MAX - 1;
}
bool isEmpty(Stack* s) {
 return s->top == -1;
}
bool push(Stack* s, char c) {
 if (isFull(s)) return false;
 s->items[++(s->top)] = c;
 return true;
}
bool pop(Stack* s, char* c) {
 if (isEmpty(s)) return false;
 *c = s->items[(s->top)--];
 return true;
}
bool isMatchingPair(char open, char close) {
 if (open == '(' && close == ')') return true;
 if (open == '{' && close == '}') return true;
 if (open == '<' && close == '>') return true;
 return false;
}
void countPairs(int count, const char* type) {
 if (count < 5) {
 printf("%s: Insufficient (%d pairs)\n", type, count);
 } else if (count >= 5 && count <= 10) {
 printf("%s: Moderate (%d pairs)\n", type, count);
 } else {
 printf("%s: Sufficient (%d pairs)\n", type, count);
 }
}
bool checkBalanced(const char* str) {
 Stack stack;
 initStack(&stack); 
 int parenthesesCount = 0;
 int bracesCount = 0;
 int angleBracketsCount = 0;
 for (int i = 0; i < strlen(str); i++) {
 char c = str[i];
 if (c == '(' || c == '{' || c == '<') {
 push(&stack, c);
 } 
 if (c == ')' || c == '}' || c == '>') {
 if (isEmpty(&stack)) {
 return false;
 } 
 char openBracket;
 pop(&stack, &openBracket); 
 if (!isMatchingPair(openBracket, c)) {
 return false; 
 } 
 if (c == ')') parenthesesCount++;
 if (c == '}') bracesCount++;
 if (c == '>') angleBracketsCount++;
 }
 }
 if (!isEmpty(&stack)) {
 return false;
 }
 countPairs(parenthesesCount, "Parentheses");
 countPairs(bracesCount, "Curly Braces");
 countPairs(angleBracketsCount, "Angle Brackets");
 return true;
}
int main() {
 char inputText[] = "<script>\n"
 
"document.getElementById(\"demo\").innerHTML = \"Hello 
JavaScript!\";\n"
 "</script>\n"
 
"document.getElementById(\"demo\").style.fontSize = 
\"25px\";\n"
 
"document.getElementById(\"demo\").style.color = 
\"red\";\n"
 
"document.getElementById(\"demo\").style.backgroundColo
r = \"yellow\";\n"
 "document.getElementById(\"image\").src = 
\"picture.gif\";\n"
 "<style>\n"
 "body {background-color: powderblue;}\n"
 "h1 {color: red;}\n"
 "p {color: blue;}\n"
 "</style>\n";
 if (checkBalanced(inputText)) {
 printf("The parentheses, braces, and brackets are 
balanced.\n");
 } else {
 printf("The parentheses, braces, or brackets are not 
balanced.\n");
 }
 return 0;
}
