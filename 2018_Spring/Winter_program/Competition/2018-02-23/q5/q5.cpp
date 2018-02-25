#include <iostream>
#include <map>
using namespace std;
int main()
{
    int N;
    while(cin>>N)
    {
        map<string,int> store;
        string country,temp;
        for(int i=0;i<N;i++)
        {
            cin>>country;
            getline(cin,temp);
            store[country]++;
        }
        for(map<string,int>::iterator it=store.begin();it!=store.end();it++)
        {
            cout<<it->first<<" "<<it->second<<endl;
        }
    }
    return 0;
}
