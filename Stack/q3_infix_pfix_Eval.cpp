#include <iostream>
#include <string>
#include <cmath>
#include <cctype>
#include "stack.h" 
using namespace std;

string convert(string );
int is_opr(char );
int getPrecedence(char );
int evaluate_postfix(string);
int eval_(int,int,char);

int main() {
    string inf_exp;
    int inp = 0, evaluation = 0 ;
    string postfix;

    while (true) {
        cout << "------------------------------------------\n";
        cout << "1. Get Infix Expression\n2. Convert Infix Expression\n3. Evaluate Postfix\n4. Exit\n\nEnter choice: ";
        cin >> inp;
        cout << endl;
        
        switch (inp) {
            case 1:
                cout << "Enter infix expression: ";
                cin >> inf_exp;
                break;
            case 2:
                if (inf_exp.empty()) {
                    cout << "Please enter an infix expression first!\n";
                } else {
                    postfix = convert(inf_exp);
                    cout << "Postfix expression: " << postfix << endl;
                }
                break;
            case 3:
                evaluation = evaluate_postfix(postfix);
                cout<<"The value of the expression: "<<evaluation<<endl;
                break;
            case 4:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid Input!\n";
        }
    }
    return 0;
}

string convert(string infix_Exp) {
    string postfix_Exp;
    listADT oprStack;

    
    oprStack.push('`');

    for (char elem : infix_Exp) {
        if (!is_opr(elem)) { 
            postfix_Exp += elem;
        } else { 
            if (elem == '(') {
                oprStack.push(elem);
            } else if (elem == ')') {
                while (oprStack.peek() != '(' && oprStack.peek() != '`') {
                    postfix_Exp += oprStack.pop();
                }
                if (oprStack.peek() == '(') {
                    oprStack.pop(); 
                }
            } else { 
                if (elem == '^') { 
                    while (oprStack.peek() != '`' && oprStack.peek() != '(' && 
                           getPrecedence(oprStack.peek()) > getPrecedence(elem)) {
                        postfix_Exp += oprStack.pop();
                    }
                } else {
                    while (oprStack.peek() != '`' && oprStack.peek() != '(' && 
                           getPrecedence(oprStack.peek()) >= getPrecedence(elem)) {
                        postfix_Exp += oprStack.pop();
                    }
                }
                oprStack.push(elem);
            }
        }
    }

    
    while (oprStack.peek() != '`') {
        char top = oprStack.pop();
        if (top != '(' && top != ')') { 
            postfix_Exp += top;
        }
    }
    oprStack.pop(); 

    return postfix_Exp;
}

int is_opr(char elem) {
    // Returns 1 if elem is an operator, 0 if operand (letter or digit)
    if (('0' <= elem && elem <= '9') || ('a' <= elem && elem <= 'z') || ('A' <= elem && elem <= 'Z')) {
        return 0;
    }
    return 1;
}

int getPrecedence(char op) {
    switch (op) {
        case '=': return 1;  // Lowest precedence
        case '|': return 2;
        case '&': return 3;
        case '<': case '>': return 4;
        case '+': case '-': return 5;  // Addition/subtraction
        case '*': case '/': case '%': return 6;  // Multiplication/division
        case '^': return 7;  // Exponentiation (highest, right-associative)
        case '(': case ')': return 8; // Parentheses (highest when pushing)
        default: return 0;  // Unknown operator
    }
}

int evaluate_postfix(string postfix_Exp){
    listADT oprnd_stk;
    oprnd_stk.push('`');
    int output= 0;
    cout<<"post fix exp: "<<postfix_Exp<<endl;
    for(char elem: postfix_Exp){
        if (is_opr(elem)){
            int a = oprnd_stk.pop()-48;
            int op1 = a;
            a = oprnd_stk.pop()-48;

            int op2 = a;
            int val = eval_(op1,op2,elem);

            // cout<<val<<endl;
            oprnd_stk.push(val+48);
            
        }
        else{
            oprnd_stk.push(elem);
        }
    }
    output = oprnd_stk.pop()-48;
    return output;
}

int eval_(int op1, int op2 ,char optr){
    switch (optr){
        case '+':
            return op1+op2;
        case '-':
            return op2-op1;
        case '*':
            return op2*op1;
        case '/':
            return op2/op1;
        case '^':
            int ret = pow(op2,op1);
            return ret;

    }
}
