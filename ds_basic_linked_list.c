#include<stdio.h>
#include<stdlib.h>
//In node of linked list it has two parts 1)Data 2)Address of next node
struct node{
        int data;//Data part
        struct node *next;//Address of next node
};
int main(){
        struct node *head=NULL, *newnode,*temp;
        int choice=1;


        while(choice){
                newnode=(struct node*)malloc(sizeof(struct node));//Storing data in heap section so that data storage will be saved
                if(newnode==NULL){
                        printf("Memeory not allocated");
                        return 1;
                }
                //Entering ther data
                printf("Enter data");
                scanf("%d",&newnode->data);//In newnode memory data part in node is being pointed 
                newnode->next=0;//Once the newnodeis added then the next pointerof the nextnode sets to null

                if(head==NULL){
                        head=temp=newnode;
                }
                else{
                        temp->next=newnode;
                        temp=newnode;
                }


                //temp variable is being created because the head part the base address will be stored 
                //so we cannot point so we should do anything that's why we use temp variable 
                //for trasversing and if head is null then temp is store the existing data
                //else we will use temp to point from starting when next newnode is present
                printf("Do you want to continue(0/1)?");
                scanf("%d",&choice);
        }

                //Printing the values
                //The values will be printed until the pointer becomes zero
                temp=head;
                while(temp!=0){
                        printf("%d ",temp->data);
                        temp=temp->next;
                }
}
