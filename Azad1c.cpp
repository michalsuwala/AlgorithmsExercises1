#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <vector>


struct Car {
    std::string name;
    double p;
    int d;
    long result;
};

bool comp (const Car& car1, const Car& car2)  {
        if (car1.result == car2.result) {
            return car1.name < car2.name;
        }
        return car1.result < car2.result;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    long n;
    std::cin >> n;

    std::vector<Car> cars;
    cars.reserve(3);
    Car car;

    for (int i = 0; i < n; i++) {      
        std::cin >> std::ws;

        if(i < 3) {
            Car res;
            std::getline(std::cin, res.name); 
            std::cin >> res.p >> res.d;
            res.result = long((res.p * 1000) / (0.0254 * res.d * 3.141593));
            cars.emplace_back(res);
            std::sort(cars.begin(), cars.end(), &comp);
        }

        else {
            std::getline(std::cin, car.name); 
            std::cin >> car.p >> car.d;
            car.result = long((car.p * 1000) / (0.0254 * car.d * 3.141593));

            if(comp(car, cars[2])) {
                cars[2].d = car.d;
                cars[2].p = car.p;
                cars[2].name = car.name;
                cars[2].result = car.result;
                std::sort(cars.begin(), cars.end(), &comp);
            }
        }
    }

    for(int i = 0; i < 3; i++) {
        std::cout << cars[i].name << '\n' << cars[i].result << '\n';
    }
    return 0;
}