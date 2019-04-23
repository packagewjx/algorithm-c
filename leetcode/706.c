//
// Created by 吴俊贤<mailto:wu812730157@gmail.com> on 19-4-23.
//

#define INITIAL_SIZE 16
#define THRESHOLD 0.75

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct entry {
    int value;
    // 用于再哈希
    int hash;
    // 链式哈希
    struct entry *next;
} entry;

typedef struct {
    // 保存着数组大小
    int capacity;
    // 存储内容。是entry指针的数组
    entry **entries;
    // 保存着实际存储
    int size;

} MyHashMap;

void doPut(entry **entries, int entLen, int key, int value) {
    int index = key % entLen;
    entry *ent = malloc(sizeof(entry));
    ent->hash = key;
    ent->value = value;
    ent->next = 0;
    if (entries[index] == 0) {
        // 若不存在，则放入本记录
        entries[index] = ent;
    } else {
        // 先检查是否存在hash相同的
        entry *cur = entries[index];
        while (cur) {
            if (cur->hash == ent->hash) {
                // 存在，则更新，返回
                cur->value = value;
                return;
            }
        }
        // 不存在，则加入
        ent->next = entries[index];
        entries[index] = ent;
    }
}

/**
 * 扩容HashMap，增大1倍。需要再哈希
 * @param obj 哈希表对象
 */
void myHashMapEnlarge(MyHashMap *obj) {
    int newCapacity = obj->capacity << 1;
    entry **newEntries = malloc(newCapacity * sizeof(entry *));
    memset(newEntries, 0, newCapacity * sizeof(entry *));

    // 再哈希
    for (int i = 0; i < obj->capacity; i++) {
        if (obj->entries[i] == 0)
            continue;

        entry *ent = obj->entries[i];
        entry *next = 0;
        while (ent) {
            doPut(newEntries, newCapacity, ent->hash, ent->value);
            next = ent->next;
            // 不再需要原本的ent了
            free(ent);
            // 循环更新
            ent = next;
        }
    }

    // 修改原对象
    free(obj->entries);
    obj->entries = newEntries;
    obj->capacity = newCapacity;
}


/** Initialize your data structure here. */
MyHashMap *myHashMapCreate() {
    MyHashMap *map = malloc(sizeof(MyHashMap));
    map->capacity = INITIAL_SIZE;
    map->size = 0;
    map->entries = malloc(INITIAL_SIZE * sizeof(entry *));
    memset(map->entries, 0, INITIAL_SIZE * sizeof(entry *));
    return map;
}

/** value will always be non-negative. */
void myHashMapPut(MyHashMap *obj, int key, int value) {
    if ((double) obj->size / obj->capacity > THRESHOLD) {
        // 若超过阈值，则需要扩展空间保证性能
        myHashMapEnlarge(obj);
    }

    doPut(obj->entries, obj->capacity, key, value);
    obj->size++;
}

/** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
int myHashMapGet(MyHashMap *obj, int key) {
    entry *ent = obj->entries[key % obj->capacity];
    while (ent) {
        if (ent->hash == key)
            return ent->value;
        ent = ent->next;
    }
    return -1;
}

/** Removes the mapping of the specified value key if this map contains a mapping for the key */
void myHashMapRemove(MyHashMap *obj, int key) {
    entry *ent = obj->entries[key % obj->capacity];
    entry *last = 0;
    while (ent) {
        if (ent->hash == key) {
            // 执行删除
            if (last != 0)
                last->next = ent->next;
            else
                obj->entries[key % obj->capacity] = ent->next;
            free(ent);
            obj->size--;
            return;
        }
        last = ent;
        ent = ent->next;
    }
}

void myHashMapFree(MyHashMap *obj) {
    for (int i = 0; i < obj->capacity; i++) {
        if (obj->entries[i] == 0)
            continue;

        entry *ent = obj->entries[i];
        entry *temp;
        while (ent) {
            temp = ent;
            ent = ent->next;
            free(temp);
        }
    }

    free(obj->entries);
    free(obj);
}

int main(int argv, char *argc[]) {
    MyHashMap *map = myHashMapCreate();

//    for (int i = 0; i < 20; i++) {
//        myHashMapPut(map, i, i);
//    }
//
//    for (int i = 0; i < 20; i++) {
//        int get = myHashMapGet(map, i);
//        if (get == -1) {
//            printf("problem %d", i);
//        }
//    }
//
//    myHashMapRemove(map, 10);
//    int mapGet = myHashMapGet(map, 10);
//    if (mapGet != -1) {
//        printf("problem remove");
//    }


    myHashMapPut(map, 1, 1);
    myHashMapPut(map, 2, 2);
    myHashMapGet(map, 1);
    myHashMapGet(map, 3);
    myHashMapPut(map, 2, 1);
    myHashMapGet(map, 2);
    myHashMapRemove(map, 2);
    printf("%d\n", myHashMapGet(map, 2));

    myHashMapFree(map);

    return 0;
}