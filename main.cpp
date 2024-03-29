 // In The Name Of God
// Game Kastel
// Muhammad Hussain Chahkandi

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void start();
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
private :
    int handCardNumber[3], handCardChar[3];
    int showCardNumber[6], showCardChar[6];
    int score{}, numberOfShowCards{};
    char name[30];
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
    void newShowCard( int cardsNumber, int cardsChar, int numberOfShowCard )
    {
        numberOfShowCards++;
        showCardNumber[numberOfShowCard-1] = cardsNumber;
        showCardChar[numberOfShowCard-1] = cardsChar;
    }
    void setShowCard( int cardsNumber, int cardsChar, int numberOfShowCard )
    {
        if( cardsChar == showCardChar[numberOfShowCard-1] )
        {
            showCardNumber[numberOfShowCard-1] = cardsNumber
        }
        else
            cout << "Not Allowed" << endl;
    }
    void showShowCards()
    {
        for( int i = 0; i < numberOfShowCards; i++ )
        {
            switch ( showCardChar[i] )
            {
                case 1:
                    if( showCardNumber[i] < 10 )
                        printYavarCard1Digit( showCardNumber[i] );
                    else
                        printYavarCard2Digits( showCardNumber[i] );
                    break;
                case 2:
                    if( showCardNumber[i] < 10 )
                        printSafiCard1Digit( showCardNumber[i] );
                    else
                        printSafiCard2Digits( showCardNumber[i] );
                    break;
                case 3:
                    if( showCardNumber[i] < 10 )
                        printMofradCard1Digit( showCardNumber[i] );
                    else
                        printMofradCard2Digits( showCardNumber[i] );
            }
        }
    }
    int getNumberOfShowCards()
    {
        return numberOfShowCards;
    }
    int getHandCardNumber( int numberOfCard )
    {
        return handCardNumber[numberOfCard - 1];
    }
    int getHandCardChar( int numberOfCard )
    {
        return handCardChar[numberOfCard - 1];
    }
    void setScore( int hm )
    {
        score += hm;
    }
    int getScore()
    {
        return score;
    }
    int showCardsScore()
    {
        int temp{};
        bool y = false, s = false, m = false;
        for( int i = 0; i < numberOfShowCards; i++ )
        {
            if( showCardChar[i] == 1 )
                y = true;
            if( showCardChar[i] == 2 )
                s = true;
            if( showCardChar[i] == 3 )
                m = true;
        }
        for( int i = 0; i < numberOfShowCards; i++ )
             temp += showCardNumber[i];
        if( y && s && m )
            return temp;
        else
            return 0;
    }
    void restartNumberOfShowCards()
    {
        numberOfShowCards = 0;
    }
    void hk()
    {
        int temp, temp2;
        for( int i = 0; i < numberOfShowCards - 1; i++ )
        {
            temp = showCardNumber[i];
            temp2 = showCardChar[i];
            for( int j = i+1; j < numberOfShowCards; j++ )
            {
                if( temp == showCardNumber[j] )
                {
                    if( temp2 == showCardChar[j] )
                    {
                        for( int p = j; p < numberOfShowCards - 1; p++ )
                        {
                            showCardNumber[p] = showCardNumber[p+1];
                            showCardChar[p] = showCardChar[p+1];
                        }
                    }
                }
            }
        }
    }
};

int main()
{
    cout << "++++++++ Game Kastel ++++++++\n" << endl
         << "1-- Start" << endl
         << "0-- Exit " << endl
         << "Please Enter Your Choice --> ";
    int enter;
    cin >> enter;
    if( enter == 0 )
        exit(0);
    if( enter == 1 )
        start();
    return 0;
}

void start()
{
    gameSetting();
}
void gameSetting()
{
    system("cls");

    int numberOfPlayers, victoryScore, gameMode;

    cout << "++++++++ Game Setting ++++++++\n" << endl
        << "Number of Players ( 2 to 6 ) : ";

   cin >> numberOfPlayers;
   {   // CHECK IF NUMBER OF PLAYERS IS VALID
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
    }

   cout << "\nFinish Score :
   cin >> victoryScore;

   cout << "\n* Game Mode *" << endl
        << "1-- Standard Mode \n"
        << "2-- Pro Mode (Not Available)\n"
        << "--> ";

   cin >> gameMode;

    runGame( numberOfPlayers, victoryScore, gameMode );
}

void runGame( int numberOfPlayers, int victoryScore, int gameMode )
{
    int cardsNumber[90], cardsChar[90], roundCounter = 1, maxScore{}, starterNumber = 1;
    players player1, player2, player3, player4, player5, player6;

    while ( maxScore < victoryScore ) {
    dealCard( cardsNumber, cardsChar );
    int dealCounter{};
    bool sixShowCards = false;
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
    while( maxScore < victoryScore && dealCounter <= 90 && !sixShowCards )
    {
        system("cls");
        cout << "*** Round " << roundCounter << " ***\n";

        cin.get();
        for( int i = 1; i <= numberOfPlayers; i++ )
        {
            if( maxScore >= victoryScore || dealCounter > 90 || sixShowCards )
                break;
            system("cls");
            cout << "*** Round " << roundCounter << " ***\n";
            cout << "!!!! Player Number " << i << " !!!!" << endl;
            cout << "Press Enter If You're Player Number " << i << endl;
            cin.get();
            cin.get();
            system("cls");
            cout << "*** Round " << roundCounter << " ***\n";
            cout << "!!!! Player Number " << i << " !!!!" << endl;
            cout << "Player Number " << i << " Hand Cards " << endl;
            switch ( i )
            {
              case 1:
                  player1.showHandCards();
                  break;
              case 2:
                  player2.showHandCards();
                  break;
              case 3:
                  player3.showHandCards();
                  break;
              case 4:
                  player4.showHandCards();
                  break;
              case 5:
                  player5.showHandCards();
                  break;
              case 6:
                  player6.showHandCards();
                  break;
            }
            for( int j = 1; j <= numberOfPlayers; j++ )
            {
                cout << "Player Number " << j << " Show Cards" << endl;
                switch ( j )
                {
                    case 1:
                        player1.showShowCards();
                        break;
                    case 2:
                        player2.showShowCards();
                        break;
                    case 3:
                        player3.showShowCards();
                        break;
                    case 4:
                        player4.showShowCards();
                        break;
                    case 5:
                        player5.showShowCards();
                        break;
                    case 6:
                        player6.showShowCards();
                        break;
                }
            }
            if( maxScore >= victoryScore || dealCounter > 90 || sixShowCards )
                break;
            int chosenHandCard, chosenPlayer, chosenShowCard, numberOfShowCards;
            cout << "Choose One Of Your Hand Cards!!" << endl;
            cin >> chosenHandCard;
            cout << "Choose Number Of Player You Want To Play For!! " << endl;
            cin >> chosenPlayer;
            cout << "Choose Number Of Show Card!!" << endl;
            cin >> chosenShowCard;
            int arg1, arg2;
            switch ( i )
            {
                case 1:
                    arg1 = player1.getHandCardNumber( chosenHandCard );
                    arg2 = player1.getHandCardChar( chosenHandCard );
                    break;
                case 2:
                    arg1 = player2.getHandCardNumber( chosenHandCard );
                    arg2 = player2.getHandCardChar( chosenHandCard );
                    break;
                case 3:
                    arg1 = player3.getHandCardNumber( chosenHandCard );
                    arg2 = player3.getHandCardChar( chosenHandCard );
                    break;
                case 4:
                    arg1 = player4.getHandCardNumber( chosenHandCard );
                    arg2 = player4.getHandCardChar( chosenHandCard );
                    break;
                case 5:
                    arg1 = player5.getHandCardNumber( chosenHandCard );
                    arg2 = player5.getHandCardChar( chosenHandCard );
                    break;
                case 6:
                    arg1 = player6.getHandCardNumber( chosenHandCard );
                    arg2 = player6.getHandCardChar( chosenHandCard );
                    break;
            }
            switch( chosenPlayer )
            {
                case 1:
                    numberOfShowCards = player1.getNumberOfShowCards();
                    if( chosenShowCard <= numberOfShowCards )
                        player1.setShowCard( arg1,  arg2, chosenShowCard);
                    else
                        player1.newShowCard( arg1, arg2, chosenShowCard);
                    player1.setHandCards( cardsNumber[dealCounter], cardsChar[dealCounter], chosenHandCard - 1 );
                    dealCounter++;
                    break;
                case 2:
                    numberOfShowCards = player2.getNumberOfShowCards();
                    if( chosenShowCard <= numberOfShowCards )
                        player2.setShowCard( arg1,  arg2, chosenShowCard);
                    else
                        player2.newShowCard( arg1, arg2, chosenShowCard);
                    player2.setHandCards( cardsNumber[dealCounter], cardsChar[dealCounter], chosenHandCard - 1 );
                    dealCounter++;
                    break;
                case 3:
                    numberOfShowCards = player3.getNumberOfShowCards();
                    if( chosenShowCard <= numberOfShowCards )
                        player3.setShowCard( arg1,  arg2, chosenShowCard);
                    else
                        player3.newShowCard( arg1, arg2, chosenShowCard);
                    player3.setHandCards( cardsNumber[dealCounter], cardsChar[dealCounter], chosenHandCard - 1 );
                    dealCounter++;
                    break;
                case 4:
                    numberOfShowCards = player4.getNumberOfShowCards();
                    if( chosenShowCard <= numberOfShowCards )
                        player4.setShowCard( arg1,  arg2, chosenShowCard);
                    else
                        player4.newShowCard( arg1, arg2, chosenShowCard);
                    player4.setHandCards( cardsNumber[dealCounter], cardsChar[dealCounter], chosenHandCard - 1 );
                    dealCounter++;
                    break;
                case 5:
                    numberOfShowCards = player5.getNumberOfShowCards();
                    if( chosenShowCard <= numberOfShowCards )
                        player5.setShowCard( arg1,  arg2, chosenShowCard);
                    else
                        player5.newShowCard( arg1, arg2, chosenShowCard);
                    player5.setHandCards( cardsNumber[dealCounter], cardsChar[dealCounter], chosenHandCard - 1 );
                    dealCounter++;
                    break;
                case 6:
                    numberOfShowCards = player6.getNumberOfShowCards();
                    if( chosenShowCard <= numberOfShowCards )
                        player6.setShowCard( arg1, arg2, chosenShowCard);
                    else
                        player6.newShowCard( arg1, arg2, chosenShowCard);
                    player6.setHandCards( cardsNumber[dealCounter], cardsChar[dealCounter], chosenHandCard - 1 );
                    dealCounter++;
                    break;
            }

            int tmp;
            switch ( i )
            {
                case 1:
                    tmp = player1.getScore() + player1.showCardsScore();
                    if( tmp > maxScore )
                        maxScore = tmp;
                    if( player1.getNumberOfShowCards() >= 6 )
                        sixShowCards = true;
                    break;
                case 2:
                    tmp = player2.getScore() + player2.showCardsScore();
                    if( tmp > maxScore )
                        maxScore = tmp;
                    if( player2.getNumberOfShowCards() >= 6 )
                        sixShowCards = true;
                    break;
                case 3:
                    tmp = player3.getScore() + player3.showCardsScore();
                    if( tmp > maxScore )
                        maxScore = tmp;
                    if( player3.getNumberOfShowCards() >= 6 )
                        sixShowCards = true;
                    break;
                case 4:
                    tmp = player4.getScore() + player4.showCardsScore();
                    if( tmp > maxScore )
                        maxScore = tmp;
                    if( player4.getNumberOfShowCards() >= 6 )
                        sixShowCards = true;
                    break;
                case 5:
                    tmp = player5.getScore() + player5.showCardsScore();
                    if( tmp > maxScore )
                        maxScore = tmp;
                    if( player5.getNumberOfShowCards() >= 6 )
                        sixShowCards = true;
                    break;
                case 6:
                    tmp = player6.getScore() + player6.showCardsScore();
                    if( tmp > maxScore )
                        maxScore = tmp;
                    if( player6.getNumberOfShowCards() >= 6 )
                        sixShowCards = true;
                    break;
            }
            if( maxScore >= victoryScore || dealCounter > 90 || sixShowCards )
                break;
        }
        if( maxScore >= victoryScore || dealCounter > 90 || sixShowCards )
            break;
    }
    for( int i = 1; i <= numberOfPlayers; i++ )
    {
        int roundScore;
        switch ( i )
        {
            case 1:
                roundScore = player1.showCardsScore();
                player1.setScore( roundScore );
                player1.restartNumberOfShowCards();
                break;
            case 2:
                roundScore = player2.showCardsScore();
                player2.setScore( roundScore );
                player2.restartNumberOfShowCards();
                break;
            case 3:
                roundScore = player3.showCardsScore();
                player3.setScore( roundScore );
                player3.restartNumberOfShowCards();
                break;
            case 4:
                roundScore = player4.showCardsScore();
                player4.setScore( roundScore );
                player4.restartNumberOfShowCards();
                break;
            case 5:
                roundScore = player5.showCardsScore();
                player5.setScore( roundScore );
                player5.restartNumberOfShowCards();
                break;
            case 6:
                roundScore = player6.showCardsScore();
                player6.setScore( roundScore );
                player6.restartNumberOfShowCards();
                break;
        }
    }
    for( int i = 0; i < numberOfPlayers; i++ )
    {
            int tmp;
            switch ( i )
            {
                case 1:
                    tmp = player1.getScore();
                    if( tmp > maxScore )
                        maxScore = tmp;
                    break;
                case 2:
                    tmp = player2.getScore();
                    if( tmp > maxScore )
                        maxScore = tmp;
                    break;
                case 3:
                    tmp = player3.getScore();
                    if( tmp > maxScore )
                        maxScore = tmp;
                    break;
                case 4:
                    tmp = player4.getScore();
                    if( tmp > maxScore )
                        maxScore = tmp;
                    break;
                case 5:
                    tmp = player5.getScore();
                    if( tmp > maxScore )
                        maxScore = tmp;
                    break;
                case 6:
                    tmp = player6.getScore();
                    if( tmp > maxScore )
                        maxScore = tmp;
                    break;
            }
    }
    if( maxScore >= victoryScore )
        break;
    roundCounter++;
    }
    system("cls");
    for( int i = 1; i <= numberOfPlayers; i++ )
    {
        int tmp;
        switch ( i )
        {
            case 1:
                tmp = player1.getScore();
                if( tmp >= victoryScore )
                    cout << "Player Number 1 Is The Winner";
                break;
            case 2:
                tmp = player2.getScore();
                if( tmp >= victoryScore )
                    cout << "Player Number 2 Is The Winner";
                break;
            case 3:
                tmp = player3.getScore();
                if( tmp >= victoryScore )
                    cout << "Player Number 3 Is The Winner";
                break;
            case 4:
                tmp = player4.getScore();
                if( tmp >= victoryScore )
                    cout << "Player Number 4 Is The Winner";
                break;
            case 5:
                tmp = player5.getScore();
                if( tmp >= victoryScore )
                    cout << "Player Number 5 Is The Winner";
                break;
            case 6:
                tmp = player6.getScore();
                if( tmp >= victoryScore )
                    cout << "Player Number 6 Is The Winner";
        }
    }
}
void printYavarCard1Digit( int n )
{
    cout << "\t _ _ _ _ _ _ _ _ " << endl
        << "\t| "<< n << "             |" << endl
        << "\t|    |     |    |" << endl
        << "\t|    |     |    |" << endl
        << "\t|    |_ _ _|    |" << endl
        << "\t|          |    |" << endl
        << "\t|          |    |" << endl
        << "\t|     _ _ _|    |" << endl
        << "\t|             "<< n << " |" << endl
        << "\t|_ _ _ _ _ _ _ _|" << endl;
}
void printYavarCard2Digits( int n )
{
    cout << "\t _ _ _ _ _ _ _ _ " << endl
        << "\t| "<< n << "            |" << endl
        << "\t|    |     |    |" << endl
        << "\t|    |     |    |" << endl
        << "\t|    |_ _ _|    |" << endl
        << "\t|          |    |" << endl
        << "\t|          |    |" << endl
        << "\t|     _ _ _|    |" << endl
        << "\t|            "<< n << " |" << endl
        << "\t|_ _ _ _ _ _ _ _|" << endl;
}
void printSafiCard1Digit( int n )
{
    cout << "\t _ _ _ _ _ _ _ _ " << endl
         << "\t| "<< n << "   _ _ _     |" << endl
         << "\t|    |     |    |" << endl
         << "\t|    |          |" << endl
         << "\t|    |_ _ _     |" << endl
         << "\t|          |    |" << endl
         << "\t|          |    |" << endl
         << "\t|    |_ _ _|    |" << endl
         << "\t|             "<< n << " |" << endl
         << "\t|_ _ _ _ _ _ _ _|" << endl;
}
void printSafiCard2Digits( int n )
{
    cout << "\t _ _ _ _ _ _ _ _ " << endl
         << "\t| "<< n << "  _ _ _     |" << endl
         << "\t|    |     |    |" << endl
         << "\t|    |          |" << endl
         << "\t|    |_ _ _     |" << endl
         << "\t|          |    |" << endl
         << "\t|          |    |" << endl
         << "\t|    |_ _ _|    |" << endl
         << "\t|            "<< n << " |" << endl
         << "\t|_ _ _ _ _ _ _ _|" << endl;
}
void printMofradCard1Digit( int n )
{
    cout << "\t _ _ _ _ _ _ _ _ " << endl
         << "\t| "<< n << "             |" << endl
         << "\t|               |" << endl
         << "\t|   |\\    /|    |" << endl
         << "\t|   | \\  / |    |" << endl
         << "\t|   |  \\/  |    |" << endl
         << "\t|   |      |    |" << endl
         << "\t|               |" << endl
         << "\t|             "<< n << " |" << endl
         << "\t|_ _ _ _ _ _ _ _|" << endl;
}
void printMofradCard2Digits( int n )
{
    cout << "\t _ _ _ _ _ _ _ _ " << endl
         << "\t| "<< n << "            |" << endl
         << "\t|               |" << endl
         << "\t|   |\\    /|    |" << endl
         << "\t|   | \\  / |    |" << endl
         << "\t|   |  \\/  |    |" << endl
         << "\t|   |      |    |" << endl
         << "\t|               |" << endl
         << "\t|            "<< n << " |" << endl
         << "\t|_ _ _ _ _ _ _ _|" << endl;
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
}
