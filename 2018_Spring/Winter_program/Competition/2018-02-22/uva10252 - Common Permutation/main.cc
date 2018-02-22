#include <cstdio>
#include <cstdlib>
#include <string>

int main(){
    char c;
    std::string str1(""),str2("");
    int t1[26], t2[26];
    for(int i=0;i<26;i++){
        t1[i]=0;
        t2[i]=0;
    }

    int count=0;
    while(scanf("%c",&c)!=EOF){
        if(c == '\n'){
            count++;
            if(!(count%2)){
                // put them into table
                //printf("str1: %s, str2: %s\n",str1.c_str(),str2.c_str());
                // insert 
                for(int i=0;i<str1.length();i++){
                    t1[(int)str1.c_str()[i]-'a']++;
                }
                for(int i=0;i<str2.length();i++){
                    t2[(int)str2.c_str()[i]-'a']++;
                }
                for(int i=0;i<26;i++){
                    if(t1[i] && t2[i]){
                        if(t1[i] > t2[i]){
                            for(int j=0;j<t2[i];j++){
                                printf("%c",(char)(i+97));
                            }
                        }
                        else{
                            for(int j=0;j<t1[i];j++){
                                printf("%c",(char)(i+97));
                            }
                        }
                    }
                }
                printf("\n");
                // clear
                str1.clear();
                str2.clear();
                for(int i=0;i<26;i++){
                    t1[i]=0;
                    t2[i]=0;
                }
            }
        }
        else{
            if(count%2==1)
                str1+=c;
            else{
                str2+=c;
            }
        }
    }

    return 0;
}