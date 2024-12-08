# **Making a Hash Table in C**

This is a small project where I build a **hash table** data structure in C from scratch. The main features include:

- **Insertion**
- **Search**
- **Hash Function**
- **Delete**
- **Rehashing**

> **Reference**: This project was inspired by this [repository](https://github.com/jamesroutley/write-a-hash-table) by [James Routley](https://github.com/jamesroutley).  
> A helpful [video](https://www.youtube.com/watch?v=YIoZQwWJIDA) explains collisions in hashing.

---

## **What’s a Hash Table?**

A **hash table** is a data structure that allows us to map **large data** into a smaller set using a **hash function**.  
Key characteristics:
- **Efficient data retrieval:** Provides average O(1) time complexity for insert, delete, and search operations.
- **Irreversible process:** The hash function is designed to be one-way, meaning it’s not possible to derive the original value from the hashed value.

---

## **Structs**

### **Hash Table Item**
The hash table item has two fields:
1. **Key**
2. **Value**

### **Hash Table**
The hash table itself has three fields:
1. **Size** – Total capacity of the hash table.
2. **Count** – Current number of items in the table.
3. **Items** – The actual key-value pairs stored in the table.

---

## **Adding an Item**
1. Create a new item `i`.
2. Allocate memory for the item.
3. Assign the key and value to the allocated memory.

---

## **Deleting an Item**
1. Free the memory allocated to the specific item.

---

## **Creating a Hash Table**
1. Create a new hash table variable `ht`.
2. Allocate memory for the hash table, accounting for:
   - The table size.
   - The size of each item.

---

## **Deleting a Hash Table**
1. Delete all items stored in the hash table by freeing their memory.
2. Free the memory allocated to the entire hash table.

---

## **Hashing**

Hashing is the technique of mapping a **large set of data** into a **smaller set of data** using a **hash function**.  
> **Key Properties of Hashing**:
> - **Collisions**: Occur when multiple keys map to the same hash value.  
> - **Applications**: URL shorteners, cryptographic functions, and more.

### **Collision Example**
Imagine having:
- **3 buckets**, each storing up to 1L of water.
- **5L of water** to distribute among these buckets.  

Since the buckets can't hold all the water, some water "overflows," creating **collisions**.

---

## **Hashing Algorithm: DJB2**

This project uses the **DJB2 hashing algorithm**, known for its simplicity and good distribution.

### **Steps**:
1. **Initial Hash Value**: `5381`
   - Chosen to ensure a good spread of hash values.
2. **Main Loop**:
   - For each character in the string:
     - Shift the current hash value left by 5 bits: `hash << 5`
     - Multiply the result by 33: `hash * 33`

### **Example Code**:
```c
unsigned long djb2(const char *str) {
    unsigned long hash = 5381;
    int c;

    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
    }

    return hash;
}
```
### **Future Plans**
- Implement a **custom hashing algorithm** to better avoid collisions.
- Explore stronger hash functions for enhanced performance.

---

## **References**
- [GeeksforGeeks: Hash Table Implementation](https://www.geeksforgeeks.org/implementation-of-hash-table-in-c-using-separate-chaining/)
- [Repository by James Routley](https://github.com/jamesroutley/write-a-hash-table)

