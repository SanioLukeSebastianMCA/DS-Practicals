#include <stdio.h>
#include <stdlib.h>

void main(){
    ques01();
    ques02();
}

void ques01(){

    int size1,size2;
    printf("1. To merge two arrays and sort them.");

    printf("\nEnter the size of the array A : ");
    scanf("%d",&size1);
    fflush(stdin);

    printf("\nEnter the size of the array B : ");
    scanf("%d",&size2);
    fflush(stdin);

    int size3= size1+size2;
    int A[size1], B[size2], C[size3];

    printf("Enter the elements for the array A : \n");
    for(int i=0;i<size1;i++){
        scanf("%d",&A[i]);
        fflush(stdin);
    }
    printf("Enter the elements for the array B : \n");
    for(int i=0;i<size2;i++){
        scanf("%d",&B[i]);
        fflush(stdin);
    }

    for(int i=0;i<size1;i++){
        C[i]= A[i];
    }

    int tempsize=size1;
    for(int i=0;i<size2;i++){
        C[tempsize]=B[i];
        tempsize+=1;
    }

    printf("\nBefore Sort, Array C : [");
    for(int i=0;i<size3;i++){
        printf("%3d",C[i]);
    }
    printf(" ]");

    for(int i=0;i<size3;i++){
        for(int j=i+1;j<size3;j++){
            if(C[i] > C[j]){
                C[i]= C[i] + C[j];
                C[j]= C[i] - C[j];
                C[i]= C[i] - C[j];
            }
        }
    }

    printf("\n\n");
    printf("Array A : [");
    for(int i=0;i<size1;i++){
        printf("%3d",A[i]);
    }
    printf(" ]");

    printf("\nArray B : [");
    for(int i=0;i<size2;i++){
        printf("%3d",B[i]);
    }
    printf(" ]");


    printf("\nSorted Array C : [");
    for(int i=0;i<size3;i++){
        printf("%3d",C[i]);
    }
    printf(" ]");

    printf("\n\n\n");
}

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

void ques02(){
    int size,choice;
    header();
    printf("Stack operations using linked list\n");

    while(1){

        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n\n");
        printf("Enter the option number to perform operation : ");
        scanf("%d",&choice);
        fflush(stdin);

        switch(choice){
            case 1: {
                        push();
                        break;
                    }

            case 2: {
                        pop();
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

void pop(){

    struct node *linked_list, *linked_list1;
    if(head==NULL){
        header();
    }
    if(head->next==NULL){
         printf("\nPop failed - Underflow !! List is Empty !!");
    }
    else{
        linked_list=head->next;
        linked_list1= linked_list->next;
        linked_list->next=NULL;
        head->next= linked_list1;
        free(linked_list);
    }
}

void push(){

    struct node *temp, *linked_list;

    temp= (struct node*) malloc(sizeof(struct node*));
    printf("\nEnter the value : ");
    scanf("%d",&temp->data);
    fflush(stdin);
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
            printf("%d --> ",list->data);
            list=list->next;
        };
        printf("\n");
    }

}



