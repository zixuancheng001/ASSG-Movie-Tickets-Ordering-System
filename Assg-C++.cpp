#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include<ctime>
#include<limits>
#include<map>
#include<algorithm>
#define vipcard "1119033003280612"
using namespace std;


string getCurrentDateTime() {
    time_t now = time(0);
    tm localTime;
    localtime_s(&localTime, &now);
    char buffer[20];
    strftime(buffer, sizeof(buffer), "%d/%m/%Y %H:%M", &localTime);
    return string(buffer);
}

string dateTime = getCurrentDateTime();

//----------------Function to remove spaces from card number input----------------------
string removeSpaces(const string& input) {
    string result;
    for (char c : input) {
        if (c != ' ') result += c;
    }
    return result;
}

struct FoodOrder {
    int id = 0;
    string name;
    double price = 0.0;
    int qty = 0;
};

FoodOrder menuFood[] = {
{1, "Popcorn", 8.5},
{2, "Soft Drinks", 4.0},
{3, "Hotdogs", 6.5},
{4, "French Fries", 5.5},
{5, "Chicken Nuggets", 7.0}
};

struct MovieReceipt {
    string movieName;
    string timeSelected;
    int pax;
    double price;
    vector<string> chooseSeats;
    vector<FoodOrder> orderFood;
    bool isVIP = false;
    double foodCost = 0.0;
};
//-----------------------------Global Variables-----------------------------

int menuSizeFood = sizeof(menuFood) / sizeof(menuFood[0]);
double totalSubtotal = 0.0;
double totalDiscount = 0.0;
double totalServiceCharge = 0.0;
double totalTax = 0.0;
double grandTotal = 0.0;
int totalPax = 0;
int InvoiceCounter = 0;
double discountRate = 0;

int totalPopcornSold = 0;
double totalAmountForPopcorn = 0;
int totalDrinkSold = 0;
double totalAmountForDrinks = 0;
int totalFriesSold = 0;
double totalAmountForFries = 0;
int totalHotdogSold = 0;
double totalAmountForHotdog = 0;
int totalNuggetsSold = 0;
double totalAmountForNuggets = 0;

int totalTicketsSoldForAvatar = 0;
double totalAmountForAvatar = 0;
int totalTicketsSoldForPokemon = 0;
double totalAmountForPokemon = 0;
int totalTicketsSoldForThreeKingdoms = 0;
double totalAmountForThreeKingdoms = 0;
int totalTicketsSoldForAvenger = 0;
double totalAmountForAvenger = 0;

map<string, map<string, string>> movieSeats;
// -------------------------------------Logo module ---------------------------------
void LogoShow() {
    for (int r = 0; r <= 116; r++) cout << "-";
    cout << endl;
    cout << "\t\t\t          CCCCC   IIIII  N   N  EEEEE   M     M   AAAAA  " << endl;
    cout << "\t\t\t         C     C    I    NN  N  E       MM   MM  A     A " << endl;
    cout << "\t\t\t         C          I    N N N  EEEE    M M M M  AAAAAAA " << endl;
    cout << "\t\t\t         C     C    I    N  NN  E       M  M  M  A     A " << endl;
    cout << "\t\t\t          CCCCC   IIIII  N   N  EEEEE   M     M  A     A " << endl;
    for (int r = 0; r <= 116; r++) cout << "-";
    cout << endl;
    cout << "\t\t\t        ____ _                   __        __         _     _       \n";
    cout << "\t\t\t       / ___(_)_ __   ___        \\ \\      / /__  _ __| | __| |  \n";
    cout << "\t\t\t      | |   | | '_ \\ / _ \\        \\ \\ /\\ / / _ \\| '_ | '/ _` | \n";
    cout << "\t\t\t      | |___| | | | |  __/         \\ V  V / (_) | |  | | (_| | \n";
    cout << "\t\t\t       \\____|_|_| |_|\\___|          \\_/\\_/ \\___/|_|  |_|\\__,_| \n";

    cout << endl;
    for (int r = 0; r <= 116; r++) cout << "=";
    cout << endl;
    cout << "\t\t\t                 <<  Welcome to Cine World >>                 \n";
    for (int r = 0; r <= 116; r++) cout << "=";
    cout << endl;
    cout << endl;
    cout << "\t\t\t                  Press  [ENTER]  to Continue...";
    cin.get();   // Wait for user to press Enter
    system("cls"); // Clear screen
}


// --------------------------------- Movie table module ---------------------------------
void movieTable() {

    cout << endl;
    for (int r = 0; r <= 42; r++) cout << "-";
    cout << "Explore Movies";
    for (int r = 0; r <= 43; r++) cout << "-";
    cout << endl;
    for (int r = 0; r <= 100; r++) cout << "-";
    cout << endl;
    // Set column widths
    int widthNo[5] = { 3, 23, 21, 40, 1 };

    // Header
    cout << "|" << setw(widthNo[0]) << left << "No."
        << "|" << setw(widthNo[1]) << left << "  Movie Title"
        << "|" << setw(widthNo[2]) << left << "  Run Time"
        << "|" << setw(widthNo[3]) << left << "  Show Time"
        << "|" << setw(8) << left << "  Price"
        << "|" << endl;

    // Divider
    for (int r = 0; r <= 100; r++) cout << "-";
    cout << endl;

    // Data Rows
    cout << "|" << setw(widthNo[0]) << left << " 1"
        << "|" << setw(widthNo[1]) << left << "  Avatar"
        << "|" << setw(widthNo[2]) << left << "  2 hours 30 minutes "
        << "|" << setw(widthNo[3]) << left << "  12:00pm | 14:30pm | 17:00pm | 19:30pm "
        << "|" << "  RM" << setw(4) << left << "32"
        << "|" << endl;

    for (int r = 0; r <= 100; r++) cout << "-";
    cout << endl;

    cout << "|" << setw(widthNo[0]) << left << " 2"
        << "|" << setw(widthNo[1]) << left << "  Pokémon The Movie    "
        << "|" << setw(widthNo[2]) << left << "  1 hours 30 minutes "
        << "|" << setw(widthNo[3]) << left << "  11:00am |13:00pm | 17:30pm | 20:30pm "
        << "|" << "  RM" << setw(4) << left << "26"
        << "|" << endl;

    for (int r = 0; r <= 100; r++) cout << "-";
    cout << endl;

    cout << "|" << setw(widthNo[0]) << left << " 3"
        << "|" << setw(widthNo[1]) << left << "  Three Kingdoms"
        << "|" << setw(widthNo[2]) << left << "  2 hours 15 minutes "
        << "|" << setw(widthNo[3]) << left << "  13:20pm | 16:20pm | 19:20pm | 22:20pm "
        << "|" << "  RM" << setw(4) << left << "38"
        << "|" << endl;

    for (int r = 0; r <= 100; r++) cout << "-";
    cout << endl;

    cout << "|" << setw(widthNo[0]) << left << " 4"
        << "|" << setw(widthNo[1]) << left << "  Avenger"
        << "|" << setw(widthNo[2]) << left << "  1 hours 45 minutes "
        << "|" << setw(widthNo[3]) << left << "  11:45am | 15:45pm | 18:45pm | 22:45pm "
        << "|" << "  RM" << setw(4) << left << "42"
        << "|" << endl;

    for (int r = 0; r <= 100; r++) cout << "-";
    cout << endl;

    cout << endl;
    cout << endl;
}

void releaseSeats(const vector<MovieReceipt>& receipts) {
    for (const auto& r : receipts) {
        string movieKey = r.movieName + " | " + r.timeSelected;
        if (movieSeats.find(movieKey) != movieSeats.end()) {
            for (const auto& seat : r.chooseSeats) {
                movieSeats[movieKey][seat] = seat;
            }
        }
    }
}

bool chooseSeats(MovieReceipt& r, int numberToChoose) {
    vector<MovieReceipt> receipts;
    string movieKey = r.movieName + " | " + r.timeSelected;
    // Check if this movie already has a seating chart in movieSeats.
   // If not, initialize seats A1–F14 as available (seat label itself).
    if (movieSeats.find(movieKey) == movieSeats.end()) {
        for (char row = 'A'; row <= 'F'; row++) {
            for (int i = 1; i <= 14; i++) {
                string seat = string(1, row) + to_string(i);
                movieSeats[movieKey][seat] = seat;
            }
        }
    }

    // a reference to this movie's seating chart
    auto& seats = movieSeats[movieKey];
    string choice;
    int spacing[14] = { 15, 3, 8, 3, 3, 3, 3, 3, 3, 4, 4, 4, 9, 4 };  //array for setw

    // Print the seating chart
    cout << "\nMovie Seat for " << r.timeSelected << endl;
    cout << right << setw(12) << endl;
    for (int r = 0; r <= 59; r++) cout << "-";
    cout << endl;
    cout << setw(42) << "Screen" << endl << endl;
    for (char row = 'A'; row <= 'F'; row++) {
        for (int i = 1; i <= 14; i++) {
            cout << setw(spacing[i - 1]) << seats[string(1, row) + to_string(i)];
        }
        cout << endl << endl;
    }
    cout << setw(12);
    for (int r = 0; r <= 59; r++) cout << "-";
    cout << endl << endl;

    // how many tickets the customer bought
    int remaining = numberToChoose;
    cout << "You have bought " << numberToChoose << " tickets for " << r.movieName << " (" << r.timeSelected << ")" << endl;
    for (int r = 0; r <= 45; r++) cout << "-";
    cout << endl;
    while (remaining > 0) {
        cout << "Please choose your seat(Q to quit): ";
        cin >> choice;
        if (choice.empty()) {
            cout << "Invalid input, please re-enter!" << endl;
            continue;
        }
        choice[0] = toupper(choice[0]); // letter to uppercase

        if (choice == "Q") {
            cout << "Quit to explore movie" << endl;

            if (r.chooseSeats.empty() || r.chooseSeats.size() < r.pax) {
                r.pax -= remaining;
                if (r.pax == 0) return false;
            }
            return true;
        }

        // Check if the chosen seat exists
        if (seats.find(choice) != seats.end()) {
            if (seats[choice] == "XX") {
                cout << "This seat has already been chosen, please choose another seat!" << endl << endl;
            }
            else {
                seats[choice] = "XX";                          // Marks seat as booked
                cout << "You have chosen " << choice << endl;
                r.chooseSeats.push_back(choice);             // Save chosen seat into the receipt
                remaining--;                                // one less seat to choose based on ticket
                cout << "You have " << remaining << " seat to choose" << endl << endl;
            }
        }
        else {
            cout << "Invalid choice, please re-enter!" << endl;
        }
    }

    // Print seat after booking
    cout << setw(12) << endl;
    for (int r = 0; r <= 59; r++) cout << "-";
    cout << endl;
    cout << setw(42) << "Screen" << endl << endl;
    for (char row = 'A'; row <= 'F'; row++) {
        for (int i = 1; i <= 14; i++) {
            cout << setw(spacing[i - 1]) << seats[string(1, row) + to_string(i)];
        }
        cout << endl << endl;
    }
    cout << setw(12);
    for (int r = 0; r <= 59; r++) cout << "-";
    cout << endl << endl;

    return true;
}

// --------------------------------- Print receipt module ---------------------------------
void printReceipt(const string& movieName, const string& timeSelected, int pax, double pricePerTicket, const string& chooseSeats) {
    double total = pax * pricePerTicket;

    // Update global staff sales data
    if (movieName == "Avatar") {
        totalTicketsSoldForAvatar += pax;
        totalAmountForAvatar += total;
    }
    else if (movieName == "Pokémon The Movie") {
        totalTicketsSoldForPokemon += pax;
        totalAmountForPokemon += total;
    }
    else if (movieName == "Three Kingdoms") {
        totalTicketsSoldForThreeKingdoms += pax;
        totalAmountForThreeKingdoms += total;
    }
    else if (movieName == "Avenger") {
        totalTicketsSoldForAvenger += pax;
        totalAmountForAvenger += total;
    }

    cout << endl;
    for (int r = 0; r <= 40; r++) cout << "=";
    cout << endl;
    cout << "Movie Selected\t: " << movieName << endl;
    cout << "Movie Show Time\t: " << timeSelected << endl;
    cout << "Pax\t\t: " << pax << endl;
    cout << "Seat\t\t: " << chooseSeats << endl;
    cout << "Price per pax\t: RM" << pricePerTicket << endl;
    cout << "Total Price\t: RM" << total << endl;
    for (int r = 0; r <= 40; r++) cout << "=";
    cout << endl;


}

// ---------------------------------- Food ordering module ---------------------------------
double orderFood(MovieReceipt& receipt) {
    cout << endl;
    for (int r = 0; r <= 14; r++) cout << "-";
    cout << "Food Menu";
    for (int r = 0; r <= 13; r++) cout << "-";
    cout << endl;

    int colWidths[] = { 4, 20, 10 };
    int numCols = sizeof(colWidths) / sizeof(colWidths[0]);

    void (*printLine)(int[], int) = [](int widths[], int n) {
        cout << "+";
        for (int i = 0; i < n; i++) {
            cout << string(widths[i], '-') << "+";
        }
        cout << "\n";
        };

    printLine(colWidths, numCols);
    cout << "|" << setw(colWidths[0] - 1) << left << "Code"
        << "| " << setw(colWidths[1] - 1) << left << "Food/Drinks"
        << "| " << setw(colWidths[2] - 1) << left << "Price(RM)"
        << "|\n";
    printLine(colWidths, numCols);

    for (int i = 0; i < menuSizeFood; i++) {
        cout << "| " << setw(colWidths[0] - 1) << left << menuFood[i].id
            << "| " << setw(colWidths[1] - 1) << left << menuFood[i].name
            << "| " << setw(colWidths[2] - 1) << right
            << fixed << setprecision(2) << menuFood[i].price
            << "|\n";
    }
    printLine(colWidths, numCols);

    double foodTotal = 0.0;
    int choice, qty;
    while (true) {
        cout << "\nPlease choose your food (0 = Finish): ";
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Enter a number.\n";
            continue;
        }
        if (choice == 0) break; //end ordering when 0

        bool found = false;
        for (int i = 0; i < menuSizeFood; i++) {
            if (menuFood[i].id == choice) {
                found = true;
                cout << "Enter quantity: ";
                if (!(cin >> qty) || qty <= 0) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid quantity. Try again.\n";
                    break;
                }

                double cost = menuFood[i].price * qty;
                foodTotal += cost;

                bool foodMerged = false;
                for (auto& existing : receipt.orderFood) {
                    if (existing.name == menuFood[i].name) { //Combine the food that are same
                        existing.qty += qty;
                        foodMerged = true;
                        break;
                    }
                }
                if (!foodMerged) {
                    FoodOrder item;
                    item.name = menuFood[i].name;
                    item.price = menuFood[i].price;
                    item.qty = qty;
                    receipt.orderFood.push_back(item);
                }

                cout << "Added: " << menuFood[i].name << " x" << to_string(qty)
                    << " = RM " << fixed << setprecision(2) << cost << endl;
                switch (choice) { //for staff sales data (update data)
                case 1:
                    totalPopcornSold += qty;
                    totalAmountForPopcorn += qty * menuFood[i].price;
                    break;
                case 2:
                    totalDrinkSold += qty;
                    totalAmountForDrinks += qty * menuFood[i].price;
                    break;
                case 3:
                    totalHotdogSold += qty;
                    totalAmountForHotdog += qty * menuFood[i].price;
                    break;
                case 4:
                    totalFriesSold += qty;
                    totalAmountForFries += qty * menuFood[i].price;
                    break;
                case 5:
                    totalNuggetsSold += qty;
                    totalAmountForNuggets += qty * menuFood[i].price;
                    break;
                }
                totalPax += qty;
                break;
            }
        }
        if (!found) {
            cout << "Invalid code, please try again!\n";
        }
    }

    receipt.foodCost = foodTotal;

    cout << "\nFood total: RM " << fixed << setprecision(2) << foodTotal << endl;
    return foodTotal;
}

// ---------------------------------- Explore movie module ---------------------------------
void ExploreMovies(vector<MovieReceipt>& receipts) {
    cout << endl;
    bool cancelled = false;
    int choice = 1;
    int again = 1;
    do {
        cancelled = false;
        movieTable();
        cout << endl;
        cout << "Movies select(1-4)" << endl;
        cout << "Please enter your choice (5 to exit): ";

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input, please enter a number!" << endl;
            cout << endl;
            continue;
        }

        string seatsStr;
        int pax;
        int timeChoice;
        string timeSelected;
        string movieName;
        double price = 0.0;

        switch (choice) {
        case 1:
            movieName = "Avatar";
            price = 32;
            cout << "Enter number of tickets for " << movieName << ": ";
            if (!(cin >> pax)) {
                // Input failed (e.g. user typed 'a'
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input, please enter a number!" << endl;
                cout << endl;
                continue;
            }

            do {
                cout << "Show time:" << endl;
                for (int r = 0; r <= 58; r++) cout << "-";
                cout << endl;
                cout << "| 1) 12:00pm | 2) 14 : 30pm | 3) 17 : 00pm | 4) 19 : 30pm | " << endl;
                for (int r = 0; r <= 58; r++) cout << "-";
                cout << endl;
                cout << "Choice (1-4):";

                if (!(cin >> timeChoice)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input, please enter a number!" << endl;
                    cout << endl;
                    continue;
                }

                if (timeChoice == 1) timeSelected = "12:00pm";
                else if (timeChoice == 2) timeSelected = "14:30pm";
                else if (timeChoice == 3) timeSelected = "17:00pm";
                else if (timeChoice == 4) timeSelected = "19:30pm";

            } while (timeChoice < 1 || timeChoice > 4);
            break;

        case 2:
            movieName = "Pokémon The Movie";
            price = 26;
            cout << "Enter number of tickets for " << movieName << ": ";
            if (!(cin >> pax)) {
                // Input failed (e.g. user typed 'a'
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input, please enter a number!" << endl;
                cout << endl;
                continue;
            }
            do {
                cout << "Show time:" << endl;
                for (int r = 0; r <= 58; r++) cout << "-";
                cout << endl;
                cout << "|  1. 11:00am  |  2. 13:30pm  |  3. 17:30pm  |  4. 20:30pm | " << endl;
                for (int r = 0; r <= 58; r++) cout << "-";
                cout << endl;
                cout << "Choice:";
                if (!(cin >> timeChoice)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input, please enter a number!" << endl;
                    cout << endl;
                    continue;
                }
                if (timeChoice == 1) timeSelected = "11:00am";
                else if (timeChoice == 2) timeSelected = "13:30pm";
                else if (timeChoice == 3) timeSelected = "17:30pm";
                else if (timeChoice == 4) timeSelected = "20:30pm";

            } while (timeChoice < 1 || timeChoice > 4);
            break;

        case 3:
            movieName = "Three Kingdoms";
            price = 38;
            cout << "Enter number of tickets for " << movieName << ": ";
            if (!(cin >> pax)) {
                // Input failed (e.g. user typed 'a'
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input, please enter a number!" << endl;
                cout << endl;
                continue;
            }
            do {
                cout << "Show time:" << endl;
                for (int r = 0; r <= 58; r++) cout << "-";
                cout << endl;
                cout << "|  1. 13:20pm  |  2. 16:20pm  |  3. 19:20pm  |  4. 22:20pm | " << endl;
                for (int r = 0; r <= 58; r++) cout << "-";
                cout << endl;
                cout << "Choice:";
                if (!(cin >> timeChoice)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input, please enter a number!" << endl;
                    cout << endl;
                    continue;
                }
                if (timeChoice == 1) timeSelected = "13:20pm";
                else if (timeChoice == 2) timeSelected = "16:20pm";
                else if (timeChoice == 3) timeSelected = "19:20pm";
                else if (timeChoice == 4) timeSelected = "22:20pm";


            } while (timeChoice < 1 || timeChoice > 4);
            break;

        case 4:
            movieName = "Avenger";
            price = 42;
            cout << "Enter number of tickets for " << movieName << ": ";
            if (!(cin >> pax)) {
                // Input failed (e.g. user typed 'a'
                cin.clear(); // clear error flags
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard bad input
                cout << "Invalid input, please enter a number!" << endl;
                cout << endl;
                continue; // restart loop
            }
            do {
                cout << "Show time:" << endl;
                for (int r = 0; r <= 58; r++) cout << "-";
                cout << endl;
                cout << "|  1. 11:45am  |  2. 15:45pm  |  3. 18:45pm  |  4. 22:45pm | " << endl;
                for (int r = 0; r <= 58; r++) cout << "-";
                cout << endl;
                cout << "Choice:";
                if (!(cin >> timeChoice)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input, please enter a number!" << endl;
                    cout << endl;
                    continue;
                }
                if (timeChoice == 1) timeSelected = "11:45am";
                else if (timeChoice == 2) timeSelected = "15:45pm";
                else if (timeChoice == 3) timeSelected = "18:45pm";
                else if (timeChoice == 4) timeSelected = "22:45pm";


            } while (timeChoice < 1 || timeChoice > 4);
            break;

        case 5:
            system("cls");
            cout << "Returning to Customer Portal...\n";
            return;

        default:
            cout << "Invalid choice" << endl;
            continue;
        }

        bool merged = false;
        for (auto& r : receipts) {
            if (r.movieName == movieName && r.timeSelected == timeSelected) { //Combine the ticket that are same movie and same time
                int newlyBought = pax;
                r.pax += newlyBought;
                totalPax += newlyBought;

                bool result = chooseSeats(r, newlyBought);
                if (!result && r.pax == 0) {
                    receipts.pop_back();
                    cancelled = true;
                }
                merged = true;
                break;
            }
        }
        if (!merged) {
            receipts.push_back({ movieName, timeSelected, pax, price });
            totalPax += pax;
            chooseSeats(receipts.back(), pax);
            if (receipts.back().chooseSeats.empty()) {
                receipts.pop_back();
                cancelled = true;
            }
        }

        if (cancelled) continue;

        seatsStr.clear();
        for (const auto& seat : receipts.back().chooseSeats) {
            seatsStr += seat + " ";
        }
        printReceipt(
            receipts.back().movieName,
            receipts.back().timeSelected,
            receipts.back().pax,
            receipts.back().price,
            seatsStr
        );

        do {
            cout << endl;
            for (int r = 0; r <= 32; r++) cout << "-";
            cout << "\nDo you want to buy another movie?\n1. Yes\n2. No\n";
            for (int r = 0; r <= 32; r++) cout << "-";
            cout << endl;
            cout << "Choice :";
            if (!(cin >> again)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input, enter 1 or 2!\n";
                continue;
            }
            if (again != 1 && again != 2) {
                cout << "Invalid input, enter 1 or 2!\n";
            }
        } while (again != 1 && again != 2);
    } while (again == 1);
}

// -------------------------------Membership module to get discount---------------------------------
void memberModule() {

    // --- Membership check ---
    int membership = 0;

    do {
        cout << endl;
        for (int r = 0; r <= 29; r++) cout << "-";
        cout << endl;
        cout << "Do you have membership ? " << endl;
        for (int r = 0; r <= 29; r++) cout << "-";
        cout << endl;
        cout << "1. Yes" << endl;
        cout << "2. No" << endl;
        for (int r = 0; r <= 29; r++) cout << "-";
        cout << endl;
        cout << "Please enter your choice :  ";
        if (!(cin >> membership)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input, please enter a number!" << endl;
            cout << endl;
            continue;
        }// restart loop

        string memberID;
        int attempts = 0;
        if (membership == 1) {
            while (attempts < 3) {
                cout << "Please insert your Member ID: ";
                cin >> memberID;
                if (memberID != "M2025") {
                    cout << "invalid Member ID... " << endl;
                    attempts++;
                    if (attempts == 3) {
                        cout << "Too many attempts, access denied" << endl;
                        cout << endl;
                        continue;
                    }
                }
                else {
                    cout << "Access granted, welcome Member " << memberID << endl;
                    cout << endl;
                    for (int r = 0; r <= 39; r++) cout << "=";
                    cout << endl;
                    cout << "You are entitled to 10% discount!" << endl;
                    for (int r = 0; r <= 39; r++) cout << "=";
                    cout << endl;
                    discountRate = 0.1;
                    break;
                }
            }
        }
        else if (membership == 2) {
            cout << endl;
            for (int r = 0; r <= 39; r++) cout << "=";
            cout << endl;
            cout << "No membership, no discount applied" << endl;
            for (int r = 0; r <= 39; r++) cout << "=";
            cout << endl;
            discountRate = 0;
        }
        else {
            cout << "Invalid choice, please enter 1 or 2." << endl;
        }
    } while (membership != 1 && membership != 2);
}

// -------------------------------------Print invoice---------------------------------
void printInvoice(const vector<MovieReceipt>& receipts) {
    int invoiceNo = ++InvoiceCounter;
    totalSubtotal = 0.0;
    totalDiscount = 0.0;
    totalServiceCharge = 0.0;
    totalTax = 0.0;

    for (const auto& r : receipts) {
        totalSubtotal += (r.pax * r.price) + r.foodCost;
    }

    totalDiscount = totalSubtotal * discountRate;
    totalServiceCharge = totalSubtotal * 0.05;
    totalTax = totalSubtotal * 0.03;
    grandTotal = totalSubtotal + totalServiceCharge + totalTax - totalDiscount;

    // Print invoice
    cout << endl << "Invoice: " << endl;
    cout << setw(10) << " ";
    for (int i = 0; i < 60; i++) cout << "-";
    cout << " " << endl;
    cout << right << setw(44) << "Cine World" << endl;
    cout << setw(24);
    for (int i = 0; i <= 30; i++) cout << "=";
    cout << endl;
    cout << setw(24) << "Invoice No: ";
    cout << invoiceNo << right << setw(40) << getCurrentDateTime() << endl;

    // Print order list
    int movieOrderNo = 1;
    for (auto& r : receipts) {
        double subtotal = r.pax * r.price;
        cout << fixed << setprecision(2) << "            " << movieOrderNo++ << ". " << left << setw(17) << r.movieName
            << "(" << r.pax << " x RM " << r.price << left << setw(11) << ")"
            << "RM " << fixed << setprecision(2) << subtotal << endl;
        cout << right << setw(29) << "Movie Show Time: " << r.timeSelected << endl << endl;
        if (r.foodCost > 0) {
            cout << endl;
            cout << right << setw(22) << "Food order" << endl;
            int foodOrderNo = 1;
            for (const auto& f : r.orderFood) {
                double foodCost = f.qty * f.price;
                cout << fixed << setprecision(2) << "            " << foodOrderNo++ << "." << left << setw(19) << f.name
                    << "(" << f.qty << " x RM " << f.price << left << setw(11) << ")"
                    << "RM " << foodCost << endl;
            }
        }
    }

    cout << setw(55) << " ";
    for (int r = 0; r <= 11; r++) cout << "-";
    cout << endl;
    cout << right << setw(20) << "Subtotal" << right << setw(39) << "RM " << fixed << setprecision(2) << totalSubtotal << endl;
    cout << setw(30) << "Service Charge(5%)" << right << setw(29) << "RM " << fixed << setprecision(2) << totalServiceCharge << endl;
    cout << setw(15) << "Tax" << right << setw(44) << "RM " << fixed << setprecision(2) << totalTax << endl;
    cout << setw(20) << "Discount" << right << setw(39) << "- RM " << fixed << setprecision(2) << totalDiscount << endl;
    cout << setw(55);
    for (int r = 0; r <= 11; r++) cout << "-";
    cout << endl;
    cout << setw(25) << "Total items: " << totalPax << endl;
    cout << setw(26) << "Total payable:" << right << setw(33) << "RM " << fixed << setprecision(2) << grandTotal << endl;
    cout << setw(10);
    for (int r = 0; r <= 60; r++) cout << "-";
    cout << endl << endl;
}

//  --------------------------let user choose payment method and print receipt---------------------------------
bool printPayment(const vector<MovieReceipt>& receipts) {
    int invoiceNo = ++InvoiceCounter;

    // Payment
    char method = 0;
    string payment;
    bool valid = false;
    string cardNumber;
    double paymentAmount = 0.0;
    double change = 0.0;
    bool isVIP = false;
    srand(time(NULL));

    while (!valid) {
        for (int i = 0; i < 27; i++) cout << "-";
        cout << endl;
        cout << "Select payment method\n";
        for (int i = 0; i < 27; i++) cout << "-";
        cout << endl;
        cout << "  W = e-Wallet\n" << "  R = Credit Card\n" << "  D = Debit Card\n" << "  C = Cash\n" << "  Q = Quit\n";
        for (int i = 0; i < 27; i++) cout << "-";
        cout << endl;
        cout << "Enter your payment method:";
        cin >> method;
        cin.ignore();

        switch (toupper(method)) {
        case 'W':
            payment = "e-Wallet";
            valid = true;
            break;

        case 'R':
        case 'D': {
            payment = (toupper(method) == 'R') ? "Credit Card" : "Debit Card";
            for (int i = 0; i < 52; i++) cout << "-";
            cout << endl;
            cout << "Enter your 16-digit card number: ";
            getline(cin, cardNumber);
            for (int i = 0; i < 52; i++) cout << "-";
            cout << endl;
            string cleanCard = removeSpaces(cardNumber);

            if (cleanCard.length() == 16 && all_of(cleanCard.begin(), cleanCard.end(), ::isdigit)) {
                if (cleanCard == vipcard) {
                    cout << "VIP card detected! Your payment is waived!" << endl;
                    payment = "VIP Card";
                    isVIP = true;
                    totalDiscount = totalSubtotal + totalServiceCharge + totalTax;
                    grandTotal = 0.0; // Vip card get payment waived
                }
                else {
                    cout << "Card accepted. Proceed with payment." << endl;
                    paymentAmount = grandTotal;
                    change = 0.0;
                }
                valid = true;
            }
            else {
                cout << "Invalid card number! Must be 16 digits." << endl << endl;
            }
            break;
        }

        case 'C':
            payment = "Cash";
            valid = true;
            break;

        case 'Q':
            cout << "Quit to explore movie..." << endl << endl;
            return false;

        default:
            cout << "Invalid payment method! Please enter again!" << endl << endl;
        }
    }

    // If not vip, then ask for payment amount
    if (!isVIP) {
        if (payment == "Cash" || payment == "e-Wallet") {
            do {
                cout << "Payment amount: RM ";
                if (!(cin >> paymentAmount)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Please insert valid number !" << endl;
                    continue;
                }
                else if (paymentAmount < grandTotal) {
                    cout << "Your payment is not enough! You still need RM "
                        << fixed << setprecision(2) << (grandTotal - paymentAmount) << endl;
                }
            } while (paymentAmount < grandTotal);

            change = paymentAmount - grandTotal;
            if (fabs(change) < 0.005) {
                change = 0.0;
            }
        }
        else {
            paymentAmount = grandTotal;
            change = 0.0;
            cout << payment << " payment successful. Amount deducted: RM "
                << fixed << setprecision(2) << paymentAmount << endl;
        }
    }
    else {
        paymentAmount = 0.0;
        change = 0.0;
    }

    // Print receipt
    cout << "\nReceipt:" << endl;
    cout << setw(10) << " ";
    for (int r = 0; r <= 60; r++) cout << "-";
    cout << endl;
    cout << right << setw(44) << "Cine World" << endl;
    cout << setw(24);
    for (int r = 0; r <= 30; r++) cout << "=";
    cout << endl;
    cout << setw(24) << "Invoice No\t: " << invoiceNo << endl;
    cout << setw(24) << "Ticket No\t: " << (rand() % 8999998 + 100000) << endl;
    cout << setw(29) << "Trans Date Time: " << getCurrentDateTime() << endl << endl;

    int movieOrderNo = 1;
    for (auto& r : receipts) {
        double ticketSubtotal = r.pax * r.price;
        double subtotal = ticketSubtotal + r.foodCost;

        cout << fixed << setprecision(2) << setw(13) << movieOrderNo++ << ". " << left << setw(17) << r.movieName
            << "(" << r.pax << " x RM " << r.price << left << setw(11) << ")"
            << "RM " << fixed << setprecision(2) << ticketSubtotal << endl;
        cout << right << setw(29) << "Movie Show Time: " << r.timeSelected << endl;
        cout << setw(16) << "Seat" << setw(13) << ": ";
        for (const auto& seat : r.chooseSeats) {
            cout << seat << " ";
        }
        cout << endl << endl;
        // If order food than print
        if (r.foodCost > 0) {
            cout << endl;
            cout << right << setw(22) << "Food order" << endl;
            int foodOrderNo = 1;
            for (const auto& f : r.orderFood) {
                double foodCost = f.qty * f.price;
                cout << fixed << setprecision(2) << "            " << foodOrderNo++ << "." << left << setw(19) << f.name
                    << "(" << f.qty << " x RM " << f.price << left << setw(11) << ")"
                    << "RM " << foodCost << endl;
            }
        }
    }
    cout << setw(55) << " ";
    for (int r = 0; r <= 11; r++) cout << "-";
    cout << endl;
    cout << right << setw(20) << "Subtotal" << right << setw(39) << "RM " << fixed << setprecision(2) << totalSubtotal << endl;
    cout << setw(30) << "Service Charge(5%)" << right << setw(29) << "RM " << fixed << setprecision(2) << totalServiceCharge << endl;
    cout << setw(15) << "Tax" << right << setw(44) << "RM " << fixed << setprecision(2) << totalTax << endl;
    cout << setw(20) << "Discount" << right << setw(39) << "- RM " << fixed << setprecision(2) << totalDiscount << endl;
    cout << setw(55);
    for (int r = 0; r <= 11; r++) cout << "-";
    cout << endl;
    cout << setw(25) << "Total items: " << totalPax << endl;
    cout << setw(26) << "Total payable:" << right << setw(33) << "RM " << fixed << setprecision(2) << grandTotal << endl << endl;
    cout << setw(28) << "Payment method\t:" << payment << endl;
    cout << setw(30) << "Payment amount\t:RM" << paymentAmount << endl;
    cout << setw(23) << "Change\t\t:RM" << change << " " << endl;
    cout << setw(10);
    for (int r = 0; r <= 60; r++) cout << "-";
    cout << endl << endl;
}

// ---------------------------------Staff module to view sales report------------------------------
void staffModule() {

    string staffID;
    int attempts = 0;
    cout << "Staff module is locked for security practice" << endl << endl;

    while (attempts < 3) {
        cout << "Please enter staff id : ";
        cin >> staffID;

        if (staffID != "M001") {
            cout << "Invalid staff ID, access denied." << endl;
            attempts++;
            if (attempts == 3) {
                cout << "Too many attempts, access denied." << endl;
                cout << endl;
                return;
            }
        }
        else {
            cout << "Access granted, welcome staff " << staffID << endl;
            int choice = 1;
            while (choice != 2) {
                cout << endl;
                for (int r = 0; r <= 12; r++) {
                    if (r <= 12)
                        cout << "-";
                }
                cout << endl;
                cout << "Staff Portal" << endl;
                for (int r = 0; r <= 12; r++) cout << "-";
                cout << endl;
                cout << "1. View Sales Report" << endl;
                cout << "2. Exit" << endl;
                cout << endl;
                cout << "Please enter your choice : ";
                if (!(cin >> choice)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input, please enter a number!" << endl;
                    cout << endl;
                    continue;
                }

                int grandTickets = totalTicketsSoldForAvatar + totalTicketsSoldForPokemon +
                    totalTicketsSoldForThreeKingdoms + totalTicketsSoldForAvenger;
                double grandSales = totalAmountForAvatar + totalAmountForPokemon +
                    totalAmountForThreeKingdoms + totalAmountForAvenger;
                int grandFood = totalDrinkSold + totalNuggetsSold + totalPopcornSold +
                    totalHotdogSold + totalFriesSold;
                int grandFoodSales = totalAmountForPopcorn + totalAmountForDrinks + totalAmountForNuggets +
                    totalAmountForHotdog + totalAmountForFries;

                switch (choice) {
                case 1:
                    cout << "View Sales Report selected" << endl;
                    cout << endl;
                    for (int r = 0; r <= 80; r++) cout << "-";
                    cout << endl;
                    cout << "|" << right << setw(48) << "CINEMA SALES REPORT" << setw(32) << "|" << endl;
                    for (int r = 0; r <= 80; r++) cout << "-";
                    cout << endl;
                    cout << left << setw(40) << "| Movie Name"
                        << setw(20) << "Tickets Sold"
                        << setw(20) << "Total Sales (RM)" << "|\n";
                    cout << string(81, '-') << "\n";

                    cout << left << setw(40) << "| Avatar"
                        << setw(20) << totalTicketsSoldForAvatar
                        << setw(20) << totalAmountForAvatar << "|\n";

                    cout << left << setw(40) << "| Pokémon The Movie"
                        << setw(20) << totalTicketsSoldForPokemon
                        << setw(20) << totalAmountForPokemon << "|\n";

                    cout << left << setw(40) << "| Three Kingdoms"
                        << setw(20) << totalTicketsSoldForThreeKingdoms
                        << setw(20) << totalAmountForThreeKingdoms << "|\n";

                    cout << left << setw(40) << "| Avenger"
                        << setw(20) << totalTicketsSoldForAvenger
                        << setw(20) << totalAmountForAvenger << "|\n";

                    cout << string(81, '-') << "\n";

                    cout << left << setw(40) << "| TOTAL"
                        << setw(20) << grandTickets
                        << setw(20) << grandSales << "|\n";

                    for (int r = 0; r <= 80; r++) cout << "-";
                    cout << endl;

                    for (int r = 0; r <= 80; r++) cout << "-";
                    cout << endl;
                    cout << "|" << right << setw(48) << "FOOD SALES REPORT" << setw(32) << "|" << endl;
                    for (int r = 0; r <= 80; r++) cout << "-";
                    cout << endl;
                    cout << left << setw(40) << "| FOOD Name"
                        << setw(20) << "Tickets Sold"
                        << setw(20) << "Total Sales (RM)" << "|\n";
                    cout << string(81, '-') << "\n";

                    cout << left << setw(40) << "| Popcorn"
                        << setw(20) << totalPopcornSold
                        << setw(20) << totalAmountForPopcorn << "|\n";

                    cout << left << setw(40) << "| Soft Drinks"
                        << setw(20) << totalDrinkSold
                        << setw(20) << totalAmountForDrinks << "|\n";

                    cout << left << setw(40) << "| Hotdogs"
                        << setw(20) << totalHotdogSold
                        << setw(20) << totalAmountForHotdog << "|\n";

                    cout << left << setw(40) << "| French Fries"
                        << setw(20) << totalFriesSold
                        << setw(20) << totalAmountForFries << "|\n";

                    cout << left << setw(40) << "| Chicken Nuggets"
                        << setw(20) << totalNuggetsSold
                        << setw(20) << totalAmountForNuggets << "|\n";

                    cout << string(81, '-') << "\n";

                    cout << left << setw(40) << "| TOTAL"
                        << setw(20) << grandFood
                        << setw(20) << grandFoodSales << "|\n";

                    for (int r = 0; r <= 80; r++) cout << "-";
                    cout << endl;
                    break;
                case 2:
                    system("cls");
                    cout << "Exit staff module..." << endl;
                    cout << endl;
                    return;
                    break;
                default:
                    cout << "Invalid choice" << endl;
                    break;
                }
            }
        }
    }
}



// ---customer module to let customer teleport to explore movie, order food and make payment--------------------

void customerModule() {
    vector<MovieReceipt> receipts;
    int choice = 1;
    while (choice != 2) {
        for (int r = 0; r <= 15; r++) cout << "-";
        cout << endl;
        cout << "Customer Portal" << endl;
        for (int r = 0; r <= 15; r++)  cout << "-";
        cout << endl;
        cout << "1. Explore Movies" << endl;
        cout << "2. Exit" << endl;
        cout << endl;

        cout << "Please enter your choice : ";
        if (!(cin >> choice)) {
            // Input failed (e.g. user typed 'a'
            cin.clear(); // clear error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard bad input
            cout << "Invalid input, please enter a number!" << endl;
            cout << endl;
            continue; // restart loop
        }//expecting 1 or 2

        switch (choice) {
        case 1:
            //Explore Movies selected" << endl;
            ExploreMovies(receipts);
            if (!receipts.empty()) {
                int buyFood;
                do {
                    cout << endl;
                    for (int r = 0; r <= 32; r++) cout << "-";
                    cout << "\nDo you want to order food/drinks?\n";
                    cout << "1. Yes\n";
                    cout << "2. No\n";
                    for (int r = 0; r <= 32; r++) cout << "-";
                    cout << endl;
                    cout << "Choice: ";
                    if (!(cin >> buyFood)) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Invalid input, please enter a number!" << endl;
                        continue;
                    }
                    if (buyFood == 1) {
                        double foodTotal = orderFood(receipts.back());
                        receipts.back().foodCost = foodTotal;
                    }
                    else if (buyFood == 2) {
                        break;
                    }
                    else {
                        cout << "Invalid input, please enter 1 or 2!" << endl;
                        continue;
                    }
                } while (buyFood != 2);
                memberModule();
                printInvoice(receipts);
                if (!printPayment(receipts)) {
                    releaseSeats(receipts);
                    receipts.clear();
                    totalSubtotal = totalServiceCharge = totalTax = totalDiscount = grandTotal = 0.0;
                    totalPax = 0;
                    continue;
                }
                receipts.clear();
            }
            break;
        case 2:
            system("cls");
            cout << "Exit customer module..." << endl;
            cout << endl;
            return;
            break;

        default:
            cout << "Invalid choice" << endl;
            break;
        }
    }
}

// ----------------------------------------Main function-----------------------------------------
int main() {
    LogoShow();
    int choice = 1;

    while (choice != 3) {
        cout << "MAIN PORTAL" << endl;
        for (int r = 0; r <= 22; r++) cout << "-";
        cout << endl;
        cout << "1. Customer" << endl;
        cout << "2. Staff" << endl;
        cout << "3. Exit" << endl;
        cout << endl;

        //cout << "Please enter your choice : ";
        //cin >> choice;//expecting 1 or 2
        cout << "Please enter your choice : ";

        if (!(cin >> choice)) {
            // Input failed (e.g. user typed 'a'
            cin.clear(); // clear error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard bad input
            cout << "Invalid input, please enter a number!" << endl;
            cout << endl;
            continue; // restart loop
        }
        switch (choice) {
        case 1:
            system("cls");
            customerModule();
            break;
        case 2:
            system("cls");
            staffModule();
            break;
        case 3:
            cout << "Glad you enjoy our system, Bye!" << endl;
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
    }
}
