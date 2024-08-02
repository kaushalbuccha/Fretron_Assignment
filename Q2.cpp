// Ram , sham and rahim went for shopping apple. They bought apple worth
// 100 rupees. Ram paid 50 rupees, sham paid 30 rupees and rahim paid 20
// rupees. Each apple is tagged with its weight on it. Write a program to
// distribute apples such that the quantity of apple they get is in best
// proportionate to the amount they paid.
// Note : you cannot cut a apple into pieces have to allocate the whole apple to
// one of them.
// For example :
// If there is 8 apple of 400g , 100g , 400g , 300g , 200g , 300g ,100g , 200g
// then we can distribute them as
// Ram : 400g , 400g , 200g (total 1kg , 50%)
// Sham : 300g , 300g (tatal 600g , 30%)
// rahim , 200g , 100g , 100g (tatal 400g , 20%)

// Input:
// Enter apple weight in gram (-1 to stop ) : 400
// Enter apple weight in gram (-1 to stop ) : 100
// Enter apple weight in gram (-1 to stop ) : 400
// Enter apple weight in gram (-1 to stop ) : 300
// Enter apple weight in gram (-1 to stop ) : 200
// Enter apple weight in gram (-1 to stop ) : 300
// Enter apple weight in gram (-1 to stop ) : 100
// Enter apple weight in gram (-1 to stop ) : 200
// Enter apple weight in gram (-1 to stop ) : -1

// Output:
// Ram : 400 400 100
// Sham : 300 , 300
// Rahim : 200 , 100 , 100

#include <bits/stdc++.h>
using namespace std;

struct Person {
    string name;
    int amountPaid;
    int totalWeight;
    vector<int> apples;
};

bool compare(int a, int b) {
    return a > b;
}
bool comp(Person* a,Person* b){
    return (a->totalWeight * b->amountPaid) < (b->totalWeight * a->amountPaid);
}

int main() {
    vector<int> appleWeights;
    int weight;
    
    cout << "Enter apple weight in gram (-1 to stop): ";
    while (cin >> weight && weight != -1) {
        appleWeights.push_back(weight);
        cout << "Enter apple weight in gram (-1 to stop): ";
    }
    
    sort(appleWeights.begin(), appleWeights.end(), compare);
    
    Person ram = {"Ram", 50, 0, {}};
    Person sham = {"Sham", 30, 0, {}};
    Person rahim = {"Rahim", 20, 0, {}};
    
    vector<Person*> people = {&ram, &sham, &rahim};
    
    for (int apple : appleWeights) {
        sort(people.begin(), people.end(),comp);
        people[0]->apples.push_back(apple);
        people[0]->totalWeight += apple;
    }

    cout << "Ram: ";
    for (int apple : ram.apples) cout << apple << " ";
    cout << endl;
    
    cout << "Sham: ";
    for (int apple : sham.apples) cout << apple << " ";
    cout << endl;
    
    cout << "Rahim: ";
    for (int apple : rahim.apples) cout << apple << " ";
    cout << endl;
    return 0;
}

