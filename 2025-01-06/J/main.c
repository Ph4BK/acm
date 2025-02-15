#include <stdio.h>

typedef struct {
    int hw_score;
    int exam_score;
} score;

int main() {
    int n;
    scanf("%d",&n);
    int hw, exam, pass;
    scanf("%d %d %d",&hw,&exam,&pass);
    score scores[n];
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &scores[i].hw_score, &scores[i].exam_score);
    }
    int add;
    scanf("%d", &add);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (scores[i].hw_score + scores[i].exam_score >= pass) continue;
        scores[i].hw_score = scores[i].hw_score + add > hw ? hw : scores[i].hw_score + add;
        if (scores[i].hw_score + scores[i].exam_score >= pass) sum++;
    }
    printf("%d\n", sum);
    return 0;
}
