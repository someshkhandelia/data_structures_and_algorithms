#include <bits/stdc++.h>

using namespace std;

// ************* All the typedefs *************************
typedef long long ll              ;    // long long
typedef string str                ;    // string

typedef list<int> lint            ;    // list of integers
typedef list<char> lchar          ;    // list of chars
typedef list<ll> llong            ;    // list of long long
typedef list<str> lstr            ;    // list of strings

typedef map<int, int> mii         ;    // map of integer-integer
typedef map<ll, ll> mll           ;    // map of long long-long long
typedef map<int, str> mis         ;    // map of integer-string
typedef map<ll, str> mls          ;    // map of long long-string
typedef map<str, int> msi         ;    // map of string-integer
typedef map<str, ll> msl          ;    // map of string-long long

typedef pair<int, int> pii        ;    // pair of integer-integer
typedef pair<ll, ll> pll          ;    // pair of long long-long long
typedef pair<int, str> pis        ;    // pair of integer-string
typedef pair<ll, str> pls         ;    // pair of long long-string
typedef pair<str, int> psi        ;    // pair of string-integer
typedef pair<str, ll> psl         ;    // pair of string-long long

typedef set<int> sint             ;    // set of integers
typedef set<char> schar           ;    // set of chars
typedef set<ll> slong             ;    // set of long long
typedef set<str> sstr             ;    // set of strings

typedef vector<int> vint          ;    // vector of integers
typedef vector<char> vchar        ;    // vector of chars
typedef vector<ll> vlong          ;    // vector of long long
typedef vector<str> vstr          ;    // vector of strings
// ************** Insert code here ************************


pll take_input(ll x){
    cout << "Please enter weight and value of item " << x << ": ";
    ll weight, val;
    cin >> weight >> val;
    return make_pair(weight, val);
}


ll knapsack(ll n, mll weights, mll vals, ll total_weight){
    vector<vlong> ks_arr(n+1, vlong(total_weight+1, 0));

    for(auto item = 1; item <= n; item++){
        for(auto weight = 1; weight <= total_weight; weight++){

            if(weights[item] > weight){
                ks_arr[item][weight] = ks_arr[item-1][weight];
            }
            else{
                ks_arr[item][weight] = max(vals[item] + ks_arr[item-1][weight-weights[item]], ks_arr[item-1][weight]);
            }
        }
    }

    cout << "\nThe following items (weight, val) were chosen:" << endl;

    ll item = n;
    ll weight = total_weight;

    while(item >= 1 and weight > 0){

        ll curr_val = ks_arr[item][weight];
        ll val_without_item = ks_arr[item-1][weight];

        if (curr_val != val_without_item){
            cout << weights[item] << "," << vals[item] << endl;
            weight = weight-weights[item];
            item--;
        }
        else{
            item--;
        }
    }

    return ks_arr[n][total_weight];
}


int main(void){
    cout << "Please enter maximum knapsack weight: ";
    ll total_weight;
    cin >> total_weight;

    cout << "Please enter number of elements: ";
    ll n;
    cin >> n;

    mll weights;
    mll vals;
    for(auto i=1; i<=n; i++){
        pll weight_val = take_input(i);
        weights.insert(make_pair(i, weight_val.first));
        vals.insert(make_pair(i, weight_val.second));
    }

    ll result = knapsack(n, weights, vals, total_weight);

    cout << "\nThe maximum obtainable value within weight " << total_weight << " is " << result << endl;

    return 0;
}

