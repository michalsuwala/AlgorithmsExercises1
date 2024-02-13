#include <iostream>
#include <vector>
#include <algorithm>


struct Place{
    std::string name;
    int dist;

    Place() {}
    Place(std::string n, int d) : name(n), dist(d) {}
};

bool comp(const Place &a, const Place &b) {
    if(a.dist == b.dist) {
        return a.name > b.name;
    }
    return a.dist > b.dist;
}

Place median(std::vector<Place> &places, int n) {
    if(n <= 5) {
        std::sort(places.begin(), places.begin() + n, comp);

        return places[(n - 1) / 2];
    }
    int count = 0;
    for(int i = 0; i < n; i += 5) {
        if(i + 5 < n) {
            std::sort(places.begin() + i, places.begin() + i + 5, comp);
            
            std::swap(places[count], places[i + 2]);
            count++;
        }
        else {
            std::sort(places.begin() + i, places.begin() + n, comp);
            std::swap(places[count], places[i + (n - i - 1) / 2]);
            count++;
        }
    }
    
    return median(places, count); 
}

std::string findK(std::vector<Place> &places, int k, int &limit) {
    if(places.size() <= 10) {
        std::sort(places.begin(), places.end(), comp);
        if(places[k].dist > limit) {
            return "NIE";
        }
        limit -= places[k].dist;
        return places[k].name;
    }

    std::vector<Place> vecB, vecC, vecD;
    Place m = median(places, places.size());
    for(Place p : places) {
        if(p.dist > m.dist || p.name > m.name && p.dist == m.dist) vecB.push_back(p);
        else if(p.name == m.name && p.dist == m.dist) vecC.push_back(p);
        else vecD.push_back(p);
    }
    
    if(k <= vecB.size()) {
        return findK(vecB, k, limit);
    }
    else if(k <= vecB.size() + vecC.size()) {
        if(m.dist > limit) {
            return "NIE";
        }
        limit -= m.dist;
        return m.name;
    }
    else {
        return findK(vecC, k - vecB.size() - vecC.size(), limit);
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<Place> places;


    for(int i = 0; i < n; i++) {
        std::string name;
        int d;
        Place p = Place();
        std::cin >> std::ws;
        std::getline(std::cin, p.name, ' ');
        std::cin >> p.dist;
        p.dist *= 2;
        places.push_back(p);
    }


    int limit, m;
    std::cin >> limit >> m;

    std::vector<int> 🧭(m);

    for(int i = 0; i < m; i++) {
        std::cin >> 🧭[i];
    }

    for(int i = 0; i < 🧭.size(); i++) {
        std::cout << findK(places, 🧭[i], limit) << ' ';
    }

    

    return 0;
}