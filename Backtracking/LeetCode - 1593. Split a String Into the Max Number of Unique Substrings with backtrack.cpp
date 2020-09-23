class Solution {
public:
    string str;
    int sz;

    int FuN(int pos , map<string , int>&m)
    {
        if(pos >= sz)
            return 0;
        int ret = 0;
        string temps = "";
        for(int i=pos ; i<sz ; i++){
            temps += str[i];
            if(m[temps] == 0){
                m[temps] = 1;
                ret = max(ret , 1 + FuN(i+1 , m));
                m[temps] = 0;
            }
        }
        return ret;
    }

    int maxUniqueSplit(string s) {
        map<string , int>m;
        str = s;
        sz = (int)s.size();
        return FuN(0 , m);
    }
};
