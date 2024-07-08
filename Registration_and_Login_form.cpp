#include<iostream>
#include<fstream>
#include<windows.h>
#include<sstream>
using namespace std;

class Login{
    private:
    string LoginId, Password;
    public:
    Login():LoginId(""),Password(""){}

    void setID(string ID){
        LoginId = ID;
    }

    void setPW(string pw){
        Password = pw;
    }

    string getID(){
        return LoginId;
    }

    string getPW(){
        return Password;
    }
};

void login(Login Log){
    system("cls");
    string id,pw;

    cout<<"\t Enter Login ID: "<<endl;
    cin>>id;

    cout<<"\t Enter Password: "<<endl;
    cin>>pw;

    ifstream fin("Login Data.txt");
    if(!fin){
        cout<<"\tError: File Can't Open!"<<endl;
    }
    else{
        string line;
        bool found = false;
        while(getline(fin,line)){
            stringstream ss;
            ss<<line;
            string userId, userPW;
            char delimiter;
            ss>>userId>>delimiter>>userPW;

            if(id == userId && pw == userPW){
                found = true;
            }

            cout<<"\tPlease Wait";
            for(int i = 0 ; i < 3 ; i++ ){
                cout<<".";
                Sleep(800);
            }
            system("cls");
            cout<<"\tWelcome To This Page!"<<endl;
        }
    if(!found){
        cout<<"\tError: Incorrect login ID or Password!"<<endl;
    }
    }
    
    fin.close();
    Sleep(5000);
}

void registration(Login Log){
system("cls");
string id, pw;
cout<<"\tEnter Login ID: ";
cin>>id;
Log.setID(id);

start:
cout<<"\tEnter A Strong Password: ";
cin>>pw;
if(pw.length() >= 8){
Log.setPW(pw);
}
else{
    cout<<"\t Enter Minimum 8 Characters!"<<endl;
    goto start;
}


ofstream fout("Login Data.txt", ios::app);  //<---- iosw::app save all the information in the file , else one data is input others will be deleted
if(!fout){
    cout<<"\tError: Can't Open File!"<<endl;
}
else{
    fout<<"\t"<<Log.getID()<<" : "<<Log.getPW()<<endl<<endl;
    cout<<"\tUser Registered Successfuly!"<<endl;
}
fout.close();

Sleep(3000);
}



int main(){
    Login log;
    bool exit = false;
    while(!exit){
        system("cls");   // <----clear previous results
       int val;
       cout<<"\tWelcome To Registration and Login Form"<<endl;
        cout<<"\t*************************************"<<endl;   
        cout<<"\t1.Register"<<endl;   //<----\t use krne se ek tab ka space aata h
        cout<<"\t2.Login."<<endl;
        cout<<"\t3.Exit"<<endl;
        cout<<"\tEnter Choice: "<<endl;
        cin>>val;
        
        if(val == 1){
            registration(log);
        }
        else if(val == 2){
            login(log);
        }
        else if(val == 3){
            system("cls");
            exit = true;
            cout<<"\tGood Luck"<<endl;
            Sleep(3000);
        }
        
        Sleep(3000);    // <---3 sec ke liye output display hoga

    }
}