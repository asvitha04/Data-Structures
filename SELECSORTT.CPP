#include<iostream>
using namespace std;

template<typename T>
class sort {
public:
    T arr[10];
    int n, i, j, min, temp;

    void selecsort() {
        for (i = 0; i < n - 1; i++) {
            min = i;
            for (j = i + 1; j < n; j++) {
                if (arr[j] < arr[min]) {
                    min = j;
                }
            }
            if (min != i) {
                temp = arr[i];
                arr[i] = arr[min];
                arr[min] = temp;
            }
        }

        cout << "The sorted array:";
        for (i = 0; i < n; i++) {
            cout << "\t" << arr[i];
        }
        cout << endl;
    }

    void getarr() {
        cout << "Enter the number of elements in the array:";
        cin >> n;
        cout << "Enter the elements:";
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
    }
};

int main() {
    sort<int> in;
    in.getarr();
    in.selecsort();

    sort<float> fl;
    fl.getarr();
    fl.selecsort();

    sort<char> ch;
    ch.getarr();
    ch.selecsort();

    return 0;
}
