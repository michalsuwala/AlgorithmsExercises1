#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin >> n;

    std::string *names = new std::string[n];
    std::string *names2 = new std::string[n];
    int *calories = new int[n];
    int *mod = new int[n];
    int *div = new int[n];
    int *div2 = new int[n];
    int *arr1 = new int[n] {0};
    int *arr2 = new int[n] {0};
    int *arr3 = new int[n] {0};
    int *arr4 = new int[n] {0};


    for(int i = 0; i < n; i++) {
        std::cin >> names[i];
        std::cin >> calories[i];
        mod[i] = calories[i] % n;
        div[i] = calories[i] / n;
        arr1[mod[i]]++;
        arr3[div[i]]++;
    }

    int count = -1;
    for(int i = 0; i < n; i++) {
        count += arr1[i];
        arr2[i] = count;
    }

    std::string temp;
    int tmod;
    int index;
    for(int i = n - 1; i >= 0; i--) {
        index = arr2[mod[i]];
        div2[index] = div[i];
        names2[index] = names[i];
        arr2[mod[i]]--; 
    }

    count = -1;
    for(int i = 0; i < n; i++) {
        count += arr3[i];
        arr4[i] = count;
    }

    for(int i = n - 1; i >= 0; i--) {
        index = arr4[div2[i]];
        names[index] = names2[i];
        arr4[div2[i]]--;  
    }

    for(int i = 0; i < n; i++) {
        std::cout << names[i] << " ";
    }


    delete[] names;
    delete[] names2;
    delete[] calories;
    delete[] mod;
    delete[] div2;
    delete[] div;
    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;

    return 0;
}