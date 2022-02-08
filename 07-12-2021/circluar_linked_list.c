#include <stdio.h>
#include <stdlib.h>


struct node{
    int data;
    struct node *next;
};

struct node *head=NULL;

void header(){
    if(head==NULL){
        head= (struct node*) malloc(sizeof(struct node*));
        head->data= 0;
        head->next=NULL;
    }
}

void main(){

    int size,choice;
    header();
    printf("Circluar Linked List Operations\n");

    while(1){

        printf("1. Insertion\n2. Deletion\n3. Display\n4. Exit\n\n");
        printf("Enter the option number to perform operation : ");
        scanf("%d",&choice);
        fflush(stdin);

        switch(choice){
            case 1: {
                        int ins_choice, switch_error=1;
                        while(switch_error==1){
                            printf("\n1. Insertion at begin.\n2. Insertion at end.\n3. Insertion at position.");
                            printf("\n\nChoose type of insertion - ");
                            scanf("%d",&ins_choice);
                            fflush(stdin);

                            switch_error=0;
                            switch(ins_choice){
                                case 1: {
                                            ins_begin();
                                            break;
                                        }

                                case 2: {
                                             ins_end();
                                             break;
                                        }

                                case 3: {
                                            ins_pos();
                                            break;
                                        }

                                default:{
                                            printf("Invalid Operation !!!");
                                            switch_error=1;
                                        }
                            }
                        }
                        break;
                    }

            case 2: {
                        int del_choice, del_switch_error=1;
                        while(del_switch_error==1){
                            printf("\n1. Deletion at begin.\n2. Deletion at end.\n3. Deletion at position.");
                            printf("\n\nChoose type of deletion - ");
                            scanf("%d",&del_choice);
                            fflush(stdin);

                            del_switch_error=0;
                            switch(del_choice){
                                case 1: {
                                            del_begin();
                                            break;
                                        }

                                case 2: {
                                             del_end();
                                             break;
                                        }

                                case 3: {
                                            del_pos();
                                            break;
                                        }

                                default:{
                                            printf("Invalid Operation !!!");
                                            del_switch_error=1;
                                        }
                            }
                        }
                        break;
                    }

            case 3: {
                        display();
                        break;
                    }

            case 4: {
                        exit(0);
                        break;
                    }
        }

    }


}

void del_begin(){

    struct node *firstnode, *tempnode;

    if(head==NULL){
        header();
    }
    if(head->next==NULL){
        printf("\nNo deletion possible !! List is Empty !!\n");
    }
    else{
        firstnode=head->next;

        tempnode= head->next;
        while(tempnode->next!=firstnode){
            tempnode=tempnode->next;
        }
        tempnode->next= firstnode->next;
        head->next= firstnode->next;
        free(firstnode);
    }
}

void del_end(){

    struct node *tempnode1, *tempnode2;

    if(head==NULL){
        header();
    }
    if(head->next==NULL){
        printf("\nNo deletion possible !! List is Empty !!\n");
    }
    else{
        tempnode1= head->next;
        tempnode2= head;

        if(tempnode1->next==tempnode1){
            printf("\nDelete to empty\n");
            head->next= NULL;
            free(tempnode1);
        }
        else{

             while(tempnode1->next!=head->next){
                tempnode1=tempnode1->next;
                tempnode2= tempnode2->next;
            }
            free(tempnode1);
            tempnode2->next= head->next;
        }
    }
}

void del_pos(){
    display();
    struct node *tempnode1, *tempnode2;
    int del_data, check_del=0;

    printf("\nEnter the data : ");
    scanf("%d",&del_data);

    if(head==NULL){
        header();
    }
    if(head->next==NULL){
        printf("\nNo deletion possible !! List is Empty !!\n");
    }
    else{
        tempnode1= head->next;
        tempnode2= head;

        do{
            if(tempnode1->data==del_data){
                check_del=1;
                break;
            }
            else{
                tempnode1=tempnode1->next;
                tempnode2= tempnode2->next;
            }
        }while(tempnode1!=head->next);

        if(check_del==1){
            if(tempnode1==head->next){

                struct node *firstnode, *tempnode;
                firstnode=head->next;
                tempnode= head->next;
                while(tempnode->next!=firstnode){
                    tempnode=tempnode->next;
                }
                tempnode->next= firstnode->next;
                head->next= firstnode->next;
            }
            else if(tempnode1->next==head->next){
                tempnode2->next= head->next;
            }
            else{
                tempnode2->next= tempnode1->next;
            }
            free(tempnode1);
        }
        else{
            printf("\nInsertion failed !! No such item with value=%d in the list to add new item !!\n",del_data);
        }
    }
}

void ins_end(){

    struct node *temp, *linked_list;

    temp= (struct node*) malloc(sizeof(struct node*));
    printf("\nEnter the value : ");
    scanf("%d",&temp->data);
    fflush(stdin);
    temp->next= temp;

    if(head==NULL){
        header();
    }
    if(head->next==NULL){
        head->next= temp;
    }
    else{
        linked_list=head->next;
        while(linked_list->next!=head->next){
            linked_list=linked_list->next;
        }
        temp->next=linked_list->next;
        linked_list->next= temp;

    }
}

void ins_begin(){
    struct node *newnode, *tempnode, *firstnode;

    newnode= (struct node*) malloc(sizeof(struct node*));
    printf("\nEnter the value : ");
    scanf("%d",&newnode->data);
    fflush(stdin);
    newnode->next=newnode;

    if(head==NULL){
        header();
    }
    if(head->next==NULL){
        head->next= newnode;
    }
    else{
        firstnode= head->next;
        head->next= newnode;
        newnode->next= firstnode;

        tempnode= firstnode;
        while(tempnode->next!=firstnode){
            tempnode= tempnode->next;
        }
        tempnode->next= newnode;
    }
}

void ins_pos(){

    display();
    struct node *newnode, *tempnode1, *tempnode2;
    int ins_data, check_ins_data=0;

    printf("\nEnter the data : ");
    scanf("%d",&ins_data);

    newnode= (struct node*) malloc(sizeof(struct node*));
    printf("\nEnter the value : ");
    scanf("%d",&newnode->data);
    fflush(stdin);
    newnode->next= newnode;

    if(head==NULL){
        header();
    }
    if(head->next==NULL){
        head->next= newnode;
    }
    else{
        tempnode1= head->next;
        tempnode2= head;
        do{
            if(tempnode1->data==ins_data){
                check_ins_data=1;
                break;
            }
            else{
                tempnode1=tempnode1->next;
                tempnode2= tempnode2->next;
            }
        }while(tempnode1!=head->next);
        if(check_ins_data==1){
            tempnode2->next= newnode;
            newnode->next=tempnode1;
        }
        else{
            printf("\nInsertion failed !! No such item with value=%d in the list to add new item !!\n",ins_data);
        }

    }
}

void display(){
    printf("\n\nThe list is : ");
    struct node *list;

    if(head==NULL){
        header();
    }
    if(head->next==NULL){
        printf("\nList is Empty !!\n");
    }
    else{
        list= head->next;
        do{
            printf("%d-->",list->data);
            list=list->next;
        }while(list!=head->next);
        printf("%d",list->data);
        printf("\n");
    }
}



