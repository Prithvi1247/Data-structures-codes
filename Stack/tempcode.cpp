#include <iostream>
#include <string>
#include "stack.h" // Your linked-list-based stack implementation

using namespace std;

string convert(string infix_Exp);
int is_opr(char elem);
int getPrecedence(char op);

int main() {
    string inf_exp;
    int inp = 0;

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
                    string postfix = convert(inf_exp);
                    cout << "Postfix expression: " << postfix << endl;
                }
                break;
            case 3:
                cout << "Evaluation not implemented yet.\n";
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

    // Push a sentinel value to simplify stack emptying
    oprStack.push('`');

    for (char elem : infix_Exp) {
        if (!is_opr(elem)) { // Operand (number or letter)
            postfix_Exp += elem;
        } else { // Operator
            if (elem == '(') {
                oprStack.push(elem);
            } else if (elem == ')') {
                while (oprStack.peek() != '(' && oprStack.peek() != '`') {
                    postfix_Exp += oprStack.pop();
                }
                if (oprStack.peek() == '(') {
                    oprStack.pop(); // Remove '('
                }
            } else { // Other operators (+, -, *, /, ^, etc.)
                if (elem == '^') { // Right-associative for exponentiation
                    while (oprStack.peek() != '`' && oprStack.peek() != '(' && 
                           getPrecedence(oprStack.peek()) > getPrecedence(elem)) {
                        postfix_Exp += oprStack.pop();
                    }
                } else { // Left-associative for other operators (+, -, *, /)
                    while (oprStack.peek() != '`' && oprStack.peek() != '(' && 
                           getPrecedence(oprStack.peek()) >= getPrecedence(elem)) {
                        postfix_Exp += oprStack.pop();
                    }
                }
                oprStack.push(elem);
            }
        }
    }

    // Pop remaining operators from stack
    while (oprStack.peek() != '`') {
        char top = oprStack.pop();
        if (top != '(' && top != ')') { // Ignore stray parentheses
            postfix_Exp += top;
        }
    }
    oprStack.pop(); // Remove sentinel

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