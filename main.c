#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "E:\c programs\transaction app\payment application\card\card.h"
#include "E:\c programs\transaction app\payment application\terminal\terminal.h"
#include "E:\c programs\transaction app\payment application\server\server.h"
#include "E:\c programs\transaction app\payment application\application\application.h"

 ST_accountsDB_t accountsDB[255];
 ST_transaction_t transactionDB[255];
void fill_accountDB(void);  // this function fills account database , to show database numbers remove (//)before each printf in the function
extern int account_order;
extern int accountRefrence;

int main()
{

fill_accountDB();

  appStart();


    return 0;
}
void fill_accountDB(void)
{   int i;

    strcpy((char *)accountsDB[0].primaryAccountNumber,"3214567891234561234");//state: blocked,balance: 41.000000
    strcpy((char *)accountsDB[1].primaryAccountNumber,"3214567891234561255");//state: running ,balance: 6334.000000
    strcpy((char *)accountsDB[2].primaryAccountNumber,"3214567891234561326");//state: running ,balance: 19169.000000
    strcpy((char *)accountsDB[3].primaryAccountNumber,"3214567891234561347");//state: running ,balance: 11478.000000
    strcpy((char *)accountsDB[4].primaryAccountNumber,"3214567891234561518");//state: running ,balance: 26962.000000
    strcpy((char *)accountsDB[5].primaryAccountNumber,"3214567891234561789");//state: blocked ,balance: 5705.000000
    strcpy((char *)accountsDB[6].primaryAccountNumber,"3214567891234561810");//state: blocked ,balance: 23281.000000
    for(i=0;i<7;i++)
        { int buffer=0;
            accountsDB[i].balance=(float)(rand()%1000000);
        printf("{%f",accountsDB[i].balance);
         buffer=(rand()%2);
         accountsDB[i].state=(EN_accountState_t)buffer ;
              if(accountsDB[i].state==BLOCKED)
                {
                    printf(", blocked");
                }
                else
                    {
                      printf(", running");
                    }
        printf(" ,%s}\n",accountsDB[i].primaryAccountNumber);//*/

       }

}

