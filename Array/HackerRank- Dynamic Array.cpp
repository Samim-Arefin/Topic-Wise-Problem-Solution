vector<int> dynamicArray(int n, vector<vector<int>> queries) {
   std::vector<int>v1;
   std::vector<int> arr[n];
   int lastAnswer=0;
   for(int i=0;i<queries.size();i++)
   {
       if(queries[i][0]==1)
       {
           int index=((queries[i][1]^lastAnswer)%n);
           arr[index].push_back(queries[i][2]);
       }
       else if(queries[i][0]==2)
       {
           int index=((queries[i][1]^lastAnswer)%n);
           lastAnswer=arr[index][(queries[i][2]%arr[index].size())];
           v1.push_back(lastAnswer);
       }
   }
   return std::vector<int> (v1.begin(),v1.end());
}
