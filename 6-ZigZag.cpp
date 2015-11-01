#include<string>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        int len = s.size();
		if(len <= 1||numRows==1)
			return s;
		int each = 2*numRows -2;
		int repos = 0;
		char arr[len+1];
		for(int i=0; i<numRows; ++i){
			int j = 0;
			while(i+j*each<len){
				if(i==0||i==numRows-1){
					arr[repos++] = s[i+j*each];
				}
				else{
					arr[repos++] = s[i+j*each];
					if(j*each-i-2+2*numRows < len)
						arr[repos++] = s[j*each-i-2+2*numRows];
				}
				j++;
			}
		}
		arr[repos] = '\0';
		string str(arr);
		return str;
    }
	string convert2(string s, int numRows) {
	    if (numRows < 2) return s;

	    string result;

	    for (int i = 1; i <= numRows; ++i) {
	        bool flag = true;
	        for (int j = i - 1; j < s.size(); ) {
	            result.push_back(s[j]);
	            if (i == 1 || i == numRows) {
	                j += 2 * (numRows - 1);
	            } else {
	                j += 2 * (flag ? (numRows - i) : i - 1);
	                flag = !flag;
	            }
	        }
	    }

	    return result;
	}
};

int main(){
	Solution s;
	string str = s.convert("PAYPALISHIRING", 3);
	printf("%s",str.c_str());
}