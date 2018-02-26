
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

void fileOpener(ifstream& in_stream);

void getRecurringInfo(char& recur);

void userInput(string& taskName, int& year, int& month, int& day, int& hr, int& mins, char& time, char& recur);
/*para: year, month, days, hours, minutes, timeOfDay, recurrence (by reference)
@It'll get input from user for task name,
date but from different function and also
time in different function
*/

void getUserDate(int& year, int& month, int& day);
/* parameters: year, month, day (by reference)
@It'll get input for year, month , and day
in yyyy/mm/dd format
@Will check for:
    -format
    -wrong input
    -amount of digits in each integer
*/

void getUserTime(int& hr, int& mins, char& time);
/*para: hours, minutes, time (by reference)
@Will get users time in 12 hr format
@then use a function that convert the time to 24 hr format
*/

int main()
{
    int year, month, day, hr, mins;
    string taskName;
    char timeOfDay, recur;

    ifstream in_stream;
    ofstream out_stream;

    //fileOpener(in_stream);


    userInput(taskName, year, month, day, hr, mins, timeOfDay, recur);

    cout << "\n" << year << " " << month << " " << day << "\n";
    //Will get the current date/time based on current system
    time_t now = time(0);

    tm *ltm = localtime(&now);

    cout << "Year " << 1900 + ltm->tm_year << endl;


    system("pause");
    return 0;
}

void getUserTime(int& hr, int& mins, char& time)
{
    char separator;

    do
    {
        cout << "\nEnter the time for the task in 12hr format and\nEnter an 'a' for am or a 'p' for pm (hh:mm p) ";
        cin >> hr >> separator >> mins >> time;

        if(cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "\nIncorrect input, Enter the correct format!\n";
        }
        else if(hr <= 0 || hr > 12)
            cout << "\nEnter the correct hour!\n";
        else if(mins < 0 || mins > 59)
            cout << "\nEnter the correct minutes!\n";
        else if(separator != ':')
            cout << "\nEnter the correct format!\n";
        else if(time == 'a'|| time =='p' )
            break;
        else
            cout << "\nEnter 'a' or 'p' for am or pm!\n";

    }while(true);
}

void getUserDate(int& year, int& month, int& day)
{
    char separator;

    do
    {
        cout << "\nEnter the date in (mm/dd/yyyy) format: ";
        cin >> month >> separator >> day >> separator >> year;
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "\nIncorrect input, Enter the correct format!\n";
        }
        else if(year <= 999)
            cout << "\nEnter the correct year!\n";
        else if(month <= 0 || month > 12)
            cout << "\nEnter the correct month!\n";
        else if(day <= 0 || day > 31)
            cout << "\nEnter the correct day!\n";
        else if(separator != '/')
            cout << "\nEnter the correct format!\n";
        else
            break;

    }while(true);

}

void userInput(string& taskName, int& year, int& month, int& day, int& hr, int& mins, char& time, char& recur)
{
    cout << "\nEnter the name of the task: ";
    cin >> taskName;

    getUserDate(year, month, day);

    cout << "\nIs this a recurring task?\nAnswer 'y' for Yes or 'n' for No.\n";
    cin >> recur;

    if(recur == 'y')
        getRecurringInfo(recur);

    getUserTime(hr,mins,time);


}

void getRecurringInfo(char& recur)
{
    system("CLS");
    do
    {
        cout << "Enter 'y' for yearly recurring task,\n"
            << "Enter 'm' for monthly recurring task,\n"
            << "Enter 'w' for weekly recurring task,\n"
            << "Enter 'd' for daily recurring task.\n";
        cin >> recur;

        if(cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "\nIncorrect input, Enter the correct input!\n";
        }
        else if(isdigit(recur))
            cout << "Enter a \"y, m, w, or a d\" as an input!\n";


    }while(true);


}

void fileOpener(ifstream& in_stream)
{
    in_stream.open("listInfo.txt");// finds and opens file
    if(in_stream.fail())
    {
        cout << "\nERROR!, Failed to open file.\n";
        exit(1);
    }
}
