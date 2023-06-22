class Solution {
public:
	string reverseWords(string s) {
		string temp = "";
    vector<string> arr;
		for(int i = 0; i < s.size(); i++){
			while(i < s.size() && s[i] != ' '){
				temp += s[i];
				i++;
			}
			if( temp != ""){
				arr.push_back(temp);
				temp = "";
			}
		}

		string res = "";
		for(int i = arr.size() - 1; i >= 0; i--){
			if(i == arr.size() - 1){
				res = arr[i];
			}else res += " " + arr[i];
		}
		return res;
	}
};
