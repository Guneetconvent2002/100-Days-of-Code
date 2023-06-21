class SnapshotArray {
public:
    vector<vector<pair<int, int>>> arr;
    int snapId;

    SnapshotArray(int length) {
        snapId = 0;
        arr = vector<vector<pair<int, int>>> (length, vector<pair<int, int>> (1, {0,0}));
    }
    
    void set(int index, int val) {
        arr[index].push_back({snapId, val});
    }
    
    int snap() {
        return snapId++;
    }
    
    int get(int index, int snap_id) {
        auto it = upper_bound(arr[index].begin(), arr[index].end(), make_pair(snap_id, INT_MAX));
        return prev(it)->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */