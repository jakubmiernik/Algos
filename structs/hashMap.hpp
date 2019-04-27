#include "vector.hpp"
#pragma once

template<typename T_K, typename T_V>
class BruteMap {
	template<typename T_K, typename T_V>
	class Node {
	public:
		T_K key;
		T_V val;
		Node(T_K _key = -1, T_V _val = -1) : key(_key), val(_val) {}
	};

	vector<Node<T_K, T_V>> data;
	int find(T_K key) {
		for (int ii = 0; ii < data.size(); ii++) {
			if (data[ii].key == key)
				return ii;
		}
		return -1;
	}
public:
	void insert_or_assign(T_K key, T_V val) {
		int idx = find(key);
		if (idx == -1) {
			Node<T_K, T_V> newNode(key, val);
			data.push_back(newNode);
			return;
		}
		else {
			data[idx].val = val;
		}
	}
	bool contains(T_K key) {
		return find(key) == -1 ? false : true;
	}
	T_V get(T_K key) {
		int idx = find(key);
		if (idx < 0) throw;
		return data[idx].val;
	}
	void erase(T_K key) {
		int idx = find(key);
		if (idx < 0) throw;
		data[idx] = data[data.size() - 1];
		data.pop_back();
	}
	void clear() {
		data.clear();
	}
};

template<typename T_K, typename T_V, int S>
class HashMap {
	BruteMap<T_K, T_V> bruteMaps[S];
	int hash(T_K key) {
		int ret = key % S;
		if (ret < 0)
			ret += S;
		return ret;
	}
public:
	void insert_or_assign(T_K key, T_V val) {
		int h = hash(key);
		bruteMaps[h].insert_or_assign(key, val);
	}
	bool contains(T_K key) {
		int h = hash(key);
		return bruteMaps[h].contains(key);
	}
	T_V get(T_K key) {
		int h = hash(key);
		return bruteMaps[h].get(key);
	}
	void erase(T_K key) {
		int h = hash(key);
		bruteMaps[h].erase(key);
	}
	void clear() {
		for (int ii = 0; ii < S; ii++)
			bruteMaps[ii].clear();
	}
};