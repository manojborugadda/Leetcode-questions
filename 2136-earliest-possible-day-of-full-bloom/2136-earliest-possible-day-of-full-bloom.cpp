class Solution { //TC:O(nlogn)  SC:O(N)
    public int earliestFullBloom(int[] plantTime, int[] growTime) {
        List<Seed>plant = new ArrayList<>();
        for(int i = 0;i<plantTime.length;i++) {
            plant.add(new Seed(plantTime[i],growTime[i]));
        }
        
        //sorting  in Decreasing order with respective to GrowTime array
        Collections.sort(plant,(a,b)->(b.growTime - a.growTime));
        
        int time = 0 , max = 0;
        for(int i = 0;i<plantTime.length;i++) {
            time += plant.get(i).plantTime;
            max  = Math.max(max,time + plant.get(i).growTime);
        }
        return max;
    }
    
    private class Seed {
        int plantTime;
        int growTime;
        
        public Seed(int p , int g) {
            this.plantTime = p;
            this.growTime = g;
        }
    }
}