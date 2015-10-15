#include<iostream>
#include<iomanip>
#include<sstream>
#include<vector>
#include<stack>
#include "DynamicStack.h"

using namespace std;

int main() {

	//Declaring variables
	string input;
	int choice, size;

	cout << "Let's work on our Polish skills, shall we?" << endl;
	cout << "Would you like to go with dynamic stack or the STL stack?" << endl;

	//Gets choice
	while(choice != 1 && choice != 2) {
		cout << "Enter '1' for dynamic or '2' for the STL container: ";
	
		cin >> choice;
	}

	//If Dynamic stack
	if(choice == 1) {

		//Declare a temp string to convert
		string tempString;
		double temp, modTemp1, modTemp2, result;
		
		//Create a stack
		DynamicStack theStack;

		cout << "Please enter your arithmatic expression: ";

		//Gets the whole input
		cin.ignore();
		getline(cin, input);
		
		//For loop starts at the end of the string
		for(int i = input.size(); i >= 0; i--) {


			//If the input is not a space or a modifier, add it to the front of the temp string
			if(input[i] != ' ' && input[i] != '+' && input[i] != '-' && input[i] != '*' && input[i] != '/') {
				
				tempString.insert(0, 1, input[i]);
			}

			//If the input does equal a space or a modifier, convert what is in the temp string to an int,
			//pushes it onto the stack, and clear the temp string, but only if the temp string size is > 0
			if(input[i] == ' ' || input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/') {

				if(tempString.size() != 0) {
					temp = atoi(tempString.c_str());
					cout << fixed << setprecision(2) << "Pushing: " << temp << endl;
					theStack.push(temp);
					tempString.clear();
				}
			}
			
			//The different cases for the modifiers:
			if(input[i] == '+') {
				
				theStack.pop(modTemp1);
				theStack.pop(modTemp2);
				result = modTemp1 + modTemp2;

				cout << fixed << setprecision(2) << modTemp1 << " + " << modTemp2 << " = " << result << endl;
				cout << "Pushing result: " << result << endl;
				theStack.push(result);
			}

			if(input[i] == '-') {

				theStack.pop(modTemp1);
				theStack.pop(modTemp2);
				result = modTemp1 - modTemp2;

				cout << fixed << setprecision(2) << modTemp1 << " - " << modTemp2 << " = " << result << endl;
				cout << "Pushing result: " << result << endl;
				theStack.push(result);
			}

			if(input[i] == '*') {

				theStack.pop(modTemp1);
				theStack.pop(modTemp2);
				result = modTemp1 * modTemp2;

				cout << fixed << setprecision(2) << modTemp1 << " * " << modTemp2 << " = " << result << endl;
				cout << "Pushing result: " << result << endl;
				theStack.push(result);
			}

			if(input[i] == '/') {

				theStack.pop(modTemp1);
				theStack.pop(modTemp2);
				result = modTemp1 / modTemp2;

				cout << fixed << setprecision(2) << modTemp1 << " / " << modTemp2 << " = " << result << endl;
				cout << "Pushing result: " << result << endl;
				theStack.push(result);
			}

		}

	}

	//If STL stack
	if(choice == 2) {

		//Declaring variables
		string tempString;
		double temp, modTemp1, modTemp2, result;
		
		//Creating a stack
		stack< double, vector<double> > theStack;

		cout << "Please enter your arithmatic expression: ";

		cin.ignore();
		getline(cin, input);
		
		//The rest is the same logic as above
		for(int i = input.size(); i >= 0; i--) {


			if(input[i] != ' ' && input[i] != '+' && input[i] != '-' && input[i] != '*' && input[i] != '/') {
				
				tempString.insert(0, 1, input[i]);
			}

			if(input[i] == ' ' || input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/') {

				if(tempString.size() != 0) {
					temp = atoi(tempString.c_str());
					cout << "Pushing: " << temp << endl;
					theStack.push(temp);
					tempString.clear();
				}
			}
			
			if(input[i] == '+') {
				
				modTemp1 = theStack.top();
				theStack.pop();
				modTemp2 = theStack.top();
				theStack.pop();
				result = modTemp1 + modTemp2;

				cout << fixed << setprecision(2) << modTemp1 << " + " << modTemp2 << " = " << result << endl;
				cout << "Pushing result: " << result << endl;
				theStack.push(result);
			}

			if(input[i] == '-') {

				modTemp1 = theStack.top();
				theStack.pop();
				modTemp2 = theStack.top();
				theStack.pop();
				result = modTemp1 - modTemp2;

				cout << fixed << setprecision(2) << modTemp1 << " - " << modTemp2 << " = " << result << endl;
				cout << "Pushing result: " << result << endl;
				theStack.push(result);
			}

			if(input[i] == '*') {

				modTemp1 = theStack.top();
				theStack.pop();
				modTemp2 = theStack.top();
				theStack.pop();
				result = modTemp1 * modTemp2;

				cout << fixed << setprecision(2) << modTemp1 << " * " << modTemp2 << " = " << result << endl;
				cout << "Pushing result: " << result << endl;
				theStack.push(result);
			}

			if(input[i] == '/') {

				modTemp1 = theStack.top();
				theStack.pop();
				modTemp2 = theStack.top();
				theStack.pop();
				result = modTemp1 / modTemp2;

				cout << fixed << setprecision(2) << modTemp1 << " / " << modTemp2 << " = " << result << endl;
				cout << "Pushing result: " << result << endl;
				theStack.push(result);
			}

		}

	}


	return 0;
}
