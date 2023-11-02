class Solution {
    public int smallestRangeI(int[] nums, int k) {
        //find max and min element 
        int max, min;
        max=min=nums[0];
        for(int i=0;i<nums.length;i++){
            max=Math.max(max,nums[i]);
            min=Math.min(min,nums[i]);

        }
        // how will be the difference will be minimum
        // when we max=max-k and min=min+k;

        int diff= (max-k)-(min+k);

        return (diff>0) ? diff : 0;

    }
}