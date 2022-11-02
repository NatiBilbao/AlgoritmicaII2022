#include <vector>
#include <climits>

using namespace std;

int LIS(vector<int> const &arr){

    int n = arr.size();

    if (n == 0){
        return 0;
    }

    int L[n] = { 0 };

    L[0] = 1;

    for (int i = 1; i < n; i++){

        for (int j = 0; j < i; j++){

            if (arr[j] < arr[i] && L[j] > L[i]){
                L[i] = L[j];
            }
        }

        L[i]++;
    }

    int lis = INT_MIN;

    for (int x: L){
        lis = max(lis, x);
    }

    return lis;
}

int main(){

    vector<int> arr = { 0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15 };

    cout << "La longitud de la LIS es " << LIS(arr);

    return 0;
}
