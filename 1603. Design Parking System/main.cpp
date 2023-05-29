class ParkingSystem {//TC:O(1)  SC:O(N)
public:
    unordered_map<int,int>parking;
    ParkingSystem(int big, int medium, int small) {
        parking[1] = big;
        parking[2] = medium;
        parking[3] = small;
    }
    
    bool addCar(int carType) {
        bool res = false;
        if(parking[carType]) {
            res = true;
            parking[carType]--;
        }
        return res;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
