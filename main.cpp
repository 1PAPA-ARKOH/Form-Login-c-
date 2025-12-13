#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

void login();
void registration();
void forgot();

int main()
{
    int c;
    cout<<"\t\t\t______________________________________________"<<endl;;
    cout<<"\t\t\t           Welcome to the Login Page          "<<endl;
    cout<<"\t\t\t_____________________MENU_____________________"<<endl;
    cout<<endl;
    cout<<"\t| Press 1 to LOGIN"<<endl;
    cout<<"\t| Press 2 to REGISTER "<<endl;
    cout<<"\t| Press 3 if FORGOT PASSWORD "<<endl;
    cout<<"\t| Press 4 to EXIT "<<endl;
    cout<<"Please choose from the options : ";
    cin>>c;
    cout<<endl;
    cin.clear();
    fflush(stdin);

    switch(c){
    case 1 :
        login();
        break;
    case 2:
        registration();
        break;
    case 3:
        forgot();
        break;
    case 4:
        cout<<"\t\t\t Thank you for using our service "<<endl;
    default:
        system("cls");
        cout<<"Choose from the options given above "<<endl;
        main();
    }
    return 0;
}
void login(){
    int count1;
    string userId, password, Id, pass;
    system("cls");
    cout<<"\t\t\tPlease login with username and password"<<endl;
    cout<<"\t\t\tUSERNAME : ";
    cin>>userId;
    cout<<"\t\t\tPASSWORD : ";
    cin>>password;

    fstream input("records.txt");
    while(input>>Id>>pass)
    if(userId==Id && password==pass){
        count1=1;
        system("cls");
        break;
    }

    input.close();
    if(count1=1){
        cout<<userId<<" Your login is successful "<<endl;
    }else {
        cout<<"LOGIN ERROR ! Please check your username and password "<<endl;
        main();
    }
}
void registration(){
    string ruserId, rpassword, rId, rpass;
    system("cls");
    cout<<"\t\t\t Please register with your username and password "<<endl;
    cout<<"\t\t\t USERNAME : ";
    cin>>ruserId;
    cout<<"\t\t\t PASSWORD : ";
    cin>>rId;

     ofstream bills("records.txt ", ios::app);
     bills<<rId<<" "<<rpass;
     system("cls");
     cout<<"Registration successful !"<<endl;
     main();
}
void forgot(){
    int choice;
    system("cls");
    cout<<"\t\t\t Forgot password? No worries "<<endl;
    cout<<"\t| Press 1 to search by username "<<endl;;
    cout<<"\t| Press 2 to return to main menu "<<endl;;
    cout<<"\t\t\tEnter your choice : ";
    cin>>choice;
    cin.clear();
    fflush(stdin);

    switch(choice){
    case 1:
    {
    string suserId, spassword, sId, spass;
    int count1=0;
    cout<<"\t\t Enter the username you remember : ";
    cin>>suserId;
    fstream f2("record.txt");
    while(f2>>sId>>spass){
        if(suserId==sId){
            count1=1;
        }
    }
    f2.close();
    if(count1=1){
        cout<<" Your account is found !"<<endl;
        cout<<"Your password is :"<<spass;
        cout<<endl;
        main();
    }else {
        cout<<"\n\t Sorry, your account is not found !"<<endl;
        main();
    }
    break;
    }
    case 2:
        {
            main();
        }
    default:
        cout<<"Wrong choice! Please try again"<<endl;
        main();
   }
}

