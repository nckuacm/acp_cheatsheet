#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>

int main(){
    std::map<std::string,int> conquest;
    std::map<std::string,int>::iterator map_it;

    std::string str("");
    int c;
    std::getline(std::cin,str);
    c = atoi(str.c_str());
    for(int i=0;i<c;i++){
        std::getline(std::cin,str);
        // printf("%s\n",str.c_str());
        // get first
        char *tok = std::strtok(&str[0]," ");
        std::string country(tok);
        conquest[country]++;
    }

    for(map_it=conquest.begin(); map_it != conquest.end(); ++map_it)
        printf("%s %d\n",map_it->first.c_str(),map_it->second);

    return 0;
}