#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#define MAX_SIZE  6

typedef struct movie{
	int tickets;
	int snacks;
};
typedef struct friends{
	struct movie mv;
	char fname[20];
	int taxi;
	int breakfast;
	int lunch;
	int dinner;
	int total;
};
typedef struct totals{
	char tname[20];
	int totalpaid;
	int equalshare;
	int tobepaid;
	int getpaid;
};
void prln();

int main()
{
	int k, grandtotal=0, i;
	friends f[MAX_SIZE];
	totals t[MAX_SIZE];
	
	printf("   ****************************************************************************************\n");
	printf("   *  This Program Prints the Friends Names and Their Expenses as Given Below             *\n");
	printf("   ****************************************************************************************\n");
	printf("   *                                                                                      *\n");
	printf("   *  1. Summary of  Friend Names and Activity Expenses                                   *\n");
	printf("   *  2. Disribution of Expenses                                                          *\n");
	printf("   *  3. Activitywise Expenses Report                                                     *\n");
	printf("   *                                                                                      *\n");
	printf("   ****************************************************************************************\n");
	
	printf("\nFriend Names and Activity Expenses Entry\n\n");
	int p;
	for (p=0 ; p<MAX_SIZE ; p++)
	{
		printf("name of the %dst friend  :\t", p+1);
		scanf("%s", f[p].fname);
	}
	printf("-------------------------------------------------------\n");
	int sum;
	for (i=0 ; i<MAX_SIZE ; i++)
	{
		int sum=0;
		printf("%s 's Account              \n", f[i].fname);
		printf("how much for TAXI          : \t"); scanf("%d", &f[i].taxi); 
		printf("how much for BREAKFAST     : \t"); scanf("%d", &f[i].breakfast);
		printf("how much for LUNCH         : \t"); scanf("%d", &f[i].lunch); 
		printf("how much for DINNER        : \t"); scanf("%d", &f[i].dinner); 
		printf("how much for MOVIE Tickets : \t"); scanf("%d", &f[i].mv.tickets);
		printf("how much for MOVIE Snacks  : \t"); scanf("%d", &f[i].mv.snacks);
		f[i].total = f[i].taxi + f[i].breakfast + f[i].lunch + f[i].dinner + f[i].mv.tickets + f[i].mv.snacks;
		printf("--------------------------------\n");
		strcpy(t[i].tname,f[i].fname);
		t[i].totalpaid = f[i].total;
		grandtotal = grandtotal + t[i].totalpaid; 
	}
	int rows, cols;
	int e=0;
	printf("\n\nSummary of  Friendwise Activity Expenses\n");
	for (rows=0 ; rows<MAX_SIZE ; rows++)
	{
		if(e<1)
		{
			prln();
			printf("Names\t");
			printf("\t\tTaxi\t");
			printf("\tBreakfast\t");
			printf("Lunch\t");
			printf("\tDinner\t");
			printf("\tTickets\t");
			printf("\tSnacks\t");
			printf("\tTotal\t");  
			e++;
			prln();
		}
	
		printf("%s", f[rows].fname);
		if (strlen(f[rows].fname) < 20)
		{
			int j;
			j = 20 - strlen(f[rows].fname);
			for (cols=1 ; cols<j ; cols++)
			{
				printf(" ");				}
			}
			printf("\t%d\t", f[rows].taxi);
			printf("\t%d\t", f[rows].breakfast);
			printf("\t%d\t", f[rows].lunch);
			printf("\t%d\t", f[rows].dinner);
			printf("\t%d\t", f[rows].mv.tickets);
			printf("\t%d\t", f[rows].mv.snacks);
			printf("\t%d\t", f[rows].total);
			prln();
		}
		
	for (i=0 ; i<MAX_SIZE ; i++)
	{
		t[i].equalshare = grandtotal/MAX_SIZE;
		if (t[i].equalshare > t[i].totalpaid)
		{
			t[i].tobepaid = t[i].equalshare - t[i].totalpaid;
			t[i].getpaid = 0;
		}
		else
		{
			t[i].getpaid = t[i].totalpaid - t[i].equalshare;
			t[i].tobepaid = 0;
		}
	}
		
	 e=0;
	printf("\n\nThis Report Distributes the Expenses incurred among Friends\n");
	for (i=0 ; i<MAX_SIZE ; i++)
	{
		if(e<1)
		{
			prln();
			printf("Names               ");
			printf("\tTotal Paid\t");
			printf("Equal Share\t");
			printf("To Pay\t");
			printf("\tGet paid\t");  
			e++;
			prln();
		}
	printf("%s", t[i].tname);
	if (strlen(t[i].tname) < 20)
	{
		int j;
		j = 20 - strlen(t[i].tname);
		for (cols=1 ; cols<j ; cols++)
		{
			printf(" ");
		}
	}
    	printf("\t%d\t", t[i].totalpaid);
		printf("\t%d\t", t[i].equalshare);
		printf("\t%d\t", t[i].tobepaid);
		printf("\t%d\t", t[i].getpaid);
		prln();
	}
	e=0;
	int taxi=0;
	printf("\n\n\nThis Report gives details of Activitywise Expenses \n");
	prln();
	for (i=0 ; i<MAX_SIZE ; i++)
	{
		taxi = taxi + f[i].taxi;
	}
	printf("Total Expenses for TAXI       : %d\n", taxi);
	taxi=0;
	for (i=0 ; i<MAX_SIZE ; i++)
	{
		taxi = taxi + f[i].breakfast;
	}
	printf("Total Expenses for BREAKFAST  : %d\n", taxi);
	taxi=0;
	for (i=0 ; i<MAX_SIZE ; i++)
	{
		taxi = taxi + f[i].lunch;
	}
	printf("Total Expenses for LUNCH      : %d\n", taxi);
	taxi=0;
	for (i=0 ; i<MAX_SIZE ; i++)
	{
		taxi = taxi + f[i].dinner;
	}
	printf("Total Expenses for DINNER     : %d\n", taxi);
	taxi=0;
	for (i=0 ; i<MAX_SIZE ; i++)
	{
		taxi = taxi + f[i].mv.tickets;
	}
	printf("Total Expenses for TICKETS    : %d\n", taxi);
	taxi=0;
	for (i=0 ; i<MAX_SIZE ; i++)
	{
		taxi = taxi + f[i].mv.snacks;
	}
	printf("Total Expenses for SNACKS     : %d\n", taxi);
	prln();
}

void prln()
{
	printf("\n-------------------------------------------------------------------------------------------------------------------------------\n");
}


