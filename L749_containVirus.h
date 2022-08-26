//
// Created by admin on 2022/7/19.
//

#ifndef PROJECT_L749_CONTAINVIRUS_H
#define PROJECT_L749_CONTAINVIRUS_H
#ifndef _L749_containVirus_H_
#define _L749_containVirus_H_

#include <memory>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class L749_containVirus {
private:
    vector<vector<bool> > infected;
public :
    int containVirus(vector<vector<int>>& isInfected);
};


#endif //_L749_containVirus_H_
#endif //PROJECT_L749_CONTAINVIRUS_H
