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


int main(){
        int choice;
        do{
                //add_begin();
                add_end();
                printf("Do you want to add more:");
                scanf("%d",&choice);
        }while(choice==1);
        display();
        
        delete_duplicate();
        display();
}
