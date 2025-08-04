#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Player {
    int ID;
    char name[20];
    char category[10];
    int wickets;
    int runscored;
    int runGiven;
    int catches;
    int matches;
};

void readPlayers(FILE *file, struct Player players[], int *count) {
    *count = 0;
    while (fscanf(file, "%d %s %s %d %d %d %d %d",
                 &players[*count].ID, players[*count].name, players[*count].category,
                 &players[*count].wickets, &players[*count].runscored,
                 &players[*count].runGiven, &players[*count].catches,
                 &players[*count].matches) != EOF) {
        (*count)++;
    }
}

void highestRunsScorerWC(struct Player players[], int count) {
    int maxRuns = -1;
    char maxName[20] = "";

    for (int i = 0; i < count; i++) {
        if (strcmp(players[i].category, "WC") == 0 && players[i].runscored > maxRuns) {
            maxRuns = players[i].runscored;
            strcpy(maxName, players[i].name);
        }
    }

    if (maxRuns != -1) {
        printf("Highest runs scorer in WC category: %s with %d runs\n", maxName, maxRuns);
    } else {
        printf("No WC category players found.\n");
    }
}

void batsmanTotalRunsAndHighestAverage(struct Player players[], int count) {
    int maxAverage = -1;
    char maxName[20] = "";
    int totalRuns;

    for (int i = 0; i < count; i++) {
        if (strcmp(players[i].category, "Batsman") == 0) {
            totalRuns = players[i].runscored;
            int average = totalRuns / players[i].matches;
            printf("Batsman %s has total runs: %d\n", players[i].name, totalRuns);

            if (average > maxAverage) {
                maxAverage = average;
                strcpy(maxName, players[i].name);
            }
        }
    }

    if (maxAverage != -1) {
        printf("Batsman with highest average run: %s with average %d\n", maxName, maxAverage);
    } else {
        printf("No Batsman category players found.\n");
    }
}

void highestCatches(struct Player players[], int count) {
    int maxCatchesBowler = -1, maxCatchesBatsman = -1;
    char maxBowlerName[20] = "", maxBatsmanName[20] = "";

    for (int i = 0; i < count; i++) {
        if (strcmp(players[i].category, "Bowler") == 0 && players[i].catches > maxCatchesBowler) {
            maxCatchesBowler = players[i].catches;
            strcpy(maxBowlerName, players[i].name);
        }
        if (strcmp(players[i].category, "Batsman") == 0 && players[i].catches > maxCatchesBatsman) {
            maxCatchesBatsman = players[i].catches;
            strcpy(maxBatsmanName, players[i].name);
        }
    }

    if (maxCatchesBowler != -1) {
        printf("Bowler with highest catches: %s with %d catches\n", maxBowlerName, maxCatchesBowler);
    } else {
        printf("No Bowler category players found.\n");
    }

    if (maxCatchesBatsman != -1) {
        printf("Batsman with highest catches: %s with %d catches\n", maxBatsmanName, maxCatchesBatsman);
    } else {
        printf("No Batsman category players found.\n");
    }
}

void leastRunsGivenPerWicket(struct Player players[], int count) {
    float minRatio = -1;
    char minName[20] = "";

    for (int i = 0; i < count; i++) {
        if (strcmp(players[i].category, "Bowler") == 0 && players[i].wickets > 0) {
            float ratio = (float)players[i].runGiven / players[i].wickets;
            if (minRatio == -1 || ratio < minRatio) {
                minRatio = ratio;
                strcpy(minName, players[i].name);
            }
        }
    }

    if (minRatio != -1) {
        printf("Bowler with least runs given per wicket: %s with %.2f runs per wicket\n", minName, minRatio);
    } else {
        printf("No Bowler category players found.\n");
    }
}

void batsmanWithHighestWickets(struct Player players[], int count) {
    int maxWickets = -1;
    char maxName[20] = "";

    for (int i = 0; i < count; i++) {
        if (strcmp(players[i].category, "Batsman") == 0 && players[i].wickets > maxWickets) {
            maxWickets = players[i].wickets;
            strcpy(maxName, players[i].name);
        }
    }

    if (maxWickets != -1) {
        printf("Batsman with highest wickets: %s with %d wickets\n", maxName, maxWickets);
    } else {
        printf("No Batsman category players found.\n");
    }
}

int main() {
    FILE *file = fopen("info.txt", "r");
    if (!file) {
        perror("Failed to open file");
        return 1;
    }

    struct Player players[100];
    int count;

    readPlayers(file, players, &count);
    fclose(file);

    highestRunsScorerWC(players, count);
    batsmanTotalRunsAndHighestAverage(players, count);
    highestCatches(players, count);
    leastRunsGivenPerWicket(players, count);
    batsmanWithHighestWickets(players, count);

    return 0;
}