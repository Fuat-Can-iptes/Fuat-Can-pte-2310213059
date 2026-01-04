#include <stdio.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

/* stack islemleri */
void push(char c) {
    top++;
    stack[top] = c;
}

char pop() {
    char c = stack[top];
    top--;
    return c;
}

char peek() {
    return stack[top];
}

/* operator onceligi */
int priority(char c) {
    if (c == '+' || c == '-')
        return 1;
    if (c == '*' || c == '/')
        return 2;
    return 0;
}

int main() {

    char infix[MAX];
    char postfix[MAX];
    int i = 0, k = 0;

    printf("Infix ifadeyi giriniz: ");
    scanf("%s", infix);

    while (infix[i] != '\0') {

        char ch = infix[i];

        /* operand ise direkt postfixe ekle */
        if (isalnum(ch)) {
            postfix[k] = ch;
            k++;
        }

        /* sol parantez */
        else if (ch == '(') {
            push(ch);
        }

        /* sag parantez */
        else if (ch == ')') {
            while (peek() != '(') {
                postfix[k] = pop();
                k++;
            }
            pop(); // '(' cikar
        }

        /* operator */
        else {
            while (top != -1 && priority(peek()) >= priority(ch)) {
                postfix[k] = pop();
                k++;
            }
            push(ch);
        }

        i++;
    }

    /* stackte kalan operatorleri ekle */
    while (top != -1) {
        postfix[k] = pop();
        k++;
    }

    postfix[k] = '\0';

    printf("Postfix ifade: %s\n", postfix);

    return 0;
}