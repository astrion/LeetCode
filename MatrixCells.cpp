// 1030. Matrix cells in distance order
#include <algorithm>

class Solution {
private:
    // Driver function to sort the 2D vector
    // on basis of a particular column.
    // in this function, it compares distance(0), rows(1), columns(2)
    // dist(0), rows(1), cols(2)
    static bool sortcol (const vector<int>& v1, const vector<int> v2){
        if (v1[0] == v2[0]){
            if (v1[1] == v2[1])
                return v1[2] < v2[2];
            else
                return v1[1] < v2[1];
        }
        else
            return v1[0] < v2[0];
    }
    
    template<typename T>
    static void pop_front(vector <T>& vec){
        vec.erase(vec.begin());
    }
    
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        
    vector<vector<int>> emptyVect(rows*cols, vector<int> (vector<int> (3, 0)));
    for(int i=0; i<rows; ++i){
        // cout << "[";
        for(int j=0; j<cols; ++j)
        {
            // cout << "[";
            for(int k=0; k<3; ++k)
            {
                // cout << "i*cols+j:" << i*cols+j << " ";
                if(k ==0)
                {
                    if (i==rCenter && j==cCenter)
                        emptyVect[i*cols+j][k] = -1;
                    else
                        emptyVect[i*cols+j][k] = calcDistCoordinates(i, j, rCenter, cCenter);
                }
                else if(k==1)
                {
                    emptyVect[i*cols+j][k] = i;
                    
                }
                else
                {
                    emptyVect[i*cols+j][k] = j;
                }
                // cout << emptyVect[i*cols+j][k] << " ";
            }
            // cout << "]";
        }
        // cout << "]";
    }

    sort(emptyVect.begin(), emptyVect.end(), sortcol);
    cout << endl;

    for(int i=0; i<rows*cols; ++i){
        pop_front(emptyVect[i]);
        // cout << emptyVect[i][0] << " " << emptyVect[i][1] << " ";
    }
    cout << endl;
    
    return emptyVect;
    }
    
    int calcDistCoordinates(int rowNum, int colNum, int rCenter, int cCenter){
        return abs(rowNum-rCenter)+abs(colNum-cCenter);
    }
};
