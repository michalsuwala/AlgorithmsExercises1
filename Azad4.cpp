#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

struct Student {
    char code[5];
    float average;
    int distance, month;
};

double typeS(Student s, char c) {
    if(c == 's') {
        return s.average;
    }
    else if(c == 'd') {
        return s.distance;
    }
    else if(c == 'm') {
        return s.month;
    }
    return 0;
}

bool comp(Student s1, Student s2, char order[]) {
    if(typeS(s1, order[0]) > typeS(s2, order[0]) ||
    (typeS(s1, order[0]) == typeS(s2, order[0]) && typeS(s1, order[1]) > typeS(s2, order[1])) ||
    (typeS(s1, order[0]) == typeS(s2, order[0]) && typeS(s1, order[1]) == typeS(s2, order[1]) 
    && typeS(s1, order[2]) > typeS(s2, order[2])) ||
    (typeS(s1, order[0]) == typeS(s2, order[0]) && typeS(s1, order[1]) == typeS(s2, order[1]) 
    && typeS(s1, order[2]) == typeS(s2, order[2])) && s1.code[3] < s2.code[3]) {
        return 1;
    }
    else {
        return 0;
    }
}

Student* quickSortC(Student* s, int n, char order[]) {
    if(n < 2) return s;
    else {
        double x = typeS(s[rand() / (RAND_MAX / n)], order[2]);

        int i1 = 0, i2 = 0, i3 = 0;
        int c2 = 0, c3 = 0;

        for(int i = 0; i < n; i++) {
            if(typeS(s[i], order[2]) > x) {
            }
            else if(typeS(s[i], order[2]) < x) {
                c2 += 1;
            }
            else {
                c3 += 1;
            }
        }

        Student* s2 = new Student[c2];
        Student* s3 = new Student[c3];


        for(int i = 0; i < n; i++) {
            if(typeS(s[i], order[2]) > x) {
                s[i1] = s[i];
                i1 += 1;
            }
            else if(typeS(s[i], order[2]) < x) {
                s2[i2] = s[i];
                i2 += 1;
            }
            else {
                s3[i3] = s[i];
                i3 += 1;
            }
        }

        s = quickSortC(s, i1, order);
        s2 = quickSortC(s2, i2, order);



        for(int i = i1, j = 0; j < i3; i++, j++) {
            s[i] = s3[j];
        }

        for(int i = i1 + i3, j = 0; j < i2; i++, j++) {
            s[i] = s2[j];
        }


        delete[] s2;
        delete[] s3;

        return s;
    }
}

Student* quickSortB(Student* s, int n, char order[]) {
    if(n < 2) return s;
    else {
        double x = typeS(s[rand() / (RAND_MAX / n)], order[1]);


        int i1 = 0, i2 = 0, i3 = 0;
        int c2 = 0, c3 = 0;

        for(int i = 0; i < n; i++) {
            if(typeS(s[i], order[1]) > x) {
            }
            else if(typeS(s[i], order[1]) < x) {
                c2 += 1;
            }
            else {
                c3 += 1;
            }
        }

        Student* s2 = new Student[c2];
        Student* s3 = new Student[c3];

        for(int i = 0; i < n; i++) {
            if(typeS(s[i], order[1]) > x) {
                s[i1] = s[i];
                i1 += 1;
            }
            else if(typeS(s[i], order[1]) < x) {
                s2[i2] = s[i];
                i2 += 1;
            }
            else {
                s3[i3] = s[i];
                i3 += 1;
            }
        }

        s = quickSortB(s, i1, order);
        s2 = quickSortB(s2, i2, order);
        s3 = quickSortC(s3, i3, order);



        for(int i = i1, j = 0; j < i3; i++, j++) {
            s[i] = s3[j];
        }

        for(int i = i1 + i3, j = 0; j < i2; i++, j++) {
            s[i] = s2[j];
        }


        delete[] s2;
        delete[] s3;

        return s;
    }
}

Student* quickSortA(Student* s, int n, char order[]) {
    if(n < 2) return s;
    else {
        int ind = rand() / (RAND_MAX / n);
        Student x = s[ind];
        double x0 = typeS(s[ind], order[0]);
        double x1 = typeS(s[ind], order[1]);
        double x2 = typeS(s[ind], order[2]); 
        char x4 = s[ind].code[3];       
        int i1 = 0, i2 = 0, i3 = 0;
        int c2 = 0, c3 = 0;

        for(int i = 0; i < n; i++) {
            comp(s[i], x, order);  
        }

        Student* s2 = new Student[c2];


        for(int i = 0; i < n; i++) {
            if(comp(s[i], x, order)) {
                s[i1] = s[i];
                i1 += 1;
            }
            else{
                s2[i2] = s[i];
                i2 += 1;
            }
            
        }

        s = quickSortA(s, i1, order);
        s2 = quickSortA(s2, i2, order);


        

        for(int i = i1, j = 0; j < i2; i++, j++) {
            s[i] = s2[j];
        }

        delete[] s2;
        return s;
    }
}

int main() {
    std::srand(std::time(NULL));
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    char order[3];

    std::cin >> n;

    Student* boys = new Student[n];
    Student* girls = new Student[n];

    for(int i = 0; i < 3; i++) {
        std::cin >> order[i];
    }
    for(int i = 0; i < n; i++) {
        std::cin >> girls[i].code >> girls[i].average >> girls[i].distance >> girls[i].month;
        std::cin >> boys[i].code >> boys[i].average >> boys[i].distance >> boys[i].month;
    }

    quickSortA(girls, n, order);
    quickSortA(boys, n, order);

    for(int i = 0; i < n; i++) {
        std::cout << girls[i].code << " " << boys[i].code << " ";
    }

    delete[] boys;
    delete[] girls;

    return 0;
}

