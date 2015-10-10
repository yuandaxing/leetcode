class Solution {
public:
    bool isPosInteger(const char* s, int l, int r)
    {
        if(l > r) return false;
        for(int i = l; i <= r; i++)
        {
            if(*(s + i) < '0' || *(s + i) > '9') return false;
        }
        return true;
    }
    bool isInteger(const char* s, int l, int r)
    {
        if(*(s + l) == '-' || *(s + l) == '+')
        {
            return isPosInteger(s, l + 1, r);
        }
        return isPosInteger(s, l, r);
    }
    bool isPosFloat(const char* s, int l, int r)
    {
        int il = l;
        int ir;
        int dl;
        int dr;
        for(int i = l; i <= r; i++)
        {
            if(*(s + i) == '.')
            {
                ir = i - 1;
                dl = i + 1;
                dr = r;
                if(il > ir && dl > dr) return false;
                return (il > ir || isPosInteger(s, il, ir)) && 
                       (dl > dr || isPosInteger(s, dl, dr));
            }
        }
        return isPosInteger(s, il, r);
    }
    bool isFloat(const char* s, int l, int r)
    {
        if(*(s + l) == '-' || *(s + l) == '+')
        {
            return isPosFloat(s, l + 1, r);
        }
        return isPosFloat(s, l, r);
    }
    bool isNumber(const char *s) {
        int l = 0;
        while(*(s + l) == ' ')
        {
            l++;
        }
        int r = strlen(s) - 1;
        while(*(s + r) == ' ')
        {
            r--;
        }
        int il = l;
        int ir;
        int dl;
        int dr;
        for(int i = l; i <= r; i++)
        {
            if(*(s + i) == 'e')
            {
                ir = i - 1;
                dl = i + 1;
                dr = r;
                return isFloat(s, il, ir) && isInteger(s, dl, dr);
            }
        }
        return isFloat(s, il, r);
    }
};
