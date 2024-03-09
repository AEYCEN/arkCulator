#include <iostream>
#include <string>
#include <limits>
using namespace std;

/*
===============================================================================
File: 		    ArkCulator_v5.0-linux.cpp
Author: 	    TRAYVED [Discord: trayved] / AEYCEN [Discord: aeycen]
Update date: 	10. September 2023
Version: 	    5.0-linux
Description: 	This calculator is used to calculate the cost and resources 
		        required to destroy structures in Ark: Survival Evolved. 
	         	The program allows you to enter the type of weapon, the HP and 
	         	material of the structure and the presence of 6x cave damage.
	         	It then calculates the amount of explosives needed and displays
	         	the resource cost of crafting the ammo.
===============================================================================
*/

const string ANSI_RESET = "\033[0m";
const string ANSI_RED = "\033[31m";
const string ANSI_BLUE = "\033[34m";
const string ANSI_GREEN = "\033[32m";
const string ANSI_PURPLE = "\033[35m";
const string ANSI_CYAN = "\033[36m";
const string ANSI_YELLOW = "\033[33m";

const string programInfo = "\033[3m\033[1m\033[33mArk\033[32mCulator\033[0m\033[0m v5.0-linux | © 2023 TRAYVED/AEYCEN | MIT License";

enum class Material
{
    Wood,
    Stone,
    Metal,
    Tek
};

// Funktion zur Berechnung der benötigten Sprengstoffmenge
double calculateDamage(int type, Material material)
{
    double damage = 0.0;

    switch (type)
    {
    case 1:
        switch (material)
        {
        case Material::Wood:
            damage = 11813.0;
            break;
        case Material::Stone:
            damage = 99999.0;
            break;
        case Material::Metal:
            damage = 3544.0;
            break;
        case Material::Tek:
            damage = 788.0;
            break;
        }
        break;
    case 2:
        switch (material)
        {
        case Material::Wood:
            damage = 7350.0;
            break;
        case Material::Stone:
            damage = 99999.0;
            break;
        case Material::Metal:
            damage = 2205.0;
            break;
        case Material::Tek:
            damage = 596.0;
            break;
        }
        break;
    case 3:
        switch (material)
        {
        case Material::Wood:
            damage = 26800.0;
            break;
        case Material::Stone:
            damage = 14700.0;
            break;
        case Material::Metal:
            damage = 1450.0;
            break;
        case Material::Tek:
            damage = 9250.0;
            break;
        }
        break;
    case 4:
        switch (material)
        {
        case Material::Wood:
            damage = 99999.0;
            break;
        case Material::Stone:
            damage = 3446.0;
            break;
        case Material::Metal:
            damage = 355.0;
            break;
        case Material::Tek:
            damage = 40.0;
            break;
        }
        break;
    case 5:
        switch (material)
        {
        case Material::Wood:
            damage = 788.0;
            break;
        case Material::Stone:
            damage = 1838.0;
            break;
        case Material::Metal:
            damage = 237.0;
            break;
        case Material::Tek:
            damage = 53.0;
            break;
        }
        break;
    case 6:
        switch (material)
        {
        case Material::Wood:
            damage = 15750.0;
            break;
        case Material::Stone:
            damage = 700.0;
            break;
        case Material::Metal:
        case Material::Tek:
            return 0.0;
        }
        break;
    }

    return damage;
}

// Funktion zur Berechnung der benötigten Ressourcen
void calculateCost(int type, double damage)
{
    int Gunpowder = 0;
    int Crystal = 0;
    int Cement = 0;
    int Fiber = 0;
    int Hide = 0;
    int Polymer = 0;
    int Electronics = 0;
    int Metal = 0;
    int Obsidian = 0;
    int Oil = 0;
    int Stone = 0;

    switch (type)
    {
    case 1:
        Gunpowder = 60;
        Crystal = 10;
        Cement = 5;
        Fiber = 50;
        Hide = 5;
        Polymer = 5;
        Electronics = 5;
        break;
    case 2:
        Gunpowder = 40;
        Crystal = 10;
        Cement = 20;
        Polymer = 10;
        Metal = 12;
        break;
    case 4:
        Metal = 80;
        Gunpowder = 30;
        Cement = 20;
        Obsidian = 4;
        break;
    case 5:
        Fiber = 15;
        Stone = 20;
        Gunpowder = 30;
        Hide = 5;
        Metal = 2;
        Oil = 4;
        break;
    case 6:
        Stone = 30;
        Metal = 3;
        break;
    }

    // Ressourcenkosten berechnen und ausgeben
    cout << "Resources needed to craft:" << endl;
    if (Gunpowder > 0)
        cout << "Gunpowder: " << Gunpowder * damage << endl;
    if (Crystal > 0)
        cout << "Crystal: " << Crystal * damage << endl;
    if (Cement > 0)
        cout << "Cement: " << Cement * damage << endl;
    if (Fiber > 0)
        cout << "Fiber: " << Fiber * damage << endl;
    if (Hide > 0)
        cout << "Hide: " << Hide * damage << endl;
    if (Polymer > 0)
        cout << "Polymer: " << Polymer * damage << endl;
    if (Electronics > 0)
        cout << "Electronics: " << Electronics * damage << endl;
    if (Metal > 0)
        cout << "Metal: " << Metal * damage << endl;
    if (Obsidian > 0)
        cout << "Obsidian: " << Obsidian * damage << endl;
    if (Oil > 0)
        cout << "Oil: " << Oil * damage << endl;
    if (Stone > 0)
        cout << "Stone: " << Stone * damage << endl;
}

bool isValidIntInput(const string& input)
{
    try
    {
        int value = stoi(input);
        return value >= 1 && value <= 100000;
    }
    catch (const std::invalid_argument& e)
    {
        return false;
    }
    catch (const std::out_of_range& e)
    {
        return false;
    }
}

int main()
{
    cout << programInfo  << endl << endl;
    int type = 0;
    cout << "Enter Weapon [" << ANSI_YELLOW << "1" << ANSI_RESET << "(C4)/" << ANSI_YELLOW << "2" << ANSI_RESET << "(Rocket Launcher)/" << ANSI_YELLOW << "3" << ANSI_RESET << "(Tek Rifle)/" << ANSI_YELLOW << "4" << ANSI_RESET << "(Cannon)/" << ANSI_YELLOW << "5" << ANSI_RESET << "(Grenade)/" << ANSI_YELLOW << "6" << ANSI_RESET << "(Catapult)] > ";
    cin >> type;

    string displayWeapon;
    switch (type)
    {
        case 1:
            displayWeapon = "C4";
            break;
        case 2:
            displayWeapon = "Rocket Launcher";
            break;
        case 3:
            displayWeapon = "Tek Rifle";
            break;
        case 4:
            displayWeapon = "Cannon";
            break;
        case 5:
            displayWeapon = "Grenade";
            break;
        case 6:
            displayWeapon = "Catapult";
            break;
    }

    Material material;

    string materialInput;
    string displayStructure;
    while (true)
    {
        cout << "[" << ANSI_BLUE << displayWeapon << ANSI_RESET << "] Enter material of structure [" << ANSI_YELLOW << "w" << ANSI_RESET << "ood/" << ANSI_YELLOW << "s" << ANSI_RESET << "tone/" << ANSI_YELLOW << "m" << ANSI_RESET << "etal/" << ANSI_YELLOW << "t" << ANSI_RESET << "ek] > ";
        cin >> materialInput;
    
        if (materialInput == "Wood" || materialInput == "wood" || materialInput == "w")
        {
            material = Material::Wood;
            displayStructure = "Wood";
            break;
        }
        else if (materialInput == "Stone" || materialInput == "stone" || materialInput == "s")
        {
            material = Material::Stone;
            displayStructure = "Stone";
            break;
        }
        else if (materialInput == "Metal" || materialInput == "metal" || materialInput == "m")
        {
            material = Material::Metal;
            displayStructure = "Metal";
            break;
        }
        else if (materialInput == "Tek" || materialInput == "tek" || materialInput == "t")
        {
            material = Material::Tek;
            displayStructure = "Tek";
            break;
        }
        else
        {
            cout << ANSI_RED << "Invalid material input. Please choose from 'wood/w', 'stone/s', 'metal/m' or 'tek/t'" << ANSI_RESET << endl;
        }
    }
    
    double damage = calculateDamage(type, material);
    if (damage == 0.0)
    {
        cout << "---------------------------------------------------------------" << endl << endl;
        cout << "[" << ANSI_BLUE << displayWeapon << ANSI_RESET << "|" << ANSI_PURPLE << displayStructure << ANSI_RESET << "] This structure is indestructible with this weapon";
        exit(0);
    }

    string inputBuffer;
    int HP = 0;
    while (true)
    {
        cout << "[" << ANSI_BLUE << displayWeapon << ANSI_RESET << "|" << ANSI_PURPLE << displayStructure << ANSI_RESET << "] Enter HP of structure > ";
        cin >> inputBuffer;

        if (isValidIntInput(inputBuffer))
        {
            HP = stoi(inputBuffer);
            if (HP >= 1 && HP <= 100000)
            {
                break;
            }
        }

        cout << ANSI_RED << "Invalid HP input. Please enter a valid integer between 1 and 100000" << ANSI_RESET << endl;

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    string caveDamageInput;
    string displayCave;
    while (true)
    {
        cout << "[" << ANSI_BLUE << displayWeapon << ANSI_RESET << "|" << ANSI_PURPLE << displayStructure << ANSI_RESET << "|" << ANSI_CYAN << HP << " HP" << ANSI_RESET << "] Cave Damage? [" << ANSI_YELLOW << "y" << ANSI_RESET << "es/" << ANSI_YELLOW << "n" << ANSI_RESET << "o] > ";
        cin >> caveDamageInput;

        if (caveDamageInput == "yes" || caveDamageInput == "y")
        {
            displayCave = "Inside";
            break;
        }
        else if (caveDamageInput == "no" || caveDamageInput == "n")
        {
            displayCave = "No";
            break;
        }
        else
        {
            cout << ANSI_RED << "Invalid input. Please enter 'yes/y' or 'no/n'." << ANSI_RESET << endl;
        }
    }

    if (caveDamageInput == "yes" || caveDamageInput == "y")
    {
        damage *= 6;
    }

    cout << "---------------------------------------------------------------" << endl << endl;

    if (damage == 0.0)
    {
        cout << "[" << ANSI_BLUE << displayWeapon << ANSI_RESET << "|" << ANSI_PURPLE << displayStructure << ANSI_RESET << "|" << ANSI_CYAN << HP << " HP" << ANSI_RESET << "|" << ANSI_GREEN << displayCave << " Cave" << ANSI_RESET << "] This structure is indestructible with this weapon";
    }
    else
    {
        int amount = static_cast<int>(HP / damage + 0.99);
        cout << "[" << ANSI_BLUE << displayWeapon << ANSI_RESET << "|" << ANSI_PURPLE << displayStructure << ANSI_RESET << "|" << ANSI_CYAN << HP << " HP" << ANSI_RESET << "|" << ANSI_GREEN << displayCave << " Cave" << ANSI_RESET << "] Amount needed to destroy: " << amount;
        cout << endl;
        cout << endl;
        calculateCost(type, damage);
    }

    return 0;
}