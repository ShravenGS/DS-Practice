#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node *head=NULL;
void swap_adjacent_nodes(){
	if(head==NULL||head->next==NULL){
		return;
	}
	struct node *prev=NULL,*curr=head;
	head=head->next;
	while(curr!=NULL&&curr->next!=NULL){
		struct node *next=curr->next;
		struct node *nextNext=next->next;

		next->next=curr;
		curr->next=nextNext;
		if(prev!=NULL){
			prev->next=next;
		}

		prev=curr;
		curr=curr->next;
	}
}

int main(){
	int choice;
	do{
		//add_begin();
		add_end();
		printf("Do you want to add more:");
		scanf("%d",&choice);
	}while(choice==1);
	display();
	swap_adjacent_nodes();
	display();
}
