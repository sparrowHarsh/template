struct StringMatching{
    const ll mode = 1e9+9;
    const ll base1 = 2;
    const ll base2 = 3;

    vector<pair<ll,ll>> hashes,power;

    StringMatching(string &s){
        ll n = s.size();
        hashes.assign(n+1,{1,1});
        power.assign(n+1,{1,1});

        for(ll i=0;i<n;i++){
            hashes[i+1] = {((hashes[i].first * base1) % mode + (s[i]-'a'+1))%mode,((hashes[i].second * base2) %mode + (s[i]-'a'+1))%mode};
            power[i+1] = {(power[i].first * base1) % mode, (power[i].second * base2) % mode};
        }
    }

    pair<ll,ll> get(ll l,ll r){
        l++;
        r++;

        ll hash1 = ((hashes[r].first * power[r].first) % mode - (hashes[r-l+1].first * power[r-l+1].first) %mode + mode) %mode;
        ll hash2 = ((hashes[r].second * power[r].second) % mode - (hashes[r-l+1].second * power[r-l+1].second) %mode + mode) %mode;

        return {hash1,hash2};
    }
};