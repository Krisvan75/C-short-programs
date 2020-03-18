#include<iostream>
#include<fstream>
#include<ctime>
#include<assert.h>
#include<string>
#include<algorithm>
using namespace std;

class Grade
{
private:
    int Number_score;
    string Letter_Grade;
    int n;
    
public:
    void inputi(int inputQ)
    {
        n=inputQ;
    }
    int inscore(int)
    {
        return Number_score;
    }
    string ingrade(int sco)
    {
        setgrade();
        return Letter_Grade;
    }
    void input(int);
    string setgrade();
    void input_grade();
    void input_size(int);
    int Average_Grade();
};
string setgfile();
int year();
int month();
int day();
int main()
{
    
    Grade g;
    int i;
    int k;
    char user_menu;
    char help;
    int* ptr;
    cout<<"How many test scores would you like to enter today:\t";
    cin>>i;
    assert(i>0);//Bonus- used assert to project the size of the array from negative values.
    g.inputi(i);
    ptr= new int[i];
    do
    {
        cout<<"           Main Menu      "<<endl;
        cout<<"*******************************"<<endl;
        cout<<"_______________________________"<<endl;
        cout<<"|\t\t\t      |\n|  1- Help\t              |"<<endl;
        cout<<"|\t\t\t      |\n|  2- Enter Scores\t      |"<<endl;
        cout<<"|\t\t\t      |\n|  3- Quit\t              |"<<endl;
        cout<<"|\t\t\t      |\n|\t\t\t      |"<<endl;
        cout<<"*******************************"<<endl;
        cout<<"your selection:-\t";
        cin>>user_menu;
        if(user_menu!='3'&& user_menu!='2'&&user_menu!='1')
        {
            cout<<"Invalid Input\n"<<"Choose 1,2, or 3"<<endl;
        }
        else if(user_menu=='1')
        {
            do
            {
            cout<<"       Help Selection\n"<<endl;
            cout<<"What do you need help with:-"<<endl;
            cout<<"1) About"<<endl;
            cout<<"2) Instructions"<<endl;
            cin>>help;
            if(help=='1')
            {
                cout<<"input your test scores and this program will calculate your grade and average"<<endl;
                cout<<"Created by Kris Vanga.\n\n"<<endl;
            }
            else if(help=='2')
            {
                cout<<"press 2 on the main menu to enter test scores"<<endl;
                cout<<"press 3 on the main menu to quit.\n\n\n"<<endl;
            }
            else
            {
                cout<<"invalid response"<<endl;
            }
            }while(help!='1' && help!='2');//input validation for help menu.
        }
    }while(user_menu!='3'&& user_menu!='2');//input validation for the menu
    if(user_menu=='2')
    {
        cout << "Enter the test scores.\n";
        
        for (k = 0; k <i; k++)
            
        {
            do{
            cout << "Test Score " << (k + 1) << ": ";
            cin >> ptr[k];
            assert(ptr[k]>=0);// assert protecting from negative values.
            if(ptr[k]>110)
            {
                cout<<"oops!, score is to high, please enter a realistic score, thank you"<<endl;
            }
            }while(ptr[k]>110);
        }
    }
    assert(user_menu=='1' || user_menu=='2');//Bonus- used assert to quit program in main menu.
    sort(ptr, ptr+i);//Bonus- sorted code.
    
    for(int s=0;s<i;s++)
    {
        cout<<ptr[s]<<"\t";
        g.input(ptr[s]);
        cout<<endl;
    }
    float average;
    int total=0;
    char agrade;
    for (int j = 0; j<i; j++)
    {
        total += ptr[j];
    }
    average = total / i;
    cout<<"Your average is:\t"<<average<<"%"<<endl;//Bonus- Letter average.
    if (average>89)
        agrade='A';
    else if(average>79 && average<90)
        agrade='B';
    else if(average>69 && average<80)
        agrade='C';
    else if (average>59 && average<70)
        agrade='D';
    else
        agrade='F';
    cout<<"Your average letter grade is:\t"<<agrade<<endl;
    cout<<"Your Lowest test score is:\t"<<ptr[0]<<endl;//Bonus- displays highest and lowest test scores
    cout<<"Your Highest test score is:\t"<<ptr[i-1]<<endl;
    if(average>=90)
    {
        cout<<"Outstanding performance!!!!"<<endl;
    }
    
    ofstream Report_card;
    
    Report_card.open("Report_card.txt");
    Report_card<<"date of entry:\t"<<month()<<"/"<<day()<<"/"<<year()<<endl;//Bonus- date of entry
    Report_card<<"Grades"<<endl;
    for(int s=0; s<i; s++)
    {
        char fgrade;
        if (ptr[s]>89)
            fgrade='A';
        else if(ptr[s]>79 && ptr[s]<90)
            fgrade='B';
        else if(ptr[s]>69 && ptr[s]<80)
            fgrade='C';
        else if (ptr[s]>59 && ptr[s]<70)
            fgrade='D';
        else
            fgrade='F';
        Report_card<<ptr[s]<<"/100\t\t"<<fgrade<<endl;
    }
    Report_card<<"Average is:\t"<<average<<"%\n";
    Report_card<<"Letter Grade:\t"<<agrade<<endl;
    Report_card<<"The lowest test score is:\t"<<ptr[0]<<endl;
    Report_card<<"The highest test score it:\t"<<ptr[i-1]<<endl;
    if(average>=90)
    {
        Report_card<<"Good Standing"<<endl;
    }
    Report_card.close();
    delete ptr;// deleting the dynamically allocated array
}

void Grade::input(int percent)
{
    Number_score= percent;
    setgrade();
    cout<< Letter_Grade;
}

string Grade::setgrade()
{
    if(Number_score>89 && Number_score<=110)// Used 110 because some tests have extra credit options. User friendly.
    {
        Letter_Grade="A";
    }
    else if(Number_score>79 and Number_score<90)
    {
        Letter_Grade="B";
    }
    else if(Number_score>69 and Number_score<80)
    {
        Letter_Grade="C";
    }
    else if(Number_score>59 and Number_score<70)
    {
        Letter_Grade="D";
    }
    else if(Number_score<60)
    {
        Letter_Grade="F";
    }
    return Letter_Grade;
}

int year()
{
    time_t t = time(0);
    struct tm * now = localtime( & t );
    return (now->tm_year+1900);
}

int month()
{
    time_t t = time(0);
    struct tm * now = localtime( & t );
    return (now->tm_mon + 1);
}

int day()
{
    time_t t = time(0);
    struct tm * now = localtime( & t );
    return(now->tm_mday);
}




