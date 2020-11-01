#include<iostream>
#include<cmath>

using namespace std;

class bank{
    private:
    int Balance;
    int Roi;

    public:
        void OpenAccount()
    {
        cout << "Enter Balance : ";
        cin >> Balance;

        cout<<"Enter interest : ";
        cin>> Roi;
    }

    void Deposit()
    {
        int Amount;
        cout << "Enter Amount you want to deposit : ";
        cin >> Amount;
        Balance = Balance + Amount;
    }

    void Withdrawal()
    {
        int Amount;
        cout << "Enter Amount you want to withdraw : ";
        cin >> Amount;
        if (Amount <= Balance)
            Balance = Balance - Amount;
        else
            cout << "Balance Low " << endl;
    }
    
    void Compound(){
       int time;
       cout<<"Enter the time period : ";
       cin>>time;
       double CI =Balance*(pow((double)(1 + (double)Roi / 100), time)); 
       Balance = CI;
    }

    void getBalance()
    {
        cout << "Balance : " << Balance << endl;
    }

    ~bank(){

        cout<<"Thanks for visiting"<<endl;
        
    };

};

int main()
{
    bank C;

    int found = 0, a, ch=0;

    C.OpenAccount();
    
    while(ch!=5) {
       
        cout << "Please input your choice: "<<endl;
       
        cout << "1-Deposit"<<endl<<"2-Withdraw"<<endl<<"3-Compound"<<endl<<"4-getBalance"<<endl<<"5-Exit"<<endl;
        
        cin >> ch;

        switch (ch) {
        case 1:
            C.Deposit();
            break;
        
        case 2: 
            C.Withdrawal();
            break;
           
        case 3:
            C.Compound();
            break;
        case 4:
        C.getBalance();
        break;

        case 5: 
            break;
        default:
            cout << "Wrong Option" << endl;
        }
    }
    
    return 0;
}