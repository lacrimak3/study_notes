#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

struct member{
    int age;
    string name;
    bool operator<(const member &other) const{
        return age < other.age;
    }
};

int n;
member a[100001];
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i].age >> a[i].name;
    }
    stable_sort(a, a + n);
    for(int i = 0; i < n; i++){
        cout << a[i].age << ' ' << a[i].name << '\n';
    }
    return 0;
}