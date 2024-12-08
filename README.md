# Making a hash table with C
This is a small project where i am going to make a hash
table data structure in C from scratch. The main features:  
    1)Insertion  
    2)Search  
    3)Hash Function  
    4)Delete  
    5)Rehashing  
## So what's a hash table?
A hash table is a data structure which allows us to map
large data to a small set of data. This is done by using
a hash function. It is an irreversible process.
## Structs
So the hash table item will have two fields:  
    1) The key  
    2) The value  
The hash table itself will have three fields:  
    1)Size  
    2)Count  
    3)The items stored in the table  
## Adding an item
To add an item we create a new item i. Then we allocate
memory to that item and assign the key and the value.
## Deleting an item
We free the memory allocated previously to that item.
## Creating a hash_table
We create a new variable ht and we allocate memory according
to the size of that hash_table and taking in consideration 
the size of a single item.
## Deleting a hash_table
We delete all the items stored in the hash table so we can 
free the memory allocated to those. After that we can delete
the whole hashtable by freeing the memory allocated to it.
## Hashing
Hashing is a technique that maps a large set of data to a 
small set of data. It uses a hash function for doing this 
mapping. It is an irreversible process and we cannot find
the original value of the key from its hashed value because
we are trying to map a large set of data into a small set 
of data, which may cause collisions. It is not uncommon to
encounter collisions when mapping a large dataset into a 
smaller one. Suppose, We have three buckets and each bucket
can store 1L of water in it and we have 5L of water also.
We have to put all the water in these three buckets and this
kind of situation is known as a collision. URL shorteners are
an example of hashing as it maps large size URL to small size.
[W3C](https://www.geeksforgeeks.org/implementation-of-hash-table-in-c-using-separate-chaining/)  
For the hashing i will use this algorithm :  
DJB2 Hashing Algorithm:  
Initial Hash Value (5381):  
This value is chosen to ensure a good distribution of hash values.  
Main Loop:  
The algorithm processes each character in the string. For each 
character, it shifts the current hash value left by 5 bits 
(hash << 5), multiplies the result by 33 (hash * 33)  
Maybe in the future i will create my own hashing algorithm, we
should take in consideration that a stronger hash algorithm the
more we avoid Collisions.  

