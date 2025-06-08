// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<ctime>
#include<vector>
#include <random>
using namespace std;


enum class items 
{
    coin, key, rock, bottle, axe
};


std::string item_names[] = { "coin","key","rock","bottle", "axe" };

struct door
{
    int target;
    bool open;
    items reqItem;
     

};
struct loca
{
    string name;
    string descrip;
    vector <items> things;
    vector <door> portal;

};

struct player
{
    int loc;
    vector <items> things;
};

const int loc_count = 3;
loca place[loc_count];
player player1;

void inventory()
{
    for (int i = 0; i < player1.things.size(); i++)
    {
        items a = player1.things[i];
        cout << i << " " << item_names[(int)a];
        cout << " ";
    }
    cout << "\n";
}
void openDoor(items item)
{
    for (loca& location : place)
    {
        for (door& currentDoor : location.portal)
        {
            if (currentDoor.reqItem == item)
            {
                currentDoor.open = true;
                cout << "Opened door leading to loc " << place[currentDoor.target].name << "!\n";
            }
        }
    }
}


int main()
{
    player1.loc = 1;

    random_device random_device;
    mt19937 generator(random_device());
    uniform_int_distribution<> atk(10, 45);
    uniform_int_distribution<> hp(100, 500);
    int atkP1 = atk(generator);
    int hpEn1 = hp(generator);
    
    int en1hp = hpEn1;
    int en1atk = 10;
    
    int p1hp = 100;
    int p1atk = atkP1;


    
    place[0].name = "town";
    place[0].descrip = " - big town ";
    place[0].things.push_back(items::coin);
    door d1, d0, d2;
    d0.open = d1.open = d2.open = false;
    d1.target = 1;
    d0.target = 0;
    d2.target = 2;
    d0.reqItem = items::key;
    d2.reqItem = items::key;
    
    place[0].portal.push_back(d1);

    place[1].name = "forest";
    place[1].descrip = " - rocks and water ";
    place[1].things.push_back(items::rock);
    place[1].things.push_back(items::key);
    place[1].portal.push_back(d0);
    place[1].portal.push_back(d2);

    place[2].name = "village";
    place[2].descrip = " - big church in the center ";
    place[2].things.push_back(items::axe);
    place[2].things.push_back(items::bottle);
    place[2].portal.push_back(d1);

    //player1.things.push_back(items::key);
    //player1.things.push_back(items::bottle);


    while (true)
    {
        string input;
        cout << "Yours place on map: " << "\n";
        cout << place[player1.loc].name;
        cout << place[player1.loc].descrip << endl;

        cout << "enter <go> to choose place or <items> to show inventory" << endl;
        cin >> input;

        system("cls");

        if (input == "go")
        {
            for (int i = 0; i < place[player1.loc].portal.size(); i++)
            {
                int destLoc = place[player1.loc].portal[i].target;
                cout << i << " " << place[destLoc].name << "\n";

            }

            int choice;
            cin >> choice;

            system("cls");

            if (choice >= place[player1.loc].portal.size())
            {
                cout << "Error: Invalid number!\n";
            }

            else
            {
                auto& selectedDoor = place[player1.loc].portal[choice];

                if (!selectedDoor.open)
                {
                    bool hasRequiredItem = false;
                    for (auto item : player1.things)
                    {
                        if (item == selectedDoor.reqItem)
                        {
                            hasRequiredItem = true;
                            break;
                        }
                    }

                    if (hasRequiredItem) {
                        selectedDoor.open = true;
                        player1.loc = selectedDoor.target;
                        cout << "You opened the door\n";
                    }
                    else
                    {
                        cout << "You need a key\n";
                    }
                }
                else
                {
                    player1.loc = selectedDoor.target;
                }
            }
        }
        if (input == "use")
        {
            inventory();
            cout << "Choose item number";
            int usabale;
            cin >> usabale;

            if (usabale >= 0 && usabale < player1.things.size())
            {
                auto itemID = player1.things[usabale];
                openDoor(itemID);
            }
            else
            {
                cout << "Selected item invalid\n";
            }

        }

        if (input == "items")
        {
            for (int i = 0; i < place[player1.loc].things.size(); i++)
            {
                items a = place[player1.loc].things[i];
                cout << i << " " << item_names[(int)a];
                cout << " ";
            }
            cout << "\n";

        }

        if (input == "list")
        {
            inventory();
        }

        if (input == "pick")
        {
            inventory();
            cout << ("write items number for pick") << "\n";
            int in;
            cin >> in;

            int location_num = player1.loc;
            auto location = place[location_num];

            if (in >= 0 and in < location.things.size())
            {
                auto thing = location.things[in];
                player1.things.push_back(thing);
                place[location_num].things.erase(place[location_num].things.begin() + in);
            }
        
            else
            {
                cout << "Error\n";
            }
        }
       
    }
} 

// check how work comands
// logic fight with npc