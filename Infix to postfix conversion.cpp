#include<iostream>

/* Infix to postfix conversion */

using namespace std;

class node{
	
	public:
	char val;
	node* next;
	
	void push(char);
	char pop();
	bool isEmpty();
	char peek();
	~node(){
		
		
		node * temp = this->next;
		node* current = NULL;
		while(temp){
			current = temp;
			temp = this->next;
			delete(current);			
		}
		
		this->next = NULL;
		this->val = NULL;		
	}
		
		
};


node* head = new node();

void node::push(char val){
	
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

char node::pop(){
	char pop_val;
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


char node::peek(){
	
	return head->val;
	
}


int main(){
	
	node *n1;
	
	char* a = new char[100];
	cout<<"Enter an infix expression: ";
	cin>>a;
	cout<<"\nThe postfix expression is: ";
	
	while(*a!='\0')	{
		
		if((*a>='a'&&*a<='z') || (*a>='A'&&*a<='Z')||(*a>='0'&&*a<='9')){
			
			cout<<*a;
			
		}
		
		else if(*a=='('){
			
			n1->push(*a);
		}
		
		else if(*a=='+'||*a=='-'||*a=='*'||*a=='/'||*a=='^'){
			
			if(n1->isEmpty() || n1->peek()=='(' ){
				
				n1->push(*a);
			}
			
			else if(precedence(*a)>precedence(n1->peek())){
				
				n1->push(*a);
				
			}
			
			
			
			else if(precedence(n1->peek())>=precedence(*a)){
				
				while(precedence(n1->peek())>=precedence(*a)){
					
					cout<<n1->pop();
				}
				
				n1->push(*a);
				
			}

		}
		
		else if(*a==')'){
			
			while(n1->peek()!='('){
				
				cout<<n1->pop();
				
			}
			n1->pop();
		}
		
		
		a++;
}

while(!n1->isEmpty()){
	cout<<n1->pop();
}

delete n1;
	
	return 0;
}
