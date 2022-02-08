void main(){

    stack(); // A program for implementing a stack using array

    //queue(); // A program for implementing a queue using array

}

void stack(){

    int max=5,stack[max];
    int menuch,top=-1;
    printf("\n\n");
    printf("A program for implementing a stack using array");

    printf("\n\nNOTE : The array can any contain 5 elements.");


    while(1){

        printf("\n\n");
        printf("Perform various stack operations as given below:\n1. Push an element.\n2. Pop an element.\n3. Display all elements.\n4. Exit.");
        printf("\nEnter the choice : ");
        scanf("%d",&menuch);

        switch(menuch){
            case 1: {
                        if(top < max-1){
                            int push_item;
                            printf("\nEnter the element that you want to push : ");
                            scanf("%d",&push_item);
                            top+=1;
                            stack[top]=push_item;
                        }
                        else{
                            printf("\nStack is full !!!");
                        }
                        break;
                    }

            case 2: {
                        if(top == -1){
                            printf("No element to pop !! The stack is empty !!");
                        }
                        else{
                            int pop_item=stack[top];
                            top-=1;
                            printf("\nThe popped/deleted element is : %d",pop_item);
                        }
                        break;
                    }

            case 3: {
                        if(top == -1){
                            printf("\nThe stack is empty !!!");
                        }
                        else{
                            printf("\nThe elements in the stack are : [");
                            for(int i=0;i<=top;i++){
                                printf("%3d",stack[i]);
                            }
                            printf("  ]\n");
                        }
                        break;
                    }

            case 4:
                exit(0);
                break;

            default:
                printf("Wrong choice !! Please enter a valid input !!!!");
                break;
        }
    }

}

void queue(){

    printf("\n\n");
    printf("A program for implementing a queue using array");

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


void queue_using_stack(){

}
