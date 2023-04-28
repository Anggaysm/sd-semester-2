#include <iostream>
#include <stack>
#include <cmath>

using namespace std;

bool isOperator(char c) {
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
        return true;
    }
    return false;
}

int precedence(char op) {
    if (op == '^') {
        return 3;
    } else if (op == '*' || op == '/') {
        return 2;
    } else if (op == '+' || op == '-') {
        return 1;
    }
    return 0;
}

double applyOp(double a, double b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        case '^': return pow(a, b);
    }
    return 0;
}

double evaluate(string expression) {
    stack<double> values;
    stack<char> operators;
    for (int i = 0; i < expression.length(); i++) {
        if (expression[i] == ' ') {
            continue;
        } else if (expression[i] == '(') {
            operators.push(expression[i]);
        } else if (isdigit(expression[i])) {
            double num = 0;
            while (i < expression.length() && isdigit(expression[i])) {
                num = num * 10 + (expression[i] - '0');
                i++;
            }
            i--;
            values.push(num);
        } else if (isOperator(expression[i])) {
            while (!operators.empty() && precedence(operators.top()) >= precedence(expression[i])) {
                double b = values.top();
                values.pop();
                double a = values.top();
                values.pop();
                char op = operators.top();
                operators.pop();
                double result = applyOp(a, b, op);
                values.push(result);
            }
            operators.push(expression[i]);
        } else if (expression[i] == ')') {
            while (!operators.empty() && operators.top() != '(') {
                double b = values.top();
                values.pop();
                double a = values.top();
                values.pop();
                char op = operators.top();
                operators.pop();
                double result = applyOp(a, b, op);
                values.push(result);
            }
            operators.pop();
        }
    }
    while (!operators.empty()) {
        double b = values.top();
        values.pop();
        double a = values.top();
        values.pop();
        char op = operators.top();
        operators.pop();
        double result = applyOp(a, b, op);
        values.push(result);
    }
    return values.top();
}

int main() {
    string expression = "(a-b)/2+5*(4+c)";
    double result = evaluate(expression);
    cout << "Hasil ekspresi matematika " << expression << " adalah " << result << endl;
    return 0;
}