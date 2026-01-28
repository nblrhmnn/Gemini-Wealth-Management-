#include <stdio.h>
#include <string.h>

void greeting(); 																										// FILE 
void intro();																											// NABILA RAHMAN INTRODUCTION 			
void displayRate();																										// 2D ARRAY																											
void input(char *name, char *phone, float *income, char *employmentCategory, int *financialPlan, int *dependant);		// NABILA RAHMAN INPUT
void displayIncomeLevel(float income);																					// ARIFAH DISPLAY INCOMETYPE@LEVL
void incomeLevel1(float income, char employmentCategory, int financialPlan, float saving[], int financialType[]);			// ARIFAH INCOME LEVEL 1
void incomeLevel2(float income, char employmentCategory, int financialPlan, float saving[], int financialType[]);			// NABILAH INCOME LEVEL 2
void incomeLevel3(float income, char employmentCategory, int financialPlan, float saving[], int financialType[]);			// ATIEKA INCOME LEVEL 3
float calcdiscount(float income, int dependant, int *financialType, float *saving, float *savingafterdiscount, int financialPlan);					// NABILA RAHMAN DISCOUNT DEPENDENT
float calcserviceRate(float income);																												// ARIFAH SERVICE CHARGE
float calcSavings(int financialPlan, float saving[]);																							// NABILAH TOTAL SAVING
void displayReceipt(int financialPlan, int *financialType, float *saving, char employmentCategory, float income, char *name, char *phone, float *savingafterdiscount, float discount, float servicecharge, float totalSavings);	  // ATIEKA DISPLAY RECIPT
char next();                                                                                                                // ATIEKA NEXT CUSTOMER
void displayReport(int totalCustomers, float Profit);																	//  NABILAH DISPLAY REPORT

int main() // MAIN FUNCTION
{
    char name[50], phone[20], num[3][3][15], Title[100];
	char employmentCategory, anothercust;
    float saving[3], savingafterdiscount[3];
    int dependant, financialPlan, financialType[3];
    int numCustomers;
    int totalCustomers=0;
    float Profit, totalSavings, totalService,servicecharge, income, discount ;

    greeting();
    intro();
    displayRate();
    do
    {
	    input(name, phone, &income, &employmentCategory, &financialPlan, &dependant);
    	displayIncomeLevel(income);

		if (income <5000)
    	{
    	    incomeLevel1 (income, employmentCategory, financialPlan, saving, financialType);
    	}
    	else if (income < 10000)
    	{
    	    incomeLevel2 (income, employmentCategory, financialPlan, saving, financialType);
    	}
    	else
    	{
    	    incomeLevel3 (income, employmentCategory, financialPlan, saving, financialType);
    	}
    	discount = calcdiscount(income, dependant, financialType, saving, savingafterdiscount, financialPlan);
    	servicecharge = calcserviceRate(income);
    	totalSavings = calcSavings(financialPlan, saving);
    	displayReceipt(financialPlan, financialType, saving, employmentCategory, income, name, phone, savingafterdiscount, discount, servicecharge, totalSavings);

    	printf("\n\n-----------------------------------------------------------------\n");

    	anothercust=next();
		totalCustomers++;						//COUNT CUSTOMER
		Profit+=servicecharge	;			//COUNT PROFIT
	}
	while(anothercust=='Y' || anothercust=='y');

	displayReport(totalCustomers, Profit);

    return 0;
}

void greeting()													//FILE
{
    FILE *myFile;
    char Title[100];

    myFile = fopen("Title.txt", "w");
    fprintf(myFile, "\t\t\t      WELCOME TO GEMINI WEALTH MANAGEMENT!");
    fclose(myFile);

    myFile = fopen("Title.txt", "r");
    fgets(Title, 100, myFile);
    puts(Title);

    fclose(myFile);
}

void intro()   // NABILA RAHMAN INTRODUCTION																		
{
    printf("\n\t\t\t        ~*+ GEMINI WEALTH MANAGEMENT +*~ \n");
    printf("\t\t\t      Invest in Your Tomorrow: Save Today! \n\n");
}

void displayRate()													 // 2D ARRAY
{
    char num[3][3][15] = {
        {" < RM5000", "3%"},
        {" < RM10000", "8%"},
        {">= RM10000", "12%"}
    };

    printf("\t\t--------------------------------------------------------------\n");
    printf("\n\t\t    Here is our charge service rate based on income level;\n\n");
    printf(" \t\t\t\tB40 |\t%s  |  \t%s\n", num[0][0], num[0][1]);
    printf(" \t\t\t\tM40 |\t%s | \t%s\n", num[1][0], num[1][1]);
    printf(" \t\t\t\tT20 |\t%s | \t%s\n\n", num[2][0], num[2][1]);
    printf("\t\t--------------------------------------------------------------\n");
}

void input(char *name, char *phone, float *income, char *employmentCategory, int *financialPlan, int *dependant) 	 // NABILA RAHMAN INPUT
{
    float saving[3];
    int financialType[3], i;

	fflush(stdin);
    printf("\nEnter your Name: ");
    gets(name);
    fflush(stdin);

	fflush(stdin);
    printf("Enter your Phone Number: ");
    scanf("%s", phone);

    printf("Enter your Salary Income: RM ");
    scanf("%f", &*income);

    printf("Enter Employment Category [G: Government Sector, P: Private Sector, S: Self-Employment]: ");
    scanf(" %c", &*employmentCategory);

    printf("Enter your Total Dependant: ");
    scanf("%d", &*dependant);

    printf("Enter how many Financial Plans you want: ");
    scanf("%d", &*financialPlan);

}

void displayIncomeLevel(float income)									//ARIFAH DISPLAY INCOME LEVEL TYPE
{
    if(income < 5000)
    {
        printf("You are included in income level of B40.\n");
    }
    else if(income < 10000)
    {
        printf("You are included in income level of M40.\n");
    }
    else
    {
        printf("You are included in income level of T20.\n");
    }
}

void incomeLevel1(float income, char employmentCategory, int financialPlan, float saving[], int financialType[]) 		//ARIFAH INCOME LEVEL 1
{
    int i;

    for (i = 0; i < financialPlan; i++)
    {
        printf("Enter Financial Plan [1. Medical Expenses, 2. Education, 3. Loan Repayments]: ");
        scanf("%d", &financialType[i]);

        if (employmentCategory=='G')
        {
            if (financialType[i] == 1)
            {
                saving[i] = 0.01 * income;
            }
            else if (financialType[i] == 2)
            {
                saving[i] = 0.02 * income;
            }
            else 
            {
                saving[i] = 0.05 * income;
            }
        }
        else if(employmentCategory=='P')
        {
            if (financialType[i] == 1)
            {
                saving[i] = 0.03 * income;
            }
            else if (financialType[i] == 2)
            {
                saving[i] = 0.03 * income;
            }
            else 
            {
                saving[i] = 0.07 * income;
            }
        }
        else
        {
            if (financialType[i] == 1)
            {
                saving[i] = 0.05 * income;
            }
            else if (financialType[i] == 2)
            {
                saving[i] = 0.08 * income;
            }
           else
            {
                saving[i] = 0.10 * income;
            }
        }
    }
}
void incomeLevel2(float income, char employmentCategory, int financialPlan, float saving[], int financialType[]) { 		//NABILAH INCOME LEVEL2
    int i;

    for (i = 0; i < financialPlan; i++)
    {
        printf("Enter Financial Plan [1. Medical Expenses, 2. Education, 3. Loan Repayments]: ");
        scanf("%d", &financialType[i]);

        if(employmentCategory=='G')
        {
            if (financialType[i] == 1)
            {
                saving[i] = 0.07* income;
            }
            else if (financialType[i] == 2)
            {
                saving[i] = 0.08 * income;
            }
            else 
            {
                saving[i] = 0.13 * income;
            }
        }
        else if(employmentCategory=='P')
        {
            if (financialType[i] == 1)
            {
                saving[i] = 0.10 * income;
            }
            else if (financialType[i] == 2)
            {
                saving[i] = 0.12 * income;
            }
            else 
            {
                saving[i] = 0.15 * income;
            }
        }
        else
        {
            if (financialType[i] == 1)
            {
                saving[i] = 0.20 * income;
            }
            else if (financialType[i] == 2)
            {
                saving[i] = 0.15 * income;
            }
            else
            {
                saving[i] = 0.17 * income;
            }
        }
    }
}


void incomeLevel3(float income, char employmentCategory, int financialPlan, float saving[], int financialType[])  		//ATIEKA INCOMELEVEL 3
{
    int i;

    for (i = 0; i < financialPlan; i++)
    {
        printf("Enter Financial Plan [1. Medical Expenses, 2. Education, 3. Loan Repayments]: ");
        scanf("%d", &financialType[i]);

        if(employmentCategory=='G')
        {
            if (financialType[i] == 1)
            {
                saving[i] = 0.13 * income;
            }
            else if (financialType[i] == 2)
            {
                saving[i] = 0.15 * income;
            }
            else
            {
                saving[i] = 0.18 * income;
            }
        }
        else if(employmentCategory=='P')
        {
            if (financialType[i] == 1)
            {
                saving[i] = 0.17 * income;
            }
            else if (financialType[i] == 2)
            {
                saving[i] = 0.13 * income;
            }
            else
            {
                saving[i] = 0.18 * income;
            }
        }
        else
        {
            if (financialType[i] == 1)
            {
                saving[i] = 0.18 * income;
            }
            else if (financialType[i] == 2)
            {
                saving[i] = 0.15 * income;
            }
            else
            {
                saving[i] = 0.20 * income;
            }
        }
    }
}

float calcdiscount(float income, int dependant, int *financialType, float saving[], float *savingafterdiscount, int financialPlan)	// NABILA RAHMAN DISCOUNT DEPENDENT
{
    float discount = 0;
	int i;

     for (i = 0; i < financialPlan; i++) {
        if (dependant < 3)
		{
            if (financialType[i] == 1 || financialType[i] == 2)
			{
                savingafterdiscount[i] = saving[i] - saving[i] * 0.02;
                discount += savingafterdiscount[i];
            }
			else 
			{
                savingafterdiscount[i] = saving[i] - saving[i] * 0.01;
                discount += savingafterdiscount[i];
            }
        }
		else if (dependant < 6) 
		{
            if (financialType[i] == 1 || financialType[i] == 2)
			{
                savingafterdiscount[i] = saving[i] - saving[i] * 0.04;
                discount += savingafterdiscount[i];
            } 
			else 
			{
                savingafterdiscount[i] = saving[i] - saving[i] * 0.02;
                discount += savingafterdiscount[i];
            }
        }
		else 
		{
            if (financialType[i] == 1 || financialType[i] == 2) 
			{
                savingafterdiscount[i] = saving[i] - saving[i] * 0.06;
                discount += savingafterdiscount[i];
            } 
			else  
			{
                savingafterdiscount[i] = saving[i] - saving[i] * 0.04;
                discount += savingafterdiscount[i];
            }
        }
    }

    return discount;
}

float calcserviceRate(float income)										//ARIFAH SERVICE RATE CHARGE
{
	float rate;

    if(income < 5000)
    {
        rate = 0.03 * income;
    }
    else if(income < 10000)
    {
        rate = 0.08 * income;
    }
    else
    {
        rate = 0.12 * income;
    }

    return rate;
}

float calcSavings(int financialPlan, float saving[])						// NABILAH CACLSAVING
{
    int i;
    float total = 0;

    for (i = 0; i < financialPlan; i++)
    {
        total += saving[i];
    }
    return total;
}

void displayReceipt(int financialPlan, int *financialType, float *saving, char employmentCategory, float income, char *name, char *phone, float *savingafterdiscount, float totaldiscount, float servicecharge, float totalSavings)      //ATIEKA DISPLAY RECEIPT
{
    int i;
    char type[20];

    printf("\n\n--------------------------- RECEIPT ----------------------------\n\n");
    printf("Name: %s\n", name);
	printf("Phone: %s\n", phone);
    printf("Income: RM %.2f\n", income);

    if (employmentCategory == 'G' || employmentCategory == 'g')
    {
        printf("Employment Category: Government\n");
    }
    else if (employmentCategory == 'P' || employmentCategory == 'p')
    {
        printf("Employment Category: Private\n");
    }
    else if (employmentCategory == 'S' || employmentCategory == 's')
    {
        printf("Employment Category: Self-Employment\n");
    }
    else
    {
        printf("Invalid input");
        return;
    }

    printf("Financial Plan: %d\n\n", financialPlan);

    printf("    Financial Type\tSaving\t\tSaving After Discount\n");
    for (i = 0; i < financialPlan; i++)
    {
        if (financialType[i] == 1)
        {
            strcpy(type, "Medical Expenses");
            printf("#%d. %s\tRM %.2f\tRM %.2f\n", i + 1, type, saving[i], savingafterdiscount[i]);
        }
        else if (financialType[i] == 2)
        {
            strcpy(type, "Education");
            printf("#%d. %s\t\tRM %.2f\tRM %.2f\n", i + 1, type, saving[i], savingafterdiscount[i]);
        }
        else if (financialType[i] == 3)
        {
            strcpy(type, "Loan Repayments");
            printf("#%d. %s\tRM %.2f\tRM %.2f\n", i + 1, type, saving[i], savingafterdiscount[i]);
        }
        else
        {
            printf("Invalid input");
        }
    }

    printf("\nTotal discount that you get [Based on the dependents]:  RM%.2f\n", totaldiscount);
    printf("Total amount that you need to save:  RM%.2f", totalSavings);
    printf("\nService charge You need to pay: RM%.2f", servicecharge);

}

char next() // ATIEKA NEXT CUSTOMER
{
	char anothercust;
	
	printf("\nAnother customer? [Y: Yes, N: No]: ");
	scanf(" %c", &anothercust);
	
	return anothercust;
}


void displayReport(int totalCustomers, float Profit) 			// NABILAH DISPLAY REPORT 
{
    printf("\n************ Company Report ************\n");

    printf("Total Customers: %d\n", totalCustomers);
    printf("Total Profit: %.2f\n", Profit);


    printf("****************************************\n");
}


