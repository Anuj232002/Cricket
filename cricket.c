#include<stdio.h>
#include<string.h>

struct cricketnew
{
    int run;
    char name[50];
    int wicket;
    int t20_20;
    float avg_score;
    char type[20];
    char country[20];
}player[20];
void change(int i,int j,struct cricketnew player[])
{char na_me[10];
strcpy(na_me,player[i].name);
strcpy(player[i].name,player[j].name);
strcpy(player[j].name,na_me);

float score = player[i].avg_score;
player[i].avg_score = player[j].avg_score;
player[j].avg_score = score;

}
int main()
{int p,k,temp,tem,m,n,t_emp,l,t,choice,o;
float te_mp;
char country_name[10];
char na_me[20];
printf("\nEnter number of players:");
scanf("%d",&p);
for (int i = 0; i < p; i++)
{   printf("Player %d detail",i);
    printf("\nEnter name:");
    scanf("%s",player[i].name);
    printf("\nEnter number of 20-20 played:");
    scanf("%d",&player[i].t20_20);
    printf("\nEnter number of run:");
    scanf("%d",&player[i].run);
    printf("\nEnter wickets taken:");
    scanf("%d",&player[i].wicket);
    printf("\nEnter Average Score:");
    scanf("%f",&player[i].avg_score);
    printf("\nEnter Player type (Batsman/Bowler):");
    scanf("%s",player[i].type);
    printf("\nEnter Country:");
    scanf("%s",player[i].country);
}
do{
printf("\n****************************************");
printf("\n1.Display board");
printf("\n2.No. of batsman of particular country");
printf("\n3.Batsman as per average batting score");
printf("\n4.Batsman with highest average score");
printf("\n5.Bowler with highst wicket");
printf("\n6.No. of bowler of particular country");
printf("\n7.Display particular player info");
printf("\n8.Exit");
printf("\n");
printf("\nEnter choice:");
scanf("%d",&choice);

switch (choice)
{
case 1:
printf("Name\tRun\tWicket\tAvg.Score\tPlayer_type\t20-20 palyed\tCountry");
for (int i = 0; i < p; i++)
{
    printf("\n%s\t%d\t%d\t%f\t%s\t\t\t%d\t%s",player[i].name,player[i].run,player[i].wicket,player[i].avg_score,player[i].type,player[i].t20_20,player[i].country);
}
break;
case 2:
m=0;
printf("Enter name of country:");
scanf("%s",country_name);
for (int i = 0; i < p; i++)
{if(strcmp(country_name,player[i].country)==0 && strcmp(player[i].type,"Batsman")==0)
{
 m++;
}
}
printf("No. of batsman of particular country:%d",m);
break;
case 3:
for (int i = 0; i < p; i++)
{
    for (int j = i+1; j < p; j++)
    {
        if (player[i].avg_score>player[i].avg_score)
        {
            change(i,j,player);
        }
        
    }
    
}
printf("\nName\tAvg.score");
for (int i = 0; i < p; i++)
{
printf("\n%s\t%f",player[i].name,player[i].avg_score);
}

break;
case 4:
te_mp=player[0].avg_score;
t=0;
for (int i = 0; i < p; i++)
{
    if(player[i].avg_score>te_mp)
    {te_mp=player[i].avg_score;
    t=i;
    }
    
}
printf("Batsman name with highest batting score:%s",player[t].name);
break;
case 5:
temp=player[0].wicket;
for (int i = 0; i < p; i++)
{
    if(player[i].wicket>temp)
    {temp=player[i].wicket;
    k=i;
    }
    
}
printf("Bowler name with max wickets:%s",player[k].name);
break;
case 6:
n=0;
printf("Enter name of country:");
scanf("%s",country_name);
for (int i = 0; i < p; i++)
{if(strcmp(country_name,player[i].country)==0 && strcmp(player[i].type,"Bowler")==0)
{
 n++;
}
}
printf("No. of batsman of particular country:%d",n);
break;
case 7:

printf("Enter name of player: ");
scanf("%s",na_me);
for(int i=0;i<n;i++)
 {
if(strcmp(player[i].name,na_me)==0)
{
  o = i;
 break;
}
}
printf("\n");
printf("\nName : %s",player[o].name);
            
printf("\nCountry: %s",player[o].country);
printf("\nType : %s",player[o].type);
        
printf("\nNumber of 20-20's played: %d",player[o].t20_20);
printf("\nAverage score: %f",player[o].avg_score);
printf("\nMax-wickets taken: %d",player[o].wicket);
break;
case 8:

break;
default:
printf("Plese enter correct choice");
    break;
}
}while(choice!=8);
return 0;
}
