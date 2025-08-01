#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

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

int count(){
	struct node *temp=head;
	int c=0;
	while(temp!=NULL){
		++c;
		temp=temp->next;
	}
return c;
}
void reverse_data(){
	struct node *ptr=head;
	int c=count(ptr);
	int temp;
	struct node **p=(struct node **)malloc(c*sizeof(struct node *));
	if(p==NULL){
		printf("Memeory not allocated");
		return;
	}
	int i,j;
	for(i=0;i<c;i++){
		p[i]=ptr;
		ptr=ptr->next;
	}
	for(i=0,j=c-1;i<j;i++,j--){
		temp=p[i]->data;
		p[i]->data=p[j]->data;
		p[j]->data=temp;
	}
	free(p);
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
	printf("\nNumber of datas given is:%d",count());
	printf("\n");
	reverse_data();
	display();
	printf("\n");
