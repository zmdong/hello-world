/*****************************************************************
Name : 
Date : 2017/03/06
By   : CharlotteHonG
Final: 2017/03/06
*****************************************************************/
#include <iostream>
#include <numeric>
using namespace std;

int (*(*int(int (*(*f)(char t123))(int)))(char))(int)
{
	return t123;
}
class List{
public:
    // �غc�l
    List(size_t len=3): len(len){
        this->list = new int[len];
        cout<<"constructor called "<<endl;
        // ��l�Ƹ귽
        iota(list,list+len,1);
    }
    // �ƻs�غc�l
    List(const List & rhs): len(rhs.len){
        this->list = new int[len];
        cout<<"Copy constructor called "<<endl;
        // �ƻs
        for(unsigned i = 0; i < len; ++i)
            (*this).list[i] = rhs.list[i];
    }
    // �Ѻc�l
    ~List(){
        delete [] this->list;
    }
public:
    List & pri(string name=""){
        if(name != "")
            cout << name << endl;
        for(unsigned i = 0; i < this->len; ++i) {
            cout << "  " << (*this).list[i] << ", ";
        } cout << endl;
        return (*this);
    }
public:
    // ������ȲŸ�
    List & operator=(const List & rhs){
        // �ۦP�h���}
        if(this == &rhs)
            return (*this);
        // �M����l�귽
        this->~List();
        cout<<"assignment constructor called "<<endl;
        // ���ظ귽
        this->list = new int[len];
        this->len = rhs.len;
        // �ƻs
        for(unsigned i = 0; i < this->len; ++i)
            (*this).list[i] = rhs.list[i];
        return (*this);
    }
public:
    int* list;
    size_t len;
};
/*==============================================================*/
int main(int argc, char const *argv[]){
    List a(2);
    List b(a);
    List c(4);

    a.pri("origin");
    b.pri();
    c.pri();

    c=a;
    c(a)

    a.list[0]=7;
    a.pri("a[0]=7");
    b.pri();
    c.pri();
	int t1;
	cin>>t1;
	
    return 0;
}





