#ifndef TABLE2_H
#define TABLE2_H

#include <cstdlib>
#include "link2.h"

const std::size_t TABLE_SIZE = 10;

template <typename RecordType>
class Table {
public:
    Table();

    void insert(const RecordType& entry);
    void remove(int key);
    void print(int index) const;

    bool is_present(const RecordType& target) const;
    void find(int key, bool& found, RecordType& result) const;
    std::size_t size() const;

    void operator=(const Table& source);

private:
    Node<RecordType>* data[TABLE_SIZE];
    std::size_t total_records;

    std::size_t hash(int key) const;
    Node<RecordType>* find_node(Node<RecordType>*& cursor, Node<RecordType>*& precursor, int key) const;
};

#include "table2.template"
#endif
