vector<int> matchingStrings(vector<string> strings, vector<string> queries) {

   std::vector<int> v1;
   std::map<string,int>mp;
   for(auto it:strings)
   {
       mp[it]++;
   }
   for(auto it:queries)
   {
       v1.push_back(mp[it]);
   }
   return std::vector<int> (v1.begin(),v1.end());
}
