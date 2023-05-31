class UndergroundSystem {
public:
    unordered_map<int, pair<string, int>> in;
    map<pair<string, string>, double> tim, count;
    UndergroundSystem() {
        tim.clear(); count.clear(); in.clear();
    }
    
    void checkIn(int id, string stationName, int t) {
        in[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        t = t-in[id].second;
        string s = in[id].first;
        double c = count[{s, stationName}];
        double tt = tim[{s, stationName}];
        tt *= c;
        c++;
        tt += t;
        tt /= c;
        count[{s, stationName}]++;
        tim[{s, stationName}] = tt;
        in.erase(id);
        return;
    }
    
    double getAverageTime(string startStation, string endStation) {
        return tim[{startStation, endStation}];
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */