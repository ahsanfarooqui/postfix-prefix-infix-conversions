#include<iostream>

/* Postfix to infix conversion */

using namespace std;

class node{
	
	public:
	string val;
	node* next;
	
	void push(string);
	string pop();
	bool isEmpty();
	string peek();
	node(){
		
		val = "";
		next = NULL;
		
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

void node::push(string val){
	
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

string node::pop(){
	string pop_val;
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


string node::peek(){
	
	return head->val;
	
}


int main(){
	
	
node *n1 = new node();
string op1 = "";
string op2 = "";
char *infix = new char[100];
cout<<"Enter postfix expression";
cin>>infix;

while(*infix!='\0'){
	
	if((*infix>='a'&&*infix<='z') || (*infix>='A'&&*infix<='Z')||(*infix>='0'&&*infix<='9')){
		string s = "";
		n1->push(s+=*infix);
		
	}
	else if (*infix=='+'||*infix=='-'||*infix=='*'||*infix=='/'||*infix=='^'){
		
		
			op1 = n1->pop();
			op2 = n1->pop();
			string s = "";
			s.push_back('(');	
			s+=op2;
			s.push_back(*infix);
			s+=op1;
			s.push_back(')');
			n1->push(s); 
			}
		
		infix++;
	}
	
	
	
	
cout<<n1->pop();
	

	
	return 0;
}
