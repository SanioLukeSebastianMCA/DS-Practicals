#include <stdio.h>
#include <string.h>

void main(){

    int size, choice;
    printf("A menu driven program to perform operations on user defined array.");
    printf("\n\nEnter the size the size for the array : ");
    scanf("%d", &size);

    int arr[size];
    printf("\nEnter the elements in the array : \n");
    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }

    while(1){
        printf("\n\nFollowing the operations that your can perform on the created array - \n1. Insertion of an element to the array.\n2. Deletion of one element of the array.\n3. Searching an element from the array.\n4. Traversal of the array.\n5. Exit");
        printf("\n\nChoose any one of the numbers from the above to perform corresponding operations : ");
        scanf("%d",&choice);

        switch(choice){
            case 1: {
                        int new_element;
                        printf("\nEnter the new element to add in the array : ");
                        scanf("%d",&new_element);

                        arr[size]=new_element;
                        size+=1;

                        printf("\nThe array with newly added element is as follows : [");
                        for(int i=0;i<size;i++){
                            printf("%3d",arr[i]);
                        }
                        printf(" ]\n");

                        break;
                    }

            case 2: {
                        if(size <= 0){
                            printf("\nUnable to delete !! Array is empty!!!");
                        }
                        else{
                            size-=1;
                            printf("\nThe array after deleting an element is as follows : [");
                            for(int i=0;i<size;i++){
                                printf("%3d",arr[i]);
                            }
                            printf(" ]\n");
                        }
                        break;
                    }

            case 3: {

                        int search_element, flag=0;
                        printf("\nEnter an value of an element to searching from the array : ");
                        scanf("%d",&search_element);

                        for(int i=0;i<size;i++){
                            if(arr[i]==search_element){
                                flag=i;
                                break;
                            }
                        }

                        if(flag>=1){
                            printf("\nThe searched item's position : %d",flag+1);
                        }
                        else{
                            printf("\nThe searched item not found !!");
                        }

                        break;
                    }

            case 4: {
                        printf("\nTraversal of the array is as follows : [");
                        for(int i=0;i<size;i++){
                            printf("%3d",arr[i]);
                        }
                        printf(" ]\n");
                        break;
                    }

            case 5: {
                        exit(0);
                        break;
                    }

            default:{
                        printf("Invalid Operation !!! Please try again an operation using valid corresponding number");
                        break;
                    }
        }
    }

}
