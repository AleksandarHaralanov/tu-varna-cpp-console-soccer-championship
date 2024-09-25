#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Team {
    char teamName[100]{}, teamHometown[100]{};
    int foundedDay{}, foundedMonth{}, foundedYear{};
    int matchPlayed{}, matchLost{}, goalsFor{}, goalsAgainst{}, goalDifference{}, points{};
};

static void createContestant(Team* teams, int& contestantCount, Team newTeam) {
    teams[contestantCount] = newTeam;
    contestantCount++;
}

static void addContestant(Team* teams, int& contestantCount) {
    Team newContestant;

    cout << "  What is the name of the team?" << endl;
    cout << "  > ";
    cin >> newContestant.teamName;

    cout << "  What is " << newContestant.teamName << "'s hometown?" << endl;
    cout << "  > ";
    cin >> newContestant.teamHometown;

    do {
        cout << "  What day was " << newContestant.teamName << " founded?" << endl;
        cout << "  > ";
        cin >> newContestant.foundedDay;
    } while (newContestant.foundedDay < 1 || newContestant.foundedDay > 31);

    do {
        cout << "  What month was " << newContestant.teamName << " founded?" << endl;
        cout << "  > ";
        cin >> newContestant.foundedMonth;
    } while (newContestant.foundedMonth < 1 || newContestant.foundedMonth > 12);

    do {
        cout << "  What year was " << newContestant.teamName << " founded?" << endl;
        cout << "  > ";
        cin >> newContestant.foundedYear;
    } while (newContestant.foundedYear < 1800 || newContestant.foundedYear > 2021);

    createContestant(teams, contestantCount, newContestant);
}

static void holdChampionship(Team* teams, int& contestantCount) {
    int score1, score2;
    srand(unsigned int(time(NULL)));
    system("cls");

    cout << "|----------------------------------------------------------------|" << endl;
    cout << "                     HOLDING THE CHAMPIONSHIP" << endl;
    cout << "|----------------------------------------------------------------|" << endl << endl;

    for (int i = 0; i < contestantCount - 1; i++) {
        for (int j = i + 1; j < contestantCount; j++) {
            cout << "___________________________________________" << endl;
            cout << "  Team " << teams[i].teamName << " vs Team " << teams[j].teamName << endl;

            score1 = rand() % 5;
            score2 = rand() % 5;

            teams[i].matchPlayed++;
            teams[i].goalsFor += score1;
            teams[i].goalsAgainst += score2;

            teams[j].matchPlayed++;
            teams[j].goalsFor += score2;
            teams[j].goalsAgainst += score1;

            teams[i].goalDifference += score1 - score2;
            teams[j].goalDifference += score2 - score1;

            cout << "  Result: (" << teams[i].teamName << ") " << score1 << " : " << score2 << " (" << teams[j].teamName << ")" << endl;
            if (score1 > score2) {
                teams[i].points += 3;
                teams[j].matchLost++;
            }
            else if (score2 > score1) {
                teams[j].points += 3;
                teams[i].matchLost++;
            }
            else {
                teams[i].points++;
                teams[j].points++;
                cout << "  Match was a tie!" << endl;
            }

            cout << "  Team " << teams[j].teamName << " vs Team " << teams[i].teamName << endl;
            score1 = rand() % 5;
            score2 = rand() % 5;

            teams[j].matchPlayed++;
            teams[j].goalsFor += score1;
            teams[j].goalsAgainst += score2;

            teams[i].matchPlayed++;
            teams[i].goalsFor += score2;
            teams[i].goalsAgainst += score1;

            teams[j].goalDifference += score1 - score2;
            teams[i].goalDifference += score2 - score1;

            cout << "  Result: (" << teams[j].teamName << ") " << score1 << " : " << score2 << " (" << teams[i].teamName << ")" << endl;
            if (score1 > score2) {
                teams[j].points += 3;
                teams[i].matchLost++;
            }
            else if (score2 > score1) {
                teams[i].points += 3;
                teams[j].matchLost++;
            }
            else {
                teams[j].points++;
                teams[i].points++;
                cout << "  Match was a tie!" << endl;
            }
        }
    }
    cout << "___________________________________________" << endl << endl;
    system("pause");
}

static void showContestants(Team* teams, int& contestantCount) {
    system("cls");
    cout << "|-------------------------------------------------------------|" << endl;
    cout << "                       CONTESTANTS LIST" << endl;
    cout << "|-------------------------------------------------------------|" << endl << endl;

    for (int i = 0; i < contestantCount; i++) {
        cout << "  | Name: " << teams[i].teamName << "  | Hometown: " << teams[i].teamHometown
            << "  | Founded: " << teams[i].foundedDay << "/" << teams[i].foundedMonth << "/" << teams[i].foundedYear
            << "y.  | Scored Goals: " << teams[i].goalsFor << "  | Allowed Goals: " << teams[i].goalsAgainst
            << "  | Goal Difference: " << teams[i].goalDifference << "  | Points: " << teams[i].points
            << "  | Played Matches: " << teams[i].matchPlayed << "  | Lost Matches: " << teams[i].matchLost << endl << endl;
    }
    system("pause");
}

static void showContestantDate(Team* teams, int& contestantCount) {
    int year = INT_MAX, month = INT_MAX, day = INT_MAX;

    for (int i = 0; i < contestantCount; i++) {
        if (teams[i].foundedYear < year) year = teams[i].foundedYear;
        if (teams[i].foundedYear == year && teams[i].foundedMonth < month) month = teams[i].foundedMonth;
        if (teams[i].foundedYear == year && teams[i].foundedMonth == month && teams[i].foundedDay < day) day = teams[i].foundedDay;
    }

    for (int i = 0; i < contestantCount; i++) {
        if (teams[i].foundedYear == year && teams[i].foundedMonth == month && teams[i].foundedDay == day) {
            system("cls");
            cout << "|--------------------------------------------------------------------------------------------|" << endl;
            cout << "                      SHOWING THE TEAM WITH EARLIEST DATE OF FOUNDATION" << endl;
            cout << "|--------------------------------------------------------------------------------------------|" << endl << endl;
            cout << "  | Team: " << teams[i].teamName << " | Founded: " << day << "/" << month << "/" << year << "y." << endl << endl;
            system("pause");
        }
    }
}

static void showContestantLosses(Team* teams, int& contestantCount) {
    int minLosses = INT_MAX;

    for (int i = 0; i < contestantCount; i++) {
        if (teams[i].matchLost < minLosses) minLosses = teams[i].matchLost;
    }

    for (int i = 0; i < contestantCount; i++) {
        if (teams[i].matchLost == minLosses) {
            system("cls");
            cout << "|--------------------------------------------------------------------------------------------|" << endl;
            cout << "                         SHOWING THE TEAM WITH THE LEAST LOST MATCHES" << endl;
            cout << "|--------------------------------------------------------------------------------------------|" << endl << endl;
            cout << "  | Team: " << teams[i].teamName << " | Lost Matches: " << teams[i].matchLost << endl << endl;
            system("pause");
        }
    }
}

static void searchContestant(Team* teams, int& contestantCount) {
    string nameSearch;
    system("cls");

    cout << "|---------------------------------------------------|" << endl;
    cout << "                SEARCHING FOR A TEAM" << endl;
    cout << "|---------------------------------------------------|" << endl << endl;
    cout << "  > Enter team name: ";
    cin >> nameSearch;

    for (int i = 0; i < contestantCount; i++) {
        if (nameSearch == teams[i].teamName) {
            system("cls");
            cout << "|---------------------------------------|" << endl;
            cout << "  Showing match data for team (" << nameSearch << ")." << endl;
            cout << "|---------------------------------------|" << endl << endl;
            cout << " The team has " << teams[i].matchPlayed << " matches." << endl << endl;
            system("pause");
            break;
        }
    }
}

static void goalDifferenceContestant(Team* teams, int& contestantCount) {
    int maxDifference = 0;

    for (int i = 0; i < contestantCount; i++) {
        if (teams[i].goalDifference > maxDifference) maxDifference = teams[i].goalDifference;
    }

    for (int i = 0; i < contestantCount; i++) {
        if (teams[i].goalDifference == maxDifference) {
            system("cls");
            cout << "|--------------------------------------------------------------------------------------------|" << endl;
            cout << "                       SHOWING THE TEAM WITH THE BIGGEST GOAL DIFFERENCE" << endl;
            cout << "|--------------------------------------------------------------------------------------------|" << endl << endl;
            cout << "  | Team: " << teams[i].teamName << " | Goal Difference: " << teams[i].goalDifference << endl << endl;
            system("pause");
        }
    }
}

static void mostGoalsContestant(Team* teams, int& contestantCount) {
    int mostGoals = 0;

    for (int i = 0; i < contestantCount; i++) {
        if (teams[i].goalsFor > mostGoals) mostGoals = teams[i].goalsFor;
    }

    for (int i = 0; i < contestantCount; i++) {
        if (teams[i].goalsFor == mostGoals) {
            system("cls");
            cout << "|--------------------------------------------------------------------------------------------|" << endl;
            cout << "                         SHOWING THE TEAM WITH THE MOST SCORED GOALS" << endl;
            cout << "|--------------------------------------------------------------------------------------------|" << endl << endl;
            cout << "  | Team: " << teams[i].teamName << " | Scored: " << teams[i].goalsFor << endl << endl;
            system("pause");
        }
    }
}

static void sortContestantsByDate(Team* teams, int& contestantCount) {
    for (int i = 0; i < contestantCount; i++) {
        for (int j = i + 1; j < contestantCount; j++) {
            if (teams[i].foundedYear > teams[j].foundedYear ||
                (teams[i].foundedYear == teams[j].foundedYear && teams[i].foundedMonth > teams[j].foundedMonth) ||
                (teams[i].foundedYear == teams[j].foundedYear && teams[i].foundedMonth == teams[j].foundedMonth && teams[i].foundedDay > teams[j].foundedDay)) {
                Team temp = teams[i];
                teams[i] = teams[j];
                teams[j] = temp;
            }
        }
    }

    system("cls");
    cout << "|--------------------------------------------------------------------------------------------|" << endl;
    cout << "                            SORTING CONTESTANTS BY FOUNDATION DATE" << endl;
    cout << "|--------------------------------------------------------------------------------------------|" << endl << endl;
    for (int c = 0; c < contestantCount; c++) {
        cout << "  | Team: " << teams[c].teamName << " | Founded: " << teams[c].foundedDay << "/" << teams[c].foundedMonth << "/" << teams[c].foundedYear << "y." << endl << endl;
    }
}

static void sortContestantsByPoints(Team* teams, int& contestantCount) {
    for (int i = 0; i < contestantCount; i++) {
        for (int j = i + 1; j < contestantCount; j++) {
            if (teams[i].points < teams[j].points) {
                Team temp = teams[i];
                teams[i] = teams[j];
                teams[j] = temp;
            }
        }
    }

    system("cls");
    cout << "|--------------------------------------------------------------------------------------------|" << endl;
    cout << "                      SORTING CONTESTANTS BY POINTS WON FROM ALL MATCHES" << endl;
    cout << "|--------------------------------------------------------------------------------------------|" << endl << endl;
    for (int i = 0; i < contestantCount; i++) {
        cout << "  | Team: " << teams[i].teamName << "  | Points: " << teams[i].points << endl << endl;
    }
}

static void writeBinary(Team* teams, int& contestantCount) {
    fstream file;
    file.open("data.bin", ios::binary | ios::out);
    if (file.is_open()) {
        file.write((char*)teams, sizeof(Team) * contestantCount);
        file.close();
        system("cls");
        cout << "|--------------------------------------------------------------------------------------------|" << endl;
        cout << "                            DATA SUCCESSFULLY SAVED TO BINARY FILE" << endl;
        cout << "|--------------------------------------------------------------------------------------------|" << endl << endl;
        system("pause");
    }
    else {
        system("cls");
        cout << "|--------------------------------------------------------------------------------------------|" << endl;
        cout << "                                COULD NOT OPEN BINARY DATA FILE" << endl;
        cout << "|--------------------------------------------------------------------------------------------|" << endl << endl;
        system("pause");
    }
}

static int readBinary(Team* teams) {
    int n = 0;
    long pos;
    fstream file;
    file.open("data.bin", ios::binary | ios::in);
    if (!file) {
        system("cls");
        cout << "|--------------------------------------------------------------------------------------------|" << endl;
        cout << "              WE DETECTED THAT YOU DO NOT HAVE ANY DATA SAVED INTO A BINARY FILE" << endl;
        cout << "|--------------------------------------------------------------------------------------------|" << endl << endl;
        system("pause");
        return n;
    }

    file.seekg(0l, ios::end);
    pos = file.tellg();
    file.close();
    n = pos / (sizeof(Team));

    file.open("data.bin", ios::binary | ios::in);
    if (!file) {
        system("cls");
        cout << "|--------------------------------------------------------------------------------------------|" << endl;
        cout << "                                COULD NOT OPEN BINARY DATA FILE" << endl;
        cout << "|--------------------------------------------------------------------------------------------|" << endl << endl;
        system("pause");
        exit(1);
    }

    for (int i = 0; i < n; i++) {
        file.read((char*)&teams[i], sizeof(Team));
    }
    file.close();
    return n;
}

int main() {
    Team teams[5];
    string choiceAddAnother;
    int choiceMain, choiceAdd, choiceData, choiceShowData, choiceReferenceData, choiceSortData;
    int contestantCount = readBinary(teams);

    do {
        system("cls");
        cout << "|----------------------------------------------------|" << endl;
        cout << "                      MAIN MENU" << endl;
        cout << "|----------------------------------------------------|" << endl << endl;
        cout << "  (1) Add contestant(s)" << endl;
        cout << "  (2) Hold championship" << endl;
        cout << "  (3) View contestant(s) data" << endl;
        cout << "  (4) Save data to binary file" << endl << endl;
        cout << "  (5) EXIT" << endl << endl;
        cout << "  > Choose an option: ";
        cin >> choiceMain;

        switch (choiceMain) {
        case 1:
            if (contestantCount == 5) {
                system("cls");
                cout << "|------------------------------------------------------------------|" << endl;
                cout << "  You have reached the maximum number of allowed team contestants." << endl;
                cout << "                   You cannot enter more than 5!" << endl;
                cout << "|------------------------------------------------------------------|" << endl << endl;
                system("pause");
            }
            else {
                do {
                    system("cls");
                    cout << "|----------------------------------------------------|" << endl;
                    cout << "                   ADD CONTESTANT(S)" << endl;
                    cout << "|----------------------------------------------------|" << endl << endl;
                    cout << "  (1) Add a single contestant" << endl;
                    cout << "  (2) Add multiple contestants" << endl << endl;
                    cout << "  (3) GO BACK" << endl << endl;
                    cout << "  > Choose an option: ";
                    cin >> choiceAdd;

                    switch (choiceAdd) {
                    case 1:
                        do {
                            system("cls");
                            if (contestantCount == 0) {
                                cout << "|--------------------------------------------------|" << endl;
                                cout << "  You haven't entered any team contestants so far." << endl;
                                cout << "                  You can enter " << 5 - contestantCount << "." << endl << endl;
                                cout << "      Entering data for team contestant No" << contestantCount + 1 << endl;
                                cout << "|--------------------------------------------------|" << endl << endl;
                            }
                            else if (contestantCount < 5) {
                                cout << "|-----------------------------------------------|" << endl;
                                cout << "  You have entered " << contestantCount << " team contestant(s) so far." << endl;
                                cout << "              You can enter " << 5 - contestantCount << " more." << endl << endl;
                                cout << "      Entering data for team contestant No" << contestantCount + 1 << endl;
                                cout << "|-----------------------------------------------|" << endl << endl;
                            }
                            else {
                                cout << "|------------------------------------------------------------------|" << endl;
                                cout << "  You have reached the maximum number of allowed team contestants." << endl;
                                cout << "                   You cannot enter more than 5!" << endl;
                                cout << "|------------------------------------------------------------------|" << endl << endl;
                                system("pause");
                                break;
                            }
                            addContestant(teams, contestantCount);
                            if (contestantCount == 5) {
                                system("cls");
                                cout << "|------------------------------------------------------------------|" << endl;
                                cout << "             SUCCESSFULLY ADDED CONTESTANT(S) TO ARRAY" << endl;
                                cout << "  You have reached the maximum number of allowed team contestants." << endl << endl;
                                cout << "                       RETURNING TO MAIN MENU" << endl;
                                cout << "|------------------------------------------------------------------|" << endl << endl;
                                system("pause");
                                break;
                            }
                            else if (contestantCount < 5) {
                                system("cls");
                                cout << "|------------------------------------------------------------------|" << endl;
                                cout << "             SUCCESSFULLY ADDED CONTESTANT(S) TO ARRAY" << endl;
                                cout << "                     You have " << 5 - contestantCount << " slot(s) left!" << endl << endl;
                                cout << "              Would you like to add another contestant?" << endl;
                                cout << "       (Y/y) to do so! | Anything else returns to main menu!" << endl;
                                cout << "|------------------------------------------------------------------|" << endl << endl;
                                cout << "  > Your choice: ";
                                cin >> choiceAddAnother;
                            }
                        } while (choiceAddAnother == "Y" || choiceAddAnother == "y");
                        break;
                    case 2:
                        do {
                            system("cls");
                            if (contestantCount == 0) {
                                cout << "|--------------------------------------------------|" << endl;
                                cout << "  You haven't entered any team contestants so far." << endl;
                                cout << "                  You can enter " << 5 - contestantCount << "." << endl;
                                cout << "|--------------------------------------------------|" << endl << endl;
                            }
                            else if (contestantCount < 5) {
                                cout << "|-----------------------------------------------|" << endl;
                                cout << "  You have entered " << contestantCount << " team contestant(s) so far." << endl;
                                cout << "              You can enter " << 5 - contestantCount << " more." << endl;
                                cout << "|-----------------------------------------------|" << endl << endl;
                            }
                            else {
                                cout << "|------------------------------------------------------------------|" << endl;
                                cout << "  You have reached the maximum number of allowed team contestants." << endl;
                                cout << "                   You cannot enter more than 5!" << endl;
                                cout << "|------------------------------------------------------------------|" << endl << endl;
                                system("pause");
                                break;
                            }
                            int n;
                            do {
                                cout << "  How many contestants would you like to add?" << endl;
                                cout << "  > ";
                                cin >> n;
                                system("cls");
                            } while (n < 1);
                            if (contestantCount + n > 5) {
                                cout << "|----------------------------------------|" << endl;
                                cout << "  You cannot enter " << n << " team contestants! " << endl;
                                cout << "        You can only enter " << 5 - contestantCount << " more." << endl;
                                cout << "|----------------------------------------|" << endl << endl;
                                system("pause");
                                break;
                            }
                            for (int i = 0; i < n; i++) {
                                system("cls");
                                if (contestantCount == 0) {
                                    cout << "|--------------------------------------------------|" << endl;
                                    cout << "  You haven't entered any team contestants so far." << endl;
                                    cout << "                  You can enter " << 5 - contestantCount << "." << endl << endl;
                                    cout << "      Entering data for team contestant No" << contestantCount + 1 << endl;
                                    cout << "|--------------------------------------------------|" << endl << endl;
                                }
                                else if (contestantCount < 5) {
                                    cout << "|-----------------------------------------------|" << endl;
                                    cout << "  You have entered " << contestantCount << " team contestant(s) so far." << endl;
                                    cout << "              You can enter " << 5 - contestantCount << " more." << endl << endl;
                                    cout << "      Entering data for team contestant No" << contestantCount + 1 << endl;
                                    cout << "|-----------------------------------------------|" << endl << endl;
                                }
                                addContestant(teams, contestantCount);
                            }
                            if (contestantCount == 5) {
                                system("cls");
                                cout << "|------------------------------------------------------------------|" << endl;
                                cout << "             SUCCESSFULLY ADDED CONTESTANT(S) TO ARRAY" << endl;
                                cout << "  You have reached the maximum number of allowed team contestants." << endl << endl;
                                cout << "                       RETURNING TO MAIN MENU" << endl;
                                cout << "|------------------------------------------------------------------|" << endl << endl;
                                system("pause");
                            }
                            else if (contestantCount < 5) {
                                system("cls");
                                cout << "|------------------------------------------------------------------|" << endl;
                                cout << "             SUCCESSFULLY ADDED CONTESTANT(S) TO ARRAY" << endl;
                                cout << "                     You have " << 5 - contestantCount << " slot(s) left!" << endl << endl;
                                cout << "              Would you like to add another contestant?" << endl;
                                cout << "       (Y/y) to do so! | Anything else returns to main menu!" << endl;
                                cout << "|------------------------------------------------------------------|" << endl << endl;
                                cout << "  > Your choice: ";
                                cin >> choiceAddAnother;
                            }
                        } while (choiceAddAnother == "Y" || choiceAddAnother == "y");
                        break;
                    default:
                        break;
                    }
                } while (choiceAdd == 1 || choiceAdd == 2);
            }
            break;
        case 2:
            if (contestantCount < 3) {
                system("cls");
                cout << "|----------------------------------------------------------------|" << endl;
                cout << "  You must enter at least 3 team contestants to use this option." << endl;
                cout << "                    You have entered " << contestantCount << " so far." << endl;
                cout << "|----------------------------------------------------------------|" << endl << endl;
            }
            else {
                holdChampionship(teams, contestantCount);
            }
            break;
        case 3:
            if (contestantCount < 3) {
                system("cls");
                cout << "|----------------------------------------------------------------|" << endl;
                cout << "  You must enter at least 3 team contestants to use this option." << endl;
                cout << "                    You have entered " << contestantCount << " so far." << endl;
                cout << "|----------------------------------------------------------------|" << endl << endl;
                system("pause");
            }
            else {
                do {
                    system("cls");
                    cout << "|----------------------------------------------------|" << endl;
                    cout << "                   CONTESTANT DATA" << endl;
                    cout << "|----------------------------------------------------|" << endl << endl;
                    cout << "  (1) Show contestant(s)" << endl;
                    cout << "  (2) Search contestant(s)" << endl;
                    cout << "  (3) Reference contestant(s)" << endl << endl;
                    cout << "  (4) GO BACK" << endl << endl;
                    cout << "  > Choose an option: ";
                    cin >> choiceData;

                    switch (choiceData) {
                    case 1:
                        do {
                            system("cls");
                            cout << "|----------------------------------------------------|" << endl;
                            cout << "                 VIEW CONTESTANT DATA" << endl;
                            cout << "|----------------------------------------------------|" << endl << endl;
                            cout << "  (1) Show contestants" << endl;
                            cout << "  (2) Show contestant (Earliest date of foundation)" << endl;
                            cout << "  (3) Show contestant (Least lost matches)" << endl << endl;
                            cout << "  (4) GO BACK" << endl << endl;
                            cout << "  > Choose an option: ";
                            cin >> choiceShowData;

                            switch (choiceShowData) {
                            case 1:
                                showContestants(teams, contestantCount);
                                break;
                            case 2:
                                showContestantDate(teams, contestantCount);
                                break;
                            case 3:
                                showContestantLosses(teams, contestantCount);
                                break;
                            default:
                                break;
                            }
                        } while (choiceShowData != 4);
                        break;
                    case 2:
                        searchContestant(teams, contestantCount);
                        break;
                    case 3:
                        do {
                            system("cls");
                            cout << "|----------------------------------------------------|" << endl;
                            cout << "               REFERENCE CONTESTANT DATA" << endl;
                            cout << "|----------------------------------------------------|" << endl << endl;
                            cout << "  (1) Sort contestants" << endl;
                            cout << "  (2) Show contestant (Most scored goals)" << endl;
                            cout << "  (3) Show contestant (Biggest goal difference)" << endl << endl;
                            cout << "  (4) GO BACK" << endl << endl;
                            cout << "  > Choose an option: ";
                            cin >> choiceReferenceData;

                            switch (choiceReferenceData) {
                            case 1:
                                do {
                                    system("cls");
                                    cout << "|----------------------------------------------------|" << endl;
                                    cout << "                 SORT CONTESTANTS LIST" << endl;
                                    cout << "|----------------------------------------------------|" << endl << endl;
                                    cout << "  (1) Sort by foundation date" << endl;
                                    cout << "  (2) Sort by points" << endl << endl;
                                    cout << "  (3) GO BACK" << endl << endl;
                                    cout << "  > Choose an option: ";
                                    cin >> choiceSortData;

                                    switch (choiceSortData) {
                                    case 1:
                                        sortContestantsByDate(teams, contestantCount);
                                        system("pause");
                                        break;
                                    case 2:
                                        sortContestantsByPoints(teams, contestantCount);
                                        system("pause");
                                        break;
                                    default:
                                        break;
                                    }
                                } while (choiceSortData != 3);
                                break;
                            case 2:
                                mostGoalsContestant(teams, contestantCount);
                                break;
                            case 3:
                                goalDifferenceContestant(teams, contestantCount);
                                break;
                            default:
                                break;
                            }
                        } while (choiceReferenceData != 4);
                        break;
                    default:
                        break;
                    }
                } while (choiceData != 4);
            }
            break;
        case 4:
            writeBinary(teams, contestantCount);
            break;
        default:
            break;
        }
    } while (choiceMain != 5);

    system("cls");
    cout << "|----------------------------------------------------|" << endl;
    cout << "                   QUITTING PROGRAM" << endl;
    cout << "|----------------------------------------------------|" << endl;
    exit(0);
}
