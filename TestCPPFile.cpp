struct LineAndRowInfo
{
  // 行
  int line;
  // 列
  int row;
  int index = 0;
  // 待备选的数组
  vector<int> res;
};


static void Get_Position_Value(const vector<vector<int>>& arr, LineAndRowInfo& lineAndRowInfo)
{
   if(lineAndRowInfo.line < 0 || lineAndRowInfo.line >= arr.size())
   {
    return;
   }
   int temp[9] = {1,2,3,4,5,6,7,8,9};
   for(const auto item: arr[lineAndRowInfo.line])
   {
      if(item != -1)
      {
       temp[item - 1] = -1;
      }
   }
   for (const auto& item1 : arr)
   {
      if (item1[lineAndRowInfo.row] != -1)
      {
       temp[item1[lineAndRowInfo.row] - 1] = -1;
      }
   }
   for(int i = 1; i <= 2; i++)
   {
      for (int j = 1; j <= 2; j++)
      {
       if (arr[lineAndRowInfo.line + i][lineAndRowInfo.row + j] != -1)
       {
        temp[arr[lineAndRowInfo.line + i][lineAndRowInfo.row + j]] = -1;
       }
      }
   }
   for (int k = 0; k < 9; k++)
   {
      if(temp[k] != -1)
      {
       lineAndRowInfo.res.push_back(temp[k]);
      }
   }
}
