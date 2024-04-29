#include <iostream>
#include <string>
using namespace std;

class Player
{
private:
    int Id;
    string Name;
    string teamName;
    int noOfMatches;
    int totalRuns;
    int totalWickets;
    int totalCatches;

public:
    Player() {
	    Id = 0;
        Name = " ";
        teamName = " ";
        noOfMatches = 0;
        totalRuns = 0;
        totalWickets = 0;
        totalCatches = 0;
		}
    Player(int id, string player, string team, int matches, int runs, int wickets, int catches)
    {
        Id = id;
        Name = player;
        teamName = team;
        noOfMatches = matches;
        totalRuns = runs;
        totalWickets = wickets;
        totalCatches = catches;
    }
    void setId(int id)
    {
        Id = id;
    }
    void setPlayerName(string player)
    {

        Name = player;
    }
    void setteamName(string team)
    {
        teamName = team;
    }
    void setMatches(int matches)
    {
        noOfMatches = matches;
    }
    void setRuns(int runs)
    {
        totalRuns = runs;
    }
    void setSellPrice(int wickets)
    {
        totalWickets = wickets;
    }
    void setCatches(int catches)
    {
        totalCatches = catches;
    }
    
    int getCatches()
    {
        return totalCatches;
    }
    int getWickets()
    {
        return totalWickets;
    }
    int getRuns()
    {
        return totalRuns;
    }
    void displayAllData()
    {
        cout << "ID: " << Id << endl;
        cout << "Player Name: " << Name << endl;
        cout << "Team Name: " << teamName << endl;
        cout << "No of Matches Played: " << noOfMatches << endl;
        cout << "Total Runs Scored: " << totalRuns << endl;
        cout << "Total Wickets Taken: " << totalWickets << endl;
        cout << "Total Catches Taken: " << totalCatches << endl;
    }
};

int main()
{
	int id, matches, runs, wickets, catches, size;
    string player, team;
    cout << "Please enter the Number of Players: " ;
    cin >> size;
    Player *playerArray = new Player[size];

    for (int i = 0; i < size; i++)
    {
        cout << "\nEnter Stats for Player " << i + 1 << ":\n";
        cout << "ID Number: ";
        cin >> id;
        cin.ignore();
        cout << "Player Name: ";
        getline(cin, player);
        cout << "Team Name: ";
        getline(cin, team);
        cout << "No. of Matches Played: ";
        cin >> matches;
        cout << "Total Runs Scored: ";
        cin >> runs;
        cout << "Total Wickets Taken: ";
        cin >> wickets;
        cout << "Total Catches Taken: ";
        cin >> catches;

        playerArray[i] = Player(id, player, team, matches, runs, wickets, catches);
    }

    for (int i = 0; i < size; i++)
    {
        cout << "\nPlayer Statistics " << i + 1 << endl;
        playerArray[i].displayAllData();
    }
    Player runObj, wicketObj, catchObj;
    for (int i = 0; i < size; i++)
    {
    	if(playerArray[0].getRuns() <= playerArray[i].getRuns()){
    		runObj = playerArray[i];
		}
		if( playerArray[0].getWickets() <= playerArray[i].getWickets()){
    		wicketObj = playerArray[i];
		}
		if(playerArray[0].getCatches() <= playerArray[i].getCatches()){
    		catchObj = playerArray[i];
		}
    }
         
        cout << endl << endl <<endl;
        cout << "Highest Achievers of Each Team" << endl << endl;
        cout << "Player with Highest Runs" << endl << endl;
    	runObj.displayAllData();
    	cout << "\n\nPlayer with Most Wickets" << endl << endl;
    	wicketObj.displayAllData();
    	cout << "\n\nPlayer with Most Catches" << endl;
    	catchObj.displayAllData();
    
    delete[] playerArray;

    return 0;
}
