#include<bits/stdc++.h>
using namespace std;
/*class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {   brute force TLE
        int n = nums.size();
        /*vector<int> diff;
        for(int i = 0 ;i<n;i++){    //O(n2) + o(nlogn)
            for(int j = i+1 ;j<n;j++){
                diff.push_back(abs(nums[i] - nums[j]));
            }
        }
        sort(diff.begin() , diff.end());
        return diff[k-1];
};*/

/*class Solution {   //using heap but TLE     O(n2 * log k)   sc - O(k)
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        priority_queue<int> pq;
        int n = nums.size();
        for(int i = 0 ;i<n;i++){
            for(int j = i+1 ;j<n;j++){
                pq.push(abs(nums[i] - nums[j]));
                while(pq.size() > k){
                    pq.pop();
                }
            }
        }
        return pq.top();
    }
};*/

/*class Solution {   
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        int maxi = 0;
        for(int i = 0 ;i<n;i++){
            maxi = max(maxi,nums[i]);
        }
        vector<int> absDiff(maxi+1,0);

        for(int i = 0 ;i<n;i++){
            for(int j = i+1 ;j<n;j++){
                int x = abs(nums[i] - nums[j]);
                absDiff[x]++;
            }
        }

        for(int i = 0 ;i<maxi+1;i++){
            k-=absDiff[i];
            if(k <= 0){
                return i;
            }
        }
        return -1;
    }
};*/

//optimal approach....


int noOfValidPairs(vector<int>& nums,int k1,int n){
    int cnt = 0;
    int i = 0,j=1;
    while(j<n){
        while(nums[j] - nums[i] > k1){
            i++;
        }
        cnt +=(j-i);j++;
    }
    return cnt;
}


class Solution {   //Tc - O(nlogn) + O(log(high) * n) || sc - O(1)
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin() , nums.end());
        int low = 0;
        int high = nums[n-1] - nums[0];
        int ans =-1;
        while(low<=high){
            int mid = (low + high)/2;
            if(noOfValidPairs(nums,mid,n) < k){
                low = mid+1;
            }
            else{
                ans = mid;
                high = mid-1;
            }
        }
        return ans;
    }
};

int main(){
    vector<int> nums ={2,2,0,1,1,0,0,1,2,0};
    Solution s ;
    int k = 2;
    int ans = s.smallestDistancePair(nums,k);
    cout<<ans<<endl;
    return 0;
}