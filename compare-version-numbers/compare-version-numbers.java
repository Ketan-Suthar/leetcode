class Solution {
    public int compareVersion(String version1, String version2)
    {
        String[] v1tokens = version1.split("\\.");
        String[] v2tokens = version2.split("\\.");
        int len = Math.max(v1tokens.length, v2tokens.length);
        
        for(int i=0; i<len; ++i)
        {
            Integer n1 = i < v1tokens.length ? Integer.parseInt(v1tokens[i]) : 0;
            Integer n2 = i < v2tokens.length ? Integer.parseInt(v2tokens[i]) : 0;
            
            int compare = n1.compareTo(n2);
            if(compare !=0)
                return compare;
        }
        return 0;
    }
}