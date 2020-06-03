//Alexander Howes
//820184866
#include <iostream> 
#include <regex> 
#include <fstream>
#include <string>
using namespace std;
int main() 
{
    vector<string> errormessage;
    errormessage.push_back("  <pass>");
    errormessage.push_back("  <assignment does not have semi-colon>");
    errormessage.push_back("  <assignment does not follow (id) (=) (exp)>");
    errormessage.push_back("  <expression does not follow (id) (operator) (id)>");
    errormessage.push_back("  <invalid operator>");
    errormessage.push_back("  <misused parentheses>");
    errormessage.push_back("  <invalid id>");

    vector<string> oper;
    oper.push_back("*");
    oper.push_back("/");
    oper.push_back("-");
    oper.push_back("+");
    oper.push_back("%");
    regex num("0-9");
    regex id("[a-zA-Z][a-zA-Z0-9]+");


    int i, j, h, cmp, semiflag, flag, errorflag;
    size_t found;
    string input, str, c, hold, a, b, d;
    vector<string> data;
    vector<int> par;
    vector<string> ids;
    ifstream file("ex.txt");
    while (getline(file, input)) {
        data.push_back(input);
    }
    //data.size()
    for (j = 0;j < data.size();j++) {
        semiflag = 0;
        flag = 0;
        errorflag = 0;
        str = data[j];
        if (str.empty()) {
            cout << '\n';
        }
        else {
            for (i = 0;i < str.size()-1;i++) {
                while (!isspace(str[i])) {
                    if (i == str.size()) {
                        break;
                    }
                    c = (str[i]);
                    hold.append(c);
                    i++;
                    c.clear();
                }
                ids.push_back(hold);
                hold.clear();
            }
            found = str.find(";");
            if (found != string::npos) {
                ids.push_back(";");
                semiflag = 1;
            }
            //handleing parenthesis
            for (i = 0; i < ids.size();i++) {
                hold = ids[i];
                if (hold == "(") {
                    if (!regex_match(ids[i + 1], id)) {
                        errorflag = 5;
                    }
                    if (find(oper.begin(), oper.end(), ids[i+2]) != oper.end()) {
                        errorflag = 5;
                    }
                    if (!regex_match(ids[i + 3], id)) {
                        errorflag = 5;
                    }
                    if (ids[i+4] != ")") {
                        errorflag = 5;
                    }
                    par.push_back(i);
                    par.push_back(i+1);
                    par.push_back(i+2);
                    par.push_back(i+3);
                    par.push_back(i+4);
                }
                a = hold[0];
                b = "(";
                if (a == b) {
                    for (h = 1;h < hold.size();h++) {
                        hold[h - 1] = hold[h];
                    }
                    for (h = 0;h < ids[i+2].size()-1;h++) {
                        d = ids[i + 2];
                        a = d[i];
                        c.append(a);
                    }
                    if (!regex_match(hold, id)) {
                        errorflag = 5;
                    }
                    if (find(oper.begin(), oper.end(), ids[i + 1]) != oper.end()) {
                        flag = 0;
                    }
                    else{
                        errorflag = 5;
                    }
                    if (!regex_match(c, id)) {
                        errorflag = 5;
                    }
                    par.push_back(i);
                    par.push_back(i + 1);
                    par.push_back(i + 2);
                }
                hold.clear();
            }
            if (errorflag == 0) {
                for (i = 0;i < ids.size();i++) {
                    flag = 0;
                    //handeling expressions
                    if (semiflag == 0) {
                        if (ids[1] == "=") {
                            errorflag = 1;
                            break;
                        }
                        if (find(par.begin(), par.end(), i) != par.end()) {
                            flag = 1;
                        }
                        if (flag == 0 && i % 2 == 0) {
                            if (!regex_match(ids[i], id)) {
                                if (find(oper.begin(), oper.end(), ids[i + 1]) != oper.end()) {
                                    errorflag = 3;
                                    break;
                                }
                                else {
                                    errorflag = 6;
                                    break;
                                }
                            }
                        }
                        if (flag == 0 && i % 2 == 1) {
                            if (find(oper.begin(), oper.end(), ids[i]) != oper.end()) {
                                flag = 0;
                            }
                            else {
                                if (!regex_match(ids[i], id)) {
                                    errorflag = 4;
                                    break;
                                }
                                else{
                                    errorflag = 3;
                                    break;
                                }
                            }
                        }
                    }
                    //handeling assignemnts
                    else {
                        if (ids[i] == "=" && i != 1) {
                            errorflag = 2;
                            break;
                        }
                        if (ids[1] == "=") {
                            flag = 0;
                        }
                        else {
                            errorflag = 2;
                            break;
                        }
                        if (find(par.begin(), par.end(), i) != par.end()) {
                            flag = 1;
                        }
                        else {
                            if (flag == 0 && i % 2 == 0) {
                                if (!regex_match(ids[i], id)) {
                                    if (find(oper.begin(), oper.end(), ids[i]) != oper.end()) {
                                        errorflag = 2;
                                        break;
                                    }
                                    else {
                                        errorflag = 6;
                                        break;
                                    }
                                }
                            }
                            if(flag == 0 && i % 2 == 1) {
                                if (i > 1 ) {
                                    if (find(oper.begin(), oper.end(), ids[i]) != oper.end()) {
                                        flag = 0;
                                    }
                                    else{
                                        if (regex_match(ids[i], id)) {
                                            errorflag = 6;
                                            break;
                                        }
                                        else {
                                            if (i < ids.size() - 1) {
                                                errorflag = 4;
                                                break;
                                            }
                                        }
                                    }
                                }
                            }
                        }    
                    }
                }
            }
            for (i = 0;i < ids.size();i++) {
                cout << ids[i];
            }
            cout << errormessage[errorflag] << '\n';
            ids.clear();
            par.clear();
        }
    }
} 