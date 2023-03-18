class BrowserHistory {
public:
    vector<string> history;
    int cur;
    BrowserHistory(string homepage) {
        history.push_back(homepage);
        cur = 0;
    }
    
    void visit(string url) {
        // cout<<"removed values from "<<cur+1<<" to "<<history.size();
        int n = history.size();
        for(int i=cur+1; i<n; i++) history.erase(history.begin()+cur+1);
        // cout<<" , n="<<history.size()<<'\n';
        history.push_back(url);
        cur = history.size()-1;
        // cout<<"vis "<<cur<<" , n="<<history.size()<<'\n';
        return;
    }
    
    string back(int steps) {
        // cout<<cur<<"-"<<steps<<"=";
        cur -= steps;
        cur = max(cur, 0);
        // cout<<cur<<" , n="<<history.size()<<'\n';
        return history[cur];
    }
    
    string forward(int steps) {
        // cout<<cur<<"+"<<steps<<"=";
        cur += steps;
        int n = history.size();
        cur = min(cur, n-1);
        // cout<<cur<<" , n="<<n<<'\n';
        return history[cur];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */