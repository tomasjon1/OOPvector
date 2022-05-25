#include <iostream>
#include "CustomVectorLib.h"
#include <vector>
#include <chrono>

using std::cout;
using std::endl;

void CustomVectorPushBack(int size);
void StdVectorPushBack(int size);

void Swap();
void IsEqual();
void ShrinkToFit();
void Crend();
void Emplace();


std::chrono::steady_clock::time_point clockStart;

int main()
{
    int sizes[5] = { 10000, 100000, 1000000, 10000000, 100000000 };

    for (int i = 0; i < 5; i++)
    {
        CustomVectorPushBack(sizes[i]);
        StdVectorPushBack(sizes[i]);
    }

    cout << endl;
    Swap();
    cout << endl;
    IsEqual();
    cout << endl;
    ShrinkToFit();
    cout << endl;
    Crend();
    cout << endl;
    Emplace();
}

void CustomVectorPushBack(int size) {
    clockStart = std::chrono::steady_clock::now();

    int n = 0;
    CustomVector<int> vect;

    for (int i = 0; i < size; i++)
        vect.push_back(i);

    double timeTaken = std::chrono::duration<double>(std::chrono::steady_clock::now() - clockStart).count();
    cout << "CustomVector - " << size << " - veiksmai truko " << timeTaken << "s." << endl;
}

void StdVectorPushBack(int size) {
    clockStart = std::chrono::steady_clock::now();

    int n = 0;
    std::vector<int> vect;

    for (int i = 0; i < size; i++)
        vect.push_back(i);

    double timeTaken = std::chrono::duration<double>(std::chrono::steady_clock::now() - clockStart).count();
    cout << "std::vector - " << size << " - veiksmai truko " << timeTaken << "s." << endl;
}

void Swap() {
    cout << endl;
    CustomVector<int> v1(3, 100);   // three ints with a value of 100
    CustomVector<int> v2(5, 200);   // five ints with a value of 200

    v1.swap(v2);

    cout << "Swap funkcijos rezultatai: " << endl;
    cout << "v1 vektoriaus reiksmes:";
    for (unsigned i = 0; i < v1.size(); i++)
        cout << ' ' << v1[i];
    cout << '\n';

    cout << "v2 vektoriaus reiksmes:";
    for (unsigned i = 0; i < v2.size(); i++)
        cout << ' ' << v2[i];
    cout << '\n';

    cout << "Laukiamas rezultatas:" << endl << "v1: 200 200 200 200 200" << endl << "v2: 100 100 100" << endl << endl;
}

void IsEqual() {
    unsigned int i;
    CustomVector<int> v1(3, 1);   // three ints with a value of 100
    CustomVector<int> v2(3, 1);   // five ints with a value of 200

    if (v1 == v2)
        cout << "Vektoriai lygus" << endl;
    else
        cout << "Vektoriai nera lygus" << endl;
}

void ShrinkToFit() {
    CustomVector<int> v(100);
    cout << "Vektoriaus dydis ji sukurus: " << v.capacity() << '\n';

    v.resize(10);
    cout << "Vektoriaus dydis ji resize'inus: " << v.capacity() << '\n';

    v.shrink_to_fit();
    cout << "Vektoriaus dydis panaudojus shrink_to_fit: " << v.capacity() << '\n';

    cout << "Laukiamas rezultatas:"
        << endl << "1: 100"
        << endl << "2: 100"
        << endl << "3: 10" << endl << endl;
}

void Crend() {
    CustomVector<int> v = { 1,2,3,4,5 };

    cout << "Crend rezultatai: ";
    for (auto rit = v.crbegin(); rit != v.crend(); ++rit)
        cout << ' ' << *rit;
    cout << '\n';

    cout << "Laukiamas rezultatas: 5 4 3 2 1" << endl << endl;
}

void Emplace() {
    CustomVector<int> v = { 10,20,30 };

    auto it = v.emplace(v.begin() + 1, -1);
    v.emplace(it, -2);
    v.emplace(v.end(), -3);


    cout << "Emplace funkcijos rezultatai: ";
    for (auto& x : v)
        cout << ' ' << x;
    cout << '\n';

    cout << "Laukiami rezultatai: 10 -2 -1 20 30 -3" << endl << endl;
}