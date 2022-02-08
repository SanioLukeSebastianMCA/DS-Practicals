#include<stdio.h>
#include <stdlib.h>

void main()
{
    int l1,l2,i,op;
    printf("Enter the length of first set :");
    scanf("%d",&l1);
    printf("\nEnter the length of second set :");
    scanf("%d",&l2);
    int a[l1],b[l2],c[100];
    if(l1!=l2){
        printf("\nThe length of the set must be equal !!!");
    }
    else{
        printf("\nEnter the elements of first set (only 1 & 0):\n");
        for(i=0;i<l1;i++){
            while(1){
                int val;
                scanf("%d",&val);
                if(val==0 || val==1){
                    a[i]= val;
                    break;
                }
                else{
                    printf("\nInvalid input !! Please enter only 0 or 1 as values !!\n");
                }
            }

        }

        printf("\nEnter the elements of second set (only 1 & 0) :\n");
        for(i=0;i<l1;i++){
            while(1){
                int val;
                scanf("%d",&val);
                if(val==0 || val==1){
                    b[i]= val;
                    break;
                }
                else{
                    printf("\nInvalid input !! Please enter only 0 or 1 as values !!\n");
                }
            }
        }

        printf("\n\nSet Operations that you can perform are : ");
        printf("\n1. Union of sets \n2. Intersection of sets \n3. Difference of sets \n4. Exit");
        printf("\n\nChoose your option : ");
        scanf("%d",&op);
        printf("\nThe set 01 : ");
        for(int i=0;i<l1;i++){
            printf("%d", a[i]);
        }
        printf("\nThe set 02 : ");
        for(int i=0;i<l1;i++){
            printf("%d", b[i]);
        }
        switch(op){

            case 1: {
                        printf("\nThe union of the sets is : ");

                        for(i=0;i<l1;i++){
                            if(a[i]==1 || b[i]==1)
                                c[i]=1;
                            else
                                c[i]=0;
                            printf("%d",c[i]);
                        }
                        printf("\n\n");
                        break;
                    }

            case 2: {
                        printf("\nThe intersection of the sets is : ");
                        for(i=0;i<l1;i++){
                            if(a[i]==1 && b[i]==1)
                                c[i]=1;
                            else
                                c[i]=0;
                            printf("%d",c[i]);
                        }
                        break;
                    }

            case 3: {
                        printf("\nThe difference of the set is: ");
                        int neg_b[l2];
                        for(i=0;i<l2;i++){
                            if(b[i]==0)
                                neg_b[i]=1;
                            else
                                neg_b[i]=0;
                        }
                        for(i=0;i<l1;i++){
                            if(a[i]==1 && neg_b[i]==1)
                                c[i]=1;
                            else
                                c[i]=0;
                            printf("%d",c[i]);
                        }
                    }

            case 4: {
                        exit(0);
                    }
        }
    }
}
