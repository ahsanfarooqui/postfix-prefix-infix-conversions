#include<iostream>
#include<math.h>

/* Postfix Evaluation */

using namespace std;

class node{
	
	public:
	int val;
	node* next;
	
	void push(int);
	int pop();
	bool isEmpty();
	int peek();
	node(){
		
		this->next = NULL;
		this->val = NULL;
		
	}
	~node(){
		
		node * temp = this->next;
		node* current = NULL;
		while(temp){
			current = temp;
			temp = this->next;
			delete(current);			
		}		

	}
	
};


node* head = new node();

void node::push(int val){
	
	node* new_node = new node();
	new_node->val = val;
	
	if(head==NULL){
		head = new_node;
	}
	else{
		
		new_node->next = head;
		head = new_node;	
		
	}
	
}

int node::pop(){
	int pop_val;
	if(head==NULL){
		
		cout<<"Stack Empty\n";
		
	}
	
	else{
	
	pop_val = head->val;
	head = head->next;
	
	}
	
	return pop_val;
}

bool node::isEmpty(){
	
	if(head==NULL){
		
		return true;
	}
	else{
		return false;
	}
	
	
}


int precedence(char optr){
	
	switch(optr){
		
		case '+':
			return 1;
		case '-':
			return 1;
		case '*':
			return 2;
		case '/':
			return 2;
		case '^':
			return 3;
		default:
			return -1;

		
	}
	
	
}


int node::peek(){
	
	return head->val;
	
}


int main(){
	
	node* n1 = new node();
	char* a = new char[100];
	int op1 = 0;
	int op2 = 0;
	cout<<"Enter a Postfix expression (0-9 and +-*/^)";
	cin>>a;
	cout<<"Evaluated Postfix solution is: ";
	
	
	while(*a!='\0'){
		
	if(*a>='0'&&*a<='9'){
			
			n1->push(*a-'0');
			
			//cout<<*a-'0';
			
	}
	else if(*a=='+'||*a=='-'||*a=='*'||*a=='/'||*a=='^'){
		
		op1 = n1->pop();
		op2 = n1->pop();
		switch(*a){
		
			case '+': n1->push(op2+op1); break;
			case '-': n1->push(op2-op1); break;
			case '*' : n1->push(op2*op1); break;
			case '/': n1->push(op2/op1); break;
			case '^': n1->push(pow(op2,op1)); break;
			default: n1->push(-1);
			
			}
		


}
	
a++;}	
	
	cout<<n1->pop();
	

	return 0;
}
