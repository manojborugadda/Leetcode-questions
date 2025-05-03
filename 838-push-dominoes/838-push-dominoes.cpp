class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        vector<int> forces(n, 0);
        
        // Calculate forces from right-pushing dominoes
        int force = 0;
        for (int i = 0; i < n; i++) {
            if (dominoes[i] == 'R') {
                force = n; // Set a high force value
            } else if (dominoes[i] == 'L') {
                force = 0; // No force
            } else if (force > 0) {
                force--; // Reduce force as it propagates
            }
            forces[i] += force;
        }
        
        // Calculate forces from left-pushing dominoes
        force = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (dominoes[i] == 'L') {
                force = n; // Set a high force value
            } else if (dominoes[i] == 'R') {
                force = 0; // No force
            } else if (force > 0) {
                force--; // Reduce force as it propagates
            }
            forces[i] -= force;
        }
        
        // Determine final state of dominoes
        string result;
        for (int i = 0; i < n; i++) {
            if (forces[i] > 0) {
                result += 'R';
            } else if (forces[i] < 0) {
                result += 'L';
            } else {
                result += '.';
            }
        }
        
        return result;
    }
};
