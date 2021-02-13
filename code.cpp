/*********************************
Title      : rental sys
Authors    : 1.Praveen Naik
             2.Prasad Patil
             3.Prajwal Gouli
Start Date : 02 / 05 / 2020
End Date   : 14 / 05 / 2020

University : KLE Technological University , Hubli
Guidance   : NOONE

Purpose    : To simulate system for renting cars and bikes
*************************************/
#include <bits/stdc++.h>

using namespace std;

#define SUCCESS 1
#define FAILURE -1
#define OUT_OF_INDEX -20
#define FILE_EMPTY_ERROR -30
#define NOTFOUND 404

int ORDER_IDX = 1001; // Initial orderID
void lines()
{
    cout<<"\n-----------------------------------------------------------------\n";
}
void stars()
{
    cout<<"\n*****************************************************************\n";
}

void clrscreen()
{
    cin.ignore();
    cout<<"\n\nPress Enter to continue !!!!\n\n";
    getchar();
    system("cls");
}
int getint()
{
    int num;
    cin>>num;
     while (cin.fail())
    {
        cin.clear(); // clear input buffer to restore cin to a usable state
        cin.ignore(INT_MAX, '\n'); // ignore last input
        cout << "You can only enter numbers\n";
        cout << "Enter a number \n";
        cin >> num;
    }
    return num;
}
long long int getlli()
{
    long long int num;
    cin>>num;
     while (cin.fail())
    {
        cin.clear(); // clear input buffer to restore cin to a usable state
        cin.ignore(INT_MAX, '\n'); // ignore last input
        cout << "You can only enter numbers\n";
        cout << "Enter a number \n";
        cin >> num;
    }
    return num;
}
double getdouble()
{
    double x;
    cin>>x;
    while (cin.fail())
    {
        cin.clear(); // clear input buffer to restore cin to a usable state
        cin.ignore(INT_MAX, '\n'); // ignore last input
        cout << "You can only enter numbers\n";
        cout << "Enter a number \n";
        cin >> x;
    }
    return x;
}

int file_empty_check(const char *filename)
{
    // Declaring "stat" a system call to know about content of file.
    FILE* fp = fopen(filename, "r");

    // checking if the file exist or not
    if (fp == NULL) {
        cout<<"File Not Found!\n";
        return -1;
    }

    fseek(fp, 0L, SEEK_END);

    // calculating the size of the file
    long int res = ftell(fp);

    // closing the file
    fclose(fp);

    //check size of file and return appropriate status.
    if( res == 0 )
    {
        return FILE_EMPTY_ERROR;
    }
    else
    {
        return SUCCESS;
    }
}


class vehicle;

class insuranceCompany
{
public:
    string name;
    string loc;
    long long int ID;

    insuranceCompany()
    {
        name = "";
        loc = "";
        ID = 0;
    }
    insuranceCompany(string name,string loc,long long int ID)
    {
        this->name = name;
        this->loc = loc;
        this->ID = ID;
    }
    void read()
    {
        cout<<"\ncompany name : ";
        cin>>name;
        cout<<"\ncompany loc : ";
        cin>>loc;
        cout<<"\ncompany ID : ";
        ID=getlli();
    }
    void display()
    {
        cout<<"\ncompany name : ";
        cout<<name;
        cout<<"\ncompany loc : ";
        cout<<loc;
        cout<<"\ncompany ID : ";
        cout<<ID;
    }
};

class vehicle
{
   protected :
       string veh_name;
       int modelNo;
       string regNo;
       bool status;
       string damage;
       insuranceCompany ins_comp;
       int ins_peroid;
       double rate;
       insuranceCompany *comp;
   public:
    vehicle()
    {
       veh_name = "";
       modelNo = 0;
       regNo = "";
       status = false;
       damage = "";
       ins_peroid = 0;
       rate = 0.0;
       comp = NULL;
    }
    vehicle(string name,int no,string reg,bool stat,string damg,insuranceCompany ins,int p)
    {
       veh_name = name;
       modelNo = no;
       regNo = reg;
       status = stat;
       damage = damg;
       ins_comp = ins;
       ins_peroid = p;
    }
    void read_v()
    {
        cout<<"\nveh_name : ";
        cin>>veh_name;
        cout<<"\nmodelNo : ";
        modelNo = getint();
        cout<<"\nregNo : ";
        cin>>regNo;
        cout<<"\ndamage : ";
        cin>>damage;
        cout<<"\nins_peroid : ";
        ins_peroid = getint();
        cout<<"\nrate:";
        rate = getdouble();
        //ins_comp.read();
    }
    void display_v()
    {
        cout<<"\nveh_name : ";
        cout<<veh_name;
        cout<<"\nmodelNo : ";
        cout<<modelNo;
        cout<<"\nregNo : ";
        cout<<regNo;
        cout<<"\nstatus : ";
        status?cout<<"Rented":cout<<"Available";
        cout<<"\ndamage : ";
        cout<<damage;
        cout<<"\nins_peroid : ";
        cout<<ins_peroid;
        cout<<"\nrate:";
        cout<<rate;
       // ins_comp.display();
    }
    string getreg()
    {
        return regNo;
    }
    friend class order;
};

class car : public vehicle
{
    int no_of_seats;
    double mileage;
    string fuel;
    double tank_capacity;

public:
    car()
    {
        no_of_seats = 4;
        mileage = 0;
        fuel = "petrol";
        tank_capacity = 0;
    }
    car(int no,double m,string f,double r,double tc)
    {
        no_of_seats = no;
        mileage = m;
        fuel = f;
        rate = r;
        tank_capacity = tc;
    }
    void read_c()
    {
        read_v();
        cout<<"\nNo. of seats :";
        no_of_seats = getint();
        cout<<"\nmileage km/h:";
        mileage = getdouble();
        cout<<"\nfuel : ";
        cin>>fuel;
        cout<<"\ntank_capacity :";
        tank_capacity = getdouble();

    }
    void display_c()
    {
        display_v();
        cout<<"\nNo. of seats :";
        cout<<no_of_seats;
        cout<<"\nmileage km/l:";
        cout<<mileage;
        cout<<"\nfuel :";
        cout<<fuel;
        cout<<"\ntank_capacity :";
        cout<<tank_capacity;


    }
    friend class company;

};

class bike : public vehicle
{
    string type;
    float power;

public:
    bike()
    {
        type = "";
        power = 0.0;
    }
    bike(string t,float p)
    {
        type = t;
        power = p;
    }
    void read_b()
    {
        read_v();
        cout<<"\nType : ";
        cin>>type;
        cout<<"\nPower in HP: ";
        power=getdouble();

    }
    void display_b()
    {
        display_v();
        cout<<"\nType : ";
        cout<<type;
        cout<<"\nPower in HP: ";
        cout<<power;

    }
    friend class company;

};
class person
{
protected:
    string name;
    int age;
    long long int phoneno;
    string address;
    string sex;
public:
    person()
    {
        name = "";
        age = 0;
        phoneno = 0;
        address = "";
        sex = "";
    }
    person(string name,int age,string s,string loc,long long int p)
    {
        this->name = name;
        this->age = age;
        phoneno = p;
        address = loc;
        sex = s;
    }
    void read()
    {
        cout<<"\nName :  ";
        cin>>name;
        cout<<"\nage :  ";
        age=getint();
        cout<<"\nphoneno :  ";
        phoneno=getlli();
        cout<<"\nsex :  ";
        cin>>sex;
        cout<<"\naddress :  ";
        cin>>address;
    }
    void display()
    {
        cout<<"\nName :  ";
        cout<<name;
        cout<<"\nage :  ";
        cout<<age;
        cout<<"\nphoneno :  ";
        cout<<phoneno;
        cout<<"\nsex :  ";
        cout<<sex;
        cout<<"\naddress :  ";
        cout<<address;
    }

};
class employee: public person
{
private:
    double salary;
    int term;
    string description;
    string ID;

public:
    int ord_count;
    employee()
    {
        salary = 0.0;
        term = 0;
        description = "";
        ord_count = 0;
    }
    employee(double s,int t,string desc)
    {
        salary = s;
        term = t;
        description = desc;
        ord_count = 0;
    }
    void read()
    {
        cout<<"\nID : ";
        cin>>ID;
        person::read();
        cout<<"\nsalary :  ";
        salary=getdouble();
        cout<<"\nterm :  ";
        term=getint();
        cout<<"\ndescription :  ";
        getline(cin,description);
    }
    void display()
    {
        cout<<"\nID :  ";
        cout<<ID;
        person::display();
        cout<<"\nsalary :  ";
        cout<<salary;
        cout<<"\nterm :  ";
        cout<<term;
        cout<<"\ndescription :  ";
        cout<<description;
        cout<<"\nOrder count:  ";
        cout<<ord_count;

    }
    string getID()
    {
        return ID;
    }
    friend class company;
    friend class order;
};

class order;

class paymentInfo
{
private:
    string cardname;
    long long int cardno;
    double amount;
    string type;
public:
    paymentInfo()
    {
        cardname = "";
        cardno = 0;
        amount = 0.0;
        type = "";
    }
    paymentInfo(string cname, string ctyp,long long int no, double amt )
    {
        cardname = cname;
        cardno = no;
        amount = amt;
        type = ctyp;
    }
    void read(double amt)
    {
        cout<<"\ncardname :  ";
        cin>>cardname;
        cout<<"\ncardno :  ";
        cardno=getlli();
        cout<<"\ncardtype :  ";
        cin>>type;
        cout<<"\namount :  ";
        amount = amt;
        cout<<amount;
    }
    void display()
    {
        cout<<"\ncardname :  ";
        cout<<cardname;
        cout<<"\ncardno :  ";
        cout<<cardno;
        cout<<"\ncardtype :  ";
        cout<<type;
        cout<<"\namount :  ";
        cout<<amount<<endl;

    }
    friend class order;

};


class customer : public person
{
private:
    string username;
    string password;

public:
    int orderCount;
    customer()
    {
        person();
        orderCount = 0;
        username = "";
        password = "";
    }
    customer(int cnt,string pass,string uN)
    {
        person();
        orderCount = cnt;
        username = uN;
        password = pass;
    }
    int login(vector<customer> cust,string un,string pass)
    {
        int size_v = cust.end() - cust.begin();
        for(int i = 0;i<size_v;i++)
        {
            if(cust[i].username == un)
            {
                if(pass == cust[i].password)
                    return i;
            }
        }
        return FAILURE;
    }
    int create_account(vector<customer>cust)
    {
        person::read();
        cout<<"\nusername : ";
        while(1)
        {
            cin>>username;
           if(checkUN(cust,username))
            break;
        }
        cout<<"\npassword : ";
        while(1)
        {
            cin>>password;
           if(checkPass(password))
            break;
        }
        return SUCCESS;
    }
    bool checkUN(vector<customer>cust,string UN)
    {
        vector<customer>::iterator it;
        for(it = cust.begin();it != cust.end();it++)
        {
            if(it->username == UN)
            {
                return false;
            }
        }
        return true;
    }
    bool checkPass(string pass)
    {
        if(pass.size()<8)
        {
           cout<<"\nPassword length must be >7\n";
           return false;
        }

        int alpha = 0,num = 0,spl_char = 0;
        for(unsigned int i = 0;i<pass.size();i++)
        {
            if(pass[i]<58&&pass[i]>47)
                num++;
            else if((pass[i]<91&&pass[i]>64)||(pass[i]>96&&pass[i]<123))
                alpha++;
            else
                spl_char++;
        }
        if(!num)
        {
           cout<<"\nPassword must contain a number\n";
           return false;
        }
        if(!alpha)
        {
           cout<<"\nPassword must contain a alphabet\n";
           return false;
        }
        if(!spl_char)
        {
           cout<<"\nPassword must contain a special character\n";
           return false;
        }
        return true;
    }

    void display()
    {
    cout<<"\nUser name : ";
    cout<<username;
    cout<<"\n NO. of orders : ";
    cout<<orderCount;
    person::display();
    }
    void displayall(vector<customer> cust)
    {
        vector<customer>::iterator it;
        bool flag = false;
        for( it = cust.begin();it != cust.end();it++)
        {
            lines();
            it->display();
            flag = true;
        }
        if(!flag)
        cout<<"\nNo records found \n";
    }
    friend  class order;
    int loadCust();
    int updateDatabase_Cust();
};

class company
{
private:
    static company *instance;
    string comp_name;
    string comp_ID;
    string comp_loc;
    string CEO;
    vector<car *>carlist;
    vector<bike *> bikelist;
    vector<employee *>emplist;
    string PASSWORD;
    company()
    {
        comp_name = "RENT--IT";
        comp_ID = "Rent2000";
        comp_loc = "HUBLI";
        CEO = "prk";
        PASSWORD = "12345678";
    }
public:
    static company *getinstance()
    {
        if(!instance)
           instance = new company;
        return instance;
    }
    company(string name,string ceo,string id,string loc,vector<car *>c,vector<bike *>b,vector<employee *>emp)
    {
        comp_name = name ;
        comp_ID = id;
        comp_loc = loc;
        carlist = c;
        bikelist = b;
        CEO = ceo;
        emplist = emp;
    }
    bool login(string pass)
    {
        if(pass == PASSWORD)
            return true;
        return false;
    }
    void read()
    {
        cout<<"\ncomp_name: ";
        cin>>comp_name;
        cout<<"\ncomp_ID: ";
        cin>>comp_ID;
        cout<<"\ncomp_loc: ";
        cin>>comp_loc;
        cout<<"\ncomp_CEO: ";
        cin>>CEO;
    }
    int add_vehicle(int x)
    {
        carlist.push_back(new car);
        carlist.back()->read_c();
        return SUCCESS;
    }
    int add_vehicle(char x)
    {
        bikelist.push_back(new bike);
        bikelist.back()->read_b();
        return SUCCESS;
    }
    int add_employee()
    {
        emplist.push_back(new employee);
        emplist.back()->read();
        return SUCCESS;
    }
    int remove_bike(string regno)
    {
        vector<bike *>::iterator it;
        for(it= bikelist.begin();it!=bikelist.end();it++)
        {
            if((*it)->getreg() == regno)
                break;
        }
        if(it == bikelist.end())
            return NOTFOUND;
        bikelist.erase(it);
        delete (*it);
        return SUCCESS;
    }
    int remove_car(string regno)
    {
        vector<car *>::iterator it;
        for(it= carlist.begin();it!=carlist.end();it++)
        {
            if((*it)->getreg() == regno)
                break;
        }
        if(it == carlist.end())
            return NOTFOUND;
        carlist.erase(it);
        delete (*it);
        return SUCCESS;
    }
    int remove_emp(string ID)
    {
        vector<employee *>::iterator it;
        for(it= emplist.begin();it!=emplist.end();it++)
        {
            if((*it)->getID() == ID)
                break;
        }
        if(it == emplist.end())
            return NOTFOUND;
        emplist.erase(it);
        delete (*it);
        return SUCCESS;
    }
    int load_bikedatabase()
    {
        int num_of_bike;
        int i = 0;
        //check whether numofcity.txt file is empty or not.
        int file_status = file_empty_check("numofbike.txt");
        if (file_status == -30)
        {
            cout<<"\nnumofbike file has no content\n";
            return FAILURE;
        }
        // Creation of ifstream class object to read the file
        ifstream fd;

        // by default open mode = ios::in mode
        fd.open("numofbike.txt");
        fd>>num_of_bike;

        if(num_of_bike <= 0 )
        {
            cout<<"\nNo. of bikes can't be less than 1\n";
            return FAILURE;
        }
        fd.close();

        file_status = file_empty_check("bikedetails.txt");
        if (file_status == -30)
        {
            cout<<"\nbikedetails file has no content\n";
            return FAILURE;
        }
        ifstream fb;
        fb.open("bikedetails.txt");
        while(fb&& i < num_of_bike)
        {
            bikelist.push_back(new bike);
            fb>>bikelist.back()->veh_name;
            fb>>bikelist.back()->modelNo;
            fb>>bikelist.back()->regNo;
            fb>>bikelist.back()->rate;
            fb>>bikelist.back()->damage;
            fb>>bikelist.back()->type;
            fb>>bikelist.back()->power;
            i++;
        }
        fb.close();

        return SUCCESS;
    }
    int load_cardatabase()
    {
        int num_of_car;
        int i = 0;
        //check whether numofcity.txt file is empty or not.
        int file_status = file_empty_check("numofcar.txt");
        if (file_status == -30)
        {
            cout<<"\nnumofcar file has no content\n";
            return FAILURE;
        }
        // Creation of ifstream class object to read the file
        ifstream fd;

        // by default open mode = ios::in mode
        fd.open("numofcar.txt");
        fd>>num_of_car;

        if(num_of_car <= 0 )
        {
            cout<<"\nNo. of cars can't be less than 1\n";
            return FAILURE;
        }
        fd.close();

        file_status = file_empty_check("cardetails.txt");
        if (file_status == -30)
        {
            cout<<"\ncardetails file has no content\n";
            return FAILURE;
        }
        ifstream fb;
        fb.open("cardetails.txt");

        while(fb&& i < num_of_car)
        {
            carlist.push_back(new car);
            fb>>carlist.back()->veh_name;
            fb>>carlist.back()->modelNo;
            fb>>carlist.back()->regNo;
            fb>>carlist.back()->rate;
            fb>>carlist.back()->damage;
            fb>>carlist.back()->no_of_seats;
            fb>>carlist.back()->mileage;
            fb>>carlist.back()->fuel;
            fb>>carlist.back()->tank_capacity;
            i++;
        }
        fb.close();
        return SUCCESS;
     }
     int load_empdatabase()
    {
        int num_of_emp;
        int i = 0;
        //check whether numofcity.txt file is empty or not.
        int file_status = file_empty_check("numofemp.txt");
        if (file_status == -30)
        {
            cout<<"\nnumofemp file has no content\n";
            return FAILURE;
        }
        // Creation of ifstream class object to read the file
        ifstream fd;

        // by default open mode = ios::in mode
        fd.open("numofemp.txt");
        fd>>num_of_emp;

        if(num_of_emp <= 0 )
        {
            cout<<"\nNo. of emps can't be less than 1\n";
            return FAILURE;
        }
        fd.close();

        file_status = file_empty_check("empdetails.txt");
        if (file_status == -30)
        {
            cout<<"\nempdetails file has no content\n";
            return FAILURE;
        }
        ifstream fb;
        fb.open("empdetails.txt");

        while(fb&& i < num_of_emp)
        {
            emplist.push_back(new employee);
            fb>>emplist.back()->ID;
            fb>>emplist.back()->name;
            fb>>emplist.back()->age;
            fb>>emplist.back()->phoneno;
            fb>>emplist.back()->address;
            fb>>emplist.back()->sex;
            fb>>emplist.back()->salary;
            fb>>emplist.back()->term;
            fb>>emplist.back()->description;
            i++;
        }
        fb.close();
        return SUCCESS;
     }
     int update_database()
     {
        ofstream fdb;
        fdb.open("numofbike.txt");
        fdb<<(bikelist.end()-bikelist.begin())<<endl;
        fdb.close();

        fdb.open("bikedetails.txt");
        vector<bike *>::iterator it;

        for(it=bikelist.begin();it!=bikelist.end();it++)
        {
        fdb<<(*it)->veh_name<<" ";
        fdb<<(*it)->modelNo<<" ";
        fdb<<(*it)->regNo<<" ";
        fdb<<(*it)->rate<<" ";
        fdb<<(*it)->damage<<" ";
        fdb<<(*it)->type<<" ";
        fdb<<(*it)->power<<" ";
        fdb<<endl;
        }
        fdb.close();

        ofstream fdc;
        fdc.open("numofcar.txt");
        fdc<<(carlist.end()-carlist.begin())<<endl;
        fdc.close();

        fdc.open("cardetails.txt");

        vector<car *>::iterator itc;

        for(itc=carlist.begin();itc!=carlist.end();itc++)
        {
        fdc<<(*itc)->veh_name<<" ";
        fdc<<(*itc)->modelNo<<" ";
        fdc<<(*itc)->regNo<<" ";
        fdc<<(*itc)->rate<<" ";
        fdc<<(*itc)->damage<<" ";
        fdc<<(*itc)->no_of_seats<<" ";
        fdc<<(*itc)->mileage<<" ";
        fdc<<(*itc)->fuel<<" ";
        fdc<<(*itc)->tank_capacity<<" ";
        fdc<<endl;
        }

        ofstream fde;
        fde.open("numofemp.txt");
        fde<<(emplist.end()-emplist.begin())<<endl;
        fde.close();

        fde.open("empdetails.txt");
        vector<employee *>::iterator ite;

        for(ite=emplist.begin();ite!=emplist.end();ite++)
        {
        fde<<(*ite)->ID<<" ";
        fde<<(*ite)->name<<" ";
        fde<<(*ite)->age<<" ";
        fde<<(*ite)->phoneno<<" ";
        fde<<(*ite)->address<<" ";
        fde<<(*ite)->sex<<" ";
        fde<<(*ite)->salary<<" ";
        fde<<(*ite)->term<<" ";
        fde<<(*ite)->description<<" ";
        fde<<endl;
        }

        fde.close();

        return SUCCESS;
    }
    void display_basic()
    {
        cout<<"\ncomp_name: ";
        cout<<comp_name<<endl;
        cout<<"comp_ID: ";
        cout<<comp_ID<<endl;
        cout<<"comp_loc: ";
        cout<<comp_loc<<endl;
        cout<<"comp_CEO: ";
        cout<<CEO<<endl;
    }
    void display_bike()
    {
        vector<bike *>::iterator it;
        for(it= bikelist.begin();it!=bikelist.end();it++)
        {
            lines();
            (*it)->display_b();
            cout<<endl;
        }
    }
    void display_car()
    {
        vector<car *>::iterator it;
        for(it= carlist.begin();it!=carlist.end();it++)
        {
            lines();
            (*it)->display_c();
                cout<<endl;
        }
    }
    void display_emp()
    {
        vector<employee *>::iterator it;
        for(it= emplist.begin();it!=emplist.end();it++)
        {
            lines();
            (*it)->display();
        }
    }
    bike *assign_bike(string regno)
    {
        vector<bike *>::iterator it;
        for(it= bikelist.begin();it!=bikelist.end();it++)
        {
            if((*it)->getreg() == regno &&(*it)->status == false)
                return (*it);
        }
        return NULL;
    }
    car *assign_car(string regno)
    {
        vector<car *>::iterator it;
        for(it= carlist.begin();it!=carlist.end();it++)
        {
            if((*it)->getreg() == regno&&(*it)->status == false)
                return (*it);
        }
        return NULL;
    }
    employee *assign_emp()
    {
        vector<employee *>::iterator it;
        for(it= emplist.begin();it!=emplist.end();it++)
        {
            if((*it)-> ord_count<5 )
                return (*it);
        }
        return NULL;
    }
    employee *assign_emp(string Id)
    {
        vector<employee *>::iterator it;
        for(it= emplist.begin();it!=emplist.end();it++)
        {
            if((*it)->ID == Id)
                return (*it);
        }
        return NULL;
    }
    bool display_bikecust()
    {
        bool flag = false;
        vector<bike *>::iterator it;
        for(it= bikelist.begin();it!=bikelist.end();it++)
        {

            if((*it)->status == false)
            {
                lines();
                flag = true;
                (*it)->display_b();
            }
        }
        return flag;
    }
    bool display_carcust()
    {
    vector<car *>::iterator it;
    bool flag = false;
    for(it= carlist.begin();it!=carlist.end();it++)
    {
        if((*it)->status == false)
        {
            lines();
            flag = true;
            (*it)->display_c();
        }
    }
    return flag;
    }
};

company *company::instance = 0;
company *MyCompany = MyCompany->getinstance();
vector<customer>cust_list;


class order
{
    int orderID;
    customer *oCust;
    employee *oEmp;
    bike *oBike;
    car *oCar;
    double total_amount;
    int no_of_days;
    paymentInfo pay;
    bool isPaid;
    bool isReturned;
public:
    order()
    {
        oCust = NULL;
        oEmp = NULL;
        oBike = NULL;
        oCar = NULL;
        total_amount = 0.0;
        no_of_days = 0;
        isPaid = false;
        isReturned = false;
    }
    int rentBike(int user)
    {
        order();
        oBike = NULL;
        string str;
        if(!MyCompany->display_bikecust())
        {
            cout<<"\nNo bike available\n";
            return FAILURE;
        }
        cout<<"\n\nEnter regNo of the bike u want to rent : ";
        cin>>str;
        oBike = MyCompany->assign_bike(str);
        if(!oBike)
        {
            cout<<"Invalid Register NO !!!!!!!!!!!\n";
            return FAILURE;
        }
        orderID = ++ORDER_IDX;

        cust_list[user].orderCount++;
        oCust = &cust_list[user];
        oBike->status = true;
        oEmp = MyCompany->assign_emp();
        oEmp->ord_count++;
        cout<<"\nNo of days (<1) : ";
        no_of_days = getint();
        no_of_days?:no_of_days=1;

        calculateAmt(1);
        return SUCCESS;
    }
    int rentCar(int user)
    {
        order();

        oCar = NULL;
        oBike = NULL;
        string str;
        if(!MyCompany->display_carcust())
        {
            cout<<"\nNo car available\n";
            return FAILURE;
        }
        cout<<"\n\nEnter regNo of the car u want to rent : ";
        cin>>str;
        oCar = MyCompany->assign_car(str);
        if(!oCar)
        {
            cout<<"Invalid Register NO !!!!!!!!!!!\n";
            return FAILURE;
        }
        cust_list[user].orderCount++;
        oCust = &cust_list[user];
        orderID = ++ORDER_IDX;

        oCar->status = true;
        oEmp = MyCompany->assign_emp();
        oEmp->ord_count++;

        cout<<"\nNo of days (<1) : ";
        no_of_days = getint();
        no_of_days?:no_of_days=1;

        calculateAmt('1');
        return SUCCESS;
    }
    int payOrder()
    {
        if(isPaid == true)
        {
            cout<<"\nAlready paid \n";
            return SUCCESS;
        }
        pay.read(total_amount);
        cout<<"\n1.CLICK 1 to confirm payment and 0 to cancel";
        if(getint()==1)
        {
            isPaid = true;
            return SUCCESS;
        }
        return FAILURE;
    }
    int return_vehicle()
    {
        if(!isPaid)
        {
            cout<<"\nPay the amount"<<total_amount<<" before returning \n";
            if(payOrder()==FAILURE)
                return FAILURE;
        }
        if(oBike)
            oBike->status = false;
        else if(oCar)
            oCar->status = false;
        (oEmp)->ord_count--;
        isReturned = true;
        return SUCCESS;
    }
    int search_order(vector<order>ord_list,int orderid)
    {
        int size_v = ord_list.end() - ord_list.begin() ;
        for(int i = 0;i <size_v ; i++)
        {
            if(ord_list[i].orderID == orderid)
                return i;
        }
        return -1;
    }
    bool showAll(vector<order> ord_list,int user)
    {
        vector<order>::iterator it;
        bool flag = false;
        for(it = ord_list.begin() ;it!=ord_list.end();it++)
        {
            if((it->oCust)->username == cust_list[user].username)
            {
                it->show_details();
                flag = true;
            }
        }
        return flag;
    }
    void show_details()
    {
        lines();
        cout<<"\n\nOrder Id : ";
        cout<<orderID;
        cout<<"\nRented Vehicle details\n";
        if(oBike)
        {
            if(oBike->regNo!="xxx")
               oBike->display_b();
        }
        if(oCar)
        {
            if(oCar->regNo!="xxx")
                oCar->display_c();
        }
        cout<<"\n---Over seer -- ";
        getemployee();

        cout<<"\nTotal amount : ";
        cout<<total_amount;

        cout<<"\nPayment Status : ";
        if(isPaid==true)
            cout<<"PAID"<<endl;
        else
            cout<<"NOT PAID"<<endl;
        if(isReturned==true)
            cout<<"Vehicle Returned"<<endl;
        else
            cout<<"Vehicle is Not returned"<<endl;

    }
    void calculateAmt(char x)
    {
        total_amount = oCar->rate * no_of_days;
    }
    void calculateAmt(int x)
    {
        total_amount = oBike->rate * no_of_days;
    }
    void getemployee()
    {
        cout<<"\nEmployee  : ";
        cout<<oEmp->name;
        cout<<"\nPhone no : ";
        cout<<oEmp->phoneno;
    }
    int getindex(vector<order> ord)
    {
        vector<order>::iterator it;

        for(it = ord.begin();it!=ord.end();it++)
        {
            if(it->oCust->username == oCust->username)
                return (it - ord.begin());

        }
        return -1;
    }
    void displayall(vector<order>ord)
    {
        vector<order>::iterator it;
        bool flag = false;

        for(it = ord.begin();it!=ord.end();it++)
        {
            it->show_details();
            flag = true;
        }
        if(!flag)
            cout<<"\nNo records found \n";
    }
    int updateDatabase_order();
    int loadOrder();
};

vector<order>ord_list;

int customer::loadCust()
{
    int file_status = file_empty_check("userdetails.txt");
    if (file_status == -30)
    {
        cout<<"\nuserdetails file has no content\n";
        return FAILURE;
    }
    ifstream fdc;
    fdc.open("userdetails.txt");
    int no_of_user = 0,i = 0 ;
    fdc>>no_of_user;
    //cout<<no_of_user;
    customer cust;
    while(fdc&&i<no_of_user)
    {
        cust_list.push_back(cust);
        fdc>>cust_list.back().username;
        fdc>>cust_list.back().password;
        fdc>>cust_list.back().name;
        fdc>>cust_list.back().age;
        fdc>>cust_list.back().phoneno;
        fdc>>cust_list.back().address;
        fdc>>cust_list.back().sex;
        ++i;
    }
    fdc.close();
    return SUCCESS;
}
int customer::updateDatabase_Cust()
{
    ofstream fdx;
    int size_v = cust_list.end()-cust_list.begin();
    int i = 0;

    fdx.open("userdetails.txt");
    fdx<<size_v<<endl;
    while(i<size_v)
    {
        fdx<<cust_list[i].username<<" ";
        fdx<<cust_list[i].password<<" ";
        fdx<<cust_list[i].name<<" ";
        fdx<<cust_list[i].age<<" ";
        fdx<<cust_list[i].phoneno<<" ";
        fdx<<cust_list[i].address<<" ";
        fdx<<cust_list[i].sex<<" ";
        fdx<<endl;
        ++i;
    }
    fdx.close();
    return SUCCESS;
}
int order::updateDatabase_order()
{
    ofstream fdx;
    int size_v ;
    fdx.open("orderdetails.txt");

    size_v = ord_list.end() - ord_list.begin();
    fdx<<size_v<<endl;
    for(int i = 0;i<size_v;i++)
    {

        fdx<<ord_list[i].orderID<<" ";
        fdx<<ord_list[i].getindex(ord_list)<<" ";
        if(ord_list[i].oBike)
            fdx<<ord_list[i].oBike->regNo<<" ";
        else
            fdx<<"xxx"<<" ";
        if(ord_list[i].oCar)
            fdx<<ord_list[i].oCar->regNo<<" ";
        else
            fdx<<"xxx"<<" ";

        fdx<<ord_list[i].oEmp->ID<<" ";

        fdx<<ord_list[i].total_amount<<" ";
        fdx<<ord_list[i].no_of_days<<" ";
        fdx<<ord_list[i].isPaid<<" ";
        fdx<<ord_list[i].isReturned<<" ";
        if(ord_list[i].isPaid)
        {
            fdx<<ord_list[i].pay.cardname<<" ";
            fdx<<ord_list[i].pay.type<<" ";
            fdx<<ord_list[i].pay.cardno<<" ";
        }
        fdx<<endl;
    }
    fdx.close();
    return SUCCESS;
}
int order::loadOrder()
{
    int file_status = file_empty_check("orderdetails.txt");
        if (file_status == -30)
        {
            cout<<"\norderdetails file has no content\n";
            return FAILURE;
        }
    ifstream fdo;
    fdo.open("orderdetails.txt");
    int no_of_orders = 0,i = 0;
    int index;
    string bikereg,carreg,empId;
    fdo>>no_of_orders;

    while(fdo&&i<no_of_orders)
    {
        order ord;
        ord_list.push_back(ord);
        fdo>>ord_list.back().orderID;
        fdo>>index;
        fdo>>bikereg;
        fdo>>carreg;
        fdo>>empId;
        fdo>>ord_list.back().total_amount;
        fdo>>ord_list.back().no_of_days;
        fdo>>ord_list.back().isPaid;
        fdo>>ord_list.back().isReturned;
        if(ord_list.back().isPaid)
        {
            fdo>>ord_list.back().pay.cardname;
            fdo>>ord_list.back().pay.type;
            fdo>>ord_list.back().pay.cardno;
            ord_list.back().pay.amount = ord_list.back().total_amount;
        }
        cust_list[index].orderCount++;
        ord_list.back().oCust = &cust_list[index];
        ord_list.back().oBike = MyCompany->assign_bike(bikereg);

        if(ord_list.back().oBike&&!ord_list.back().isReturned)
            ord_list.back().oBike->status = true;

        ord_list.back().oCar  = MyCompany->assign_car(carreg);
        if(ord_list.back().oCar&&!ord_list.back().isReturned)
            ord_list.back().oCar->status = true;

        ord_list.back().oEmp  = MyCompany->assign_emp(empId);
        if(!ord_list.back().isReturned)
            ord_list.back().oEmp->ord_count++;
        ++i;
    }
    ORDER_IDX = ord_list.back().orderID;
    return SUCCESS;
}


void message1()
{
    cout<<"\n\n1.Enter basic company info "<<endl
        <<"2.Add a bike "<<endl
        <<"3.Add a car "<<endl
        <<"4.Add a employee "<<endl
        <<"5.Remove a bike "<<endl
        <<"6.Remove a car "<<endl
        <<"7.Remove a employee "<<endl
        <<"8.Show basic info"<<endl
        <<"9.show all car "<<endl
        <<"10.show all bike "<<endl
        <<"11.show all employee "<<endl
        <<"12.show all customers "<<endl
        <<"13.show all orders "<<endl
        <<"111.Update database"<<endl
        <<"-1.Main menu \n"<<endl
        <<"Enter your choice :\n\n";
}

void notify(int x)
{
    switch(x)
    {
    case SUCCESS:
        cout<<"\n Process successfully completed\n";
        break;
    case FAILURE:
        cout<<"\n Process FAILED\n";
        break;
    case OUT_OF_INDEX:
        cout<<"\n Process tried to access invalid data ...TERMINATED\n";
        break;
    case FILE_EMPTY_ERROR:
        cout<<"\n FILE is empty\n";
        break;
    case NOTFOUND:
        cout<<"\n Record Not Found (404)\n";
        break;
    default:
        cout<<"\n Unknown Error\n";
    }
}

void message2()
{
    cout<<"\n\n1.View my profile"<<endl
        <<"2.Talk with order managing employee "<<endl
        <<"3.Rent a bike "<<endl
        <<"4.Rent a car "<<endl
        <<"5.View my orders "<<endl
        <<"6.Return a car "<<endl
        <<"7.Pay a order "<<endl
        <<"8.Save my Profile "<<endl
        <<"-1.Main menu \n"<<endl
        <<"Enter your choice :\n\n";
}

void next_menu(int user_index)
{
    clrscreen();
    int ch;
    string str;
    order ordc,ord,ordcar;
    int ord_index = -1;
    customer user;
    while(1)
    {
        ord_index = -1;
        message2();
        ch = getint();

        switch(ch)
        {
        case 1:
            cust_list[user_index].display();
            break;
        case 2:
            if(!ordc.showAll(ord_list,user_index))
                cout<<"\nNo orders placed yet !!! You have to place a order \n";
            else
            {
                cout<<"\nEnter an order ID \n";
                ch = getint();
                ord_index = ordc.search_order(ord_list,ch);
                if(ord_index == -1)
                    cout<<"\nInvalid order ID \n";
                else
                    ord_list[ord_index].getemployee();
            }
            break;
        case 3:
            if(ord.rentBike(user_index)==SUCCESS)
            {
                ord_list.push_back(ord);
                notify(SUCCESS);
            }
            else
                notify(FAILURE);
            break;
        case 4:
            if(ordcar.rentCar(user_index)==SUCCESS)
            {
                ord_list.push_back(ordcar);
                notify(SUCCESS);
            }
            else
                notify(FAILURE);
            break;
        case 5:
            if(!ordc.showAll(ord_list,user_index))
                cout<<"\nNo orders placed yet \n";
            break;
        case 6:
            if(!ordc.showAll(ord_list,user_index))
                cout<<"\nNo orders placed yet \n";
            else
            {
                cout<<"\nEnter an order ID \n";
                ch = getint();
                ord_index = ordc.search_order(ord_list,ch);
                if(ord_index == -1)
                    cout<<"\nInvalid order ID \n";
                else
                    notify(ord_list[ord_index].return_vehicle());
            }

            break;
        case 7:
            if(!ordc.showAll(ord_list,user_index))
                cout<<"\nNo orders placed yet \n";
            else
            {
                cout<<"\nEnter an order ID \n";
                ch = getint();
                ord_index = ordc.search_order(ord_list,ch);
                if(ord_index == -1)
                    cout<<"\nInvalid order ID \n";
                else
                    notify(ord_list[ord_index].payOrder());
            }
            break;
        case 8:
            notify(user.updateDatabase_Cust());
            notify(ordc.updateDatabase_order());
            break;
        case -1:
            return;
        default:
            cout<<"Invalid Option !!!!!!!\n";
        }
        clrscreen();
    }
}
void menuForCustomer()
{
    int ch;
    int user_index;
    string str,str2;
    customer user2;

    while(ch!=1||ch!=2)
    {
        clrscreen();
        cout<<"\n1.LOGIN to existing account "
            <<"\n2.Create a new account "
            <<"\n3.Main menu \nEnter your choice \n\n";
        ch = getint();

        switch(ch)
        {
        case 1:
            cout<<"\nEnter user name : ";
            cin>>str;
            cout<<"\nEnter password : ";
            cin>>str2;
            user_index = user2.login(cust_list,str,str2);
            if(user_index == FAILURE)
            {
                cout<<"Incorrect login credentials entered!!!" ;
                ch = 4;
            }
            else
                next_menu(user_index);
                break;
        case 2:
            cust_list.push_back(user2);
            notify(cust_list.back().create_account(cust_list));
            next_menu(cust_list.end()-cust_list.begin()-1);
            break;
        case 3:
            return ;
        default:
            cout<<"Invalid Option !!!!!!!\n";
        }
    }
}

void menuforadmin()
{
    int ch;
    string str;
    customer c;
    order o;
    while(1)
    {
        clrscreen();
        message1();
        ch=getint();

        switch(ch)
        {
        case 1:
            MyCompany->read();
            break;
        case 2:
            MyCompany->add_vehicle('1');//char for bike
            break;
        case 3:
            MyCompany->add_vehicle(1);
            break;
        case 4:
            MyCompany->add_employee();
            break;
        case 5:
            cout<<"\nEnter register no \n";
            cin.ignore();
            cin>>str;
            notify(MyCompany->remove_bike(str));
            break;
        case 6:
            cout<<"\nEnter register no \n";
            cin.ignore();
            cin>>str;
            notify(MyCompany->remove_car(str));
            break;
        case 7:
            cout<<"\nEnter Employee ID \n";
            cin.ignore();
            cin>>str;
            notify(MyCompany->remove_emp(str));
            break;
        case 8:
            MyCompany->display_basic();
            break;
        case 9:
            MyCompany->display_car();
            break;
        case 10:
            MyCompany->display_bike();
            break;
        case 11:
            MyCompany->display_emp();
            break;
        case 12:
            c.displayall(cust_list);
            break;
        case 13:
            o.displayall(ord_list);
            break;
        case 111:
            notify(MyCompany->update_database());
            break;
        case -1:
            return;
        default:
            cout<<"\nInvalid input\n";
        }
    }

}

void loadDatabase()
{
    customer cust;
    order ord;
    notify( MyCompany->load_bikedatabase());
    notify( cust.loadCust());
    notify( MyCompany->load_cardatabase());
    notify( MyCompany->load_empdatabase());
    notify(ord.loadOrder());
}

int main()
{
    loadDatabase();
    int ch;
    string pass;
    while(1)
    {
        clrscreen();
        cout<<"\n1. ADMIN "
            <<"\n2. CUSTOMER "
            <<"\n3.EXIT"
            <<"\nEnter ur choice \n";
        ch = getint();
        switch(ch)
        {
        case 1:
            cout<<"\nEnter Password to get admin access : '";
            cin>>pass;
            if(MyCompany->login(pass))
                menuforadmin();
            else
                cout<<"Incorrect login credentials entered!!!" ;
            break;
        case 2:
            menuForCustomer();
            break;
        case 3:
            cout<<"\n\n\t\t\tThank You For using !!!!!!!\n\t\t\tProgram terminating!!!!!!!!\n\n";
            return 0;
        default:
            cout<<"\nInvalid entry \n";
        }

    }
}
