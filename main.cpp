// In The Name Of God
// Game Kastel
// Muhammad Hussein Chahkandi

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void start();
void help();
void gameSetting();
void runGame( int, int, int );
void dealCard( int (&)[90], int (&)[90] );
void printYavarCard1Digit( int );
void printYavarCard2Digits( int );
void printSafiCard1Digit( int );
void printSafiCard2Digits( int );
void printMofradCard1Digit( int );
void printMofradCard2Digits( int );

class players
{
public :
    void setHandCards( int cardsNumber, int cardsChar, int i )
    {
        handCardNumber[i] = cardsNumber;
        handCardChar[i] = cardsChar;
    }
    void showHandCards()
    {
        for( int i = 0; i < 3; i++ )
        {
            switch ( handCardChar[i] )
            {
                case 1:
                    {
                        if( handCardNumber[i] < 10 )
                            printYavarCard1Digit( handCardNumber[i] );
                        else
                            printYavarCard2Digits( handCardNumber[i] );
                        break;
                    }
                case 2:
                    {
                        if( handCardNumber[i] < 10 )
                            printSafiCard1Digit( handCardNumber[i] );
                        else
                            printSafiCard2Digits( handCardNumber[i] );
                        break;
                    }
                case 3:
                    {
                        if( handCardNumber[i] < 10 )
                            printMofradCard1Digit( handCardNumber[i] );
                        else
                            printMofradCard2Digits( handCardNumber[i] );
                        break;
                    }
            }
        }
    }
private :
    int handCardNumber[3], handCardChar[3];
    int showCardNumber[6], showCardChar[6];
    int score{};
};

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
    int cardsNumber[90], cardsChar[90];
    dealCard( cardsNumber, cardsChar );

    int dealCounter{};
    players player1, player2, player3, player4, player5, player6;
    switch ( numberOfPlayers )
    {
        case 6:
            {
                dealCounter += 3;
                for( int i = 15; i < 18; i++ )
                    player6.setHandCards( cardsNumber[i], cardsChar[i], i-15 );
            }
        case 5:
            {
                dealCounter += 3;
                for( int i = 12; i < 15; i++ )
                    player5.setHandCards( cardsNumber[i], cardsChar[i], i-12 );
            }
        case 4:
            {
                dealCounter += 3;
                for( int i = 9; i < 12; i++ )
                    player4.setHandCards( cardsNumber[i], cardsChar[i], i-9 );
            }
        case 3:
            {
                dealCounter += 3;
                for( int i = 6; i < 9; i++ )
                    player3.setHandCards( cardsNumber[i], cardsChar[i], i-6 );
            }
        case 2:
            {
                dealCounter += 6;
                for( int i = 0; i < 3; i++ )
                    player1.setHandCards( cardsNumber[i], cardsChar[i], i );
                for( int i = 3; i < 6; i++ )
                    player2.setHandCards( cardsNumber[i], cardsChar[i], i-3 );
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

void dealCard( int (&cardsNumber)[90], int (&cardsChar)[90] )
{
    int cardCounter{}, numberTemp, charTemp;
    for( int i = 0; i < 90; i++ )
    {
        bool cardsNotFree;
        srand(time(0));
        do
        {
            cardsNotFree = false;
            numberTemp = rand() % 15 + 1;
            charTemp = rand() % 3 + 1;
            for( int j = 0; j < cardCounter; j++ )
            {
                if( numberTemp == cardsNumber[j] )
                {
                    if( charTemp == cardsChar[j] )
                    {
                        for( int r = j+1; r < cardCounter; r++ )
                        {
                            if( numberTemp == cardsNumber[r] )
                            {
                                if( charTemp == cardsChar[r] )
                                {
                                    cardsNotFree = true;
                                }
                            }
                        }
                    }
                }
            }
        }while( cardsNotFree );
        cardsNumber[cardCounter] = numberTemp;
        cardsChar[cardCounter] = charTemp;
        cardCounter++;
    }

    int temp[90], temp1[90], temp2[90];
    bool tmp;
    for( int i = 0; i < 90; i++ )
    {
        tmp = false;
        int t;
        t = rand() % 90;
        for( int j = 0; j < i; j++ )
        {
            if( t == temp2[j] )
            {
                i--;
                tmp = true;
                break;
            }
            else
            {
                temp2[i] = t;
            }
        }
        if( tmp )
            continue;
        temp[i] = cardsNumber[t];
        temp1[i] = cardsChar[t];
    }
    for( int i = 0; i < 90; i++ )
    {
        cardsNumber[i] = temp[i];
        cardsChar[i] = temp1[i];
    }
    // for( int i = 0; i < 90; i++ )
    //     cout << cardsNumber[i] << ' ' << cardsChar[i] << "\t";
}
