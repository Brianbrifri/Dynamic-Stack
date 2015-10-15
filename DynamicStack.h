#ifndef DYNAMICSTACK_H
#define DYNAMICSTACK_H

class DynamicStack {

	private:
		struct StackNode {
			double value;
			StackNode *next;
		};

		StackNode *top;

	public:
		//Constructor
		DynamicStack() {
			top = NULL;
		}

		//Destructor
		~DynamicStack();

		//Stack Operations
		void push(double);
		void pop(double &);
		bool isEmpty() const;

};
#endif
