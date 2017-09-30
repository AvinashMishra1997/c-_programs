#include <iostream>
using namespace std;
#define MAX 500

class Parenthesis_Checker{
public:
	char exp[MAX],stack[MAX],value;
	int top;

	Parenthesis_Checker(){
		top=-1;
	}

	void Accept(){
		cout<<"Enter The Expression That You Want To Check The Parenthesis For : ";
		cin>>exp;
	}

	void push(char x){
		if(top==MAX-1){
			cout<<"Stack Is Full\n";
		}
		else{
			top++;
			stack[top]=x;
		}
	}

	char pop(){
		if(top==-1){
			cout<<"Stack Is Empty\n";
		}
		else{
			value=stack[top];
			top--;
		}
		return value;
	}

	void Checker(){
		for(int i=0;exp[i]!='\0';i++){
			if(exp[i]=='{'||exp[i]=='('||exp[i]=='['){
				push(exp[i]);
			}
			else if(exp[i]=='}' && stack[top]=='{'){
				pop();
			}
			else if(exp[i]==']' && stack[top]=='['){
				pop();
			}
			else if(exp[i]==')' && stack[top]=='('){
				pop();
			}
		}
	}

	void IsEmpty(){
		if(top==-1){
			cout<<"Parenthesis Are Well Balanced\n";
		}
		else{
			cout<<"ERROR : Parenthesis Not Balanced\n";
		}
	}
};


int main(){
	char ch;
	do{
		Parenthesis_Checker p;
		p.Accept();
		p.Checker();
		p.IsEmpty();
		cout<<"Do You Want To Check The Parenthesis For Another Expression(y/n) : ";
		cin>>ch;
	}while(ch=='y'||ch=='Y');
	return 0;
}