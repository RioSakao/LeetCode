
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


vector<int> FindInterSection(vector<int>&nums1, vector<int>&nums2){
if (nums1.size() > nums2.size()) {
        return FindInterSection(nums2, nums1);
    }
    unordered_map<int, int> m;
    for (auto n : nums1) {
        ++m[n];
    }
    int k = 0;
    for (auto n : nums2) {
        auto it = m.find(n);
        if (it != end(m) && --it->second >= 0) {
            nums1[k++] = n;
        }
    }
    return vector(begin(nums1), begin(nums1) + k);
}


int main() {
  vector<int> res;
  vector<int> nums1{1,2,2,1};
  vector<int> nums2{2,2};

  res = FindInterSection(nums1, nums2);
  
  cout << "[";
  for(unsigned i = 0; i < res.size()-1; ++i) {
    cout << res[i] << ",";
  }//for
  cout << res[res.size()]  << "]";

  return 0;
}
