#include <stdio.h>

void main(){

    int size, choice, isContinue;
    printf("A menu driven program to perform operations on user defined array.");
    printf("\n\nEnter the size the size for the array : ");
    scanf("%d", &size);

    int arr[size];
    printf("\nEnter the elements for the array to perform operations : \n");
    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }


    while(1){
        printf("\n\nFollowing the operations that your can perform on the created array - \n1. Insertion of an element to the array.\n2. Deletion of one element of the array.\n3. Searching an element from the array.\n4. Traversal of the array.");
        printf("\n\nChoose any one of the numbers from the above to perform corresponding operations : ");
        scanf("%d",&choice);

        switch(choice){

            case 0: {
                        printf("The size of the arr is : %d",size);
                        for(int i=0;i<size;i++){
                            printf("%d  ",arr[i]);
                        }
                        break;
                    }

            case 1: {
                        int new_element;
                        printf("\nEnter the value for the element that you want to add to the array : ");
                        scanf("%d",&new_element);

                        arr[size]= new_element;
                        size+=1;

                        printf("\nThe modified array with newly inserted new element is as follows - [");
                        for(int i=0;i<size;i++){
                            printf("%3d",arr[i]);
                        }
                        printf("  ]");
                        printf("\nThe size of the array is : %d", size);
                        break;
                    }

            case 2: {
                        size-=1;
                        printf("\nThe newly modified array after deleting one element is as follows - [");
                        for(int i=0;i<size;i++){
                            printf("%3d",arr[i]);
                        }
                        printf("  ]");
                        break;
                    }

            case 3: {
                        int search_element, flag=0,pos;
                        printf("\nEnter an value of an element to searching from the array : ");
                        scanf("%d",&search_element);

                        for(int i=0;i<size;i++){
                            if(arr[i]==search_element){
                                flag=1;
                                pos=i+1;
                                break;
                            }
                        }

                        if(flag==1){
                            printf("\nThe searched item exists in the array and its position is : %d",pos);
                        }
                        else{
                            printf("\nThe searched item not found !! No such item exists in the array !!");
                        }

                        break;
                    }

            case 4: {
                        printf("\nThe traversal of the array is as follows- [");
                        for(int i=0;i<size;i++){
                            printf("%3d",arr[i]);
                        }
                        printf("  ]");
                        break;
                    }

            default:{
                        printf("\nInvalid operation !! Please restart the program and enter the valid number corresponding to the desired operation to perform.");
                    }

        }

        printf("\n\n\nDo you want to continue to perform the operations on the array ? If yes type '1' to continue or else type '0' to exit the program : ");
        scanf("%d",&isContinue);

        if(isContinue==0)
            //exit(0);
            break;
        else if(isContinue==1)
            continue;

    }
}

