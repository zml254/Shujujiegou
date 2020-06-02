#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[10];
    int score;
}Student;

int getSize(Student students[]){

    int i, count = 0;
    for (i = 0; i < 100; i++) {
        if (students[i].name[0] == '\0' && students[i].score == -1) {
            break;
        }
        count++;
    }
    return count;
}

int testInit(Student students[]){
    int i;
    for (i = 0; i < 100; i++) {
        students[i].name[0] = '\0';
        students[i].score = -1;
    }
    for (i = 0; 1; i++) {
        printf("请输入学生姓名:");
        scanf("%s", students[i].name);
        getchar();
        printf("请输入学生成绩:");
        scanf("%d", &(students[i].score));
        getchar();
        printf("是否继续输入:");
        char y = getchar();
        getchar();
        if (y != 'Y') {
            break;
        }
    }
    return 1;
}

int rank(Student students[], int ranking[]) {
    int i, length, j;
    Student st;
    length = getSize(students);
    for (i = 1; i < length; i++) {
        st = students[i];
        for (j = i - 1; j >= 0; j--) {
            if (st.score < students[j].score) {
                students[j + 1] = students[j];
                students[j] = st;
            } else if (st.score > students[j].score) {
                break;
            }
        }
    }
    int t = 1;
    for (i = length - 1; i >= 0; i--) {
        if (students[i].score == students[i + 1].score && i + 1 < length) {
            ranking[i] = ranking[i + 1];
            t++;
        } else {
            ranking[i] = t;
            t++;
        }
    }
    return 1;
}

int chooseRank(Student students[],int ranking[]) {

    int i, j, length, temp;
    Student student;
    length = getSize(students);
    for (i = 0; i < length; i++) {
        temp = i;
        for (j = i; j < length; j++) {
            if (students[j].score > students[j + 1].score && j + 1 < length) {
                temp = j + 1;
            }
        }
        student = students[i];
        students[i] = students[temp];
        students[temp] = student;
    }
    int t = 1;
    for (i = length - 1; i >= 0; i--) {
        if (students[i].score == students[i + 1].score && i + 1 < length) {
            ranking[i] = ranking[i + 1];
            t++;
        } else {
            ranking[i] = t;
            t++;
        }
    }
    return 1;

}

int put(Student students[], int ranking[]) {
    int i, length;
    length = getSize(students);
    for (i = length - 1; i >= 0; i--) {
        printf("姓名:%10s ,成绩:%3d ,名次:%2d.\n", students[i].name, students[i].score, ranking[i]);
    }
}

int main() {

    int ranking[100];
    Student students[100];
    testInit(students);
//    rank(students, ranking);
    chooseRank(students, ranking);
    put(students, ranking);

}
