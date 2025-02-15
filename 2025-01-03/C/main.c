#include <stdio.h>

struct stat {
    int solved;
    int time;
};

typedef struct stat stat;

struct record {
    int solved;
    int attempt;
};

typedef struct record record;

int rank(stat* status, int team) {
    int rank = 1;
    for (int i = 1; i < team + 1; i++) {
        if (status[i].solved > status[0].solved) rank++;
        if (status[i].solved == status[0].solved) {
            if (status[i].time < status[0].time) rank++;
        }
    }
    return rank;
}

int main() {
    int team, submit;
    scanf("%d%d", &team, &submit);
    stat status[team + 1];
    for (int i = 0; i < team + 1; i++) {
        status[i].solved = 0;
        status[i].time = 0;
    }
    record list[team + 1][26];
    for (int i = 0; i < team + 1; i++) {
        for (int j = 0; j < 26; j++) {
            list[i][j].solved = 0;
            list[i][j].attempt = 0;
        }
    }
    for (int i = 0; i < submit; i++) {
        int hr, min, s, ms;
        int teamNo;
        char ques;
        char stat[3];
        scanf("%d:%d:%d.%d %d %c %s", &hr, &min, &s, &ms, &teamNo, &ques, stat);
        if (list[teamNo][ques - 'A'].solved == 0) {
            if (stat[0] == 'R') list[teamNo][ques - 'A'].attempt++;
            else {
                int prev_rank = 0;
                if (teamNo == 0) prev_rank = rank(status, team);
                list[teamNo][ques - 'A'].solved = 1;
                status[teamNo].solved++;
                status[teamNo].time += 60 * hr + min + 20 * list[teamNo][ques - 'A'].attempt;
                if (teamNo == 0) {
                    int cur_rank = rank(status, team);
                    printf("%02d:%02d:%02d.%03d %c #%d -> #%d\n", hr, min, s, ms, ques, prev_rank, cur_rank);
                }
            }
        }
    }
    return 0;
}
