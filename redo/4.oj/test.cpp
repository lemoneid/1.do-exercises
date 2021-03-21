/*************************************************************************
> File Name: test.cpp
> Author: yanzhiwei
> Mail: 1931248856@qq.com
> Created Time: 2021年03月20日 星期六 13时35分51秒
************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
using namespace std;
class Solution {
    public:
    /**
    * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
    *
    * 
    * @param matrix string字符串 
    * @param rows int整型 
    * @param cols int整型 
    * @param str string字符串 
    * @return bool布尔型
    */
    bool hasPath(string matrix, int rows, int cols, string str) {
        // write code here
        if (rows <= 0|| cols <= 0 || str.size() <= 0) return false;
        int *check = new int[rows * cols];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int idx = i * cols + j;
                if (matrix[idx] == str[0]) {
                    check[idx] = true;
                    if (dfs(i, j, matrix, str, 1, rows, cols, check)) return true;
                    check[idx] = false;
                }
            }
        }
        return false;
    }
    bool dfs(int x, int y, string &matrix,  string &str, int pos, int rows, int cols, int *check) {
        if (pos == str.size()) return true;
        for (int i = 0; i < 4; i++) {
            int xx = x + dir[i][0];
            int yy = y + dir[i][1];
            if (xx < 0 || xx >= rows || yy < 0 || yy >= cols) continue;
            int idx = xx * cols + yy;
            if (check[idx]) continue;
            if (str[pos] == matrix[idx]) {
                check[idx] = true;
                if (dfs(xx, yy, matrix,  str, pos + 1, rows, cols, check)) return true;
                check[idx] = false;
            }

        }
        return false;
    }
    int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
    //vector<vector<bool>> check(rows, vector<bool>(cols, false));
    //vector<vector<char>> arr(rows, vector<char>(cols, false));
};

int main() {
    string s = "ABCESFCSADEE";
    int cols = 3, rows = 4;
    string e = "ABCCED";
    Solution obj;
    cout << obj.hasPath(s, cols, rows, e) << endl;;
    return 0;
}
