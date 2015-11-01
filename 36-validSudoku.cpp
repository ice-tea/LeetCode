#include<iostream>
#include<vector>
#include<set>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char> >& board) {
		set<char> s;
		char c;
		int i=0,j=0,k=0,l=0;
		for(i=0;i<9;++i){
			for(j=0;j<9;++j){
				c = board[i][j];
				if(c!='.'){
					if(s.find(c)!=s.end())
						return false;
					s.insert(c);
				}
			}
			s.clear();
		}
		
		for(i=0;i<9;++i){
			for(j=0;j<9;++j){
				c = board[j][i];
				if(c!='.'){
					if(s.find(c)!=s.end())
						return false;
					s.insert(c);
				}
			}
			s.clear();
		}
		cout<<"last"<<endl;
		for(i=0;i<3;++i){
			for(j=0;j<3;++j){
				for(k=0;k<3;++k){
					for(l=0;l<3;++l){
						c = board[k+i*3][l+j*3];
						if(c!='.'){
							if(s.find(c)!=s.end())
								return false;
							s.insert(c);
						}
					}
				}
				s.clear();
			}
		}
		return true;
    }
};

void print(vector<char> v){
	int size = v.size();
	for(int i=0;i<size;++i){
		cout<<v[i]<<"  ";
	}
	cout<<endl;
}

void print2(vector<vector<char> > v){
	int size = v.size();
	for(int i=0;i<size;++i){
		print(v[i]);
	}
	cout<<endl;
}

int main(){
	
	vector<char> a (9,'.');
	
	vector<char> b (9,'.');
	b[6] = '3';
	
	vector<char> c (9,'.');
	c[3] = '1';
	c[4] = '8';
	
	vector<char> d (9,'.');
	d[3] = '7';
	
	vector<char> e (9,'.');
	e[4] = '1';
	e[6] = '9';
	e[7] = '7';
	
	vector<char> f (9,'.');
	
	vector<char> g (9,'.');
	g[3] = '3';
	g[4] = '6';
	g[6] = '1';
	
	vector<char> h (9,'.');
	
	vector<char> i (9,'.');
	i[7] = '2';
	//".87654321","2........","3........","4........","5........","6........","7........","8........","9........"
	
	vector<vector<char> > v;
	v.push_back(a);
	v.push_back(b);
	v.push_back(c);
	v.push_back(d);
	v.push_back(e);
	v.push_back(f);
	v.push_back(g);
	v.push_back(h);
	v.push_back(i);
	print2(v);
	Solution s;
	if(s.isValidSudoku(v))
		cout<<"true"<<endl;
	else
		cout<<"false"<<endl;
	return 0;
}
/*
int main(){
	
	vector<char> a (9,'.');
	a[1] = '8';
	a[2] = '7';
	a[3] = '6';
	a[4] = '5';
	a[5] = '4';
	a[6] = '3';
	a[7] = '2';
	a[8] = '1';
	
	vector<char> b (9,'.');
	b[0] = '2';
	b[1] = '7';
	
	vector<char> c (9,'.');
	c[0] = '3';
	
	vector<char> d (9,'.');
	d[0] = '4';
	
	vector<char> e (9,'.');
	e[0] = '5';
	
	vector<char> f (9,'.');
	f[0] = '6';
	
	vector<char> g (9,'.');
	g[0] = '7';
	
	vector<char> h (9,'.');
	h[0] = '8';
	
	vector<char> i (9,'.');
	i[0] = '9';
	//".87654321","2........","3........","4........","5........","6........","7........","8........","9........"
	
	vector<vector<char> > v;
	v.push_back(a);
	v.push_back(b);
	v.push_back(c);
	v.push_back(d);
	v.push_back(e);
	v.push_back(f);
	v.push_back(g);
	v.push_back(h);
	v.push_back(i);
	print2(v);
	Solution s;
	if(s.isValidSudoku(v))
		cout<<"true"<<endl;
	else
		cout<<"false"<<endl;
	return 0;
}
*/