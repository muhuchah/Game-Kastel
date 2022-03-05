// In The Name Of God
// Game Kastel
// Muhammad Hussein Chahkandi

#include <iostream>

using namespace std;

void start();
void help();
void gameSetting();
void runGame( int, int, int );
void printYavarCard1Digit( int );
void printYavarCard2Digits( int );
void printSafiCard1Digit( int );
void printSafiCard2Digits( int );
void printMofradCard1Digit( int );
void printMofradCard2Digits( int );


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
{

}

void gameSetting()
{
    system("cls");
    cout << "++++++++ Game Setting ++++++++\n" << endl
        << "Number of Players ( 2 to 6 ) : ";
   int numberOfPlayers;
   cin >> numberOfPlayers;
   if( numberOfPlayers < 2 )
    {
        cout << "!! You Need More Players !!";
        gameSetting();
    }
    else if( numberOfPlayers > 6 )
    {
        cout << "!! Too Many Players !!";
        gameSetting();
    }
   cout << "\nFinish Score : ";
   int victoryScore;
   cin >> victoryScore;
   cout << "\n* Which Mode *" << endl
        << "1-- Standard Mode \n"
        << "2-- Pro Mode \n"
        << "--> ";
   int gameMode;
   cin >> gameMode;
   runGame( numberOfPlayers, victoryScore, gameMode );
}

void runGame( int numberOfPlayers, int victoryScore, int gameMode )
{
    for( int i = 1; i <= numberOfPlayers; i++ )
    {
        system("cls");
        cout << "***| Player Number "
             << i << " |***" << endl;
        for( int cardNumber = 0; cardNumber < 3; cardNumber++ )
        {

        }
    }
}
void printYavarCard1Digit( int n )
{
    cout << " _ _ _ _ _ _ _ _ " << endl
        << "| "<< n << "             |" << endl
        << "|    |     |    |" << endl
        << "|    |     |    |" << endl
        << "|    |_ _ _|    |" << endl
        << "|          |    |" << endl
        << "|          |    |" << endl
        << "|     _ _ _|    |" << endl
        << "|             "<< n << " |" << endl
        << "|_ _ _ _ _ _ _ _|" << endl;
}
void printYavarCard2Digits( int n )
{
    cout << " _ _ _ _ _ _ _ _ " << endl
        << "| "<< n << "            |" << endl
        << "|    |     |    |" << endl
        << "|    |     |    |" << endl
        << "|    |_ _ _|    |" << endl
        << "|          |    |" << endl
        << "|          |    |" << endl
        << "|     _ _ _|    |" << endl
        << "|            "<< n << " |" << endl
        << "|_ _ _ _ _ _ _ _|" << endl;
}
void printSafiCard1Digit( int n )
{
    cout << " _ _ _ _ _ _ _ _ " << endl
         << "| "<< n << "   _ _ _     |" << endl
         << "|    |     |    |" << endl
         << "|    |          |" << endl
         << "|    |_ _ _     |" << endl
         << "|          |    |" << endl
         << "|          |    |" << endl
         << "|    |_ _ _|    |" << endl
         << "|             "<< n << " |" << endl
         << "|_ _ _ _ _ _ _ _|" << endl;
}
void printSafiCard2Digits( int n )
{
    cout << " _ _ _ _ _ _ _ _ " << endl
         << "| "<< n << "  _ _ _     |" << endl
         << "|    |     |    |" << endl
         << "|    |          |" << endl
         << "|    |_ _ _     |" << endl
         << "|          |    |" << endl
         << "|          |    |" << endl
         << "|    |_ _ _|    |" << endl
         << "|            "<< n << " |" << endl
         << "|_ _ _ _ _ _ _ _|" << endl;
}
void printMofradCard1Digit( int n )
{
    cout << " _ _ _ _ _ _ _ _ " << endl
         << "| "<< n << "             |" << endl
         << "|               |" << endl
         << "|   |\\    /|    |" << endl
         << "|   | \\  / |    |" << endl
         << "|   |  \\/  |    |" << endl
         << "|   |      |    |" << endl
         << "|               |" << endl
         << "|             "<< n << " |" << endl
         << "|_ _ _ _ _ _ _ _|" << endl;
}
void printMofradCard2Digits( int n )
{
    cout << " _ _ _ _ _ _ _ _ " << endl
         << "| "<< n << "            |" << endl
         << "|               |" << endl
         << "|   |\\    /|    |" << endl
         << "|   | \\  / |    |" << endl
         << "|   |  \\/  |    |" << endl
         << "|   |      |    |" << endl
         << "|               |" << endl
         << "|            "<< n << " |" << endl
         << "|_ _ _ _ _ _ _ _|" << endl;
}
