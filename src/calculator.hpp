#include <iostream>
#include <string>
#include <stack>
#include <sstream>

using namespace std;

class Calculator {
public:
    double evaluate(string expression){
        string postfix = infixToPostfix(expression);
        return evaluatePostfix(postfix);
    }
private:
    //ranks operators based on their precedence in pemdas order
    int precedence(char op) {
        if(op == '+'||op == '-') return 1;
        if(op == '*'||op == '/') return 2;
        return 0;
    }
    string infixToPostfix(string expression){
        stack<char> operators;
        string postfix;
        for (char c:expression){
            if (isdigit(c)){
                postfix += c;
                postfix += ' ';
            }else if(c == '('){
                operators.push(c);
            }else if(c == ')'){
                //add all the numbers and operators inside parantheses to postfix
                while(!operators.empty() && operators.top() != '('){
                    postfix += operators.top();
                    postfix += ' ';
                    operators.pop();
                }
                operators.pop(); //removes the (
            }else if(c=='+' || c=='-' || c=='*' || c=='/'){
                //checks precedence of operators and adds them to postfix
                //only if they have a higher precedence than the current operation
                while(!operators.empty() && operators.top() != '(' && precedence(operators.top()) >= precedence(c)){
                    postfix += operators.top();
                    postfix += ' ';
                    operators.pop();
                }
                operators.push(c);
            }
        }
        //push and pop any remaining operators to post fix
        while(!operators.empty()){
            postfix += operators.top();
            postfix += ' ';
            operators.pop();
        }
        return postfix;
    }
    double evaluatePostfix(string postfix){
        stack<double> values;
        //seperates each number and operator allowing us to easily evaulate
        //one at a time and push the result back onto the stack
        stringstream ss(postfix);
        string token;
        while(getline(ss, token, ' ')){
            if (isdigit(token[0])){
                //converts the string to a double and pushes it onto the stack
                values.push(stod(token));
            }
            else{
                //gets the numbers that should be on right and left of
                //operator and performs the operation on them and pushes
                //the singular result
                double right = values.top(); 
                values.pop();
                double left = values.top();
                values.pop();
                if(token[0] == '+') values.push(left + right);
                else if(token[0] == '-') values.push(left - right);
                else if(token[0] == '*') values.push(left * right);
                else if(token[0] == '/') values.push(left / right);
            }

        }
        //returns the result of the operation
        return values.top();
    }
};
