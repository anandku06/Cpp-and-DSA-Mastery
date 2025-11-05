class Solution{
public:
    void swap(int& x, int& y)
    {
        int temp = x;
        x = y;
        y = temp;
    }

    void reverse(int arr[], int n){
        int start = 0, end = n - 1;
        while(start < end)
        {
            swap(arr[start], arr[end]);
            start++;
            end--;
        } 
    }
};
