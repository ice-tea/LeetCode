public class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
        int len = triangle.size();
        int [] d = new int[len];
        
        for(int i=0; i<len; i++) 
            d[i] = triangle.get(len-1).get(i);
        
        for(int i=len-2; i>=0; i--) {
            for(int j=0; j<triangle.get(i).size(); j++) {
                d[j] =triangle.get(i).get(j) + Math.min( d[j], d[j+1]  );                    
            }
        }
        
        return d[0];
    }
}
