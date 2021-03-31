/*************************************************************************
	> File Name: memory.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月28日 星期日 14时49分28秒
 ************************************************************************/

#include <string>
#include <iostream>
#include <memory>
#include <cassert>
#include <vector>
using namespace std;

const int CAP_NUM = 16;
class Object
{
public:
    string str_object;
	static shared_ptr<Object> getObj();
protected:
	Object(){}

};
struct Position:Object
{
	bool used;
	Position* next;
} buffer[CAP_NUM];
Position* unused ;
Object* createObj()
{
    if (unused->used == true) return nullptr;
    Position *p = unused;
    unused = unused->next;
    p->used = true;
    return static_cast<Object *>(p);
		//TODO
}
bool destroyObj(Object* obj)
{
    if (obj == nullptr) return false;
    Position *p = static_cast<Position*>(obj);
    if (p == nullptr) return false;
    if (p->used == false) return false;
    p->used = false;
    p->next = unused;
    unused = p;
    return true;
		//TODO
}
shared_ptr<Object> Object::getObj()
{
	shared_ptr<Object>obj(createObj(), destroyObj);
	return obj;
}
void bufferInit()
{
	unused = &buffer[0];
	for (int i = 0; i < CAP_NUM-1; i++)
	{
		buffer[i].used = false;
		if (i!=CAP_NUM-1)
		{
			buffer[i].next = &buffer[i + 1];
		}
	}
	buffer[CAP_NUM - 1].next = NULL;
}
void assert_obj(Object* obj)
{
	auto destroy_result = destroyObj(obj);
	assert(destroy_result == false);
}

int main()
{
	bufferInit();
	{
		Object* obj = buffer - sizeof(Position);
		assert_obj(obj);
	}

	{
		int getAddr;
		Object* obj = reinterpret_cast<Object*>(&getAddr);
		assert_obj(obj);
	}

	{
		Object* obj = nullptr;
		assert_obj(obj);
	}

	{
		Object* obj = buffer + CAP_NUM + 1;
		assert_obj(obj);
	}

	{
		Object* obj = createObj();
		destroyObj(obj);
		assert_obj(obj);
	}

	{
		vector<shared_ptr<Object>> vec_obj;
		for (int i = 0; i < CAP_NUM; i++)
		{
			auto p = Object::getObj();
			if (p != nullptr)
			{
				p->str_object = "" + to_string(i);
				cout << p->str_object << endl;
			}
			vec_obj.push_back(p);
		}
		auto p_blank = Object::getObj();
		assert(p_blank == nullptr);

	}
	cout << "all tests done!" << endl;
	return 0;
}
