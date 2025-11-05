class Solution {
public:
    int LCM(int n1,int n2) {
        int max = n1 > n2 ? n1 : n2;

        int i = 1;
        do
        {
            int multiple = i * max;
            if(multiple % n1 == 0 && multiple % n2 == 0)
            {
                return multiple;
            }
            i++;
        }while(true);

        return -1;
    }
};