// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<ctime>
#include<vector>
using namespace std;

enum class items {
    coin, key, rock, bottle, axe
};


std::string item_names[] = { "coin","key","rock","bottle", "axe" };

struct door
{
    int target;
    bool open;
    int itemToOpen;

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


int main()
{
    player1.loc = 1;

    place[0].name = "town";
    place[0].descrip = " - big town ";
    place[0].things.push_back(items::coin);
    door d1, d0, d2;
    d0.open = d1.open = d2.open = false;
    d1.target = 1;
    d0.target = 0;
    d2.target = 2;
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
                int location_num = player1.loc;
                auto location = place[location_num];
                auto door = location.portal;
                int dest_loc = door[i].target;

                cout << i << " " << place[dest_loc].name << "\n";
            }

            int in;
            cin >> in;

            system("cls");
          
            if (in >= place[player1.loc].portal.size())
            {
                cout << "error, invalid number";
            }
            else
            {
                int location_num = player1.loc;
                auto location = place[location_num];
                auto door = location.portal;


                if (door[in].open)
                {
                    player1.loc = door[in].target;
                }
                else
                {
                    cout << "Door closed\n";
                }

            }

        }
        if (input == "use")
        {
            int usabale;
            inventory();
            cout << "Choose item number";
            cin >> usabale;
            //validation
            auto itemID = player1.things[usabale];
            if (itemID == items::key)
            {

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
        }
        
        





    }
}