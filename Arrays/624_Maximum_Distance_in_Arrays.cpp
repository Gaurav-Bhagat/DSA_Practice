class Solution {
public:
    /*static bool compareVec(vector<int>vec1 , vector<int>vec2){  //brute force....TLE
        return vec1[0]<vec2[0];
    }
    int maxDistance(vector<vector<int>>& arr) {
        sort(arr.begin() , arr.end() ,compareVec); //custom sorting...
        int n = arr.size();
        int x = 0;
        for(int i =0 ;i<n;i++){
            int n1 = arr[i].size();
            for(int j=i+1;j<n;j++){
                int m = arr[j].size();
                x = max(x,abs(arr[i][0] - arr[j][m-1]));
                x = max(x,abs(arr[i][0] - arr[j][0]));
                x = max(x,abs(arr[i][n1-1] - arr[j][0]));
                x = max(x,abs(arr[i][n1-1] - arr[j][m-1]));
            }
        }
        
        return x;
    }*/
    int maxDistance(vector<vector<int>>& arr) {    //TC - O(N)  sc-(1)
        int n = arr.size();
        int small =arr[0][0];
        int big = arr[0].back();
        int ans = 0;
        for(int i = 1;i<n;i++){
            ans = max(ans,abs(arr[i][0] - big));
            ans = max(ans,abs(arr[i].back() - small));

            small = min(small ,arr[i][0]);
            big = max(big,arr[i].back());
        }
        return ans ;
    }
};
