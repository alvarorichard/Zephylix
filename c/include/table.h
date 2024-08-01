#ifndef ZEPHLIX_TABLE_H
#define ZEPHLIX_TABLE_H

#include "common.h"
#include "value.h"
#include <stdbool.h>

typedef struct {
    ObjString* key;
    Value value;
} Entry;

typedef struct {
    int count;
    int capacity;
    Entry* entries;
} Table;

void initTable(Table* table);
void freeTable(Table* table);
bool tableGet(Table* table, ObjString* key, Value* value);
bool tableSet(Table* table, ObjString* key, Value value);
bool tableDelete(Table* table, ObjString* key);
void tableAddAll(Table* from, Table* to);
void tableRemoveWhite(Table* table);
ObjString* tableFindString(Table* table, const char* chars, int length, uint32_t hash);

#endif // ZEPHLIX_TABLE_H
