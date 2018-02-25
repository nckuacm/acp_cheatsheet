#include <iostream>    
#include <map>    
#include <vector>  
  
using namespace std;  
  
map <int, vector<int> > Map;  
  
int main()  
{  
    int n, m, k ,v;  
    while (cin >> n >> m) {  
        Map.clear();  
        for (int i = 0; i < n; ++ i) {  
            cin >> v;  
            Map[v].push_back(i+1);  
        }  
          
        for (int i = 0; i < m; ++ i) {  
            cin >> k >> v;  
            if (Map[v].size() < k)  
                cout << 0 << endl;  
            else cout << Map[v][k-1] << endl;  
        }  
    }  
    return 0;  
}  
