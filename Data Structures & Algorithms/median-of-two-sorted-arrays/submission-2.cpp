class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int med1 = 0, med2 = 0;
        int size1 = nums1.size(), size2 = nums2.size();
        int i = 0, j = 0;
        for(int count = 0; count < (size1+size2)/2 + 1; ++count){
            med2 = med1;
            if(i < size1 && j < size2){
                if(nums1[i]>nums2[j]){
                    med1 = nums2[j];
                    j++;
                }
                else{
                    med1 = nums1[i];
                    i++;
                }
            }else if(i < size1){
                med1 = nums1[i];
                i++;
            }else{
                med1 = nums2[j];
                j++;
            }

        }
        if((size1+size2)%2 == 1){
            return (float)med1;
        }
        else{
            return (float)(med1 + med2)/2.0;
        }
    }
};
