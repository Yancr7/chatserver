#include "json.hpp"
using json = nlohmann::json;

#include<iostream>
#include<map>
#include<vector>
#include<string>
using namespace std;

void func1(){
    json js;
    js["msg_type"]=2;
    js["from"]="zhang san";
    js["to"]= "li si";
    js["msg"]="ni hao";
    string sendBuf = js.dump();
    cout<<sendBuf.c_str()<<endl;

}
void func2(){
    json js;
    js["id"]={1,2,3,4,5};
    js["name"]="zhang san";
    js["msg"]["zhang san"]="hello word";
    js["msg"]["wang wu"]= "hello china";
    //上面等同于下面这一次性添加数组的对象
    js["msg"]={{"zhang san","hello word"},{"wang wu","hello china"}};
    cout<<js<<endl;
}
void func3(){
    json js;
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(7);
    js["list"]=v;
    map<int,string>m;
    m.insert({1,"黄山"});
    m.insert({2,"泰山"});
    m.insert({3,"华山"});
    js["path"]=m;
    string sendBuf = js.dump();//json 数据化对象->序列化json字符串
    cout<<sendBuf.c_str()<<endl;
}
int main(){
    func3();
    return 0;
}