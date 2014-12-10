//You will need this so you can make a string to throw in
// remove
#include <string>

template <class Key, class T>
HashTable<Key,T>::HashTable(){
	backingArraySize = hashPrimes[0];
	backingArray = new HashRecord[backingArraySize];
	numItems = 0;
	numRemoved = 0;
}

template <class Key, class T>
HashTable<Key,T>::~HashTable() {
	backingArray = NULL;
	delete[] backingArray;
}

template <class Key, class T>
unsigned long HashTable<Key,T>::calcIndex(Key k){
	unsigned long i = hash(k) % backingArraySize;
	for (i; true; i++){
		if (backingArray[i].isNull || backingArray[i].k == k){
			return (i);
		}
	}
	return numItems; //This indicates failure, since it is an impossible value
}

template <class Key, class T>
void HashTable<Key,T>::add(Key k, T x){

	if ((numItems + numRemoved) >= backingArraySize / 2){
		grow();
	}

	unsigned long i = hash(k);
	for (i; true; i++){
		if (backingArray[i % backingArraySize].isNull || backingArray[i % backingArraySize].k == k || backingArray[i % backingArraySize].isDel){
			i = (i % backingArraySize);
			break;
		}	
	}

	backingArray[i].k = k;
	backingArray[i].x = x;
	backingArray[i].isNull = false;

	numItems++;
}

template <class Key, class T>
void HashTable<Key,T>::remove(Key k){
	if (keyExists(k)){
		backingArray[calcIndex(k)].isDel = true;

		numItems--;
		numRemoved++;
	}
}

template <class Key, class T>
T HashTable<Key,T>::find(Key k){
	if (keyExists(k)){
		return (backingArray[calcIndex(k)].x);
	}
	else{
		throw std::string("Error: No item in hash table with that key");
	}
}

template <class Key, class T>
bool HashTable<Key,T>::keyExists(Key k){
	unsigned long i = calcIndex(k);
	if (backingArray[i].isNull) 
		return false;
	if (backingArray[i].isDel) 
		return false;
	if (backingArray[i].k == k)
		return true;

	return false;
}

template <class Key, class T>
unsigned long HashTable<Key,T>::size(){
	return numItems;
}

template <class Key, class T>
void HashTable<Key,T>::grow(){
	HashRecord* oldArray = backingArray;
	int oldArraySize = backingArraySize;
	for (int i = 0; true; i++) {
		if (hashPrimes[i] == backingArraySize) {
			backingArray = new HashRecord[hashPrimes[i + 1]];
			backingArraySize = hashPrimes[i + 1];
			break;
		}
	}
	numItems = 0;
	numRemoved = 0;
	for (int i = 0; i < oldArraySize; i++) {
		if (!oldArray[i].isNull && !oldArray[i].isDel) {
			add(oldArray[i].k, oldArray[i].x);
		}
	}
	delete[] oldArray;
}
