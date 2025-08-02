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


void rev_print(){
	struct node *temp=head;
	if(temp!=NULL){
		rev_print(temp->next);
		printf("%d ", temp->data);
	}
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

void delete_all(){
	struct node *temp=head;
	while(temp!=NULL){
		struct node *nextNode=temp->next;
		free(temp);
		temp=nextNode;
	}
	head=NULL;
	printf("\nDatas Deleted successfully\n");
}


void delete_duplicate(){
	struct node *curr=head;
	while(curr!=NULL && curr->next!=NULL){
		if(curr->data==curr->next->data){
			struct node *temp=curr->next;
			curr->next=temp->next;
			free(temp);
		}
		else{
			curr=curr->next;
		}
	}
}

void delete_node(int x){
	struct node *temp=head;
	struct node *prev=NULL;
	while(temp!=0){
		if(temp->data==x){
			if(temp==head){
				head=temp->next;
				free(temp);
			}
			else{
				prev->next=temp->next;
				free(temp);
			}
			return;
		}
		prev=temp;
		temp=temp->next;
	}
		printf("Node not found");
}


int main(){
	int choice;
	int num;
	do{
		//add_begin();
		add_end();
		printf("Do you want to add more:");
		scanf("%d",&choice);
	}while(choice==1);
	display();
	printf("\nNumber of datas given is:%d",count());
	printf("\n");
	//rev_print();
	reverse_data();
	display();
	printf("\n");
	reverse_link();
	display();
	printf("\n");
	//delete_all();
	//printf("\n");
	delete_duplicate();
	display();
	printf("\n");
	printf("Enter a node for deletion");
	scanf("%d",&num);
	delete_node(num);
	display();

}
