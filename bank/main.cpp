#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main()
{
    fstream file;
    string bankfilename;
    char usercommand;
    float store, amount, balance[50], max;
    int flag = 0, count = 0, accountno, account[50], a = 1, b = 1, discard = 0, amountwrong =0;
    

    cout<<"** Welcome to UIC Bank v1.0 **"<<endl;
    
    cout<<"Enter bank filename>"<<endl;
    getline(cin, bankfilename);

    file.open(bankfilename + ".txt", ios::in);
    if(file.is_open()){
        
        cout<<"** Inputting account data..."<<endl;
        cout<<"** Outputting account data..."<<endl;
        
        while(file >> store){
            if(flag == 0){
                cout<<"Account "<<store<<": ";
                account[a] = store;
                a++;
                flag = 1;
            }
            else{
                cout<<"Balance $"<<fixed<<setprecision(2)<<store<<endl;
                balance[b] = store;
                b++;
                flag = 0;
            }
            count += 1;
        }
        
    }
    else{
        
        cout<<"FILE NOT FOUND check the file name "<<endl;
        discard = 1;
    }
    
    file.close();
    
    
    if(discard == 0){
        
        cout<<"** Processing user commands..."<<endl;
        
        do{
            
            cout<<"Enter command (+, -, ?, ^, *, x):"<<endl;
            cin>>usercommand;
            
            switch(usercommand){
                
                case '+':
                    
                    cout<<"Enter Account No: "<<endl;
                    cin>>accountno;
                    
                    for(a = 1; a <= count / 2; a++){
                        if(account[a] == accountno){
                            cout<<"Enter the amount to ADD: "<<endl;
                            cin>>amount;
                            balance[a] = balance[a] + amount;
                            cout<<"Account "<<account[a]<<": "<<"balance $"<<fixed<<balance[a]<<setprecision(2)<<endl;
                            amountwrong = 1;
                            break;
                        }
                    }
                    if(amountwrong == 0){
                        cout<<"** Invalid account, transaction ignored"<<endl;
                    }
                    break;
                
                case '-':
                    
                    cout<<"Enter Account No: "<<endl;
                    cin>>accountno;
                    
                    for(a = 1; a <= count / 2; a++){
                        if(account[a] == accountno){
                            cout<<"Enter the amount to SUB: "<<endl;
                            cin>>amount;
                            balance[a] = balance[a] - amount;
                            cout<<"Account "<<account[a]<<": "<<"balance $"<<fixed<<balance[a]<<setprecision(2)<<endl;
                            amountwrong = 1;
                            break;
                        }
                    }
                    if(amountwrong == 0){
                        cout<<"** Invalid account, transaction ignored"<<endl;
                    }
                    break;
                
                case '?':
                    
                    cout<<"Enter Account No: "<<endl;
                    cin>>accountno;
                    
                    for(a = 1; a <= count / 2; a++){
                        if(account[a] == accountno){
                            cout<<"Account "<<account[a]<<": "<<"balance $"<<fixed<<balance[a]<<setprecision(2)<<endl;
                            amountwrong = 1;
                            break;
                        }
                    }
                    if(amountwrong == 0){
                        cout<<"** Invalid account, transaction ignored"<<endl;
                    }
                    break;
                
                case '^':
                    
                    max = balance[a];
                    
                    for(a = 1; a <= count / 2; a++){
                        if(balance[a] > max){
                            max = balance[a];
                        }
                    }
                    
                    for(a = 1; a <= count / 2; a++){
                        if(balance[a] == max){
                            cout<<"Account "<<account[a]<<": "<<"balance $"<<fixed<<balance[a]<<setprecision(2)<<endl;
                            break;
                        }
                    }
                    
                    break;
                
                case '*':
                    
                    for(a = 1; a <= count / 2; a++){
                        cout<<"Account "<<account[a]<<": "<<"balance $"<<fixed<<balance[a]<<setprecision(2)<<endl;
                    }
                    break;
                
                case 'x':
                    break;
                    
                default:
                    
                    cout<<"** Invalid command, try again..."<<endl;
            }
        }while(usercommand != 'x');
        
        cout<<"** Saving account data..."<<endl;
        cout<<"** Done **"<<endl;
        
        
        file.open(bankfilename+".txt",ios::out);
        for(a=1;a<=count/2;a++){
            file<<account[a]<<" "<<balance[a]<<endl;
        }
        file.close();
        
    }
    
    return 0;
}