class Solution {
public:
 vector<vector<int>> rects;
    vector<double> weights;
    double totalWeight;
    default_random_engine generator;
    Solution(vector<vector<int>>& rects) {
         this->rects = rects;
        totalWeight = 0;
        for (const auto& rect : rects) {
            int x1 = rect[0], y1 = rect[1], x2 = rect[2], y2 = rect[3];
            double weight = (x2 - x1 + 1) * (y2 - y1 + 1);
            weights.push_back(weight);
            totalWeight += weight;
        }
        for (auto& weight : weights) {
            weight /= totalWeight;
        }
    }
    
    vector<int> pick() {
         uniform_real_distribution<double> distribution(0.0, 1.0);
        double randomWeight = distribution(generator);
        
        double cumulativeWeight = 0.0;
        int chosenRectIdx = 0;
        for (int i = 0; i < rects.size(); ++i) {
            cumulativeWeight += weights[i];
            if (randomWeight <= cumulativeWeight) {
                chosenRectIdx = i;
                break;
            }
        }
        
        int x1 = rects[chosenRectIdx][0], y1 = rects[chosenRectIdx][1];
        int x2 = rects[chosenRectIdx][2], y2 = rects[chosenRectIdx][3];
        
        uniform_int_distribution<int> xDistribution(x1, x2);
        uniform_int_distribution<int> yDistribution(y1, y2);
        
        int x = xDistribution(generator);
        int y = yDistribution(generator);
        
        return {x, y};
    }
};