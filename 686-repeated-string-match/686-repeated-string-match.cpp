#define BASE 29
#define mod 10000000

class Solution {
    bool robinKarp(string& source, string& toFind) {
        if(source == toFind) return true;
        int lenT = toFind.length();
        int mostSig = 1;
        
        int toFindHash = 0;
        for(int i = 0; i < lenT; i++) {
            mostSig = (mostSig*BASE) % mod;
            toFindHash = (toFindHash*BASE + toFind[i])%mod;
        }
        
        int curHash = 0;
        
        for(int i = 0; i < source.length(); i++) {
            curHash = (curHash*BASE + source[i])%mod;
            if(i < lenT-1) continue;
            if(i >= lenT) {
                curHash = (curHash - mostSig*source[i-lenT])%mod;
            }
            
            if(curHash < 0) curHash += mod;
            if(curHash == toFindHash) {
                if(source.substr(i - lenT + 1, lenT) == toFind) return true;
            }
        }
        
        return false;
    }
public:
    int repeatedStringMatch(string a, string b) {
        if(a == b) return 1;
        string source = "";
        
        int count = 0;
        while(source.length() < b.length()) {
            source.append(a);
            count++;
        }
        
        if(robinKarp(source, b)) return count;
        source.append(a);
        count++;
        if(robinKarp(source, b)) return count;
        
        return -1;
    }
};