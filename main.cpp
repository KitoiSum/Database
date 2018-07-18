//
//  main.cpp
//  Databace2.0
//
//  Created by  魏小渺 on 2018/7/18.
//  Copyright © 2018年 weixm. All rights reserved.
//

#include <iostream>
#include "./databace/database.hpp"
#include <sstream>
using namespace std;
int Pair:: total  = 0;

void operations(){
    cout << "'I' for insert;"<<endl;
    cout << "'S' for search;"<<endl;
    cout << "'F' for find range;"<<endl;
    cout << "'D' for delete;"<<endl;
    cout << "'R' for replace;"<<endl;
    cout << "'Q' for quit and save;"<<endl;
}

int main(){
    DB* mydb = new DB();
    cout << "--------------simple-databace----------------"<<endl;
    cout << "---Enter'O' for open existed project.--------"<<endl;
    cout << "---Enter'C' for creat an empty project.------"<<endl;
    cout << "---Enter'H' for operation help when opened---"<<endl;
    cout << ">> ";
    string mode;
    cin >> mode; char coro = mode[0];
    while(true){
        if(coro == 'C' || coro == 'c'){
            mydb->IOcreat();
            break;
        }else if(coro == 'O' || coro == 'o'){
            mydb->IOopen();
            break;
        }else{
            cout << "Invalid input, try again.\n>> ";
            cin  >> mode; coro = mode[0];
        }
    }

    char op = '-';
    while(op != 'Q' && op != 'q' ){
        cout << "Enter oprator: ";
        string input;
        cin >> input;
        op = input[0];
        switch (op) {
            case 'H':case 'h':
                operations();
                break;
            case 'I':case 'i':
                mydb->IOinsert();
                break;
            case 'S':case 's':
                mydb->IOget();
                break;
            case 'F':case 'f':
                mydb->IOrangeGet();
                break;
            case 'D':case 'd':
                mydb->IOremove();
                break;
            case 'R':case 'r':
                mydb->IOreplace();
                break;
            case 'Q':case 'q':
                mydb->save();
                cout << "Bye!" <<endl;
                break;
                
            case 'g':case 'G':
                mydb->save();
                mydb = new DB();
                cout << "this DB has been shut."<<endl;
                break;
            case 'O':case'o':
                mydb->IOcreat();
                break;
                
            default:
                cout << "Invalid operator." << endl;
                break;
        }
    }
}
