class Solution {
public:

    bool isPrime(int num) {
        // This will cause any num value less than 2 to return false
        if (num < 2) {
            return false;
        }
        // This will cause the value to be false if num is equal to two
        if (num == 2) {
            return true;
        }
        // This will cause any num value % 2 to return false if it equals 0
        if (num % 2 == 0) {
            return false;
        }
        //Loop will until the factor times itself is greater than the input number, and increments by 2 to keep the factor value odd.
        for (int factor = 3; factor * factor <= num; factor += 2) {
            //if num % and odd number equals 0 it will return false
            if (num % factor == 0) {
                return false;
            }
        }
        // if none above are true then the return value will be true.
        return true;
    }

    vector<int> constructRectangle(int area) {
        vector<int> arr;
        int root1 = sqrt(area);
        int root2 = sqrt(area);
        if (root1 * root1 == area) {
            arr.push_back(root1);
            arr.push_back(root1);
            return arr;
        }
        if (isPrime(area)) {
            arr.push_back(area);
            arr.push_back(1);
            return arr;
        }
        else {
            while (root2 > 1) {
                if (area % root2 == 0) {
                    arr.push_back(area / root2);
                    arr.push_back(root2);
                    break;
                }
                root2--;
            }
        }
        return arr;
    }

};