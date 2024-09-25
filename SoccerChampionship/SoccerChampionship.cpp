#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct Team {
	char teamName[100]{}, teamHometown[100]{};
	int foundedDay{}, foundedMonth{}, foundedYear{}, matchPlayed{}, matchLost{}, goalsFor{}, goalsAgainst{}, goalDifference{}, Points{};
};

void createContestant(Team* T, int& contestantCount, Team newTeam) {
	T[contestantCount] = newTeam;
	contestantCount++;
}

void addContestant(Team* T, int& contestantCount) {
	Team addContestant;
	cout << "  What is the name of the team?" << endl;
	cout << "  > ";
	cin >> addContestant.teamName;
	cout << "  What is " << addContestant.teamName << "'s hometown?" << endl;
	cout << "  > ";
	cin >> addContestant.teamHometown;
	do {
		cout << "  What day was " << addContestant.teamName << " founded?" << endl;
		cout << "  > ";
		cin >> addContestant.foundedDay;
	} while (addContestant.foundedDay < 1 || addContestant.foundedDay > 31);
	do {
		cout << "  What month was " << addContestant.teamName << " founded?" << endl;
		cout << "  > ";
		cin >> addContestant.foundedMonth;
	} while (addContestant.foundedMonth < 1 || addContestant.foundedMonth > 12);
	do {
		cout << "  What year was " << addContestant.teamName << " founded?" << endl;
		cout << "  > ";
		cin >> addContestant.foundedYear;
	} while (addContestant.foundedYear < 1800 || addContestant.foundedYear > 2021);

	createContestant(T, contestantCount, addContestant);
}

void holdChampionship(Team* T, int& contestantCount) {
	int s1, s2;
	srand(unsigned int(time(NULL)));
	system("cls");
	cout << "|----------------------------------------------------------------|" << endl;
	cout << "                     HOLDING THE CHAMPIONSHIP" << endl;
	cout << "|----------------------------------------------------------------|" << endl << endl;
	for (int i = 0; i < contestantCount - 1; i++) {
		for (int j = i + 1; j < contestantCount; j++) {
			cout << "___________________________________________" << endl;
			cout << "  Team " << T[i].teamName << " vs Team " << T[j].teamName << endl;
			s1 = rand() % 5;
			s2 = rand() % 5;

			T[i].matchPlayed += 1;
			T[i].goalsFor += s1;
			T[i].goalsAgainst += s2;

			T[j].matchPlayed += 1;
			T[j].goalsFor += s2;
			T[j].goalsAgainst += s1;

			T[i].goalDifference += s1 - s2;
			T[j].goalDifference += s2 - s1;

			cout << "  Result: (" << T[i].teamName << ") " << s1 << " : " << s2 << " (" << T[j].teamName << ")" << endl;
			if (s1 > s2) {
				cout << "  " << T[i].teamName << " won the match!" << endl;
				T[i].Points += 3;
				T[j].matchLost += 1;
			}
			else if (s2 > s1) {
				cout << "  " << T[j].teamName << " won the match!" << endl;
				T[j].Points += 3;
				T[i].matchLost += 1;
			}
			else {
				T[i].Points += 1;
				T[j].Points += 1;
				cout << "  Match was a tie!" << endl;
			}

			cout << "  Team " << T[j].teamName << " vs Team " << T[i].teamName << endl;
			s1 = rand() % 5;
			s2 = rand() % 5;

			T[j].matchPlayed += 1;
			T[j].goalsFor += s1;
			T[j].goalsAgainst += s2;

			T[i].matchPlayed += 1;
			T[i].goalsFor += s2;
			T[i].goalsAgainst += s1;

			T[j].goalDifference += s1 - s2;
			T[i].goalDifference += s2 - s1;

			cout << "  Result: (" << T[j].teamName << ") " << s1 << " : " << s2 << " (" << T[i].teamName << ")" << endl;
			if (s1 > s2) {
				cout << "  " << T[j].teamName << " won the match!" << endl;
				T[j].Points += 3;
				T[i].matchLost += 1;
			}
			else if (s2 > s1) {
				cout << "  " << T[i].teamName << " won the match!" << endl;
				T[i].Points += 3;
				T[j].matchLost += 1;
			}
			else {
				T[j].Points += 1;
				T[i].Points += 1;
				cout << "  Match was a tie!" << endl;
			}
		}
	}
	cout << "___________________________________________" << endl << endl;
	system("pause");
}

void showContestants(Team* T, int& contestantCount) {
	system("cls");
	cout << "|-------------------------------------------------------------|" << endl;
	cout << "                       CONTESTANTS LIST" << endl;
	cout << "|-------------------------------------------------------------|" << endl << endl;
	for (int i = 0; i < contestantCount; i++) {
		cout << "  | Name: " << T[i].teamName << "  | Hometown: " << T[i].teamHometown
			<< "  | Founded: " << T[i].foundedDay << "/" << T[i].foundedMonth << "/" << T[i].foundedYear
			<< "y.  | Scored Goals: " << T[i].goalsFor << "  | Allowed Goals: " << T[i].goalsAgainst
			<< "  | Goal Difference: " << T[i].goalDifference << "  | Points: " << T[i].Points
			<< "  | Played Matches: " << T[i].matchPlayed << "  | Lost Matches: " << T[i].matchLost << endl << endl;
	}
	system("pause");
}

void showContestantDate(Team* T, int& contestantCount) {
	int year = 9999;
	int month = 9999;
	int day = 9999;
	for (int i = 0; i < contestantCount; i++) {
		if (T[i].foundedYear < year) {
			year = T[i].foundedYear;
		}
		if (T[i].foundedYear == year) {
			if (T[i].foundedMonth < month) {
				month = T[i].foundedMonth;
			}
			if (T[i].foundedMonth == month) {
				if (T[i].foundedDay < day) {
					day = T[i].foundedDay;
				}
			}
		}
	}

	for (int i = 0; i < contestantCount; i++) {
		if (T[i].foundedYear == year && T[i].foundedMonth == month && T[i].foundedDay == day) {
			system("cls");
			cout << "|--------------------------------------------------------------------------------------------|" << endl;
			cout << "                      SHOWING THE TEAM WITH EARLIEST DATE OF FOUNDATION" << endl;
			cout << "|--------------------------------------------------------------------------------------------|" << endl << endl;
			cout << "  | Team: " << T[i].teamName << " | Founded: " << day << "/" << month << "/" << year << "y." << endl << endl;
			system("pause");
		}
	}
}

void showContestantLosses(Team* T, int& contestantCount) {
	int min = 9999;
	for (int i = 0; i < contestantCount; i++) {
		if (T[i].matchLost < min) {
			min = T[i].matchLost;
		}
	}

	for (int i = 0; i < contestantCount; i++) {
		if (T[i].matchLost == min) {
			system("cls");
			cout << "|--------------------------------------------------------------------------------------------|" << endl;
			cout << "                         SHOWING THE TEAM WITH THE LEAST LOST MATCHES" << endl;
			cout << "|--------------------------------------------------------------------------------------------|" << endl << endl;
			cout << "  | Team: " << T[i].teamName << " | Lost Matches: " << T[i].matchLost << endl << endl;
			system("pause");
		}
	}
}

void searchContestant(Team* T, int& contestantCount) {
	string nameSearch;
	system("cls");
	cout << "|---------------------------------------------------|" << endl;
	cout << "                SEARCHING FOR A TEAM" << endl;
	cout << "|---------------------------------------------------|" << endl << endl;
	cout << "  > Enter team name: ";
	cin >> nameSearch;
	for (int i = 0; i < contestantCount; i++) {
		if (nameSearch == T[i].teamName) {
			system("cls");
			cout << "|---------------------------------------|" << endl;
			cout << "  Showing match data for team (" << nameSearch << ")." << endl;
			cout << "|---------------------------------------|" << endl << endl;
			cout << " The team has " << T[i].matchPlayed << " matches." << endl << endl;
			system("pause");
			break;
		}
	}
}

void goalDifferenceContestant(Team* T, int& contestantCount) {
	int difference = 0;

	for (int i = 0; i < contestantCount; i++) {
		if (T[i].goalDifference > difference) {
			difference = T[i].goalDifference;
		}
	}
	for (int i = 0; i < contestantCount; i++) {
		if (T[i].goalDifference == difference) {
			system("cls");
			cout << "|--------------------------------------------------------------------------------------------|" << endl;
			cout << "                       SHOWING THE TEAM WITH THE BIGGEST GOAL DIFFERENCE" << endl;
			cout << "|--------------------------------------------------------------------------------------------|" << endl << endl;
			cout << "  | Team: " << T[i].teamName << " | Goal Difference: " << T[i].goalDifference << endl << endl;
			system("pause");
		}
	}
}

void mostGoalsContestant(Team* T, int& contestantCount) {
	int goals = 0;

	for (int i = 0; i < contestantCount; i++) {
		if (T[i].goalsFor > goals) {
			goals = T[i].goalsFor;
		}
	}
	for (int i = 0; i < contestantCount; i++) {
		if (T[i].goalsFor == goals) {
			system("cls");
			cout << "|--------------------------------------------------------------------------------------------|" << endl;
			cout << "                         SHOWING THE TEAM WITH THE MOST SCORED GOALS" << endl;
			cout << "|--------------------------------------------------------------------------------------------|" << endl << endl;
			cout << "  | Team: " << T[i].teamName << " | Scored: " << T[i].goalsFor << endl << endl;
			system("pause");
		}
	}
}

void sortContestantsByDate(Team* T, int& contestantCount) {
	for (int i = 0; i < contestantCount; i++) {
		for (int j = i + 1; j < contestantCount; j++) {
			if (T[i].foundedYear > T[j].foundedYear) {
				Team temporary = T[i];
				T[i] = T[j];
				T[j] = temporary;
			}
			else if (T[i].foundedYear == T[j].foundedYear && T[i].foundedMonth > T[j].foundedMonth) {
				Team temporary = T[i];
				T[i] = T[j];
				T[j] = temporary;
			}
			else if (T[i].foundedYear == T[j].foundedYear && T[i].foundedMonth == T[j].foundedMonth && T[i].foundedDay > T[j].foundedDay) {
				Team temporary = T[i];
				T[i] = T[j];
				T[j] = temporary;
			}
		}
	}
	system("cls");
	cout << "|--------------------------------------------------------------------------------------------|" << endl;
	cout << "                            SORTING CONTESTANTS BY FOUNDATION DATE" << endl;
	cout << "|--------------------------------------------------------------------------------------------|" << endl << endl;
	for (int c = 0; c < contestantCount; c++) {
		cout << "  | Team: " << T[c].teamName << " | Founded: " << T[c].foundedDay << "/" << T[c].foundedMonth << "/" << T[c].foundedYear << "y." << endl << endl;
	}
}

void sortContestantsByPoints(Team* T, int& contestantCount) {
	int points;

	for (int j = 0; j < contestantCount; j++) {
		for (int i = 0; i < contestantCount; i++) {
			if (T[i].Points < T[i + 1].Points) {
				points = T[i].Points;
				T[i].Points = T[i + 1].Points;
				T[i + 1].Points = points;
			}
		}
	}
	system("cls");
	cout << "|--------------------------------------------------------------------------------------------|" << endl;
	cout << "                      SORTING CONTESTANTS BY POINTS WON FROM ALL MATCHES" << endl;
	cout << "|--------------------------------------------------------------------------------------------|" << endl << endl;
	for (int i = 0; i < contestantCount; i++) {
		cout << "  | Team: " << T[i].teamName << "  | Points: " << T[i].Points << endl << endl;
	}
}

void writeBinary(Team* T, int& contestantCount) {
	Team Data;
	fstream File;
	File.open("Data.bin", ios::binary | ios::out);
	if (File.is_open()) {
		File.write((char*)T, sizeof(Team) * contestantCount);
		File.close();
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

int readBinary(Team* T) {
	long pos;
	int n = 0;
	Team Data;
	fstream File;
	File.open("Data.bin", ios::binary | ios::in);
	if (!File) {
		system("cls");
		cout << "|--------------------------------------------------------------------------------------------|" << endl;
		cout << "              WE DETECTED THAT YOU DO NOT HAVE ANY DATA SAVED INTO A BINARY FILE" << endl;
		cout << "|--------------------------------------------------------------------------------------------|" << endl << endl;
		system("pause");
		return n;
	}
	File.seekg(0l, ios::end);
	pos = File.tellg();
	File.close();
	n = pos / (sizeof(Team));

	File.open("Data.bin", ios::binary | ios::in);
	if (!File) {
		system("cls");
		cout << "|--------------------------------------------------------------------------------------------|" << endl;
		cout << "                                COULD NOT OPEN BINARY DATA FILE" << endl;
		cout << "|--------------------------------------------------------------------------------------------|" << endl << endl;
		system("pause");
		exit(1);
	}
	for (int i = 0; i < n; i++) {
		File.read((char*)&Data, sizeof(Team));
		T[i] = Data;
	}
	File.close();
	return n;
}

int main() {
	Team T[5];
	string choiceAddAnother;
	int choiceMain, choiceAdd, choiceData, choiceShowData, choiceReferenceData, choiceSortData;
	int contestantAdded = readBinary(T);
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
		do {
			cout << "  > Choose an option: ";
			cin >> choiceMain;
		} while (choiceMain < 1 || choiceMain > 5);
		switch (choiceMain) {
		case 1: {
			if (contestantAdded == 5) {
				system("cls");
				cout << "|------------------------------------------------------------------|" << endl;
				cout << "  You have reached the maximum number of allowed team contestants." << endl;
				cout << "                   You cannot enter more than 5!" << endl;
				cout << "|------------------------------------------------------------------|" << endl << endl;
				system("pause");
				break;
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
				} while (choiceAdd < 1 || choiceAdd > 3);
				switch (choiceAdd) {
				case 1: {
					do {
						system("cls");
						if (contestantAdded == 0) {
							cout << "|--------------------------------------------------|" << endl;
							cout << "  You haven't entered any team contestants so far." << endl;
							cout << "                  You can enter " << 5 - contestantAdded << "." << endl << endl;
							cout << "      Entering data for team contestant No" << contestantAdded + 1 << endl;
							cout << "|--------------------------------------------------|" << endl << endl;
						}
						else if (contestantAdded < 5) {
							cout << "|-----------------------------------------------|" << endl;
							cout << "  You have entered " << contestantAdded << " team contestant(s) so far." << endl;
							cout << "              You can enter " << 5 - contestantAdded << " more." << endl << endl;
							cout << "      Entering data for team contestant No" << contestantAdded + 1 << endl;
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
						addContestant(T, contestantAdded);
						if (contestantAdded == 5) {
							system("cls");
							cout << "|------------------------------------------------------------------|" << endl;
							cout << "             SUCCESSFULLY ADDED CONTESTANT(S) TO ARRAY" << endl;
							cout << "  You have reached the maximum number of allowed team contestants." << endl << endl;
							cout << "                       RETURNING TO MAIN MENU" << endl;
							cout << "|------------------------------------------------------------------|" << endl << endl;
							system("pause");
							break;
						}
						else if (contestantAdded < 5) {
							system("cls");
							cout << "|------------------------------------------------------------------|" << endl;
							cout << "             SUCCESSFULLY ADDED CONTESTANT(S) TO ARRAY" << endl;
							cout << "                     You have " << 5 - contestantAdded << " slot(s) left!" << endl << endl;
							cout << "              Would you like to add another contestant?" << endl;
							cout << "       (Y/y) to do so! | Anything else returns to main menu!" << endl;
							cout << "|------------------------------------------------------------------|" << endl << endl;
							cout << "  > Your choice: ";
							cin >> choiceAddAnother;
						}
					} while (choiceAddAnother == "Y" || choiceAddAnother == "y");
					break;
				}
				case 2: {
					do {
						system("cls");
						if (contestantAdded == 0) {
							cout << "|--------------------------------------------------|" << endl;
							cout << "  You haven't entered any team contestants so far." << endl;
							cout << "                  You can enter " << 5 - contestantAdded << "." << endl;
							cout << "|--------------------------------------------------|" << endl << endl;
						}
						else if (contestantAdded < 5) {
							cout << "|-----------------------------------------------|" << endl;
							cout << "  You have entered " << contestantAdded << " team contestant(s) so far." << endl;
							cout << "              You can enter " << 5 - contestantAdded << " more." << endl;
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
						if (contestantAdded + n > 5) {
							cout << "|----------------------------------------|" << endl;
							cout << "  You cannot enter " << n << " team contestants! " << endl;
							cout << "        You can only enter " << 5 - contestantAdded << " more." << endl;
							cout << "|----------------------------------------|" << endl << endl;
							system("pause");
							break;
						}
						for (int i = 0; i < n; i++) {
							system("cls");
							if (contestantAdded == 0) {
								cout << "|--------------------------------------------------|" << endl;
								cout << "  You haven't entered any team contestants so far." << endl;
								cout << "                  You can enter " << 5 - contestantAdded << "." << endl << endl;
								cout << "      Entering data for team contestant No" << contestantAdded + 1 << endl;
								cout << "|--------------------------------------------------|" << endl << endl;
							}
							else if (contestantAdded < 5) {
								cout << "|-----------------------------------------------|" << endl;
								cout << "  You have entered " << contestantAdded << " team contestant(s) so far." << endl;
								cout << "              You can enter " << 5 - contestantAdded << " more." << endl << endl;
								cout << "      Entering data for team contestant No" << contestantAdded + 1 << endl;
								cout << "|-----------------------------------------------|" << endl << endl;
							}
							addContestant(T, contestantAdded);
						}
						if (contestantAdded == 5) {
							system("cls");
							cout << "|------------------------------------------------------------------|" << endl;
							cout << "             SUCCESSFULLY ADDED CONTESTANT(S) TO ARRAY" << endl;
							cout << "  You have reached the maximum number of allowed team contestants." << endl << endl;
							cout << "                       RETURNING TO MAIN MENU" << endl;
							cout << "|------------------------------------------------------------------|" << endl << endl;
							system("pause");
							break;
						}
						else if (contestantAdded < 5) {
							system("cls");
							cout << "|------------------------------------------------------------------|" << endl;
							cout << "             SUCCESSFULLY ADDED CONTESTANT(S) TO ARRAY" << endl;
							cout << "                     You have " << 5 - contestantAdded << " slot(s) left!" << endl << endl;
							cout << "              Would you like to add another contestant?" << endl;
							cout << "       (Y/y) to do so! | Anything else returns to main menu!" << endl;
							cout << "|------------------------------------------------------------------|" << endl << endl;
							cout << "  > Your choice: ";
							cin >> choiceAddAnother;
						}
					} while (choiceAddAnother == "Y" || choiceAddAnother == "y");
					break;
				}
				case 3: {
					break;
				}
				}
			}
			break;
		}
		case 2: {
			if (contestantAdded < 3) {
				system("cls");
				cout << "|----------------------------------------------------------------|" << endl;
				cout << "  You must enter at least 3 team contestants to use this option." << endl;
				cout << "                    You have entered " << contestantAdded << " so far." << endl;
				cout << "|----------------------------------------------------------------|" << endl << endl;
			}
			else {
				holdChampionship(T, contestantAdded);
			}
			break;
		}
		case 3: {
			if (contestantAdded < 3) {
				system("cls");
				cout << "|----------------------------------------------------------------|" << endl;
				cout << "  You must enter at least 3 team contestants to use this option." << endl;
				cout << "                    You have entered " << contestantAdded << " so far." << endl;
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
				} while (choiceData < 1 || choiceData > 4);
				switch (choiceData) {
				case 1: {
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
					} while (choiceShowData < 1 || choiceShowData > 4);
					switch (choiceShowData) {
					case 1: {
						showContestants(T, contestantAdded);
						break;
					}
					case 2: {
						showContestantDate(T, contestantAdded);
						break;
					}
					case 3: {
						showContestantLosses(T, contestantAdded);
						break;
					}
					case 4: {
						break;
					}
					}
				}
					break;
				case 2: {
					searchContestant(T, contestantAdded);
					break;
				}
				case 3: {
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
					} while (choiceReferenceData < 1 || choiceReferenceData > 4);
					switch (choiceReferenceData) {
					case 1: {
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
						} while (choiceSortData < 1 || choiceSortData > 3);
						switch (choiceSortData) {
						case 1: {
							sortContestantsByDate(T, contestantAdded);
							system("pause");
							break;
						}
						case 2: {
							sortContestantsByPoints(T, contestantAdded);
							system("pause");
							break;
						}
						case 3: {
							break;
						}
						}
					}
						break;
					case 2: {
						mostGoalsContestant(T, contestantAdded);
						break;
					}
					case 3: {
						goalDifferenceContestant(T, contestantAdded);
						break;
					}
					case 4: {
						break;
					}
					}
				}
				case 4: {
					break;
				}
				}
			}
			break;
		}
		case 4: {
			writeBinary(T, contestantAdded);
			break;
		}
		}
	} while (choiceMain != 5); {
		system("cls");
		cout << "|----------------------------------------------------|" << endl;
		cout << "                   QUITTING PROGRAM" << endl;
		cout << "|----------------------------------------------------|" << endl;
		exit(0);
	}
}
