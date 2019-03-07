#include<iostream>
#include<stack>
#include<string>
int res = 0;
int add(int a, int b);
int multiply(int a, int b);
int substract(int a, int b);
int divide(int a, int b);
using namespace std;

int precedence(char operatr) {
	if (operatr == '+' || operatr == '-')
		return 1;
	if (operatr == '*' || operatr == '/')
		return 2;
	return 0;
}
int evaloperation(int a, int b, char operatr) {
	switch (operatr) {
	case '+': return add(a,b);
	case '-': return substract(a,b);
	case '*': return multiply(a,b);
	case '/': return divide(a,b);
	}
}
int eval_exp(string inputstr) {
	int i;
	stack <int> vals;
	stack <char> oprtrs;

	for (i = 0; i < inputstr.length(); i++) {
		if (inputstr[i] == '(') {
			oprtrs.push(inputstr[i]);
		}
		else if (isdigit(inputstr[i])) {
			int val = 0;
			while (i < inputstr.length() &&isdigit(inputstr[i]))
			{
				val = (val * 10) + (inputstr[i] - '0');
				i++;
			}
			vals.push(val);
			i--;
		}
		else if (inputstr[i] == ')')
		{
			while (!oprtrs.empty() && oprtrs.top() != '(')
			{
				int val2 = vals.top();
				vals.pop();

				int val1 = vals.top();
				vals.pop();

				char op = oprtrs.top();
				oprtrs.pop();

				vals.push(evaloperation(val1, val2, op));
			}
			oprtrs.pop();
		}
		else
		{
			while (!oprtrs.empty() && precedence(oprtrs.top())
				>= precedence(inputstr[i])) {
				int val2 = vals.top();
				vals.pop();

				int val1 = vals.top();
				vals.pop();

				char op = oprtrs.top();
				oprtrs.pop();

				vals.push(evaloperation(val1, val2, op));
			}	
			oprtrs.push(inputstr[i]);
		}
	}
	while (!oprtrs.empty()) {
		int val2 = vals.top();
		vals.pop();

		int val1 = vals.top();
		vals.pop();

		char op = oprtrs.top();
		oprtrs.pop();

		vals.push(evaloperation(val1, val2, op));
	}
	return vals.top();
}

int main() {
	string input_string;
	cout << "Enter the string";
	getline(cin, input_string);
	cout << eval_exp(input_string);
	getchar();
	getchar();
	return 0;
}