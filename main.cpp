#include<iostream>
#include<string>
using namespace std;


enum Vendingstate{
 SELECT, QUANTITY, CALCULATE, UPDATE
};
enum Brand{
 PEPSI=1,COKE=2,SEVENUP=3,MAZZA=4,THUMBSUP=5
};
struct student{
 string name;
 int points;
};
struct Soda{
 Brand brandName;
 int inventory;
 int price;
};

int main()
{
    Vendingstate curstate=SELECT;

    Soda vendingMachine[5];
    //Loading Pepsi
    vendingMachine[0].brandName=PEPSI;
    vendingMachine[0].inventory=10;
    vendingMachine[0].price=50;
    //Loading Coke
    vendingMachine[1].brandName=COKE;
    vendingMachine[1].inventory=10;
    vendingMachine[1].price=70;
    //Loading Seven up
    vendingMachine[2].brandName=SEVENUP;
    vendingMachine[2].inventory=10;
    vendingMachine[2].price=30;
    //Loading Mazza
    vendingMachine[3].brandName=MAZZA;
    vendingMachine[3].inventory=10;
    vendingMachine[3].price=90;
    //Loading Thumbs up
    vendingMachine[4].brandName=THUMBSUP;
    vendingMachine[4].inventory=10;
    vendingMachine[4].price=100;

    Soda SelectedSoda;

    student S;
    S.name="Sachin";
    S.points=1000;//1000 points in the wallet

    for(;;)
    {
        switch(curstate)
        {
        case SELECT:
            //1.Display the current status of vending machine
            cout<<"\t\t\t\t <--Current Status--> \t\t\t\t" <<endl;
            cout<<"[[[Vending Machine]]]" <<endl;
            for(int i=0;i<5;i++)
            {
                cout<<vendingMachine[i].brandName<<" has "<<vendingMachine[i].inventory<<" drinks, and each drink costs "<<vendingMachine[i].price<<endl;
            }
            cout<<"\[[[Student]]]"<<endl;
            cout<<S.name<<" has "<<S.points<<" points available in his wallet"<<endl;
            cout<<"\t\t\t\t <--End Status--> \t\t\t\t"<<endl;
            //2.Ask the user what they want
            cout<<"Enter the drink you want from the following available options"<<endl;
            //3.Display the available options
            cout<<"1.PEPSI\n2.COKE\n3.SEVENUP\n4.MAZZA\n5.ThUMBSUP\n"<<endl;
            //4.Take the user input
            int selectedDrink;
            cin>>selectedDrink;
            //5.If valid drink selected, move to QUANTITY state,else go back to SELECT state
            switch(selectedDrink)
            {
             case PEPSI:
                cout<<"You have selected PEPSI"<<endl;
                SelectedSoda.brandName=PEPSI;
                curstate=QUANTITY;
                break;
             case COKE:
                cout<<"You have selected COKE"<<endl;
                SelectedSoda.brandName=COKE;
                curstate=QUANTITY;
                break;
             case SEVENUP:
                cout<<"You have selected SEVENUP"<<endl;
                SelectedSoda.brandName=SEVENUP;
                curstate=QUANTITY;
                break;
             case MAZZA:
                cout<<"You have selected MAZZA"<<endl;
                SelectedSoda.brandName=MAZZA;
                curstate=QUANTITY;
                break;
             case THUMBSUP:
                cout<<"You have selected THUMBSUP"<<endl;
                SelectedSoda.brandName=THUMBSUP;
                curstate=QUANTITY;
                break;
             default:cout<<"Please select a valid choice"<<endl;
                   curstate=SELECT;
                   break;
            }
            break;
        case QUANTITY:
            cout<<"How many drinks you like"<<endl;
            int orderQuantity;
            cin>>orderQuantity;

            cout<<"Your order has been received.You placed an order for "<<orderQuantity<<" soda(s)"<<endl;
            switch(SelectedSoda.brandName)
            {
            case PEPSI:
                if(orderQuantity<0 || orderQuantity>vendingMachine[0].inventory)
                {
                    cout<<"Not enough "<<SelectedSoda.brandName<<" in stock"<<endl;
                    curstate=SELECT;
                    cout<<endl;
                }
                else{
                    curstate=CALCULATE;
                }
                break;
            case COKE:
               if(orderQuantity<0 || orderQuantity>vendingMachine[1].inventory)
                {
                    cout<<"Not enough "<<SelectedSoda.brandName<<" in stock"<<endl;
                    curstate=SELECT;
                    cout<<endl;
                }
                else{
                    curstate=CALCULATE;
                }
                break;
            case SEVENUP:
               if(orderQuantity<0 || orderQuantity>vendingMachine[2].inventory)
                {
                    cout<<"Not enough "<<SelectedSoda.brandName<<" in stock"<<endl;
                    curstate=SELECT;
                    cout<<endl;
                }
                else{
                    curstate=CALCULATE;
                }
                break;
            case MAZZA:
                if(orderQuantity<0 || orderQuantity>vendingMachine[3].inventory)
                {
                    cout<<"Not enough "<<SelectedSoda.brandName<<" in stock"<<endl;
                    curstate=SELECT;
                    cout<<endl;
                }
                else{
                    curstate=CALCULATE;
                }
                break;
            case THUMBSUP:
               if(orderQuantity<0 || orderQuantity>vendingMachine[4].inventory)
                {
                    cout<<"Not enough "<<SelectedSoda.brandName<<" in stock"<<endl;
                    curstate=SELECT;
                    cout<<endl;
                }
                else{
                    curstate=CALCULATE;
                }
                break;
           default:cout<<"Invalid amount received"<<endl;
                   break;
            }
            break;
        case CALCULATE:
            cout<<"The total cost of your soda is"<<endl;
            int cost;
            switch(SelectedSoda.brandName)
            {
            case PEPSI:
                cost=vendingMachine[0].price*orderQuantity;
                cout<<cost<<endl;
                break;
            case COKE:
                cost=vendingMachine[1].price*orderQuantity;
                cout<<cost<<endl;
                break;
            case SEVENUP:
                cost=vendingMachine[2].price*orderQuantity;
                cout<<cost<<endl;
                break;
            case MAZZA:
                cost=vendingMachine[3].price*orderQuantity;
                cout<<cost<<endl;
                break;
            case THUMBSUP:
                cost=vendingMachine[4].price*orderQuantity;
                cout<<cost<<endl;
                break;
            default:cout<<"Error!"<<endl;
                    break;
            }
            int payment;
            cout<<"Please type in payment"<<endl;
            cin>>payment;

            if(payment<cost || payment>S.points || payment<=0)
            {
                cout<<"You don't have enough money"<<endl;
                curstate=SELECT;
                cout<<endl;
            }
            else{
                S.points=S.points-payment;
                int change=payment-cost;
                cout<<"Thank You! Your change is "<<change<<" points"<<endl;
                S.points=S.points+change;
                curstate=UPDATE;
            }
            break;
        case UPDATE:
            switch(SelectedSoda.brandName)
            {
            case PEPSI:
                vendingMachine[0].inventory-=orderQuantity;
                curstate=SELECT;
                cout<<endl;
                break;
            case COKE:
                vendingMachine[1].inventory-=orderQuantity;
                curstate=SELECT;
                cout<<endl;
                break;
            case SEVENUP:
                vendingMachine[2].inventory-=orderQuantity;
                curstate=SELECT;
                cout<<endl;
                break;
            case MAZZA:
                vendingMachine[3].inventory-=orderQuantity;
                curstate=SELECT;
                cout<<endl;
                break;
            case THUMBSUP:
                vendingMachine[4].inventory-=orderQuantity;
                curstate=SELECT;
                cout<<endl;
                break;
            default:
                cout<<"Error!"<<endl;
                curstate=SELECT;
                cout<<endl;
                break;
            }
            cout<<"Inventory Updated"<<endl;
            curstate=SELECT;
            cout<<endl;
            break;
        default:cout<<"Invalid state detected"<<endl;
                break;
            }
        }
    return 0;
}



