#include <iostream>
#include <vector>
using namespace std;

/**
	 当你想首先处理最后一个元素时，栈将是最合适的数据结构。
*/
class MyStack{
private:
	vector<int> data;
public:
	void push(int x){
		data.push_back(x);
	}

	bool isEmpty(){
		return data.empty();
	}

	int top(){
		return data.back();
	}

	bool pop(){
		if (isEmpty())
		{
			return false;
		}
		data.pop_back();
		return true;
	}
};

int main_stack(){
	MyStack s;
	s.push(1);
	s.push(2);
	s.push(3);
	for (int i = 0; i < 4; ++i) {
		if (!s.isEmpty())
		{
			cout << s.top() << endl;
		}
		cout << (s.pop() ? "true" : "false") << endl;
	}

	return 0;
}