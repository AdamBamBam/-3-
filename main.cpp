#include <iostream>
#include "array.h"

using namespace std;


int main()
{
    /*
    Array arr;
    arr.setValue(6);
    arr.setValue(60);
    arr.setValue(40);
    arr.showElements();
    cout << "\n" << endl;
    int sunchez[5] = { 3, 2, 8, 4, 228 };
    arr.setArray(sunchez, 5);
    arr.showElements();
    */
    Array miner;
    miner.setValue(6);
    miner.setValue(60);
    miner.setValue(40);
    
    miner.showElements();
    cout << "\n" << endl;
    //cout << "\n" << endl;

    Array kityk;
    kityk = miner - 2;
    kityk.showElements();
    kityk += 20;
    kityk.showElements();

    kityk++;
    kityk.showElements();
    cout << kityk[2] << endl;
    cout << kityk[11] << endl;
    
    Array master;
    cout << "\n" << endl;
    kityk.showElements();
    miner.showElements();
    cout << "\n" << endl;
    master = kityk + miner + kityk;
    master.showElements();
    //miner.showElements();

    Array miller;
    miller.setValue(6);
    miller.setValue(60);
    miller.setValue(40);
    
    Array steiner;
    steiner.setValue(6);
    steiner.setValue(58);
    steiner.setValue(40);
    steiner.setValue(55);
    steiner.setValue(30);

    miller.showElements();
    steiner.showElements();

    if (miller != steiner) {
        cout << "True" << endl;
    }
    else {
        cout << "Not true" << endl;
    }

    cout << miller << endl;
}