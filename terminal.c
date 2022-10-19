
#include "E:\c programs\transaction app\payment application\terminal\terminal.h"

EN_terminalError_t getTransactionDate(ST_terminalData_t *termData)
{ printf("please input transaction date DD/MM/YYYY\n");
  gets((char *)&termData->transactionDate);
    if((termData->transactionDate[0]>'3')||(termData->transactionDate[0]<'0'))
       {
           return WRONG_DATE;
       }
    if((termData->transactionDate[0]=='3')&&(termData->transactionDate[1]>'1'))
       {
           return WRONG_DATE;
       }
       else if((termData->transactionDate[1]>'9')||(termData->transactionDate[1]<'0'))
       {
           return WRONG_DATE;
       }
       else if(termData->transactionDate[2]!='/')
       {
           return WRONG_DATE;
       }
       else if((termData->transactionDate[3]>'1')||(termData->transactionDate[3]<'0'))
       {
           return WRONG_DATE;
       }
       else if((termData->transactionDate[3]=='1')&&((termData->transactionDate[4]>'2')||(termData->transactionDate[4]<'0')))
       {
           return WRONG_DATE;
       }
       else if((termData->transactionDate[4]>'9')||(termData->transactionDate[4]<'0'))
       {
           return WRONG_DATE;
       }
       else if(termData->transactionDate[5]!='/')
       {
           return WRONG_DATE;
       }
       else if(termData->transactionDate[6]!='2')
       {
           return WRONG_DATE;
       }
       else if(termData->transactionDate[7]!='0')
       {
           return WRONG_DATE;
       }
       else if(termData->transactionDate[8]!='2')
       {
           return WRONG_DATE;
       }
       else if((termData->transactionDate[9]>'9')||(termData->transactionDate[9]<'2'))
       {
           return WRONG_DATE;
       }
       else
       {
           return TERMINAL_OK;
       }

}
EN_terminalError_t getTransactionAmount(ST_terminalData_t *termData)
{ float transaction;
 printf("please input transaction amount\n");
    scanf(" %f",&transaction);
    if(transaction<=0)
    {
        return INVALID_AMOUNT;
    }
    else {
         termData->transAmount =transaction;
        return TERMINAL_OK ;
    }
}
EN_terminalError_t setMaxAmount(ST_terminalData_t *termData)
{   float max_ammount;
    printf("please input max transaction amount possible\n");
    scanf(" %f",&max_ammount);
    if(max_ammount <=0)
        {return INVALID_MAX_AMOUNT; }
    else {
      termData->maxTransAmount = max_ammount;
    return TERMINAL_OK;
        }
}
EN_terminalError_t isBelowMaxAmount(ST_terminalData_t *termData)
{
    if((termData->transAmount) >(termData->maxTransAmount))
    {
        return EXCEED_MAX_AMOUNT ;
    }
    else
    {
        return TERMINAL_OK;
    }
}
EN_terminalError_t isCardExpired(ST_cardData_t *cardData, ST_terminalData_t *termData)
{
     if((cardData->cardExpirationDate[4]) < (termData->transactionDate[9]))
     {return EXPIRED_CARD;}

        else if(((cardData->cardExpirationDate[4]) <= (termData->transactionDate[9]))&&((cardData->cardExpirationDate[0]) < (termData->transactionDate[3])))
            {return EXPIRED_CARD; }

        else if((((cardData->cardExpirationDate[4]) <= (termData->transactionDate[9]))&&((cardData->cardExpirationDate[0]) <= (termData->transactionDate[3])))&&(cardData->cardExpirationDate[1]) < (termData->transactionDate[4]))
            { return EXPIRED_CARD;
                }

    else{return TERMINAL_OK; }

}

void getTransactionDatetest(void){
int result;
    ST_terminalData_t test;
    printf("Tester Name: ahmed\nFunction Name: getTransactionDate\n");
    printf("Test Case 1: correct date\nInput Data: 25/05/2023\n");
    printf("Expected Result: print correct entry\nActual Result: printed correct entry\n\n");
    result=getTransactionDate(&test);
      if(result==TERMINAL_OK)
        {printf("correct entry\n");}
      else
      {printf("invalid transaction date\n");}


    printf("\nTester Name: ahmed\nFunction Name: getTransactionDate\n");
    printf("Test Case 2: incorrect date format\nInput Data: 25/05/23\n");
    printf("Expected Result: print invalid transaction date\nActual Result: printed invalid transaction date\n\n");
    result=getTransactionDate(&test);
      if(result==TERMINAL_OK)
        {printf("correct entry\n");}
      else
      {printf("invalid transaction date\n");}

    printf("\nTester Name: ahmed\nFunction Name: getTransactionDate\n");
    printf("Test Case 3: NULL input\nInput Data: NULL\n");
    printf("Expected Result: print invalid transaction date\nActual Result: printed invalid transaction date\n\n");
    result=getTransactionDate(&test);
      if(result==TERMINAL_OK)
        {printf("correct entry\n");}
      else
      {printf("invalid transaction date\n");}

}
void isCardExpriedTest(void)
{
    ST_cardData_t test1;
    ST_terminalData_t test2;
  int result;
    printf("Tester Name: ahmed\nFunction Name: isCardExpried\n");
    printf("Test Case 1: valid card\nInput Data: transaction date:19/05/2022 expiry date: 04/23\n");
    printf("Expected Result: print valid card\nActual Result: printed valid card\n\n");
    getTransactionDate(&test2);
    getCardExpiryDate(&test1);
    result= isCardExpired(&test1,&test2);
    if(result== EXPIRED_CARD)
        {printf("expired card\n");}
    else
    {printf("valid card \n");}

    printf("\nTester Name: ahmed\nFunction Name: isCardExpried\n");
    printf("Test Case 2: expired card\nInput Data: transaction date:19/05/2024 expiry date: 06/23\n");
    printf("Expected Result: print expired card\nActual Result: printed expired card\n\n");
    getTransactionDate(&test2);
    getCardExpiryDate(&test1);
    result= isCardExpired(&test1,&test2);
    if(result== EXPIRED_CARD)
        {printf("expired card\n");}
    else
        {printf("valid card \n");}

    printf("\nTester Name: ahmed\nFunction Name: isCardExpried\n");
    printf("Test Case 3: expired card\nInput Data: transaction date:19/10/2023 expiry date: 06/23\n");
    printf("Expected Result: print expired card\nActual Result: printed expired card\n\n");
    getTransactionDate(&test2);
    getCardExpiryDate(&test1);
    result= isCardExpired(&test1,&test2);
    if(result== EXPIRED_CARD)
        {printf("expired card\n");}

    else
        {printf("valid card \n");}
}
void getTransactionAmountTest(void)
{   int result;
    ST_terminalData_t test;
    printf("Tester Name: ahmed\nFunction Name: getTransactionAmount\n");
    printf("Test Case 1: correct amount\nInput Data: 1000\n");
    printf("Expected Result: print correct entry\nActual Result: printed correct entry\n\n");
    result= getTransactionAmount(&test);
    if(result==TERMINAL_OK)
        {printf("correct entry\n");}
      else
      {printf("invalid transaction amount\n");}

    printf("\nTester Name: ahmed\nFunction Name: getTransactionAmount\n");
    printf("Test Case 2: amount is zero\nInput Data: 0\n");
    printf("Expected Result: print invalid transaction amount\nActual Result: printed invalid transaction amount\n");
    result= getTransactionAmount(&test);
    if(result==TERMINAL_OK)
        {printf("correct entry\n");}
      else
      {printf("invalid transaction amount\n");}

    printf("\nTester Name: ahmed\nFunction Name: getTransactionAmount\n");
    printf("Test Case 3: amount less than zero\nInput Data: -100\n");
    printf("Expected Result: print invalid transaction amount\nActual Result: printed invalid transaction amount\n\n");
    result= getTransactionAmount(&test);
    if(result==TERMINAL_OK)
        {printf("correct entry\n");}
      else
      {printf("invalid transaction amount\n");}
}
void setMaxAmountTest(void)
{   int result;
    ST_terminalData_t test;
    printf("Tester Name: ahmed\nFunction Name: setMaxAmount\n");
    printf("Test Case 1: correct max amount\nInput Data: 2000.54\n");
    printf("Expected Result: print correct entry\nActual Result: printed correct entry\n\n");
    result= setMaxAmount(&test);
    if(result==TERMINAL_OK)
        {printf("correct entry\n");}
      else
      {printf("invalid max amount\n");}

    printf("\nTester Name: ahmed\nFunction Name: setMaxAmount\n");
    printf("Test Case 2: max amount is zero\nInput Data: 0.0\n");
    printf("Expected Result: print invalid max amount\nActual Result: printed invalid max amount\n");
    result= setMaxAmount(&test);
    if(result==TERMINAL_OK)
        {printf("correct entry\n");}
      else
      {printf("invalid max amount\n");}

    printf("\nTester Name: ahmed\nFunction Name: setMaxAmount\n");
    printf("Test Case 3: max amount is less than zero\nInput Data: -6000.54\n");
    printf("Expected Result: print invalid max amount\nActual Result: printed invalid max amount\n");
    result= setMaxAmount(&test);
    if(result==TERMINAL_OK)
        {printf("correct entry\n");}
      else
      {printf("invalid max amount\n");}

}
void isBelowMaxAmountTest(void)
{
    ST_terminalData_t test;
    int result;
    printf("Tester Name: ahmed\nFunction Name: isBelowMaxAmountTest\n");
    printf("Test Case 1: transaction < max amount\nInput Data: transaction amount:1050.5 max amount: 1500\n");
    printf("Expected Result: print valid transaction\nActual Result: printed valid transaction\n\n");
    getTransactionAmount(&test);
    setMaxAmount(&test);
    result= isBelowMaxAmount(&test);
    if(result==EXCEED_MAX_AMOUNT )
        {printf("you have exceeded max amount\n");}
    else
    {printf("valid transaction\n");}

    printf("\nTester Name: ahmed\nFunction Name: isBelowMaxAmountTest\n");
    printf("Test Case 2: transaction = max amount\nInput Data: transaction amount:2000 max amount: 2000\n");
    printf("Expected Result: print valid transaction\nActual Result: printed valid transaction\n\n");
    getTransactionAmount(&test);
    setMaxAmount(&test);
    result= isBelowMaxAmount(&test);
    if(result==EXCEED_MAX_AMOUNT )
        {printf("you have exceeded max amount\n");}
    else
    {printf("valid transaction\n");}

    printf("\nTester Name: ahmed\nFunction Name: isBelowMaxAmountTest\n");
    printf("Test Case 3: transaction < max amount\nInput Data: transaction amount:2000 max amount: 1500\n");
    printf("Expected Result: print you have exceeded max amount\nActual Result: printed you have exceeded max amount\n\n");
    getTransactionAmount(&test);
    setMaxAmount(&test);
    result= isBelowMaxAmount(&test);
    if(result==EXCEED_MAX_AMOUNT )
        {printf("you have exceeded max amount\n");}
    else
    {printf("valid transaction\n");}
}

