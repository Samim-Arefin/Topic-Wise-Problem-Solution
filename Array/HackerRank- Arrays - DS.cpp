vector<int> reverseArray(vector<int> a) {

    reverse(a.begin(),a.end());
    return std::vector<int> (a.begin(),a.end());
}
