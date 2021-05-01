#ifndef DESMOND_TUTORIAL_CONTAINERS_HPP
#define DESMOND_TUTORIAL_CONTAINERS_HPP

#include <vector>
#include <array>
#include <deque>
#include <forward_list>
#include <list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <span>

#include <type_traits>

// Type Traits Actual Definition
template <typename T>
struct is_container : std::false_type {};

template <typename T>
struct is_container_adaptor : std::false_type {};

// Template Specializations
template <typename T, typename Alloc>
struct is_container<std::vector<T, Alloc>> : std::true_type {};

template <typename T, size_t N>
struct is_container<std::array<T, N>> : std::true_type {};

template <typename T, typename Alloc>
struct is_container<std::deque<T, Alloc>> : std::true_type {};

template <typename T, typename Alloc>
struct is_container<std::forward_list<T, Alloc>> : std::true_type {};

template <typename T, typename Alloc>
struct is_container<std::list<T, Alloc>> : std::true_type {};

template <typename Key, typename Compare, typename Alloc>
struct is_container<std::set<Key, Compare, Alloc>> : std::true_type {};

template <typename Key, typename T, typename Compare, typename Alloc>
struct is_container<std::map<Key, T, Compare, Alloc>> : std::true_type {};

template <typename Key, typename Compare, typename Alloc>
struct is_container<std::multiset<Key, Compare, Alloc>> : std::true_type {};

template <typename Key, typename T, typename Compare, typename Alloc>
struct is_container<std::multimap<Key, T, Compare, Alloc>> : std::true_type {};

template <typename Key, typename Hash, typename Pred, typename Alloc>
struct is_container<std::unordered_set<Key, Hash, Pred, Alloc>> : std::true_type {};

template <typename Key, typename T, typename Hash, typename Pred, typename Alloc>
struct is_container<std::unordered_map<Key, T, Hash, Pred, Alloc>> : std::true_type {};

template <typename Key, typename Hash, typename Pred, typename Alloc>
struct is_container<std::unordered_multiset<Key, Hash, Pred, Alloc>> : std::true_type {};

template <typename Key, typename T, typename Hash, typename Pred, typename Alloc>
struct is_container<std::unordered_multimap<Key, T, Hash, Pred, Alloc>> : std::true_type {};

template <typename T, size_t Extent>
struct is_container<std::span<T, Extent>> : std::true_type {};

template <typename T, typename Cont>
struct is_container_adaptor<std::stack<T, Cont>> : std::true_type {};

template <typename T, typename Cont>
struct is_container_adaptor<std::queue<T, Cont>> : std::true_type {};

template <typename T, typename Cont, typename Compare>
struct is_container_adaptor<std::priority_queue<T, Cont, Compare>> : std::true_type {};

// Helper Variable Templates
template <typename T>
constexpr bool is_container_v = is_container<T>::value;

template <typename T>
constexpr bool is_container_adaptor_v = is_container_adaptor<T>::value;

// Concepts
template <typename T>
concept Container = is_container_v<T>;

template <typename T>
concept Container_Adaptor = is_container_adaptor_v<T>;

#endif // DESMOND_TUTORIAL_CONTAINERS_HPP
