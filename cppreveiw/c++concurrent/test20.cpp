#include "head.h"



template<typename T>
class queue
{
    private:
        struct node
        {
            T data;
            std::unique_ptr<node> next;
            node(T _data): data(_data){}
        };

        std::unique_ptr<node> head;
        node * tail;

    public:
        queue() {}

        queue(const queue& other) = delete; // delete copy constructor

        queue &operator=(const queue& other)=delete; //delete assignment operator
        std::shared_ptr<T> try_pop()
        {
            if (!head)
                return std::shared_ptr<T>();
            
            std::shared_ptr<T> const res(std::make_shared<T>(std::move(head->data)));

            std::unique_ptr<node> const old_head = std::move(head); // unique_ptr 没有赋值运算 ， 只能调用移动构造
            head = std::move(old_head->next);

            return res；
        }

        void push(T new_vlaue)
        {
            std::unique_ptr<node> p(new node(std::move(new_value)));
            node* const new_tail = p.get(); // 获取到原始指针
            if (tail)
            {
                tail->next = std::move(p);
            }
            else 
            {
                head = std::move(p);   // push 第一个元素
            }

            tail = new_tail;
        }

};


// next version

tempate<typename T>
class queue
{
    private:
        struct node {
            std::shared_ptr<T> data;
            std::unique_ptr<node> next;
        };

        std::unique_ptr<node> head;
        node* tail;
    public:
        queue(): head(new node), tail(head.get()) {}
        queue(const queue& other) = delete;
        queue & operator=(const queue & other)=delete;

        std::shared_ptr<T> try_pop()
        {
            if (head.get() == tail)
                return std::shared_ptr<T>(); // 没有元素， 返回空
            
            std::shared_ptr<T> const res(head->data);

            std::unique_ptr<node> old_head = std::move(head);
            head = std::move(old_head->next);
            return res;
        }

        void push(T new_value)
        {
            std::shared_ptr<T> new_data(std::make_shared<T>(std::move(new_value)));
            std::unique_ptr<node> p(new node);
            tail->data = new_data;
            node* const new_tail = p.get();
            tail->next = std::move(p);
            tail = new_tail;
        }
};
