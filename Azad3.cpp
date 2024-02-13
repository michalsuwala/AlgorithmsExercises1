#include <iostream>
#include <cstdlib>
#include <ctime>

struct Person {
    std::string name;
    int x;
};

Person* quicksortName(Person* p, int n) {
    if(n < 2) return p;
    else {
        std::string name = p[rand() / (RAND_MAX / n)].name;

        Person* p1 = new Person[n];
        Person* p2 = new Person[n];
        Person* p3 = new Person[n];
        int i1 = 0, i2 = 0, i3 = 0;

        for(int i = 0; i < n; i++) {
            if(p[i].name < name) {
                p1[i1] = p[i];
                i1 += 1;
            }
            else if(p[i].name > name) {
                p2[i2] = p[i];
                i2 += 1;
            }
            else {
                p3[i3] = p[i];
                i3 += 1;
            }
        }

        p1 = quicksortName(p1, i1);
        p2 = quicksortName(p2, i2);

        for(int i = 0; i < i1; i++) {
            p[i] = p1[i];
        }

        for(int i = i1, j = 0; j < i3; i++, j++) {
            p[i] = p3[j];
        }

        for(int i = i1 + i3, j = 0; j < i2; i++, j++) {
            p[i] = p2[j];
        }

        delete[] p1;
        delete[] p2;
        delete[] p3;

        return p;
    }
}

Person* quicksort(Person* p, int n) {
    if(n < 2) return p;
    else {
        int x = p[rand() / (RAND_MAX / n)].x;

        Person* p1 = new Person[n];
        Person* p2 = new Person[n];
        Person* p3 = new Person[n];
        int i1 = 0, i2 = 0, i3 = 0;

        for(int i = 0; i < n; i++) {
            if(p[i].x > x) {
                p1[i1] = p[i];
                i1 += 1;
            }
            else if(p[i].x < x) {
                p2[i2] = p[i];
                i2 += 1;
            }
            else {
                p3[i3] = p[i];
                i3 += 1;
            }
        }

        p1 = quicksort(p1, i1);
        p2 = quicksort(p2, i2);
        p3 = quicksortName(p3, i3);

        for(int i = 0; i < i1; i++) {
            p[i] = p1[i];
        }

        for(int i = i1, j = 0; j < i3; i++, j++) {
            p[i] = p3[j];
        }

        for(int i = i1 + i3, j = 0; j < i2; i++, j++) {
            p[i] = p2[j];
        }

        delete[] p1;
        delete[] p2;
        delete[] p3;

        return p;
    }
}

int* quicksortX(int* p, int n) {
    if(n < 2) return p;
    else {
        int x = p[rand() / (RAND_MAX / n)];

        int* p1 = new int[n];
        int* p2 = new int[n];
        int* p3 = new int[n];
        int i1 = 0, i2 = 0, i3 = 0;

        for(int i = 0; i < n; i++) {
            if(p[i] > x) {
                p1[i1] = p[i];
                i1 += 1;
            }
            else if(p[i] < x) {
                p2[i2] = p[i];
                i2 += 1;
            }
            else {
                p3[i3] = p[i];
                i3 += 1;
            }
        }

        p1 = quicksortX(p1, i1);
        p2 = quicksortX(p2, i2);


        for(int i = 0; i < i1; i++) {
            p[i] = p1[i];
        }

        for(int i = i1, j = 0; j < i3; i++, j++) {
            p[i] = p3[j];
        }

        for(int i = i1 + i3, j = 0; j < i2; i++, j++) {
            p[i] = p2[j];
        }

        delete[] p1;
        delete[] p2;
        delete[] p3;

        return p;
    }
}

int main() {
    std::srand(std::time(NULL));
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);


    int t;
    int n, p;

    Person person;

    std::cin >> t;
    for(int i = 0; i < t; i++) {
        Person* people;
        std::cin >> n >> p;
        people = new Person[p];
        int x[n];
        for(int j = 0; j < p; j++) {
            std::cin >> people[j].name >> people[j].x;
            x[j] = people[j].x;
        }
        quicksort(people, p);
        for(int j = p; j < n; j++) {
            std::cin >> person.name >> person.x;
            x[j] = person.x;
            if(person.x > people[p - 1].x) {
                people[p - 1].x = person.x;
                people[p - 1].name = person.name;
            }
            else if(person.x == people[p - 1].x && person.name < people[p - 1].name) {
                people[p - 1].x = person.x;
                people[p - 1].name = person.name;
            }
            quicksort(people, p);
        }

        quicksortX(x, n);

        long res = 0;
        for(int j = 0; j < n; j++) {
            res += 1 + j * x[j];
        }
        for(int j = 0; j < p; j++) {
            std::cout << people[j].name << " ";
        }
        std::cout << "\n";
        std::cout << res % 1000003;
        std::cout << "\n"; 
        delete[] people;
    }

    return 0;
}