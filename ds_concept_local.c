#include<stdio.h>
#include<stdlib.h>
struct node{
        int data;
        struct node *next;
};
//In this we will be adding a function for allocating a memory in heap section
//When we add the data,we will be pointing towards structure data part
//And head will be zero initially and then we will pointing to the existing address of newnode
void add_begin(struct node **head){
        struct node  *newnode=(struct node *)malloc(sizeof(struct node));
        if(newnode==NULL){
                printf("Memeory not allocated");
                return;
        }

        printf("Enter the data:");
        scanf("%d",&newnode->data);
        newnode->next=*head;
        *head=newnode;
}
//In this we will be printing the datas using *temp which we will mae that to include in struct part
//And then the datas will be printed from the starting till the data part is present but address part is null
//But we should point towards next pointer in struct so that it will iterate and if prints also it will be in reverse order
void print(struct node *head){
        struct node *temp=head;
        printf("Printing the elements");
        while(temp!=0){
                printf("%d ",temp->data);
                temp=temp->next;
        }
}


//Only difference is head pointer is added locally rather than globally
int main(){
        struct node *head=NULL;
        int choice;
        do{
                add_begin(&head);
                printf("Do you want to add more(0/1)?");
                scanf("%d",&choice);
        }while(choice==1);

        print(head);

}
