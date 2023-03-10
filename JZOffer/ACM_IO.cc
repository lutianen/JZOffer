#include <iostream>
#include <vector>
#include <string>

using std::string;
using std::vector;
using std::cout;
using std::cin;

// 只有一个或几个输入
void solution_1 () {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);


    int a, b, c;
    std::cin >> a >> b >> c;
    
    // op
    int res = a + b + c;

    std::cout << res<< "\n";
}


// 先给出行数 N ，再给出 N 行
void solution_2 () {
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int N;
    std::cin >> N;
    vector<int> res;
    while (N-- > 0) {
        int a, b, c;
        cin >> a >> b >> c;
        // op
        res.push_back(a + b + c);
    }

    for (auto e : res) {
        cout  << e << '\n';
    }
}

// 多组输入，读到文件结束符 EOF 为止
void solution_3 () {
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int a, b;
    vector<int> res;

    // cin 读到有数据输入时会返回非 0
    // 读到文件结束符时会返回 0，结束 while
    while(cin >> a >> b) {
        res.push_back(a + b);
    }

    for (auto e : res) {
        cout << e << '\n';
    }
}

// 字符串的输入
//  - C/C++ 中读入的字符串包括 '\0'，我们需要的字符数组的长度要比真正的字符数加一
//  - cin 和 scanf 两种读入方式都会忽略行首和行尾的空格
void solution_4 () {
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;

    cout << s << std::endl;
}

// cin.getline()
// - cin.getline() 实际上由三个参数，cin.getline(接收字符串的变量， 接收字符个数， 结束字符)
// - 当第三个参数省略时，系统默认为 '\0'
void solution_5() {
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    char m[20];
    cin.getline(m, 5);
    cout << m << std::endl;

    // 第三个参数的优先级更高
    cin.getline(m, 10, '4');
    cout << m << '\n';
}

void solution_6() {
    string str;
    std::getline(cin, str);

    cout << str << '\n';
}

int main() {
    // solution_1();
    // solution_2();
    // solution_3();
    // solution_4();
    // solution_5();
    solution_6();
}