/* Chris Rumble 5/16/2025
   CS 14 - Baseball Project

   Description:
   This program is a baseball statistics calculator that reads player data from a file,
   calculates batting and on-base averages, and prints the results to an output file.

   Input:
   - roster.txt: Contains player names and IDs.
   - statistic.txt: Contains player statistics (hits, walks, outs).

   Output:
   - output.txt: Contains the calculated statistics, including batting and on-base averages,
     as well as the best and worst performers in each category.
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

const int NUM_PLAYERS = 20; // Set number of players on the team.

struct PlayerInfo
{
    int PlayerID;
    string LastName;
    string FirstName;
    int Hits;
    int Walks;
    int Outs;
    double Batting;
    double OnBase;

    // Initialize elements in struct to default values.
    PlayerInfo()
    {
        PlayerID = 0;
        LastName = "";
        FirstName = "";
        Hits = 0;
        Walks = 0;
        Outs = 0;
        Batting = 0.0;
        OnBase = 0.0;
    }
};

// Function prototypes.
int GetPlayer(PlayerInfo[]);
void PrintRoster(ofstream &, PlayerInfo[], int);
void SortPlayer(PlayerInfo[]);
void GetStatistics(PlayerInfo[], int, const string &, ofstream &);
void CalculateStats(PlayerInfo[]);
void PrintFinalStats(PlayerInfo[], int, ofstream &, int);

int main()
{
    PlayerInfo Player[NUM_PLAYERS];
    ofstream outFile("results002.txt");

    int seasonYear = GetPlayer(Player);

    PrintRoster(outFile, Player, seasonYear);
    SortPlayer(Player);
    GetStatistics(Player, seasonYear, "statistic002.txt", outFile);
    CalculateStats(Player);
    PrintFinalStats(Player, seasonYear, outFile, NUM_PLAYERS);

    outFile.close();
    return 0;
}

// Reads player names and assigns ID.
int GetPlayer(PlayerInfo Player[])
{
    ifstream inFile("roster002.txt");
    int year;
    inFile >> year;

    for (int i = 0; i < NUM_PLAYERS; i++) // Loop through player names.
    {
        inFile >> Player[i].LastName >> Player[i].FirstName;
        Player[i].PlayerID = i + 1;
    }

    inFile.close();
    return year;
}

// Print initial roster to output.
void PrintRoster(ofstream &out, PlayerInfo Player[], int year)
{
    cout << "Baseball Season " << year << endl;
    out << "Baseball Season " << year << endl;
    cout << "--------------------------------" << endl;
    out << "--------------------------------" << endl;

    for (int i = 0; i < NUM_PLAYERS; i++) // Loop through player names.
    {
        cout << Player[i].LastName << " " << Player[i].FirstName
             << "\tPlayer " << Player[i].PlayerID << endl;
        out << Player[i].LastName << " " << Player[i].FirstName
            << "\tPlayer " << Player[i].PlayerID << endl;
    }
}

// Sort players by LastName
void SortPlayer(PlayerInfo Player[])
{
    for (int i = 0; i < NUM_PLAYERS - 1; i++)
    {
        int minIdx = i;
        for (int j = i + 1; j < NUM_PLAYERS; j++)
        {
            if (Player[j].LastName < Player[minIdx].LastName)
            {
                minIdx = j;
            }
        }
        if (minIdx != i)
        {
            // Swap the players.
            PlayerInfo temp = Player[i];
            Player[i].PlayerID = Player[minIdx].PlayerID;
            Player[i].LastName = Player[minIdx].LastName;
            Player[i].FirstName = Player[minIdx].FirstName;
            Player[i].Hits = Player[minIdx].Hits;
            Player[i].Walks = Player[minIdx].Walks;
            Player[i].Outs = Player[minIdx].Outs;
            Player[i].Batting = Player[minIdx].Batting;
            Player[i].OnBase = Player[minIdx].OnBase;
            Player[minIdx].PlayerID = temp.PlayerID;
            Player[minIdx].LastName = temp.LastName;
            Player[minIdx].FirstName = temp.FirstName;
            Player[minIdx].Hits = temp.Hits;
            Player[minIdx].Walks = temp.Walks;
            Player[minIdx].Outs = temp.Outs;
            Player[minIdx].Batting = temp.Batting;
            Player[minIdx].OnBase = temp.OnBase;
        }
    }
}

// Read stats and update the corresponding players.
void GetStatistics(PlayerInfo Player[], int year, const string &statsFile, ofstream &out)
{
    ifstream inFile(statsFile);
    // Detect EOF by trying to read an empty line.
    // If it fails, the statistic.txt file is empty and the season was cancelled.
    int empty;
    inFile >> empty;
    if (inFile.fail())
    {
        cout << "\nThe " << year << " baseball season was cancelled." << endl;
        out << "\nThe " << year << " baseball season was cancelled." << endl;
        inFile.close();
        exit(0);
    }
    else
    {
        inFile.close(); // Close the file and reopen it to read the stats from the beginning.
    }

    int id, h, w, o;
    inFile.open(statsFile);
    while (inFile >> id >> h >> w >> o) // Read player stats.
    {
        for (int i = 0; i < NUM_PLAYERS; i++)
        {
            if (Player[i].PlayerID == id)
            {
                Player[i].Hits += h;
                Player[i].Walks += w;
                Player[i].Outs += o;
                break;
            }
        }
    }

    inFile.close();
}

// Calculate batting and on-base averages
void CalculateStats(PlayerInfo Player[])
{
    for (int i = 0; i < NUM_PLAYERS; i++)
    {
        int ab = Player[i].Hits + Player[i].Outs;
        int totalPlays = Player[i].Hits + Player[i].Walks + Player[i].Outs;

        Player[i].Batting = ab > 0 ? static_cast<double>(Player[i].Hits) / ab : 0;
        Player[i].OnBase = totalPlays > 0 ? static_cast<double>(Player[i].Hits + Player[i].Walks) / totalPlays : 0;
    }
}

// Print stats and highlight best/worst performers
void PrintFinalStats(PlayerInfo Player[], int year, ofstream &out, int size)
{
    cout << "\nPlayer statistic with their total hits, total walks, total outs, batting and on base average for season " << year << "." << endl;
    out << "\nPlayer statistic with their total hits, total walks, total outs, batting and on base average for season " << year << "." << endl;
    cout << "Player\tNumber\tHits\tWalks\tOuts\tBatting Avg\tOn Base Avg\tIn Disabled List\n";
    out << "Player\tNumber\tHits\tWalks\tOuts\tBatting Avg\tOn Base Avg\tIn Disabled List\n";
    cout << "-------------------------------------------------------------------------------------------\n";
    out << "-------------------------------------------------------------------------------------------\n";

    double bestBA = -1, worstBA = 2;   // Initialize best and worst batting averages.
    double bestOBA = -1, worstOBA = 2; // Initialize best and worst on-base averages.

    for (int i = 0; i < size; i++)
    {
        cout << Player[i].LastName << " " << Player[i].FirstName << "\t"
             << Player[i].PlayerID << "\t" << Player[i].Hits << "\t"
             << Player[i].Walks << "\t" << Player[i].Outs << "\t";
        out << Player[i].LastName << " " << Player[i].FirstName << "\t"
            << Player[i].PlayerID << "\t" << Player[i].Hits << "\t"
            << Player[i].Walks << "\t" << Player[i].Outs << "\t";

        if (Player[i].Hits + Player[i].Outs > 0)
        {
            cout << fixed << setprecision(2) << Player[i].Batting << "\t\t"
                 << Player[i].OnBase;
            out << fixed << setprecision(2) << Player[i].Batting << "\t\t"
                << Player[i].OnBase;
        }
        else
        {
            cout << "\t\t\t";
            out << "\t\t\t";
        }

        if (Player[i].Hits + Player[i].Walks + Player[i].Outs == 0)
        {
            cout << "\t\tYes";
            out << "\t\tYes";
        }
        cout << endl;
        out << endl;

        if (Player[i].Hits + Player[i].Outs > 0)
        {
            // Calculate best/worst batting averages.
            if (Player[i].Batting > bestBA)
                bestBA = Player[i].Batting;
            if (Player[i].Batting < worstBA)
                worstBA = Player[i].Batting;
        }

        if (Player[i].Hits + Player[i].Walks + Player[i].Outs > 0)
        {
            // Calculate best/worst on-base averages.
            if (Player[i].OnBase > bestOBA)
                bestOBA = Player[i].OnBase;
            if (Player[i].OnBase < worstOBA)
                worstOBA = Player[i].OnBase;
        }
    }

    // Print best/worst performers
    cout << fixed << setprecision(2);
    out << fixed << setprecision(2);
    cout << "\nThe best hitter with batting average of " << bestBA << ": ";
    out << "\nThe best hitter with batting average of " << bestBA << ": ";
    for (int i = 0; i < size; i++)
    {
        if (Player[i].Batting == bestBA)
            cout << Player[i].LastName << " ";
        out << Player[i].LastName << " ";
    }
    cout << "\nThe best hitter with batting average of " << worstBA << ": ";
    out << "\nThe worst hitter with batting average of " << worstBA << ": ";
    for (int i = 0; i < size; i++)
    {
        if (Player[i].Batting == worstBA)
            cout << Player[i].LastName << " ";
        out << Player[i].LastName << " ";
    }
    cout << "\nThe best base runner with on base average of " << bestOBA << ": ";
    out << "\nThe best base runner with on base average of " << bestOBA << ": ";
    for (int i = 0; i < size; i++)
    {
        if (Player[i].OnBase == bestOBA)
            cout << Player[i].LastName << " ";
        out << Player[i].LastName << " ";
    }
    cout << "\nThe worst base runner with on base average of " << worstOBA << ": ";
    out << "\nThe worst base runner with on base average of " << worstOBA << ": ";
    for (int i = 0; i < size; i++)
    {
        if (Player[i].OnBase == worstOBA)
            cout << Player[i].LastName << " ";
        out << Player[i].LastName << " ";
    }
    cout << endl;
    out << endl;
}
