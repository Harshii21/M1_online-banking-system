#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct user{
        char phone[50];
        char ac[50];
        char password[50];
        float balance;
};

int main(){
        struct user user,usr;
        char filename[50],phone[50],password[50],phone1[50];
        FILE *fp,*fptr;
        int opt,choice;
        int amount;
        char cont = 'z';
        printf("\nWhat do you choose?");
        printf("\na1.Register your account");
        printf("\na2.Login to your account");

        printf("\n\n enter your choice:\t");
        scanf("%d",&opt);
        if(opt == 1){
                system("clear");
                printf("\n\npleasse enter your account number:\t");
                scanf("%s",user.ac);
                printf("Enter your phone number:\t");
                scanf("%s",user.phone);
                printf("Enter your new password:\t");
                scanf("%s",user.password);
                user.balance=0;
                stpcpy(filename,user.phone);
                fp=fopen(strcat(filename,".dat"),"w");
                fwrite(&user,sizeof(user),1,fp);
                if(fwrite != 0){
                        printf("succesfully registered");
                }
        }
        else if(opt == 2){
                system("clear");
                printf("\nphone no.:\t");
                scanf("%s",phone);
                printf("password:\t");
                scanf("%s",password);
                fp = fopen(strcat(phone,".dat"),"r");
                if(fp == NULL) printf("Account number not registered");
                else {
                    fread(&user,sizeof(struct user),1,fp);
                    fclose(fp);
                    if(!strcmp(password,user.password)){
                        while(cont == 'z'){
                        system("clear");
                        printf("\n\twelcome %s",user.phone);
                        printf("\npress 1 for balance inquiry");
                        printf("\npress 2 for adding fund");
                        printf("\npress 3 for cash withdraw");
                        printf("\npress 4 for online transfer");
                        printf("\npress 5 for changing password\n\n");
                        scanf("%d",&choice);
                        switch(choice){
                            case 1:
                                printf("your current balance is Rs. %2f",user.balance);
                                break;

                            case 2:
                                system("clear");
                                printf("enter amount to be added:\t");
                                scanf("%d",&amount);
                                user.balance += amount;
                                fp = fopen(phone,"w");
                                fwrite(&user,sizeof(struct user),1,fp);
                                if(fwrite !=0) printf("\n\nyou have deposited Rs.%d",amount);
                                fclose(fp);
                                break;

                           case 3:
                               system("clear");
                               printf("enter withdrawl amount:\t");
                               scanf("%d",&amount);
                               if(amount % 500 != 0) printf("\nsorry amount should be multiple of 500");
                               else if(amount>user.balance) printf("\nsorry insufficient balance");
                               else {
                                  user.balance -= amount;
                               fp = fopen(phone,"w");
                               fwrite(&user,sizeof(struct user),1,fp);
                               if(fwrite !=0) printf("\n\nyou have withdrawn Rs.%d",amount);
                               fclose(fp);
                               }
                               break;

                           case 4:
                               printf("please enter the phone number to transfer balance:\t");
                               scanf("%s",phone);
                               printf("enter the amount to transfer:\t");
                               scanf("%d",&amount);
                               if(amount > user.balance) printf("\nsorry number is not registered");
                               else {
                                   fptr = fopen(strcat(phone,".dat"),"r");
                                   if(fptr==NULL) printf("sorry number is not registered");
                                   else {
                                        fread(&usr,sizeof(struct user),1,fptr);
                                        fclose(fptr);

                                        usr.balance += amount;

                                        fptr = fopen(phone,"w");
                                        fwrite(&usr,sizeof(struct user),1,fptr);
                                        if(fwrite != 0){
                                          
                                            printf("your transfer is completed. you have transfered Rs.%d to %s",amount,usr.phone);
                                            fclose(fptr);
                                            user.balance -= amount;
                                            strcpy(filename,user.phone);
                                            fp = fopen(strcat(filename,".dat"),"w");
                                            fwrite(&user,sizeof(struct user),1,fp);
                                            fclose(fp);
                                        }
                                   }
                               }
                               break;
                           case 5:
                               printf("\n\nplease enter your old password:\t");
                               scanf("%s",password);
                               if(!strcmp(password,user.password)){
                                   printf("\n\nplease enter your new password:\t");
                                   scanf("%s",password);
                                   strcpy(user.password,password);
                                   strcpy(filename,user.phone);
                                   fp = fopen(strcat(filename,".dat"),"w");
                                   fwrite(&user,sizeof(struct user),1,fp);
                                   fclose(fp);
                                   printf("\npassword succesfully changed");
                               }else printf("\nsorry your password is wrong");

                           default:
                           break;                    
                        }//switch ends here
                        printf("\n\nDo you want to continue?[y/n]:\t");
                        scanf("%s",&cont);
                        }
                    }
                    else {
                        printf("Invalid password");
                    }
                }
                printf("\n\n***thank you for banking with D.bank***\n\n");
        }

        return 0;
} 