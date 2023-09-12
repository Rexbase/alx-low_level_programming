### Project Title: 0x1A. C - Hash tables

#### Description
This project focuses on hash tables in the C programming language. Hash tables are a widely used data structure for efficiently storing and retrieving data. In this project, you will learn how to implement a basic hash table, handle collisions using separate chaining, and perform various operations on hash tables.

#### Learning Objectives
By the end of this project, you should be able to:

- Understand the concept of hash tables and their applications.
- Create a basic hash table data structure.
- Handle collisions using separate chaining.
- Implement functions to insert, retrieve, and delete data from a hash table.
- Free the memory allocated for the hash table.

#### Files
1. **0-hash_table_create.c**: A C function `hash_table_create` that creates a hash table.

2. **1-djb2.c**: A C function `hash_djb2` that implements the DJB2 hash function.

3. **2-key_index.c**: A C function `key_index` that calculates the index of a key in a hash table.

4. **3-hash_table_set.c**: A C function `hash_table_set` that adds an element to a hash table.

5. **4-hash_table_get.c**: A C function `hash_table_get` that retrieves a value associated with a key from a hash table.

6. **5-hash_table_print.c**: A C function `hash_table_print` that prints the key-value pairs in a hash table.

7. **6-hash_table_delete.c**: A C function `hash_table_delete` that deletes a hash table.

#### Usage
To use the functions provided in this project, you can include the respective C files in your project and call the functions as needed.

For example:

```c
#include "hash_tables.h"

int main(void)
{
    hash_table_t *ht;
    
    ht = hash_table_create(1024);
    
    hash_table_set(ht, "name", "John");
    hash_table_set(ht, "age", "30");
    
    printf("%s\n", hash_table_get(ht, "name"));
    printf("%s\n", hash_table_get(ht, "age"));
    
    hash_table_delete(ht);
    
    return (0);
}
```

#### Testing
To test the functions, you can write test cases in C or use existing tests. Make sure to cover various scenarios, including inserting, retrieving, and deleting data from the hash table.

#### Author
Goodnews Rex

#### Acknowledgments
This project is part of the Holberton School curriculum.
