// In The Name Of God
// Game Kastel
// Muhammad Hussein Chahkandi

#include <iostream>

using namespace std;

void start();
void gameSetting();

int main()
{
    cout << "++++++++ Game Kastel ++++++++\n" << endl
         << "1-- Start" << endl
         << "2-- Help " << endl
         << "0-- Exit " << endl
         << "Please Enter Your Choice --> ";
    int enter;
    cin >> enter;
    if( enter == 0 )
        exit(0);
    if( enter == 1 )
        start();
    else
        help();

    return 0;
}

void start()
{
    gameSetting();
}

void help()
{}

void gameSetting()
{
    system("cls");
    cout << "++++++++ Game Setting ++++++++\n" << endl
        << "Number of Players : ";
   int numberOfPlayers;
   cin >> numberOfPlayers;
   cout << "\nFinish Score : ";
   int victoryScore;
   cin >> victoryScore;
   cout << "\n* Which Mode *" << endl
        << "1-- Standard Mode \n"
        << "2-- Pro Mode \n"
        << "--> ";
   int gameMode;
   cin >> gameMode;

}
