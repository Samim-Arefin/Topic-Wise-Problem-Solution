vector<int> rotateLeft(int d, vector<int> arr) {
  std::list<int>l(arr.begin(),arr.end());
  while(d--)
  {

      l.push_back(l.front());
      l.pop_front();
  }
  std::vector<int>v1(l.begin(),l.end());
  return std::vector<int> (v1.begin(),v1.end());
}
