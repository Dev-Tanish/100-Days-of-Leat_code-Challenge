class Solution {
 public:
  int superEggDrop(int k, int n) {
    vector<vector<int>> mem(k + 1, vector<int>(n + 1, -1));
    return drop(k, n, mem);
  }

 private:

  int drop(int k, int n, vector<vector<int>>& mem) {
    if (k == 0) 
      return 0;
    if (k == 1)  
      return n;
    if (n == 0)  
      return 0;
    if (n == 1)  
      return 1;
    if (mem[k][n] != -1)
      return mem[k][n];


    int l = 1;
    int r = n + 1;

    while (l < r) {
      const int m = (l + r) / 2;
      const int broken = drop(k - 1, m - 1, mem);
      const int unbroken = drop(k, n - m, mem);
      if (broken >= unbroken)
        r = m;
      else
        l = m + 1;
    }

    return mem[k][n] = 1 + drop(k - 1, l - 1, mem);
  }
};