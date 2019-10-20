#include <iostream>
#include <string>
#include <array>
#include <cstdlib>
#include <time.h>
struct PlayingCard{
std::string suite = "Clubs";
int value = 2;

void randomcard()
{
srand(time(0));
value = rand()%13 + 1;
int y = rand()%4 +1;
if(y == 1)
    suite = "Hearts";
else if(y == 2)
    suite = "Diamonds";
else if(y ==3)
    suite  = "Clubs";
else
    suite  ="Spades";
}
void cardname()
{
if(value > 1 && value < 11)
std::cout << value <<" of " << suite << "\n";    
if(value ==1)
    std::cout << "Ace of " << suite << "\n";
if(value == 11)
    std::cout << "Jack of " << suite << "\n";
if(value == 12)
    std::cout << "Queen of " << suite << "\n";
if(value == 13)
    std::cout << "King of " << suite << "\n";
}
};

int answer(char z)
{

if(z == 'y')
    return 1;
if(z == 'n')
    return 0;
return 2;
}

int main()
{

PlayingCard PC;
int b = 1;


while(b == 1)
{
PC.randomcard();
int x = PC.value;
std::string y = PC.suite;
char z_1;
std::cout << "Guess if a card is an image card (y/n)?\n";
std::cin >> z_1;
int z = answer(z_1);
PC.cardname();
if(x > 10 && z == 1)
    {
        std::cout << "Correct! \n";
    
        
    }
else if(x==1 && z ==1)
    {
        std::cout << "Correct! \n";
        
    }
else if(x < 11 && z == 0 && x != 1)
    {
        std::cout << "Correct! \n";
        
    
    }

else
    {
        std::cout << "False. Game over.\n";    
        break;
       
    }
PC.randomcard();
int x_2 = PC.value;
std::string y_2 = PC.suite;
char z_2;
std::cout << "Guess if a card is strictly larger than the previous card (y/n)?\n";
std::cin >> z_2;
int v = answer(z_2);
PC.cardname();
if(x_2 > x && v == 1)
    {
        std::cout << "Correct! \n";
    }

else if(x_2 <= x && v == 0)
    {
    std::cout << "Correct!\n";
    }


else
{
    std::cout << "False. Game over.\n";
    break;
    
}

PC.randomcard();
int x_3 = PC.value;
std::string y_3 = PC.suite;
char z_3;
std::cout << "Guess if a card is between the last cards (y/n)?\n";
std::cin >> z_3;
int v_1 = answer(z_3);
PC.cardname();
if(x_3 <= x_2 && x_3 >= x && x_2 >= x && v_1 == 1)
    {
        std::cout << "Correct! \n";
    }

else if(x_3 <= x && x_3 >= x_2 && x >= x_2 && v_1 == 1)
    {
    std::cout << "Correct!\n";
    }
else if(x_3 >= x && x_3 >= x_2 && v_1 == 0)
     {
    std::cout << "Correct!\n";
    }
else if(x_3 <= x && x_3 <= x_2 && v_1 == 0)
     {
    std::cout << "Correct!\n";
    }
else
{
    std::cout << "False.Game over.\n";
    break;
}
PC.randomcard();
int x_4 = PC.value;
std::string y_4 = PC.suite;
std::string  z_4;

std::cout << "Guess is the card of the same colour than the last one (y/n)?\n";
std::cin >> z_4;
PC.cardname();
if(z_4 == "y" && y_4 == "Heart" && y_3 == "Diamond")
    std::cout << "Correct!\n";
else if(z_4 == "y" && y_3 == "Heart" && y_4 == "Diamond")
    std::cout << "Correct!\n";
else if(z_4 == "y" && y_4 == "Spade" && y_3 == "Club")
    std::cout << "Correct!\n";
else if(z_4 == "y" && y_3 == "Spade" && y_4 == "Club")
    std::cout << "Correct!\n";
else

if(z_4 == "n" && y_4 == "Heart" && y_3 != "Diamond")
    std::cout << "Correct!\n";
else if(z_4 == "n" && y_4 == "Heart" && y_3 != "Heart")
    std::cout << "Correct!\n";
else if(z_4 == "n" && y_4 == "Diamond" && y_3 != "Diamond")
    std::cout << "Correct!\n";
else if(z_4 == "n" && y_4 == "Diamond" && y_3!= "Heart")
    std::cout << "Correct!\n";
else if(z_4 == "n" && y_4 == "Spade" && y_3 != "Spade")
    std::cout << "Correct!\n";
else if(z_4 == "n" && y_4 == "Spade" && y_3 != "Spade")
    std::cout << "Correct!\n";
else if(z_4 == "n" && y_4 == "Club" && y_3 != "Club")
    std::cout << "Correct!\n";
else if(z_4 == "n" && y_4 == "Club" && y_3 != "Spade")
    std::cout << "Correct!\n";
else
    {
        std::cout << "False. Game over.\n";
        break;
    }

PC.randomcard();
int x_5 = PC.value;
std::string y_5 = PC.suite;
std::string z_5;
std::cout << "Guess is the card of the same suit than the last one (y/n)?\n";
std::cin >> z_5;
PC.cardname();
if(z_5 == "y" && y_5 == "Heart" && y_4 == "Heart")
    std::cout << "Correct!. You passed the game!\n";
else if(z_5 == "y" && y_5 == "Diamond" && y_4 == "Diamond")
    std::cout << "Correct! You passed the game!\n";
else if(z_5 == "y" && y_5 == "Spade" && y_4 == "Spade")
    std::cout << "Correct! You passed the game!\n";
else if(z_5 == "y" && y_5 == "Cub" && y_4 == "Cub")
    std::cout << "Correct! You passed the game!\n";
else if(z_5 == "n" && y_5 == "Heart" && y_4 != "Heart")
    std::cout << "Correct! You passed the game!\n";
else if(z_5 == "n" && y_5 == "Diamond" && y_4 != "Diamond")
    std::cout << "Correct! You passed the game!\n";
else if(z_5 == "n" && y_5 == "Spade" && y_4 != "Spade")
    std::cout << "Correct! You passed the game!\n";
else if(z_5 == "n" && y_5 == "Cub" && y_4 != "Cub")
    std::cout << "Correct! You passed the game!\n";
else
{
    std::cout << "False. Game over.\n";
    break;
}

}

return 0;
}