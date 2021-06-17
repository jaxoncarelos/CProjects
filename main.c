#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <unistd.h>
int getBalance();
int balance;
int main()
{
    FILE *fptr;
    fptr = fopen("bankInfo.txt", "r");
    fscanf(fptr, "%d", &balance);
    int moneyToDeposit;
    int moneyInAccount;
    int moneyToWithdraw;
    int accountNum;
    int choice;
    system("COLOR 4");
    printf("What would you like to do?\n 1. Create Account.\n 2. Login to account.\n 3. Exit.\n");
    scanf("%d", &choice);
    switch(choice) {
    case 1:
        createAccount();
    case 2:
        login();
    case 3:
        exit(1);
    }

    return 0;
}
void createAccount(){
    system("cls");
    FILE *fptr;
    fptr = fopen("accountInfo.txt", "w");
    char username[30];
    char password[30];
    printf("Enter your username: ");
    scanf("%s", &username);
    printf("Enter your password: ");
    scanf("%s", password);
    printf("Account created successfully!\n");
    fprintf(fptr, "%s\n", username);
    fprintf(fptr, "%s", password);
    fclose(fptr);
    login();
}
void login() {
    FILE *fptr;
    char username[30];
    char password[30];
    char enteredUsername[30];
    char enteredPassword[30];
    fptr = fopen("accountInfo.txt", "r");
    fscanf(fptr, "%s\n", username);
    fscanf(fptr, "%s", password);
    printf("Enter your username: ");
    scanf("%s", enteredUsername);
    printf("Enter your password: ");
    scanf("%s", enteredPassword);
    if(strcmp(username, enteredUsername)== 0) {
        if(strcmp(password, enteredPassword)== 0) {
            mainmenu();

        }


    }else {
        printf("Invalid login!");
    }
}
void mainmenu() {
    system("cls");
    int choice;
    printf("1. Deposit money.\n2. Withdraw money.\n3. Check Balance.\n4. Exit.\n");
    scanf("%d", &choice);
    switch(choice){
        case 1:
            depositmoney();
        case 2:
            withdrawmoney();
        case 3:
            checkBalance();
        case 4:
            exit(1);
    }


}
void depositmoney() {
    FILE *fptr;
    int depositAmount;
    printf("How much would you like to deposit?: ");
    scanf("%d", &depositAmount);
    if(depositAmount <= 0){
        printf("You're exploiting faggot !xban");
        exit(1);
    }else{
        addBalance(depositAmount);
        printf("New balance is: %d", getBalance());
        getchar();
        fptr = fopen("bankInfo.txt", "w");
        fprintf(fptr, "%d", balance);
        fclose(fptr);
        mainmenu();
    }
}
void withdrawmoney() {
    system("COLOR 1");
    if (balance >= 10){
        FILE *fptr;
        int withdrawAmount;
        printf("How much would you like to withdraw: ");
        scanf("%d", &withdrawAmount);
        if(withdrawAmount <=0){
            printf("You exploiting cunt");
            sleep(1);
            mainmenu();
        }else {
            removeBalance(withdrawAmount);
            printf("New balance is: %d\n", balance);
            fptr = fopen("bankInfo.txt", "w");
            fprintf(fptr, "%d", balance);
            fclose(fptr);
            sleep(1);
            mainmenu();
        }
    }else{
        printf("You don't have any money to withdraw you idiot! You need atleast $10 to withdraw.\n");
    }
}
int getBalance() {
    int *globalBal = &balance;
    return balance;
}
void addBalance(int amount) {
    balance = (getBalance() + amount);

}
int checkBalance(){

    printf("$%d", getBalance());
    getchar();
    sleep(2);
    mainmenu();

}
int removeBalance(int amount ) {
    balance = (getBalance() - amount);

}
