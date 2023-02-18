#ifndef FORWARD_HPP
#define FORWARD_HPP

#include "remove_reference.hpp"

namespace stdlike {

template <typename T>
T&& forward(typename remove_reference<T>::type& arg) {
    return static_cast<T&&>(arg);
}

template <typename T>
T&& forward(typename remove_reference<T>::type&& arg) {
    return static_cast<T&&>(arg);
}

}

#endif // FORWARD_HPP
