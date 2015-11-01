#include<iostream>
#include<stack>
#include<string>
#include<vector>
using namespace std;

void print( vector <string> & v )
{
  for (size_t n = 0; n < v.size(); n++)
    cout << "\"" << v[ n ] << "\"\n";
  cout << endl;
}

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> s;
		vector <string> fields;

		cout << "Original = \"" << path << "\"\n\n";

		  cout << "Split on \'/\' only\n";
		  split(path, '/', fields);
		  //split( fields, s, '/' ) );
		  print( fields );
		  
		cout<<"end\n";
    }
	
};

int main(){
	Solution s;
	s.simplifyPath("/ccc/ddd/d");
	return 0;
}