// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int begin = 1, end = n;
        int mid ;
        int firstBad = n;
        while(begin <= end)
        {
                mid = begin + ( end - begin) / 2;
                if(isBadVersion(mid))
                {
                        firstBad = mid;
                        end = mid - 1;
                }
                else
                {
                        begin = mid + 1;
                }
        }

        return firstBad;
    }
};
