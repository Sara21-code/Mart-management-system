#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include<ctime>
#include<windows.h>
using namespace std;

void adminMenu(int ids[], string names[], double prices[], int prodCount[], int &count);
void cashierMenu(int ids[], string names[], double prices[], int prodCount[], int &count);
void readData(int ids[], string names[], double prices[], int prodCount[], int &count);
int main ()
{
    
    const int SIZE=100;
    int productId[SIZE]={0};
    double productPrice[SIZE]={0.0};
    string productName[SIZE]={""};
    int productCount[SIZE]={0};

    int itemCount=0;
    int choice=0;
    readData( productId, productName, productPrice, productCount, itemCount);

    do
    {
          
        
        cout << "  _________________________" << endl;
        cout << " |                         |" << endl;
        cout << " |   \033[95mMYSTIC MART & CO.\033[0m     |" << endl;
        cout << " |_________________________|" << endl;
        cout << "    ||                 ||" << endl<<endl;
        cout<<"================================"<<endl;
        cout<<"     MART MANAGMENT SYSTEM      "<<endl;
        cout<<"================================"<<endl;
        cout<<"1. Admin Menu"<<endl<<"2. Cashier Menu"<<endl<<"3. Help/ About"<<endl<< "4. Credits"<<endl<< "5. Exit System"<<endl;
        cout<< "Please enter your choice (1-5): ";
        cin>> choice;
        while(choice<1 || choice>5)
        {
            cout<<"Invalid choice !!"<<endl;
            cout<< "Please enter your choice again (1-5): ";
            cin>> choice;
        }
        if (choice==1)
        {
            cout<< "----------Entering admin menu----------"<<endl;
            adminMenu( productId, productName, productPrice, productCount, itemCount);
            
        }
        else if(choice==2)
        {
             cout<< "----------Entering cashier menu----------"<<endl;
            cashierMenu( productId, productName, productPrice, productCount, itemCount);
            
        }
        else if(choice==3)
        {
            cout << "================================" << endl;
            cout << "     MART MANAGEMENT SYSTEM     " << endl;
            cout << "================================" << endl;
            cout<<"This is a program creted to manage the products in the store,"<<endl;
            cout << "* Use Admin Mode to add or update items." << endl;
            cout << "* Use Cashier Mode to process customer sales." << endl;
            cout << "* all the data is stored in stock.txt ." << endl;
            
        }

    else if(choice == 4) 
{
    system("cls");
    cout << "==================================================" << endl;
    cout << "             PROJECT DEVELOPER TEAM               " << endl;
    cout << "==================================================" << endl << endl;
    cout << "\033[96mNARMEEN FATIMA   - Lead Architect & Base Builder" << endl;
    cout << "                     (Roll No: BAIF25M040) \033[0m" << endl << endl;
    cout << "\033[95mZUKHRUF RASHID   - Admin Logic Specialist" << endl;
    cout << "                     (Roll No: BAIF25M051) \033[0m" << endl << endl;
    cout << "\033[93mSARA AKRAM       - Sales & Checkout Engineer" << endl;
    cout << "                     (Roll No: BAIF25M054) \033[0m" << endl << endl;

    cout << "==================================================" << endl;
    system("pause"); 
}
    
       
        else if(choice==5)
        {
            cout<<"---------Exiting program----------"<<endl;
            Beep(700,200);
            Beep(500,200);
            Beep(300,300);
            return 0;
        }

    } while (choice!=5);
    
    return 0;
}
void readData(int ids[], string names[], double prices[], int prodCount[], int &count)
{
    ifstream fin;
    fin.open ("stock.txt");
    if(!fin.fail())
    {
        cout<<"========================="<<endl;
        cout<<"    Opening Inventory    "<<endl;
        cout<<"========================="<<endl;
        for(int i=1; i<=4; i++)
        {
            for(int j=0; j<i; j++)
            {
                cout<<" . ";
            }
            cout<<endl;
        }
        while(fin>>ids[count]>>names[count]>>prices[count]>>prodCount[count])
        {
            count++;
        }
        fin.close();
        cout<<"File read successfully..."<<endl<<endl;
    }
    else{
        cout<<"Error!!"<<endl<<"File not found."<<endl;
    }
    
}
void adminMenu(int ids[], string names[], double prices[], int prodCount[], int &count)
{
    string password;
    cout<<"Enter Admin Password: ";
    cin>>password;
    if(password != "Admin_123")
    {
    Beep(300,500);
    cout<<"Wrong password. Access Denied!"<<endl;
    return;
    }
    int adminChoice;
    do
    {
        cout<<"\n==============================="<<endl;
        cout<<"          ADMIN MENU           "<<endl;
        cout<<"==============================="<<endl;
        cout<<"1. View Stock"<<endl;
        cout<<"2. Add New Product"<<endl;
        cout<<"3. Restock Existing Product"<<endl;
        cout<<"4. Back to Main Menu"<<endl;
        cout<<"Enter your choice (1-4): ";
        cin>>adminChoice;
        while (adminChoice < 1 || adminChoice > 4) 
        {
            cout<<"Invalid choice. Please enter a valid option (1, 2, 3 or 4): ";
            cin>>adminChoice;
        }
        if (adminChoice == 1)
        {
            cout<<"\n-------------------------------------------------------------"<<endl;
            cout<<left<<setw(10)<<"ID"<<setw(20)<<"Name"<<setw(10)<<"Price"<<setw(10)<<"Quantity"<<setw(10)<<"Status"<<endl;
            cout<<"-------------------------------------------------------------"<<endl;
            for (int i = 0; i < count; i++)
            {
                cout<<left<<setw(10)<<ids[i]<<setw(20)<<names[i]<<"$"<<left<<setw(9)<<fixed<<setprecision(2)<<prices[i]<<setw(10)<<prodCount[i];
                if (prodCount[i] < 10)
                {
                    cout<<"[LOW STOCK]";
                }
                else 
                {
                    cout<<"[NORMAL STOCK]";
                }
                cout<<endl;
            }
            cout<<"-------------------------------------------------------------"<<endl;
        }
        else if (adminChoice == 2)
        {
            if (count >= 100)
            {
                cout<<"Error: Inventory is full. More products cannot be added."<<endl;
            }
            else
            {
                cout<<"\n--- Adding New Product ---"<<endl;
                cout<<"Enter Product ID: ";
                cin>>ids[count];
                cout<<"Enter Product Name (No spaces): ";
                cin>>names[count];
                cout<<"Enter Product Price: ";
                cin>>prices[count];
                cout<<"Enter Product Quantity: ";
                cin>>prodCount[count];
                count++;
                cout<<"Product added successfully to system memory."<<endl;
                ofstream fout;
                fout.open("stock.txt");
                if (!fout.fail())
                {
                    for (int i = 0; i < count; i++)
                    {
                        fout<<ids[i]<<" "<<names[i]<<" "<<prices[i]<<" "<<prodCount[i]<<endl;
                    }
                    fout.close();
                    cout<<"stock.txt updated successfully!"<<endl;
                }
                else
                {
                    cout<<"Error: Could not save changes to stock.txt."<<endl;
                }
            }
        }
        else if (adminChoice == 3)
        {
            cout<<"\n--- Update Existing Product Stock ---"<<endl;
            int matchId;
            cout<<"Enter the Product ID you want to restock: ";
            cin>>matchId;
            bool found;
            for (int i = 0; i < count; i++)
            {
                if (ids[i] == matchId) 
                {
                    found = true;
                    int newStock;
                    cout<<"Current stock for "<<names[i]<<" is: "<<prodCount[i]<<endl;
                    cout<<"Enter additional quantity to add: ";
                    cin>>newStock;
                    prodCount[i] += newStock;
                    cout<<"Stock updated successfully!"<<endl;
                    break; 
                }
            }
            if (!found) 
            {
                cout << "Product ID not found in system." << endl;
            }
        }
        else if (adminChoice != 4)
        {
            cout<<"Invalid choice. Please enter 1, 2, or 3."<<endl;
        }
    } while (adminChoice != 4);
}
void cashierMenu(int ids[], string names[], double prices[], int prodCount[], int &count)
{
 ofstream fout;
    fout.open ("stock.txt");
    if(!fout.fail())
    {

int id=0, k=0  , Count =0,  no_of_products=0 , qty =0  ; 
    int   bought_qty;
    double price , taxinc , GrandTotal , subtotal=0;
   
 names[30];
 prodCount[30];
 prices[30];
  int cartedcount[30];
  int currentqty[30];
Count=0;
do{
cout<<"enter the product ID to buy(0 to finish) : ";
cin>>id;

if(id==0)
{
    break;
}
 int qtymatch=0;
int found=0;

     for(int i=0 ; i<count ; i++)
     {
      
        if(id==ids[i])
        {
          cout<<"enter the quantity of product you want : ";
          cin>> qty;
          found=1;
          
         if(qty<=prodCount[i])
        {
        
        cout<<" added to cart "<<endl;
       names[Count]=names[i];
        cartedcount[Count]=qty;
       currentqty[i] = prodCount[i] - qty;
      prodCount[i] = currentqty[i];
       prices[Count]=prices[i];
        Count=Count+1;
        }
       else if(qty>prodCount[i])
       {
          qtymatch=1;
       }
     }
        
    
    }

        if(found==0)
        {
            cout<<"product not available "<<endl;
        }
     if( qtymatch==1)  
{
     cout<<"we have a limited quantity "<<endl;
}

     no_of_products++;
     
 
    
    
}while(id!=0);
for(int i=0 ; i<count ; i++)
{
    fout<<ids[i]<<" "
    <<names[i]<<" "
    <<prices[i]<<" "
    <<prodCount[i]<<endl;


}
cout<<endl;
      cout<<"\033[32m-------WELCOME TO HOME MART-------\033[0m"<<endl;
      cout<<endl; 
 cout<<endl;
 cout<<"==================================";
  cout<<endl; 
   cout<<endl;

  cout<<"-------------RECEIPT-------------";
        cout<<endl;

time_t now = time(0);
char* dt = ctime(&now);

cout<<"Date & Time: "<<dt<<endl;
cout<<"---------------------------------"<<endl;
cout << "Item\t\tPrice\tQty\tTotal" << endl;
cout<<"---------------------------------"<<endl;       
subtotal = 0;

for(int i = 0; i < Count; i++)
{
    double itemTotal = prices[i] * cartedcount[i];
    cout << names[i] << "\t\t$" << prices[i] << "\tx" << cartedcount[i] << "\t$" << itemTotal << endl;
    subtotal += itemTotal;
}
taxinc = subtotal * 0.05;
GrandTotal = subtotal + taxinc;
cout<<"---------------------------------";
 cout<<endl;
cout<<"subtotal:    $"<<subtotal<<endl;
cout<<"tax 5%:     "<<taxinc;
 cout<<endl;
cout<<"GrandTotal:   $"<<GrandTotal;
 cout<<endl;
cout<<"----------------------------------";
 cout<<endl;
 cout<<endl;
 cout<<"\033[32mSALE SUCCESSFUL! THANKS FOR SHOPPING\033[0m"<<endl;
cout<<endl; 
 cout<<endl;
 cout<<"==================================";
  cout<<endl; 
   cout<<endl;

}

}