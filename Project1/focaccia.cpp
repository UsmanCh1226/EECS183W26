/**
 * focaccia.cpp
 *
 * Name: <#Your Name#>
 * Uniqname: <#Your Uniqname#>
 *
 * EECS 183: Project 1
 * Winter 2026
 *
 * This program calculates the ingredients and cost needed to make
 * focaccia bread based on the number of people being served.
 */

#include <iostream>
#include <cmath>
#include <string>
using namespace std;

string pluralize(string singular, string plural, int number);

int main() {
    int people;
    cout << "How many people do you need to serve? ";
    cin >> people;
    cout << endl << endl;

    // --- Constants (No Magic Numbers) ---
    const double SERVINGS_PER_LOAF = 4.0;
    
    const double CUPS_FLOUR_PER_LOAF = 5.0;
    const double CUPS_FLOUR_PER_BAG = 20.0;
    const double PRICE_FLOUR = 2.69;
    
    const double TSP_YEAST_PER_LOAF = 1.75;
    const double TSP_YEAST_PER_PACKAGE = 2.25;
    const double PRICE_YEAST = 0.40;
    
    const double TSP_SALT_PER_LOAF = 1.875;
    const double TSP_SALT_PER_CANISTER = 6.0;
    const double PRICE_SALT = 0.49;
    
    const double TBSP_OIL_PER_LOAF = 2.0;
    const double ML_OIL_PER_BOTTLE = 500.0;
    const double ML_PER_TBSP = 14.8;
    const double PRICE_OIL = 6.39;
    
    // --- Calculations ---
    int loaves = ceil(people / SERVINGS_PER_LOAF);
    
    int flourBags = ceil((loaves * CUPS_FLOUR_PER_LOAF) / CUPS_FLOUR_PER_BAG);
    int yeastPackages = ceil((loaves * TSP_YEAST_PER_LOAF) / TSP_YEAST_PER_PACKAGE);
    int saltCanisters = ceil((loaves * TSP_SALT_PER_LOAF) / TSP_SALT_PER_CANISTER);
    
    double tbspPerBottle = ML_OIL_PER_BOTTLE / ML_PER_TBSP;
    int oilBottles = ceil((loaves * TBSP_OIL_PER_LOAF) / tbspPerBottle);
    
    double totalCost = (flourBags * PRICE_FLOUR) + (yeastPackages * PRICE_YEAST) +
                       (saltCanisters * PRICE_SALT) + (oilBottles * PRICE_OIL);
    
    // --- Final Output ---
    cout << "You need to make: " << loaves << " " 
         << pluralize("loaf", "loaves", loaves) << " of focaccia" << endl << endl;
    
    cout << "Shopping List for Focaccia Bread" << endl;
    cout << "--------------------------------" << endl;
    
    cout << flourBags << " " << pluralize("bag", "bags", flourBags) 
         << " of flour" << endl;
    cout << yeastPackages << " " << pluralize("package", "packages", yeastPackages) 
         << " of yeast" << endl;
    cout << saltCanisters << " " << pluralize("canister", "canisters", saltCanisters) 
         << " of salt" << endl;
    cout << oilBottles << " " << pluralize("bottle", "bottles", oilBottles) 
         << " of olive oil" << endl << endl;
    
    cout << "Total expected cost of ingredients: $" << totalCost << endl << endl;
    cout << "Have a great party!" << endl;

    return 0;
}

// DO NOT CHANGE THIS FUNCTION
string pluralize(string singular, string plural, int number) {
    if (number == 1) {
        return singular;
    }
    return plural;
}