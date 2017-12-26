//
//  main.cpp
//  hw8 RegEx-Url
//
//  Created by Platon on 25.12.17.
//  Copyright © 2017 Platon. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>
#include <regex>

using namespace std;

int main(int argc, const char * argv[]) {
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    string str;
    regex _regex(R"(^(https?:\/\/)?([\da-z\.-]+)\.([a-z\.]{2,6})([\/\w \.-]*)*\/?$)");
    while (fin>>str){
        if (regex_match(str, _regex)) {
            fout << str << endl;
        }
    }
    return 0;
}
