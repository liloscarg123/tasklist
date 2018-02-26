
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <windows.h>

using namespace std;

void fileOpener(ifstream& in_stream);

void MainMenu(string menuArray[], int selected);

void DisplayRecentTask(const string rTaskArray[], int counter);

void getScanCode(int& input);

void getRecentTask(ifstream& in_stream, string rTaskArray[], int& counter);

const int MENU_NUM = 10;
int main()
{
    string menuArray[MENU_NUM] = {"Create a New Task", "Edit a Task"},
           rTaskArray[MENU_NUM];

    int selected = 0, input, counter = 0;
    ifstream in_stream;

    fileOpener(in_stream);

    getRecentTask(in_stream, rTaskArray, counter);

    do
    {
        MainMenu(menuArray, selected);
        DisplayRecentTask(rTaskArray, counter);

        getScanCode(input);

        switch (input)
        {
        case 72:
            selected = 0;
            break;
        case 80:
            selected = 1;
            break;
        }

       system("CLS");
    }while(true);


    system("pause");
    return 0;
}
void DisplayRecentTask(const string rTaskArray[], int counter)
{
    cout << "\n===============================================\n"
         << "The most recent upcoming tasks:\n\n";

    for(int i = 0; i <= counter; i++)
        cout << rTaskArray[i] << endl;

     cout << "\n===============================================\n";

}

void getRecentTask(ifstream& in_stream, string rTaskArray[], int& counter)
{
    char reader;
    while(!in_stream.eof())
    {
        in_stream.get(reader);

        if(reader != '\n' && !in_stream.eof())
            rTaskArray[counter] += reader;

        else
            counter++;

    }
}

void MainMenu(string menuArray[], int selected)
{

    for(int i = 0; i < 3; i++)
    {
        if(selected == i)
            cout << "---> "<< menuArray[i] << endl;
        else
            cout << menuArray[i] << endl;

    }
}

void getScanCode(int& input)
{
    input = getch();//gets code for key

    if(input == 0 || input == 224)//If player chooses arrow keys of page keys
        input = getch();//run second getch
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
