class MovieRentingSystem {
public:
    typedef pair<int,int> P;

    unordered_map<int, set<P>> available; // movie -> set<{price, shop}>
    unordered_map<int, set<P>> movieToShopPrice; /// movie -> set<shop, price>
    set<tuple<int,int,int>> rented; // {price , shop, movie}

    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for(auto &entry : entries){
            int shop = entry[0];
            int movie = entry[1];
            int price = entry[2];

            available[movie].insert({price, shop});
            movieToShopPrice[movie].insert({shop, price});

        }
    }
    
    vector<int> search(int movie) {
        vector<int> res;
        int cnt = 0;
        if(available.count(movie)){
            for(auto &[price, shop] : available[movie]){
                res.push_back(shop);
                cnt++;

                if(cnt >= 5)
                    break;
            }
        }
        return res;
    }
    
    void rent(int shop, int movie) {
        auto it = movieToShopPrice[movie].lower_bound({shop, INT_MIN});
        int price = it->second;

        available[movie].erase({price, shop});
        rented.insert({price, shop, movie});
    }
    
    void drop(int shop, int movie) {
        auto it = movieToShopPrice[movie].lower_bound({shop, INT_MIN});
        int price = it->second;

        available[movie].insert({price, shop});
        rented.erase({price, shop, movie});
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> res;
        int cnt = 0;
        for(auto &[price, shop, movie] : rented){
            res.push_back({shop, movie});
            cnt++;
            if(cnt >= 5)
                break;
        }
        return res;    
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */
