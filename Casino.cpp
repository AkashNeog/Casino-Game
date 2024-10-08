#include <iostream>
#include <string> 
#include <cstdlib> 
#include <ctime>
using namespace std;

void drawLine(int n, char symbol);
void rules();

int main()
{
    const int numPlayers = 3;
    string playerNames[numPlayers];
    int amounts[numPlayers]; 
    int bettingAmount; 
    int guess;
    int dice; 
    char choice;
    
    srand(time(0)); 

    drawLine(60,'_');
    cout << "\n\n\n\t\tCASINO GAME\n\n\n\n";
    drawLine(60,'_');

    // Collect player names and deposit amounts
    for (int i = 0; i < numPlayers; ++i) {
        cout << "\n\nEnter Player " << i + 1 << " Name : ";
        getline(cin, playerNames[i]);

        cout << "Enter Deposit amount to play game : $";
        cin >> amounts[i];
        cin.ignore(); // To ignore newline character left in the input buffer
    }
    
    do
    {
        system("cls");
        rules();

        for (int i = 0; i < numPlayers; ++i) {
            cout << "\n\n" << playerNames[i] << ", your current balance is $ " << amounts[i] << "\n";

            do
            {
                cout << playerNames[i] << ", enter money to bet : $";
                cin >> bettingAmount;
                if(bettingAmount > amounts[i])
                    cout << "Your betting amount is more than your current balance\n"
                        <<"\nRe-enter data\n ";
            } while(bettingAmount > amounts[i]);

            do
            {
                cout << playerNames[i] << ", guess your number to bet between 1 to 10 :";
                cin >> guess;
                if(guess <= 0 || guess > 10)
                    cout << "Please check the number!! should be between 1 to 10\n"
                        <<"\nRe-enter data\n ";
            } while(guess <= 0 || guess > 10);

            dice = rand() % 10 + 1; 

            if(dice == guess)
            {
                cout << "\n\nGood Luck!! " << playerNames[i] << ", you won $" << bettingAmount * 10;
                amounts[i] = amounts[i] + bettingAmount * 10;
            }
            else
            {
                cout << "Bad Luck this time!! " << playerNames[i] << ", you lost $ " << bettingAmount << "\n";
                amounts[i] = amounts[i] - bettingAmount;
            }

            cout << "\nThe winning number was : " << dice << "\n";
            cout << "\n" << playerNames[i] << ", you have $ " << amounts[i] << "\n";
            
            if(amounts[i] == 0)
            {
                cout << playerNames[i] << ", you have no money to play ";
            }

            if (i < numPlayers - 1) {
                cout << "\nPress Enter to continue to the next player...\n";
                cin.ignore(); // Wait for the user to press Enter before continuing
                cin.get();
            }
        }

        // Check if any player wants to continue
        cout << "\n\n-->Do you want to play again (y/n)? ";
        cin >> choice;
    } while(choice == 'Y' || choice == 'y');

    cout << "\n\n\n";
    drawLine(70,'=');
    cout << "\n\nThanks for playing game.\n\n";

    for (int i = 0; i < numPlayers; ++i) {
        cout << playerNames[i] << ", your balance amount is $ " << amounts[i] << "\n";
    }

    drawLine(70,'=');

    return 0;
}

void drawLine(int n, char symbol)
{
    for(int i = 0; i < n; i++)
        cout << symbol;
    cout << "\n";
}

void rules()
{
    system("cls");
    cout << "\n\n";
    drawLine(80,'-');
    cout << "\t\tRULES OF THE GAME\n";
    drawLine(80,'-');
    cout << "\t1. Choose any number between 1 to 10\n";
    cout << "\t2. If you win you will get 10 times of money you bet\n";
    cout << "\t3. If you bet on wrong number you will lose your betting amount\n\n";
    drawLine(80,'-');
}
