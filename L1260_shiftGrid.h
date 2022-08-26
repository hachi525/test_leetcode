//
// Created by admin on 2022/7/20.
//

#ifndef PROJECT_L1260_SHIFTGRID_H
#define PROJECT_L1260_SHIFTGRID_H
#ifndef _L1260_shiftGrid_H_
#define _L1260_shiftGrid_H_


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class L1260_shiftGrid {
public:
    vector<vector<int> >shiftGrid(vector<vector<int> >& grid, int k);
    vector<vector<int> >shiftGrid1(vector<vector<int> >& grid, int k);
    void shif(vector<vector<int> >& grid);
};


#endif //_L1260_shiftGrid_H_
#endif //PROJECT_L1260_SHIFTGRID_H
