#include <stdio.h>
#include <stdlib.h>

void main(){
    printf("\nImplementation of Circular Queue using Array.");

    int max=5,queue[max];
    int menuch,rear=-1,front=-1;

    while(1){
        printf("\n\n");
        printf("Perform various queue operations as given below:\n1. Enter an element(Enqueue).\n2. Delete an element (Dequeue).\n3. Display all elements.\n4. Exit.");
        printf("\nEnter the choice : ");
        scanf("%d",&menuch);

        switch(menuch){

            case 1: {
                        if(rear >= max-1){
                            printf("\nThe array is full !!!!");
                        }
                        else{
                            if(front==-1)
                                front=0;
                            int new_item;
                            printf("\nEnter the element that you want to insert : ");
                            scanf("%d",&new_item);
                            rear+=1;
                            queue[rear]= new_item;
                        }

                        break;
                    }

            case 2: {
                        if(front <=-1){
                            printf("\nUnable to delete !! Array is empty !!");
                        }
                        else{
                            int deleted_item= queue[front];
                            for(int i=front;i<=rear;i++){
                                queue[i]= queue[i+1];
                            }
                            rear-=1;
                            if(rear==-1){
                                front=-1;
                            }
                            printf("\nThe deleted item is %d",deleted_item);
                        }
                        break;
                    }

            case 3: {
                        if(rear <= -1){
                            printf("\nThe stack is empty !!!");
                        }
                        else{
                            printf("\nThe elements in the stack are : [");
                            for(int i=0;i<=rear;i++){
                                printf("%3d",queue[i]);
                            }
                            printf("  ]\n");
                        }
                        break;
                    }

            case 4: {
                        exit(0);
                        break;
                    }

                    default:
                        printf("Wrong choice !! Please enter a valid input !!!!");
                        break;
        }
    }
}
