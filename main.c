#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LENGHT 100
void DATA(int IDs[], int passwords[], float balances[]);
void LOGIN(int IDs[], int passwords[], float balances[]);
int main()
{
   int IDs[LENGHT];
   int passwords[LENGHT];
   float balances[LENGHT];
   char regime[LENGHT];
   int isExit = 0;
   while(isExit == 0){
        printf("Please enter a regime\n");
        scanf("%s",regime);
        if(strcmp(regime, "DATA") == 0){
            DATA(IDs,passwords,balances);
        }
        else if(strcmp(regime, "LOGIN") == 0){
            LOGIN(IDs,passwords,balances);
        }
        else if(strcmp(regime, "EXIT") == 0){
            isExit =1;
        }

        else {
            printf("Please login\n");
        }
   }
   return 0;
}
void DATA(int IDs[], int passwords[], float balances[])
{

   for(int i=0;i<LENGHT;)
   {
       for(int j=0;j<LENGHT;)
       {
           for(int k=0;k<LENGHT;k++, i++, j++)
           {
            printf("Enter ID, password and balance\n");
            scanf("%d" "%d" "%f",&IDs[i], &passwords[j], &balances[k]);
            if(balances[k]== 0)
            {
                break;
            }
            while(balances[k] < 0)
            {
                printf("Invalid sum, try again\n");
                scanf("%f", &balances[k]);
            }
            for(int l = 2; l<LENGHT; l++)
            {
                if(IDs[i] == IDs[l])
                {
                    printf("That ID already exists, try again\n");
                    scanf("%d", &IDs[i]);
                    break;
                }

            }
           }
               if(passwords[j] == 0)
               {
                   break;
               }
       }
       if(IDs[i] == 0)
       {
           break;
       }
   }
}
void LOGIN(int IDs[], int passwords[], float balances[])
{
    int currentID, currentPassword, i=0;
    printf("Please enter ID and password\n");
    scanf("%d" "%d", &currentID, &currentPassword);
    for(i;i<LENGHT;i++)
    {
     if(currentID == IDs[i] && currentPassword == passwords[i])
     {
      printf("You entered account %d\n",IDs[i]);
    while(1){
        char regime[LENGHT];
        printf("Please enter a regime\n");
        scanf("%s",regime);
        if(strcmp(regime,"DRAW") == 0)
        {
            float sumToDraw;
            printf("Enter a sum to draw\n");
            scanf("%f",&sumToDraw);
            if(sumToDraw > balances[i])
            {
                printf("Sum is too large");
            }
            else{
                balances[i] -= sumToDraw;
                }
        }
        else if(strcmp(regime,"PUT") == 0)
        {
            float sumToPut;
            printf("Enter a sum to put\n");
            scanf("%f",&sumToPut);
            balances[i] += sumToPut;
        }
        else if(strcmp(regime,"INFO") == 0)
        {
            printf("Your balance is %.2f\n",balances[i]);
        }
        else if(strcmp(regime,"TRANSFER") == 0)
        {
            int transferID;
            printf("Enter an ID for transfer\n");
            scanf("%d", &transferID);
            for(int k = 0; k<LENGHT; k++)
            {
                if(transferID == IDs[k])
                {
                    float sumToTransfer;
                    printf("Enter a sum you wish to transfer\n");
                    scanf("%f", &sumToTransfer);
                    balances[i]-=sumToTransfer;
                    balances[k]+=sumToTransfer;
                    break;
                }

            }
            printf("That ID doesn't exist\n");
        }
        else if(strcmp(regime, "LOGOUT") == 0)
        {
            break;
        }

        }
     }
            else if(currentID == IDs[i] && currentPassword != passwords[i])
            {
                printf("Wrong password\n");
            }
    }




}

