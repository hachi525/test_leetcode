//
// Created by admin on 2022/7/28.
//

#define def_name(...) def_body(__VA_ARGS__)
#include "Test.h"
#define ages 200

class Test{
public:
    int a(int a, int b){
        return a;
    };
};

class mySequence{
private:
    int m_value;
public:
    mySequence(int ivalue):m_value(ivalue){}

    int operator()(){
        return m_value*=2;
    }
};

///测试auto作为函数返回值类型
template<typename _Tx, typename _Ty>
auto multiply(_Tx x, _Ty y)-> decltype( x*y){
    return x*y;
}



void test(){
    /* 测试unordered_map */
    unordered_map<int, int> map;
    map.emplace(1,2);
    cout << " ?"<< map.size();
    map.clear();
    cout << " ?"<< map.size();
    map.emplace(1,2);
    //将键值对3-1插入map前面
    unordered_map<int, int >::iterator iter =  map.emplace_hint(map.begin(),3, 1);
    pair<unordered_map<int,int>::iterator , bool> a = map.emplace(1, 2);
    map.erase(1);
    cout << " ?"<< map.size();
    cout << " \nbucket_count:"<< map.bucket_count() << "\nload_factor:" << map.load_factor() << endl;
    map.rehash(20);
    cout << map.bucket_count() << endl;
    map.reserve(10);

    /* 测试generate()和generate_n()
     * generate(): 用指定函数对象产生的值去给容器指定范围内元素赋值
     * generate_n(): 一个函数对象产生的值给一定的范围内指定数目的容器元素赋值
     * */
    cout << "\n---------------------------\n测试generate_n()：" << endl;
    list<int> tempList;
    tempList.emplace(begin(tempList), 0);
    vector<int> tempV(10);
    generate(tempV.begin(), tempV.begin() + 4, [](){return 5;});
    generate(tempList.begin(), tempList.end(), mySequence(100));
    generate_n(front_inserter(tempList),4,mySequence(-1));
    generate_n(back_inserter(tempList),4,mySequence(1));
    for(list<int>::iterator it = tempList.begin(); it!= tempList.end(); it++){
        cout << *it << ", ";
    }

    /* 测试array */
    array<int, 5> arr{0, 1, 3, 4, 5};
    cout << "\n---------------------------\n测试array: \n"  << get<1>(arr) << ", ";
}


/* 测试函数指针，作为形参传入 */
int fun1(int i, int j){
    cout << i  << j ;
    return 1;
}

void fun2(int (*fun1)(int i, int j), int a){
    (*fun1)(1,2);
}

/* 测试成员变量初始化顺序 */
class Base{
private:
    int  m_i, m_j;
public:
    Base(int i): m_j(i), m_i(m_j){}
    Base():m_j(0), m_i(m_j){}
    int get_i() const{
        return m_i;
    }
    int get_j() const{
        return m_j;
    };
};

/* 统计n二进制中1的个数 */
unsigned popcnt(unsigned n){
    unsigned count = 0;
    while(n){
        count ++;
        n &= (n-1);
    }
    return count;
}

// test：虚基类构造函数中有形参
//class A{
//protected:
//    int a;
//public:
//    A(int s){ a = s; cout << "A.a = " << a << endl; }
//    void showi(){
//        cout << "A.a = " << a << endl;
//    };
//};
//
//class B: virtual public A{
//public:
//    B(int a, int b):A(a){ a += 10; cout << "B.a = " << a << " B结束 " << endl; }
//};
//
//class C : virtual public A{
//public:
//    C(int a):A(a){ a += 15; cout << "C.a = " << a << " C结束 " << endl;}
//};
//
//class D: public B, public C{
//public:
//    D(int a, int b): A(a), B(a, b), C(a){
//        cout << "B::a = " <<  a << endl;
//        cout << "C::a = " <<  a << endl;
//    }
//};



// 虚基类构造函数中没有形参
//class A{
//protected:
//    int a  =5;
//public:
//    A (){  cout << "A.a = " << a << endl; }
//    void showi(){
//        cout << "A.a = " << a << endl;
//    };
//};
//
//class B: virtual public A{
//public:
//    B( ) { a += 10; cout << "B.a = " << a << " B结束 " << endl; }
//};
//
//class C : virtual public A{
//public:
//    C( ){ a += 15; cout << "C.a = " << a << " C结束 " << endl;}
//};
//
//class D: public B, public C{
//public:
//    D( ) {
//        cout << "B::a = " <<  a << endl;
//        cout << "C::a = " <<  a << endl;
//    }
//};


bool testInput(){
    std::string str;
    char delim = ',';
    stringstream ss;
    str = "123, 456";
    ss.str(str);

    /// 测试cin后接getline()时，cin后回车被getline读取的问题
    /* 解决办法：在cin和getline之间使用getline将回车读取 */
    string s1;
    int x;
    cin >> x;
    getline(cin, s1);
    while(x--){
        getline(cin, s1);
        cout << s1 << endl;
    }
    ///测试getline()
    /* 测试while(getline())按行循环输入 */
    // istream& getline ( istream &is , string &str , char delim );
    while(getline(std::cin, str, delim)){
        cout << "str: " << str << endl;
        if(str == "exit") {
            cout << "isequal: " << (str == "exit") << endl;
            break;
        }
        cout << "str's num: " << stoi(str) << ", type: " << typeid(stoi(str)).name() << endl;
    }


    /// 测试stringstream
    /* 1.istringstream
     * 2.ostringstream
     * 3.stringstream
     *  `数据类型转换
     *  `字符串拼接+清空
     * */

    // 1.istringstream
    // istringstream 只支持 >> 操作符
    istringstream iss;
    function<string()> issTest = [&iss]()->string {
        string line;
        string word;
        while(getline(cin, line)){
            iss.str(line);  //从line中读取字符
                while(iss >> word){
                cout << " word = " << word << endl;
            }
        }
    };

    // 2.ostringstream
    // ostringstream 只支持 << 操作符
    ostringstream oss;
    function<void()> ossTest = [&oss]()->void{
        string str = "Test ostringstream";
        oss.str(str);   // oss.str(str); === oss << str;
        str = oss.str() + "123";         // str = oss.str(); === oss >> str;


    };

    // 3.stringstream
    stringstream sstream;
    int num = 123;
    sstream << num; // int转换为string
    string s = "123456";
    sstream >> s;   // s变为字符串"123"
    sstream.clear();
    // 作为输入流istringstream
    sstream << s << ",789";  // 使用stringstream拼接字符串
    string a;
    // 作为输出流ostringstream
//    sstream >> a;
    getline(sstream, a, ',');   //可以使用分割符对sstream分段输出
    string b;
    sstream >> b;
    cout << "b = " << b << endl;
    cout << "a = " << a << ", s = " << s << endl;
    sstream.str("");    //清空sstream：相当于用空字符串""代替原本的字符串内容
    sstream.clear();

    /* 测试stringstream中内容输出以后是否还能再次输出 */
    stringstream mm;
    mm << "baab";
    string m, n;
    mm >> m;
    cout << " , m = " << m; // 此时m = “baab”
    mm >> n;
    cout << " , n = " << n; // 此时n = “”

    /// 测试文件输入
    /* 1.从文件中逐词读取 */
    ifstream fin("");   // 参数为文件所在路径
    string fs;
    while(fin >> fs){
        cout << "Read from file: " << fs << endl;
    }

    /* 2.文件中逐行读取 */
    while(getline(fin, fs)){
        cout << "Read from file : " << fs << endl;
    }
    fin.close();

    /* 3.从文件中逐词读取并写入vector容器中 */
    ifstream infile;
    // 使用匿名函数+function函数对象在函数内部定义函数
    function<void()> fileToVectorByWord = [&infile]()->void {
        infile.open("");
        if(!infile){    //  异常判断
            cout << "error : cannot open the file" << endl;
        }

        vector<string> v;
        string s;
        while(!infile.eof()){
            infile >> s;
            v.push_back(s);
        }

        // 验证是否读入到vector中
        vector<string>::const_iterator it = v.begin();
        while(it != v.end()){
            cout << *it << endl;
            it++;
        }
        infile.close();
    };
    fileToVectorByWord();

    return true;
}

///测试const修饰成员函数
class test{
private:
    int m_age;
public:
    void setAge(int age){
        m_age = age;
    }

/*    //const修饰成员函数体
    void setAgeConst(int age)const{
        m_age = age;    //不能修改调用该函数的数据成员
        getAge();       // 不能调用非const的成员函数
    }

    // const修饰引用形参
    void setAge(const int& age){
        age = 10;       // 不能在函数体内对该形参进行更改
        m_age = age;
    }*/

    const int getAge(){
        return m_age;
    }

    void showAge(){
        cout << "Age: " << m_age << endl;
    }

};

// 链式前向星
const int N = 100010;
int idx = 0;
int h[N], ne[2*N], w[2*N], e[2*N];

void add(int u, int v, int weight){
    e[idx] = v;
    ne[idx] = h[u];
    w[idx] = weight;
    h[u] = idx++;
}

void traverse(){
    for(int i = 1; i <= N; i ++){
        for(int j = h[i]; ~j; j = ne[j]){
            cout << "边的权重： " << w[j] << ", 边的下标：" << j << ", 结点" << i << "， 邻居顶点：" << e[j] << endl;
        }
    }
}

/// 测试constexpr修饰类的成员函数
class constexprTest{
private:
    int age;
public:
    // constexpr修饰构造函数时，函数体必须为空
    constexpr constexprTest(int age):age(age){}
    constexpr int getAge(){
        return age;
    }
};

struct mtType{
    const char* name;
    int age;
};
template<typename T>
constexpr T display(T t){
    return t;
}
void mtTypeTest(){
    struct mtType mt{"zhangsan", 18};
    cout << mt.age << mt.name << endl;

    constexpr mtType mt1{"lisi", 18};
    cout << mt1.age << mt1.name << endl;
}

/// 测试const修饰
class constTest{
private:
    const int a; int const a1;
    const int* b; int const* b1; int* const b2;

public:
    int const func(const int x) const {return x;}
};


/// 测试function #include <functional>
struct Foo{
public:
    Foo(int num):num_(num){}

    void print_add(int a)const {cout << a + num_ << endl; }
private:
    int num_;
};

struct printNum{
    void operator()(int num){ cout << num << endl;}
};
void print_Num(int num){
    cout << num << endl;
}

void functionTest(){
    // 普通函数
    function<void(int)> f_display = print_Num;
    f_display(-1);

    // lambda匿名函数
    function<void()> f_display_2 = [](){ print_Num(42); };
    f_display_2();

    // 存储到成员函数的调用
    function<void(const Foo&, int)> f_display_member = &Foo::print_add;
    const Foo foo(50);
    f_display_member(foo, 20);
    f_display_member(90, 20);

    // struct函数对象的调用
    function<void(int)> f_display_3 = printNum();
    f_display_3(18);
}

/// 可变参数模板类，Values是模板参数包
template <typename T, typename ...Values>
class Tuple{

};

template <typename ... Values>
void fun (Values... values){

}


/// 测试initializer_list
enum Gender{
    boy, girl
};

class People{
public:
    People(initializer_list<pair<string, Gender>> l){
        auto i = l.begin();
        for( ; i!= l.begin(); ++i)
            data.emplace_back(*i);
    }
private:
    vector<pair<string, Gender>> data;
};
People ship2012 = {{"zhangsan", boy}, {"lisi", girl}};



int main() {
    constexpr constexprTest constexprTest{3};
    auto a = '123';
    auto b = '123';
    cout  <<"a+b: " <<  a + b << endl;

//    functionTest();
    /*1.任何成员对象的构造函数按照声明顺序初始化*/
//    Base obj(98);
//    cout<< obj.get_j()<< " , "  << obj.get_i() ;

    /* 2.虚基类测试*/
//    C temp1;
//    cout << "C结束" <<endl;
//    D temp ;
//    cout << "D结束" << temp.i << endl;

//    /* 3.测试unordered_map */
//    test();

    /* 4.函数指针 */
//    int (*pfun)(int i, int j);
//    pfun = fun1;
//    fun2(pfun, 2);
//    fun2(fun1, 3);

    /* 5.成员函数指针调用成员函数 */
//    Test obj;
//    int (Test::*funptr)(int , int );    //成员函数指针
//    funptr = &Test::a;
//    (obj.*funptr)(1,2);

    /* 6.哈希结构模板函数 */
//    cout << boolalpha << (bool)(hash<int>()(5) == hash<int >()(2));
//    sparse_popcnt();
//    _builtin_popcount_

    /* 7.测试流输入 */
//    cout << boolalpha << testInput() << endl;

    return 0;
}
