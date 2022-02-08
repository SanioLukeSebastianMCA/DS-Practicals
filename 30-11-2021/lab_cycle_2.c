#include <stdio.h>
#include <stdlib.h>


struct node{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head=NULL;

void header(){
    if(head==NULL){
        head= (struct node*) malloc(sizeof(struct node*));
        head->data= 0;
        head->next=NULL;
        head->prev=NULL;
    }
}

void main(){

    int size,choice;
    header();
    printf("Doubly Linked List Operations\n");

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

    struct node *linked_list;

    if(head==NULL){
        header();
    }
    if(head->next==NULL){
        printf("\nNo deletion possible !! List is Empty !!\n");
    }
    else{
        linked_list=head->next;
        head->next= linked_list->next;
        linked_list->next->prev= NULL;
        free(linked_list);
    }
}

void del_end(){

    struct node *linked_list, *linked_list1;

    if(head==NULL){
        header();
    }
    if(head->next==NULL){
        printf("\nNo deletion possible !! List is Empty !!\n");
    }
    else{
        linked_list= head->next;
        linked_list1= head;
        if(linked_list->next==NULL){
            head->next= NULL;
            free(linked_list);
        }
        else{
            while(linked_list->next!=NULL){
                linked_list=linked_list->next;
                linked_list1= linked_list1->next;
            }
            linked_list1->next= NULL;
            free(linked_list);
        }
    }
}

void del_pos(){
    display();
    struct node *linked_list, *linked_list1;
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
        linked_list= head->next;
        linked_list1= head;
        while(linked_list->next!=NULL){
            if(linked_list->data==del_data){
                check_del=1;
                break;
            }
            else{
                linked_list=linked_list->next;
                linked_list1= linked_list1->next;
            }
        }
        if(check_del==1){
            linked_list1->next= linked_list->next;
            linked_list->next->prev= linked_list1;
            free(linked_list);
        }
        else{
            printf("\Deletion failed !! No such item with value=%d in the list !!\n",del_data);
        }
    }
}

void ins_end(){

    struct node *temp, *linked_list;

    temp= (struct node*) malloc(sizeof(struct node*));
    printf("\nEnter the value : ");
    scanf("%d",&temp->data);
    fflush(stdin);
    temp->prev=NULL;
    temp->next= NULL;

    if(head==NULL){
        header();
    }
    if(head->next==NULL){
        head->next= temp;
    }
    else{
        linked_list=head->next;
        while(linked_list->next!=NULL){
            linked_list=linked_list->next;
        }
        linked_list->next= temp;
        temp->prev= linked_list;
    }
    printf("\nThe head data is : %d\n",head->data);
}

void ins_begin(){
    struct node *temp, *linked_list;

    temp= (struct node*) malloc(sizeof(struct node*));
    printf("\nEnter the value : ");
    scanf("%d",&temp->data);
    fflush(stdin);
    temp->prev=NULL;
    temp->next=NULL;

    if(head==NULL){
        header();
    }
    if(head->next==NULL){
        head->next= temp;
    }
    else{
        linked_list= head->next;
        head->next= temp;
        temp->next= linked_list;
        linked_list->prev=temp;
    }
    printf("\nThe head data is : %d\n",head->data);
}

void ins_pos(){

    display();
    struct node *temp, *linked_list, *linked_list1;
    int pos_data, check_pos_data=0;

    printf("\nEnter the data : ");
    scanf("%d",&pos_data);

    temp= (struct node*) malloc(sizeof(struct node*));
    printf("\nEnter the value : ");
    scanf("%d",&temp->data);
    fflush(stdin);
    temp->next= NULL;
    temp->prev= NULL;

    if(head==NULL){
        header();
    }
    if(head->next==NULL){
        head->next= temp;
    }
    else{
        linked_list= head->next;
        linked_list1= head;
        while(linked_list->next!=NULL){
            if(linked_list->data==pos_data){
                check_pos_data=1;
                break;
            }
            else{
                linked_list=linked_list->next;
                linked_list1= linked_list1->next;
            }
        }
        if(check_pos_data==1){
            linked_list1->next= temp;
            temp->prev=linked_list1;
            temp->next=linked_list;
            linked_list->prev=temp;
        }
        else{
            printf("\nInsertion failed !! No such item with value=%d in the list to add new item !!\n",pos_data);
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
        printf("List is Empty !!");
    }
    else{
        list= head->next;
        while(list!=NULL){
            if(list->prev!=NULL){
                printf("(%d)", list->prev->data);
            }
            printf("%d <==> ",list->data);
            list=list->next;
        };
        printf("\n");
    }
}



