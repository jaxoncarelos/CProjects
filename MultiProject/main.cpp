#include <iostream>
#include <unistd.h>
#include <fstream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <sstream>

using namespace std;
void BankSystem();
void BusReservationSystem();
void RestrauntSystem();
int balance = 0;
ifstream fin;
ofstream fout;
using namespace std;

int main()
{
    int choice;
    cout << endl << endl << endl << endl <<"                           Welcome to the MultiProject!\n";
    cout << "                           What would you like to use?" << endl << "1. Access your bank." << endl << "2. Reserve a seat on the Bus." << endl << "3. Buy some food." << endl;
    cout << "                           Choice: ";
    cin >> choice;
    switch(choice){
    case 1:
        BankSystem();
    case 2:
        BusReservationSystem();
    case 3:
        RestrauntSystem();
    }
    return 0;
}

void BankSystem() {
    void WithdrawMoney();
    void DepositMoney();
    void CheckBalance();
    int choice;
    mainstart:
    cout << "\35Welcome to the bank. What would you like to do today?" << endl << "1. Withdraw Money" << endl << "2. Deposit Money" << endl << "3. Check Balance" << endl << "4. Exit." << endl << "Choice: ";
    cin >> choice;
    fin.open("bankInfo.txt");
    fin >> balance;
    if(choice > 4){
        cout << "Invalid choice, please retry." << endl;
        goto mainstart;
    }
    switch(choice){
    case 1:
        WithdrawMoney();
    case 2:
        DepositMoney();
    case 3:
        CheckBalance();
    case 4:
        main();
    }
    fin.close();
}
void WithdrawMoney(){
        fout.open("bankInfo.txt");
        int WithdrawAmount;
        start1:
        cout << "Enter the amount of money you want to withdraw: ";
        cin >> WithdrawAmount;
        if(WithdrawAmount <= 0 || WithdrawAmount > balance){
            cout << "Please enter a valid number to withdraw.\n";
            goto start1;


        }
        else
        {
            balance = balance - WithdrawAmount;
            fout << balance;
            fout.close();
        }
        cout << "New balance: " << balance << endl;
        sleep(1);
        BankSystem();
}
   void DepositMoney()
    {
        fout.open("bankInfo.txt");
        start2:
        int DepositAmount;
        cout << "Enter the amount of money you want to deposit: ";
        cin >> DepositAmount;
        if(DepositAmount <= 0){
            cout << endl << "Please enter a valid number to withdraw." << endl;
            goto start2;


        }
        else
        {
           balance = balance + DepositAmount;
           fout << balance;
           fout.close();
        }
        cout << "New balance: " << balance << endl;
        BankSystem();
    }
    void CheckBalance(){
        cout << "Your total balance is: " << balance << endl;
        BankSystem();
    }
void BusReservationSystem(){
    fout.open("busSeats.txt", std::ios_base::app);
    fin.open("busSeats.txt");
    int seatToTake;
    char seats[30];
        memset(seats, 'A', 20);
    start:
    while(fin >> seatToTake){
        seats[seatToTake] = 'T';

    }
    cout << "0  1       2  3\n";
    cout << seats[0] << "  " << seats[1] << "       " << seats[2] << "  " << seats[3] << endl;
    cout << seats[4] << "  " << seats[5] << "       " << seats[6] << "  " << seats[7] << endl;
    cout << seats[8] << "  " << seats[9] << "       " << seats[10] << "  " << seats[11] << endl;
    cout << seats[12] << "  " << seats[13] << "       " << seats[14] << "  " << seats[15] << endl;
    cout << seats[16] << "  " << seats[17] << "       " << seats[18] << "  " << seats[19] << endl;
    cout << "What seat would you like to reserve? (Put 99 to exit)" << endl << "Choice: ";
    cin >> seatToTake;
    if(seatToTake == 99){
        exit(0);


    }
    if(seats[seatToTake] != 'T'){

        seats[seatToTake] = 'T';
        cout << "Successfully reserved seat." << endl;
        fout << seatToTake << endl;
        goto start;
    }
    else
    {
        cout << "That seat is taken, please select another.";
        goto start;
    }
      fout.close();
}
void RestrauntSystem() {
        int choice;
    cout << "Welcome to the Restaurant." << endl;
    cout << "What would you like to eat?\n";
    cout << "1. Taco" << endl;
    cout << "2. Burrito" << endl;
    cout << "3. Coca-cola." << endl;
    cin >> choice;
    switch(choice){
    case 1:
        cout << "🌮, Here you go.";
    case 2:
        cout << "🌯, Here you go.";
    case 3:
        cout << "🥤, Here you go.";
    }
    main();


}

