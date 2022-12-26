#include <iostream>
#include <string>
using namespace std;

void dice(string param) {
    string getNum="";
    int diceGran = 0;
    int dicePlus = 0;
    int diceCount=1;
    bool additorEst = false;
    int result=0;
    for (int i = 0; i <= param.size(); i++) {
        if (param[i] == 'к') {
            diceCount = stoi(getNum);
            getNum = "";
        } 
        if (param[i] == '+') { 

            diceGran = stoi(getNum);
            getNum = ""; 
            additorEst = true;
        }else if(!additorEst&& param[i] == ','|| i== param.size()) {
            diceGran = stoi(getNum);
            for (int i = 0; i < diceCount; i++) {
                int newValue;
                newValue = rand() % diceGran +1;
                result += newValue;
            }
            result += dicePlus;
            if (diceCount == 1) {
                cout << "куб к" << diceGran << " --> " << result << endl;
            }
            else {
                cout << diceCount << " кубиков к" << diceGran << " --> " << result << endl;
            }
            getNum = "";
        }
        if (additorEst && param[i] == ',') {
            dicePlus = stoi(getNum);

            getNum = "";
            for (int i = 0; i < diceCount; i++) {
                int newValue;
                newValue = rand() % diceGran + 1;
                result += newValue;
            }
            result += dicePlus;
            if (diceCount == 1) {
                cout << "кубик к" << diceGran << "+" << dicePlus << " --> " << result << endl;
            }
            else {
                cout << diceCount << " кубиков к" << diceGran << "+" << dicePlus << " --> " << result << endl;
            }
            dicePlus = false;
        }
        if (param[i] == ',' || param[i] == 'к') {
          
        }
        else {
            getNum += param[i];
        }
    }
}




int main()
{
 
    system("chcp 1251>nul");
    srand(time(NULL));
    dice("2к6+2,1к10");
}

