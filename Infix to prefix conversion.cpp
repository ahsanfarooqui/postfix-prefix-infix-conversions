#include<iostream>
#include<string.h>
/* Infix to prefix conversion */

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
	
	node *n1 = new node();
	char b = 'a';
	char* a = new char[100];
	char result[100];
	result[0] = '1';
	int result_size = 0;
	
	cout<<"Enter an infix expression: ";
	cin>>a;
	
	int size = 0;
	int size_copy = 0;
	
	while(*a!='\0')	{
	
		a++;
		size++;
		
	}
	
	size_copy = size;
	
	
	
	while(size>0)	{
		
		a--;
		if((*a>='a'&&*a<='z') || (*a>='A'&&*a<='Z')||(*a>='0'&&*a<='9')){
			
			//cout<<*a;
			result[result_size++] = *a;
			
		}
		
		else if(*a==')'){
			
			n1->push(*a);
			
		}
		
		else if(*a=='+'||*a=='-'||*a=='*'||*a=='/'||*a=='^'){
			
			if(n1->isEmpty() || n1->peek()==')' ){
				
				n1->push(*a);
			}
			
			else if(precedence(*a)>=precedence(n1->peek())){
				
				n1->push(*a);
				
			}
			
			
			
			else if(precedence(n1->peek())>precedence(*a)){
				
				while(precedence(n1->peek())>precedence(*a)){
					
					//cout<<n1.pop();
			        result[result_size++] = n1->pop();
					if(n1->isEmpty()){
						
						break;
					}
					
				}
				
				n1->push(*a);
				
			}
//			
//			else if(precedence(n1.peek())==precedence(*a)){
//				
//				
//				n1.push(*a);
//				
//			}
			
			// Work in progress from here...
			
			
		}
		
		else if(*a=='('){
			
			while(n1->peek()!=')'){
				
				//cout<<n1.pop();
					result[result_size++] = n1->pop();
			
			}
			n1->pop();
		}
		
		
		size--;

if(size==0){

while(!n1->isEmpty()){
	
	//cout<<n1.pop();
		        	result[result_size++] = n1->pop();
					//cout<<result_size<<*(result)<<endl;
			
}




}

}

result[result_size++] = '\0';

cout<<"Prefix solution is: ";

for(int i = strlen(result);i>=0;i--){
	
	cout<<result[i]; 
	
}

cout<<endl;

delete n1;


	
	return 0;
}
