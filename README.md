# JZOffer

1. 使用 `0x3F3F3F3F` 来替代最大值，防止运算过程中数值溢出
2. 迭代器的二分

    ```cpp
    std::vector<int> nums{1, 2, 3, 44, 54, 96, 124};
    auto k = std::lower_bound(nums.begin(), nums.end(), 56) - nums.begin();  // k = 5
    k = std::upper_bound(nums.begin(), nums.end(), 36) - nums.begin();  // k = 3
    ```

3. 小根堆

    ```cpp
    std::priority_queue<int> pq; // 默认大根堆
    std::priroity_queue<int, vector<int>, std::greater<int>> pq; // 小根堆
    ```

4. 字符串分割：利用字符流，将旧串`s`塞入流`ss`中，然后读入到新的字符串 `str` 中

    ```cpp
    std::string s = "hello my name is Lute~";
    std::stringstream ss(s);
    std::string str;
    std::vector<std::string> vec;
    while (ss >> str) vec.push_back(str);

    std::cout << vec.size() << std::endl;
    for (const auto& str : vec) {
        std::cout << str << "\n";
    } 
    ```

5. 四舍五入保留小数

    ```cpp
    char str[10];
    double num = 3.1415926;
    sprintf(str, "%.2f", num);
    string s = str;
    cout << s << endl;  // 3.14
    ```

6. 字符串按格式拆分

    ```cpp
    std::string str = "12:34@23";
    int u, v, w;
    sscanf(str.c_str(), "%d:%d@%d", &u, &v, &w);
    std::cout << "u = " << u << ", v = " << v << ", w = " << w << std::endl; // u = 12, v = 34, w = 23
    ```
