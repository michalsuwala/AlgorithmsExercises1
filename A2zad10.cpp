#include <iostream>
#include <cmath>

/*double butelka(double cm) {
    return 10 - (cm - 2) * (cm - 2);
}*/

double volumeBottle(double height) {
    const int n = 1000; 
    double dx = height / n;
    double sum = 0.0;

    for (int i = 0; i <= n; ++i) {
        double x = i * dx;
        double r = butelka(x);
        double area = M_PI * r * r;
        if (i == 0 || i == n) {
            sum += area / 2.0;
        } else {
            sum += area;
        }
    }

    return sum * dx;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    int x, y, z;
    std::cin >> x >> y >> z;
    bool f = false;

    double aquariumVolume = x * y * z;

    double p;
    std::cin >> p;

    double initialWaterVolume = p * aquariumVolume;

    int n;
    std::cin >> n;

    double currentWaterVolume = initialWaterVolume;
    double bottleHeight;
    for (int i = 0; i < n; ++i) {
        std::cin >> bottleHeight;
        double bottleVolume = volumeBottle(bottleHeight);
        currentWaterVolume += bottleVolume;

        if (currentWaterVolume > aquariumVolume) {
            if (!f) std::cout << i + 1 << std::endl;
            f = true;
        }
    }

    if (!f) std::cout << "NIE" << std::endl;
    return 0;
}
