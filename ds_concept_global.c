#include<stdio.h>
#include<stdlib.h>
struct st{
	int roll;
	char name[50];
	int marks;

	struct st *next;
};
struct st *hptr=0;
void add_begin(){
	struct st *temp=(struct st*)malloc(sizeof(struct st));
	printf("Enter the data:\n");
	scanf("%d %s %d",&temp->roll,temp->name,&temp->marks);

	temp->next=hptr;
	hptr=temp;
}
void print(){
	struct st *ptr=hptr;
	printf("\n--------------Strudent records-------------------\n");
	while(ptr!=0){
		printf("%d %s %d\n",ptr->roll,ptr->name,ptr->marks);
		ptr=ptr->next;
	}
}
void save(){
	struct st *ptr=hptr;
	FILE *fp=fopen("data.txt","w");
	while(ptr!=0){
	fprintf(fp, "%d %s %d\n",ptr->roll,ptr->name,ptr->marks);
	ptr=ptr->next;
	}
}
int main(){
	char op;
	do{
		add_begin();
		printf("Do you want to add the student record:");
		scanf(" %c",&op);
	}while(op=='Y'||op=='y');
	print();
	save();
return 0;
}
