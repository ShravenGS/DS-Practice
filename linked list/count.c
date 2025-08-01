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
                printf("Memory not allocated");
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
}
