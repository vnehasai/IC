#include<stdio.h>
long long int withdrawl(long long int *a,long long int b)
{
    long long int c;
    if(*a<b)
{
    printf("INSUFFICIENT BALANCE\n");
    return -2; 
}
else{
    *a=*a-b;
    c=*a;
}
return c;
}
long long int deposit(long long int *a,long long int b)
{
    *a=*a+b;
    long long int c;
    c=*a;
    return c;
}
void paschange(long long int *a,long long int b)
{
    *a=b;
}
void trans_am(long long int *a,long long int *b,long long int c)
{
    *a-=c;
    *b+=c;
}
struct data
{    char acc_name[50];
    long long int acc_no;
    long long int pas;
    long long int cur_bal;
};
int main()
{  
    int count1=0;
    int count2=0;
   FILE *fp=NULL;
fp=fopen("atm.txt","r");
if(fp==NULL)
{
    printf("error");
    return 1;
} 
 else{
  char abc;
  while((abc=fgetc(fp))!=EOF)
  {
    if(abc=='\n')
    {
        count1++;
    }
  }
 // printf("no.of entries:%d\n",count1);
 }
 fclose(fp);
 fp=fopen("atm.txt","r");
struct data group[count1];
int r;
char str1[20],str2[20],str3[20],str4[25];
fscanf(fp,"%s %s %s %s\n",str1,str2,str3,str4);
for(r=0;r<count1;r++)
{
   fscanf(fp,"%s %lld %lld %lld%*c",group[r].acc_name,&group[r].acc_no,&group[r].pas,&group[r].cur_bal);
  // printf("%lld %lld %lld\n",group[r].acc_no,group[r].pas,group[r].cur_bal);
}
     long long int accno,password;
   
    int i;
    printf("Enter your account number:\n");
    scanf("%lld",&accno);
    int k=-2;
    int m=0;
     for(i=0;i<count1;i++)
     {
        if(accno==group[i].acc_no)
        {
         k=i;
         break;
        }    
     }
     fclose(fp);
    // printf("found number:%d",k);
     if(k== -2)
     {
        printf("Account number not found\n");
        printf("Do you want to  create a new account?\n");
        printf("1.YES\n2.NO\n");
        int acreate;
        scanf("%d",&acreate);
        if(acreate==1)
        {
        printf("Enter your account no:\n");
        long long int acnewcreate;
        scanf("%lld",&acnewcreate);
        long long int acnewpas;
        printf("Enter your password\n");
        scanf("%lld",&acnewpas);
        long long int confirmpas;
        printf("Enter again for confirming your password:\n");
        scanf("%lld",&confirmpas);
        if(acnewpas==confirmpas)
        {
            
            fp=fopen("atm.txt","a");
            printf("Enter account holder name:\n");
           char name[50];
           scanf("%s",name);
            fprintf(fp,"\n%s %lld %lld 0",name,acnewcreate,acnewpas);
           // fclose(fp);
            printf("ACCOUNT CREATED\nTHANK YOU\nVISIT AGAIN");
            fclose(fp);
            return 0;
        }
        else{
            printf("The password you have entered before and now are not matching\nTRY AGAIN");
            return 0;
        }
        }
        else{
            printf("THANK YOU\nVISIT AGAIN");
            return 0;
        }
     }
     else
     {
     printf("Enter your pin number:\n");
    scanf("%lld",&password);
     if(password==group[k].pas)
     {
      m=1;
     }
    else{
           // printf("%d\n",k);
            printf("INCORRECT PASSWORD\nTRY AGAIN");
            return 0;
        }
     if(m==1)
     {
    long long int c;
    int chopt;
    long long int witam,depam;
    printf("WELCOME %s\n",group[k].acc_name);
    printf("Select an option\n");
    printf("1.Check balance\n");
    printf("2.Cash Withdrawl\n");
    printf("3.Cash deposit\n4.Change pin no:\n5.Transfer fund\n");
    scanf("%d",&chopt);
    if(chopt==1)
    {   
        printf("Current balance=");
        printf("%lld",group[k].cur_bal);
    }
    if(chopt==2)
    {
        printf("Enter the amount you want to withdrawl:\n");
        scanf("%lld",&witam);
        c=withdrawl(&group[k].cur_bal,witam);
        if(c==-2)
        {
          printf("Current balance=%lld",group[k].cur_bal);  
        }
        else
        {
        printf("Amount withdrawn successfully\n");
        printf("Current balance=%lld",c);
        }
    }
    if(chopt==3)
    {
        printf("Enter the amount you want to deposit:\n");
        scanf("%lld",&depam);
        c=deposit(&group[k].cur_bal,depam);
        printf("Amount deposited successfully\n");
        printf("Current balance=%lld",c);
    }
    if(chopt==4)
    {
        long long int pas_check,pas_change,pas_change_ver;
        printf("Enter your pin no again for more authentication:\n");
        scanf("%lld",&pas_check);
        if(pas_check==group[k].pas)
        {
            printf("Enter your new pin no:\n");
            scanf("%lld",&pas_change);
            printf("Enter your password new pin no again:\n");
            scanf("%lld",&pas_change_ver);
            if(pas_change==pas_change_ver)
            {
         paschange(&group[k].pas,pas_change);
         printf("PIN NUMBER CHANGED SUCCESSFULLY\n");
            }
            else{
                printf("The pin numbers you entered are not the same\nCHECH AGAIN\nTHANK YOU\n");
                return 0;
            }
        }
        else{
            printf("INCORRECT PIN NO\nTRY AGAIN\n");
        }
    }
    if(chopt==5)
    {
       
        long long int pas_check;
        printf("Enter your pin no again for more authentication:\n");
        scanf("%lld",&pas_check);
        if(pas_check==group[k].pas)
        {
            printf("Enter the account number to which you want to transfer money:\n");
            long long int transfer_acc,transfer_acc_check;
            scanf("%lld",&transfer_acc);
            int t;
            int n= -2;
            fp=fopen("atm.txt","r");
             for( t=0;t<count1;t++)
               {
                
                if(transfer_acc==group[t].acc_no)
                 {
                 n=t;
                 break;
                }
               }
               fclose(fp);
               //printf("transfer account status:\n%d",n);
                if(n== -2)
                {
                    printf("Account not found\nCHECK AGAIN");
                    return 0;
                }
                else{
            printf("Enter once again the account number to which you want to transfer money for more safety:\n");
            scanf("%lld",&transfer_acc_check);
            if(transfer_acc==transfer_acc_check)
            {

            
                printf("Enter the amount you want to transfer:\n");
                long long int transfer_amount,transfer_amount_check;
                scanf("%lld",&transfer_amount);
                printf("Enter once again the amount you want to transfer for more safety:\n");
                scanf("%lld",&transfer_amount_check);
                if(transfer_amount==transfer_amount_check)
                {
            if(transfer_acc==transfer_acc_check)
            {
                if(transfer_amount>group[k].cur_bal)
                {
                    printf("INSUFFICIENT FUND\nYour CURRENT BALANCE is:\n%lld",group[k].cur_bal);
                }
                else{
                trans_am(&group[k].cur_bal,&group[t].cur_bal,transfer_amount);
                printf("AMOUNT TRANSFERRED SUCCESSFULLY\nYour Current balance:%lld",group[k].cur_bal);  
                }
                }
                }
                else{
                    printf("The amount you entered before and now are not same\n TRY AGAIN  ");
                    return 0;
                }
            }
            else{
                printf("The account number you gave now is not same as before\nCHECK AGAIN");
                return 0;
            }
            }
        }
         else{
            printf("INCORRECT PIN NO\nTRY AGAIN\n");
        }
    }
        
     }
     FILE *fp2;
   fp2=fopen("atm.txt","r");
   if(fp2==NULL)
   {
    printf("error");
    return 1;
   }
   else{
  char abc;
  while((abc=fgetc(fp2))!=EOF)
  {
    if(abc== '\n')
    {
        count2++;
    }
  }
   }
   fclose(fp2);
   fp2=fopen("atm.txt","w");
   if(fp2==NULL)
   {
    printf("error");
    return 1;
   }
   fprintf(fp,"%s %s %s %s\n","ACC_HOL_NAME","ACCOUNT_NO-----","PIN_NO----","CURRENT_BALANCE");
    for(r=0;r<(count2-1);r++)
{
   fprintf(fp,"%s %lld %lld %lld\n",group[r].acc_name,group[r].acc_no,group[r].pas,group[r].cur_bal);
} 
fprintf(fp,"%s %lld %lld %lld",group[r].acc_name,group[r].acc_no,group[r].pas,group[r].cur_bal);
fclose(fp2);   
return 0;
}
}
    

  
        
