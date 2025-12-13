class Solution {
public:
    int evalRPN(vector<string>& tokens) {
      stack<int> nms;
      int nm1, nm2;
      for (auto &x: tokens){
        if (x == "+" || x == "-" || x == "/" || x == "*"){
          nm2 = nms.top(); nms.pop();
          nm1 = nms.top(); nms.pop();
          if (x == "+")
            nm2 = nm1 + nm2;
          else if (x == "*")
            nm2 = nm1 * nm2;
          else if (x == "-")
            nm2 = nm1 - nm2;
          else if (x == "/")
            nm2 = nm1 / nm2;
        } else {
          nm2 = stoi(x);
        }
        nms.push(nm2);
      }
      return nms.top();
    }
};
