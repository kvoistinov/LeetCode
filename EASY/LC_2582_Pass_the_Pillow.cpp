//2582. Pass the Pillow
class Solution {
public:
    int passThePillow(int n, int time) {
        int passes    = time / (n - 1);
        int remainder = time % (n - 1);

        return (passes % 2 == 0) ? remainder + 1: n - remainder;
    }
};
