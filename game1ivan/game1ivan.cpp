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

struct loca
{
    string name;
    string descrip;
    vector <items> things;
    vector <int> portal;


};
//
struct player
{
    int loc;

    vector <items> things;
};

const int loc_count = 3;
loca place[loc_count];
player player1;

int main()
{
    player1.loc = 1;

    place[0].name = "town";
    place[0].descrip = " - big town ";
    place[0].things.push_back(items::coin);
    place[0].things.push_back(items::key);
    place[0].portal.push_back(1);

    place[1].name = "forest";
    place[1].descrip = " - rocks and water ";
    place[1].things.push_back(items::rock);
    place[1].portal.push_back(0);
    place[1].portal.push_back(2);

    place[2].name = "village";
    place[2].descrip = " - big church in the center ";
    place[2].things.push_back(items::axe);
    place[2].things.push_back(items::bottle);
    place[2].portal.push_back(1);


    while (true)
    {
        string input;
        cout << "Yours place on map: " << "\n";
        cout << place[player1.loc].name;
        cout << place[player1.loc].descrip << endl;

        cout << "enter <go> to choose place or <items> to show inventory" << endl;
        cin >> input;




        if (input == "go")
        {
            for (int i = 0; i < place[player1.loc].portal.size(); i++)
            {
                int location_num = player1.loc;
                auto location = place[location_num];
                auto portal = location.portal;
                int dest_loc = portal[i];

                cout << i << " " << place[dest_loc].name << "\n";
            }

            int in;
            cin >> in;

            int location_num = player1.loc;
            auto location = place[location_num];
            auto portal = location.portal;
            player1.loc = portal[in];

            if (in < loc_count and in >= 0)
            {
                cout << "error, invalid number";
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
            for (int i = 0; i < player1.things.size(); i++)
            {
                items a = player1.things[i];
                cout << i << " " << item_names[(int)a];
                cout << " ";
            }
            cout << "\n";
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