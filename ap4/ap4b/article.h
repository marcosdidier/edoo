#ifndef ARTICLE_H
#define ARTICLE_H

#include <string>

class Article{
    private:
    long number;
    std::string name;
    double price;
    static int counter;

    public:

    Article(long number = 0, const std::string& nome = "Produto sem nome", double price = 0.0);

    ~Article();

    void print();

    long getNumber() const;
    std::string getName() const;
    double getPrice() const;
    static int getObjectCount() { return counter; }

    void setNumber(long number);
    void setName(const std::string& name);
    void setPrice(double price);


};

#endif