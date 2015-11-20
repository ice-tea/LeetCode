class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int w1 = C-A;
        int w2 = G-E;
        int d1 = D-B;
        int d2 = H-F;
        
        int tmp1 = (w1 + w2 + min(A,E) > max(C,G))?(w1+w2+min(A,E)-max(C,G)):0;
        int tmp2 = (d1 + d2 + min(B,F) > max(D,H))?(d1+d2+min(B,F)-max(D,H)):0;
        //to avoid overflow
        //cout<<w1<<"  "<<w2<<"  "<<d1<<"  "<<d2<<endl;
        //cout<<tmp1<<"  "<<tmp2<<endl;
        return w1*d1 + w2*d2 - tmp1*tmp2;
    }
};
