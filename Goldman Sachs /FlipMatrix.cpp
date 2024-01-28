class Solution {
private:
    vector<int> v;
    int size, M, N;
public:
    Solution(int M, int N): M(M), N(N), size(M * N), v(M * N) {
        for (int i = 0; i < size; ++i) v[i] = i;
        srand(time(NULL));
    }
    
    vector<int> flip() {
        swap(v[rand() % size], v[size - 1]);
        --size;
        return { v[size] / N, v[size] % N };
    }
    
    void reset() {
        size = M * N;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */
