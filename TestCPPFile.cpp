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


static void FillArray(vector<vector<int>>& arr)
{
  // 初始化数组
  if(arr.size() < 9)
  {
    return;
  }
  LineAndRowInfo lineAndRowInfo;
  SqStack<LineAndRowInfo*> stack;
  for(int i = 0; i < 9 ;)
  {
    for (int j = 0; j < 9;)
    {
      if(arr[i][j] == -1)
      {
        lineAndRowInfo.line = i;
        lineAndRowInfo.row = j;
        Get_Position_Value(arr, lineAndRowInfo);
        if(lineAndRowInfo.res.empty())
        {
          LineAndRowInfo* temp;
          // 回溯到上一位置
          stack.Pop(temp);
          i = lineAndRowInfo.line;
          j = lineAndRowInfo.row;
        }
        else
        {
          if(lineAndRowInfo.index >= lineAndRowInfo.res.size())
          {
            LineAndRowInfo* temp;
            // 回溯到上一位置
            stack.Pop(temp);
            i = lineAndRowInfo.line;
            j = lineAndRowInfo.row;
            continue;
          }
          arr[i][j] = lineAndRowInfo.res[lineAndRowInfo.index++];
          stack.Push(&lineAndRowInfo);
          i++;
          j++;
        }
      }
    }
  }
}

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
