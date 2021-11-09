#include <stdio.h>

void main(){

    int size, choice, isContinue;
    printf("A menu driven program to perform operations on user defined array.");
    printf("\n\nEnter the size the size for the array : ");
    scanf("%d", &size);

    int arr[size];
    printf("\nEnter the elements in the array : \n");
    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }


    while(1){
        printf("\n\nFollowing the operations that your can perform on the created array - \n1. Insertion of an element to the array.\n2. Deletion of one element of the array.\n3. Searching an element from the array.\n4. Traversal of the array.");
        printf("\n\nChoose any one of the numbers from the above to perform corresponding operations : ");
        scanf("%d",&choice);

        switch(choice){

            case 1: {
                        size=insertion(&arr,size);
                        break;
                    }

            case 2: {
                        size=deletion(&arr,size);
                        break;
                    }

            case 3: {
                        search(arr,size);
                        break;
                    }

            case 4: {
                        traversal(arr,size);
                        break;
                    }

            default:{
                        printf("\nInvalid operation !! Enter a valid number.");
                    }

        }

        printf("\n\n\nDo you want to continue ? If yes type '1' or else type '0' to exit the program : ");
        scanf("%d",&isContinue);

        if(isContinue==0)
            //exit(0);
            break;
        else if(isContinue==1)
            continue;

        //fflush(stdin);

    }
}

int insertion(int *arr,int size){
    int new_element;
    printf("\nEnter the new element : ");
    scanf("%d",&new_element);

    *(arr+size)= new_element;
    size+=1;

    printf("\nThe modified array - [");
    for(int i=0;i<size;i++){
        printf("%3d",*(arr+i));
    }
    printf("  ]");
    return size;
}

int deletion(int* arr,int size){
    size-=1;
    printf("\nThe newly modified array - [");
    for(int i=0;i<size;i++){
        printf("%3d",*(arr+i));
    }
    printf("  ]");
    return size;
}

void search(int arr[],int size){
    int search_element, flag=0;
    printf("\nEnter an value of an element to searching from the array : ");
    scanf("%d",&search_element);

    for(int i=0;i<size;i++){
        if(arr[i]==search_element){
            flag=i;
            break;
        }
    }

    if(flag==1){
        printf("\nThe searched item's position : %d",flag+1);
    }
    else{
        printf("\nThe searched item not found !!");
    }

}

void traversal(int arr[],int size){
    printf("\nThe traversal of the array - [");
    for(int i=0;i<size;i++){
        printf("%3d",arr[i]);
    }
    printf("  ]");
}

