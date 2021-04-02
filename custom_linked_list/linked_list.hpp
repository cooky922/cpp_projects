#ifndef __CUSTOM_LINKED_LIST_HPP__
#define __CUSTOM_LINKED_LIST_HPP__

#include <sstream>
#include <string>
#include <initializer_list>
#include <algorithm>
#include <exception>
#include <memory>

template <typename T = int>
class Linked_List {
private:
    template <typename _Base>
    struct Node {
        _Base __data;
        Node<_Base>* __prev;
        Node<_Base>* __next;
    };
    // VARS
    Node<T>* head;
    Node<T>* tail;
    Node<T>* current_node;

    // PRIVATE PILLAR ACCESS
    Node<T>*& __at_node(size_t __index) {
        auto __temp = head;
        size_t __counter = 0;

        while (__counter < __index) {
            __temp = __temp->__next;
            __counter++;
        }

        current_node = __temp;

        return current_node;
    }

    Node<T>*& __at_node_from_tail(size_t __index) {
        auto __temp = this->__get_tail();
        size_t __counter = 0;

        while (__counter < __index) {
            __temp = __temp->__prev;
            __counter++;
        }

        current_node = __temp;

        return current_node;
    }

    Node<T>*& __get_head() {
        return this->__at_node(0);
    }

    Node<T>*& __get_tail() {
        return this->__at_node(this->length() - 1);
    }

public:
    // CONSTRUCTOR
    Linked_List(): head{nullptr}, tail{nullptr} {}

    Linked_List(std::initializer_list<T>&& __list) : Linked_List() {
        decltype(auto) __list_1 = std::forward<decltype(__list)>(__list);
        T __temp[__list_1.size()];
        std::copy(__list_1.begin(), __list_1.end(), __temp);
        std::reverse(__temp, __temp + __list.size());
        for (const auto& __index : __temp)
            this->push_front(__index);
    }

    ~Linked_List() { /***/ }

    Linked_List& operator=(const Linked_List& __other) = delete;
    /**
    {
        head = __other.head;
        tail = __other.__get_tail();
        current_node = __other.current_node;
    }
    */

    Linked_List& operator=(std::initializer_list<T>&& __list) = delete;
    /**
    {
        decltype(auto) __other  = std::forward<decltype(__list)>(__list);
        head = __other.head;
        tail = __other.__get_tail();
        current_node = __other.current_node;
    }
    */

    /**
    Linked_List& assign(const Linked_List& __other) {
        *this = __other;
    }

    Linked_List& assign(std::initializer_list<T>&& __list) {
        *this = __list;
    }
    */

    // ITERATOR
    class iterator {
    private:
        Node<T>* __node;
    public:
        iterator() noexcept : __node{head} {}
        iterator(Node<T>* __arg) noexcept : __node{__arg} {}

        iterator& operator=(Node<T>* __arg) {
            this->__node = __arg;
            return *this;
        }

        iterator operator++() {
            if (__node)
                __node = __node->__next;
            return *this;
        }

        iterator operator++(int) {
            iterator __iter = *this;
            ++(*this);
            return __iter;
        }

        iterator operator--() {
            if (__node)
                __node = __node->__prev;
            return *this;
        }

        iterator operator--(int) {
            iterator __iter = *this;
            --(*this);
            return __iter;
        }

        bool operator==(const iterator& __iter) {
            return (__node == __iter.__node);
        }

        bool operator!=(const iterator& __iter) {
            return (__node != __iter.__node);
        }

        T& operator*() {
            return __node->__data;
        }
        // UNFINISHED
    };

    iterator begin() {
        return iterator(head);
    }

    iterator end() {
        return iterator(nullptr);
    }

    // MODIFIERS
    Linked_List& push_front(T __arg) {
        auto __new_node = new Node<T>;

        __new_node->__data = __arg;
        __new_node->__prev = nullptr;
        __new_node->__next = head;

        if (head != nullptr) head->__prev = __new_node;

        head = __new_node;

        return *this;
    }

    Linked_List& push_back(T __arg) {
        auto __new_node = new Node<T>;
        auto __last = head;

        __new_node->__data = __arg;
        __new_node->__next = nullptr;

        if (head == nullptr) {
            __new_node->__prev = nullptr;
            head = __new_node;
            return *this;
        }

        while (__last->__next != nullptr)
            __last = __last->__next;
        __last->__next = __new_node;
        __new_node->__prev = __last;

        return *this;
    }

    // No Implementations Yet :<
    Linked_List& insert_at(size_t __index, T __arg);

    Linked_List& append(Linked_List __list) {
        auto __temp = __list;
        this->__get_tail()->__next = __temp.head;
        return *this;
    }

    Linked_List& append(std::initializer_list<T>&& __list) {
        Linked_List __temp = std::forward<decltype(__list)>(__list);
        this->__get_tail()->__next = __temp.head;
        return *this;
    }

    Linked_List& prepend(Linked_List __list) {
        auto __temp = __list;
        __temp.__get_tail()->__next = head;
        head = __temp.head;
        return *this;
    }

    Linked_List& prepend(std::initializer_list<T>&& __list) {
        Linked_List __temp = std::forward<decltype(__list)>(__list);
        __temp.__get_tail()->__next = head;
        head = __temp.head;
        return *this;
    }

    Linked_List& pop_back() {
        if (head != nullptr) {
            if (this->length() != 1) {
                delete std::move(this->__get_tail());
                this->__at_node(this->length() - 2)->__next = nullptr;
            } else { this->clear(); }

            /**
            Node<T>*& __temp = this->__at_node(this->length() - 1);
            this->__get_tail() = this->__get_tail()->__prev;
            delete __temp;
            this->__get_tail()->__next = nullptr;
            */
        } else {}

        return *this;
    }

    Linked_List& pop_front() {
        if (head != nullptr) {
            Node<T>* __temp = head;
            head = head->__next;

            delete __temp;
        } else {}

        return *this;
    }

    Linked_List& remove_at(size_t __index) {
        auto& __temp = this->__at_node(__index);

        if (
            head == nullptr
         || __temp == nullptr
        ) return *this;

        if (head == __temp)
            head = __temp->__next;

        if (__temp->__next != nullptr)
            __temp->__next->__prev = __temp->__prev;

        if (__temp->__prev != nullptr)
            __temp->__prev->__next = __temp->__next;

        delete __temp;

        return *this;
    }

    Linked_List& clear() {
        Node<T>* __temp = head;
        Node<T>* __next_temp;

        while (__temp != nullptr) {
            __next_temp = __temp->__next;
            delete __temp;
            __temp = __next_temp;
        }

        head = nullptr;

        return *this;
    }


    // ELEMENT ACCESS

    /// #1: ONE WAY
    T  at(size_t __index)         { return this->__at_node(__index)->__data; }

    T  at(int __index) {
        if (__index < 0)
            return this->__at_node_from_tail(-__index - 1)->__data;
        else
            return this->at(static_cast<size_t>(__index));
    }

    T& operator[](size_t __index) { return this->__at_node(__index)->__data; }

    T& operator[](int __index) {
        if (__index < 0)
            return this->__at_node_from_tail(-__index - 1)->__data;
        else
            return (*this)[static_cast<size_t>(__index)];
    }

    T& front() {
        try {
            return this->__at_node(0)->__data;
        } catch (...) {
            throw std::range_error("This container is empty.");
        }
    }

    T& back() {
        try {
            return this->__at_node_from_tail(0)->__data;
        } catch (...) {
            throw std::range_error("This container is empty.");
        }
    }

    /// #2: TWO WAY

    /// #3: HEAD + MEMORY

    /// #4: HEAD + TAIL + MEMORY


    // DEBUGGING

    void print() {
        auto __temp = head;
        while (__temp != nullptr) {
            std::cout << __temp->__data << " ";
            __temp = __temp->__next;
        }
    }

    void println() {
        this->print();
        std::cout << '\n';
    }

    std::string stringify() {
        if (head != nullptr) {
            std::ostringstream __oss;
            auto __temp = head;

            while (__temp != nullptr) {
                __oss << __temp->__data << " ";
                __temp = __temp->__next;
            }
            return __oss.str();
        } else return "";
    }

    // CAPACITY
    size_t length() {
        auto __temp = head;
        size_t __count = 0;
        while (__temp != nullptr) {
            __count++;
            __temp = __temp->__next;
        }
        return __count;
    }

    size_t size() {
        return this->length();
    }

    bool is_empty() {
        return (head == nullptr);
    }

    // CONVERSTION
    auto to_carray() {
        const size_t __len = this->length();
        int __result[__len];
        size_t __i = 0;

        auto __temp = head;

        while (__temp != nullptr) {
            __result[__i++] = __temp->__data;
            __temp = __temp->__next;
        }

        return __result;
    }

    // TEMPORARY ACTIONS
    Linked_List& rotate(int __integer = 1) {
        if (__integer > 0) {
            for (int __counter = 0; __counter < __integer; __counter++) {
                auto __temp_value = this->back();
                this->pop_back();
                this->push_front(__temp_value);
            }
        } else if (__integer < 0) {
            for (int __counter = 0; __counter < -__integer; __counter++) {
                auto __temp_value = this->front();
                this->pop_front();
                this->push_back(__temp_value);
            }
        } else {
            // __integer == 0
            return *this;
        }
        return *this;
    }

    Linked_List& rotate_right(size_t __integer = 1) {
        this->rotate(static_cast<int>(__integer));
        return *this;
    }

    Linked_List& rotate_left(size_t __integer = 1) {
        this->rotate(-static_cast<int>(__integer));
        return *this;
    }

    T max_element() {
        T __result = this->at(0);
        for (size_t __index = 0; __index < this->length(); __index++) {
            if (this->at(__index) > __result)
                __result = this->at(__index);
        }
        return __result;
    }

    T min_element() {
        T __result = this->at(0);
        for (size_t __index = 0; __index < this->length(); __index++) {
            if (this->at(__index) < __result)
                __result = this->at(__index);
        }
        return __result;
    }
};

#endif // __CUSTOM_LINKED_LIST_HPP__
