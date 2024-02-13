#include <iostream>

struct Student {
    char code[5];
    double average;
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
    if((typeS(s1, order[0]) > typeS(s2, order[0])) ||
    (typeS(s1, order[0]) == typeS(s2, order[0]) && typeS(s1, order[1]) > typeS(s2, order[1])) ||
    (typeS(s1, order[0]) == typeS(s2, order[0]) && typeS(s1, order[1]) == typeS(s2, order[1]) 
    && typeS(s1, order[2]) > typeS(s2, order[2])) ||
    (typeS(s1, order[0]) == typeS(s2, order[0]) && typeS(s1, order[1]) == typeS(s2, order[1]) 
    && typeS(s1, order[2]) == typeS(s2, order[2]))) {
        return 1;
    }
    else {
        return 0;
    }
}



void merge(Student left[], Student right[], Student s[], int ls, int rs, int n, char order[]) {
    int i = 0, l = 0, r = 0;


    while(l < ls && r < rs) {
        if(comp(left[l], right[r], order)) {
            s[i] = left[l];
            i++;
            l++;
        }
        else {
            s[i] = right[r];
            i++;
            r++; 
        }
    }

    while(l < ls) {
        s[i] = left[l];
        i++;
        l++;
    }

    while(r < rs) {
        s[i] = right[r];
        i++;
        r++;
    }
}

void mergeSort(Student s[], int n, char order[]) {
    if(n <= 1) return;

    int middle = n / 2;
    Student left[middle];
    Student right[n - middle];

    int j = 0;
    int l = 0;

    for(int i = 0; i < n; i++) {
        if(i < middle) {
            left[i] = s[i];
            l++;
        }
        else {
            right[j] = s[i];
            j++;
        }
    }
    mergeSort(left, l, order);
    mergeSort(right, j, order);
    merge(left, right, s, l, j, n, order);
}




int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    char order[3];

    std::cin >> n;

    Student boys[n];
    Student girls[n];

    for(int i = 0; i < 3; i++) {
        std::cin >> order[i];
    }
    for(int i = 0; i < n; i++) {
        std::cin >> girls[i].code >> girls[i].average >> girls[i].distance >> girls[i].month;
        std::cin >> boys[i].code >> boys[i].average >> boys[i].distance >> boys[i].month;
    }

    mergeSort(girls, n, order);
    mergeSort(boys, n, order);

    for(int i = 0; i < n; i++) {
        std::cout << girls[i].code << " " << boys[i].code << " ";
    }

    return 0;
}