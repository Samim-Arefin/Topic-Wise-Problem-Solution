class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        std::vector<int>v1(nums1.size()+nums2.size());
        merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(),v1.begin());
        double ans=0;
        if(v1.size() & 1)
        {
            ans=v1[v1.size()/2];

        }
        else
        {
            ans=(double)(v1[v1.size()/2]+v1[(v1.size()/2)-1])/2;
        }
        return ans;
    }
};
