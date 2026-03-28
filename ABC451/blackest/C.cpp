#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

int main(){
    int Q;
    priority_queue<int> result;
    cin >> Q;
    for(int i = 0; i < Q; i++){
       int command, height;
       cin >> command >> height;
       if(command == 1){
           result.push(-height);
       }
       else{
           while(!result.empty() && -result.top() <= height){
               result.pop();
           }
       }
       cout << result.size() << "\n";
    }

    return 0;
}