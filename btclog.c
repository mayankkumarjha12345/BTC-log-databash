#include<stdio.h>
#include<stdlib.h>

void add(void);
void sh(void);
void calculate();

struct btc{
    float amount;
    char date[10];
}s;
int main()
{
    while(1){
    int choice;
    printf("\n1.Add\n2.Display\n3.Calculate\n4.Exit");
    printf("\nEnter your choice :");
    scanf("%d",&choice);

    switch(choice){
    case 1:
        add();
        break;
    case 2:
        sh();
        break;
    case 3:
        calculate();
        break;
    case 4:
        exit(-1);
    default:
        printf("Wrong choice :(");
        }
    }
    return 0;
}

void add(){
    FILE *fp;
   printf("Enter BTC amount :");
   scanf("%f",&s.amount);
   printf("Enter date :");
   scanf("%s",s.date);
      fp = fopen("btclog.txt", "a");
   fprintf(fp, "\n=>\nDate = %s\nBtc = %f",s.date,s.amount);
   fclose(fp);
}

void sh(){
    int i=0;
    FILE * fp;
    char str[1000];
    fp = fopen( "btclog.txt" , "r");
    if (fp){
    while(fgets(str, 999, fp)!=NULL)
	{
		printf("\t%s",str);
		if(i==3){
            printf("\n");
            i=0;
		}
        i++;
	}
    fclose(fp);
    }
}

void calculate()
{
    float a,b;
    printf("\tEnter 1st number :");
    scanf("%f",&a);
    printf("\tEnter 2nd number :");
    scanf("%f",&b);

    printf("\tThe result is :%f",a-b);
}
