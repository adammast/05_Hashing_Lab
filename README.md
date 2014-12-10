05_Hashing_Lab
==============

Implement a hash table in C++

Requirements
------------

1. `keyExists`, `find`, `remove`, and `size` should all be O(1)
2. `add` should be reasonably fast. Use linear probing to find an open slot in the hash table. This will be O(1), on average, except when `grow` is called.
3. `grow` should be O(n)
4. Do not leak memory


Reading
=======
"Open Data Structures," Chapter 5, except for 5.2.3. http://opendatastructures.org/ods-cpp/5_Hash_Tables.html

Questions
=========

#### 1. Which of the above requirements work, and which do not? For each requirement, write a brief response.

1. All of them are 0(1)
2. I believe it is decently fast.
3. I had trouble with this method, but I believe it is working well right now.
4. Deletion method works well.

#### 2. I decided to use two function (`keyExists` and `find`) to enable lookup of keys. Another option would have been to have `find` return a `T*`, which would be `NULL` if an item with matching key is not found. Which design do you think would be better? Explain your reasoning. You may notice that the designers of C++ made the same decision I did when they designed http://www.cplusplus.com/reference/unordered_map/unordered_map/

		I believe that the design that was chosen is faster. According to the reading it would be faster this way because find
		has to cycle through everything in the parameters. Also, it's always useful to make helper methods in my opinion.

#### 3. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?

		My advice is to make sure you completely understand the reading before starting this assignment. It was a
		very complicated assignment.