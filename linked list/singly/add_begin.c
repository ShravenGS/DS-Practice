#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node *head=NULL;
void add_begin(){
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
	newNode->next=head;
	head=newNode;
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
		add_begin();
		
		printf("Do you want to add more:");
		scanf("%d",&choice);
	}while(choice==1);
	display();
}
