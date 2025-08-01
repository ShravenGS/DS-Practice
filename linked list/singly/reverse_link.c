#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};


struct node *head=NULL;

void add_end(){
	struct node *temp,*newNode;
	int data;
	newNode=(struct node*)malloc(sizeof(struct node));
	if(newNode==NULL){
		printf("Memeory not allocated");
		return;
	}
	printf("Enter the data");
	scanf("%d",&data);
	newNode->data=data;
	newNode->next=NULL;

	if(head==NULL){
		head=newNode;
	}

	else{
		temp=head;

		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->next=newNode;
	}
}

void reverse_link(){
	struct node *prev=NULL;
	struct node *curr=head;
	struct node *next=NULL;
	while(curr!=NULL){
		next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;
	}
head=prev;
}
void display(){
	struct node *temp=head;
	if(head==NULL){
		printf("List is empty");
	}
	else{
		while(temp!=NULL){
			printf("%d ",temp->data);
			temp=temp->next;
		}
	}
}

int main(){
	int choice;
	do{
		add_end();
		printf("Do you want to add more:");
		scanf("%d",&choice);
	}while(choice==1);
	display();
	
	reverse_link();
	display();
	printf("\n");
	
}
