// Mahdi Khaliki
// CS20
//
/*
 Stack Demo
 Evalutes a postfix arithmetic expression via a stack.
 This version only handles the four binary operators +,-,*,/
 */

#include <stack>    // to provide STL stack ADT
#include <iostream>
#include <exception>
#include <sstream>  // to provide stringstream
#include <cmath>

using namespace std;

bool isOperator(const string &tok, int &arity);
double toDouble(const string &s);
double evalBinaryOp(double x, double y, const string &op);
double evalOp(stack<double> &stk, const string & op);
double unaryMinus(stack<double> &stk);
double factorial(double n);
double sum(stack<double> &stk);
double average(stack<double> &stk);
double exponential(stack<double> &stk);
void process(const string &tok, stack<double> &stk);

int main() {
    
    string tok, exp;
    bool done = false;
    // read each line of input as a postfix expression and output the corresponding value
    do  {
        cout << "Please type in a postfix expr or Enter to quit: ";
        getline(cin, exp);           // get next expression to process
        if (exp == "") done = true;  // user wants to quit
        else {
            try {
                istringstream in(exp);  // create a stringstream object
                stack<double> stk;      // create a stack of type double
                in >> tok;              // extract the first token from stream
                while (in)              // loop to process subsequent tokens
                {
                    process(tok, stk);
                    in >> tok;          // get next token
                }
                
                double result = stk.top(); // this should be the final answer
                stk.pop();
                if (stk.empty())
                    cout << exp << "  =  " << result << endl; // success!
                else
                    throw logic_error("Malformed expression"); // too many tokens on stack
                
            }
            catch (logic_error e) {
                cout << e.what() << endl;  // e.g. malformed expression, unsupported operator, not enough operands
            }
            catch (range_error e) {
                cout << "Range error: " << e.what() << endl;
            }
        }
        
    } while (!done);
    return 0;
}

// Return true iff tok appears to be an operator, meaning a one character that's not a digit.
// Pass back arity via reference paraeter arity.
bool isOperator(const string &tok, int &arity) {
    arity = 0;
    if (tok.length() != 1) return false; // only single character ops are supported
    char op = tok[0];
    if (op >= '0' && op <= '9')
        return false;  // it's a number
    if (op >= '*' && op <= '/')
        arity = 2;
    else
        arity = 1;
    return true;
}

// Convert s to a double.
// If conversion fails, throw a logic_error exception.
double toDouble(const string &s ) {
    istringstream in(s);
    double x;
    in >> x;
    if (!in) throw logic_error("Bad operand");
    return x;
}

// Return result of evaluating the the binary operation op applied to x and y
// if op doesn't represent a known operation then throw an exception.
double evalBinaryOp(double x, double y, const string & op) {
    
    if (op == "+") return x + y;
    if (op == "-") return x - y;
    if (op == "*") return x * y;
    if (op == "/") {
        if (y == 0)
            throw range_error("Can't divide by zero!");
        return x / y;
    }
    throw logic_error("Unsupported operator!");
}

double evalOp(stack<double> &stk, const string & op) {
    double result = 0;
    if (op == "~")
        result = unaryMinus(stk);
    else if (op == "!") {
        result = factorial(stk.top());
        stk.pop();
    }
    else if (op == "S") result = sum(stk);
    else if (op == "$") result = average(stk);
    else if (op == "^") result = exponential(stk);
    return result;
}

double unaryMinus(stack<double> &stk) {
    double top = stk.top();
    stk.pop();
    return -top;
}

double factorial(double n) {
    if (n < 0) throw range_error("Factorial cannot take in a negative!");
    double t = n;
    while(--n > 1)
        t *= n;
    return t;
}

double sum(stack<double> &stk) {
    double sum = 0;
    int sumNumbers = (int)stk.top();
    stk.pop();
    
    if (stk.size() < sumNumbers) throw logic_error("Not enough operands");
    if (sumNumbers == 0) return 0;
    
    for (int i = 0; i < sumNumbers; i++) {
        sum += stk.top();
        stk.pop();
    }
    return sum;
}

double average(stack<double> &stk) {
    double sum = 0;
    int sumNumbers = stk.top();
    stk.pop();
    
    if (stk.size() < sumNumbers) throw logic_error("Not enough operands");
    
    for (int i = 0; i < sumNumbers; i++) {
        sum += stk.top();
        stk.pop();
    }
    return sum / sumNumbers;
}

double exponential(stack<double> &stk) {
    double exponent = stk.top();
    stk.pop();
    double result = pow(stk.top(), exponent);
    if (isnan(result) || isinf(result))
        throw range_error("Cannot use values for exponent");
    stk.pop();
    return result;
}

/*
 Process the next token.  The token might be an operator or an operand.
 
 In the case of an operator: pop appropriate number of operands from the
 stack, evaluate the operation and push answer onto the stack.
 The current implementation only supports binary operators, which means
 exactly two values will be popped from the stack.
 
 In the case of an operand. convert it to a double and push onto the stack.
 */
void process(const string & tok, stack<double> & stk) {
    int arity = 0;
    if (isOperator(tok, arity ) )  {
        double answer = 0;
        if (stk.size() < arity) throw logic_error("Not enough operands");
        if (arity == 1) {
            answer = evalOp(stk, tok);
        }
        else {
            double v2 = stk.top();
            stk.pop();
            double v1 = stk.top();
            stk.pop();
            answer = evalBinaryOp(v1, v2, tok); // e.g. add two numbers
        }
        stk.push(answer);  // push answer onto the stack
    }
    else {
        double d = toDouble(tok); // convert token to a double
        stk.push(d);    // push the value onto stack
    }
}
