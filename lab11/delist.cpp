#include "delist.h"
#include <iostream>
#include <cstdlib>

using namespace std;

DEList::DEList(){ //constructor
	head=NULL;
	tail=head;
	num_nodes=0;
}

DEList::~DEList(){ //destructor
	DEItem*temp=head;

	while(temp != tail){
		temp= temp->next;
		delete head;
		head=temp;
	}
	delete temp;
}

bool DEList::empty(){
	if(num_nodes==0){
		return 1;
	}
	else{
		return 0;
	}
}

int DEList::size(){
	return num_nodes;
}

int DEList::front(){
	if(empty()){
		return -1;
	}
	else{
		return head->val;
	}
}

int DEList::back(){
	if(empty()){
		return -1;
	}
	else{
		return tail->val;
	}
}

void DEList::push_front(int new_val){
	if(empty()){
		DEItem*temp = new DEItem;
		temp->prev=NULL;
		temp->val=new_val;
		temp->next=NULL;
		head=temp;
		tail=temp;
	}
	else{
		DEItem*temp = new DEItem;
		temp->next=head;
		temp->val=new_val;
		temp->prev=NULL;
		head->prev=temp;
		head=temp;
	}
	num_nodes++;
}

void DEList::push_back(int new_val){
	if(empty()){
		DEItem*temp = new DEItem;
		temp->prev=NULL;
		temp->val=new_val; 
		temp->next=NULL;
		head = temp;
		tail = temp;
	}
	else{
		DEItem*temp = new DEItem;
		temp->prev=tail;
		temp->val=new_val;
		temp->next=NULL;
		tail->next=temp;
		tail=temp;
	}
	num_nodes++;
}

void DEList::pop_front(){
	if(!empty()){
		DEItem*temp = head;
		head=temp->next;
		delete temp;
		num_nodes--;
	}
}
void DEList::pop_back(){
	if(!empty()){
		DEItem*temp = tail;
		tail=tail->prev;
		delete temp;
		num_nodes--;
	}
}