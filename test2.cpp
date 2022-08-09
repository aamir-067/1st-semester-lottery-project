#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<conio.h>
#include<time.h>
int main()
{
	/*
	   nop = number of persons
	   nom = number of months
	   mc = 1 month collcetion form every person
	*/
	int ran[12];   
	int nop,nom,mc;
	int t=0;
	int temp1,temp2,temp3,temp4=0; // temporary ints used in multipal places
	
	printf("Enter a number of persons \n");
	printf("Persons must be greater then 6 and less then 12\n");
	scanf("%d",&nop);
	
	system("cls");
	
	if(nop<6 || nop>12 || (nop<6 && nop>12)){
		
		printf("People must be greater the 6 and less then 12 please try again\n");
		printf("Do you want to try again? [1/0] \n");
		scanf("%d",&temp1);
		
		if(temp1==1){
			
			system("cls");
			main();
		}
		else{
			return 0;
		}
	}
	else
	
	nom=nop;
	printf("Number of months will be = %d\n",nop);
	
	int tc[nop][nom];  // s=total collection of each person 		//tc[][] = persons and months 
	int s[12];
	//rows=persons colums=months
	temp3=nop;
	
	printf("How much money you want to collcet every month from each person \n");
	scanf("%d",&mc);
	
	system("cls");
	srand(time(NULL));
	
	for(int m=1;m<=nom;m++)
	{
		
		for(int p=1;p<=nop;p++)
		{
			temp2=0;
			printf("Enter a money of person %d in month %d \n",p,m);
			scanf("%d",&tc[m-1][p-1]);
		
			if( tc[m-1][p-1] < mc )
			{
			
				printf("The person %d entered money less then %d so the person is kicked from lottery\n",p,mc);
				t=t+tc[m-1][p-1];
				temp2=2;
				temp4++;
			}
			else;
			{
				temp2=1;
				t=t+tc[m-1][p-1];
			}
			
			
		}
		system("cls");
		printf("Collection of month %d is = %d\n",m,t);
		printf("Press ant key...");
		getch();
		
		ran[m-1] = rand() % temp3+1;
		
		printf("\nThe random selected person is person %d \n", ran[m-1] );
		printf("He Got Money = %d\n",t);
		printf("Press ant key...");
		getch();
		
		s[m-1]=t;
		t=0;
		
		
		if(temp2==2)
			nop-=2;
		else
			nop--;			
		system("cls");
	}
	
	
	printf("\t\t\t ||========== FULL LIST ==========|| \n\n");
	printf("Person No. \t\t Investment \t\t Got in lottery \t\t Profit/Loss\n");
	
	for(int y=1;y<=temp3-temp4;y++)
	{
		printf("Person %d \t\t %d \t\t\t %d \t\t\t\t %d\n", ran[y-1] , mc*y , s[y-1] , s[y-1] - mc*y );
	}
	
	return 0;
	
}		
		