class Bitset {
public:
    string s = "";
    string rev = "";
    int co = 0;
    int n = 100000;
    Bitset(int size) {
        
        n = size;
        s = string(size, '0');
        rev = string(size, '1');
    }
    
    void fix(int idx) {
        if(s[idx] == '0')
            co++;
        s[idx] = '1';
        rev[idx] = '0';
        
    }
    
    void unfix(int idx) {
        if(s[idx] == '1')
            co--;
        s[idx] = '0';
        rev[idx] = '1';
    }
    
    void flip() {
        // string temp = s;
        // s = rev;
        // rev = temp;
        swap(s, rev);
        co = n-co;
    }
    
    bool all() 
    {
        if(co == n)
            return true;
        return false;
    }
    
    bool one() {
        if(co >= 1)
            return true;
        return false;
    }
    
    int count() {
        return co;
    }
    
    string toString() {
        return s;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */