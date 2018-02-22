#include <cstdio>
#include <cstdlib>
#include <string>

int main()
{
    char c;
    std::string str("");
    int hour=0,minute=0,flag=0;
    while(scanf("%c",&c)!=EOF){
        //printf("%c ",c);
        if(c != ':'){
            str += c;
        }
        else{
            hour = atoi(str.c_str());
            str.clear();
            flag=1;
        }
        if(flag==1 && str.size() == 2){
            minute=atoi(str.c_str());
            str.clear();
            flag=0;
            // TODO: need to check hour, minute range
            if(hour < 0 || hour > 12 || minute < 0 || minute >= 60){
                return 0;
            }
            if(hour == 0 && minute == 0){
                return 0;
            }
            //printf("%d : %d\n",hour,minute);
            // get degree

            float degree = (30)*(float)hour + (30)*((float)minute/60)  - (float)(6)*minute;
            //printf("Before: %f\n",degree);
            if(degree < 0){
                degree = -degree;
                if(degree >= 180)
                    degree = 360 - degree;
            }
            else if(degree >= 180){
                degree = 360 - degree;
            }
            printf("%.3f\n",degree);
        }
    }

    return 0;
}