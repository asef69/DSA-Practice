#include <bits/stdc++.h>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

long merge(vector<int>& arr, vector<int>& temp, int left, int mid, int right){
    long count = 0;
    int i = left, j = mid + 1, k = left;
    
    while((i <= mid) && (j <= right)){
        if(arr[i] <= arr[j]){
            temp[k++] = arr[i++];
        }
        else{
            temp[k++] = arr[j++];
            count += (mid - i + 1);
        }
    }
    
    while(i <= mid){
        temp[k++] = arr[i++];
    }
    
    while(j <= right){
        temp[k++] = arr[j++];
    }
    
    for(int idx = left; idx <= right; idx++){
        arr[idx] = temp[idx];
    }
    
    return count;
}

long mergeSort(vector<int>& arr, vector<int>& temp, int left, int right){
    long count = 0;
    if(left < right){
        int mid = left + (right - left) / 2;
        count += mergeSort(arr, temp, left, mid);
        count += mergeSort(arr, temp, mid + 1, right);
        count += merge(arr, temp, left, mid, right);
    }
    return count;
}

long countInversions(vector<int> arr) {
    vector<int> temp(arr.size());
    return mergeSort(arr, temp, 0, arr.size() - 1);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);
    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(cin, n_temp);
        int n = stoi(ltrim(rtrim(n_temp)));

        string arr_temp_temp;
        getline(cin, arr_temp_temp);
        vector<string> arr_temp = split(rtrim(arr_temp_temp));

        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            arr[i] = stoi(arr_temp[i]);
        }

        long result = countInversions(arr);
        fout << result << "\n";
    }

    fout.close();
    return 0;
}

string ltrim(const string &str) {
    string s(str);
    s.erase(s.begin(), find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));
    return s;
}

string rtrim(const string &str) {
    string s(str);
    s.erase(find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(), s.end());
    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;
    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));
        start = end + 1;
    }
    tokens.push_back(str.substr(start));
    return tokens;
}