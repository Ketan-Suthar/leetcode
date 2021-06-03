class Solution {
public:
    string simplifyPath(string path)
    {
        int s = path.size();
        
        string res = "";
        
        stack<string> stk;
        int ind = 0;
        
        while(ind < s)
        {
            while(ind < s && path[ind]=='/')
                ++ind;
            
            string name = "";
            
            while(ind < s && path[ind]!='/')
            {
                name.push_back(path[ind]);
                ++ind;
            }
            cout << '\n' << name;
            if(name == ".")
            {
                cout << " in . if";
                continue;
            }
            
            if(name == "..")
            {
                cout << " in .. if";
                if(!stk.empty())
                    stk.pop();
                continue;
            }
            cout << " pushing " + name;
            if(!name.empty())
                stk.push(name);
        }
        if(stk.empty())
            return "/";
        stack<string> temp;
        while(!stk.empty())
        {
            temp.push(stk.top());
            stk.pop();
        }
        res = "/";
        while(!temp.empty())
        {
            string s = temp.top();
            temp.pop();
            res.append(s);
            res.push_back('/');
        }
        
        string str = res.substr(0, res.size()-1);
        return str;
    }
};