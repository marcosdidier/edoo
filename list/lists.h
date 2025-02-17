#ifndef LIST_H
#define LIST_H

template <typename E>

class List {

    public:

    virtual ~List() = 0;
    virtual void insert(const E& item) = 0;
    virtual void append(const E& item) = 0;
    virtual E remove() = 0;
    virtual void moveToStart() = 0;
    virtual void moveToEnd() = 0;
    virtual void prev() = 0;
    virtual void next() = 0;
    virtual int length() = 0;
    virtual int currPos() = 0;
    virtual void moveToPos(int pos) = 0;
    virtual E getValue() = 0;

};

template <typename E>
List<E>::~List() {} //Lembrar de implementar destrutores virtuais puros

#endif